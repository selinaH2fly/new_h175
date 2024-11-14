import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
import sys
import os

from get_plot_settings import *





# Import parameters.py from the parent directory
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from parameters import Optimization_Parameters
_params_optimization = Optimization_Parameters()


# Plot the optimized cathode inlet rel. humidity for each dataset
def plot_optimized_parameters(plot_params, data, data_doe, titles, fl_set, markers_oL, weighting, show_plot, saving=True):
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
    var = plot_params['opt_parameters']
    y_range = plot_params['yranges']
    #For plotting the dashed lines we need to know which plot we are doing
    num_columns = data_doe.shape[1]
    
    for df, title in zip(data, titles):

        df = filter_data_by_f1_and_weight(df, fl_set, weighting)
        if df.empty:
            print(f"No data available for Optimized Operating Parameters {var} {title} at FL {fl_set} or for weighting {weighting}. Skipping plot.")
            continue  # Skip plotting if no data exists
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Create a colormap and normalize for the color gradient
        norm, cmap = create_colormap(plot_params['vmin'], plot_params['vmax'], cmap='viridis')

        
        # Separate BoL (Beginning of Life) and EoL (End of Life) points
        df_bol, df_eol = seperate_bol_eol(df)

        
        # plot min/max bounds according to parameters.py
        lower_bound = ax.axhline(min(_params_optimization.bounds[num_columns-1]), color='black', linestyle='--', label=f'{var} Bounds', zorder=0)
        upper_bound = ax.axhline(max(_params_optimization.bounds[num_columns-1]), color='black', linestyle='--', zorder=0)
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter_bol = ax.scatter(df_bol['current_A (Value)'], 
                                 df_bol[plot_params['opt_parameters']], 
                                 c=df_bol['System Power (kW)'], 
                                 cmap='viridis', norm=norm, 
                                 edgecolor='k', s=100, marker=markers_oL[0], label='BoL', zorder=1)

        # Plot EoL points (use squares for distinction)
        scatter_eol = ax.scatter(df_eol['current_A (Value)'], 
                                 df_eol[plot_params['opt_parameters']], 
                                 c=df_eol['System Power (kW)'], 
                                 cmap='viridis', norm=norm, 
                                 edgecolor='k', s=100, marker=markers_oL[1], label='EoL', zorder=1)
        
        # Plot DOE data in the background
        scatter_eol = ax.scatter(data_doe["current_A"], 
                                 data_doe.iloc[:,-1], c="k", edgecolor='k', 
                                 s=100, marker="o", label='DOE data', zorder=0, alpha=0.2)
        

        # Add colorbar for the gradient
        add_colorbar(cmap, ax)
        # Add a red shaded area from 700 A to 800 A
        ax.axvspan(700, 800, color='red', alpha=0.3)

        # Set title and labels
        plot_params.update({'title': f'Optimized Operating Parameters: {var}, FL {fl_set}, {title}'})
        plot_params.update({'y_label': f'{var}'})
        plot_params.update({'y_lim': [y_range[0], y_range[1]]})

        configure_axes(ax, **plot_params)        
        fig.tight_layout()
        # Create a custom legend (optional)
        create_legend(ax, markers_oL)

        # # Annotate points where 'eol (t/f)' is True
        # for i in df[df["eol (t/f)"] == True].index:
        #     ax.annotate('EoL', 
        #                 (df['current_A (Value)'][i], df['cathode_rh_in_perc (Value)'][i]), 
        #                 textcoords="offset points", 
        #                 xytext=(2, -20), 
        #                 ha='center',
        #                 fontsize=11, 
        #                 color='black')
    
        
        # Save the plot as a PNG file if saving is True
        if saving and ax.collections:
            directory = 'Optimized_Operating_Parameters'
            file_path = create_plot_save_directory(f'{var}_{title}_weighting_{weighting}.png', weighting, directory)
            plt.savefig(file_path, bbox_inches='tight')
            
        plt.show() if show_plot and ax.collections else plt.close()
