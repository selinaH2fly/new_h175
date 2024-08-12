# -*- coding: utf-8 -*-
"""
Created on Mon Aug 12 05:44:09 2024

@author: wenzel.gassner
"""

# %% Imports:
import pandas as pd
import os
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.lines as mlines

# Function to create the plot
def plot_polarization_curves(data, titles, saving=True):
    """
    Plots the polarization curves for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    for df, title in zip(data, titles):
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Create a colormap and normalize for the color gradient
        norm = mcolors.Normalize(vmin=df['System Power (kW)'].min(), vmax=min(df['System Power (kW)'].max(), 175))
        cmap = cm.ScalarMappable(norm=norm, cmap='viridis')
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df['current_A (Value)'], df['Cell Voltage (V)'], c=df['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100)

        # Add colorbar for the gradient
        cbar = plt.colorbar(scatter, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Manually set colorbar ticks from 20 to 175 in 25 steps, excluding 25
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

        # Add a red shaded area from 700 A to 800 A
        ax.axvspan(700, 800, color='red', alpha=0.3)
        
        # Set title and labels
        ax.set_title(f'System Polarization Curve, FL 120, {title}', fontsize=14)
        ax.set_xlabel('Current [A]')
        ax.set_ylabel('Cell Voltage [V]')
        ax.grid(True)
        ax.set_xlim([0, 800])
        ax.set_ylim([0, 1.25])
        fig.tight_layout()

        # Annotate points where 'eol (t/f)' is True
        for i in df[df["eol (t/f)"] == True].index:
            ax.annotate('EOL', 
                        (df['current_A (Value)'][i], df['Cell Voltage (V)'][i]), 
                        textcoords="offset points", 
                        xytext=(2, -20), 
                        ha='center',
                        fontsize=11, 
                        color='black')
            
        # Create a custom legend entry with a colorless circle
        legend_circle = mlines.Line2D([], [], color='none', marker='o', markerfacecolor='none', markeredgecolor='black', markersize=11, linestyle='None', label='System Power [kW]')
        ax.legend(handles=[legend_circle], loc='best')

        # Save the plot as a PNG file if saving is True
        if saving:
            plt.savefig(f'{title}_polarization_curve.png')
        
        # Show the plot
        plt.show()
        
        
# Function to create the plot
def plot_h2_consumption(data, titles, colors, weights, saving=True):
    fig, ax = plt.subplots(figsize=(12, 8))
    fig.tight_layout()
    # Store handles and labels for manual legend creation
    handles = []
    labels = []

    for df, title, color, weight in zip(data, titles, colors, weights):
        for filter_eol, linestyle, marker, label_suffix in [(False, '-', 'o', 'Normal'), (True, '--', '^', 'EOL')]:
            # Apply the filter based on the function argument
            filtered_df = df[df["eol (t/f)"] == filter_eol]
            
            # Scatter plot for each dataset
            scatter = ax.scatter(filtered_df['System Power (kW)'], 
                                 filtered_df['Hydrogen Consumption (g/s)']/weight, 
                                 s=100, edgecolor='k', color=color, marker=marker)
            
            # Fit a polynomial of degree 2
            coeffs = np.polyfit(filtered_df['System Power (kW)'], 
                                filtered_df['Hydrogen Consumption (g/s)']/weight, 2)
            poly = np.poly1d(coeffs)
            
            # Plot the polynomial fit
            line_x = np.linspace(filtered_df['System Power (kW)'].min(), 
                                 filtered_df['System Power (kW)'].max(), 500)
            line_y = poly(line_x)
            line, = ax.plot(line_x, line_y, linestyle=linestyle, color=color, alpha=0.7)
            
            # Add the polynomial formula to the legend
            formula = f'{title} ({label_suffix}) Fit: {coeffs[0]:.2e}x² + {coeffs[1]:.2e}x + {coeffs[2]:.2e}'
            
            # Collect handles and labels for the legend
            handles.append(scatter)
            labels.append(f'{title} ({label_suffix}) Data')
            handles.append(line)
            labels.append(formula)

    # Create the legend
    ax.legend(handles, labels, loc='best')

    # Set title and labels
    ax.set_title('Hydrogen Consumption vs System Power, FL 120')
    ax.set_xlabel('System Power [kW]')
    ax.set_ylabel('Hydrogen Consumption [g/s kg]')
    ax.grid(True)
    
    if saving:
        plt.savefig('Hydrogen_Consumption.png')
    plt.show()

def plot_polarization_curves_bol_eol(df1, titles,colors, saving=True):
    
    def load_and_filter_data(df1, eol, cell_counts):
        df = df1
        
        filtered_data = {}
        for count in cell_counts:
            filtered_data[count] = df[(df['Specified Cell Count'] == count)
                                      & (df["eol (t/f)"] == eol)]
        return filtered_data

    # Define plotting and annotation function
    def plot_and_annotate_data(ax, bol_data, eol_data, titles, colors, highlight_powers, highlight_range=5, marker='o'):
        for count, title, color in zip(bol_data.keys(), titles, colors):
            bol_df = bol_data[count]
            eol_df = eol_data[count]
            
            # Plot BOL data
            ax.scatter(bol_df['current_A (Value)'], bol_df['Cell Voltage (V)'], color=color, label=f'{title} bol', marker=marker)
            
            # Plot EOL data
            ax.scatter(eol_df['current_A (Value)'], eol_df['Cell Voltage (V)'], color=color, label=f'{title} eol', marker='v')
            
            # Connect corresponding BOL and EOL points
            for power in highlight_powers:
                bol_highlight = bol_df[bol_df["System Power (kW)"].between(power - highlight_range, power + highlight_range)]
                eol_highlight = eol_df[eol_df["System Power (kW)"].between(power - highlight_range, power + highlight_range)]
                
                for (_, bol_row), (_, eol_row) in zip(bol_highlight.iterrows(), eol_highlight.iterrows()):
                    ax.plot([bol_row['current_A (Value)'], eol_row['current_A (Value)']], 
                            [bol_row['Cell Voltage (V)'], eol_row['Cell Voltage (V)']],
                            color=color, alpha=0.5, linestyle='--')
                    
                    # Annotate points
                    ax.annotate(f'{bol_row["Power Constraint (kW)"]:.0f} kW', 
                                (bol_row['current_A (Value)'], bol_row['Cell Voltage (V)']),
                                textcoords="offset points", xytext=(0, 40), ha='center', color=color,
                                arrowprops=dict(facecolor=color, shrink=0.1))

    # Power levels to highlight and annotate
    highlight_powers = [20.0,110.0,140.0,175.0]#[125, 150, 175]

    cell_counts = [400, 450, 500]

    # Load and filter data for different scenarios
    bol_data = load_and_filter_data(df1, eol=False, cell_counts=cell_counts)
    eol_data = load_and_filter_data(df1, eol=True, cell_counts=cell_counts)
    
    # Create a plot
    fig, ax = plt.subplots(figsize=(12, 8))
    
    # Plot, annotate, and connect BOL and EOL data
    plot_and_annotate_data(ax, bol_data, eol_data, titles, colors, highlight_powers)

    # Add a red shaded area from 700 A to 1300 A
    ax.axvspan(700, 1300, color='red', alpha=0.2)

    # Set title and labels
    ax.set_title("System Polarization Curve, FL 120, eol vs bol")
    ax.set_xlabel('Current [A]')
    ax.set_xlim([0, 1300])
    ax.set_ylabel('Cell Voltage [V]')
    ax.set_ylim([0.3, 1])
    ax.grid(True)
    ax.legend(loc='upper right')

    # Show plot
    if saving:
        plt.savefig('Hydrogen_Consumption.png')
    plt.show()
    
    
# %% Power Plot Grid, fancy
def format_data_for_plot(df, components, eol_col='eol (t/f)'):
    """
    Formats the DataFrame for plotting by separating components based on the eol (t/f) column.

    Parameters:
    - df (pd.DataFrame): The DataFrame to be formatted.
    - components (list): List of component columns to include in the formatted DataFrame.
    - eol_col (str): Name of the column containing 'True' or 'False' values to split by.

    Returns:
    - pd.DataFrame: A formatted DataFrame for plotting.
    """
    # Create an empty DataFrame to store formatted data
    formatted_df = pd.DataFrame()

    for component in components:
        # Filter out the columns related to the component
        component_df = df[['Power', component, eol_col]].copy()

        # Separate the data based on eol (t/f)
        df_false = component_df[component_df[eol_col] == False].drop(columns=[eol_col])
        df_true = component_df[component_df[eol_col] == True].drop(columns=[eol_col])

        # Append to the formatted DataFrame
        formatted_df = pd.concat([formatted_df, df_false, df_true], axis=1)

    # Reset column names to be more descriptive
    formatted_df.columns = ['Power'] + [f'{component}_False' for component in components] + [f'{component}_True' for component in components]
    
    return formatted_df

# Example usage
components = ['C1', 'C2', 'C3', 'C4', 'C5']  # Specify components to include
filtered_df_400 = filter_columns(df_400, ['Power'] + components + ['eol (t/f)'])
formatted_df_400 = format_data_for_plot(filtered_df_400, components)

def plot_power_needs(df, saving=False):
    """
    Plot a heatmap-like representation of power needs by components, with specific formatting.

    Parameters:
    - df (pd.DataFrame): DataFrame where the first column is 'Power' and the remaining columns represent components.
    - saving (bool): If True, saves the plot to a file. Defaults to False.
    - filename (str): Filename to save the plot, used only if saving=True.

    The plot displays:
    - A heatmap-like grid where each cell represents power needs.
    - Gaps are inserted between every second column for visual separation.
    """
    
    # Set up the figure and axis
    fig, ax = plt.subplots(figsize=(10, 8))

    # Define the colormap and normalization
    cmap = plt.cm.viridis
    norm = mcolors.Normalize(vmin=df.iloc[:, 1:].min().min(), vmax=df.iloc[:, 1:].max().max())

    # Plot each cell with a gap between every second column
    for i in range(len(df)):
        for j in range(df.shape[1] - 1):
            col_pos = j + (j // 2)  # Calculate position with gaps after every second column
            cell_value = df.iloc[i, j + 1]
            ax.imshow([[cell_value]], aspect='auto', cmap=cmap, norm=norm,
                      extent=[col_pos, col_pos + 1, (len(df) - i - 1) * 2, (len(df) - i - 1) * 2 + 1])

    # Adjust xlim to ensure the first cell is fully inside the plot
    total_columns = df.shape[1] - 1 + (df.shape[1] - 2) // 2  # Adjusted number of columns with gaps
    ax.set_xlim(-0.5, total_columns + 0.5)

    # Calculate adjusted x-tick positions (centered)
    col_positions = [i + (i // 2) + 0.5 for i in range(df.shape[1] - 1)]
    ax.set_xticks(col_positions)

    # Set x-tick labels to alternate between 'Bol' and 'Eol'
    ax.set_xticklabels(['Bol' if i % 2 == 0 else 'Eol' for i in range(df.shape[1] - 1)])

    # Adjust y-ticks to be centered on the colored boxes
    y_tick_positions = np.arange(1, len(df) * 2, 2) - 0.5  # Center y-ticks by shifting them down
    ax.set_yticks(y_tick_positions)
    ax.set_yticklabels([f'Power Level {i + 1}' for i in range(len(df))])
    ax.set_ylim(-0.5, len(df) * 2 - 0.5)

    # Add secondary x-axis on top, with centered labels above each pair of boxes
    ax2 = ax.twiny()
    ax2.set_xlim(ax.get_xlim())  # Ensure the limits are the same

    # Determine the tick positions for the secondary x-axis
    num_columns = df.shape[1] - 1
    positions = [1 + 3 * i for i in range((df.shape[1] - 2) // 2 + 1)]  # Positions for labels, adjust to the center
    ax2.set_xticks(positions)

    # Adjust labels for the secondary x-axis
    ax2.set_xticklabels([df.columns[i + 1] for i in range(0, num_columns, 2)])  # Every other column label
    ax2.set_xlabel('Components', labelpad=10)

    # Add colorbar
    cbar = fig.colorbar(plt.cm.ScalarMappable(norm=norm, cmap=cmap), ax=ax)
    cbar.set_label('Power (kW)')

    # Set the title centered between the colored boxes
    title = "Powerconsuption of Components [kW]"
    ax.set_title(title, pad=20, loc='center')

    # Save or show the plot
    if saving:
        plt.savefig('power_needs_plot.png', bbox_inches='tight')
    else:
        plt.show()


# Create the DataFrame
np.random.seed(0)
powerlevel = 7
components_num = 5
column_num = components_num * 2 + 1
data = np.random.rand(powerlevel, column_num) * 100
df = pd.DataFrame(data, columns=['Power'] + [f'C{i}' for i in range(column_num - 1)])

plot_power_needs(df, saving=False, filename='power_needs_plot.png')

    
def analyze_data(_file_path1=r"consolidated_20-175kW_400-500_120-120ft__3\optimized_parameters_20-175kW_400-500_120-120ft.csv", saving=True):
    
    # Load the CSV file into a DataFrame
    df1 = pd.read_csv(_file_path1)

    # Change the working directory to the directory containing the .csv file
    file_dir = os.path.dirname(_file_path1)
    os.chdir(file_dir)

    # Create a new directory for plots
    os.makedirs("00_Plots", exist_ok=True)
    os.chdir("00_Plots")
    
    # Sort data by index
    df1 = df1.sort_values(by=['idx'])
        
    # Split the data based on 'Specified Cell Count'
    df_400 = df1[df1['Specified Cell Count'] == 400]
    df_450 = df1[df1['Specified Cell Count'] == 450]
    df_500 = df1[df1['Specified Cell Count'] == 500]
    
    data   = [     df_400,       df_450,     df_500]
    titles = ['400 Cells',  '450 Cells','500 Cells']
    colors = [ "tab:blue", "tab:orange",  "tab:red"]
    

    ##########
    # PLOT: Polcurves
    plot_polarization_curves(data, titles, saving=True)    
    
    
    ###########
    # PLOT: H2 consumption
    
    weights = [1,1,1]#[39.92+ 6.26,43.75+6.01,47.58+5.77] #stack + compressor gewicht
    plot_h2_consumption(data, titles, colors, weights, saving=True)
    
    
    ############
    #PLOT: Flightlevel specific Plot
    
    #Check if flightlevel is the same in the column "Flight Level (100x ft)"
        #if True --> Pass
        #if False--> create flightlevel Plot
        
    ############
    #PLOT: System Power


    ############
    #PLOT: Polcurves eol vs bol connected
    plot_polarization_curves_bol_eol(df1, titles,colors, saving=True)

# %%    


analyze_data(_file_path1=r"consolidated_20-175kW_400-500_120-120ft__3\optimized_parameters_20-175kW_400-500_120-120ft.csv", saving=True)    


#TODO write init: