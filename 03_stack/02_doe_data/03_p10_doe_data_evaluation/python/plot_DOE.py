# -*- coding: utf-8 -*-
"""
Created on Wed May 22 08:24:32 2024

@author: wenzel.gassner, SteNo
"""
import os
from pathlib import Path

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

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


# Plot the data
def plot_columns(df, y_columns, units_df, regression=False):
    plt.figure(figsize=(10, 6))

    for col in y_columns:
        unit = units_df[col]
        x = df['current']
        y = df[col]
        plt.scatter(x, y, label=f"{col} [{unit}]")

        if regression:
            coeffs = np.polyfit(x.to_list(), y.to_list(), 3)
            poly = np.poly1d(coeffs)
            x_samples = np.linspace(0, 760, 100)
            plt.plot(x_samples, poly(x_samples), color='orange', linewidth=1.5, label="3rd order LSE regression")

    plt.xlabel(f"current [{units['current']}]")
    plt.ylabel(f"[{unit}]")
    plt.xlim([0, 760])
    plt.xticks([50 * n for n in range(16)])
    plt.legend()
    plt.title(f"current vs {col}")
    plt.savefig(f'{col}.png', dpi=300, bbox_inches='tight')
    plt.show()


# Example usage
y_columns = ["metis_CVM_Cell_Voltage_Mean"]
# y_columns = ["pressure_coolant_inlet","pressure_anode_inlet"]
# y_columns = ["Anode_H2_Concentration"]
# y_columns = ["temp_anode_inlet"]
# y_columns = ["temp_anode_dewpoint_gas"]
# y_columns = ["total_cathode_stack_flow"]
# y_columns = ["pressure_coolant_inlet"]
# y_columns = ["temp_cathode_dewpoint_gas"]  # List of columns to plot on y-axis

plot_columns(df, y_columns, units, regression=True)
