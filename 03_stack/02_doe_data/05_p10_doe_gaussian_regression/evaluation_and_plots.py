# -*- coding: utf-8 -*-
"""
Created on Mon Aug  5 08:30:51 2024

@author: wenzel.gassner
"""

# %% Polkurven 1 cell count, mit shaded are bis 800 A, Cmap Power
import pandas as pd
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt

# Read the data from the CSV file
file_path = r"consolidated_20.0-175.0kW_500-500_120-120ft__1\optimized_parameters_20.0-175.0kW_500-500_120-120ft.csv"
df = pd.read_csv(file_path)

# Sort the DataFrame by 'System Power (kW)'
df = df.sort_values(by='System Power (kW)')

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

# Add a red shaded area from 700 A to 800 A
ax.axvspan(700, 800, color='red', alpha=0.3)

# Set title and labels
flight_level = "Enter_Flight_Level"
cell_count = "Enter_Cell_Count"
ax.set_title(r'System Polarization Curve, FL 120, 500 Cells', fontsize=14)
ax.set_xlabel('Current [A]')
ax.set_ylabel('Cell Voltage [V]')
ax.grid(True)
ax.set_xlim([0, 800])
ax.set_ylim([0.55, 0.8])

# Annotate the first, last, and second-to-last points with the corresponding 'System Power (kW)'
for idx in [0, -1, -2]:
    point = df.iloc[idx]
    ax.annotate(f"{point['Power Constraint (kW)']:.1f} kW", (point['current_A (Value)'], point['Cell Voltage (V)']),
                textcoords="offset points", xytext=(0,10), ha='center')

# Add a legend (the colorbar serves as the legend in this case)
scatter.set_label('System Power [kW]')
ax.legend(loc='best')

plt.show()

# %% Dig data set Polcurve with highlighted 125 150 175 kW points

import pandas as pd
import matplotlib.pyplot as plt

# File paths to the CSV files
file_path1 = r"consolidated_20-175kW_400-500_0-120ft__1/optimized_parameters_20-175kW_400-500_0-120ft.csv"

# Load the CSV files into DataFrames
df1 = pd.read_csv(file_path1)

# Define power levels to highlight
highlight_powers = [125, 150, 175]
highlight_range = 4

# Split the data based on 'Specified Cell Count'
df_400 = df1[df1['Specified Cell Count'] == 400]
df_450 = df1[df1['Specified Cell Count'] == 450]
df_500 = df1[df1['Specified Cell Count'] == 500]

data = [df_400, df_450, df_500]
titles = ['System Polarization Curve, 400 Cells',
          'System Polarization Curve, 450 Cells',
          'System Polarization Curve, 500 Cells']

colors = ["tab:blue", "tab:orange", "tab:red"]

#colors = plt.cm.tab10.colors  # Native tab colors of matplotlib

for df, title in zip(data, titles):
    fig, ax = plt.subplots(figsize=(12, 8))

    # Plot all points in gray with some transparency
    ax.scatter(df['current_A (Value)'], df['Cell Voltage (V)'], color='gray', alpha=0.3, label='_nolegend_')

    # Highlight points for each power level
    for i, power in enumerate(highlight_powers):
        highlight = df[df['System Power (kW)'].between(power - highlight_range, power + highlight_range)]
        ax.scatter(highlight['current_A (Value)'], highlight['Cell Voltage (V)'], 
                   color=colors[i], s=100, edgecolor='k', label=f'{power} kW ± {highlight_range} kW')
    # Add a red shaded area from 700 A to 800 A
    ax.axvspan(700, 800, color='red', alpha=0.3)
    # Set title and labels
    ax.set_title(title)
    ax.set_xlabel('Current [A]')
    ax.set_xlim([0, 800])
    ax.set_ylabel('Cell Voltage [V]')
    ax.set_ylim([0.55, 0.76])
    ax.grid(True)
    ax.legend(loc='best')

    plt.show()
    
    
    
# %% Weight estimation Plot for Stack + Compressor vs System Power

import numpy as np
import matplotlib.pyplot as plt

compressor_dings = 0.63

power_500 = [118.6,146.7,175]
compressor_power_500 = np.array([5.74,7.33,9.16])*compressor_dings
Stack_weight_500 = 47.58
system_weight_500 = compressor_power_500 + Stack_weight_500

power_450 = [118.5,146.69,174.88]
compressor_power_450 = np.array([5.82,7.53,9.54])*compressor_dings
Stack_weight_450 = 43.75
system_weight_450 = compressor_power_450 + Stack_weight_450

power_400 = [118.5,146.68,174.87]
compressor_power_400 = np.array([5.94,7.92,9.94])*compressor_dings
Stack_weight_400 = 39.92
system_weight_400 = compressor_power_400 + Stack_weight_400

from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score

