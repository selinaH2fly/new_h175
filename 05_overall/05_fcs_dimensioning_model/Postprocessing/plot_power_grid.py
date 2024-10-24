# %% Imports:
import pandas as pd
import numpy as np
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt

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

    return formatted_df

def plot_power_needs(data, titles, fl_set, components, weighting, show_plot, saving=True, power_range = [20,50,80,125,150,175]):
    """
    Plot a heatmap-like representation of power needs by components, with specific formatting.

    Parameters:
    - data (list of pd.DataFrame): List of DataFrames where each DataFrame represents different conditions.
    - titles (list of str): List of titles for each DataFrame.
    - saving (bool): If True, saves the plot to a file. Defaults to False.
    """
    
    for df1, title in zip(data, titles):
        #Formate the data to the needed formate:
        df = format_data_for_plot(df1, components, fl_set, power_range, weighting, eol_col='eol (t/f)')
        
        # Set up the figure and axis
        fig, ax = plt.subplots(figsize=(10, 8))
    
        # Define the colormap and normalization
        cmap = plt.cm.coolwarm
        norm = mcolors.LogNorm(vmin=0.1, vmax=225)  # Logarithmic normalization
        
        # Adjust y-ticks to be centered on the colored boxes
        # Y-Axis should always have 6 entries, regarding of the data (20-175 kW)
        y_tick_positions = np.arange(1, 6 * 2, 2) - 0.5  # Center y-ticks by shifting them down
        ax.set_yticks(y_tick_positions)
        #power_range = [20,50,80,125,150,175]
        ax.set_yticklabels([f'{power_range[i]} kW' for i in range(len(power_range))])
        ax.set_ylim(-0.5, len(y_tick_positions) * 2 - 0.5)
        
        # Plot each cell with a gap between every second column
        for i in range(len(df)):
            for j in range(df.shape[1] - 1):
                col_pos = j + (j // 2)  # Calculate position with gaps after every second column
                cell_value = df.iloc[i, j + 1]
                if not pd.isna(cell_value):  # Check if the cell value is NaN
                    y_pos = i * 2  # This matches the actual index directly without inverting
                    ax.imshow([[cell_value]], aspect='auto', cmap=cmap, norm=norm,
                              extent=[col_pos, col_pos + 1, y_pos, y_pos + 1])
        
        annotate_boxes(ax, df, cell_width=1, cell_height=2)
        
        # Adjust xlim to ensure the first cell is fully inside the plot
        total_columns = df.shape[1] - 1 + (df.shape[1] - 2) // 2  # Adjusted number of columns with gaps
        ax.set_xlim(-0.5, total_columns + 0.5)
    
        # Calculate adjusted x-tick positions (centered)
        col_positions = [i + (i // 2) + 0.5 for i in range(df.shape[1] - 1)]
        ax.set_xticks(col_positions)
    
        # Set x-tick labels to alternate between 'BoL' and 'EoL'
        ax.set_xticklabels(['BoL' if i % 2 == 0 else 'EoL' for i in range(df.shape[1] - 1)])
    
        # Add secondary x-axis on top, with centered labels above each pair of boxes
        ax2 = ax.twiny()
        ax2.set_xlim(ax.get_xlim())  # Ensure the limits are the same
    
        # Determine the tick positions for the secondary x-axis
        positions = [1 + 3 * i for i in range((df.shape[1] - 2) // 2 + 1)]  # Positions for labels, adjust to the center
        ax2.set_xticks(positions)
    
        # Adjust labels for the secondary x-axis
        names = ["Compressor (+)", "Turbine (-)", "Reci. Pump (+)", "Coolant Pump (+)", "Stack (-)"]
        #ax2.set_xticklabels([col.replace(' Power (kW)_bol', '').replace(' Power (kW)_eol', '') for col in df.columns[1::2]])
        ax2.set_xticklabels(names)
        
        # Add colorbar
        cbar = fig.colorbar(plt.cm.ScalarMappable(norm=norm, cmap=cmap), ax=ax)
        cbar.set_label('Power (kW)')
    
        # Set the title centered between the colored boxes
        title = f"Power Consumption of Components [kW], {title}, FL {fl_set}"
        ax.set_title(title, pad=30, loc='center')
    
        # Save and show the plot
        if saving:
            plt.savefig(f"Component_Powers_{title}.png", bbox_inches='tight')
 
        plt.show() if show_plot else plt.close()
