"""This file contains funtions to load and plot Powercell DoE raw data."""

import sys
#import mariadb
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import glob
import os

# High-level function for loading the data
def load_doe_data():
    #path = os.path.dirname()
    # path = os.getcwd()
    # #filename = os.path.join(dirname, 'relative/path/to/file/you/want')
    # datatype = "dict"
    # all_files = glob.glob(os.path.join(path, r"/data/*.csv"))
    # print(all_files)
    # # Ensure only three files are read
    # if len(all_files) != 3:
    #     raise ValueError(f"Expected exactly 3 CSV files in the directory, got {len(all_files)}")
    all_files = [r"C:\Users\wenzel.gassner\Documents\h175_model\03_stack\04_PC_BBM_NN\data\MC_1stdraft_Inputs.csv",
    r"C:\Users\wenzel.gassner\Documents\h175_model\03_stack\04_PC_BBM_NN\data\MC_1stdraft_Outputs.csv",
    r"C:\Users\wenzel.gassner\Documents\h175_model\03_stack\04_PC_BBM_NN\data\MC_1stdraft_Parameters.csv"]
    
    def convert_to_float(value):
        try:
            return float(value)
        except ValueError:
            return None
    
    li = {}
    units = {}

    for filename in all_files:
        name_short = filename.removeprefix(r"C:\Users\wenzel.gassner\Documents\h175_model\03_stack\04_PC_BBM_NN\data\MC_1stdraft_").removesuffix(".csv")
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
        #data_dicts[key] = {col: df[col].tolist() for col in df.columns}
        
        data_dicts[key] = {col: [convert_to_float(val) for val in df[col]] for col in df.columns}
    
    # Construct the final output dictionaries
    input_data = data_dicts.get('Inputs')
    input_units = units.get('Inputs')
    output_data = data_dicts.get('Outputs')
    output_units = units.get('Outputs')
    parameters_data = data_dicts.get('Parameters')
    parameters_units = units.get('Parameters')

    return (input_data, input_units, output_data, output_units, parameters_data, parameters_units)

# Assign the input and output data to the respective dictionaries
# def assign_input_output_dicts(keys, doe_data_dict, processed_doe_data_dict):
#     '''
#     This function assigns the input and output data to the respective dictionaries.
#     '''

#     # Create an empty data dictionary
#     new_dict = {}

#     # Look for the keys in the overall data dictionaries
#     for key in keys:
#         # Look for the key in the original data dictionary
#         if key in doe_data_dict:
#             new_dict[key] = doe_data_dict[key]
#         # Look for the key in the processed data dictionary
#         elif key in processed_doe_data_dict:
#             new_dict[key] = processed_doe_data_dict[key]
#         else:
#             print('Key ' + key + ' not found in the data dictionary!')

#     return new_dict

def plot_doe_data(model_in_dict, model_out_dict):
    
    # # Create scatter plots of the varied input parameters (cf. illustration provided by Powercell)
    # cols = 3
    # rows = int(np.ceil((len(model_in_dict)-1)/cols))
    # fig, axs = plt.subplots(rows, cols)
    # mgr = plt.get_current_fig_manager()
    # mgr.resize(1280, 720)
    # fig.suptitle('Variation of Input Parameters \n (cf. Illustration provided by Powercell)')
    # row, col = 0, 0
    # for key in model_in_dict:
    #     if key != 'Current':
    #         axs[row, col].grid(True, zorder=1)
    #         axs[row, col].scatter(model_in_dict['Current'], model_in_dict[key], marker='o', facecolor='darkred', edgecolor='black', zorder=2)
    #         axs[row, col].xaxis.set_label_text('current (A)')
    #         axs[row, col].yaxis.set_label_text(key)
    #         col += 1
    #         if col == cols:
    #             col = 0
    #             row += 1

    # for ax in axs.flat:
    #     if ax.get_xlabel() != 'current (A)':
    #         # Delete the axes
    #         fig.delaxes(ax)

    # plt.tight_layout()
    # plt.show(block=False)

    # # Create scatter plots of the output parameters (cf. illustration provided by Powercell)
    # cols = 3
    # rows = int(np.ceil((len(model_out_dict))/cols))
    # fig, axs = plt.subplots(rows, cols)
    # mgr = plt.get_current_fig_manager()
    # mgr.resize(1280, 720)
    # fig.suptitle('Variation of Output Parameters \n (cf. Illustration provided by Powercell)')
    # row, col = 0, 0
    # for key in model_out_dict:
    #         axs[row, col].grid(True, zorder=1)
    #         axs[row, col].scatter(model_in_dict['Current'], model_out_dict[key], marker='o', facecolor='darkred', edgecolor='black', zorder=2)
    #         axs[row, col].xaxis.set_label_text('current (A)')
    #         axs[row, col].yaxis.set_label_text(key)
    #         col += 1
    #         if col == cols:
    #             col = 0
    #             row += 1
    # plt.tight_layout()
    # plt.draw()

    return plt