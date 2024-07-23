import pandas as pd
import glob
import os

def process_files(path='', datatype="dict"):
    datatype = str(datatype)
    all_files = glob.glob(os.path.join(path, "*.csv"))

    # Ensure only three files are read
    if len(all_files) != 3:
        raise ValueError("Expected exactly 3 CSV files in the directory.")

    li = {}
    units = {}

    for filename in all_files:
        name_short = filename.removeprefix("MC_1stdraft_").removesuffix(".csv")
        df = pd.read_csv(filename, index_col=None, header=0)
        # Extract units (first row)
        unit_row = df.iloc[0]
        units[name_short] = unit_row.to_dict()
        # Remove the units row from the dataframe
        df = df[1:].reset_index(drop=True)
        li[name_short] = df

    # Remove NaN columns (not converged cases) from all 3 data sets, use the steady state column of Outputs
    idx = li.get("Outputs")["Steady_State"].notnull()
    for key in li.keys():
        li[key] = li[key][idx].reset_index(drop=True)

    # Redefine li to extract each DataFrame into a new dictionary with column names as keys
    data_dicts = {}
    for key, df in li.items():
        if key == 'Inputs':
            df = df.drop(columns=['Case', 'Case_Number'])
        elif key == 'Outputs':
            df = df.drop(columns=['Case', 'Steady_State'])
        elif key == 'Parameters':
            df = df.drop(columns=['Case', 'DOE Experiment Number'])
        data_dicts[key] = {col: df[col].tolist() for col in df.columns}

    # Construct the final output dictionaries
    input_data = data_dicts.get('Inputs')
    input_units = units.get('Inputs')
    output_data = data_dicts.get('Outputs')
    output_units = units.get('Outputs')
    parameters_data = data_dicts.get('Parameters')
    parameters_units = units.get('Parameters')

    return input_data, input_units, output_data, output_units, parameters_data, parameters_units

# Example usage:
# path = "path_to_your_csv_files"
# datatype = "dict"
input_data, input_units, output_data, output_units, parameters_data, parameters_units = process_files()
# print(input_data, input_units, output_data, output_units, parameters_data, parameters_units)