# Function to perform linear regression and return the formula and R^2
def linear_fit(x, y):
    x = np.array(x).reshape(-1, 1)
    y = np.array(y)
    model = LinearRegression().fit(x, y)
    y_pred = model.predict(x)
    slope = model.coef_[0]
    intercept = model.intercept_
    r2 = r2_score(y, y_pred)
    return slope, intercept, r2, y_pred

# Performing linear regression for each dataset
slope_500, intercept_500, r2_500, y_pred_500 = linear_fit(power_500, system_weight_500)
slope_450, intercept_450, r2_450, y_pred_450 = linear_fit(power_450, system_weight_450)
slope_400, intercept_400, r2_400, y_pred_400 = linear_fit(power_400, system_weight_400)

# Plotting
plt.figure(figsize=(10, 6))

plt.scatter(power_400, system_weight_400, marker='^', label=f'400 Stack + Compressor weight\n y={slope_400:.2f}x+{intercept_400:.2f}')
plt.scatter(power_450, system_weight_450, marker='s', label=f'450 Stack + Compressor weight\n y={slope_450:.2f}x+{intercept_450:.2f}')
plt.scatter(power_500, system_weight_500, marker='o', label=f'500 Stack + Compressor weight\n y={slope_500:.2f}x+{intercept_500:.2f}')

# Plotting the fitted lines
plt.plot(power_400, y_pred_400, linestyle='--', color='tab:blue')
plt.plot(power_450, y_pred_450, linestyle='--', color='tab:orange')
plt.plot(power_500, y_pred_500, linestyle='--', color='tab:green')

plt.xlabel('System Power (kW)')
plt.ylabel('Stack + Compressor Weight Estimation [kg]')
plt.title('Stack + Compressor Weight Estimation vs System Power')
# Moving the legend below the x-axis
plt.legend(bbox_to_anchor=(0.5, -0.1), loc='upper center', ncol=3)
plt.grid(True)
plt.show()

# %% Plot (weight spcific) H2 consumption vs System Power with fits 
import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import linregress

# File paths to the CSV files
file_paths = [
    r"consolidated_20.0-175.0kW_400-400_120-120ft__1\optimized_parameters_20.0-175.0kW_400-400_120-120ft.csv",
    r"consolidated_20.0-175.0kW_450-450_120-120ft__1\optimized_parameters_20.0-175.0kW_450-450_120-120ft.csv",
    r"consolidated_20.0-175.0kW_500-500_120-120ft__1\optimized_parameters_20.0-175.0kW_500-500_120-120ft.csv"
]

# Titles for the datasets
titles = [
    '400 Cells',
    '450 Cells',
    '500 Cells'
]

#set to [1,1,1] for system h2 consumption...
weights = [39.92+ 6.26,43.75+6.01,47.58+5.77] #stack + compressor gewicht

fig, ax = plt.subplots(figsize=(12, 8))

for i, (file_path, title,weight) in enumerate(zip(file_paths, titles,weights)):
    df = pd.read_csv(file_path)
    
    # Scatter plot for each dataset
    scatter = ax.scatter(df['System Power (kW)'], df['Hydrogen Consumption (g/s)']/weight, label=title, s=100, edgecolor='k')
    
    # Fit a polynomial of degree 2 (you can change the degree as needed)
    coeffs = np.polyfit(df['System Power (kW)'], df['Hydrogen Consumption (g/s)']/weight, 2)
    poly = np.poly1d(coeffs)
    
    # Plot the polynomial fit
    line_x = np.linspace(df['System Power (kW)'].min(), df['System Power (kW)'].max(), 500)
    line_y = poly(line_x)
    ax.plot(line_x, line_y, color=scatter.get_facecolor()[0], alpha=0.5)
    
    # Add the polynomial formula to the legend
    formula = f'Fit: {coeffs[0]:.2e}x² + {coeffs[1]:.2e}x + {coeffs[2]:.2e}'
    ax.scatter([], [], label=formula, color=scatter.get_facecolor()[0])

# Set title and labels
ax.set_title('Weight Specific Hydrogen Consumption vs System Power, FL 120')
ax.set_xlabel('System Power [kW]')
ax.set_ylabel('Weight Specific Hydrogen Consumption [g/s kg]')
ax.grid(True)
ax.legend(loc='best')

plt.show()

    
# %% H2 consumption over flight level all in one

import pandas as pd
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt

# File path to the CSV file
file_path1 = r"consolidated_20-175kW_400-500_0-120ft__1/optimized_parameters_20-175kW_400-500_0-120ft.csv"

# List of cell counts and corresponding icons
cells = [400, 450, 500]
icons = ["o", "v", "s"]

# Define power levels to highlight
highlight_powers = [125, 150, 175]
highlight_range = 4

# Load the CSV file into a DataFrame
df1 = pd.read_csv(file_path1)

