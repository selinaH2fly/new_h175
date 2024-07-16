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

# Import parameters
import parameters

# Import input optimization function from input_optimization.py
from input_optimization import optimize_inputs_evolutionary, optimize_inputs_gradient_based

# Define a GP model
class ExactGPModel(gpytorch.models.ExactGP):
    def __init__(self, train_x, train_y, likelihood):
        super(ExactGPModel, self).__init__(train_x, train_y, likelihood=gpytorch.likelihoods.GaussianLikelihood())
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

    # create folder for storing model snapshots
    os.mkdir("model_performance_snapshots")

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
def preprocess_data(df, target='voltage', cutoff_current=0, params_pyhsics=None):

    # Drop data points from the dataframe with current values below the cutoff value
    df = df[df['current'] > cutoff_current]

    # Convert the dataframes to dictionaries
    df_dict = df.to_dict('list')

    # Create a dictionary for processed training input data
    input_data_dict = {}

    # New features (idea as of July 05, 2024)
    # input_data_tensor['cell_power_W'] = [power / 275 * 1000 for power in df_dict['power']]
    # input_data_tensor['anode_rh_in_perc'] = [calculate_relative_humidity(dewpoint, temp) for dewpoint, temp in zip(df_dict['temp_anode_dewpoint_gas'], df_dict['temp_anode_inlet'])]
    # input_data_tensor['cathode_rh_in_perc'] = [calculate_relative_humidity(dewpoint, temp) for dewpoint, temp in zip(df_dict['temp_cathode_dewpoint_gas'], df_dict['temp_cathode_inlet'])]
    # input_data_tensor['cathode_stoich_'] = df_dict['cathode_stoich']
    # input_data_tensor['cathode_pressure_in_barg'] = df_dict['pressure_cathode_inlet']
    # input_data_tensor['coolant_temp_in_degC'] = df_dict['temp_coolant_inlet']
    # input_data_tensor['coolant_flow_in_lpm'] = df_dict['flow_coolant']

    # Classic Powercell features
    # input_data_tensor['current'] = df_dict['current']
    # input_data_tensor['stoich_anode'] = df_dict['anode_stoich']
    # input_data_tensor['stoich_cathode'] = df_dict['cathode_stoich']
    # input_data_tensor['pressure_anode_in_barg'] = df_dict['pressure_anode_inlet']
    # input_data_tensor['pressure_cathode_in_barg'] = df['pressure_cathode_inlet']
    # input_data_tensor['temp_anode_inlet_degC'] = df_dict['temp_anode_inlet']
    # input_data_tensor['temp_cathode_inlet_degC'] = df_dict['temp_cathode_inlet']
    # input_data_tensor['dewpoint_anode_degC'] = df_dict['temp_anode_dewpoint_gas']
    # input_data_tensor['dewpoint_cathode_degC'] = df_dict['temp_cathode_dewpoint_gas']
    # input_data_tensor['temp_coolant_inlet_degC'] = df_dict['temp_coolant_inlet']
    # input_data_tensor['flow_coolant_lpm'] = df_dict['flow_coolant']

    # "Best" features from the feature selection process for the voltage prediction (as of July 05, 2024)
    input_data_dict['current_A'] = df_dict['current']
    input_data_dict['cathode_rh_in_perc'] = [calculate_relative_humidity(dewpoint, temp) for dewpoint, temp in zip(df_dict['temp_cathode_dewpoint_gas'], df_dict['temp_cathode_inlet'])]
    input_data_dict['stoich_cathode'] = df_dict['cathode_stoich']
    input_data_dict['pressure_cathode_in_bara'] = [pressure_barg + params_pyhsics.std_ambient_pressure_bar for pressure_barg in df_dict['pressure_cathode_inlet']]
    # input_data_dict['temp_coolant_avg_degC'] = [(temp_in + temp_out) / 2 for temp_in, temp_out in zip(df_dict['temp_coolant_inlet'], df_dict['temp_coolant_outlet'])]
    input_data_dict['temp_coolant_outlet_degC'] = df_dict['temp_coolant_outlet'] # Use the outlet temperature as suggested by Steffen P.

    # Extract feature names and write them to a file
    feature_names = list(input_data_dict.keys())
    with open('feature_names.txt', 'w') as file:
        for feature in feature_names:
            file.write(f'{feature}\n')

    # Try to find the target variable in the df_dict
    if target in df_dict:
        target_data = df_dict[target]
    else:
        # Check for custom targets
        if target == 'eta_lhv':
            target_data = [voltage / 275 / params_pyhsics.hydrogen_lhv_voltage_equivalent for voltage in df_dict['voltage']]
        elif target == 'eta_hhv':
            target_data = [voltage / 275 / params_pyhsics.hydrogen_hhv_voltage_equivalent for voltage in df_dict['voltage']]
        else:
            raise ValueError(f'Target variable {target} not found in the dataframe!')

    # Convert to pytorch tensors
    input_data_tensor = torch.tensor(list(input_data_dict.values()), dtype=torch.float32).T
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

    # Get means and standard deviations for normalization
    input_data_mean = input_data_tensor.mean(dim=0)
    input_data_std = input_data_tensor.std(dim=0)
    target_data_mean = target_data_tensor.mean()
    target_data_std = target_data_tensor.std()

    # Normalize the training and test data
    train_input_tensor = (train_input_tensor - input_data_mean) / input_data_std
    train_target_tensor = (train_target_tensor - target_data_mean) / target_data_std
    test_input_tensor = (test_input_tensor - input_data_mean) / input_data_std
    test_target_tensor = (test_target_tensor - target_data_mean) / target_data_std

    return train_input_tensor, train_target_tensor, test_input_tensor, test_target_tensor, (input_data_mean, input_data_std), (target_data_mean, target_data_std), feature_names

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
    - X: The input data as a numpy array or torch tensor.
    - feature_index: The index of the feature to vary.
    - fixed_feature_index: The index of the feature to fix.
    - fixed_value: The value to fix the specified feature at.
    - grid_resolution: The number of points to evaluate.

    Returns:
    - grid: The values of the feature.
    - pdp: The partial dependence values.
    """
      # Calculate the range of the feature
    feature_min, feature_max = X[:, feature_index].min(), X[:, feature_index].max()
    grid = np.linspace(feature_min, feature_max, grid_resolution)
    
    # Create a tiled array to hold the variations
    X_temp = np.tile(X, (grid_resolution, 1))

    # Replace the values of the feature with the grid values
    for i, value in enumerate(grid):
        X_temp[i * X.shape[0]:(i + 1) * X.shape[0], feature_index] = value

    # Fix the specific feature value if provided
    if fixed_feature_index is not None and fixed_value is not None:
        X_temp[:, fixed_feature_index] = fixed_value
    
    # Convert to torch tensor
    X_temp = torch.tensor(X_temp, dtype=torch.float)
    
    # Compute the predictions
    model.eval()
    with torch.no_grad(), gpytorch.settings.fast_pred_var():
        predictions = model(X_temp).mean.numpy()
    
    # Average the predictions across the samples for each grid value
    pdp = predictions.reshape(grid_resolution, X.shape[0]).mean(axis=1)
    
    return grid, pdp

# Evaluate the model performance
def eval_model_performance(model, likelihood, mll, input_tensor, target_tensor):

    model.eval()
    likelihood.eval()

    with torch.no_grad():
        val_output = model(input_tensor)
        val_loss = -mll(val_output, target_tensor)

    return val_loss

# Plot the model performance
def plot_model_performance(model, likelihood, input_tensor, target_tensor, iteration, target="voltage", target_normalization=(0, 1), test=True):

    # Evaluate the model on the training data
    model.eval()
    likelihood.eval()
    with torch.no_grad():
        with warnings.catch_warnings():
            warnings.simplefilter("ignore", GPInputWarning)
            predictions = likelihood(model(input_tensor)).mean.numpy()

    # Denormalize the target tensor and the predictions
    targets = target_tensor.numpy() * target_normalization[1].numpy() + target_normalization[0].numpy()
    predictions = predictions * target_normalization[1].numpy() + target_normalization[0].numpy()

    # Initialize plot
    f, ax = plt.subplots(1, 1)
    mgr = plt.get_current_fig_manager()
    mgr.resize(720, 720)

    # Set the title
    ax.set_title(f'Model Performance Snapshot Test Data - Iteration: {iteration}') if test else ax.set_title(f'Model Performance Snapshot Training Data - Iteration: {iteration}')

    # Set the labels
    ax.set_xlabel(f'{target} Targets')
    ax.set_ylabel(f'{target} Predictions')

    # Set axis limits to min and max values of the targets + 10% (rounded to nearest 0.1)
    y_min = np.floor((np.min(targets) * 0.9) * 10) / 10
    y_max = np.ceil((np.max(targets) * 1.1) * 10) / 10
    ax.set_xlim([y_min, y_max])
    ax.set_ylim([y_min, y_max])

    # Set the aspect ratio to be equal
    # ax.set_aspect('equal', adjustable='box')
    ax.grid(True, zorder=1)

    # Plot the diagonal line
    ax.plot([y_min, y_max], [y_min, y_max], 'k--', lw=2)

    # Plot target vs. predictions
    ax.plot(targets, predictions, 'o', label='Training Data', color='blue')

    # Compute the RMS error, R2 score, max error
    rms_error = np.sqrt(np.mean((targets - predictions) ** 2))
    r2_score = np.corrcoef(targets, predictions)[0, 1] ** 2
    max_error = np.max(np.abs(targets - predictions))

    # Add text to the plot
    ax.text(
        0.05, 0.95, 
        f'RMS Error: {rms_error:.4f}\nMax Error: {max_error:.4f}\nR2 Score: {r2_score:.4f}', 
        horizontalalignment='left', 
        verticalalignment='top', 
        transform=ax.transAxes, 
        fontsize=10,
        bbox=dict(facecolor='white', alpha=0.8, edgecolor='none', pad=3.0)  # Add background color
    )

    # Save the figure to the model performance snapshots folder
    path = 'model_performance_snapshots/test' if test else 'model_performance_snapshots/train'
    os.makedirs(path, exist_ok=True)
    plt.savefig(f'{path}/model_performance_snapshot_{iteration}.png', dpi=300, bbox_inches='tight')

    plt.close()

def create_video_from_snapshots(test=True):

    # Change the current working directory
    path = 'model_performance_snapshots/test' if test else 'model_performance_snapshots/train'
    os.chdir(path)

    # Set the path to the folder containing your PNG frames and the output video file name
    frame_folder = os.getcwd()

    output_video = "model_performance_evolution_test.avi" if test else "model_performance_evolution_train.avi"

    # Define the frame rate and frame size
    frame_rate = 5  # Adjust as needed

    # Get a list of the PNG files in the folder
    frame_files = sorted([f for f in os.listdir(frame_folder) if f.startswith("model_performance_snapshot")], key=lambda x: int(''.join(filter(str.isdigit, os.path.splitext(x)[0]))))

    # Extract frame size from first frame
    frame_path = os.path.join(frame_folder, frame_files[0])
    frame = cv2.imread(frame_path)
    height, width, _ = frame.shape

    # Initialize VideoWriter
    fourcc = 0
    out = cv2.VideoWriter(output_video, fourcc, frame_rate, (width, height))

    # Loop through the PNG frames and add them to the video
    for frame_file in frame_files:
        frame_path = os.path.join(frame_folder, frame_file)
        frame = cv2.imread(frame_path)
        out.write(frame)

    # Release the VideoWriter
    out.release()

    print("Video creation for test data complete.") if test else print("Video creation for training data complete.")

    # Change the current working directory back to the experiment folder
    os.chdir("../..")

    return None

# Partial dependence plots
def plot_partial_dependence(model, train_x_tensor, feature_names, target='voltage', input_normalization=(0, 1), target_normalization=(0, 1), fixed_feature=None, fixed_value=400):

    # Making predictions
    model.eval()

    # Get the index of the fixed feature
    if fixed_feature is not None:
        fixed_feature_index = feature_names.index(fixed_feature)
        fixed_value_norm = (fixed_value - input_normalization[0][fixed_feature_index]) / input_normalization[1][fixed_feature_index]

    else:
        fixed_feature_index = None
        fixed_value_norm = None

    # Convert the training data to a numpy array for easier manipulation
    train_x_np = train_x_tensor.numpy()

    # Number of features
    num_features = len(feature_names)

    # Create subplots with 2 columns
    fig, axes = plt.subplots(int(np.ceil(num_features / 2)), 2, figsize=(12, 12))

    # Adjust the layout
    fig.subplots_adjust(hspace=2)

    # Create figure title
    fig.suptitle('GPR DoE Model - Partial Dependence Plots')

    # Loop through each feature and plot its partial dependence TODO: Make agnostic to the number of features
    for i in range(num_features):
        if i != fixed_feature_index:  # Skip the fixed feature

            # Calculate the partial dependence
            grid, pdp = partial_dependence(model, train_x_np, i, fixed_feature_index=fixed_feature_index, fixed_value=fixed_value_norm)

            # Denormalize the grid and pdp values
            # Convert tensor to numpy array
            input


            grid = grid * np.array(input_normalization[1][i]) + np.array(input_normalization[0][i])
            pdp = pdp * np.array(target_normalization[1]) + np.array(target_normalization[0])

            # Plot the partial dependence
            ax = axes[i // 2, i % 2]
            ax.plot(grid, pdp)

            # ax.set_ylim([0, 300])
            # extract target unit and check for lower and upper case
            # if (target[0].lower() + target[1:]) in feature_units:
            #     ax.set_ylabel(f'{target} ({feature_units[target[0].lower() + target[1:]]})')
            # elif (target[0].upper() + target[1:]) in feature_units:
            #     ax.set_ylabel(f'{target} ({feature_units[target[0].upper() + target[1:]]})')
            # else:
            #     ax.set_ylabel(f'{target} (-)')

            # Set the axes labels
            ax.set_ylabel(f'{target}')
            ax.set_xlabel(f'{feature_names[i]}')

            ax.grid(True, zorder=1)
        else:
            # Write the fixed feature value in the subplot in bold
            ax = axes[i // 2, i % 2]
            ax.text(0.5, 0.5, f'{fixed_feature} fixed at {fixed_value}', horizontalalignment='center', verticalalignment='center', transform=ax.transAxes, fontsize=12, fontweight='bold')


    # Remove empty subplot (if any)
    if len(axes.flatten()) > num_features:
        fig.delaxes(axes.flatten()[-1])

    # Unify the y-axis limits to min and max values of the subplots (excluding the fixed feature subplot!)
    # y_min = np.floor((np.min([ax.get_ylim()[0] for ax in axes.flatten() if ax.get_ylim()[0] != 0]) * 0.9) * 10) / 10
    # y_max = np.ceil((np.min([ax.get_ylim()[1] for ax in axes.flatten() if ax.get_ylim()[1] != 1]) * 1.1) * 10) / 10
    y_min = 0.4
    y_max = 0.7
    for ax in axes.flatten():
        ax.set_ylim([y_min, y_max])

    # Finalize the layout
    plt.tight_layout()

    # Draw the canvas
    fig.canvas.draw()

    # Save the figure with title according to the fixed feature value to the partial dependence plots folder
    if fixed_feature is not None:
        plt.savefig(f'partial_dependence_plots/partial_dependence_plot_{fixed_feature}_{fixed_value}.png', bbox_inches='tight')    
    else:
        plt.savefig(f'partial_dependence_plots/partial_dependence_plot.png', bbox_inches='tight')

    # Close the figure
    plt.close()

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
            plot_model_performance(model, likelihood, test_input_tensor, test_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=True) if plot else None
            plot_model_performance(model, likelihood, train_input_tensor, train_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=False) if plot else None

            # Compute the test loss
            test_loss = eval_model_performance(model, likelihood, mll, test_input_tensor, test_target_tensor)
            print(f'Iteration {i}/{training_iterations} - Training Loss: {loss.item()} - Test Loss: {test_loss.item()}')
            loss_list.append(loss.item())
            test_loss_list.append(test_loss.item())
            iterations.append(i)

        loss.backward()
        optimizer.step() # the actual update step!

    # Print and save the final loss values
    i = i + 1
    if i % _params_logging.log_interval == 0:

        plot_model_performance(model, likelihood, test_input_tensor, test_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=True) if plot else None
        plot_model_performance(model, likelihood, train_input_tensor, train_target_tensor, i, target=target, target_normalization=(target_data_mean, target_data_std), test=False) if plot else None

        test_loss = eval_model_performance(model, likelihood, mll, test_input_tensor, test_target_tensor)
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
        create_video_from_snapshots(test=True)
        create_video_from_snapshots(test=False)

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
