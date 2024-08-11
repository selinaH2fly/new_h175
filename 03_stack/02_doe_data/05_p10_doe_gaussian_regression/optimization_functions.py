# Import libraries
import torch
import gpytorch
import numpy as np
from scipy.optimize import differential_evolution, NonlinearConstraint

# Import custom classes and functions
import parameters
#from components import Compressor, Turbine
#TODO: think about the structure again.... import looks shit
from Components.compressor import Compressor
from Components.turbine import Turbine
from basic_physics import compute_air_mass_flow

def optimize_inputs_evolutionary(cell_voltage_model, cathode_pressure_drop_model, flight_level_100ft, cellcount=275, bounds=None, power_constraint_kW=None, penalty_weight=0.1, params_physics=None, consider_turbine=True, end_of_life=False):
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
    
    # Instantiate classes
    _params_physics = parameters.Physical_Parameters()
    _params_compressor = parameters.Compressor_Parameters()
    compressor = Compressor(_params_physics, isentropic_efficiency=_params_compressor.isentropic_efficiency, 
                            electric_efficiency=_params_compressor.electric_efficiency)
    
    _params_turbine = parameters.Turbine_Parameters()
    turbine = Turbine(_params_physics, isentropic_efficiency=_params_turbine.isentropic_efficiency)

    def evaluate_models(x):
        """
        Helper function to evaluate models and compute necessary values.

        Parameters:
        - x: Normalized input variables.

        Returns:
        - optimal_input: Denormalized optimal input variables.
        - cell_voltage: Denormalized cell voltage.
        - compressor_power_W: Computed compressor power.
        - turbine_power_W: Computed turbine power.
        - hydrogen_mass_flow_g_s: Computed hydrogen mass flow rate.
        """
        # Evaluate the cell voltage model
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)
        cell_voltage_model.model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            cell_voltage = cell_voltage_model.model(x_tensor).mean.item()

        # Denormalize
        optimal_input = x * np.array(cell_voltage_model.input_data_std) + np.array(cell_voltage_model.input_data_mean)
        cell_voltage = cell_voltage * cell_voltage_model.target_data_std + cell_voltage_model.target_data_mean

        # Consider the end of life derating factor
        if end_of_life:
            cell_voltage *= 0.9

        # Compute air massflow
        air_mass_flow_kg_s = compute_air_mass_flow(stoichiometry=optimal_input[2], current_A=optimal_input[0], cellcount=cellcount)
        
        #Set Parameters for compressor:
        compressor.air_mass_flow_kg_s = air_mass_flow_kg_s
        compressor.pressure_out_Pa = optimal_input[3]*1e5
        compressor.flight_level_100ft = flight_level_100ft
        
        #Calculat compressor power
        compressor_power_W = compressor.calculate_power()

        if consider_turbine:
            # Normalize current, stoichiometry, and pressure and temperature for evaluating the cathode pressure drop model
            current_for_dp_normalized = (optimal_input[0] - cathode_pressure_drop_model.input_data_mean[0]) / cathode_pressure_drop_model.input_data_std[0]
            stoichiometry_for_dp_normalized = (optimal_input[2] - cathode_pressure_drop_model.input_data_mean[1]) / cathode_pressure_drop_model.input_data_std[1]
            pressure_for_dp_normalized = (optimal_input[3] - cathode_pressure_drop_model.input_data_mean[2]) / cathode_pressure_drop_model.input_data_std[2]
            temperature_for_dp_normalized = (optimal_input[4] - cathode_pressure_drop_model.input_data_mean[3]) / cathode_pressure_drop_model.input_data_std[3]
            x_tensor = torch.tensor([current_for_dp_normalized, stoichiometry_for_dp_normalized, pressure_for_dp_normalized, temperature_for_dp_normalized], dtype=torch.float).unsqueeze(0)

            # Evaluate the cathode pressure drop model
            cathode_pressure_drop_model.model.eval()
            with torch.no_grad(), gpytorch.settings.fast_pred_var():
                cathode_pressure_drop = cathode_pressure_drop_model.model(x_tensor).mean.item()

            # Denormalize
            cathode_pressure_drop_bar = cathode_pressure_drop * cathode_pressure_drop_model.target_data_std \
                + cathode_pressure_drop_model.target_data_mean
            
            # Limit the cathode pressure drop to be non-negative
            cathode_pressure_drop_bar = max(cathode_pressure_drop_bar.item(), 0)
            
            # Compute the cathode pressure out        
            cathode_pressure_out_bar = optimal_input[3] - cathode_pressure_drop_bar

            #Set Parameters for turbine
            turbine.air_mass_flow_kg_s = air_mass_flow_kg_s
            turbine.pressure_in_Pa     = cathode_pressure_out_bar*1e5
            turbine.temperature_in_K   = optimal_input[5]+273.15 
            turbine.flight_level_100ft = flight_level_100ft
            
            # Compute the turbine power        
            turbine_power_W = turbine.calculate_power()
            
            # Limit the turbine power to not exceed the compressor power
            turbine_power_W = min(turbine_power_W, compressor_power_W)
        else:
            turbine_power_W = 0

        # Compute the hydrogen mass flow rate
        hydrogen_mass_flow_g_s = optimal_input[0] * cellcount * params_physics.hydrogen_molar_mass / (2 * params_physics.faraday) * 1000

        return optimal_input, cell_voltage, compressor_power_W, turbine_power_W, hydrogen_mass_flow_g_s

    # Normalize the bounds
    normalized_bounds = [((min_val - mean) / std, (max_val - mean) / std ) for (min_val, max_val), mean, std in \
                         zip(bounds, cell_voltage_model.input_data_mean.numpy(), cell_voltage_model.input_data_std.numpy())]

    # Define the objective function for optimization
    def objective_function(x):

        # Evaluate the models with the normalized input
        optimal_input, cell_voltage, compressor_power_W, turbine_power_W, hydrogen_mass_flow_g_s = evaluate_models(x)
        
        # Compute the penalty term for the power constraint
        if power_constraint_kW is not None:
            power_constraint = cell_voltage * cellcount * optimal_input[0] - compressor_power_W + turbine_power_W \
                  - power_constraint_kW * 1000
            penalty = penalty_weight * (power_constraint**2)
        else:
            penalty = 0
        
        return hydrogen_mass_flow_g_s + penalty
    
    # Define the nonlinear constraint for the (denormalized) coolant temperatures: T_C_out - T_C_in >= 5 K
    def nonlinear_constraint(x):
        return (x[5]*np.array(cell_voltage_model.input_data_std[5]) + np.array(cell_voltage_model.input_data_mean[5])) \
            - (x[4]*np.array(cell_voltage_model.input_data_std[4]) + np.array(cell_voltage_model.input_data_mean[4])) - 5
    
    nonlinear_constraint = NonlinearConstraint(nonlinear_constraint, 0, np.inf)

    # Perform the optimization using differential evolution
    result = differential_evolution(objective_function, normalized_bounds, constraints=nonlinear_constraint, maxiter=1000, popsize=30, tol=1e-6, recombination=0.9, polish=False, disp=False, seed=None)
    print(f'{result.message}')

    # Evaluate the models with the optimal input
    optimal_input, cell_voltage, compressor_power_W, turbine_power_W, hydrogen_mass_flow_g_s = evaluate_models(result.x)

    # Convert powers from W to kW
    stack_power_kW = optimal_input[0] * cell_voltage * cellcount / 1000
    compressor_power_kW = compressor_power_W / 1000
    turbine_power_kW = turbine_power_W / 1000

    return optimal_input, cell_voltage, hydrogen_mass_flow_g_s, stack_power_kW, compressor_power_kW, turbine_power_kW