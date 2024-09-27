import os
import torch
import gpytorch

import parameters
from file_handling import load_gpr_model

# Instantiate the parameters
_params_pyhsics = parameters.Physical_Parameters()

# Load the saved model
gpr_model_cell_voltage = load_gpr_model(os.path.join(os.getcwd(), "1_experiment_gpr_doe_model_high_amp", "gpr_model_cell_voltage.pth"))

# Specify the input data
feature_names = gpr_model_cell_voltage.feature_names

# Create a dictionary with the input data
input_data_dict = {
    # feature_names[0]: [400, 450, 500, 550, 600, 650, 700, 750],             # current_A
    feature_names[0]: 400,                                                  # current_A
    feature_names[1]: 50,                                                   # cathode_rh_in_perc
    feature_names[2]: 1.6,                                                  # stoich_cathode
    feature_names[3]: 1.5 + _params_pyhsics.sea_level_ambient_pressure_bar, # pressure_cathode_in_bara
    feature_names[4]: 95,                                                   # temp_coolant_inlet_degC
    feature_names[5]: 105,                                                  # temp_coolant_outlet_degC
    }

# Convert the dictionary to a tensor
input_data_tensor = torch.tensor([[input_data_dict[feature] for feature in feature_names]], dtype=torch.float)

# Normalize the input data
x_tensor = (input_data_tensor - gpr_model_cell_voltage.input_data_mean) / gpr_model_cell_voltage.input_data_std

# Predict the cell voltage
gpr_model_cell_voltage.model.eval()
with torch.no_grad(), gpytorch.settings.fast_pred_var():
    cell_voltage_prediction = gpr_model_cell_voltage.model(x_tensor).mean.item()

# Denormalize the cell voltage prediction
cell_voltage_V = cell_voltage_prediction * gpr_model_cell_voltage.target_data_std + gpr_model_cell_voltage.target_data_mean

# Print the cell voltage prediction
print(f"The predicted cell voltage is: {cell_voltage_V:.3f} V")
