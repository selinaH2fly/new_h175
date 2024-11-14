import itertools
import os
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.colors as mcolors
import matplotlib.cm as cm
from scipy.spatial import ConvexHull

from get_plot_settings import *



def plot_h2_vs_mass(plot_params, params_general, show_plot, saving=True):
    """
    Plot of H2 supply vs system power with convex hull envelope around all points,
    connected dashed lines for the same power levels, and colored scatter points
    based on 'System Power (kW)'.
    
    Parameters:
    - data : List of pandas DataFrames for different cell counts.
    - titles: List of strings, corresponding to the titles for each dataset.
    - colors: List of strings, corresponding to the colors used inside the plot to distinguish different cell counts.
    - fl_set: Int [0, 150] kft, specific Flight Level at which the plot will be generated.
    - saving: Boolean, if True, saves the plots as PNG files.
    """

    data = params_general['data']
    fl = params_general['fl']
    cellcounts = params_general['cellcounts']
    weightings = params_general['weightings']  # Only plot weightings 0 and 1
    titles = params_general['titles']

    markers = ['o', 'D'] # Circle for weighting 0, Diamond for weighting 1

    colors = params_general['colors']


    num_plots = len(data)  # Determine the number of required subplots

    # Handle case where all DataFrames are empty
    if not num_plots:
        print("No non-empty datasets available for plotting.")
        return



    eol = False  # Assuming eol remains constant in all cases
    for fl in fl:
    #for fl in fl:
    
        fig, axs = plt.subplots(1, num_plots, figsize=(6 * num_plots, 6))  # Dynamically adjust figure size
        if num_plots == 1:
            axs = [axs]  # Convert to list if only one subplot is present
        for ax, df, title, color in zip(axs, data, titles, colors):   
            print(f"fl: {fl},  title {title}, color {color}")

            df_filtered = df[(df['Flight Level (100x ft)'] == fl) & (df['eol (t/f)'] == eol)]
            
            # Set up colormap for 'System Power (kW)'
            norm, cmap = create_colormap(plot_params['vmin'], plot_params['vmax'], cmap='viridis')

            if df_filtered.empty:
                print(f"No data available for H2_Supply_Comparison {title} at FL {fl}. Skipping subplot.")
                continue  # Skip plotting if no data exists

            all_points_x = []
            all_points_y = []
            all_power = []  # Collect 'System Power (kW)' for coloring

        
            for weighting, marker in zip(weightings, markers):
                df_weighted = df_filtered[df_filtered["weighting ([0,1])"] == weighting]
                
                if df_weighted.empty:
                    print(f"No data available for weighting {weighting} in {title}.")
                    continue

                # Scatter plot with color based on 'System Power (kW)'
                scatter = ax.scatter(df_weighted['System Mass (kg)'], 
                                    df_weighted['Hydrogen Supply Rate (g/s)'], 
                                    s=100, edgecolor='k', 
                                    c=df_weighted['System Power (kW)'],  # Color based on power
                                    cmap='viridis', norm=norm, 
                                    marker=marker, label=f'Weighting {weighting}',
                                    zorder=2)
            # Collect points for convex hull
            all_points_x.extend(df_weighted['System Mass (kg)'].values)
            all_points_y.extend(df_weighted['Hydrogen Supply Rate (g/s)'].values)
            all_power.extend(df_weighted['System Power (kW)'].values)

            # Convert the collected points to numpy arrays for convex hull calculation
            all_points_x = np.array(all_points_x)
            all_points_y = np.array(all_points_y)

            # Compute and plot convex hull over all points from both weightings
            plot_convex_hull(ax, all_points_x, all_points_y, color)

            # Connect points with the same power level using dashed lines
            connect_power_levels(ax, df_filtered)

            # Set title, labels, and legend
            plot_params.update({'title': f'{title} Cells, FL {fl}'})
            configure_axes(ax, **plot_params)

            ax.legend([f"Optimized: {plot_params['label'][0]}", f"Optimized: {plot_params['label'][1]}"], loc='lower right')

        # Add colorbar for the gradient
        add_colorbar(cmap, ax)
        
        # Adjust layout after adding all subplots
        plt.tight_layout(pad=2.0)
        
        if saving and ax.collections :
            file_path = create_plot_save_directory(f'H2_Supply_Comparison_FL{fl}_weighting_{weighting}.png', weighting)
            plt.savefig(file_path, bbox_inches='tight', dpi=300)
            
        plt.show() if show_plot and ax.collections else plt.close()



         
            
  
def plot_convex_hull(ax, x, y, color):
    """
    Plots the convex hull around the combined points for weightings 0 and 1
    and shades the enclosed area.
    
    Parameters:
    - ax: The axes on which to plot.
    - x: The x-data (System Mass).
    - y: The y-data (Hydrogen Supply Rate).
    - color: The color for the hull and shading.
    """
    if len(x) < 3 or len(y) < 3:
        print("Not enough points to form a convex hull.")
        return
    
    # Combine x and y into a 2D array for ConvexHull calculation
    points = np.column_stack((x, y))
    hull = ConvexHull(points)
    
    # Extract the hull vertices
    hull_points = points[hull.vertices]
    
    # Plot the convex hull boundary
    ax.plot(hull_points[:, 0], hull_points[:, 1], linestyle=':', color=color, alpha=0.6,zorder=1)
    
    # Shade the convex hull area
    ax.fill(hull_points[:, 0], hull_points[:, 1], color=color, alpha=0.3, zorder=1)

def connect_power_levels(ax, df):
    """
    Connects points with the same 'Power Constraint (kW)' value using dashed lines.
    
    Parameters:
    - ax: The axes on which to plot the connections.
    - df: The DataFrame containing the data points to connect.
    """
    power_levels = df['Power Constraint (kW)'].unique()
    
    # For each power level, connect the points
    for power in power_levels:
        df_power = df[df['Power Constraint (kW)'] == power]
        
        if len(df_power) > 1:  # Ensure there are at least 2 points to connect
            ax.plot(df_power['System Mass (kg)'], 
                    df_power['Hydrogen Supply Rate (g/s)'], 
                    linestyle='--', color='k', alpha=0.8, zorder=1)