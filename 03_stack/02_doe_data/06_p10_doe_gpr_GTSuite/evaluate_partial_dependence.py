# Import libraries
import csv
import matplotlib.pyplot as plt
import numpy as np

# Import custom functions
from file_handling import load_gpr_model

# Define plot settings
secondary_y_axis = False
relative_deviation = True

# Define the fixed feature, the fixed value, and the target
num_features = 6
fixed_feature = 'current_A'
fixed_feature_index = 0
fixed_value = 700
target = 'Cell Voltage (V)'

# Load the grid and pdp values from the .csv files
def load_pdp_data(file_path):
    with open(file_path, 'r') as file:
        reader = csv.reader(file)
        grid, pdp = zip(*[(float(row[0]), float(row[1])) for row in reader])
    return np.array(grid), np.array(pdp)

# Create subplots with 2 columns
fig, axes = plt.subplots(int(np.ceil(num_features / 2)), 2, figsize=(12, 12))

# Adjust the layout
# fig.subplots_adjust(hspace=4)

# Create figure title
fig.suptitle('GPR DoE-Data Models - Partial Dependence Plots', y=1.002)

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

        ax = axes[i // 2, i % 2]

        if relative_deviation:
            # Calculate the mean value of the high-amp pdp values
            mean_pdp_high_amp = np.mean(pdp_high_amp)

            # Calculate the relative deviation of the high-temp pdp values
            pdp_high_amp_relative = 100 / mean_pdp_high_amp * pdp_high_amp - 100
            pdp_high_temp_relatve = 100 / mean_pdp_high_amp * pdp_high_temp - 100

            # Plot the partial dependence in terms of relative deviation
            high_amp_line, = ax.plot(grid_high_amp, pdp_high_amp_relative, color='cornflowerblue', label='High-Current DoE-Data')
            high_temp_line, = ax.plot(grid_high_temp, pdp_high_temp_relatve, color='orange', label='High-Temperature DoE-Data')

            # Set x-axis label
            ax.set_ylabel(r'Relative Cell Voltage Deviation$^1$ (%)')

        else:
        
            # Plot the partial dependence
            high_amp_line, = ax.plot(grid_high_amp, pdp_high_amp, color='cornflowerblue', label='High-Current DoE-Data')
            high_temp_line, = ax.plot(grid_high_temp, pdp_high_temp, color='orange', label='High-Temperature DoE-Data')

            # Set x-axis label
            ax.set_ylabel(f'{target}')

        if secondary_y_axis:
            
            # Clip the grid to the overlapping range
            grid_min = np.max([np.min(grid_high_amp), np.min(grid_high_temp)])
            grid_max = np.min([np.max(grid_high_amp), np.max(grid_high_temp)])
            grid_clipped = np.linspace(grid_min, grid_max, 100)

            # Map pdp values to clipped grid
            pdp_high_temp_clipped = np.interp(grid_clipped, grid_high_temp, pdp_high_temp)
            pdp_high_amp_clipped = np.interp(grid_clipped, grid_high_amp, pdp_high_amp)

            # Plot the relative improvement on a secondary y-axis
            ax2 = ax.twinx()
            relative_deviation_perc = 100 / pdp_high_amp_clipped * pdp_high_temp_clipped - 100
            rel_dev_line, = ax2.plot(grid_clipped, relative_deviation_perc, color='red', linestyle='--', label='Relative Deviation (%)')

            ax2.set_ylim([-10, 10])
            ax2.set_ylabel('Relative Deviation (%)')

            # Combine the handles and labels from both axes
            lines = [high_amp_line, high_temp_line, rel_dev_line]

        # Create legend
        lines = [high_amp_line, high_temp_line]
        labels = [line.get_label() for line in lines]
        ax.legend(lines, labels, loc='upper left')

        # Set plot properties
        ax.set_xlabel(f'{feature}')
        ax.grid(True, zorder=1)

    else:
        # Write the fixed feature value in the subplot in bold
        ax = axes[i // 2, i % 2]
        ax.text(0.5, 0.5, f'{fixed_feature} fixed at {fixed_value} A', horizontalalignment='center', verticalalignment='center', transform=ax.transAxes, fontsize=12, fontweight='bold')

        # No ticks and labels for the fixed feature subplot
        ax.set_xticks([])
        ax.set_yticks([])
        ax.set_xticklabels([])
        ax.set_yticklabels([])

# Include footnote in case of relative deviation
if relative_deviation:
    fig.text(0.52, -0.02, r'$^1$Relative deviation with respect to the mean value of the high-current DoE-data', ha='left')

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
fig.subplots_adjust(hspace=0.3, wspace=0.25)

# Draw the canvas
# fig.canvas.draw()

# Save the figure with title according to the fixed feature value
plt.savefig(f'pdp_plot_{fixed_feature}_{fixed_value}.png', bbox_inches='tight')    

# Close the figure
plt.close()

