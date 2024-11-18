#%% Imports
import itertools
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.lines as mlines
import matplotlib.cm as cm
import numpy as np
from scipy.spatial import ConvexHull, Delaunay

from get_plot_settings import *

# Function to scale convex hull towards a specific point
def scale_convex_hull(hull_points, center_point, scale_factor):
    # Move points towards the center by scale factor
    scaled_points = center_point + scale_factor * (hull_points - center_point)
    return scaled_points

# %% PLOT: Compressormap from data
def plot_compressor_map(plot_params, params_general, show_plot, saving=True, mode="bol"):
    """
    Plots the compressor map for multiple datasets in one plot.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - colors: List of colors for each dataset.
    - markers: List of markers for each dataset.
    - saving: Boolean, if True, saves the plots as PNG files.
    """

    data = params_general['data']
    fl_set = params_general['fl']
    weightings = params_general['weightings'] 
    colors = params_general['colors']
    markers = params_general['markers']
    titles = params_general['titles']


    # Filter option for eol or bol plot: 
    # If sizing for eol, Turbine and Compressor power tend to increase, and thus the estimated cathode mass would be higher.
    
    # Determine the filter mode
    filter_mode, mode_name = getMode(mode)

        
    power_set = 160 #kW should be in line with one "Power Constraint" value of the df
    N = 3 # Specify scaling factor N
    
    scaling_factors = [1 - i/N for i in range(N)]  # Progressive shrinking from 1 to 0
    non_empty_data = [df for df in data if not df.empty]
                

    
    # Create a colormap and normalize for the color gradient
    norm, cmap = create_colormap(plot_params['vmin'], plot_params['vmax'], cmap='viridis')

    
    # empty list for plot legend icons
    legend_handles  = []
    for weighting, fl in itertools.product(weightings, fl_set):     
        fig, axs = plt.subplots(nrows=1, ncols=len(non_empty_data), figsize=(17, 8))
        axs = axs.flatten()  # Flatten the 2D array of axes to easily iterate through
        # Iterate through the data, titles, colors, and markers
        for i, (df, title, color, marker) in enumerate(zip(data, titles, colors, markers)):
            ax = axs[i]  # Select the appropriate subplot
            
            # Set title and axis labels
            plot_params.update({'title': titles[i]}) # Add subfigure title for each subplot

            configure_axes(ax, **plot_params)   

            
            df = df[(df["eol (t/f)"] == filter_mode) & 
                    (df['current_A (Value)'] <= 700) &
                    (df['weighting ([0,1])'] == weighting)] # filter out eol points, FL and points above 700 A 
            if df.empty:
                print(f"No data available for ideal Compressor Map {title} for current_A <= 700, {mode_name} or weighting {weighting}. Skipping plot.")
                continue  # Skip plotting if no data exists
            # Scatter plot with color based on 'System Power (kW)'
            scatter = ax.scatter(df["Compressor Corrected Air Flow (g/s)"]
                                , df["Compressor Pressure Ratio (-)"], 
                                c=df['System Power (kW)'], cmap='viridis', 
                                norm=norm, edgecolor='k', s=100, marker=marker, label=title)
            
            # Collect legend handles for the current dataset
            legend_handles.append(mlines.Line2D([], [], color='none', marker=marker, 
                                                markerfacecolor='none', markeredgecolor=color, 
                                                markersize=11, linestyle='None', label=title))
            
            
            # Prepare data for Convex Hull (x and y coordinates)
            points = np.column_stack((df["Compressor Corrected Air Flow (g/s)"], df["Compressor Pressure Ratio (-)"]))
            
            # Compute the convex hull
            hull = ConvexHull(points)
            
            # Find the point to collapse towards, e.g. 100 kW
            center_point = df[(df["Power Constraint (kW)"] == power_set) & (df['Flight Level (100x ft)'] == fl)][["Compressor Corrected Air Flow (g/s)", "Compressor Pressure Ratio (-)"]]
            
            # If no point is found, skip scaling and plotting the hulls
            if center_point.empty:
                print(f"Compressor map: No center point found for dataset '{title}', FL {fl}, Weighting {weighting}', skipping scaled hulls.")
                # Plot the convex hull as a polygon by connecting points
                for simplex in hull.simplices:
                    ax.plot(points[simplex, 0], points[simplex, 1], color=color, linestyle ='--', lw=2, zorder=0, alpha=0.5)  #dashed line for hull edges
                continue  # Skip to the next dataset
            
            center_point = center_point.values[0] # extract the values into np array
            ax.scatter(center_point[0], center_point[1], color="red", marker="X", edgecolor='black', s=200)
            # Check if the point is inside the convex hull
            hull_delaunay = Delaunay(points[hull.vertices])  # Pass the vertices of the convex hull
            
            if not hull_delaunay.find_simplex(center_point) >= 0:
                raise ValueError("Compressor map: The specified point is outside the convex hull!")
                
            # Plot the original convex hull and scaled versions
            for scale in scaling_factors:
                # Scale the convex hull towards the center point
                scaled_hull_points = center_point + scale * (points[hull.vertices] - center_point)
                
                # Plot the scaled hull by connecting points
                ax.plot(np.append(scaled_hull_points[:, 0], scaled_hull_points[0, 0]),
                        np.append(scaled_hull_points[:, 1], scaled_hull_points[0, 1]),
                        color=color, linestyle='--', lw=1.5, alpha=1)
                
                
        # Add colorbar for the gradient
        add_colorbar(cmap, ax)

        # Add title and a legend for the datasets
        fig.suptitle(f'Compressor Pressure Ratio vs Corrected Air Flow, {mode_name}, FL {fl}, Weighting {weighting}', fontsize=14)

        # Create a custom legend
        fig.legend(legend_handles, [handle.get_label() for handle in legend_handles], loc='lower center', ncol=3, bbox_to_anchor=(0.5, -0.1), fontsize='medium', title='Legend')
        legend_handles.clear()           
        fig.tight_layout()

        # Save the plot as a PNG file if saving is True
        if saving and ax.collections:
            file_path = create_plot_save_directory(f'ideal_compressor_map_{mode_name}_fl_{fl}_weighting{weighting}.png', weighting, fl)
            plt.savefig(file_path, bbox_inches='tight')
        
        # Show the plot
        plt.show() if show_plot and ax.collections else plt.close()
