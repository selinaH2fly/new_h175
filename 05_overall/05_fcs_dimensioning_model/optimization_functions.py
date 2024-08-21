# Import libraries
import torch
import gpytorch
import numpy as np
from scipy.optimize import differential_evolution, NonlinearConstraint

# Import custom classes and functions
import parameters
from Components.compressor import Compressor
from Components.turbine import Turbine
from Components.recirculation_pump import Recirculation_Pump
from Components.coolant_pump import Coolant_Pump
from Components.radiator import Radiator
from Components.stack import Stack
from basic_physics import compute_air_mass_flow, compute_coolant_flow

def optimize_inputs_evolutionary(cell_voltage_model, cathode_pressure_drop_model, flight_level_100ft, cellcount=275,
                                 bounds=None, power_constraint_kW=None, penalty_weight=0.1, params_physics=None,
                                 consider_turbine=True, end_of_life=False):
    """
    Optimize the (cell) voltage predicted by the GPyTorch model with a (cell) power constraint using differential evolution.

    Parameters:
    - cell_voltage_model: The trained GPyTorch model (alongside likelihood and input/target data statistics).
    - cathode_pressure_drop_model: The trained GPyTorch model for the cathode pressure drop. (alongside likelihood and input/target data statistics).
    - flight_level_100ft: Flight level in 100 feet units.
    - cellcount: Number of cells.
    - bounds: Bounds for each feature as a list of tuples [(min1, max1), (min2, max2), ...].
    - power_constraint_kW: Power constraint in kilowatts.
    - penalty_weight: Weight for the penalty term in the objective function.
    - params_physics: Physical parameters.
    - consider_turbine: Whether to consider power recuperation in the optimization.
    - end_of_life: Whether to consider the end of life derating factor.

    Returns:
    - optimal_input: The optimal input values in the original scale.
    - hydrogen_mass_flow_g_s: The minimized target.
    - compressor_power: The power of the compressor.
    """
    
    # Load parameters
    _params_physics = parameters.Physical_Parameters()
    _params_compressor = parameters.Compressor_Parameters()
    _params_turbine = parameters.Turbine_Parameters()
    _params_recirculation_pump = parameters.Recirculation_Pump_Parameters()
    _params_coolant_pump = parameters.Coolant_Pump_Parameters()
    _params_radiator = parameters.Radiator_Parameters()
    _params_stack = parameters.Stack_Parameters()
    _params_Eol = parameters.Eol_Parameter()

    # Instantiate components
    compressor      =   Compressor(_params_physics, isentropic_efficiency=_params_compressor.isentropic_efficiency,
                                   electric_efficiency=_params_compressor.electric_efficiency,
                                   nominal_BoP_pressure_drop_Pa=_params_compressor.nominal_BoP_pressure_drop_Pa,
                                   nominal_air_flow_kg_s=_params_compressor.nominal_air_flow_kg_s)
    
    turbine         =   Turbine(_params_physics, isentropic_efficiency=_params_turbine.isentropic_efficiency,
                                nominal_BoP_pressure_drop_Pa=_params_turbine.nominal_BoP_pressure_drop_Pa,
                                nominal_air_flow_kg_s=_params_turbine.nominal_air_flow_kg_s)
    
    reci_pump       =   Recirculation_Pump(_params_physics, isentropic_efficiency=_params_recirculation_pump.isentropic_efficiency,
                                           electric_efficiency=_params_recirculation_pump.electric_efficiency,
                                           n_cell=cellcount, cell_area_m2=_params_stack.cell_area_m2,
                                           fixed_recirculation_ratio=_params_recirculation_pump.fixed_recirculation_ratio,
                                           nominal_BoP_pressure_drop_Pa=_params_recirculation_pump.nominal_BoP_pressure_drop_Pa)
    
    coolant_pump_ht =   Coolant_Pump(isentropic_efficiency=_params_coolant_pump.isentropic_efficiency,
                                     electric_efficiency=_params_coolant_pump.electric_efficiency)
    
    coolant_pump_lt =   Coolant_Pump(isentropic_efficiency=_params_coolant_pump.isentropic_efficiency,
                                     electric_efficiency=_params_coolant_pump.electric_efficiency) # virtual LT coolant pump for straight-forward power computation
    
    radiator        =   Radiator(nominal_pressure_drop_Pa=_params_radiator.nominal_pressure_drop_Pa,
                                 nominal_coolant_flow_m3_s=_params_radiator.nominal_coolant_flow_m3_s)
    
    stack           =   Stack(cellcount=cellcount)

    def evaluate_models(x): # TODO: refactor this function that became too long and complex
        """
        Helper function to evaluate models and compute necessary values.

        Parameters:
        - x: Normalized input variables.

        Returns:
        - optimal_input: Denormalized optimal input variables.
        - cell_voltage: Denormalized cell voltage.
        - compressor_power_W: Computed compressor power.
        - turbine_power_W: Computed turbine power.
        - reci_pump_power_W: Computed recirculation pump power.
        - coolant_pump_power_W: Computed coolant pump power.
        - hydrogen_mass_flow_g_s: Computed hydrogen mass flow rate.
        """

        # %% Cell Voltage Model

        # Evaluate the cell voltage model
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)
        cell_voltage_model.model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            cell_voltage = cell_voltage_model.model(x_tensor).mean.item()

        # Denormalize
        optimized_input = x * np.array(cell_voltage_model.input_data_std) + np.array(cell_voltage_model.input_data_mean)
        optimized_cell_voltage_V = cell_voltage * cell_voltage_model.target_data_std + cell_voltage_model.target_data_mean

        # Assign the optimal input values to the corresponding variables for better readability
        optimized_current_A = optimized_input[0]
        # optimized_cathode_rh_in_perc = optimized_input[1]
        optimized_stoich_cathode = optimized_input[2]
        optimized_pressure_cathode_in_bara = optimized_input[3]
        optimized_temp_coolant_inlet_degC = optimized_input[4]
        optimized_temp_coolant_outlet_degC = optimized_input[5]

        # Consider the end of life derating factor
        if end_of_life:
            optimized_cell_voltage_V *= _params_Eol.eol_factor

        # %% Compressor and Turbine

        # Compute air massflow
        air_flow_kg_s = compute_air_mass_flow(stoichiometry=optimized_stoich_cathode,
                                              current_A=optimized_current_A,cellcount=cellcount)
        
        # Estimate the cathode BoP pressure drop downstream the compressor (compressor out -> cathode in)
        cathode_BoP_inlet_pressure_drop_Pa = compressor.calculate_BoP_pressure_drop(air_flow_kg_s=air_flow_kg_s)
        
        # Set compressor attributes
        compressor.air_mass_flow_kg_s = air_flow_kg_s
        compressor.flight_level_100ft = flight_level_100ft
        compressor.pressure_out_Pa = optimized_pressure_cathode_in_bara*1e5 + cathode_BoP_inlet_pressure_drop_Pa # compressor_out == cathode_in + BoP_pressure_drop

        # Calculate compressor power
        compressor_power_W = compressor.calculate_power()

        if consider_turbine:
            # TODO: Move the turbine computations to a separate function

            # Normalize current, stoichiometry, and pressure and temperature for evaluating the cathode pressure drop model
            current_for_dp_normalized = (optimized_current_A - cathode_pressure_drop_model.input_data_mean[0]) / \
                cathode_pressure_drop_model.input_data_std[0]
            stoichiometry_for_dp_normalized = (optimized_stoich_cathode - cathode_pressure_drop_model.input_data_mean[1]) / \
                cathode_pressure_drop_model.input_data_std[1]
            pressure_for_dp_normalized = (optimized_pressure_cathode_in_bara - cathode_pressure_drop_model.input_data_mean[2]) / \
                cathode_pressure_drop_model.input_data_std[2]
            temperature_for_dp_normalized = (optimized_temp_coolant_inlet_degC - cathode_pressure_drop_model.input_data_mean[3]) / \
                cathode_pressure_drop_model.input_data_std[3]
            
            pressure_drop_model_input = torch.tensor([current_for_dp_normalized, stoichiometry_for_dp_normalized, pressure_for_dp_normalized,
                                                      temperature_for_dp_normalized], dtype=torch.float).unsqueeze(0)

            # Evaluate the cathode pressure drop model
            cathode_pressure_drop_model.model.eval()
            with torch.no_grad(), gpytorch.settings.fast_pred_var():
                cathode_pressure_drop = cathode_pressure_drop_model.model(pressure_drop_model_input).mean.item()

            # Denormalize
            cathode_pressure_drop_bar = cathode_pressure_drop * cathode_pressure_drop_model.target_data_std \
                + cathode_pressure_drop_model.target_data_mean
            
            # Limit the cathode pressure drop to be non-negative
            cathode_pressure_drop_bar = max(cathode_pressure_drop_bar.item(), 1e-9)
            
            # Compute the cathode pressure out        
            cathode_pressure_out_bar = optimized_input[3] - cathode_pressure_drop_bar

            # Estimate the cathode BoP pressure drop upstream the turbine (cathode out -> turbine in)
            cathode_BoP_outlet_pressure_drop_Pa = turbine.calculate_BoP_pressure_drop(air_flow_kg_s=air_flow_kg_s)

            # Set turbine attributes
            turbine.air_mass_flow_kg_s = air_flow_kg_s
            turbine.pressure_in_Pa     = max(cathode_pressure_out_bar*1e5 - cathode_BoP_outlet_pressure_drop_Pa, 1e-9) # turbine_in == cathode_out - BoP_pressure_drop
            turbine.temperature_in_K   = max(optimized_temp_coolant_outlet_degC + 273.15, 1e-9) 
            turbine.flight_level_100ft = flight_level_100ft
            
            # Compute the turbine power        
            turbine_power_W = turbine.calculate_power()
            
            # Limit the turbine power to not exceed the compressor power
            turbine_power_W = min(turbine_power_W, compressor_power_W)
        else:
            turbine_power_W = 0

        # %% Recirculation Pump

        # Set recirculation pump attributes
        reci_pump.current_A = optimized_current_A
        reci_pump.temperature_in_K = max(optimized_temp_coolant_outlet_degC + 273.15, 1e-9)
        reci_pump.pressure_out_Pa = 1e5*(optimized_pressure_cathode_in_bara + 0.200)    # reci_out == anode_in \approx: cathode_in + 0.2 bar (cf. PowerLayout); TODO: include p_anode_in in cell voltage model
        reci_pump.stoich_anode = 1.5                                                    # TODO: include anode stoichiometry in cell voltage model

        # Estimate the anode pressure drop
        stack.current_A = optimized_current_A
        anode_pressure_drop_Pa = stack.calculate_pressure_drop_anode()

        # Estimate the BoP pressure drop in the recirculation loop
        anode_BoP_pressure_drop_Pa = reci_pump.calculate_BoP_pressure_drop()

        # Compute the pressure at the anode outlet
        reci_pump.pressure_in_Pa = max(reci_pump.pressure_out_Pa -
                                       anode_pressure_drop_Pa -
                                       anode_BoP_pressure_drop_Pa, 1e-9) # reci_in == anode_out \approx: anode_in - dp_anode; TODO: include DoE data-based GPR anode pressure drop model
        
        # Compute the recirculation pump power
        reci_pump_power_W = reci_pump.calculate_power()

        # %% Coolant Pump

        # Compute the coolant pump power for the HT circuit
        coolant_flow_rate_ht_m3_s = compute_coolant_flow(optimized_current_A, optimized_cell_voltage_V,
                                                         optimized_temp_coolant_inlet_degC, optimized_temp_coolant_outlet_degC,
                                                         flight_level_100ft=flight_level_100ft, cellcount=cellcount)
        coolant_flow_rate_ht_l_min = coolant_flow_rate_ht_m3_s * 60 * 1000
        stack_pressure_drop_mbar = 6.5e-3*(coolant_flow_rate_ht_l_min ** 2) + 0.477*coolant_flow_rate_ht_l_min # TODO: 1. move to stack component 2. include stack pressure drop GPR model; caution: High-Amp DoE s.t. water as a coolant!
        coolant_pump_ht.coolant_flow_m3_s = coolant_flow_rate_ht_m3_s
        coolant_pump_ht.head_Pa = stack_pressure_drop_mbar*1e-3*1e5 + radiator.calculate_pressure_drop(coolant_flow_m3_s=coolant_flow_rate_ht_m3_s) # coolant_pump.head_Pa = stack_pressure_drop + radiator_pressure_drop (including 0.1 bar additional HT pressure drop)
        
        # Compute the (virtual) coolant pump power for the LT circuit (assuming a constant flow rate)
        coolant_pump_lt.coolant_flow_m3_s = _params_coolant_pump.nominal_coolant_flow_lt_m3_s
        coolant_pump_lt.head_Pa = _params_coolant_pump.nominal_pressure_drop_lt_Pa

        # Compute the actual coolant pump power
        coolant_pump_power_W = coolant_pump_ht.calculate_power() + coolant_pump_lt.calculate_power()

        # %% Consumed hydrogen mass flow rate

        # Compute the hydrogen mass flow rate
        hydrogen_mass_flow_g_s = optimized_input[0] * cellcount * params_physics.hydrogen_molar_mass / \
            (2 * params_physics.faraday) * 1000

        return optimized_input, optimized_cell_voltage_V, compressor_power_W, turbine_power_W, reci_pump_power_W, \
            coolant_pump_power_W, hydrogen_mass_flow_g_s


