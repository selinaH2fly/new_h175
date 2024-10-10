import os
import torch
import gpytorch
import csv
import matplotlib.pyplot as plt
import parameters
from file_handling import load_gpr_model
import matplotlib.cm as cm
import matplotlib.colors as mcolors
import numpy as np

# Instantiate the parameters
_params_pyhsics = parameters.Physical_Parameters()

folder_paths = [os.path.join(os.getcwd(), "1_experiment_gpr_doe_model_high_amp"), os.path.join(os.getcwd(), "1_experiment_gpr_doe_model_high_temp")]
labels = ["Powercell Default MEA", "Powercell HT MEA"]
cmapcolors = ['Blues', 'Reds']

# Specify operating parameters
stoich = 1.8
current_A = 750
p_bara = 2.5

# Create the figure and axis objects
fig, ax = plt.subplots(figsize=(10, 6))

for experiment_folder, label, cmapcolor in zip(folder_paths , labels, cmapcolors):
   
    # Go to folder high temp or high amp
    os.chdir(experiment_folder)

    # Load the saved model
    gpr_model_cell_voltage = load_gpr_model("gpr_model_cell_voltage.pth")

    # Specify the input data
    feature_names = gpr_model_cell_voltage.feature_names

    # Define colormap and normalization
    cmap = plt.get_cmap(cmapcolor)
    norm = mcolors.Normalize(vmin=20, vmax=120)


    for t_coolant_inlet in [75, 120]:
        
        # Create a list of dictionaries with the input data
        input_data_dict_list = []
        for RH in [0, 10, 20, 30, 40, 50, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 130, 140]:
            input_data_dict_list.append({
                feature_names[0]: current_A,                                                  # current_A
                feature_names[1]: RH,                                                   # cathode_rh_in_perc
                feature_names[2]: stoich,                                                  # stoich_cathode
                feature_names[3]: p_bara,                                               # pressure_cathode_in_bara
                feature_names[4]: t_coolant_inlet,                                                   # temp_coolant_inlet_degC
                feature_names[5]: t_coolant_inlet + 10,                                                  # temp_coolant_outlet_degC
            })

        # Convert the input data to a tensor
        input_data_tensor = torch.tensor([[input_data_dict[feature_name] for feature_name in feature_names] for input_data_dict in input_data_dict_list])

        # Normalize the input data
        x_tensor = (input_data_tensor - gpr_model_cell_voltage.input_data_mean) / gpr_model_cell_voltage.input_data_std

        # Predict the cell voltage
        gpr_model_cell_voltage.model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            cell_voltage_prediction_tensor = gpr_model_cell_voltage.model(x_tensor).mean

        # Denormalize the cell voltage prediction
        cell_voltage_tensor_V = cell_voltage_prediction_tensor * gpr_model_cell_voltage.target_data_std + gpr_model_cell_voltage.target_data_mean

        # Create plot
        RH_values = [input_data_dict[feature_names[1]] for input_data_dict in input_data_dict_list]
        cell_voltage_values = [cell_voltage_V.item() for cell_voltage_V in cell_voltage_tensor_V]
        
        # Plot the predicted voltage
        t_color = norm(t_coolant_inlet)
        line, = ax.plot(RH_values, cell_voltage_values, color=cmap(t_color), alpha = 1, 
                        label = f'{label}, T = {t_coolant_inlet} C')

# Add titles and labels
ax.set_xlabel('Relative Humidity (RH) [%]')
ax.set_ylabel('Cell Voltage [V]')
ax.set_title(f'I = {current_A} A, p = {np.round(p_bara, 2)} bara, λ = {stoich}')


# Create a ScalarMappable for the colorbar
sm = cm.ScalarMappable(cmap=cmap, norm=norm)
sm.set_array([])  # Only needed for older versions of matplotlib

# Add the colorbar to the figure
# cbar = fig.colorbar(sm, ax=ax, orientation='vertical', pad=0.02)
# cbar.set_label(r'Temperature [$\degree$C]', fontsize=12)

plt.legend(frameon=False)

# Adjust layout to prevent clipping of the colorbar text
plt.tight_layout()

# Display the plot
plt.show()