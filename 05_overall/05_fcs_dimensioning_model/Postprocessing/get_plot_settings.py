import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.lines as mlines
import os
import sys

import numpy as np
import pandas as pd




def filter_data_by_f1_and_weight(df, fl_set, weighting):
    df = df[(df['Flight Level (100x ft)'] == fl_set) & (df['weighting ([0,1])'] == weighting)]
    return df




def create_plot_save_directory(filename, weighting, directory=""):
    if directory != "": 
        folder_name = f'{directory}/weighting_{weighting}'
    else: 
        folder_name = f'weighting_{weighting}'
    folder_path = os.path.join(os.getcwd(), folder_name)
    file_path = os.path.join(folder_path, filename)
    os.makedirs(folder_path, exist_ok=True)
    return file_path
 

def configure_axes(ax, **params):
        ax.set_title(params.get('title', 'Standard Titel'))
        ax.set_xlabel(params.get('x_label', 'X-Achse'))
        ax.set_xlim(params.get('x_lim', None))
        ax.set_ylabel(params.get('y_label', 'Y-Achse'))
        ax.set_ylim(params.get('y_lim', None))
        ax.grid(True)

def create_legend(ax, markers_oL):
        legend_bol = mlines.Line2D([], [], color='none', marker=markers_oL[0], 
                                      markerfacecolor='none', markeredgecolor='black', 
                                      markersize=11, linestyle='None', label='System Power BoL [kW]')
        legend_eol = mlines.Line2D([], [], color='none', marker=markers_oL[1],
                                      markerfacecolor='none', markeredgecolor='black', 
                                      markersize=11, linestyle='None', label='System Power EoL [kW]')
        
        ax.legend(handles=[legend_bol,legend_eol], loc='best')

def create_colormap(vmin, vmax, cmap): 
        norm = mcolors.Normalize(vmin=vmin, vmax=vmax)
        cmap = cm.ScalarMappable(norm=norm, cmap=cmap)
        return norm, cmap



def seperate_bol_eol(df):
        df_bol = df[df["eol (t/f)"] == False]
        df_eol = df[df["eol (t/f)"] == True]
        return df_bol, df_eol



def add_colorbar(cmap, ax):
        # Add colorbar for the gradient
        cbar = plt.colorbar(cmap, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Set custom colorbar ticks
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])


def plot_scatter(ax, x, y, color_data=None, label=None, marker='o', edgecolor='k', cmap='viridis', norm=None, size=100, zorder=None, alpha=1.0):
    scatter = ax.scatter(
        x, y, c=color_data, cmap=cmap, norm=norm, edgecolor=edgecolor, 
        s=size, marker=marker, label=label, zorder=zorder, alpha=alpha
    )
    return scatter



def getMode(mode): 
    return (True, "EoL") if mode == "eol" else (False, "BoL")


#######Systempower and System Effizienz
# Create the polynomial function
def poly(x, coeffs):
    return coeffs[0] * x**2 + coeffs[1] * x + (coeffs[2] if len(coeffs) > 2 else 0)
# Create the polynomial function and plot polynomial fit
def create_plot_polynomial_function(ax, x, linestyle, color, coeffs): 
    line_x = np.linspace(x.min(), x.max(), 500)
    line_y = poly(line_x, coeffs)
    line, = ax.plot(line_x, line_y, linestyle=linestyle, color=color, alpha=0.7)
    return line

def handles_lables_for_legends(handles, labels, scatter, title, label_suffix, line, formula): 
    handles.append(scatter)
    labels.append(f'{title} ({label_suffix}) Data')
    handles.append(line)
    labels.append(formula)





#####Power Grid
def create_colormap_power_grid(vmin, vmax): 
        cmap = plt.cm.coolwarm
        norm = mcolors.LogNorm(vmin=vmin, vmax=vmax)  # Logarithmic normalization
        return norm, cmap

def add_colorbar_power_grid(fig, norm, cmap, ax): 
        cbar = fig.colorbar(plt.cm.ScalarMappable(norm=norm, cmap=cmap), ax=ax)
        cbar.set_label('Power (kW)')
        return cbar

def set_y_axis_power_grid(ax, power_range): 
    y_tick_positions = np.arange(1, len(power_range) * 2, 2) - 0.5  # Center y-ticks by shifting them down
    ax.set_yticks(y_tick_positions)
    #power_range = [20,50,80,125,150,175]
    ax.set_yticklabels([f'{power_range[i]} kW' for i in range(len(power_range))])
    ax.set_ylim(-0.5, len(y_tick_positions) * 2 - 0.5)


