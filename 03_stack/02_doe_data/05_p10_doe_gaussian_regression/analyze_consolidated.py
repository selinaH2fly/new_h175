# -*- coding: utf-8 -*-
"""
Created on Thu Aug  1 07:49:03 2024
 
@author: wenzel.gassner
"""
 
import pandas as pd
import matplotlib.pyplot as plt
 
 
#file_path = r"consolidated_20-175kW_300-300_100-100ft__1\optimized_parameters_20-175kW_300-300_100-100ft.csv"
file_path = r"consolidated_25-175kW_455-455_120-120ft__1\optimized_parameters_25-175kW_455-455_120-120ft.csv"
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
 
# Set title and labels
ax.set_title(f'Kennlinie - Flight Level: {flight_level}, Cell Count: {cell_count}')
ax.set_xlabel('Current [A]')
ax.set_ylabel('Cell Voltage [V]')
ax.grid(True)
ax.set_xlim([0, 700])
ax.set_ylim([0.5, 1])
 
# Add a legend (the colorbar serves as the legend in this case)
scatter.set_label('System Power [kW]')
ax.legend(loc='best')
 
plt.show()
 
# Safe the plot
fig.savefig('Pole_Curve.png')


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

fig.savefig('Hydrogen_Consumption.png')