# Create a figure and axis
fig, ax = plt.subplots(figsize=(12, 8))

# Create a colormap and normalize for the color gradient
norm = mcolors.Normalize(vmin=125, vmax=175)
cmap = cm.ScalarMappable(norm=norm, cmap='plasma')

# Loop through each cell count and plot the data
for cell, icon in zip(cells, icons):
    #filter dataframe after cell count and 125-+, 150+-, and 175+-
    df_filtered = df1[(df1['Specified Cell Count'] == cell) &
                      (df1['System Power (kW)'].between(highlight_powers[0] - highlight_range, highlight_powers[0] + highlight_range) |
                       df1['System Power (kW)'].between(highlight_powers[1] - highlight_range, highlight_powers[1] + highlight_range) |
                       df1['System Power (kW)'].between(highlight_powers[2] - highlight_range, highlight_powers[2] + highlight_range))]

    # Scatter plot with color based on 'System Power (kW)'
    scatter = ax.scatter(df_filtered['Flight Level (100x ft)'], df_filtered['Hydrogen Consumption (g/s)'], 
                         c=df_filtered['System Power (kW)'], cmap='plasma', norm=norm, edgecolor='k', s=100, marker=icon, label=f'{cell} Cells')

# Add colorbar for the gradient
cbar = plt.colorbar(cmap, ax=ax)
cbar.set_label('System Power [kW]')

# Create custom legend handles
handles = [plt.Line2D([0], [0], marker=icon, color='w', markerfacecolor='k', markersize=10, linestyle='') for icon in icons]
labels = [f'{cell} Cells' for cell in cells]

# Add legend
ax.legend(handles, labels, loc='upper left')

# Set title and labels
ax.set_title('System Hydrogen Consumption over Flight Level for Different Cell Counts', fontsize=14)
ax.set_xlabel('Flight Level [100x ft]')
ax.set_xlim([0, 120])
ax.set_ylabel('Hydrogen Consumption [g/s]')
ax.set_ylim([1.9, 3.4])
ax.grid(True)

# Show the plot
plt.show()

# %% PLOT BOTH LOW AND HIGH C_IN BAR INTO ON PLOT Gray shaded

# import pandas as pd
# import matplotlib.pyplot as plt
# import matplotlib.colors as mcolors
# import matplotlib.cm as cm
# from scipy.interpolate import make_interp_spline
# import numpy as np

# # File paths to the CSV files
# file_path1 = r"consolidated_20-175kW_350-350_100-100ft__1\optimized_parameters_20-175kW_350-350_100-100ft.csv"
# file_path2 = r"consolidated_20-175kW_350-350_100-100ft__2\optimized_parameters_20-175kW_350-350_100-100ft.csv"

# # Load the CSV files into DataFrames
# df1 = pd.read_csv(file_path1)
# df2 = pd.read_csv(file_path2)

# # Define the allowed difference (kW)
# X = 10

# # Filter rows based on the allowed difference
# filtered_df1 = df1[abs(df1['System Power (kW)'] - df1['Power Constraint (kW)']) <= X]
# filtered_df2 = df2[abs(df2['System Power (kW)'] - df2['Power Constraint (kW)']) <= X]

# # Create a colormap and normalize for the color gradient
# norm = mcolors.Normalize(vmin=min(20, 20), 
#                          vmax=min(175, 175))
# cmap = cm.ScalarMappable(norm=norm, cmap='viridis')

# # Plot 'Current A (Value)' vs 'Cell Voltage (V)' for both datasets
# fig, ax = plt.subplots(figsize=(12, 8))

# # Curve fitting
# x1, y1 = filtered_df1['current_A (Value)'], filtered_df1['Cell Voltage (V)']
# x2, y2 = filtered_df2['current_A (Value)'], filtered_df2['Cell Voltage (V)']

# # Sort the data by x values
# x1_sorted, y1_sorted = zip(*sorted(zip(x1, y1)))
# x2_sorted, y2_sorted = zip(*sorted(zip(x2, y2)))

# # Create spline fits
# spline1 = make_interp_spline(x1_sorted, y1_sorted, k=3)
# spline2 = make_interp_spline(x2_sorted, y2_sorted, k=3)

# # Define a range for x values for smooth curves
# x_range = np.linspace(min(min(x1), min(x2)), max(max(x1), max(x2)), 500)

# # Evaluate the spline fits on the x range
# y1_smooth = spline1(x_range)
# y2_smooth = spline2(x_range)

# # Fill the space between the curves
# ax.fill_between(x_range, y1_smooth, y2_smooth, where=(y2_smooth > y1_smooth), interpolate=True, color='lightgray', alpha=0.8)

# # Plot the smooth curves
# #ax.plot(x_range, y1_smooth, color='lightgray', label='Fit 1.5 bara', alpha=0.8)
# #ax.plot(x_range, y2_smooth, color='lightgray', label='Fit 3.0 bara', alpha=0.8)


