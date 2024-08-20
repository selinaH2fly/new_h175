# Import libraries
import os
import numpy as np
import torch
import argparse
import random

# Import custom classes and functions
import parameters
from file_handling import create_experiment_folder, load_gpr_model
from optimization_functions import optimize_inputs_evolutionary

from data_export_csv import export_to_csv
 
def optimize_input_variables(power_constraint_kW=75.0, specified_cell_count=275, flight_level_100ft=50, consider_turbine=True, end_of_life=True):
    
    # Load parameters
    _params_optimization = parameters.Optimization_Parameters()  
    _params_pyhsics = parameters.Physical_Parameters()

    # Set the random seed for reproducibility
    if _params_optimization.seed is not None:
        random.seed(_params_optimization.seed)
        np.random.seed(_params_optimization.seed)
        torch.manual_seed(_params_optimization.seed)

    print(f"\nOptimization System (Net) Power Constraint: {power_constraint_kW:.0f} kW")
    print(f"Specified Flight Level: {flight_level_100ft} (100x ft)")
    print(f"Specified Cell Count: {specified_cell_count}")
    
    # Load the trained cell voltage model from the "Trained_Models" folder
    gpr_model_cell_voltage = load_gpr_model(os.path.join(os.getcwd(), "Trained_Models", "gpr_model_cell_voltage.pth"))

    # Load the trained cathode pressure drop model from the "Trained_Models" folder
    gpr_model_cathode_pressure_drop = load_gpr_model(os.path.join(os.getcwd(), "Trained_Models", "gpr_model_cathode_pressure_drop.pth"))

    # Create a folder to store the training results
    create_experiment_folder(_params_optimization=_params_optimization, type='optimization')
    
    # Optimize the input variables
    optimal_input, cell_voltage, hydrogen_mass_flow_g_s, \
        stack_power_kW, compressor_power_kW, turbine_power_kW, \
            reci_pump_power_kW, coolant_pump_power_kW, converged = optimize_inputs_evolutionary(gpr_model_cell_voltage, gpr_model_cathode_pressure_drop,
                                                                                                flight_level_100ft, cellcount=specified_cell_count,
                                                                                                bounds=_params_optimization.bounds, power_constraint_kW=power_constraint_kW,
                                                                                                penalty_weight=1e-7, params_physics=_params_pyhsics,
                                                                                                consider_turbine=consider_turbine, end_of_life=end_of_life)
    
    system_power_kW = stack_power_kW - compressor_power_kW + turbine_power_kW - reci_pump_power_kW - coolant_pump_power_kW

    # Print the optimal input, target variables, and bounds including feature names and target variable
    print("\nOptimized Input Variables:")
    for name, value, bound in zip(gpr_model_cell_voltage.feature_names, optimal_input, _params_optimization.bounds):
        lower_bound_formatted = f"{bound[0]}" if abs(bound[0]) < 1000 else f"{bound[0]:.1e}"
        upper_bound_formatted = f"{bound[1]}" if abs(bound[1]) < 1000 else f"{bound[1]:.1e}"
        print(f"  {name}: {value:.4f} (Bounds: [{lower_bound_formatted}, {upper_bound_formatted}])")
    print(f"\nOptimized Target (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):\n  Hydrogen Consumption: {hydrogen_mass_flow_g_s:.4f} g/s\n")
    print(f"Cell Voltage (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):\n  {cell_voltage:.4f} V\n")

    # Print the resultant power numbers
    label_width = 45
    value_width = 10
    print("Resultant Power Numbers:")
    print(f"  {'Stack (Gross) Power Estimate:':<{label_width}}  {stack_power_kW:>{value_width}.2f} kW")
    print(f"  {'Compressor Power Estimate (at FL ' + str(flight_level_100ft) + '):':<{label_width}} -{compressor_power_kW:>{value_width}.2f} kW")
    print(f"  {'Turbine Power Estimate (at FL ' + str(flight_level_100ft) + '):':<{label_width}} +{turbine_power_kW:>{value_width}.2f} kW")
    print(f"  {'Recirculation Pump Power Estimate:':<{label_width}} -{reci_pump_power_kW:>{value_width}.2f} kW")
    print(f"  {'Coolant Pump Power Estimate:':<{label_width}} -{coolant_pump_power_kW:>{value_width}.2f} kW")
    print("-" * (label_width + value_width + 7))
    print(f"  {'System (Net) Power (s.t. Optimization):':<{label_width}} ={system_power_kW:>{value_width}.2f} kW")
    
    # Save results to a .csv file 
    export_to_csv(gpr_model_cell_voltage.feature_names, optimal_input, _params_optimization.bounds, hydrogen_mass_flow_g_s, cell_voltage, 
                      system_power_kW, compressor_power_kW, turbine_power_kW, reci_pump_power_kW, coolant_pump_power_kW, stack_power_kW,
                      power_constraint_kW, specified_cell_count, flight_level_100ft, consider_turbine, end_of_life, converged, filename='optimized_input_data.csv')
    
# Entry point of the script
if __name__ == '__main__':
    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Optimize input variables using a trained Gaussian process regression model")
    parser.add_argument("-p", "--power", type=float, help="Power constraint for input variable optimization", default=150.0)
    parser.add_argument("-n", "--cellcount", type=int, help="Stack cell number for optimizing subject to power constraint", default=455)
    parser.add_argument("-f", "--flightlevel", type=int, help="Flight level in 100x feets", default=120)
    parser.add_argument("-t", "--turbine", type=str, choices=["True", "False"], default="True", help="Specifies whether recuperation shall be taken into account (default: True).")
    parser.add_argument("--eol", type=str, choices=["True", "False"], default="True", help="Specifies whether cell voltage is derated by a factor of 0.8 to account for end of life (default: False).")

    args = parser.parse_args()

    # Convert string inputs to booleans
    consider_turbine = args.turbine == "True"
    end_of_life = args.eol == "True"

    # Call the optimize_with_trained_model function
    optimize_input_variables(args.power, args.cellcount, args.flightlevel, consider_turbine=consider_turbine, end_of_life=end_of_life)