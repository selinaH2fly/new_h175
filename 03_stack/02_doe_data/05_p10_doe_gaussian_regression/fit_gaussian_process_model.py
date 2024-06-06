"""The objective of this project is to train a Gaussian process regression model on Powercell DoE data.

Author: Stefan Notter
Date: June 2024
"""

# Import libraries
import os
import sys
import shutil
import argparse
import mariadb
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


def plot_model_performance(model, dataset, data_sampler, denormalize_min, denormalize_max, epoch=0, test=False):

    dataloader=torch.utils.data.DataLoader(dataset, batch_size=1, sampler=data_sampler)

    # Evaluate the model
    (predictions, observations) = evaluate_model(model, dataloader)

    # Denormalize the data
    predictions = ((0.5 * (predictions + 1)) * (denormalize_max - denormalize_min)) + denormalize_min
    observations = ((0.5 * (observations + 1)) * (denormalize_max - denormalize_min)) + denormalize_min
    
    # Convert list of tensors to a simple numpy array
    predictions = [tensor.numpy() for tensor in predictions]
    predictions_array = np.stack(predictions, axis=0)
    observations = [tensor.numpy() for tensor in observations]
    observations_array = np.stack(observations, axis=0)

    # Plot predictions vs. observations
    fig, axs = plt.subplots(2, 2)
    mgr = plt.get_current_fig_manager()
    mgr.resize(1280, 720)

    if test:
        fig.suptitle('Model Performance on Test Data')
    else:
        fig.suptitle('Model Performance on Training Data')

    voltage_predictions = predictions_array[:, 0]
    voltage_observations = observations_array[:, 0]
    axs[0, 0].grid(True, zorder=1)
    axs[0, 0].set_title('Voltage (V)')
    axs[0, 0].set_xlim([250, 450])
    axs[0, 0].set_ylim([250, 450])
    axs[0, 0].plot(np.linspace(250, 450, 100), np.linspace(250, 450, 100), color='blue', zorder=2)
    axs[0, 0].scatter(voltage_observations, voltage_predictions, color='orange', zorder=2)
    axs[0, 0].xaxis.set_label_text('Observations')
    axs[0, 0].yaxis.set_label_text('Predictions')

    pressure_drop_anode_predictions = predictions_array[:, 6]
    pressure_drop_anode_observations = observations_array[:, 6]
    axs[0, 1].grid(True, zorder=1)
    axs[0, 1].set_title('Anode Pressure Drop (mbar)')
    axs[0, 1].set_xlim([0, 500])
    axs[0, 1].set_ylim([0, 500])
    axs[0, 1].plot(np.linspace(0, 500, 100), np.linspace(0, 500, 100), color='blue', zorder=2)
    axs[0, 1].scatter(pressure_drop_anode_observations, pressure_drop_anode_predictions, color='orange', zorder=2)
    axs[0, 1].xaxis.set_label_text('Observations')
    axs[0, 1].yaxis.set_label_text('Predictions')

    pressure_drop_cathode_predictions = predictions_array[:, 7]
    pressure_drop_cathode_observations = observations_array[:, 7]
    axs[1, 0].grid(True, zorder=1)
    axs[1, 0].set_title('Cathode Pressure Drop (mbar)')
    axs[1, 0].set_xlim([0, 500])
    axs[1, 0].set_ylim([0, 500])
    axs[1, 0].plot(np.linspace(0, 500, 100), np.linspace(0, 500, 100), color='blue', zorder=2)
    axs[1, 0].scatter(pressure_drop_cathode_observations, pressure_drop_cathode_predictions, color='orange', zorder=2)
    axs[1, 0].xaxis.set_label_text('Observations')
    axs[1, 0].yaxis.set_label_text('Predictions')

    pressure_drop_coolant_predictions = predictions_array[:, 8]
    pressure_drop_coolant_observations = observations_array[:, 8]
    axs[1, 1].grid(True, zorder=1)
    axs[1, 1].set_title('Coolant Pressure Drop (mbar)')
    axs[1, 1].set_xlim([0, 1000])
    axs[1, 1].set_ylim([0, 1000])
    axs[1, 1].plot(np.linspace(0, 1000, 100), np.linspace(0, 1000, 100), color='blue', zorder=2)
    axs[1, 1].scatter(pressure_drop_coolant_observations, pressure_drop_coolant_predictions, color='orange', zorder=2)
    axs[1, 1].xaxis.set_label_text('Observations')
    axs[1, 1].yaxis.set_label_text('Predictions')

    plt.tight_layout()

    if test:
        plt.savefig("model_performance_test_{}".format((epoch + 1)) + ".png")
    else:
        plt.savefig("model_performance_train_{}".format((epoch + 1)) + ".png")

    # Close the figure
    plt.close(fig)

    return None

def create_experiment_folder(_params_model, _params_training, _params_logging):
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
    dirName = "{}_ann_doe_model_experiment".format(experimentID)
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
    parameterFile.write(
        format(vars(_params_model)) + "\n" +
        format(vars(_params_training)) + "\n" +
        format(vars(_params_logging)))
    parameterFile.close()

    return None

# Main function
def train_gpr_model_on_doe_data(plot=False):

   # Training data
    train_x = torch.linspace(0, 1, 10)
    train_y = torch.sin(train_x * (2 * torch.pi)) + torch.randn(train_x.size()) * 0.2

    # Likelihood and model
    likelihood = gpytorch.likelihoods.GaussianLikelihood()
    model = ExactGPModel(train_x, train_y, likelihood)

    # Training the model
    model.train()
    likelihood.train()

    optimizer = torch.optim.Adam(model.parameters(), lr=0.1)
    mll = gpytorch.mlls.ExactMarginalLogLikelihood(likelihood, model)

    training_iterations = 50
    for i in range(training_iterations):
        optimizer.zero_grad()
        output = model(train_x)
        loss = -mll(output, train_y)
        loss.backward()
        print(f'Iteration {i + 1}/{training_iterations} - Loss: {loss.item()}')
        optimizer.step()

    # Making predictions
    model.eval()
    likelihood.eval()

    # Test points are regularly spaced along [0,1]
    test_x = torch.linspace(0, 2, 100)
    with torch.no_grad(), gpytorch.settings.fast_pred_var():
        observed_pred = likelihood(model(test_x))

    # Plotting
    with torch.no_grad():
        f, ax = plt.subplots(1, 1, figsize=(8, 6))
        # Get upper and lower confidence bounds
        lower, upper = observed_pred.confidence_region()
        # Plot training data as black stars
        ax.plot(train_x.numpy(), train_y.numpy(), 'k*')
        # Plot predictive means as blue line
        ax.plot(test_x.numpy(), observed_pred.mean.numpy(), 'b')
        # Shade between the lower and upper confidence bounds
        ax.fill_between(test_x.numpy(), lower.numpy(), upper.numpy(), alpha=0.5)
        ax.set_ylim([-3, 3])
        ax.legend(['Observed Data', 'Mean', 'Confidence'])
        plt.show()


# Entry point of the script
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Train a Gaussian process regression model on Powercell DoE data")
    parser.add_argument("-p", "--plot", type=int, help="Plot the input/output data", default=False)

    args = parser.parse_args()

    # Call the main function                        
    train_gpr_model_on_doe_data(args.plot)
