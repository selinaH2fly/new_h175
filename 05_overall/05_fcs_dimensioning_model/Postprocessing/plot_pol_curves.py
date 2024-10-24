#%% Imports
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.lines as mlines

from get_plot_settings import *


# %% PLOT: Polcurve single BoL/EoL
def plot_polarization_curves(data, titles, fl_set, markers_oL, weighting, show_plot, saving=True):
    """
    Plots the polarization curves for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - saving: Boolean, if True, saves the plots as PNG files.
    """

    for df, title in zip(data, titles):
        # Filter data for the specified flight level
        df = filter_data_by_flight_level(df, fl_set, weighting)
        
        # Create the figure and axis
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Set up colormap for 'System Power (kW)'
        norm, cmap = create_colormap()
        
        # Separate BoL (Beginning of Life) and EoL (End of Life) points
        df_bol, df_eol = seperate_bol_eol(df)

        # Plot BoL points (use circles by default)
        scatter_bol = ax.scatter(df_bol['current_A (Value)'], 
                                 df_bol['Cell Voltage (V)'], 
                                 c=df_bol['System Power (kW)'], 
                                 cmap='viridis', norm=norm, 
                                 edgecolor='k', s=100, marker=markers_oL[0], label='BoL')

        # Plot EoL points (use squares for distinction)
        scatter_eol = ax.scatter(df_eol['current_A (Value)'], 
                                 df_eol['Cell Voltage (V)'], 
                                 c=df_eol['System Power (kW)'], 
                                 cmap='viridis', norm=norm, 
                                 edgecolor='k', s=100, marker=markers_oL[1], label='EoL')

        # Add colorbar for the gradient
        add_colorbar(cmap, ax)


        # Add a shaded region to highlight a specific current range
        ax.axvspan(700, 800, color='red', alpha=0.3)

        # Set title and axis labels
        configure_axes(ax, f'System Polarization Curve, FL {fl_set}, {title}', 'Current [A]', [0, 800], 'Cell Voltage [V]',[0, 1.25])
        # Create a custom legend (optional)
        create_legend(ax, markers_oL)




        # # Annotate EoL points with text
        # for i, row in df_eol.iterrows():
        #     ax.annotate('EoL', 
        #                 (row['current_A (Value)'], row['Cell Voltage (V)']),
        #                 textcoords="offset points", xytext=(2, -20), 
        #                 ha='center', fontsize=11, color='black')



        # Adjust layout and save the plot if necessary
        fig.tight_layout()
        if saving:
            plt.savefig(f'{title}_polarization_curve.png')

        # Show the plot
        plt.show() if show_plot else plt.close()