def set_x_axis_power_grid(ax, df): 
    total_columns = df.shape[1] - 1 + (df.shape[1] - 2) // 2  # Adjusted number of columns with gaps
    ax.set_xlim(-0.5, total_columns + 0.5)

    # Calculate adjusted x-tick positions (centered)
    col_positions = [i + (i // 2) + 0.5 for i in range(df.shape[1] - 1)]
    ax.set_xticks(col_positions)

    # Set x-tick labels to alternate between 'BoL' and 'EoL'
    ax.set_xticklabels(['BoL' if i % 2 == 0 else 'EoL' for i in range(df.shape[1] - 1)])

def create_second_x_axis_power_grid(ax, df):
    # Add secondary x-axis on top, with centered labels above each pair of boxes
    ax2 = ax.twiny()
    ax2.set_xlim(ax.get_xlim())  # Ensure the limits are the same

    # Determine the tick positions for the secondary x-axis
    positions = [1 + 3 * i for i in range((df.shape[1] - 2) // 2 + 1)]  # Positions for labels, adjust to the center
    ax2.set_xticks(positions)
    return ax2


def create_cells_power_grid(df, ax, cmap, norm): 
    for i in range(len(df)):
        for j in range(df.shape[1] - 1):
            col_pos = j + (j // 2)  # Calculate position with gaps after every second column
            cell_value = df.iloc[i, j + 1]
            if not pd.isna(cell_value):  # Check if the cell value is NaN
                y_pos = i * 2  # This matches the actual index directly without inverting
                ax.imshow([[cell_value]], aspect='auto', cmap=cmap, norm=norm,
                            extent=[col_pos, col_pos + 1, y_pos, y_pos + 1])



# %% PLOT: Power Grid, fancy
def annotate_boxes(ax, df, cell_width=1, cell_height=2):
    """
    Annotates each cell in the plot with its corresponding value, taking into account the gaps between columns.
    - ax: plt ax object of the plot (eg for 400 cells)
    - df: data of the plot (eg for 400 cells)
    - cell_width: int, size of the cell width
    - cell_height: int, size of the cell height
    """
    for i in range(len(df)):
        for j in range(df.shape[1] - 1):
            col_pos = j + (j // 2)  # Column position considering the gaps
            y_pos = i * cell_height-0.5  # Y position for each row
            
            # Get the cell value and handle NaN values
            cell_value = df.iloc[i, j + 1]
            
            if not pd.isna(cell_value):
                # Round the value to the nearest integer
                cell_value = round(cell_value)
                if cell_value == 0:
                    # Annotate the cell with "< 1"
                    ax.text(col_pos + cell_width / 2, y_pos + cell_height / 2, 
                            str("< 1"), color='black', ha='center', va='center')
                else:
                    # Annotate the cell with the value
                    ax.text(col_pos + cell_width / 2, y_pos + cell_height / 2, 
                            str(cell_value), color='black', ha='center', va='center')
            else:
                # if it is NaN make it an X
                cell_value = "X"
                
                # Annotate the cell with the value
                ax.text(col_pos + cell_width / 2, y_pos + cell_height / 2, 
                        str(cell_value), color='black', ha='center', va='center')
                




def format_data_for_plot(df, components, fl_set, power_range, weighting, eol_col='eol (t/f)', tolerance=0.01):
    """
    Formats the DataFrame for plotting by separating components based on the eol (t/f) column.
    Also checks if 'Power Constraint (kW)_bol' matches the stack power values within a tolerance and sets NaN if not.

    Parameters:
    - df (pd.DataFrame): The DataFrame to be formatted.
    - components (list): List of component columns to include in the formatted DataFrame.
    - eol_col (str): Name of the column containing 'True' or 'False' values to split by.
    - tolerance (float): The allowed tolerance factor for matching values.

    Returns:
    - pd.DataFrame: A formatted DataFrame for plotting.
    """
    # Create an empty DataFrame to store formatted data
    formatted_df = pd.DataFrame()
    #current = df["current_A (Value)"]
    df = df[(df['Flight Level (100x ft)'] == fl_set) & (df['Power Constraint (kW)'].isin(power_range)) & (df['weighting ([0,1])'] == weighting)]
    for component in components:
        # Filter out the columns related to the component
        component_df = df[[component, eol_col]].copy()

        # Separate the data based on eol (t/f)
        df_false = component_df[component_df[eol_col] == False].drop(columns=[eol_col]).reset_index(drop=True)
        df_false.columns = [f'{component}_bol']  # Rename the columns of df_false by adding _bol

        df_true = component_df[component_df[eol_col] == True].drop(columns=[eol_col]).reset_index(drop=True)
        df_true.columns = [f'{component}_eol']  # Rename the columns of df_true by adding _eol

        # Append to the formatted DataFrame
        formatted_df = pd.concat([formatted_df, df_false, df_true], axis=1)


    # Convert to numeric, coercing errors to NaN
    formatted_df['current_A (Value)_bol'] = pd.to_numeric(formatted_df['current_A (Value)_bol'], errors='coerce')
    formatted_df['current_A (Value)_eol'] = pd.to_numeric(formatted_df['current_A (Value)_eol'], errors='coerce')
    
    current_caint = 700  # Threshold value for current

    # Identify rows where current exceeds threshold for BOL and EOL
    bol_exceeds_threshold = formatted_df['current_A (Value)_bol'] > current_caint
    eol_exceeds_threshold = formatted_df['current_A (Value)_eol'] > current_caint

    # Set all component power values to NaN if their corresponding current exceeds the threshold
    for component in components:
        bol_col = f'{component}_bol'
        eol_col = f'{component}_eol'

        if bol_col in formatted_df.columns:
            formatted_df.loc[bol_exceeds_threshold, bol_col] = np.nan

        if eol_col in formatted_df.columns:
            formatted_df.loc[eol_exceeds_threshold, eol_col] = np.nan
    
    
    # Drop columns that should not be in the final DataFrame
    drop_columns = ['Power Constraint (kW)_eol','current_A (Value)_bol','current_A (Value)_eol']
    for drop_column in drop_columns:
        if drop_column in formatted_df.columns:
            formatted_df.drop(drop_column, axis=1, inplace=True)

    return formatted_df.abs()