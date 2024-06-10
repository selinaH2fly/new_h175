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
# import parameters

# Import functions to load and visualize the doe dataset
# from load_doe_data import load_doe_data
# from load_doe_data import plot_doe_data

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

def partial_dependence(model, X, feature, grid_resolution=100):
    """
    Calculate partial dependence for a given feature.
    
    Parameters:
    - model: The trained gpytorch model.
    - X: The input data as a numpy array or pandas DataFrame.
    - feature: The index of the feature to vary.
    - grid_resolution: The number of points to evaluate.

    Returns:
    - grid: The values of the feature.
    - pdp: The partial dependence values.
    """
    # Determine the range of the feature
    feature_min, feature_max = X[:, feature].min(), X[:, feature].max()
    
    # Create a grid of values for the feature
    grid = np.linspace(feature_min, feature_max, grid_resolution)
    
    # Create a copy of the input data
    X_temp = np.tile(X, (grid_resolution, 1))
    
    # Replace the values of the feature with the grid values
    X_temp[:, feature] = np.repeat(grid, X.shape[0])
    
    # Convert the data to a torch tensor
    X_temp = torch.tensor(X_temp, dtype=torch.float)
    
    # Compute the predictions
    model.eval()
    with torch.no_grad(), gpytorch.settings.fast_pred_var():
        predictions = model(X_temp).mean.numpy()
    
    # Average the predictions across the samples
    pdp = predictions.reshape(grid_resolution, X.shape[0]).mean(axis=1)
    
    return grid, pdp

def plot_partial_dependence(model, train_x_tensor, feature_names, feature_units, target='voltage'):

    # Making predictions
    model.eval()

    # Convert the training data to a numpy array for easier manipulation
    train_x_np = train_x_tensor.numpy()

    # Create subplots
    fig, axes = plt.subplots(4, 3, figsize=(18, 12))  # 4 rows, 3 columns of subplots

    # Adjust the layout
    fig.subplots_adjust(hspace=1)

    # Create figure title
    fig.suptitle(f'Gaussian Process Regression Model - Partial Dependence Plots', fontsize=16)

    # Loop through each feature and plot its partial dependence
    for i in range(11):
        grid, pdp = partial_dependence(model, train_x_np, i)
        ax = axes[i // 3, i % 3]  # Determine subplot location
        ax.plot(grid, pdp)
        # ax.set_ylim([0, 300])
        ax.set_ylabel(f'{target}')
        # assign unit if it is not none
        if not pd.isna(feature_units[feature_names[i]]):
            ax.set_xlabel(f'{feature_names[i]} ({feature_units[feature_names[i]]})')
        else:
            ax.set_xlabel(f'{feature_names[i]} (-)')
        ax.grid(True, zorder=1)

    # Remove empty subplot (if any)
    if len(axes.flatten()) > 11:
        fig.delaxes(axes.flatten()[-1])

    # Finalize the layout
    plt.tight_layout()

    # Draw the canvas
    fig.canvas.draw()

    # Save the figure
    plt.savefig('partial_dependence_plots.png', bbox_inches='tight')

    # Display the figure
    plt.show()

# Main function
def train_gpr_model_on_doe_data(target='voltage', plot=True):

    # Create a folder to store the training results
    create_experiment_folder()

    # Load and assign the data
    pd_dataframe, units = load_high_amp_doe_data()
    train_x = pd_dataframe[['current', 'anode_stoich', 'temp_anode_inlet', 'pressure_anode_inlet', 'temp_anode_dewpoint_gas',
                            'cathode_stoich', 'temp_cathode_inlet', 'pressure_cathode_inlet', 'temp_cathode_dewpoint_gas',
                            'temp_coolant_inlet', 'flow_coolant']]
    feature_names = train_x.columns
    train_y = pd_dataframe[[target]]

    # assign the data to a PyTorch tensor
    for column in train_x.columns:
        train_x[column] = pd.to_numeric(train_x[column].values, errors='coerce', downcast='float')
    for column in train_y.columns:
        train_y[column] = pd.to_numeric(train_y[column].values, errors='coerce', downcast='float')

    # Convert the data to PyTorch tensors
    train_x_tensor = torch.tensor(train_x.values, dtype=torch.float32)
    train_y_tensor = torch.tensor(train_y.values, dtype=torch.float32)
    train_y_tensor = train_y_tensor.flatten()

    # Likelihood and model
    likelihood = gpytorch.likelihoods.GaussianLikelihood()
    model = ExactGPModel(train_x_tensor, train_y_tensor, likelihood)

    # Training the model
    model.train()
    likelihood.train()

    optimizer = torch.optim.Adam(model.parameters(), lr=0.1)
    mll = gpytorch.mlls.ExactMarginalLogLikelihood(likelihood, model)

    # List to store the loss values and iterations
    loss_list = []

    # Training loop
    training_iterations = int(200)
    for i in range(training_iterations):
        optimizer.zero_grad()
        output = model(train_x_tensor)
        loss = -mll(output, train_y_tensor)
        if i % 100 == 0:
            print(f'Iteration {i}/{training_iterations} - Loss: {loss.item()}')
            loss_list.append(loss.item())
        loss.backward()
        optimizer.step()

    # Save the model
    torch.save(model.state_dict(), 'model_current_to_voltage.pth')

    # Plot the partial dependence plots
    if plot:
        # Plot the partial dependence plots
        plot_partial_dependence(model, train_x_tensor, feature_names, feature_units=units, target='voltage')

        # Plot the loss to a new figure
        fig = plt.figure(figsize=(8, 6))
        plt.plot(loss_list)
        plt.xlabel('Iterations (x100)')
        plt.ylabel('Loss')
        plt.yscale('log')
        plt.grid(True, zorder=1)
        plt.title('Loss During Training')
        plt.savefig('loss.png', dpi=300, bbox_inches='tight')
        plt.show()

    # Save the loss values to a dat file
    with open('loss_values.dat', 'w') as file:
        for loss in loss_list:
            file.write(str(loss) + '\n')

# Entry point of the script
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Train a Gaussian process regression model on Powercell DoE data")
    parser.add_argument("-t", "--target", type=str, help="Target variable for Gaussia process regression", default="voltage")
    parser.add_argument("-p", "--plot", type=bool, help="Plot the input/output data", default=True)


    args = parser.parse_args()

    # Call the main function                        
    train_gpr_model_on_doe_data(args.target, args.plot)
