import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def load_high_amp_doe_data():
    # Get path to data file
    my_dir = r"F:\gauss"
    filename = "FC-P10-275C-H0C-SN0014 - H2Fly DOE averaged.xlsx"
    path = os.path.join(my_dir, filename)

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

def calculate_n_dot(nlpm_df):
    # Conversion constants
    liters_per_mole = 22.414  # Liters per mole at STP
    seconds_per_minute = 60
    
    # Convert NLPM to mol/s
    flow_rate_l_per_s = nlpm_df / seconds_per_minute
    flow_rate_mol_per_s = flow_rate_l_per_s / liters_per_mole
    
    return flow_rate_mol_per_s

def subdivide_data(data, column_name="pressure_cathode_inlet", n_groups=3):
    """
    Subdivides the data into N groups based on the specified column.

    Parameters:
    data (pd.DataFrame): The input data.
    column (str): The column name to base the subdivision on.
    n_groups (int): The number of groups to divide the data into.

    Returns:
    list: A list of DataFrames, each containing one of the subdivided groups.
    """
    # Ensure the column exists in the data
    if column_name not in data.columns:
        raise ValueError(f"Column '{column_name}' not found in the data.")
    
    # Sort data by the specified column
    data_sorted = data.sort_values(by=column_name)
        
    # Determine the size of each group
    group_size = len(data_sorted) // n_groups
    subdivided_data = []
    
    for i in range(n_groups):
        start_index = i * group_size
        # Ensure the last group gets any remaining rows
        if i == n_groups - 1:
            end_index = len(data_sorted)
        else:
            end_index = (i + 1) * group_size
            
        subset = data_sorted.iloc[start_index:end_index]
        subdivided_data.append(subset)
    
    return subdivided_data

def cubic_polynomial(x, a, b, c, d):
    return a * x**3 + b * x**2 + c * x + d

# Main code block with the updated fitting process
LHV_H2 = 241800  # J/mol (Lower Heating Value of hydrogen)
HHV_H2= 286000
F = 96485.3321 #s A / mol

E_LHV = LHV_H2/(2*F) #[V]
data, units = load_high_amp_doe_data()
n_groups = 3

data_subdivided = subdivide_data(data, 'pressure_cathode_inlet', n_groups)

system_voltage = []
system_power = []
system_current = []
h2_flow_n_dot = []
efficiency = []
in_range = []
all_cells = [350, 400, 450, 500]
for j in range(len(all_cells)):
    cells = all_cells[j]
    for i in range(3):
        system_power.append(data_subdivided[i]["power"]*1/275) #[kW] !!!
        system_voltage.append(data_subdivided[i]["voltage"])
        system_current.append(data_subdivided[i]["current"])
        
        _flow_high = data_subdivided[i]["flow_anode_h2_mfc_high"]
        _flow_low = data_subdivided[i]["flow_anode_h2_mfc_low"]
        
        _flow_high.replace(0, np.nan, inplace=True)
        _flow_low.replace(0, np.nan, inplace=True)
        
        # Combine the DataFrames using combine_first
        h2_flow = _flow_high.combine_first(_flow_low)
           
        h2_flow_n_dot.append(calculate_n_dot(h2_flow))
        
        # Calculate efficiency
        _eff = (system_voltage[i])*1/275 / E_LHV
        efficiency.append(_eff)

    cathode_in = data_subdivided[i]["current"]

    plt.figure(figsize=(10, 6))
    colors = ["tab:blue", "tab:orange", "tab:green"]
    mean_vals = ["1.42 bara +/- 0.18 bara","1.96 bara +/- 0.18 bara","2.65 bara +/- 0.26 bara"]
    for i in range(3):
        x = system_power[i]*cells/1.15 # gros to net conversion by dividing by 1.15
        y = efficiency[i]
        
        # Ensure x and y are numeric and handle NaNs
        x = pd.to_numeric(x, errors='coerce').dropna()
        y = pd.to_numeric(y, errors='coerce').dropna()

        # Sort x and y by x
        sorted_indices = np.argsort(x)
        x_sorted = x.iloc[sorted_indices]
        y_sorted = y.iloc[sorted_indices]
        
        # Fit a cubic polynomial using curve_fit
        popt, _ = curve_fit(cubic_polynomial, x_sorted, y_sorted)
        cubic_fit = cubic_polynomial(x_sorted, *popt)
        
        # Plotting efficiency against power with cubic fit
        plt.plot(x_sorted, cubic_fit, '-', label=mean_vals[i], c=colors[i])
        plt.plot(x_sorted, y_sorted, '.', c=colors[i], alpha=0.5)
        #plt.plot(x_sorted, cubic_fit, '-', label=f'p{i}: cubic fit', c=colors[i])
    
    plt.vlines([125, 150, 175], [0, 0, 0], [0.7, 0.7, 0.7], 'tab:red')
    plt.text(125, 0.71, '125 kW', horizontalalignment='center', verticalalignment='bottom', color='tab:red')
    plt.text(150, 0.71, '150 kW', horizontalalignment='center', verticalalignment='bottom', color='tab:red')
    plt.text(175, 0.71, '175 kW', horizontalalignment='center', verticalalignment='bottom', color='tab:red')

    # Adding labels and title
    plt.xlabel('Est. System Net Power (kW)')
    plt.ylabel('Efficiency (-)')
    plt.title(f'Efficiency vs. Power at {cells} Cells')
    plt.legend()
    plt.grid(True)
    plt.xlim([0, 250])
    plt.ylim([0, 1])
    
    # Show the plot
    plt.savefig(f"eta_{cells}_cubic_fit.png")
    plt.show()
    
    #%% lets extract the data for the 3 desiered power levels for each pressure group data_subdivided
    vertical_lines = [125, 150, 175]
    buffer = 2 # look +- 10 % around the vline
    
    for line in vertical_lines:
        for i in range(3):
            indices_within_buffer = np.where((system_power[i]*cells/1.15 >= line - buffer) & (system_power[i]*cells/1.15 <= line + buffer))[0]
            
            # Extracting the corresponding data from data_subdivided[i]
            corresponding_data = data_subdivided[i].iloc[indices_within_buffer]
            
            in_range.append(corresponding_data)
        
    
    # Save in_range to Excel file
    # output_file = f"inrange_cell_{all_cells[j]}.xlsx"
    # with pd.ExcelWriter(output_file) as writer:
    #     for idx, df in enumerate(in_range):
    #         df.to_excel(writer, sheet_name=f'Power_{idx+1}', index=False)
    
    # print(f"Data saved to {output_file}.")
        
    
    
# #%% Lets extract the maximum efficiency point at each Power
#     vertical_lines = [125, 150, 175]
#     buffer = 2 # look +- 10 % around the vline
#     max_eta_in_range = []
#     for line in vertical_lines:
#         indices_within_buffer = np.where((system_power[i]*cells >= line - buffer) & (system_power[i]*cells <= line + buffer))[0]
        
#         # Extracting the corresponding data from data_subdivided[i]
#         corresponding_data = data_subdivided[i].iloc[indices_within_buffer]
#         try:
#             max_eta_index = np.argmax(efficiency[i].iloc[indices_within_buffer])
#         except:
#             raise(ValueError)
        
#         max_eta_in_range.append(corresponding_data)

    
        
    
    
    
    
    
