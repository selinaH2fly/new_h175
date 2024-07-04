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

# Import parameters
import parameters

# Define a GP model
class ExactGPModel(gpytorch.models.ExactGP):
    def __init__(self, train_x, train_y, likelihood):
        super(ExactGPModel, self).__init__(train_x, train_y, likelihood)
        self.mean_module = gpytorch.means.ConstantMean()
        self.covar_module = gpytorch.kernels.ScaleKernel(gpytorch.kernels.RBFKernel())

    def forward(self, x):
        mean_x = self.mean_module(x)
        covar_x = self.covar_module(x)
        return gpytorch.distributions.MultivariateNormal(mean_x, covar_x)

# Create and browse to folder for storing experiment results
def create_experiment_folder(_params_model=None, _params_training=None, _params_logging=None):
    """ Creates new folder to store training results

    Parameters
    ----------
    _params_training : LearningParameters
        Hyperparameters for training the model

    _params_logging : LoggingParameters
        Intervals for saving and logging

    Returns
    -------
    parameterFile : io.TextIOWrapper
        File descriptor to parameter file

    lossFile : io.TextIOWrapper
        File descriptor to loss file
    """

    # create folder to store data for the experiment running
    experimentID = 1
    dirName = "{}_gpr_doe_model_experiment".format(experimentID)
    while os.path.exists(dirName):
        experimentID += 1
        dirName = "{}_".format(experimentID) + dirName.split('_', 1)[1]
    os.mkdir(dirName)
    shutil.copytree(os.getcwd(), os.path.join(dirName, "Sources_unzipped"),
                    ignore=shutil.ignore_patterns('*experiment*', 'archive', '.git*', 
                                                  '../.idea', '__pycache__', 'README*'))

    os.chdir(dirName)
    shutil.make_archive("Sources", 'zip', "Sources_unzipped")
    shutil.rmtree("Sources_unzipped")
    print("Directory for running experiment no. {} created".format(experimentID))

    # save parameters to file
    parameterFile = open("parameterFile.txt", "w")
    # write paramters to file if they are not None
    if _params_model is not None:
        parameterFile.write(format(vars(_params_model)) + "\n")
    if _params_training is not None:
        parameterFile.write(format(vars(_params_training)) + "\n")
    if _params_logging is not None:
        parameterFile.write(format(vars(_params_logging)))
    parameterFile.close()

    return None

# Load the high amp DoE data
def load_high_amp_doe_data():
    # Get path to data file
    my_dir = os.getcwd()
    filename = "FC-P10-275C-H0C-SN0014 - H2Fly DOE averaged.xlsx"
    path = os.path.join(Path(my_dir).parents[1], '01_p10_doe_basic_files', '02_TV500106_750A', filename)

    # Load data file
    xls = pd.ExcelFile(path)

    # Get the name of the second sheet
    second_sheet_name = xls.sheet_names[1]

    # Load the second sheet into a DataFrame, skipping the first row
    df = pd.read_excel(path, sheet_name=second_sheet_name)

    # Extract the units row and set it as the DataFrame column names
    units = df.iloc[0]
    df.columns = df.iloc[1]
    df = df.drop([0, 1]).reset_index(drop=True)
    df = df.drop(0)
    df = df[df['Point successfully run'] == 1]
    df = df.loc[:, ~df.columns.duplicated()]

    return df, units

