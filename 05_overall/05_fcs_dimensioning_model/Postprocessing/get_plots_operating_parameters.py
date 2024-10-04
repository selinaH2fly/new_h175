import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
import sys
import os

# Import parameters.py from the parent directory
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from parameters import Optimization_Parameters
_params_optimization = Optimization_Parameters()


# Plot the optimized cathode inlet rel. humidity for each dataset
def plot_optimized_parameters(data, data_doe, titles, fl_set, markers_oL, var, yrange, saving=True):
    """
    Plots the optimized operating paramter for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - fl_set: Integer, the flight level to be plotted.
    - markers_oL: which marker is used for bol and eol plots
    - var: which optimized variable will be ploted. 
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    parameter_list = ["current_A (Value)",
                      'cathode_rh_in_perc (Value)',
                      'stoich_cathode (Value)',
                      'pressure_cathode_in_bara (Value)',
                      'temp_coolant_inlet_degC (Value)',
                      'temp_coolant_outlet_degC (Value)']
    #For plotting the dashed lines we need to know which plot we are doing
    num_columns = data_doe.shape[1]
    
    for df, title in zip(data, titles):
        df = df[df['Flight Level (100x ft)'] == fl_set]
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Create a colormap and normalize for the color gradient
        norm = mcolors.Normalize(vmin=20, vmax=175)
        cmap = cm.ScalarMappable(norm=norm, cmap='viridis')
        
        # Separate BoL (Beginning of Life) and EoL (End of Life) points
        df_bol = df[df["eol (t/f)"] == False]
        df_eol = df[df["eol (t/f)"] == True]
        
        # plot min/max bounds according to parameters.py
        lower_bound = ax.axhline(min(_params_optimization.bounds[num_columns-1]), color='black', linestyle='--', label=f'{var} Bounds', zorder=0)
        upper_bound = ax.axhline(max(_params_optimization.bounds[num_columns-1]), color='black', linestyle='--', zorder=0)
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter_bol = ax.scatter(df_bol['current_A (Value)'], 
                                 df_bol[var], 
                                 c=df_bol['System Power (kW)'], 
                                 cmap='viridis', norm=norm, 
                                 edgecolor='k', s=100, marker=markers_oL[0], label='BoL', zorder=1)

        # Plot EoL points (use squares for distinction)
        scatter_eol = ax.scatter(df_eol['current_A (Value)'], 
                                 df_eol[var], 
                                 c=df_eol['System Power (kW)'], 
                                 cmap='viridis', norm=norm, 
                                 edgecolor='k', s=100, marker=markers_oL[1], label='EoL', zorder=1)
        
        # Plot DOE data in the background
        scatter_eol = ax.scatter(data_doe["current_A"], 
                                 data_doe.iloc[:,-1], c="k", edgecolor='k', 
                                 s=100, marker="o", label='DOE data', zorder=0, alpha=0.2)
        
        # Add colorbar for the gradient
        cbar = plt.colorbar(cmap, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Manually set colorbar ticks from 20 to 175 in 25 steps, excluding 25
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

        # Add a red shaded area from 700 A to 800 A
        ax.axvspan(700, 800, color='red', alpha=0.3)

        # Set title and labels
        ax.set_title(f'Optimized Operating Parameters: {var}, FL {fl_set}, {title}', fontsize=14)
        ax.set_xlabel('Current [A]')
        ax.set_ylabel(f'{var}')
        ax.grid(True)
        ax.set_xlim([0, 800])
        ax.set_ylim([yrange[0], yrange[1]])
        fig.tight_layout()

        # # Annotate points where 'eol (t/f)' is True
        # for i in df[df["eol (t/f)"] == True].index:
        #     ax.annotate('EoL', 
        #                 (df['current_A (Value)'][i], df['cathode_rh_in_perc (Value)'][i]), 
        #                 textcoords="offset points", 
        #                 xytext=(2, -20), 
        #                 ha='center',
        #                 fontsize=11, 
        #                 color='black')
        #Create a custom legend (optional)
        legend_bol = mlines.Line2D([], [], color='none', marker=markers_oL[0], 
                                      markerfacecolor='none', markeredgecolor='black', 
                                      markersize=11, linestyle='None', label='System Power BoL [kW]')
        legend_eol = mlines.Line2D([], [], color='none', marker=markers_oL[1],
                                      markerfacecolor='none', markeredgecolor='black', 
                                      markersize=11, linestyle='None', label='System Power EoL [kW]')
        
        ax.legend(handles=[legend_bol,legend_eol], loc='best')
    
        
        # Save the plot as a PNG file if saving is True
        if saving:
            plt.savefig(f'{var}_{title}.png')