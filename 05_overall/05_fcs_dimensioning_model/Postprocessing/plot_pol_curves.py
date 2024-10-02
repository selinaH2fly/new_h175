#%% Imports
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.lines as mlines

# %% PLOT: Polcurve single BoL/EoL
def plot_polarization_curves(data, titles, fl_set, saving=True):
    """
    Plots the polarization curves for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    for df, title in zip(data, titles):
        # Filter data for the specified flight level
        df = df[df['Flight Level (100x ft)'] == fl_set]
        
        # Create the figure and axis
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Set up colormap for 'System Power (kW)'
        norm = mcolors.Normalize(vmin=20, vmax=175)
        cmap = cm.ScalarMappable(norm=norm, cmap='viridis')
        
        # Separate BoL (Beginning of Life) and EoL (End of Life) points
        df_bol = df[df["eol (t/f)"] == False]
        df_eol = df[df["eol (t/f)"] == True]

        # Plot BoL points (use circles by default)
        scatter_bol = ax.scatter(df_bol['current_A (Value)'], 
                                 df_bol['Cell Voltage (V)'], 
                                 c=df_bol['System Power (kW)'], 
                                 cmap='viridis', norm=norm, 
                                 edgecolor='k', s=100, label='BoL')

        # Plot EoL points (use squares for distinction)
        scatter_eol = ax.scatter(df_eol['current_A (Value)'], 
                                 df_eol['Cell Voltage (V)'], 
                                 c=df_eol['System Power (kW)'], 
                                 cmap='viridis', norm=norm, 
                                 edgecolor='k', s=100, marker='s', label='EoL')

        # Add colorbar for the gradient
        cbar = plt.colorbar(cmap, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Set custom colorbar ticks
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

        # Add a shaded region to highlight a specific current range
        ax.axvspan(700, 800, color='red', alpha=0.3)

        # Set title and axis labels
        ax.set_title(f'System Polarization Curve, FL {fl_set}, {title}', fontsize=14)
        ax.set_xlabel('Current [A]')
        ax.set_ylabel('Cell Voltage [V]')
        ax.grid(True)
        ax.set_xlim([0, 800])
        ax.set_ylim([0, 1.25])

        # Annotate EoL points with text
        for i, row in df_eol.iterrows():
            ax.annotate('EoL', 
                        (row['current_A (Value)'], row['Cell Voltage (V)']),
                        textcoords="offset points", xytext=(2, -20), 
                        ha='center', fontsize=11, color='black')

        # Create a custom legend (optional)
        legend_circle = mlines.Line2D([], [], color='none', marker='o', 
                                      markerfacecolor='none', markeredgecolor='black', 
                                      markersize=11, linestyle='None', label='System Power BoL [kW]')
        legend_square = mlines.Line2D([], [], color='none', marker='s', 
                                      markerfacecolor='none', markeredgecolor='black', 
                                      markersize=11, linestyle='None', label='System Power EoL [kW]')
        
        ax.legend(handles=[legend_circle,legend_square], loc='best')

        # Adjust layout and save the plot if necessary
        fig.tight_layout()
        if saving:
            plt.savefig(f'{title}_polarization_curve.png')

        # Show the plot
        plt.show()