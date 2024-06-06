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
        # plt.scatter(x, y, label=f"{col} [{unit}]")
        plt.scatter(x, y, label="DoE Raw Data", zorder=2)

        if regression:
            # 3rd order regression
            coeffs = np.polyfit(x.to_list(), y.to_list(), 3)
            poly = np.poly1d(coeffs)
            x_samples = np.linspace(0, 760, 100)
            plt.plot(x_samples, poly(x_samples), color='orange', linewidth=1.5, label="3rd Order LSE Regression", zorder=2)

            # plot markers to specific values on regression line
            specific_current_samples = [600, 750]
            specific_values = poly(specific_current_samples)
            plt.scatter(specific_current_samples, specific_values, color='orange', label="Expected Values at 600 A & 750 A", zorder=2)

            # print specific values
            for i, txt in enumerate(specific_values):
                plt.annotate(f"{txt:.2f}" + " V", (specific_current_samples[i], specific_values[i]), textcoords="offset points",
                             xytext=(0, 10), ha='center', zorder=2)
                
            # find data point whose x values are within an interval of +/- 10 A around specific_current_samples
            for i, current in enumerate(specific_current_samples):
                interval = 10
                mask = (x >= current - interval) & (x <= current + interval)
                x_interval = x[mask]
                y_interval = y[mask]
                # get datapoint with max y-value
                max_y = y_interval.idxmax()
                # plot max y-value
                label = f"Max. Values within +/-{interval} A Interval" if i == 0 else None
                plt.scatter(x_interval.loc[max_y], y_interval.loc[max_y], label=label, color="red", zorder=2)
                # create annotation
                plt.annotate(f"{y_interval.loc[max_y]:.2f}" + " V", (x_interval.loc[max_y], y_interval.loc[max_y]), textcoords="offset points",
                             xytext=(0, 10), ha='center', zorder=2)


    plt.xlabel(f"Current [{units['current']}]")
    # plt.ylabel(f"[{unit}]")
    plt.ylabel(f"Cell Voltage [{unit}]")
    plt.xlim([0, 760])
    plt.xticks([50 * n for n in range(16)])
    plt.grid(True, zorder=1)
    plt.legend()
    # plt.title(f"current vs {col}")
    plt.title("Polarization Curve")
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
