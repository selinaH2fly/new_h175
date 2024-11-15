#%% Imports
import itertools
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.lines as mlines

from get_plot_settings import *



# %% PLOT: Polcurve single BoL/EoL
def plot_polarization_curves(plot_params, params_general, show_plot, saving=True):
    """
    Plots the polarization curves for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    data = params_general['data']
    fl_set = params_general['fl']
    weightings = params_general['weightings'] 
    titles = params_general['titles']

    markers = params_general['markers_oL']
    colors = params_general['colors']
    for weighting, fl in itertools.product(weightings,fl_set): 
        print(f"weighting: {weighting}, fl: {fl}")
        for df, title in zip(data, titles):
            # Filter data for the specified flight level
            df = filter_data_by_f1_and_weight(df, fl, weighting)
            
            if df.empty:
                print(f"No data available for System Polarization Curve {title} at FL {fl} and weighting {weighting}. Skipping plot.")
                continue  # Skip plotting if no data exists

            # Create the figure and axis
            fig, ax = plt.subplots(figsize=(12, 8))
            
            # Set up colormap for 'System Power (kW)'
            norm, cmap = create_colormap(plot_params['vmin'], plot_params['vmax'], cmap='viridis')
            
            # Separate BoL (Beginning of Life) and EoL (End of Life) points
            df_bol, df_eol = seperate_bol_eol(df)

            # Plot BoL points (use circles by default)
                        # Plot BoL points (use circles by default)
            """ for marker, label in zip(markers, plot_params['label']): 
                ax.scatter(df_bol['current_A (Value)'], 
                                        df_bol['Cell Voltage (V)'], 
                                        c=df_bol['System Power (kW)'], 
                                        cmap='viridis', norm=norm, 
                                        edgecolor='k', s=100, marker=marker, label=label) """
            scatter_bol = ax.scatter(df_bol['current_A (Value)'], 
                                    df_bol['Cell Voltage (V)'], 
                                    c=df_bol['System Power (kW)'], 
                                    cmap='viridis', norm=norm, 
                                    edgecolor='k', s=100, marker=markers[0], label=plot_params['label'][0])

            # Plot EoL points (use squares for distinction)
            scatter_eol = ax.scatter(df_eol['current_A (Value)'], 
                                    df_eol['Cell Voltage (V)'], 
                                    c=df_eol['System Power (kW)'], 
                                    cmap='viridis', norm=norm, 
                                    edgecolor='k', s=100, marker=markers[1], label=plot_params['label'][1])

            # Add colorbar for the gradient
            add_colorbar(cmap, ax)


            # Add a shaded region to highlight a specific current range
            ax.axvspan(700, 800, color='red', alpha=0.3)

            # Set title and axis labels
            plot_params.update({'title': f'System Polarization Curve, FL {fl}, weighting {weighting}, {title}'})

            configure_axes(ax, **plot_params)        
            # Create a custom legend (optional)
            create_legend(ax, markers)




            # # Annotate EoL points with text
            # for i, row in df_eol.iterrows():
            #     ax.annotate('EoL', 
            #                 (row['current_A (Value)'], row['Cell Voltage (V)']),
            #                 textcoords="offset points", xytext=(2, -20), 
            #                 ha='center', fontsize=11, color='black')



            # Adjust layout and save the plot if necessary
            fig.tight_layout()
            if saving and ax.collections:
                file_path = create_plot_save_directory((f'{title}_polarization_curve_fl_{fl}_weighting_{weighting}.png'), weighting)
                plt.savefig(file_path, bbox_inches='tight')

            # Show the plot
            plt.show() if show_plot and ax.collections else plt.close()
