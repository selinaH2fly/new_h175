# -*- coding: utf-8 -*-
"""
Created on Thu Aug  1 07:49:03 2024

@author: wenzel.gassner
"""

import pandas as pd
import matplotlib.pyplot as plt


#file_path = r"consolidated_20-175kW_300-300_100-100ft__1\optimized_parameters_20-175kW_300-300_100-100ft.csv"
file_path = r"consolidated_20-175kW_350-350_100-100ft__1\optimized_parameters_20-175kW_350-350_100-100ft.csv"
# Load the CSV file into a DataFrame
# Replace 'your_file.csv' with the path to your CSV file
df = pd.read_csv(file_path)

X = 10 #kW difference allowed between constrain and system power
filtered_df = df[abs(df['System Power (kW)'] - df['Power Constraint (kW)']) <= X]
# Extract relevant values for the title
flight_level = df['Flight Level (100x ft)'].iloc[0]
cell_count = df['Specified Cell Count'].iloc[0]
# Display the first few rows of the DataFrame to understand its structure
print(df.head())

# %%
import pandas as pd
import matplotlib.colors as mcolors
import matplotlib.cm as cm

# Create a colormap and normalize for the color gradient
norm = mcolors.Normalize(vmin=df['System Power (kW)'].min(), vmax=min(df['System Power (kW)'].max(), 175))
cmap = cm.ScalarMappable(norm=norm, cmap='viridis')

# Plot 'Current A (Value)' vs 'Cell Voltage (V)'
fig, ax = plt.subplots(figsize=(12, 8))

# Scatter plot with color based on 'System Power (kW)'
scatter = ax.scatter(df['current_A (Value)'], df['Cell Voltage (V)'], c=df['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100)

# Add colorbar for the gradient
cbar = plt.colorbar(scatter, ax=ax)
cbar.set_label('System Power [kW]')

c_in = "1.5 bar"
# Set title and labels
ax.set_title(f'Kennlinie - Flight Level: {flight_level}, Cell Count: {cell_count}, C_in = {c_in}')
ax.set_xlabel('Current [A]')
ax.set_ylabel('Cell Voltage [V]')
ax.grid(True)
ax.set_xlim([0, 700])
ax.set_ylim([0.5, 1])

# Add a legend (the colorbar serves as the legend in this case)
scatter.set_label('System Power [kW]')
ax.legend(loc='best')

plt.show()


# %%

# Plot 'Net Power (kW)' vs 'Hydrogen Consumption (g/s)'
fig, ax = plt.subplots(figsize=(12, 8))

# Scatter plot without color gradient
ax.scatter(df['System Power (kW)'], df['Hydrogen Consumption (g/s)'], marker='o', color='b', edgecolor='k', s=100)

# Set title and labels
ax.set_title(f'Hydrogen Consumption vs Net Power - Flight Level: {flight_level}, Cell Count: {cell_count}')
ax.set_xlabel('Net Power [kW]')
ax.set_ylabel('Hydrogen Consumption [g/s]')
ax.grid(True)

plt.show()


# %% PLOT BOTH LOW AND HIGH C_IN BAR INTO ON PLOT

import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.cm as cm
from scipy.interpolate import make_interp_spline
import numpy as np

# File paths to the CSV files
file_path1 = r"consolidated_20-175kW_350-350_100-100ft__1\optimized_parameters_20-175kW_350-350_100-100ft.csv"
file_path2 = r"consolidated_20-175kW_350-350_100-100ft__2\optimized_parameters_20-175kW_350-350_100-100ft.csv"

# Load the CSV files into DataFrames
df1 = pd.read_csv(file_path1)
df2 = pd.read_csv(file_path2)

# Define the allowed difference (kW)
X = 10

# Filter rows based on the allowed difference
filtered_df1 = df1[abs(df1['System Power (kW)'] - df1['Power Constraint (kW)']) <= X]
filtered_df2 = df2[abs(df2['System Power (kW)'] - df2['Power Constraint (kW)']) <= X]

# Create a colormap and normalize for the color gradient
norm = mcolors.Normalize(vmin=min(20, 20), 
                         vmax=min(175, 175))
cmap = cm.ScalarMappable(norm=norm, cmap='viridis')

# Plot 'Current A (Value)' vs 'Cell Voltage (V)' for both datasets
fig, ax = plt.subplots(figsize=(12, 8))

# Curve fitting
x1, y1 = filtered_df1['current_A (Value)'], filtered_df1['Cell Voltage (V)']
x2, y2 = filtered_df2['current_A (Value)'], filtered_df2['Cell Voltage (V)']

# Sort the data by x values
x1_sorted, y1_sorted = zip(*sorted(zip(x1, y1)))
x2_sorted, y2_sorted = zip(*sorted(zip(x2, y2)))

# Create spline fits
spline1 = make_interp_spline(x1_sorted, y1_sorted, k=3)
spline2 = make_interp_spline(x2_sorted, y2_sorted, k=3)

# Define a range for x values for smooth curves
x_range = np.linspace(min(min(x1), min(x2)), max(max(x1), max(x2)), 500)

# Evaluate the spline fits on the x range
y1_smooth = spline1(x_range)
y2_smooth = spline2(x_range)

# Fill the space between the curves
ax.fill_between(x_range, y1_smooth, y2_smooth, where=(y2_smooth > y1_smooth), interpolate=True, color='lightgray', alpha=0.8)

# Plot the smooth curves
#ax.plot(x_range, y1_smooth, color='lightgray', label='Fit 1.5 bara', alpha=0.8)
#ax.plot(x_range, y2_smooth, color='lightgray', label='Fit 3.0 bara', alpha=0.8)


# Scatter plot for the first dataset
scatter1 = ax.scatter(filtered_df1['current_A (Value)'], filtered_df1['Cell Voltage (V)'], 
                      c=filtered_df1['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100, label=r'$p_{{in}}^{{C}} = 1.5$ bar(a)')


# Scatter plot for the second dataset
scatter2 = ax.scatter(filtered_df2['current_A (Value)'], filtered_df2['Cell Voltage (V)'], c=filtered_df2['System Power (kW)'], 
                      cmap='viridis', norm=norm, edgecolor='k', s=100, marker='^', label=r'$p_{{in}}^{{C}} = 3.0$ bar(a)')


# Add colorbar for the gradient
cbar = plt.colorbar(cmap, ax=ax)
cbar.set_label('System Power [kW]')

# Set title and labels

ax.set_title(rf'System Polarization Curve, $p_{{in}}^{{C}}  \in [1.5, 3.0] \, \text{{bar(a)}}$', fontsize=14)
ax.set_xlabel('Current [A]', fontsize=12)
ax.set_ylabel('Cell Voltage [V]', fontsize=12)
ax.grid(True)
ax.set_xlim([0, 700])
ax.set_ylim([0.5, 1])

# Add a legend
ax.legend(loc='best')

plt.show()




































