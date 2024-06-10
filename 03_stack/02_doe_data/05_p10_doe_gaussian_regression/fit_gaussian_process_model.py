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

    return df

# Main function
def train_gpr_model_on_doe_data(target='metis_CVM_Cell_Voltage_Mean', plot=False):

    # Create a folder to store the training results
    create_experiment_folder()

    # Load and assign the data
    pd_dataframe = load_high_amp_doe_data()

   # Extract input training data (current) and output training data (cell voltage)
    # train_x = pd_dataframe['current']
    # train_y = pd_dataframe['voltage']
    # train_y = pd_dataframe['metis_CVM_Cell_Voltage_Mean']

    # Extract input training data:
    # current, anode stoichiometry, anode inlet temperature, anode inlet pressure, anode inlet dewpoint, ...
    # cathode stoichiometry, cathode inlet temperature, cathode inlet pressure, cathode inlet dewpoint, coolant inlet temperature, coolant flow
    # train_x = pd_dataframe[['current'], ['anode_stoich'], ['temp_anode_inlet'], ['pressure_anode_inlet'], ['temp_anode_dewpoint_gas'],
    #                        ['cathode_stoich'], ['temp_cathode_inlet'], ['pressure_cathode_inlet'], ['temp_cathode_dewpoint_gas'],
    #                        ['temp_coolant_inlet'], ['flow_coolant']]
    train_x = pd_dataframe[['current', 'anode_stoich', 'temp_anode_inlet', 'pressure_anode_inlet', 'temp_anode_dewpoint_gas',
                            'cathode_stoich', 'temp_cathode_inlet', 'pressure_cathode_inlet', 'temp_cathode_dewpoint_gas',
                            'temp_coolant_inlet', 'flow_coolant']]
    
    train_y = pd_dataframe[[target]]

    # assign the data to a PyTorch tensor
    for column in train_x.columns:
        train_x[column] = pd.to_numeric(train_x[column].values, errors='coerce', downcast='float')
    for column in train_y.columns:
        train_y[column] = pd.to_numeric(train_y[column].values, errors='coerce', downcast='float')

    # Convert the data to PyTorch tensors
    train_x = torch.tensor(train_x.values, dtype=torch.float32)
    train_y = torch.tensor(train_y.values, dtype=torch.float32)

    # Likelihood and model
    likelihood = gpytorch.likelihoods.GaussianLikelihood()
    model = ExactGPModel(train_x, train_y, likelihood)

    # Training the model
    model.train()
    likelihood.train()

    optimizer = torch.optim.Adam(model.parameters(), lr=0.1)
    mll = gpytorch.mlls.ExactMarginalLogLikelihood(likelihood, model)

    # List to store the loss values
    loss_list = []

    # Training loop
    training_iterations = int(20e3)
    for i in range(training_iterations):
        optimizer.zero_grad()
        output = model(train_x)
        loss = -mll(output, train_y)
        if i % 100 == 0:
            print(f'Iteration {i}/{training_iterations} - Loss: {loss.item()}')
            loss_list.append(loss.item())
        loss.backward()
        optimizer.step()

    # Save the model
    torch.save(model.state_dict(), 'model_current_to_voltage.pth')

    # Making predictions
    model.eval()
    likelihood.eval()

    # Test points are regularly spaced along [0,800] Amps
    test_x = torch.linspace(0, 1000, 10000)
    with torch.no_grad(), gpytorch.settings.fast_pred_var():
        observed_pred = likelihood(model(test_x))

    # Plotting
    with torch.no_grad():
        f, ax = plt.subplots(1, 1, figsize=(8, 6))
        # Get upper and lower confidence bounds
        lower, upper = observed_pred.confidence_region()
        # Plot training data as black stars
        ax.plot(train_x.numpy(), train_y.numpy(), 'k*', zorder=2)
        # Plot predictive means as blue line
        ax.plot(test_x.numpy(), observed_pred.mean.numpy(), 'b', zorder=2)
        # Shade between the lower and upper confidence bounds
        ax.fill_between(test_x.numpy(), lower.numpy(), upper.numpy(), alpha=0.5)
        ax.set_ylim([100, 300])
        ax.set_xlim([0, 1000])
        ax.legend(['Observed Data', 'Mean', 'Confidence'])
        ax.set_xlabel('Current [A]')
        ax.set_ylabel('Voltage [V]')
        ax.set_title('First Shot Gaussian Regression Model: Voltage vs Current')
        plt.savefig('first_shot_gpr_model.png', dpi=300, bbox_inches='tight')
        ax.grid(True, zorder=1)
        plt.show()

    # Plot the loss
    plt.plot(loss_list)
    plt.xlabel('Iteration')
    plt.ylabel('Loss')
    plt.title('Loss during training')
    plt.savefig('loss.png', dpi=300, bbox_inches='tight')
    plt.show()


# Entry point of the script
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Train a Gaussian process regression model on Powercell DoE data")
    parser.add_argument("-t", "--target", type=str, help="Target variable for Gaussia process regression", default=False)
    parser.add_argument("-p", "--plot", type=bool, help="Plot the input/output data", default=False)


    args = parser.parse_args()

    # Call the main function                        
    train_gpr_model_on_doe_data(args.target, args.plot)
