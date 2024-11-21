# Import libraries
import torch
import gpytorch
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from scipy.optimize import differential_evolution, NonlinearConstraint
from scipy.spatial import ConvexHull, Delaunay
import CoolProp.CoolProp as CP
from scipy.constants import physical_constants
import alphashape
import os

# Import custom classes and functions
import parameters
from parameters import VariableContainer
import data_processing 
from Components.compressor import Compressor
from Components.turbine import Turbine
from Components.recirculation_pump import Recirculation_Pump
from Components.coolant_pump import Coolant_Pump
from Components.radiator import Radiator
from Components.stack import Stack
from Components.tank import Tank
from Components.heat_exchanger import Intercooler, Evaporator
from basic_physics import compute_air_mass_flow, icao_atmosphere, convert
from mass_estimation import sum_fixed_mass, sum_power_dependent_mass, sum_cellcount_dependent_mass
from shapely.geometry import Point

def alphashape_function(DoE_data, alpha):
    points = np.array(DoE_data, dtype=float)
    alpha_shape = alphashape.alphashape(points, alpha)
    
    
    #is_inside = alpha_shape.contains(optimized_point)
    # Separate points that are inside the alpha shape
    inside_points = [point for point in points if alpha_shape.contains(Point(point))]  # Unpack each point
    outside_points = [point for point in points if not alpha_shape.contains(Point(point))]  # Unpack each point
    # Convert lists to numpy arrays for easy plotting
    inside_points = np.array(inside_points)
    outside_points = np.array(outside_points)
    # Plot the alpha shape boundary and points

    # # Plot points inside the alpha shape in blue
    # plt.scatter(inside_points[:, 0], inside_points[:, 1], color='blue', label='Inside Points')

    # # Plot points outside the alpha shape in red
    # plt.scatter(outside_points[:, 0], outside_points[:, 1], color='red', label='Outside Points')

    # # Plot the alpha shape boundary
    # if alpha_shape.geom_type == 'Polygon':
    #     x, y = alpha_shape.exterior.xy
    #     plt.plot(x, y, color='green', linewidth=2, label='Alpha Shape Boundary')
    #     #plt.plot(random_point[0],random_point[1], "ko")
    # elif alpha_shape.geom_type == 'MultiPolygon':
    #     for polygon in alpha_shape:
    #         x, y = polygon.exterior.xy
    #         plt.plot(x, y, color='green', linewidth=2)
    # #plt.xlim(0, 750)
    # plt.ylim(0,max(outside_points[:, 1]))
    # plt.xlabel("X-coordinate")
    # plt.ylabel("Y-coordinate")

    # plt.title("Alpha Shape with Inside and Outside Points")
    # plt.legend()
    # plt.grid(True)
    # plt.show()
    
    return alpha_shape