# Preprocess the data
def preprocess_data(df, target='voltage', cutoff_current=0):

    # Drop data points from the dataframe with current values below the cutoff value
    df = df[df['current'] > cutoff_current]

    # Convert the dataframes to dictionaries
    df_dict = df.to_dict('list')

    # Create a dictionary for processed training input data
    input_data_tensor = {}
    input_data_tensor['cell_power_W'] = [power / 275 * 1000 for power in df_dict['power']]
    input_data_tensor['anode_rh_in_perc'] = [calculate_relative_humidity(dewpoint, temp) for dewpoint, temp in zip(df_dict['temp_anode_dewpoint_gas'], df_dict['temp_anode_inlet'])]
    input_data_tensor['cathode_rh_in_perc'] = [calculate_relative_humidity(dewpoint, temp) for dewpoint, temp in zip(df_dict['temp_cathode_dewpoint_gas'], df_dict['temp_cathode_inlet'])]
    input_data_tensor['cathode_stoich_'] = df_dict['cathode_stoich']
    input_data_tensor['cathode_pressure_in_barg'] = df_dict['pressure_cathode_inlet']
    input_data_tensor['coolant_temp_in_degC'] = df_dict['temp_coolant_inlet']
    input_data_tensor['coolant_flow_in_lpm'] = df_dict['flow_coolant']

    # Try to find the target variable in the df_dict
    if target in df_dict:
        target_data = df_dict[target]
    else:
        # Check for custom targets
        if target == 'eta_lhv':
            target_data = [voltage / 275 / 1.253 for voltage in df_dict['voltage']]
        elif target == 'eta_hhv':
            target_data = [voltage / 275 / 1.481 for voltage in df_dict['voltage']]
        else:
            raise ValueError(f'Target variable {target} not found in the dataframe!')

    # Convert to pytorch tensors
    input_data_tensor = torch.tensor(list(input_data_tensor.values()), dtype=torch.float32).T
    target_data_tensor = torch.tensor(target_data, dtype=torch.float32)

    # Randomly split the data into training and testing sets
    train_size = int(0.8 * len(input_data_tensor))
    indices = torch.randperm(len(input_data_tensor))
    train_indices = indices[:train_size]
    test_indices = indices[train_size:]

    train_input_tensor = input_data_tensor[train_indices]
    train_target_tensor = target_data_tensor[train_indices]

    test_input_tensor = input_data_tensor[test_indices]
    test_target_tensor = target_data_tensor[test_indices]

    # Normalize the training data
    train_input_mean = train_input_tensor.mean(dim=0)
    train_input_std = train_input_tensor.std(dim=0)
    train_input_tensor = (train_input_tensor - train_input_mean) / train_input_std

    train_target_mean = train_target_tensor.mean()
    train_target_std = train_target_tensor.std()
    train_target_tensor = (train_target_tensor - train_target_mean) / train_target_std

    # Normalize the test data using the training data statistics
    test_input_tensor = (test_input_tensor - train_input_mean) / train_input_std
    test_target_tensor = (test_target_tensor - train_target_mean) / train_target_std

    return train_input_tensor, train_target_tensor, test_input_tensor, test_target_tensor, train_input_mean, train_input_std, train_target_mean, train_target_std

# Helper function for calculating the relative humidity
def calculate_relative_humidity(dewpoint_degC, air_temp_degC):
    """
    Calculate the relative humidity using the PowerCell formula from dewpoint temperature and actual temperature.
    TODO: Check if the formula is valid for h2/n2 mixtures (i.e., anode supply) as well.
    
    Returns:
    float: Relative humidity in percentage.
    """
    constant1 = 7.337936
    constant2 = 229.3975
    
    exponent = constant1 * ((dewpoint_degC / (dewpoint_degC + constant2)) - (air_temp_degC / (air_temp_degC + constant2)))
    rh_perc = 100 * (10 ** exponent)
    
    return rh_perc

# Computation of partial dependence
def partial_dependence(model, X, feature_index, fixed_feature_index=None, fixed_value=None, grid_resolution=100):
    """
    Calculate partial dependence for a given feature with one feature fixed.
    
    Parameters:
    - model: The trained gpytorch model.
    - X: The input data as a numpy array or pandas DataFrame.
    - feature_index: The index of the feature to vary.
    - fixed_feature_index: The index of the feature to fix.
    - fixed_value: The value to fix the specified feature at.
    - grid_resolution: The number of points to evaluate.

    Returns:
    - grid: The values of the feature.
    - pdp: The partial dependence values.
    """
    feature_min, feature_max = X[:, feature_index].min(), X[:, feature_index].max()
    grid = np.linspace(feature_min, feature_max, grid_resolution)
    X_temp = np.tile(X, (grid_resolution, 1))

    # Replace the values of the feature with the grid values
    for i, value in enumerate(grid):
        X_temp[i * X.shape[0]:(i + 1) * X.shape[0], feature_index] = value
    
    # Fix the specific feature value if provided
    if fixed_feature_index is not None and fixed_value is not None:
        X_temp[:, fixed_feature_index] = fixed_value
    
    X_temp = torch.tensor(X_temp, dtype=torch.float)
    
    # Compute the predictions
    model.eval()
    with torch.no_grad(), gpytorch.settings.fast_pred_var():
        predictions = model(X_temp).mean.numpy()
    
    # Average the predictions across the samples for each grid value
    pdp = predictions.reshape(grid_resolution, X.shape[0]).mean(axis=1)
    
    return grid, pdp

