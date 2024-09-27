import os
import torch
import gpytorch
import csv

import parameters
from file_handling import load_gpr_model

# Instantiate the parameters
_params_pyhsics = parameters.Physical_Parameters()

# Browse to experiment folder
experiment_folder = os.path.join(os.getcwd(), "1_experiment_gpr_doe_model_high_temp")
os.chdir(experiment_folder)

# Load the saved model
gpr_model_cell_voltage = load_gpr_model("gpr_model_cell_voltage.pth")

# Specify the input data
feature_names = gpr_model_cell_voltage.feature_names

# Create a list of dictionaries with the input data
input_data_dict_list = []
for current in [400, 450, 500, 550, 600, 650, 700, 750]:
    input_data_dict_list.append({
        feature_names[0]: current,                                              # current_A
        feature_names[1]: 50,                                                   # cathode_rh_in_perc
        feature_names[2]: 1.6,                                                  # stoich_cathode
        feature_names[3]: 1.9 + _params_pyhsics.sea_level_ambient_pressure_bar, # pressure_cathode_in_bara
        feature_names[4]: 95,                                                   # temp_coolant_inlet_degC
        feature_names[5]: 105,                                                  # temp_coolant_outlet_degC
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

# Print the cell voltage predictions
for cell_voltage_V, input_data_dict in zip(cell_voltage_tensor_V, input_data_dict_list):
    print(f"Current: {input_data_dict[feature_names[0]]} A, Cell voltage: {cell_voltage_V.item():.4f} V")

# Save the cell voltage predictions alongside the corresponding input data to a .csv file
with open("cell_voltage_predictions.csv", "w", newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["current_A", "cathode_rh_in_perc", "stoich_cathode", "pressure_cathode_in_bara", "temp_coolant_inlet_degC", "temp_coolant_outlet_degC", "cell_voltage_V"])
    for cell_voltage_V, input_data_dict in zip(cell_voltage_tensor_V, input_data_dict_list):
        writer.writerow([input_data_dict[feature_name] for feature_name in feature_names] + [f"{cell_voltage_V.item():.4f}"])
    file.close()


