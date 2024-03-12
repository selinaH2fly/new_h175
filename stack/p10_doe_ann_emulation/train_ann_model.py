"""The objective of this project is to train a simple artificial neural network on Powercell DoE data. The trained
model shall emulate the input-output behavior of the response surface model provided by Powercell, which was created
by some sort of Gauss interpolation by means of GT-SUITE from Gamma Technologies.

Author: Stefan Notter
Date: Oct. 2023
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
import matplotlib.pyplot as plt
import pandas as pd
import random

# Import parameters
import parameters

# Import functions to load and visualize the doe dataset
from load_doe_data import load_doe_data
from load_doe_data import plot_doe_data

# Define a neural network class
class ANN_Stack_Model(nn.Module):

    # Define the layers of the network
    def __init__(self, num_inputs=10, num_outputs=10, hidden_layer_sizes=[64, 64], dropout_prob=0.3):
        super(ANN_Stack_Model, self).__init__()
        self.fc1 = nn.Linear(num_inputs, hidden_layer_sizes[0])
        self.drop1 = nn.Dropout(p=dropout_prob)
        self.fc2 = nn.Linear(hidden_layer_sizes[0], hidden_layer_sizes[1])
        self.drop2 = nn.Dropout(p=dropout_prob)
        self.fc3 = nn.Linear(hidden_layer_sizes[1], num_outputs)

    # Define the forward pass using relu activation functions
    def forward(self, x):
        x = self.fc1(x)
        x = F.relu(x)
        x = self.drop1(x)
        x = self.fc2(x)
        x = F.relu(x)
        x = self.drop2(x)
        x = self.fc3(x)
        return x


# Define a function to test the network
def evaluate_model(model, dataloader):

    predictions_list = []
    observations_list = []

    # Loop over the dataset
    for inputs, observations in dataloader:

        # Forward pass
        predictions = model(inputs)
        predictions_list.append(predictions)
        observations_list.append(observations)
    
    predictions_tensor = torch.cat(predictions_list, axis=0)
    observations_tensor = torch.cat(observations_list, axis=0)

    return (predictions_tensor, observations_tensor)


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
def train_ann_model_on_doe_data(plot=False):

    # Load parameters
    _params_model = parameters.Model_Parameters()
    _params_training = parameters.Training_Parameters()
    _params_logging = parameters.Logging_Parameters()

     # Set the random seed for reproducibility
    if _params_training.seed:
        random.seed(_params_training.seed)
        np.random.seed(_params_training.seed)
        torch.manual_seed(_params_training.seed)

    # Create a folder to store the training results
    create_experiment_folder(_params_model=_params_model, _params_training=_params_training, _params_logging = _params_logging)

    # Load and assign the data
    (model_in_dict, model_out_dict) = load_doe_data()

    # Create scatter plots of the varied input parameters (cf. illustration provided by Powercell)
    if plot:
        plot_doe_data(model_in_dict, model_out_dict)

    # Assign data to torch tensors [n_samples, n_features]
    model_in_tensor = torch.tensor(list(model_in_dict.values())).t()
    model_out_tensor = torch.tensor(list(model_out_dict.values())).t()

    # Normalize to [0, 1] (each feature is normalized independently) TODO: Normalization should be done after splitting into training and testing sets (to prevent data leakage)
    model_in_tensor_normalized = ((model_in_tensor - model_in_tensor.min(axis=0)[0]) / (model_in_tensor.max(axis=0)[0] - model_in_tensor.min(axis=0)[0])) * 2 - 1
    model_out_tensor_normalized = ((model_out_tensor - model_out_tensor.min(axis=0)[0]) / (model_out_tensor.max(axis=0)[0] - model_out_tensor.min(axis=0)[0])) * 2 - 1	

    # Create a shuffled dataset
    dataset = torch.utils.data.TensorDataset(model_in_tensor_normalized, model_out_tensor_normalized)
    dataset_size = len(dataset)
    indices = list(range(dataset_size))
    random.shuffle(indices)

    # Split the dataset into training and testing sets
    split_ratio = _params_training.split_ratio
    split_index = int(split_ratio * dataset_size)

    # Create data samplers for the training and testing sets
    train_sampler = torch.utils.data.SubsetRandomSampler(indices[:split_index])
    test_sampler = torch.utils.data.SubsetRandomSampler(indices[split_index:])

    # Create a dataloader
    trainloader = torch.utils.data.DataLoader(dataset, batch_size=_params_training.batch_size, sampler=train_sampler)

    # Instantiate the network with size of input and output layer according to the data
    model = ANN_Stack_Model(num_inputs=len(model_in_dict), num_outputs=len(model_out_dict),
                            hidden_layer_sizes=[_params_model.hidden_layer_size_1, _params_model.hidden_layer_size_2],
                            dropout_prob=_params_training.dropout_prob)
    
    # Load state dict from parent foler
    # model.load_state_dict(torch.load("../ann_doe_mode_final_experiment_5_06-Nov-2023.pt"))

    # Define the loss function and the optimizer
    criterion = nn.MSELoss()
    optimizer = optim.SGD(model.parameters(), lr=_params_training.learning_rate, momentum=_params_training.momentum)

    # Set up file to save average losses
    lossFile = open("lossFile_running.dat", "w")
    lossFile.write("epoch,avg_loss\n")
    lossFile.close()

    epoch_loss_history = []
    average_loss = []

    # Loop over the dataset multiple times
    for epoch in range(_params_training.epochs):

        epoch_loss = 0
        model.train()

        # Loop over the dataset
        for inputs, targets in trainloader:

            # Zero the parameter gradients
            optimizer.zero_grad()

            # Forward pass, backward pass, and optimize
            outputs = model(inputs)
            loss = criterion(outputs, targets)
            loss.backward()
            optimizer.step()

            # Assign loss
            epoch_loss += loss.item()

        epoch_loss /= len(trainloader)
        epoch_loss_history.append(epoch_loss)

        n_mean = _params_logging.log_interval if len(epoch_loss_history) >= _params_logging.log_interval else len(epoch_loss_history)
        average_loss.append(np.convolve(list(epoch_loss_history)[-n_mean:], np.ones((n_mean,)) / n_mean, mode='valid')[0])

        # Print results to display and log them to file
        if len(average_loss) and (epoch + 1) % _params_logging.log_interval == 0:
            print('epoch: %d, avg. loss: %.6f' % (epoch + 1, average_loss[-1]))
            with open("lossFile_running.dat", "a+") as loss_file:
                    loss_file.write(format((epoch +1)) + "," + '{:.6f}'.format(average_loss[-1]) + "\n")

        # Save model and create sample of system behavior
        if (epoch == 0) or ((epoch + 1) % _params_logging.save_interval == 0):
            
            if epoch:
                torch.save(model.state_dict(), "ann_doe_model_epoch_{}".format((epoch + 1)) + ".pt")

                fig, ax = plt.subplots()
                returns_to_plot = pd.read_csv('lossFile_running.dat')
                returns_to_plot.plot(x='epoch', y='avg_loss', ax=ax)
                plt.title("Training Progress")
                plt.xlabel("Training Epochs (-)")
                plt.xlim([0, _params_training.epochs])
                plt.ylabel("Training Loss (-)")
                plt.yscale('log')
                plt.ylim([1e-2, 2e-1])
                plt.yticks([2e-1, 1e-1, 9e-2, 8e-2, 7e-2, 6e-2, 5e-2, 4e-2, 3e-2, 2e-2, 1e-2, 1e-1])
                plt.grid(True)
                plt.legend(["Average MSE"], loc="upper right")
                plt.savefig("average_loss_{}".format((epoch + 1)) + ".png")
                plt.close()
        
            model.eval()
            with torch.no_grad():
                # Plot the model performance
                plot_model_performance(model, dataset, data_sampler=train_sampler, denormalize_min=model_out_tensor.min(axis=0)[0], denormalize_max=model_out_tensor.max(axis=0)[0], epoch=epoch, test=False)
                plot_model_performance(model, dataset, data_sampler=test_sampler, denormalize_min=model_out_tensor.min(axis=0)[0], denormalize_max=model_out_tensor.max(axis=0)[0], epoch=epoch, test=True)

    # Rename loss file consistently
    loss_file.close()
    os.rename(loss_file.name, "average_loss_final.dat")

    print('Finished Training')
    torch.save(model.state_dict(), "ann_doe_mode_final.pt")


# Entry point of the script
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Train an artificial neural network on Powercell DoE data")
    parser.add_argument("-p", "--plot", type=int, help="Plot the input/output data", default=False)

    args = parser.parse_args()

    # Call the main function                        
    train_ann_model_on_doe_data(args.plot)