# # Scatter plot for the first dataset
# scatter1 = ax.scatter(filtered_df1['current_A (Value)'], filtered_df1['Cell Voltage (V)'], 
#                       c=filtered_df1['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100, label=r'$p_{{in}}^{{C}} = 1.5$ bar(a)')


# # Scatter plot for the second dataset
# scatter2 = ax.scatter(filtered_df2['current_A (Value)'], filtered_df2['Cell Voltage (V)'], c=filtered_df2['System Power (kW)'], 
#                       cmap='viridis', norm=norm, edgecolor='k', s=100, marker='^', label=r'$p_{{in}}^{{C}} = 3.0$ bar(a)')


# # Add colorbar for the gradient
# cbar = plt.colorbar(cmap, ax=ax)
# cbar.set_label('System Power [kW]')

# # Set title and labels

# ax.set_title(rf'System Polarization Curve, $p_{{in}}^{{C}}  \in [1.5, 3.0] \, \text{{bar(a)}}$', fontsize=14)
# ax.set_xlabel('Current [A]', fontsize=12)
# ax.set_ylabel('Cell Voltage [V]', fontsize=12)
# ax.grid(True)
# ax.set_xlim([0, 700])
# ax.set_ylim([0.5, 1])

# # Add a legend
# ax.legend(loc='best')

# plt.show()



#%% Analysis turbine/no turbine eol/no elo
import pandas as pd
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import itertools
import numpy as np

#parameter vom run:
_range_power = np.array([20, 50, 80, 125, 150, 175])
_range_cellcount = np.arange(400,500+50,50)
_range_fl = np.arange(120,120+20,20)

# Convert turbine and eol to boolean lists
_range_turbine = ["true","false"]
_range_eol = ["true","false"]

# Generate all combinations of parameters
_parameters = list(itertools.product(_range_power, _range_cellcount, _range_fl, _range_turbine, _range_eol))
_c_names = ["p","c","fl","t","eol"]

# Create the DataFrame
_df_parameters = pd.DataFrame(_parameters, columns=_c_names)

file_path1 = r"consolidated_20-175kW_400-500_120-120ft__1\optimized_parameters_20-175kW_400-500_120-120ft.csv"

# Load the CSV file into a DataFrame
df1 = pd.read_csv(file_path1)
df1 = df1.sort_values(by=['Flight Level (100x ft)','Power Constraint (kW)','Specified Cell Count'])

# Concatenate side by side
df1 = pd.concat([df1, _df_parameters], axis=1)

# Split the data based on 'Specified Cell Count'
df_400 = df1[(df1['Specified Cell Count'] == 400) 
             & (df1["Turbine Power (kW)"] == 0)
             & (df1["eol"] == "false")]


.reset_index(drop=True)
df_even_indices = df1.iloc[::2]

df_450 = df1[(df1['Specified Cell Count'] == 450) 
             & (df1["Turbine Power (kW)"] == 0)]

df_500 = df1[(df1['Specified Cell Count'] == 500) 
             & (df1["Turbine Power (kW)"] == 0)]

data = [df_400, df_450, df_500]
titles = ['System Polarization Curve, FL 120, 400 Cells',
          'System Polarization Curve, FL 120, 450 Cells',
          'System Polarization Curve, FL 120, 500 Cells']

colors = ["tab:blue", "tab:orange", "tab:red"]

#colors = plt.cm.tab10.colors  # Native tab colors of matplotlib
# Define power levels to highlight
highlight_powers = [125, 150, 175]
highlight_range = 4

for df, title, color in zip(data, titles ,colors):
    fig, ax = plt.subplots(figsize=(12, 8))

    # Plot all points in gray with some transparency
    #ax.scatter(df['current_A (Value)'], df['Cell Voltage (V)'], color='gray', alpha=0.3, label='_nolegend_')
    ax.scatter(df['current_A (Value)'], df['Cell Voltage (V)'], color=color)
    # Highlight points for each power level
    # for i, power in enumerate(highlight_powers):
    #     highlight = df[df['System Power (kW)'].between(power - highlight_range, power + highlight_range)]
    #     ax.scatter(highlight['current_A (Value)'], highlight['Cell Voltage (V)'], 
    #                color=colors[i], s=100, edgecolor='k', label=f'{power} kW ± {highlight_range} kW')
    # Add a red shaded area from 700 A to 800 A
    ax.axvspan(700, 800, color='red', alpha=0.3)
    # Set title and labels
    ax.set_title(title)
    ax.set_xlabel('Current [A]')
    ax.set_xlim([0, 800])
    ax.set_ylabel('Cell Voltage [V]')
    ax.set_ylim([0.55, 0.76])
    ax.grid(True)
    ax.legend(loc='best')

    plt.show()