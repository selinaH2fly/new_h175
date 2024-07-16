"""The objective of this project is to train a Gaussian process regression model on Powercell DoE data.

Author: Stefan Notter
Date: June 2024
"""

# Import libraries
import os
from pathlib import Path
import sys
import shutil
import argparse
import csv
import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import gpytorch
import matplotlib.pyplot as plt
import pandas as pd
import random
import cv2
import warnings
from gpytorch.utils.warnings import GPInputWarning

# Import the function to create the experiment folder
from file_handling import create_experiment_folder

# Import the Gaussian process regression model
from gpr_model import ExactGPModel

# Import parameters
import parameters

# Import data processing functions
from data_processing import load_high_amp_doe_data, preprocess_data

# Import prediction performance evaluation functions
from prediction_performance_evaluation import eval_prediction_performance, plot_prediction_performance, create_prediction_performance_video

# Import partial dependence analysis functions
from partial_dependence_analysis import plot_partial_dependence

# Import input optimization function from input_optimization.py
from input_optimization import optimize_inputs_evolutionary




# Main function
def train_gpr_model_on_doe_data(target='voltage', cutoff_current=0, plot=True, optimize=True, pretrained_model=None, power_constraint_kW=75.0, specified_cell_count=275):

    # Load parameters
    _params_training = parameters.Training_Parameters()
    # _params_model = parameters.Model_Parameters()
    _params_logging = parameters.Logging_Parameters()
    _params_optimization = parameters.Optimization_Parameters()
    _params_pyhsics = parameters.Physical_Parameters()

    # Set the random seed for reproducibility
    if _params_training.seed is not None:
        random.seed(_params_training.seed)
        np.random.seed(_params_training.seed)
        torch.manual_seed(_params_training.seed)

    # Create a folder to store the training results
    create_experiment_folder(_params_training=_params_training, _params_logging=_params_logging)

    # Load and assign the data
    pd_dataframe, _ = load_high_amp_doe_data()
    train_input_tensor, train_target_tensor, test_input_tensor, test_target_tensor, (input_data_mean, input_data_std), (target_data_mean, target_data_std), feature_names = \
        preprocess_data(pd_dataframe, target, cutoff_current, params_pyhsics=_params_pyhsics)

    # Likelihood and model
    likelihood = gpytorch.likelihoods.GaussianLikelihood()
    model = ExactGPModel(train_input_tensor, train_target_tensor, likelihood)

    # Load the pretrained model if provided
    if pretrained_model is not None:
        my_dir = os.getcwd()
        pretrained_model_path = os.path.join(Path(my_dir).parents[0], pretrained_model)
        model.load_state_dict(torch.load(pretrained_model_path))

    optimizer = torch.optim.Adam(model.parameters(), lr=_params_training.learning_rate)
    mll = gpytorch.mlls.ExactMarginalLogLikelihood(likelihood, model)

    # List to store the loss values and iterations
    loss_list = []
    test_loss_list = []
    iterations = []

    # Training loop
    training_iterations = int(_params_training.iterations)
    for i in range(training_iterations):

        model.train()
        likelihood.train()

        optimizer.zero_grad()
        output = model(train_input_tensor)
        loss = -mll(output, train_target_tensor)

        if i % _params_logging.log_interval == 0:

            # Plot the model performance
            plot_prediction_performance(model, likelihood, test_input_tensor, test_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=True) if plot else None
            plot_prediction_performance(model, likelihood, train_input_tensor, train_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=False) if plot else None

            # Compute the test loss
            test_loss = eval_prediction_performance(model, likelihood, mll, test_input_tensor, test_target_tensor)
            print(f'Iteration {i}/{training_iterations} - Training Loss: {loss.item()} - Test Loss: {test_loss.item()}')
            loss_list.append(loss.item())
            test_loss_list.append(test_loss.item())
            iterations.append(i)

        loss.backward()
        optimizer.step() # the actual update step!

    # Print and save the final loss values
    i = i + 1
    if i % _params_logging.log_interval == 0:

        plot_prediction_performance(model, likelihood, test_input_tensor, test_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=True) if plot else None
        plot_prediction_performance(model, likelihood, train_input_tensor, train_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=False) if plot else None

        test_loss = eval_prediction_performance(model, likelihood, mll, test_input_tensor, test_target_tensor)
        print(f'Iteration {i}/{training_iterations} - Training Loss: {loss.item()} - Test Loss: {test_loss.item()}\n')
        loss_list.append(loss.item())
        test_loss_list.append(test_loss.item())
        iterations.append(i)

    # Save the model refering to the target variable
    torch.save(model.state_dict(), f'gpr_model_{target}.pth')

    # Save the loss values and the corresponding iteration values to a dat file
    with open('loss_values.dat', 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(zip(iterations, loss_list, test_loss_list))

    # Plot the partial dependence plots
    if plot:
        # Create a folder to store the partial dependence plots
        os.mkdir('partial_dependence_plots')

        # Plot the partial dependence plots
        for current_value in [200, 300, 400, 500, 600, 700]:
            plot_partial_dependence(model, train_input_tensor, feature_names=feature_names, target=target, input_normalization=(input_data_mean, input_data_std), target_normalization=(target_data_mean, target_data_std), fixed_feature='current_A', fixed_value=current_value)
                
        # Plot the loss to a new figure
        fig = plt.figure(figsize=(8, 6))
        plt.plot(iterations, loss_list, label='Training Loss')
        plt.plot(iterations, test_loss_list, label='Validation Loss')    
        plt.xlabel('Iterations')
        plt.ylabel('MLL Loss')
        # plt.yscale('log')
        plt.legend()
        plt.grid(True, zorder=1)
        plt.title('Loss During Training')
        plt.savefig('loss_evolution.png', dpi=300, bbox_inches='tight')
        plt.close()

        # Create a video from the model performance snapshots
        create_prediction_performance_video(test=True)
        create_prediction_performance_video(test=False)

    if optimize:

        # Create a folder to store the optimization results
        os.mkdir('optimization')

        # Load the input bounds 
        bounds = _params_optimization.bounds

        # # Loop over different current constrainsts
        # for current_value in [200, 300, 400, 500, 600, 700]:

        #     # Overwrite the current value in the bounds
        #     bounds[0] = (current_value-1, current_value+1)

        # Specify and normalize the power constraint
        power_constraint_cell_W = power_constraint_kW * 1000 / specified_cell_count

        # Normalize the bounds
        normalized_bounds = [((min_val - mean) / std, (max_val - mean) / std ) for (min_val, max_val), mean, std in zip(bounds, input_data_mean.numpy(), input_data_std.numpy())]
        
        # Optimize the input variables
        # optimal_input_norm, optimal_target_norm = optimize_inputs_gradient_based(model, bounds=normalized_bounds, power_constraint_value=power_constraint, initial_guess=None)
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
        print(f"\nMaximized Target (s.t. Optimal Input Variables, Power Constraint, and Cell Count):\n  {target}: {optimal_target:.4f}\n")

        print(f"(Validation: Power s.t. Optimal Input: {optimal_input[0] * optimal_target * specified_cell_count * _params_pyhsics.hydrogen_lhv_voltage_equivalent / 1000:.4f} kW)")

        # Save the optimal input, target variables, and bounds to a file
        with open(f'optimization/optimized_input_for_{int(power_constraint_kW)}kW_with_{int(specified_cell_count)}_cells.txt', 'w') as file:
            file.write(f"Power Constraint: {power_constraint_kW:.0f} kW\n")
            file.write(f"Specified Cell Count: {specified_cell_count}\n")

            file.write("\nOptimal Input Variables:\n")
            for name, value, bound in zip(feature_names, optimal_input, bounds):
                file.write(f"  {name}: {value:.4f} (Bounds: [{bound[0]}, {bound[1]}])\n")
            file.write(f"\nMaximized Target (s.t. Optimal Input Variables, Power Constraint, and Cell Count):\n  {target}: {optimal_target:.4f}\n")

            file.write(f"\n(Validation: Power s.t. Optimal Input: {optimal_input[0] * optimal_target * specified_cell_count * _params_pyhsics.hydrogen_lhv_voltage_equivalent / 1000:.4f} kW)")

    return None


# Entry point of the script
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Train a Gaussian process regression model on Powercell DoE data")
    parser.add_argument("-t", "--target", type=str, help="Target variable for Gaussia process regression", default="voltage")
    parser.add_argument("-c", "--cutoff", type=float, help="Datapoints below cutoff current are removed from training data", default=0.0)
    parser.add_argument("-p", "--plot", type=bool, help="Plot the input/output data", default=True)
    parser.add_argument("-o", "--optimize", type=bool, help="Optimize the input variables", default=True)
    parser.add_argument("-m", "--model", type=str, help="Load a pretrained GPR model", default=None)
    parser.add_argument("-w", "--power", type=float, help="Power constraint for input variable optimization", default=75.0)
    parser.add_argument("-n", "--cellcount", type=int, help="Stack cell number for optimizing subject to power constraint", default=275)

    args = parser.parse_args()

    # Call the main function                        
    train_gpr_model_on_doe_data(args.target, args.cutoff, args.plot, args.optimize, args.model, args.power, args.cellcount)
