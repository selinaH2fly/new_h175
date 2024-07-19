import os
from pathlib import Path
import pandas as pd
import torch

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
def preprocess_data(df, target='eta_lhv', cutoff_current=0, params_pyhsics=None):

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
    input_data_dict['pressure_cathode_in_bara'] = [pressure_barg + params_pyhsics.sea_level_ambient_pressure_bar for pressure_barg in df_dict['pressure_cathode_inlet']]
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
        elif target == 'cell_voltage':
            target_data = df_dict['metis_CVM_Cell_Voltage_Mean']
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