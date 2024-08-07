# Import libraries
import os
import numpy as np
import torch
import argparse
import random
import gpytorch
from pathlib import Path
import json
# Import custom classes and functions
import parameters
from file_handling import create_experiment_folder, load_gpr_model
from gpr_model import ExactGPModel
from data_processing import load_high_amp_doe_data, preprocess_data
from optimization_functions import optimize_inputs_evolutionary

from data_export_csv import export_to_csv

def load_config(filename):
    with open(filename, 'r') as file:
        return json.load(file)
    
def parse_range(input_str):
    """
    Parse the input string to return either a range or a list with the same value twice.
    """
    if ',' in input_str:
        return [float(x.strip()) for x in input_str.split(',')]
    single_value = float(input_str)
    return [single_value, single_value]
 
def optimize_input_variables(power_constraint_kW=75.0, specified_cell_count=275, flight_level_100ft=50, mode="auto", consider_turbine=True, end_of_life=False):
    # Load parameters
    #For now just overwrite the parameters originating from the parameters.py file with the user input: variables_user
    _params_optimization = parameters.Optimization_Parameters()
    config = load_config('config.json')
    
    variables_user = []
    for key in [
        "cathode_rh_in_perc",
        "stoich_cathode",
        "pressure_cathode_in_bara",
        "temp_coolant_inlet_degC",
        "temp_coolant_outlet_degC"]:
        
            if key in config:
                variables_user.append(parse_range(config[key]))
            
    # Update bounds, keeping the first value unchanged
    for i, val in enumerate(variables_user, start=1):
        _params_optimization.bounds[i] = (val[0], val[1])
    
    _params_pyhsics = parameters.Physical_Parameters()

    # Set the random seed for reproducibility
    if _params_optimization.seed is not None:
        random.seed(_params_optimization.seed)
        np.random.seed(_params_optimization.seed)
        torch.manual_seed(_params_optimization.seed)

    print(f"\nOptimization Stack Power Constraint: {power_constraint_kW:.0f} kW")
    print(f"Specified Flight Level: {flight_level_100ft} (100x ft)")
    print(f"Specified Cell Count: {specified_cell_count}")
    
    # Load the trained cell voltage model from the "trained_models" folder
    gpr_model_cell_voltage = load_gpr_model(os.path.join(os.getcwd(), "trained_models", "gpr_model_cell_voltage.pth"))

    # Load the trained cathode pressure drop model from the "trained_models" folder
    gpr_model_cathode_pressure_drop = load_gpr_model(os.path.join(os.getcwd(), "trained_models", "gpr_model_cathode_pressure_drop.pth"))

    # Create a folder to store the training results
    create_experiment_folder(_params_optimization=_params_optimization, type='optimization')
    
    # Optimize the input variables
    optimal_input, cell_voltage, hydrogen_mass_flow_g_s, stack_power_kW, compressor_power_kW, turbine_power_kW = optimize_inputs_evolutionary(gpr_model_cell_voltage, gpr_model_cathode_pressure_drop,
                                                                                                                                              flight_level_100ft, cellcount=specified_cell_count,
                                                                                                                                              bounds=_params_optimization.bounds, power_constraint_kW=power_constraint_kW,
                                                                                                                                              penalty_weight=1e-7, params_physics=_params_pyhsics,
                                                                                                                                              consider_turbine=consider_turbine, end_of_life=end_of_life)
    
    system_power_kW = stack_power_kW - compressor_power_kW + turbine_power_kW

    # Print the optimal input, target variables, and bounds including feature names and target variable
    print("\nOptimized Input Variables:")
    for name, value, bound in zip(gpr_model_cell_voltage.feature_names, optimal_input, _params_optimization.bounds):
        print(f"  {name}: {value:.4f} (Bounds: [{bound[0]}, {bound[1]}])")
    print(f"\nOptimized Target (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):\n  Hydrogen Consumption: {hydrogen_mass_flow_g_s:.4f} g/s\n")
    print(f"Cell Voltage (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):\n  {cell_voltage:.4f} V\n")

    print("Resultant Power Numbers:")
    print(f"  System (Net) Power (s.t. Optimization): {system_power_kW:.2f} kW")
    print(f"  Compressor Power Estimate at Fligh-Level {flight_level_100ft}: {compressor_power_kW:.2f} kW")
    print(f"  Turbine Power Estimate at Fligh-Level {flight_level_100ft}: {turbine_power_kW:.2f} kW")
    print(f"  Stack (Gross) Power: {stack_power_kW:.2f} kW")

    # Save the optimal input, target variables, and bounds to a file
    with open(f'optimized_input_for_{int(power_constraint_kW)}kW_with_{int(specified_cell_count)}_cells.txt', 'w') as file:
        file.write(f"Stack Power Constraint: {power_constraint_kW:.0f} kW\n")
        file.write(f"Specified Flight Level: {flight_level_100ft} (100x ft)")
        file.write(f"Specified Cell Count: {specified_cell_count}\n")

        file.write("\nOptimized Variables:\n")
        for name, value, bound in zip(gpr_model_cell_voltage.feature_names, optimal_input, _params_optimization.bounds):
            file.write(f"  {name}: {value:.4f} (Bounds: [{bound[0]}, {bound[1]}])\n")
            file.write(f"\nOptimized Target (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):\n  Hydrogen Consumption: {hydrogen_mass_flow_g_s:.4f} g/s\n")

        file.write("Resultant Power Numbers:")
        file.write(f"  System (Net) Power (s.t. Optimization): {system_power_kW:.2f} kW")
        file.write(f"  Compressor Power required at Fligh-Level {flight_level_100ft}: {compressor_power_kW:.2f} kW")
        file.write(f"  Turbine Power required at Fligh-Level {flight_level_100ft}: {turbine_power_kW:.2f} kW")
        file.write(f"  Stack (Gross) Power: {stack_power_kW:.2f} kW")
    
    #_file_path = os.path.join(os.getcwd(), "resulting_data")
    #save_results_to_excel(_file_path, feature_names, optimal_input, bounds, hydrogen_mass_flow_g_s, cell_voltage, system_power_kW, compressor_power_kW, stack_power_kW, power_constraint_kW, specified_cell_count, flight_level_100ft)
    export_to_csv(gpr_model_cell_voltage.feature_names, optimal_input, _params_optimization.bounds, hydrogen_mass_flow_g_s, cell_voltage, 
                      system_power_kW, compressor_power_kW, turbine_power_kW, stack_power_kW, power_constraint_kW, 
                      specified_cell_count, flight_level_100ft, filename='optimized_input_data.csv')
    