# Plot the model performance
def plot_model_performance(model, likelihood, input_tensor, target_tensor, target, iteration):

    # Evaluate the model on the training data
    model.eval()
    likelihood.eval()
    with torch.no_grad():
        predictions = likelihood(model(input_tensor)).mean.numpy()

    # Initialize plot
    f, ax = plt.subplots(1, 1)

    # Set the title
    ax.set_title(f'Model Performance Snapshot - Iteration: {iteration}')

    # Set the labels
    ax.set_xlabel('Normalized Targets')
    ax.set_ylabel('Normalized Predictions')

    # Set the aspect ratio to be equal
    # ax.set_aspect('equal', adjustable='box')
    ax.grid(True, zorder=1)

    # Plot the diagonal line
    ax.plot([target_tensor.min(), target_tensor.max()], [target_tensor.min(), target_tensor.max()], 'k--', lw=2)

    # Plot target vs. predictions
    ax.plot(target_tensor.numpy(), predictions, 'o', label='Training Data', color='blue')
    # Save and close the figure
    plt.savefig(f'gpr_model_performance_{target}_{iteration}.png', dpi=300, bbox_inches='tight')
    plt.close()

    # Reset the model to training mode
    model.train()
    likelihood.train()

# Partial dependence plots
def plot_partial_dependence(model, train_x_tensor, feature_names, feature_units, target='voltage', fixed_feature=None, fixed_value=400):

    # Making predictions
    model.eval()

    # Get the index of the fixed feature
    if fixed_feature is not None:
        feature_names_list = list(feature_names)
        fixed_feature_index = feature_names_list.index(fixed_feature)
    else:
        fixed_feature_index = None

    # Convert the training data to a numpy array for easier manipulation
    train_x_np = train_x_tensor.numpy()

    # Create subplots
    fig, axes = plt.subplots(4, 3, figsize=(18, 12))  # 4 rows, 3 columns of subplots

    # Adjust the layout
    fig.subplots_adjust(hspace=2)

    # Create figure title
    fig.suptitle(f'GPR Model - Partial Dependence Plots', fontsize=16)

    # Loop through each feature and plot its partial dependence
    for i in range(11):
        if i != fixed_feature_index:  # Skip the fixed feature
            grid, pdp = partial_dependence(model, train_x_np, i, fixed_feature_index=fixed_feature_index, fixed_value=fixed_value)
            ax = axes[i // 3, i % 3]  # Determine subplot location
            ax.plot(grid, pdp)
            # ax.set_ylim([0, 300])
            # extract target unit and check for lower and upper case
            if (target[0].lower() + target[1:]) in feature_units:
                ax.set_ylabel(f'{target} ({feature_units[target[0].lower() + target[1:]]})')
            elif (target[0].upper() + target[1:]) in feature_units:
                ax.set_ylabel(f'{target} ({feature_units[target[0].upper() + target[1:]]})')
            else:
                ax.set_ylabel(f'{target} (-)')

            # assign xlabel unit if it is not none
            if not pd.isna(feature_units[feature_names[i]]):
                ax.set_xlabel(f'{feature_names[i]} ({feature_units[feature_names[i]]})')
            else:
                ax.set_xlabel(f'{feature_names[i]} (-)')
            ax.grid(True, zorder=1)
        else:
            # Write the fixed feature value in the subplot in bold
            ax = axes[i // 3, i % 3]
            ax.text(0.5, 0.5, f'Fixed {fixed_feature} at {fixed_value} ({feature_units[feature_names[fixed_feature_index]]})', horizontalalignment='center', verticalalignment='center', transform=ax.transAxes, fontsize=12, fontweight='bold')


    # Remove empty subplot (if any)
    if len(axes.flatten()) > 11:
        fig.delaxes(axes.flatten()[-1])

    # Unify the y-axis limits to min and max values of the subplots (excluding the fixed feature subplot!)
    y_min = np.floor(np.min([ax.get_ylim()[0] for ax in axes.flatten() if ax.get_ylim()[0] != 0]))
    y_max = np.ceil(np.max([ax.get_ylim()[1] for ax in axes.flatten() if ax.get_ylim()[1] != 0]))    
    for ax in axes.flatten():
        ax.set_ylim([y_min, y_max])

    # Finalize the layout
    plt.tight_layout()

    # Draw the canvas
    fig.canvas.draw()

    # Save the figure with title according to the fixed feature value
    if fixed_feature is not None:
        plt.savefig(f'partial_dependence_plots_{fixed_feature}_{fixed_value}.png', bbox_inches='tight')
    else: 
        plt.savefig('partial_dependence_plots.png', bbox_inches='tight')

    # Display the figure
    plt.show()

# Main function
def train_gpr_model_on_doe_data(target='voltage', cutoff_current=0, plot=True, pretrained_model=None):

    # Load parameters
    _params_training = parameters.Training_Parameters()
    # _params_model = parameters.Model_Parameters()
    _params_logging = parameters.Logging_Parameters()

    # Set the random seed for reproducibility
    if _params_training.seed is not None:
        random.seed(_params_training.seed)
        np.random.seed(_params_training.seed)
        torch.manual_seed(_params_training.seed)

    # Create a folder to store the training results
    create_experiment_folder(_params_training=_params_training, _params_logging=_params_logging)

    # Load and assign the data
    pd_dataframe, _ = load_high_amp_doe_data()
    train_input_tensor, train_target_tensor, test_input_tensor, test_target_tensor, _, _, _, _ = \
        preprocess_data(pd_dataframe, target, cutoff_current)

    # Likelihood and model
    likelihood = gpytorch.likelihoods.GaussianLikelihood()
    model = ExactGPModel(train_input_tensor, train_target_tensor, likelihood)

    # Load the pretrained model if provided
    if pretrained_model is not None:
        my_dir = os.getcwd()
        pretrained_model_path = os.path.join(Path(my_dir).parents[0], pretrained_model)
        model.load_state_dict(torch.load(pretrained_model_path))

    # Set the model to training mode
    model.train()
    likelihood.train()

    optimizer = torch.optim.Adam(model.parameters(), lr=_params_training.learning_rate)
    mll = gpytorch.mlls.ExactMarginalLogLikelihood(likelihood, model)

    # List to store the loss values and iterations
    loss_list = []
    iterations = []

    # Training loop
    training_iterations = int(_params_training.iterations)
    for i in range(training_iterations):
        optimizer.zero_grad()
        output = model(train_input_tensor)
        loss = -mll(output, train_target_tensor)
        if i % _params_logging.log_interval == 0:
            print(f'Iteration {i}/{training_iterations} - Loss: {loss.item()}')
            loss_list.append(loss.item())
            iterations.append(i)
            plot_model_performance(model, likelihood, test_input_tensor, test_target_tensor, target, i)
        loss.backward()
        optimizer.step() # the actual update step!

    if (i+1) % _params_logging.log_interval == 0:
        print(f'Iteration {(i+1)}/{training_iterations} - Loss: {loss.item()}')
        loss_list.append(loss.item())
        iterations.append((i+1))
        plot_model_performance(model, likelihood, test_input_tensor, test_target_tensor, target, (i+1))

    # Save the model refering to the target variable
    torch.save(model.state_dict(), f'gpr_model_{target}.pth')

    # Plot the partial dependence plots
    if plot:
        # Plot the partial dependence plots
        # plot_partial_dependence(model, train_x_tensor, feature_names, feature_units=units, target=target, fixed_feature='current', fixed_value=200)
        # plot_partial_dependence(model, train_x_tensor, feature_names, feature_units=units, target=target, fixed_feature='current', fixed_value=300)
        # plot_partial_dependence(model, train_x_tensor, feature_names, feature_units=units, target=target, fixed_feature='current', fixed_value=400)
        # plot_partial_dependence(model, train_x_tensor, feature_names, feature_units=units, target=target, fixed_feature='current', fixed_value=500)
        # plot_partial_dependence(model, train_x_tensor, feature_names, feature_units=units, target=target, fixed_feature='current', fixed_value=600)
        # plot_partial_dependence(model, train_x_tensor, feature_names, feature_units=units, target=target, fixed_feature='current', fixed_value=700)

        # Plot the loss to a new figure
        fig = plt.figure(figsize=(8, 6))
        plt.plot(iterations, loss_list)
        plt.xlabel('Iterations')
        plt.ylabel('MLL Loss')
        plt.yscale('log')
        plt.grid(True, zorder=1)
        plt.title('Loss During Training')
        plt.savefig('loss.png', dpi=300, bbox_inches='tight')
        plt.close()

    # Save the loss values and the corresponding iteration values to a dat file
    with open('loss_values.dat', 'w') as file:
        writer = csv.writer(file)
        writer.writerows(zip(iterations, loss_list))

# Entry point of the script
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Train a Gaussian process regression model on Powercell DoE data")
    parser.add_argument("-t", "--target", type=str, help="Target variable for Gaussia process regression", default="voltage")
    parser.add_argument("-c", "--cutoff", type=float, help="Datapoints below cutoff current are removed from training data", default=0.0)
    parser.add_argument("-p", "--plot", type=bool, help="Plot the input/output data", default=True)
    parser.add_argument("-m", "--model", type=str, help="Load a pretrained GPR model", default=None)

    args = parser.parse_args()

    # Call the main function                        
    train_gpr_model_on_doe_data(args.target, args.cutoff, args.plot, args.model)
