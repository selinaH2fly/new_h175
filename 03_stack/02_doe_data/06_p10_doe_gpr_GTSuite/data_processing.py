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

# Load the high temperature DoE data
def load_high_temp_doe_data():
    # Get path to data file
    my_dir = os.getcwd()
    filename = "H2FLY HT DOE - Averaged test points - 20240912_CC.xlsx"
    path = os.path.join(Path(my_dir).parents[1], '01_p10_doe_basic_files', '03_TV501006_2_HT', '1_Averaged test point data', filename)

    # Load data file
    xls = pd.ExcelFile(path)

    # Get the name of the first sheet
    first_sheet_name = xls.sheet_names[0]

    # Load the second sheet into a DataFrame, skipping the first row
    df = pd.read_excel(path, sheet_name=first_sheet_name)

    # Extract the units from the scnd row and set the identifiers in the thrd row as the DataFrame column names
    units = df.iloc[0]
    df.columns = df.iloc[1]
    df = df.drop([0, 1]).reset_index(drop=True)
    df = df.drop(0)

    # Clear failed runs and duplicates from the DataFrame
    df = df[df['Point successfully run'] == 1]
    df = df.loc[:, ~df.columns.duplicated()]

    # Drop columns missing values
    df = df.dropna(axis=1, how='all')

    return df, units


# Load DoE data simulated in GT-Suite
def load_BBM_PowerCell_DoE():
    # Get path to data file
    my_dir = os.getcwd()
    filename = "DoE_data_BBM_PowerCell_GTSuite.csv"
    path = os.path.join(Path(my_dir).parents[1], '06_p10_doe_gpr_GTSuite', 'data_input_training', filename)

    # Load data file
    csv = pd.read_csv(path)
    csv=csv*1
    
    # Get the name of the first sheet
    first_sheet_name = xls.sheet_names[0]

    # Load the second sheet into a DataFrame, skipping the first row
    df = pd.read_excel(path, sheet_name=first_sheet_name)

    # Extract the units from the scnd row and set the identifiers in the thrd row as the DataFrame column names
    units = df.iloc[0]
    df.columns = df.iloc[1]
    df = df.drop([0, 1]).reset_index(drop=True)
    df = df.drop(0)

    # Clear failed runs and duplicates from the DataFrame
    df = df[df['Point successfully run'] == 1]
    df = df.loc[:, ~df.columns.duplicated()]

    # Drop columns missing values
    df = df.dropna(axis=1, how='all')

    return df, units




# Preprocess the data
def preprocess_data(df, target='eta_lhv', cutoff_current=0, params_pyhsics=None, data='high_amp'):

    # Drop data points from the dataframe with current values below the cutoff value
    df = df[df['current'] >= cutoff_current]

    # Assign target data and input data
    target_data, input_data_dict, feature_names = assign_input_and_target_data(df, target, params_pyhsics, data)

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

# Assign input data dict
def assign_input_and_target_data(dataframe, target, params_pyhsics, data):

    # Convert the dataframes to dictionaries
    df_dict = dataframe.to_dict('list')

    # Try to find the target variable in the df_dict
    if target in df_dict:
        target_data = df_dict[target]
        input_data_dict = default_input_data_dict(df_dict)
    else:
        # Check for custom targets
        if target == 'eta_lhv' and data == 'high_amp':
            # TODO Make agnostic to the stack size
            target_data = [voltage / 275 / params_pyhsics.hydrogen_lhv_voltage_equivalent for voltage in df_dict['voltage']]
            input_data_dict = voltage_input_data_dict(df_dict, params_pyhsics)
        elif target == 'eta_hhv' and data == 'high_amp':
            # TODO Make agnostic to the stack size
            target_data = [voltage / 275 / params_pyhsics.hydrogen_hhv_voltage_equivalent for voltage in df_dict['voltage']]
            input_data_dict = voltage_input_data_dict(df_dict, params_pyhsics)
        elif target == 'cell_voltage' and data == 'high_amp':
            target_data = df_dict['metis_CVM_Cell_Voltage_Mean']
            input_data_dict = voltage_input_data_dict(df_dict, params_pyhsics)
        elif target == 'cell_voltage' and data == 'high_temp':
            target_data = df_dict['cell_voltage_mean']
            input_data_dict = voltage_input_data_dict(df_dict, params_pyhsics)
        elif target == 'cathode_pressure_drop':
            target_data = [pressure_in - pressure_out for pressure_in, pressure_out in zip(df_dict['pressure_cathode_inlet'], df_dict['pressure_cathode_outlet'])]
            input_data_dict = cathode_dp_input_data_dict(df_dict, params_pyhsics)
        elif target == 'anode_pressure_drop':
            target_data = [pressure_in - pressure_out for pressure_in, pressure_out in zip(df_dict['pressure_anode_inlet'], df_dict['pressure_anode_outlet'])]
            input_data_dict = anode_dp_input_data_dict(df_dict, params_pyhsics)

        else:
            raise ValueError(f'Target variable {target} not found in the dataframe!')

    # Extract feature names and write them to a file
    feature_names = list(input_data_dict.keys())
    with open('feature_names.txt', 'w') as file:
        for feature in feature_names:
            file.write(f'{feature}\n')

    return target_data, input_data_dict, feature_names

