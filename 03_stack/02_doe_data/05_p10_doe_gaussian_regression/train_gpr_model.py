

"""The objective of this project is to train a Gaussian process regression model on Powercell DoE data.

Author: Stefan Notter
Date: June 2024
"""

# Import libraries
import os
import csv
import numpy as np
import torch
import gpytorch
import matplotlib.pyplot as plt
import random
from pathlib import Path
import argparse

# Import custom classes and functions
import parameters
from file_handling import create_experiment_folder
from gpr_model import ExactGPModel
from data_processing import load_high_amp_doe_data, load_high_temp_doe_data, preprocess_data
from prediction_performance_evaluation import eval_prediction_performance, plot_prediction_performance, create_prediction_performance_video
from partial_dependence_analysis import plot_partial_dependence

def train_gpr_model(target='voltage', cutoff_current=0, pretrained_model=None, data='high_amp'):
    # Load parameters
    _params_training = parameters.Training_Parameters()
    _params_logging = parameters.Logging_Parameters()
    _params_pyhsics = parameters.Physical_Parameters()

    # Set the random seed for reproducibility
    if _params_training.seed is not None:
        random.seed(_params_training.seed)
        np.random.seed(_params_training.seed)
        torch.manual_seed(_params_training.seed)

    # Create a folder to store the training results
    create_experiment_folder(_params_training=_params_training, _params_logging=_params_logging, data=data)

    # Load and assign the data
    if data == 'high_amp':
        pd_dataframe, _ = load_high_amp_doe_data()
    elif data == 'high_temp':
        pd_dataframe, _ = load_high_temp_doe_data()
    else:
        raise ValueError('Invalid data selection!')
            
    train_input_tensor, train_target_tensor, test_input_tensor, test_target_tensor, (input_data_mean, input_data_std), (target_data_mean, target_data_std), feature_names = \
        preprocess_data(pd_dataframe, target, cutoff_current, params_pyhsics=_params_pyhsics, data=data)

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
            plot_prediction_performance(model, likelihood, test_input_tensor, test_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=True)
            plot_prediction_performance(model, likelihood, train_input_tensor, train_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=False)

            # Compute the test loss
            test_loss = eval_prediction_performance(model, likelihood, mll, test_input_tensor, test_target_tensor)
            print(f'Iteration {i:04d}/{training_iterations} - Training Loss: {loss.item():02.4f} - Test Loss: {test_loss.item():02.4f}')
            loss_list.append(loss.item())
            test_loss_list.append(test_loss.item())
            iterations.append(i)

        loss.backward()
        optimizer.step() # the actual update step!

    # Print and save the final loss values
    i = i + 1
    if i % _params_logging.log_interval == 0:

        plot_prediction_performance(model, likelihood, test_input_tensor, test_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=True)
        plot_prediction_performance(model, likelihood, train_input_tensor, train_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=False)

        test_loss = eval_prediction_performance(model, likelihood, mll, test_input_tensor, test_target_tensor)
        print(f'Iteration {i:04d}/{training_iterations} - Training Loss: {loss.item():02.4f} - Test Loss: {test_loss.item():02.4f}\n')
        loss_list.append(loss.item())
        test_loss_list.append(test_loss.item())
        iterations.append(i)

    # Save all the necessary information to a "model" subfolder for restoring the trained model (refering to the target variable)
    model_dict = {
        'model_state_dict': model.state_dict(),
        'likelihood_state_dict': likelihood.state_dict(),
        'input_data_mean': input_data_mean,
        'input_data_std': input_data_std,
        'target_data_mean': target_data_mean,
        'target_data_std': target_data_std,
        'feature_names': feature_names,
        'train_input_tensor': train_input_tensor,
        'train_target_tensor': train_target_tensor
    }

    torch.save(model_dict, f'gpr_model_{target}.pth')   

    # Save the loss values and the corresponding iteration values to a dat file
    with open('loss_values.dat', 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(zip(iterations, loss_list, test_loss_list))

    # Plot the partial dependence plots
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
    plt.yscale('log')
    plt.legend()
    plt.grid(True, zorder=1)
    plt.title('Loss During Training')
    plt.savefig('loss_evolution.png', dpi=300, bbox_inches='tight')
    plt.close()

    # Create a video from the model performance snapshots
    create_prediction_performance_video(test=True)
    create_prediction_performance_video(test=False)

    print(f'\nTraining of the Gaussian process regression model for target variable {target} is completed!')
    print('___________________________________________________________________________________________\n')

    return model, input_data_mean, input_data_std, target_data_mean, target_data_std, feature_names

# Entry point of the script
if __name__ == '__main__':
    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Train a Gaussian process regression model on Powercell DoE data")
    parser.add_argument("-t", "--target", type=str, help="Target variable for Gaussian process regression", default="cell_voltage")
    parser.add_argument("-c", "--cutoff", type=float, help="Datapoints below cutoff current are removed from training data", default=0.0)
    parser.add_argument("-m", "--model", type=str, help="Load a pretrained GPR model", default=None)
    parser.add_argument("--data", type=str, choices=["high_amp","high_temp"], help="Select the DoE dataset", default="high_temp")

    args = parser.parse_args()

    # Call the train_gpr_model function                        
    train_gpr_model(args.target, args.cutoff, args.model, args.data)