# %% Optimization

    # Define the objective function for optimization
    def objective_function(x):

        # Evaluate the models with the normalized input
        optimal_input, cell_voltage, compressor_power_W, turbine_power_W, \
            reci_pump_power_W, coolant_pump_power_W, hydrogen_mass_flow_g_s = evaluate_models(x)
        
        # Compute the penalty term for the power constraint
        if power_constraint_kW is not None:
            power_constraint = cell_voltage * cellcount * optimal_input[0] \
                - compressor_power_W + turbine_power_W - reci_pump_power_W  - coolant_pump_power_W \
                    - power_constraint_kW * 1000
            penalty = penalty_weight * (power_constraint**2)
        else:
            penalty = 0
        
        return hydrogen_mass_flow_g_s + penalty
    
    # Define the nonlinear constraint for the (denormalized) coolant temperatures: T_C_out - T_C_in >= 0 K
    def nonlinear_constraint(x):
        return (x[5]*np.array(cell_voltage_model.input_data_std[5]) + np.array(cell_voltage_model.input_data_mean[5])) \
            - (x[4]*np.array(cell_voltage_model.input_data_std[4]) + np.array(cell_voltage_model.input_data_mean[4])) - 0
    
    nonlinear_constraint = NonlinearConstraint(nonlinear_constraint, 0, np.inf)

    # Normalize the bounds
    normalized_bounds = [((min_val - mean) / std, (max_val - mean) / std ) for (min_val, max_val), mean, std in \
                         zip(bounds, cell_voltage_model.input_data_mean.numpy(), cell_voltage_model.input_data_std.numpy())]

    # Perform the optimization using differential evolution
    result = differential_evolution(objective_function, normalized_bounds, constraints=nonlinear_constraint, maxiter=1000, popsize=30, recombination=0.9, polish=False, disp=False, seed=None)
    optimization_converged = result.success
    print(f'{result.message}')

    # Evaluate the models with the optimal input
    optimal_input, cell_voltage, compressor_power_W, turbine_power_W, reci_pump_power_W, coolant_pump_power_W, hydrogen_mass_flow_g_s = evaluate_models(result.x)

    # Compute stack power
    stack_power_kW = optimal_input[0] * cell_voltage * cellcount / 1000

    return optimal_input, cell_voltage, hydrogen_mass_flow_g_s, stack_power_kW, compressor_power_W / 1000, turbine_power_W / 1000, \
        reci_pump_power_W / 1000, coolant_pump_power_W / 1000, optimization_converged