# Default input data dict
def default_input_data_dict(df_dict):

    input_data_dict = {}

    # Classic Powercell features
    input_data_dict['current_A'] = df_dict['current']
    input_data_dict['stoich_anode'] = df_dict['anode_stoich']
    input_data_dict['stoich_cathode'] = df_dict['cathode_stoich']
    input_data_dict['pressure_anode_in_barg'] = df_dict['pressure_anode_inlet']
    input_data_dict['pressure_cathode_in_barg'] = df_dict['pressure_cathode_inlet']
    input_data_dict['temp_anode_inlet_degC'] = df_dict['temp_anode_inlet']
    input_data_dict['temp_cathode_inlet_degC'] = df_dict['temp_cathode_inlet']
    input_data_dict['dewpoint_anode_degC'] = df_dict['temp_anode_dewpoint_gas']
    input_data_dict['dewpoint_cathode_degC'] = df_dict['temp_cathode_dewpoint_gas']
    input_data_dict['temp_coolant_inlet_degC'] = df_dict['temp_coolant_inlet']
    input_data_dict['flow_coolant_lpm'] = df_dict['flow_coolant']

    return input_data_dict

# Voltage modeling input data dict
def voltage_input_data_dict(df_dict, params_pyhsics):

    input_data_dict = {}

    # "Best" features from the feature selection process for the voltage prediction (in consultation with Steffen P.)
    input_data_dict['current_A'] = df_dict['current']
    input_data_dict['cathode_rh_in_perc'] = [calculate_relative_humidity(dewpoint, temp) for dewpoint, temp in zip(df_dict['temp_cathode_dewpoint_gas'], df_dict['temp_cathode_inlet'])]
    input_data_dict['stoich_cathode'] = df_dict['cathode_stoich']
    input_data_dict['pressure_cathode_in_bara'] = [pressure_barg + params_pyhsics.sea_level_ambient_pressure_bar for pressure_barg in df_dict['pressure_cathode_inlet']]
    input_data_dict['temp_coolant_inlet_degC'] = df_dict['temp_coolant_inlet']
    input_data_dict['temp_coolant_outlet_degC'] = df_dict['temp_coolant_outlet']
    input_data_dict['stoich_anode'] = df_dict['anode_stoich']
    input_data_dict['pressure_anode_in_bara'] = [pressure_barg + params_pyhsics.sea_level_ambient_pressure_bar for pressure_barg in df_dict['pressure_anode_inlet']]

    '''TODO: Include anode stoichiometry and anode inlet pressure in a future version when we want to optimize for those variables.
    As a quick fix as of Aug.08, 2024, we assume constant values for these variables. If we want to optimize for them, we need minimize the H2 flow fed to the system (instead of minimizing the H2 flow consumed by the system)!
    '''

    return input_data_dict

# Cathode pressure drop modeling input data dict
def cathode_dp_input_data_dict(df_dict, params_physics):

    input_data_dict = {}

    # Variables believed to affect flow velocity and, therefore, pressure drop in the cathode
    input_data_dict['current_A'] = df_dict['current']
    # input_data_dict['cathode_rh_in_perc'] = [calculate_relative_humidity(dewpoint, temp) for dewpoint, temp in zip(df_dict['temp_cathode_dewpoint_gas'], df_dict['temp_cathode_inlet'])]
    input_data_dict['stoich_cathode'] = df_dict['cathode_stoich']
    input_data_dict['pressure_cathode_in_bara'] = [pressure_barg + params_physics.sea_level_ambient_pressure_bar for pressure_barg in df_dict['pressure_cathode_inlet']]
    input_data_dict['temp_coolant_inlet_degC'] = df_dict['temp_coolant_inlet'] # assumption: gas temperature \approx "stack" temperature, right after gas enters stack (cf. Powercell assumption for dewpoint computations)

    return input_data_dict

# Helper function for calculating the relative humidity TODO: Check this function!
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

def anode_dp_input_data_dict(df_dict, params_physics):

    input_data_dict = {}

    # Variables believed to affect flow velocity and, therefore, pressure drop in the anode
    input_data_dict['current_A'] = df_dict['current']
    input_data_dict['stoich_anode'] = df_dict['anode_stoich']
    input_data_dict['pressure_anode_in_bara'] = [pressure_barg + params_physics.sea_level_ambient_pressure_bar for pressure_barg in df_dict['pressure_anode_inlet']]
    input_data_dict['temp_coolant_inlet_degC'] = df_dict['temp_coolant_inlet'] # assumption: gas temperature \approx "stack" temperature, right after gas enters stack (cf. Powercell assumption for dewpoint computations)
    input_data_dict['H2_concentration'] = df_dict['Anode_H2_Concentration'] 
    return input_data_dict
