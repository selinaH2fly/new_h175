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

def icao_atmosphere(flight_level_100ft, params_physics):
    """
    Calculate the temperature and pressure at a given altitude using the ICAO atmosphere model.
    """
    # Calculate the altitude in meters
    altitude_m = flight_level_100ft * 100 * 0.3048

    # Calculate the temperature and pressure at the given altitude
    temperature_K = params_physics.sea_level_ambient_temperature_K - params_physics.temperature_lapse_rate * altitude_m
    pressure_Pa = params_physics.sea_level_ambient_pressure_bar*1e5 * \
        (1 - params_physics.temperature_lapse_rate * altitude_m / params_physics.sea_level_ambient_temperature_K) ** \
            (params_physics.gravity / (params_physics.specific_gas_constant * params_physics.temperature_lapse_rate))

    return temperature_K, pressure_Pa

def optimize_input_variables(model_path, power_constraint_kW=75.0, specified_cell_count=275, flight_level_100ft=50):
    # Load parameters
    _params_optimization = parameters.Optimization_Parameters()
    _params_pyhsics = parameters.Physical_Parameters()

    # Set the random seed for reproducibility
    if _params_optimization.seed is not None:
        random.seed(_params_optimization.seed)
        np.random.seed(_params_optimization.seed)
        torch.manual_seed(_params_optimization.seed)

    # Create a folder to store the training results
    create_experiment_folder(_params_optimization=_params_optimization, type='optimization')

    # Load and assign the data TODO Extract all necessary information from the stored model
    pd_dataframe, _ = load_high_amp_doe_data()
    train_input_tensor, train_target_tensor, _, _, (input_data_mean, input_data_std), (target_data_mean, target_data_std), feature_names = \
        preprocess_data(pd_dataframe, 'eta_lhv', 50, params_pyhsics=_params_pyhsics)
    
    # Load the trained model
    likelihood = gpytorch.likelihoods.GaussianLikelihood()
    model = ExactGPModel(train_input_tensor, train_target_tensor, likelihood)
    model_path = os.path.join(Path(os.getcwd()).parents[0], model_path)
    model.load_state_dict(torch.load(model_path))

    # Calculate the temperature and pressure at the given flight level
    temperature_K, pressure_Pa = icao_atmosphere(flight_level_100ft, _params_pyhsics)

    # Normalize the bounds
    bounds = _params_optimization.bounds
    normalized_bounds = [((min_val - mean) / std, (max_val - mean) / std ) for (min_val, max_val), mean, std in zip(bounds, input_data_mean.numpy(), input_data_std.numpy())]
        
    # Specify and normalize the power constraint
    power_constraint_cell_W = power_constraint_kW * 1000 / specified_cell_count

    # Optimize the input variables
    optimal_input_norm, optimal_target_norm = optimize_inputs_evolutionary(model, input_data_mean, input_data_std, target_data_mean, target_data_std,
                                                                           bounds=normalized_bounds, power_constraint_value=power_constraint_cell_W, penalty_weight=0.01, params_physics=_params_pyhsics)

    # Denormalize the optimal input and target variables	
    optimal_input = optimal_input_norm * np.array(input_data_std) + np.array(input_data_mean)
    optimal_target = optimal_target_norm * target_data_std + target_data_mean

    # Print the optimal input, target variables, and bounds including feature names and target variable
    print(f"\nOptimization Power Constraint: {power_constraint_kW:.0f} kW")
    print(f"Specified Cell Count: {specified_cell_count}\n")

    print("Optimal Input Variables:")
    for name, value, bound in zip(feature_names, optimal_input, bounds):
        print(f"  {name}: {value:.4f} (Bounds: [{bound[0]}, {bound[1]}])")
    print(f"\nMaximized Target (s.t. Optimal Input Variables, Power Constraint, and Cell Count):\n  eta_lhv: {optimal_target:.4f}\n")

    print(f"(Validation: Power s.t. Optimal Input: {optimal_input[0] * optimal_target * specified_cell_count * _params_pyhsics.hydrogen_lhv_voltage_equivalent / 1000:.4f} kW)")

    # Save the optimal input, target variables, and bounds to a file
    with open(f'optimized_input_for_{int(power_constraint_kW)}kW_with_{int(specified_cell_count)}_cells.txt', 'w') as file:
        file.write(f"Power Constraint: {power_constraint_kW:.0f} kW\n")
        file.write(f"Specified Cell Count: {specified_cell_count}\n")

        file.write("\nOptimal Input Variables:\n")
        for name, value, bound in zip(feature_names, optimal_input, bounds):
            file.write(f"  {name}: {value:.4f} (Bounds: [{bound[0]}, {bound[1]}])\n")
        file.write(f"\nMaximized Target (s.t. Optimal Input Variables, Power Constraint, and Cell Count):\n  voltage: {optimal_target:.4f}\n")

        file.write(f"\n(Validation: Power s.t. Optimal Input: {optimal_input[0] * optimal_target * specified_cell_count * _params_pyhsics.hydrogen_lhv_voltage_equivalent / 1000:.4f} kW)")

# Entry point of the script
if __name__ == '__main__':
    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Optimize input variables using a trained Gaussian process regression model")
    parser.add_argument("-m", "--model", type=str, help="Path to the trained GPR model", required=True)
    parser.add_argument("-p", "--power", type=float, help="Power constraint for input variable optimization", default=75.0)
    parser.add_argument("-n", "--cellcount", type=int, help="Stack cell number for optimizing subject to power constraint", default=275)
    parser.add_argument("-f", "--flightlevel", type=float, help="Flight level in 100x feets", default=50)

    args = parser.parse_args()

    # Call the optimize_with_trained_model function                        
    optimize_input_variables(args.model, args.power, args.cellcount, args.flightlevel)
