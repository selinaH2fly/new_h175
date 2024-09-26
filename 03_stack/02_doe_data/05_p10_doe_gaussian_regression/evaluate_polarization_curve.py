import os

from file_handling import load_gpr_model

# Load the saved model
gpr_model_cell_voltage = load_gpr_model(os.path.join(os.getcwd(), "1_experiment_gpr_doe_model_high_amp", "gpr_model_cell_voltage.pth"))

# Specify the input data
feature_names = gpr_model_cell_voltage.feature_names

# Create a dictionary with the input data
input_data_dict = {
    feature_names[0]: 450,      # current_A
    feature_names[1]: 60,       # cathode_rh_in_perc
    feature_names[2]: 1.5,      # stoich_cathode
    feature_names[3]: 2.5,      # pressure_cathode_in_bara
    feature_names[4]: 75,       # temp_coolant_inlet_degC
    feature_names[5]: 85        # temp_coolant_outlet_degC
    }
