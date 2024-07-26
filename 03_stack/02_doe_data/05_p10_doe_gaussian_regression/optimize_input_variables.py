# Import libraries
import os
import numpy as np
import torch
import argparse
import random
import gpytorch
from pathlib import Path

# Import custom classes and functions
import parameters
from file_handling import create_experiment_folder
from gpr_model import ExactGPModel
from data_processing import load_high_amp_doe_data, preprocess_data
from optimization_functions import optimize_inputs_evolutionary

def optimize_input_variables(model_path, power_constraint_kW=75.0, specified_cell_count=275, flight_level_100ft=50,variables_user=[100,5,3,60,75]):
    # Load parameters
    #For now just overwrite the parameters originating from the parameters.py file with the user input: variables_user
    _params_optimization = parameters.Optimization_Parameters()
    # Update bounds, keeping the first value unchanged
    for i, val in enumerate(variables_user, start=1):
        _params_optimization.bounds[i] = (val, val)
    
    
    _params_pyhsics = parameters.Physical_Parameters()

    # Set the random seed for reproducibility
    if _params_optimization.seed is not None:
        random.seed(_params_optimization.seed)
        np.random.seed(_params_optimization.seed)
        torch.manual_seed(_params_optimization.seed)

    print(f"\nOptimization Stack Power Constraint: {power_constraint_kW:.0f} kW")
    print(f"Specified Flight Level: {flight_level_100ft} (100x ft)")
    print(f"Specified Cell Count: {specified_cell_count}")

    # Create a folder to store the training results
    create_experiment_folder(_params_optimization=_params_optimization, type='optimization')

    # Load and assign the data TODO Extract all necessary information from the stored model
    pd_dataframe, _ = load_high_amp_doe_data()
    train_input_tensor, train_target_tensor, _, _, (input_data_mean, input_data_std), (target_data_mean, target_data_std), feature_names = \
        preprocess_data(pd_dataframe, 'cell_voltage', 50, params_pyhsics=_params_pyhsics)
    
    # Load the trained model
    likelihood = gpytorch.likelihoods.GaussianLikelihood()
    model = ExactGPModel(train_input_tensor, train_target_tensor, likelihood)
    model_path = os.path.join(Path(os.getcwd()).parents[0], model_path)
    model.load_state_dict(torch.load(model_path))

    # Normalize the bounds TODO: Move to optimization function
    bounds = _params_optimization.bounds
    normalized_bounds = [((min_val - mean) / std, (max_val - mean) / std ) for (min_val, max_val), mean, std in zip(bounds, input_data_mean.numpy(), input_data_std.numpy())]

    # Optimize the input variables
    optimal_input, cell_voltage, hydrogen_mass_flow_g_s, stack_power_kW, compressor_power_kW = optimize_inputs_evolutionary(model, input_data_mean,
                                                                                                                            input_data_std, target_data_mean, target_data_std,
                                                                                                                            flight_level_100ft, cellcount=specified_cell_count, bounds=normalized_bounds,
                                                                                                                            power_constraint_kW=power_constraint_kW, penalty_weight=1e-6,
                                                                                                                            params_physics=_params_pyhsics)
    
    system_power_kW = stack_power_kW - compressor_power_kW

    # Print the optimal input, target variables, and bounds including feature names and target variable
    print("\nOptimized Input Variables:")
    for name, value, bound in zip(feature_names, optimal_input, bounds):
        print(f"  {name}: {value:.4f} (Bounds: [{bound[0]}, {bound[1]}])")
    print(f"\nOptimized Target (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):\n  Hydrogen Consumption: {hydrogen_mass_flow_g_s:.4f} g/s\n")
    print(f"Cell Voltage (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):\n  {cell_voltage:.4f} V\n")

    print("Resultant Power Numbers:")
    print(f"  System (Net) Power (s.t. Optimization): {system_power_kW:.2f} kW")
    print(f"  Compressor Power Estimate at Fligh-Level {flight_level_100ft}: {compressor_power_kW:.2f} kW")
    print(f"  Stack (Gross) Power: {stack_power_kW:.2f} kW")

    # Save the optimal input, target variables, and bounds to a file
    with open(f'optimized_input_for_{int(power_constraint_kW)}kW_with_{int(specified_cell_count)}_cells.txt', 'w') as file:
        file.write(f"Stack Power Constraint: {power_constraint_kW:.0f} kW\n")
        file.write(f"Specified Flight Level: {flight_level_100ft} (100x ft)")
        file.write(f"Specified Cell Count: {specified_cell_count}\n")

        file.write("\nOptimized Variables:\n")
        for name, value, bound in zip(feature_names, optimal_input, bounds):
            file.write(f"  {name}: {value:.4f} (Bounds: [{bound[0]}, {bound[1]}])\n")
            file.write(f"\nOptimized Target (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):\n  Hydrogen Consumption: {hydrogen_mass_flow_g_s:.4f} g/s\n")

        file.write("Resultant Power Numbers:")
        file.write(f"  System (Net) Power (s.t. Optimization): {system_power_kW:.2f} kW")
        file.write(f"  Compressor Power required at Fligh-Level {flight_level_100ft}: {compressor_power_kW:.2f} kW")
        file.write(f"  Stack (Gross) Power: {stack_power_kW:.2f} kW")

# Entry point of the script
if __name__ == '__main__':
    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Optimize input variables using a trained Gaussian process regression model")
    parser.add_argument("-m", "--model", type=str, help="Path to the trained GPR model", required=True)
    parser.add_argument("-p", "--power", type=float, help="Power constraint for input variable optimization", default=75.0)
    parser.add_argument("-n", "--cellcount", type=int, help="Stack cell number for optimizing subject to power constraint", default=275)
    parser.add_argument("-f", "--flightlevel", type=int, help="Flight level in 100x feets", default=50)
    parser.add_argument("-v", "--variables_user", type=list, help="Enter input variables for model evaluation: [cathode_rh_in_perc,stoich_cathode,pressure_cathode_in_bara,temp_coolant_inlet_degC,temp_coolant_outlet_degC]", default=[100,5,3,60,75]) #TODO: Change defaults and varnames

    args = parser.parse_args()

    # Call the optimize_with_trained_model function                        
    optimize_input_variables(args.model, args.power, args.cellcount, args.flightlevel, args.variables_user)
