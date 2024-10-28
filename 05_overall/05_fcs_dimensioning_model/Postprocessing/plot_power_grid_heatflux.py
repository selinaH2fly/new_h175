# %% Imports:
import pandas as pd
import numpy as np
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt

from get_plot_settings import *

            


def plot_power_needs_heatflux(data, titles, fl_set, components, weighting, show_plot, power_range = [20,50,80,125,150,175], saving=True):
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
        names = ["Stack (+)", "Intercooler (+)", "Evaporator (-)", "Radiator (+)"]
        ax2.set_xticklabels([col.replace(' Heat Flux (kW)_bol', '').replace(' Power (kW)_eol', '') for col in df.columns[1::2]])
        ax2.set_xticklabels(names)
        #ax2.set_xlabel('Components', labelpad=10)
    
        # Add colorbar
        cbar = fig.colorbar(plt.cm.ScalarMappable(norm=norm, cmap=cmap), ax=ax)
        cbar.set_label('Power (kW)')
    
        # Set the title centered between the colored boxes
        title = f"Heat Flux of Components [kW], {title}, FL {fl_set}"
        ax.set_title(title, pad=30, loc='center')
    
        # Save and show the plot
        if saving:
            file_path = create_plot_save_directory(f'Component_Heat_Flux_{title}_weighting_{weighting}.png', weighting)
            plt.savefig(file_path, bbox_inches='tight')
        plt.show() if show_plot else plt.close()
