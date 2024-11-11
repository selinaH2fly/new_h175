# %% Imports:
import pandas as pd
import numpy as np
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt

from get_plot_settings import *

            


def plot_power_needs_heatflux(plot_params, data, titles, fl_set, weighting, show_plot, saving=True):
    """
    Plot a heatmap-like representation of power needs by components, with specific formatting.

    Parameters:
    - data (list of pd.DataFrame): List of DataFrames where each DataFrame represents different conditions.
    - titles (list of str): List of titles for each DataFrame.
    - saving (bool): If True, saves the plot to a file. Defaults to False.
    """
    
    for df1, title in zip(data, titles):
        #Formate the data to the needed formate:
        df = format_data_for_plot(df1, plot_params['components'], fl_set, plot_params['power_range'], weighting, eol_col='eol (t/f)')
        
        if df.empty:
            print(f"No data available for Heat Flux {title} at FL {fl_set} or for weighting {weighting}. Skipping plot.")
            continue  # Skip plotting if no data exists   

        # Set up the figure and axis
        fig, ax = plt.subplots(figsize=(10, 8))
    
        # Define the colormap and normalization
        norm, cmap = create_colormap_power_grid(plot_params['vmin'], plot_params['vmax'])
        
        # Adjust y-ticks to be centered on the colored boxes
        # Y-Axis should always have 6 entries, regarding of the data (20-175 kW)
        set_y_axis_power_grid(ax, plot_params['power_range'])
        
        # Plot each cell with a gap between every second column
        create_cells_power_grid(df, ax, cmap, norm)

        
        annotate_boxes(ax, df, cell_width=1, cell_height=2)
        
        set_x_axis_power_grid(ax, df)
        ax2 = create_second_x_axis_power_grid(ax, df)
    
        # Adjust labels for the secondary x-axis
        ax2.set_xticklabels([col.replace(' Heat Flux (kW)_bol', '').replace(' Power (kW)_eol', '') for col in df.columns[1::2]])
        ax2.set_xticklabels(plot_params['names'])
        #ax2.set_xlabel('Components', labelpad=10)
    
        # Add colorbar
        add_colorbar_power_grid(fig, norm, cmap, ax)

    
        # Set the title centered between the colored boxes
        title = f"Heat Flux of Components [kW], {title}, FL {fl_set}"
        ax.set_title(title, pad=30, loc='center')
    
        # Save and show the plot
        if saving and ax.collections:
            file_path = create_plot_save_directory(f'Component_Heat_Flux_{title}_weighting_{weighting}.png', weighting)
            plt.savefig(file_path, bbox_inches='tight')
        plt.show() if show_plot and ax.texts else plt.close()