def optimize_inputs_evolutionary(cell_voltage_model, cathode_pressure_drop_model, anode_pressure_drop_model, flight_level_100ft, cellcount=275,
                                 power_constraint_kW=None, consider_turbine=True, compressor_map=None, end_of_life=False,
                                 multiobjective_weighting=0, constraint=True):
    """
    Optimize the (cell) voltage predicted by the GPyTorch model with a (cell) power constraint using differential evolution.

    Parameters:
    - cell_voltage_model: The trained GPyTorch model (alongside likelihood and input/target data statistics).
    - cathode_pressure_drop_model: The trained GPyTorch model for the cathode pressure drop. (alongside likelihood and input/target data statistics).
    - flight_level_100ft: Flight level in 100 feet units.
    - cellcount: Number of cells.
    - power_constraint_kW: Power constraint in kilowatts.
    - consider_turbine: Whether to consider power recuperation in the optimization.
    - compressor_map: The compressor map to be used in the optimization.
    - end_of_life: Whether to consider the end of life derating factor.

    Returns:
    - optimal_input: The optimal input values in the original scale.
    - hydrogen_mass_flow_g_s: The minimized target.
    - compressor_power: The power of the compressor.
    """
    
    # Load parameters
    _params_optimization = parameters.Optimization_Parameters()
    _params_assumptions = parameters.Assumptions()
    _params_compressor = parameters.Compressor_Parameters()
    _params_turbine = parameters.Turbine_Parameters()
    _params_recirculation_pump = parameters.Recirculation_Pump_Parameters()
    _params_coolant_pump = parameters.Coolant_Pump_Parameters()
    _params_radiator = parameters.Radiator_Parameters()
    _params_stack = parameters.Stack_Parameters()
    _params_Eol = parameters.Eol_Parameters()
    _params_physics = parameters.Physical_Parameters()
    _params_intercooler = parameters.Intercooler_Parameters()
    _params_evaporator = parameters.Evaporator_Parameters()
    _params_tank = parameters.Tank_Parameters()
    _params_mass = parameters.Mass_Parameters()
    _params_assumptions = parameters.Assumptions()
    
    # Load DoE-Data 
    DoE_data, _ = data_processing.load_high_amp_doe_data()

    # reduce DoE-Data to optimized parameters
    Optimized_DoE_data_variables = data_processing.voltage_input_data_dict(DoE_data,_params_physics)
    Optimized_DoE_data_variables = pd.DataFrame(Optimized_DoE_data_variables)
    columns_list = Optimized_DoE_data_variables.columns.tolist()
    # cut DoE data at upper bounds
    for i in range((len(_params_optimization.bounds))):
        if i != 0:
            Optimized_DoE_data_variables.loc[Optimized_DoE_data_variables[columns_list[i]]>_params_optimization.bounds[i][1], columns_list[i]] = _params_optimization.bounds[i][1]


    # define alpha shape function

        ## Alpha Value Info
    # cathode_rh = 0.01
    # stoich cathode = 0.001
    # cathode pressure =0.001
    # coolant in = 0.005
    # coolant out = 0.005
    # stoich anode = 0.001
    # pressure anode = 0

    alphashape_cathode_rh = alphashape_function(Optimized_DoE_data_variables[["current_A","cathode_rh_in_perc"]], 0.01)
    alphashape_stoich_cathode = alphashape_function(Optimized_DoE_data_variables[["current_A","stoich_cathode"]], 0.001)
    alphashape_pressure_cathode = alphashape_function(Optimized_DoE_data_variables[["current_A","pressure_cathode_in_bara"]], 0.001)
    alphashape_temp_coolant_in = alphashape_function(Optimized_DoE_data_variables[["current_A","temp_coolant_inlet_degC"]], 0.005)
    alphashape_temp_coolant_out = alphashape_function(Optimized_DoE_data_variables[["current_A","temp_coolant_outlet_degC"]], 0.005)
    alphashape_stoich_anode = alphashape_function(Optimized_DoE_data_variables[["current_A","stoich_anode"]], 0.001)
    alphashape_pressure_anode = alphashape_function(Optimized_DoE_data_variables[["current_A","pressure_anode_in_bara"]],0)

    # cut data and build convex hull of DoE parameters for init population
    Optimized_DoE_data_variables_cut = Optimized_DoE_data_variables[::5]
    DoE_envelope = ConvexHull(Optimized_DoE_data_variables_cut.values)
    DoE_envelope_Delaunay = Delaunay(Optimized_DoE_data_variables_cut.values[DoE_envelope.vertices])
       
    # Evaluate ambient conditions
    temperature_ambient_K, pressure_ambient_Pa = icao_atmosphere(flight_level_100ft)

    # Consider the compressor map if provided
    compressor_map = getattr(_params_compressor, "compressor_map_" + compressor_map) if compressor_map else None


    # Instantiate components
    compressor      =   Compressor(mass_estimator=_params_mass, isentropic_efficiency=_params_compressor.isentropic_efficiency,
                                   electric_efficiency=_params_compressor.electric_efficiency,
                                   temperature_in_K=temperature_ambient_K, pressure_in_Pa=pressure_ambient_Pa,
                                   nominal_BoP_pressure_drop_Pa=_params_compressor.nominal_BoP_pressure_drop_Pa,
                                   compressor_map=compressor_map, nominal_air_flow_kg_s=_params_compressor.nominal_air_flow_kg_s,
                                   reference_ambient_conditions=(_params_compressor.reference_pressure_Pa, _params_compressor.reference_temperature_K))
    

    turbine         =   Turbine(mass_estimator=_params_mass, isentropic_efficiency=_params_turbine.isentropic_efficiency,
                                temperature_out_K=temperature_ambient_K, pressure_out_Pa=pressure_ambient_Pa,
                                nominal_BoP_pressure_drop_Pa=_params_turbine.nominal_BoP_pressure_drop_Pa,
                                nominal_air_flow_kg_s=_params_turbine.nominal_air_flow_kg_s)
    
    reci_pump       =   Recirculation_Pump(mass_estimator=_params_mass, isentropic_efficiency=_params_recirculation_pump.isentropic_efficiency,
                                           electric_efficiency=_params_recirculation_pump.electric_efficiency,
                                           n_cell=cellcount, cell_area_m2=_params_stack.cell_area_m2,
                                           fixed_recirculation_ratio=_params_recirculation_pump.fixed_recirculation_ratio,
                                           nominal_BoP_pressure_drop_Pa=_params_recirculation_pump.nominal_BoP_pressure_drop_Pa)
    
    coolant_pump_ht =   Coolant_Pump(isentropic_efficiency=_params_coolant_pump.isentropic_efficiency,
                                     electric_efficiency=_params_coolant_pump.electric_efficiency)
    
    # virtual LT coolant pump for straight-forward power computation
    coolant_pump_lt =   Coolant_Pump(isentropic_efficiency=_params_coolant_pump.isentropic_efficiency,
                                     electric_efficiency=_params_coolant_pump.electric_efficiency)
    
    radiator        =   Radiator(nominal_pressure_drop_Pa=_params_radiator.nominal_pressure_drop_Pa,
                                 nominal_coolant_flow_m3_s=_params_radiator.nominal_coolant_flow_m3_s)
    
    stack           =   Stack(cellcount=cellcount, anode_pressure_drop_coefficients=_params_stack.anode_pressure_drop_coefficients,
                              cooling_pressure_drop_coefficients=_params_stack.cooling_pressure_drop_coefficients)
    
    intercooler     =   Intercooler(efficiency=_params_intercooler.efficiency, primary_fluid = _params_intercooler.primary_fluid , coolant_fluid=_params_intercooler.primary_fluid , ALLOWED_FLUIDS=_params_intercooler.ALLOWED_FLUIDS)
    
    evaporator      =   Evaporator(efficiency=_params_evaporator.efficiency, primary_p_in_Pa = _params_evaporator.primary_p_in_Pa,  primary_fluid = _params_evaporator.primary_fluid , coolant_fluid=_params_evaporator.primary_fluid , ALLOWED_FLUIDS=_params_evaporator.ALLOWED_FLUIDS)

    tank            =   Tank(massfraction=_params_tank.massfraction , H2_mass_kg=0 , fixed_mass_kg=_params_tank.fixed_mass_kg , pressure_bar=_params_tank.pressure_bar )
    
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
        ...
        """
        
        from parameters import VariableContainer

        # Directly use the namedtuple to create instances
        ResultModels = VariableContainer()
        
        # %% Cell Voltage Model

        # Evaluate the cell voltage model
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)

        cell_voltage_model.model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            cell_voltage = cell_voltage_model.model(x_tensor).mean.item()

        # Denormalize
        optimized_input = x * np.array(cell_voltage_model.input_data_std) + np.array(cell_voltage_model.input_data_mean)
        optimized_cell_voltage_V = (cell_voltage * cell_voltage_model.target_data_std + cell_voltage_model.target_data_mean).numpy()

        # Assign the optimal input values to the corresponding variables for better readability
        optimized_current_A = optimized_input[0]
        # optimized_cathode_rh_in_perc = optimized_input[1]
        optimized_stoich_cathode = optimized_input[2]
        optimized_pressure_cathode_in_bara = optimized_input[3]
        optimized_temp_coolant_inlet_degC = optimized_input[4]
        optimized_temp_coolant_outlet_degC = optimized_input[5]
        optimized_stoich_anode = optimized_input[6]
        optimized_pressure_anode_in_bara = optimized_input[7]

        # Consider the end of life derating factor which is linearly dependent on the current density
        if end_of_life:
            current_density_A_m2 = optimized_current_A / _params_stack.cell_area_m2
            derating_factor = 1 - (1 - _params_Eol.reference_derating_factor)/_params_Eol.reference_current_density_A_m2 * current_density_A_m2
            optimized_cell_voltage_V *= derating_factor

# %% Stack
        # Set stack attributes:
        stack.current_A = optimized_current_A
        stack.cell_voltage_V = optimized_cell_voltage_V
        stack.temp_coolant_in_K = convert(optimized_temp_coolant_inlet_degC, "degC", "K")
        stack.temp_coolant_out_K = convert(optimized_temp_coolant_outlet_degC, "degC", "K")
        
        # Compute the coolant flow rate
        stack.coolant_flow_m3_s = stack.calculate_coolant_flow(pressure_ambient_Pa)
        
        # Compute the pressure drop across the stack
        stack_pressure_drop_Pa = stack.calculate_pressure_drop_cooling() # TODO: include stack pressure drop GPR model; caution: High-Amp DoE s.t. water as a coolant!
        
        # Compute heat produced by the stack:
        stack_heat_flux_W = stack.calculate_heat_flux()
        
# %% Compressor and Turbine

        # Set compressor attributes
        compressor.air_mass_flow_kg_s = compute_air_mass_flow(stoichiometry=optimized_stoich_cathode, current_A=optimized_current_A, cellcount=cellcount)
        compressor.pressure_out_Pa = convert(optimized_pressure_cathode_in_bara, "bara", "Pa") + compressor.calculate_BoP_pressure_drop() # compressor_out == cathode_in + BoP_pressure_drop (compressor out -> cathode in)
        compressor.temperature_out_K = compressor.calculate_T_out()
        # Calculate compressor power
        compressor_power_W = compressor.calculate_power()

        # TODO: Move the turbine computations to a separate function
        if consider_turbine:

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

            # Set turbine attributes
            turbine.air_mass_flow_kg_s = compute_air_mass_flow(stoichiometry=optimized_stoich_cathode, current_A=optimized_current_A, cellcount=cellcount)
            turbine.pressure_in_Pa     = max(convert(cathode_pressure_out_bar, "bar", "Pa") - turbine.calculate_BoP_pressure_drop(), 1e-9) # turbine_in == cathode_out - BoP_pressure_drop (cathode out -> turbine in)
            turbine.temperature_in_K   = max(convert(optimized_temp_coolant_outlet_degC, "degC", "K"), 1e-9) 
            
            # Compute the turbine power        
            turbine_power_W = turbine.calculate_power()
            
            # Limit the turbine power to not exceed the compressor power
            turbine_power_W = min(turbine_power_W, compressor_power_W)
        else:
            turbine_power_W = 0

        # %% Recirculation Pump

        # Set recirculation pump attributes
        reci_pump.current_A = optimized_current_A
        reci_pump.temperature_in_K = convert(optimized_temp_coolant_outlet_degC,"degC","K")
        reci_pump.pressure_out_Pa = convert(optimized_pressure_anode_in_bara,"bara",'Pa')    # reci_out == anode_in \approx: cathode_in + 0.2 bar (cf. PowerLayout); TODO: include p_anode_in in cell voltage model
        reci_pump.stoich_anode = optimized_stoich_anode                                                 # TODO: include anode stoichiometry in cell voltage model

        # Estimate the anode pressure drop         
        anode_pressure_drop_Pa = stack.calculate_pressure_drop_anode(anode_pressure_drop_model, optimized_current_A, optimized_stoich_anode, optimized_pressure_anode_in_bara, optimized_temp_coolant_inlet_degC)
        
        # Compute the cathode pressure out        
        anode_pressure_out_Pa = convert(optimized_pressure_anode_in_bara,"bara",'Pa') - anode_pressure_drop_Pa

        # Estimate the BoP pressure drop in the recirculation loop
        #anode_BoP_pressure_drop_Pa = reci_pump.calculate_BoP_pressure_drop()

        # Compute the pressure at the anode outlet
        reci_pump.pressure_in_Pa = anode_pressure_out_Pa #max(reci_pump.pressure_out_Pa -
                                       #anode_pressure_drop_Pa -
                                       #anode_BoP_pressure_drop_Pa, 1e-9) # reci_in == anode_out \approx: anode_in - dp_anode; TODO: include DoE data-based GPR anode pressure drop model
        
        # Compute the recirculation pump power
        reci_pump_power_W = reci_pump.calculate_power()

        # %% Coolant Pump

        # Compute the pressure drop across the radiator        
        radiator.coolant_flow_m3_s = stack.coolant_flow_m3_s # TODO: This ignores the TCV split between radiator and stack. Improve.
        radiator_pressure_drop_Pa = radiator.calculate_pressure_drop()

        # Compute the coolant pump power for the HT circuit
        coolant_pump_ht.coolant_flow_m3_s = stack.coolant_flow_m3_s
        coolant_pump_ht.head_Pa = stack_pressure_drop_Pa + radiator_pressure_drop_Pa # coolant_pump.head_Pa = stack_pressure_drop + radiator_pressure_drop (including 0.1 bar additional HT pressure drop)
        
        # Compute the (virtual) coolant pump power for the LT circuit (assuming a constant flow rate)
        coolant_pump_lt.coolant_flow_m3_s = _params_coolant_pump.nominal_coolant_flow_lt_m3_s
        coolant_pump_lt.head_Pa = _params_coolant_pump.nominal_pressure_drop_lt_Pa

        # Compute the actual coolant pump power
        coolant_pump_power_W = coolant_pump_ht.calculate_power() + coolant_pump_lt.calculate_power()

        # %% Intercooler
        #set T, p and m_dots here

        intercooler.primary_T_in_K = compressor.temperature_out_K
        intercooler.primary_T_out_K = convert(optimized_temp_coolant_inlet_degC,"degC",  "K")
        intercooler.primary_mdot_in_kg_s = compressor.air_mass_flow_kg_s
        intercooler.primary_p_in_Pa = compressor.pressure_out_Pa
        
        #TODO: Implement this if needed for Coolant_T increase
        # intercooler.coolant_T_in_K = #Evap t out
        # intercooler.coolant_T_out_K = # berechnen
        # intercooler.coolant_mdot_in_kg_s = #?
        # intercooler.coolant_p_in_Pa = #?
        
        #intercooler_T_out_K = intercooler.calculate_coolant_T_out()
        #intercooler.coolant_T_out_K = intercooler_T_out_K
        
        # Compute heat flux of intercooler
        intercooler_heat_flux_W = intercooler.calculate_heat_flux("primary")
        
        # %% Consumed hydrogen mass flow rate

        # Compute the hydrogen mass flow rate (supply = const. * consumption)
        hydrogen_consumption_rate_g_s = stack.current_A * stack.cellcount * CP.PropsSI('M', 'Hydrogen') / \
            (2 * (physical_constants['Faraday constant'][0])) * 1000
        hydrogen_supply_rate_g_s = hydrogen_consumption_rate_g_s * (1 + _params_assumptions.hydrogen_loss_factor)
        
        # %% Evaporator:
        evaporator.primary_T_in_K = _params_evaporator.primary_T_in_K
        evaporator.primary_T_out_K = _params_evaporator.primary_T_out_K
        evaporator.primary_mdot_in_kg_s = hydrogen_supply_rate_g_s/1000 #g -> kg
        _evaporator_cp = evaporator.calculate_specific_heat(evaporator.primary_fluid, evaporator.primary_T_in_K, evaporator.primary_T_out_K, evaporator.primary_p_in_Pa, 10)
        evaporator_heat_flux_W = evaporator.calculate_heat_flux("primary", _evaporator_cp, _params_physics.evaporation_enthalpy_J_kg)
        
        # %% Radiator
        
        radiator.thermal_power_W = (stack_heat_flux_W + intercooler_heat_flux_W + evaporator_heat_flux_W)
        radiator_heat_flux_W = radiator.thermal_power_W
        radiator_mass_kg = radiator.calculate_mass(stack.temp_coolant_out_K - 273.15)
        
        # %% Tank:
        flightduration_h = _params_assumptions.flightduration_h #X h Flight time, e.g. 4 h
        tank.H2_mass_kg = tank.calculate_H2_mass(flightduration_h, hydrogen_supply_rate_g_s) 
        _, tank_mass_wet_kg = tank.calculate_mass() # We only need wet mass atm
            
        # %% Compute System Mass
        # fixed or constant masses:
        fixed_mass, _ = sum_fixed_mass(_params_mass.masses_FCM_constants)
        #masses which depend on Power:
        compressor_mass_kg = compressor.calculate_mass()["mean"]
        rezi_pump_mass_kg = reci_pump.calculate_mass()["mean"]
        coolant_pump_mass_kg = coolant_pump_ht.calculate_mass()["mean"]
        
        power_dependent_mass = sum([compressor_mass_kg, #Compressor + Turbine
                                rezi_pump_mass_kg, 
                                coolant_pump_mass_kg,
                                radiator_mass_kg #if only "Module" masses are wanted: set to 0
                                ])
        
        #Other dependend masses:
        cellcount_dependent_mass = stack.calculate_mass()
        H2_dependend_mass = tank_mass_wet_kg #if only "Module" masses are wanted: set to 0
        
        system_mass_kg = fixed_mass + power_dependent_mass + cellcount_dependent_mass + H2_dependend_mass
        
        # %% Return
        ResultModels.update(optimized_input=optimized_input,
                            optimized_cell_voltage_V=optimized_cell_voltage_V,
                            compressor_power_W=compressor_power_W,
                            turbine_power_W=turbine_power_W,
                            reci_pump_power_W=reci_pump_power_W,
                            coolant_pump_power_W=coolant_pump_power_W,
                            
                            stack_heat_flux_W=stack_heat_flux_W,
                            intercooler_heat_flux_W=intercooler_heat_flux_W,
                            evaporator_heat_flux_W=evaporator_heat_flux_W,
                            radiator_heat_flux_W=radiator_heat_flux_W,
                            
                            hydrogen_supply_rate_g_s=hydrogen_supply_rate_g_s,
                            system_mass_kg=system_mass_kg,
                            fixed_mass=fixed_mass, 
                            power_dependent_mass=power_dependent_mass,
                            compressor_mass_kg=compressor_mass_kg, 
                            rezi_pump_mass_kg=rezi_pump_mass_kg, 
                            coolant_pump_mass_kg=coolant_pump_mass_kg, 
                            radiator_mass_kg=radiator_mass_kg,
                            cellcount_dependent_mass=cellcount_dependent_mass, 
                            H2_dependend_mass=H2_dependend_mass,
                            cell_voltage_V=stack.cell_voltage_V
                            )
        return ResultModels.result 

    #optimized_input, optimized_cell_voltage_V, compressor_power_W, turbine_power_W, reci_pump_power_W, \
     #       coolant_pump_power_W, hydrogen_supply_rate_g_s, system_mass_kg

# %% Optimization

    # Define the objective function for optimization
    def objective_function(x):

        # Evaluate the models with the normalized input
        result_models = evaluate_models(x)
        hydrogen_supply_rate_g_s =result_models.hydrogen_supply_rate_g_s  
        system_mass_kg = result_models.system_mass_kg

        # Scale the system mass such that 2 g/s hydrogen supply rate is equivalent to 100 kg system mass
        system_mass_equivalent = system_mass_kg / 100 * 2

        # Compute the objective function
        objective = hydrogen_supply_rate_g_s * (1 - multiobjective_weighting) + system_mass_equivalent * multiobjective_weighting

        return objective
   
   # Constraint to ensure that the specified system net power is met
    def nonlinear_constraint_Power(x):
        #optimal_input, cell_voltage, compressor_power_W, turbine_power_W, reci_pump_power_W, coolant_pump_power_W, _, _ = evaluate_models(x)
        # Access only the required results by name
        result_models = evaluate_models(x)
        optimal_input = result_models.optimized_input
        cell_voltage = result_models.optimized_cell_voltage_V
        compressor_power_W = result_models.compressor_power_W
        turbine_power_W = result_models.turbine_power_W
        reci_pump_power_W = result_models.reci_pump_power_W
        coolant_pump_power_W = result_models.coolant_pump_power_W

        power_balance_offset = cell_voltage * cellcount * optimal_input[0] \
            - compressor_power_W + turbine_power_W - reci_pump_power_W  - coolant_pump_power_W \
                - power_constraint_kW * 1000

        return power_balance_offset        

    # Constraint to ensure that the coolant outlet temperature is higher than the inlet temperature
    def nonlinear_constraint_Temp(x):

        return (x[5]*np.array(cell_voltage_model.input_data_std[5]) + np.array(cell_voltage_model.input_data_mean[5])) \
            - (x[4]*np.array(cell_voltage_model.input_data_std[4]) + np.array(cell_voltage_model.input_data_mean[4]))
    
    def nonlinear_constraint_Anode_Pressure(x):

        return (x[7]*np.array(cell_voltage_model.input_data_std[7]) + np.array(cell_voltage_model.input_data_mean[7])) \
            - (x[3]*np.array(cell_voltage_model.input_data_std[3]) + np.array(cell_voltage_model.input_data_mean[3]))

    def nlc_DoE_cathode_rh(x):
        x_scaled = np.array([x[index]*np.array(cell_voltage_model.input_data_std[index]) + np.array(cell_voltage_model.input_data_mean[index]) for index in range(len(x))])
        is_inside = alphashape_cathode_rh.contains(Point(x_scaled[[0,1]]))

        return 1 if is_inside else -1

    def nlc_DoE_cathode_stoich(x):
        x_scaled = np.array([x[index]*np.array(cell_voltage_model.input_data_std[index]) + np.array(cell_voltage_model.input_data_mean[index]) for index in range(len(x))])
        is_inside = alphashape_stoich_cathode.contains(Point(x_scaled[[0,2]]))

        return 1 if is_inside else -1

    def nlc_DoE_pressure_stack(x):
        x_scaled = np.array([x[index]*np.array(cell_voltage_model.input_data_std[index]) + np.array(cell_voltage_model.input_data_mean[index]) for index in range(len(x))])
        is_inside_cathode = alphashape_pressure_cathode.contains(Point(x_scaled[[0,3]]))
        is_inside_anode = alphashape_pressure_anode.contains(Point(x_scaled[[0,7]]))
        pressure_delta = (x[7]*np.array(cell_voltage_model.input_data_std[7]) + np.array(cell_voltage_model.input_data_mean[7])) \
        - (x[3]*np.array(cell_voltage_model.input_data_std[3]) + np.array(cell_voltage_model.input_data_mean[3]))
        return 1 if is_inside_cathode and is_inside_anode and 0.55 >= pressure_delta >= 0.05 else -1
    
    def nlc_DoE_coolant(x):
        x_scaled = np.array([x[index]*np.array(cell_voltage_model.input_data_std[index]) + np.array(cell_voltage_model.input_data_mean[index]) for index in range(len(x))])
        is_inside_coolant_in = alphashape_temp_coolant_in.contains(Point(x_scaled[[0,4]]))
        is_inside_coolant_out = alphashape_temp_coolant_out.contains(Point(x_scaled[[0,5]]))
        coolant_delta = (x[5]*np.array(cell_voltage_model.input_data_std[5]) + np.array(cell_voltage_model.input_data_mean[5])) \
            - (x[4]*np.array(cell_voltage_model.input_data_std[4]) + np.array(cell_voltage_model.input_data_mean[4]))
        return 1 if is_inside_coolant_in and is_inside_coolant_out and coolant_delta > 1e-3 else -1
    
    def nlc_DoE_anode_stoich(x):
        x_scaled = np.array([x[index]*np.array(cell_voltage_model.input_data_std[index]) + np.array(cell_voltage_model.input_data_mean[index]) for index in range(len(x))])
        is_inside = alphashape_stoich_anode.contains(Point(x_scaled[[0,6]]))

        return 1 if is_inside else -1


    # Check for DoE constraint setting and define the nonlinear constraints
    nlc_power = NonlinearConstraint(nonlinear_constraint_Power, 0, 1000)
    nlc_temp = NonlinearConstraint(nonlinear_constraint_Temp, 1e-3, np.inf)
    nlc_anode = NonlinearConstraint(nonlinear_constraint_Anode_Pressure,0,np.inf)
    nlc_DoE_rh = NonlinearConstraint(nlc_DoE_cathode_rh,0, np.inf)
    nlc_DoE_cath_stoich = NonlinearConstraint(nlc_DoE_cathode_stoich,0, np.inf)
    nlc_DoE_stack_pressure = NonlinearConstraint(nlc_DoE_pressure_stack,0, np.inf)
    nlc_DoE_coolantPump = NonlinearConstraint(nlc_DoE_coolant,0, np.inf)
    nlc_DoE_an_stoich = NonlinearConstraint(nlc_DoE_anode_stoich,0, np.inf)
    
    if constraint:            
        nlc = [nlc_power, nlc_DoE_rh, nlc_DoE_cath_stoich, nlc_DoE_stack_pressure, nlc_DoE_coolantPump, nlc_DoE_an_stoich]
    else:
        nlc = [nlc_power, nlc_temp, nlc_anode]

    # Normalize the bounds
    normalized_bounds = [((min_val - mean) / std, (max_val - mean) / std ) for (min_val, max_val), mean, std in \
                         zip(_params_optimization.bounds, cell_voltage_model.input_data_mean.numpy(), cell_voltage_model.input_data_std.numpy())]

    def pop_init():
        """
        Function to generate a initilization population to accelerate convergence

        Returns:
        - population that is defined between the bounds and the DoE envelope
        """

        #define current bounds by initial voltage and brutto deviation
        current_lower = power_constraint_kW*1000/_params_optimization.init_cell_voltage/cellcount
        current_upper =power_constraint_kW*1000*_params_optimization.brutto_deviation/_params_optimization.init_cell_voltage/cellcount
        adjusted_lower = Optimized_DoE_data_variables[Optimized_DoE_data_variables['current_A'] < current_lower]['current_A'].max()
        adjusted_upper = Optimized_DoE_data_variables[Optimized_DoE_data_variables['current_A'] > current_upper]['current_A'].min()
        if pd.isna(adjusted_lower):
            adjusted_lower = Optimized_DoE_data_variables['current_A'].min()
        if pd.isna(adjusted_upper):
            adjusted_upper = Optimized_DoE_data_variables['current_A'].max()
        filtered_DoE = Optimized_DoE_data_variables[(Optimized_DoE_data_variables['current_A'] >= adjusted_lower) & (Optimized_DoE_data_variables['current_A'] <= adjusted_upper)]

        #filter DoE data by min,max bounds of estimatet current
        n_bounds = len(_params_optimization.bounds)
        bounds_pop = np.zeros((n_bounds,2))
        init_pop = np.zeros((_params_optimization.popsize, n_bounds))
        for i, column in enumerate(filtered_DoE.columns):
            bounds_pop[i,0] = filtered_DoE[column].min()
            bounds_pop[i,1] = filtered_DoE[column].max()
        # build init population        
        for i in range(n_bounds):
            lower_bound, upper_bound = bounds_pop[i]
            init_pop[:,i] = np.random.uniform(lower_bound,upper_bound,_params_optimization.popsize)
        
        def is_inside_convex_hull(point,delaunay):
            return delaunay.find_simplex(point)>=0
        
        def generate_point_in_doe_envelope(delaunay, bounds):
            while True:
                DoE_point = np.random.uniform(low=bounds[:, 0], high=bounds[:, 1])
                if delaunay.find_simplex(DoE_point) >=0:
                    return DoE_point                    
        def evaluate_pop_in_DoE(points, delaunay):
            points_scaled = points*cell_voltage_model.input_data_std.numpy()+cell_voltage_model.input_data_mean.numpy()
            simplex = delaunay.find_simplex(points_scaled)
            num_simplex = np.sum(simplex)
            outside_simplex = np.sum(simplex== -1)
            return num_simplex, outside_simplex
        
        #fit init population into DoE envelope
        adjusted_pop_init = []
        for point in init_pop:
            if is_inside_convex_hull(point, DoE_envelope_Delaunay):
                point = (point-cell_voltage_model.input_data_mean.numpy())/cell_voltage_model.input_data_std.numpy()
                adjusted_pop_init.append(point)
                
            else:
                generated_point = (generate_point_in_doe_envelope(DoE_envelope_Delaunay, bounds_pop)-cell_voltage_model.input_data_mean.numpy())/cell_voltage_model.input_data_std.numpy()
                adjusted_pop_init.append(generated_point)
        adjusted_pop_init = np.array(adjusted_pop_init)
        # pop_init_bounds = np.zeros((2, adjusted_pop_init.shape[1]))
        # pop_init_bounds[0,:] = np.min(adjusted_pop_init, axis=0)
        # pop_init_bounds[1,:] = np.max(adjusted_pop_init, axis=0)
        #all_points, outside_points = evaluate_pop_in_DoE(adjusted_pop_init, DoE_envelope_Delaunay)
        return adjusted_pop_init

    '''
    class ConvergenceTracker:
        """
        Class to get detailed optimization informations and set manual convergence criteria

        Returns:
        - callback[True, False]: return of "True" stops optimizer
        """
        def __init__(self, tolerance=1e-4, window_size=30):
            self.best_objective_values = []  # Stores the best objective values at each iteration
            self.tolerance = tolerance       # Convergence tolerance (10e-4)
            self.window_size = window_size   # The window size (e.g., 30 iterations)

        def __call__(self, xk, convergence):
            # Store the best objective value
            xk_rh = xk[:2]
            current_best_value = objective_function(xk)
            self.best_objective_values.append(current_best_value)
            nlc_Temp_xk = nonlinear_constraint_Temp(xk)
            nlc_Power_xk = nonlinear_constraint_Power(xk)
            nlc_DoE_cathode_rh_xk = nlc_DoE_cathode_rh(xk)
            nlc_DoE_cathode_stoich_xk = nlc_DoE_cathode_stoich(xk)
            nlc_DoE_stack_pressure_xk = nlc_DoE_pressure_stack(xk)
            nlc_DoE_coolantPump_xk = nlc_DoE_coolant(xk)
            nlc_DoE_an_stoich_xk = nlc_DoE_anode_stoich(xk)
            DoE_constraint_xk = np.array([nlc_DoE_cathode_rh(xk), nlc_DoE_cathode_stoich(xk),nlc_DoE_pressure_stack(xk),nlc_DoE_coolant(xk),nlc_DoE_anode_stoich(xk)])

            if len(self.best_objective_values)<self.window_size:
                print(f"Iteration {len(self.best_objective_values)}: Best Objective = {current_best_value:.6f}, nlc_CP = {nlc_Temp_xk.item():.6f}, nlc_Power = {nlc_Power_xk.item():.6f}, nlc_DoE_rh = {nlc_DoE_cathode_rh_xk:.6f}, nlc_DoE_cath_stoich = {nlc_DoE_cathode_stoich_xk:.6f}, nlc_DoE_stack_pressure = {nlc_DoE_stack_pressure_xk:.6f}, nlc_DoE_coolantPump = {nlc_DoE_coolantPump_xk:.6f}, nlc_DoE_an_stoich = {nlc_DoE_an_stoich_xk:.6f}")
                return False

            else:
                # Calculate the average of the last 30 objective values
                recent_values = self.best_objective_values[-self.window_size:]
                average_recent_values = np.mean(recent_values)
                
                # Calculate the difference between the current value and the moving average
                difference_to_avg = np.abs(current_best_value - average_recent_values)
                difference_to_last = np.abs(current_best_value-recent_values[-2])
                

                # Print iteration details
                #print(f"Iteration {len(self.best_objective_values)}: Current Objective = {current_best_value:.6f}, Avg of Last {self.window_size:.6f} = {average_recent_values:.6f}, Difference to avg = {difference_to_avg:.6f}, Difference to last ={difference_to_last:.6f} , nlc_CP = {nlc_CP_xk.item():.6f}, nlc_Power = {nlc_Power_xk.item():.6f}, nlc_DoE = {nlc_DoE_xk.item():.6f}")

                # Check if the difference is less than the tolerance (i.e., convergence criterion)
                if difference_to_avg < self.tolerance and difference_to_last < self.tolerance and 0 <= nlc_Power_xk < 1000 and nlc_Temp_xk>0 and all(x > 0 for x in DoE_constraint_xk):
                    print(f"Iteration {len(self.best_objective_values)}: Best Objective = {current_best_value:.6f}, nlc_Temp = {nlc_Temp_xk.item():.6f}, nlc_Power = {nlc_Power_xk.item():.6f}, nlc_DoE_rh = {nlc_DoE_cathode_rh_xk:.6f}, nlc_DoE_cath_stoich = {nlc_DoE_cathode_stoich_xk:.6f}, nlc_DoE_stack_pressure = {nlc_DoE_stack_pressure_xk:.6f}, nlc_DoE_coolantPump = {nlc_DoE_coolantPump_xk:.6f}, nlc_DoE_an_stoich = {nlc_DoE_an_stoich_xk:.6f}")
                    print("Convergence criterion met! Stopping optimization.")
                    return True  # Return True to stop the optimization early

                else:
                    print(f"Iteration {len(self.best_objective_values)}: Best Objective = {current_best_value:.6f}, nlc_CP = {nlc_Temp_xk.item():.6f}, nlc_Power = {nlc_Power_xk.item():.6f}, nlc_DoE_rh = {nlc_DoE_cathode_rh_xk:.6f}, nlc_DoE_cath_stoich = {nlc_DoE_cathode_stoich_xk:.6f}, nlc_DoE_stack_pressure = {nlc_DoE_stack_pressure_xk:.6f}, nlc_DoE_coolantPump = {nlc_DoE_coolantPump_xk:.6f}, nlc_DoE_an_stoich = {nlc_DoE_an_stoich_xk:.6f}")
                    return False               
'''
    

    # Perform the optimization using differential evolution
    #callback = ConvergenceTracker(tolerance=1e-5, window_size=40) #activate if you need some convergence information
    result = differential_evolution(objective_function, normalized_bounds, constraints=nlc, callback=None,
                                    maxiter=_params_optimization.maxiter, popsize=_params_optimization.popsize,
                                    seed=_params_optimization.seed, recombination=_params_optimization.recombination, strategy=_params_optimization.strategy, 
                                    tol=_params_optimization.tol, polish=False, init=pop_init(), disp=False)#, workers=20
    
    optimization_converged = result.success
    print(f'{result.message}')
    
    DoE_constraint = np.array([nlc_DoE_cathode_rh(result.x), nlc_DoE_cathode_stoich(result.x),nlc_DoE_pressure_stack(result.x),nlc_DoE_coolant(result.x),nlc_DoE_anode_stoich(result.x)])
    #check convergence criteria 
    if optimization_converged:
        if constraint and all(x > 0 for x in DoE_constraint) and 0<=nonlinear_constraint_Power(result.x)<=1000:
            optimization_converged="True"
            print("solution converged")
        elif constraint and (nonlinear_constraint_Power(result.x)<0 or nonlinear_constraint_Power(result.x)>1000 or any(x < 0 for x in DoE_constraint)):
            optimization_converged= "False"
            print("DoE constraint not converged")
        elif nonlinear_constraint_Power(result.x)<0 or nonlinear_constraint_Power(result.x)>1000 or nonlinear_constraint_Anode_Pressure(result.x)<0.05 or nonlinear_constraint_Temp(result.x)<0:
            optimization_converged= "False"
            print("DoEconstraint not converged")
        else:
            optimization_converged="True"
            print("solution converged")
    else:
        optimization_converged="False"
        print("solution not converged")
   


    # Evaluate the models with the optimal input
    # Call evaluate_models and store the result in a variable
    results = evaluate_models(result.x)
    
    # Compute stack power 
    stack_power_W = stack.current_A * stack.cell_voltage_V * stack.cellcount
    
    results = results._replace(
        stack_power_W = stack_power_W,
        compressor_cor_mass_flow_g_s = 1000*compressor.calculate_corrected_mass_flow(),
        compressor_pressure_ratio =  compressor.pressure_out_Pa/compressor.pressure_in_Pa,
        optimization_converged = optimization_converged
        )
    # Plot the compressor map with the optimized operating point highlighted
    if compressor_map is not None:
        compressor.plot_compressor_map()
        
    return results