import os
import torch
import gpytorch
import csv

import parameters
from file_handling import load_gpr_model

# Instantiate the parameters
_params_pyhsics = parameters.Physical_Parameters()

# Browse to experiment folder
experiment_folder = os.path.join(os.getcwd(), "1_experiment_gpr_doe_model_high_amp")
os.chdir(experiment_folder)

# Load the saved model
gpr_model_cell_voltage = load_gpr_model("gpr_model_cell_voltage.pth")

# Specify the input data
feature_names = gpr_model_cell_voltage.feature_names

# Create a list of dictionaries with the input data
input_data_dict_list = []
current_A_vector = [50, 100, 200, 300, 400, 500, 600]
pressure_cathode_in_bara_vector = [1.1 + 0.1 * i for i in range(20)]

for current_A in current_A_vector:
    for pressure_cathode_in_bara in pressure_cathode_in_bara_vector:

        if current_A == 50:
            stoich_cathode = 4.0
            cathode_rh_in_perc = 60
            temp_coolant_inlet_degC = 65
            temp_coolant_outlet_degC = 67
        elif current_A == 100:
            stoich_cathode = 2.5
            cathode_rh_in_perc = 55
            temp_coolant_inlet_degC = 65
            temp_coolant_outlet_degC = 67
        elif current_A == 200:
            stoich_cathode = 1.8
            cathode_rh_in_perc = 55
            temp_coolant_inlet_degC = 65
            temp_coolant_outlet_degC = 70
        elif current_A == 300:
            stoich_cathode = 1.8
            cathode_rh_in_perc = 52
            temp_coolant_inlet_degC = 67
            temp_coolant_outlet_degC = 72
        elif current_A == 400:
            stoich_cathode = 1.8
            cathode_rh_in_perc = 50
            temp_coolant_inlet_degC = 67
            temp_coolant_outlet_degC = 75
        elif current_A == 500:
            stoich_cathode = 1.6
            cathode_rh_in_perc = 46
            temp_coolant_inlet_degC = 70
            temp_coolant_outlet_degC = 78
        elif current_A == 600:
            stoich_cathode = 1.6
            cathode_rh_in_perc = 46
            temp_coolant_inlet_degC = 70
            temp_coolant_outlet_degC = 80
        else:
            raise ValueError("Invalid current value.")

        input_data_dict_list.append({
            feature_names[0]: current_A,
            feature_names[1]: cathode_rh_in_perc,
            feature_names[2]: stoich_cathode,
            feature_names[3]: pressure_cathode_in_bara,
            feature_names[4]: temp_coolant_inlet_degC,
            feature_names[5]: temp_coolant_outlet_degC,
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
evaluation_ID = 1
file_name = "{}_cell_voltage_predictions.csv".format(evaluation_ID)

while os.path.exists(file_name):
    evaluation_ID += 1
    file_name = "{}_".format(evaluation_ID) + file_name.split('_', 1)[1]

with open(file_name, "w", newline='') as file:
    writer = csv.writer(file)
    writer.writerow([feature_names, "cell_voltage_V"])
    for cell_voltage_V, input_data_dict in zip(cell_voltage_tensor_V, input_data_dict_list):
        writer.writerow([input_data_dict[feature_name] for feature_name in feature_names] + [f"{cell_voltage_V.item():.4f}"])
    file.close()


