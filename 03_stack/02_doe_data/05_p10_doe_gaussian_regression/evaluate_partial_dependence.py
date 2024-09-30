import os
import torch
import gpytorch
import csv
import matplotlib.pyplot as plt
import numpy as np

import parameters
from file_handling import load_gpr_model

# Instantiate the parameters
_params_pyhsics = parameters.Physical_Parameters()

# Load the grid and pdp values from the .csv files
def load_pdp_data(file_path):
    with open(file_path, 'r') as file:
        reader = csv.reader(file)
        grid, pdp = zip(*[(float(row[0]), float(row[1])) for row in reader])
    return np.array(grid), np.array(pdp)

# Number of features
num_features = 6
fixed_feature = 'current_A'
fixed_feature_index = 0
fixed_value = 700
target = 'Cell Voltage (V)'

# Create subplots with 2 columns
fig, axes = plt.subplots(int(np.ceil(num_features / 2)), 2, figsize=(12, 12))

# Adjust the layout
fig.subplots_adjust(hspace=2)

# Create figure title
fig.suptitle('GPR DoE-Data Models - Partial Dependence Plots')

# Loop through each feature and plot its partial dependence TODO: Make agnostic to the number of features
for i in range(num_features):

    if i == 0:
        feature = 'current_A'
    elif i == 1:
        feature = 'cathode_rh_in_perc'
    elif i == 2:
        feature = 'stoich_cathode'
    elif i == 3:
        feature = 'pressure_cathode_in_bara'
    elif i == 4:
        feature = 'temp_coolant_inlet_degC'
    elif i == 5:
        feature = 'temp_coolant_outlet_degC'
    else:
        raise ValueError("Invalid feature index.")
    

    if i != fixed_feature_index:  # Skip the fixed feature

        # Load the grid and pdp values
        grid_high_temp, pdp_high_temp = load_pdp_data(f'2_experiment_gpr_doe_model_high_temp/partial_dependence_analysis/partial_dependence_data/pdp_data_{feature}_{fixed_feature}_{fixed_value}.csv')
        grid_high_amp, pdp_high_amp = load_pdp_data(f'2_experiment_gpr_doe_model_high_amp/partial_dependence_analysis/partial_dependence_data/pdp_data_{feature}_{fixed_feature}_{fixed_value}.csv')

        # Plot the partial dependence
        ax = axes[i // 2, i % 2]
        high_amp_line, = ax.plot(grid_high_amp, pdp_high_amp, color='cornflowerblue', label='High Current DoE-Data')
        high_temp_line, = ax.plot(grid_high_temp, pdp_high_temp, color='orange', label='High Temperature DoE-Data')

        # clip grid to range where both pdp values are available
        grid_min = np.max([np.min(grid_high_amp), np.min(grid_high_temp)])
        grid_max = np.min([np.max(grid_high_amp), np.max(grid_high_temp)])
        grid_clipped = np.linspace(grid_min, grid_max, 100)

        # map pdp values to clipped grid
        pdp_high_temp_clipped = np.interp(grid_clipped, grid_high_temp, pdp_high_temp)
        pdp_high_amp_clipped = np.interp(grid_clipped, grid_high_amp, pdp_high_amp)

        # Plot the relative improvement on a secondary y-axis
        ax2 = ax.twinx()
        relative_deviation_perc = 100 / pdp_high_amp_clipped * pdp_high_temp_clipped - 100
        rel_dev_line, = ax2.plot(grid_clipped, relative_deviation_perc, color='red', linestyle='--', label='Relative Deviation (%)')

        ax2.set_ylim([-10, 10])

        # Combine the handles and labels from both axes
        lines = [high_amp_line, high_temp_line, rel_dev_line]
        labels = [line.get_label() for line in lines]

        # Create a single legend for both axes
        ax.legend(lines, labels, loc='upper left')

        # Set the axes labels
        ax.set_ylabel(f'{target}')
        ax.set_xlabel(f'{feature}')
        ax2.set_ylabel('Relative Deviation (%)')

        ax.grid(True, zorder=1)

    else:
        # Write the fixed feature value in the subplot in bold
        ax = axes[i // 2, i % 2]
        ax.text(0.5, 0.5, f'{fixed_feature} fixed at {fixed_value}', horizontalalignment='center', verticalalignment='center', transform=ax.transAxes, fontsize=12, fontweight='bold')


# Remove empty subplot (if any)
if len(axes.flatten()) > num_features:
    fig.delaxes(axes.flatten()[-1])

# Unify the y-axis limits to min and max values of the subplots (excluding the fixed feature subplot!)
y_min = np.floor((np.min([ax.get_ylim()[0] for ax in axes.flatten() if ax.get_ylim()[0] != 0]) * 0.9) * 10) / 10
y_max = np.ceil((np.max([ax.get_ylim()[1] for ax in axes.flatten() if ax.get_ylim()[1] != 1]) * 1.1) * 10) / 10
# y_min = 0.4
# y_max = 0.7
for ax in axes.flatten():
    ax.set_ylim([y_min, y_max])

# Finalize the layout
plt.tight_layout()

# Draw the canvas
fig.canvas.draw()

# Save the figure with title according to the fixed feature value
plt.savefig(f'pdp_plot_{fixed_feature}_{fixed_value}.png', bbox_inches='tight')    

# Close the figure
plt.close()