# Entry point of the script
if __name__ == '__main__':
    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Optimize input variables using a trained Gaussian process regression model")
    parser.add_argument("-p", "--power", type=float, help="Power constraint for input variable optimization", default=75.0)
    parser.add_argument("-n", "--cellcount", type=int, help="Stack cell number for optimizing subject to power constraint", default=275)
    parser.add_argument("-f", "--flightlevel", type=int, help="Flight level in 100x feets", default=120)
    parser.add_argument("--mode", type=str, choices=["auto", "manual"], default="auto", help="Mode of operation: 'auto' or 'manual'")
    parser.add_argument("-t", "--turbine", type=str, choices=["true", "false"], default="true", help="Specifies whether recuperation shall be taken into account (default: True).")
    parser.add_argument("--eol", type=str, choices=["true", "false"], default="false", help="Specifies whether cell voltage is derated by a factor of 0.8 to account for end of life (default: False).")

    args = parser.parse_args()

    # Convert string inputs to booleans
    consider_turbine = args.turbine == "true"
    end_of_life = args.eol == "true"
    
    if args.mode == "manual":
        # Prompt the user for input variables
        cathode_rh_in_perc = input("Enter cathode relative humidity in percentage (single value or range like 100,110) [default: 100,110]: ") or "100,110"
        stoich_cathode = input("Enter stoichiometry of the cathode (single value or range like 1.4) [default: 1.4]: ") or "1.4"
        pressure_cathode_in_bara = input("Enter pressure at the cathode inlet in bara (single value or range like 1.5,2.0) [default: 1.5,2.0]: ") or "1.5,2.0"
        temp_coolant_inlet_degC = input("Enter temperature of the coolant inlet in degrees Celsius (single value or range like 60) [default: 60]: ") or "60"
        temp_coolant_outlet_degC = input("Enter temperature of the coolant outlet in degrees Celsius (single value or range like 75,80) [default: 75,80]: ") or "75,80"

        # Parse the input arguments to handle single values and ranges
        variables_user = [
            parse_range(cathode_rh_in_perc),
            parse_range(stoich_cathode),
            parse_range(pressure_cathode_in_bara),
            parse_range(temp_coolant_inlet_degC),
            parse_range(temp_coolant_outlet_degC)
        ]

    # Call the optimize_with_trained_model function
    optimize_input_variables(args.power, args.cellcount, args.flightlevel, args.mode, consider_turbine=consider_turbine, end_of_life=end_of_life)