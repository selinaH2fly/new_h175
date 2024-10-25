#%% Imports
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
def plot_compressor_map(data, titles, colors, markers, weighting, show_plot, saving=True, mode="bol"):
    """
    Plots the compressor map for multiple datasets in one plot.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - colors: List of colors for each dataset.
    - markers: List of markers for each dataset.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    # Filter option for eol or bol plot: 
    # If sizing for eol, Turbine and Compressor power tend to increase, and thus the estimated cathode mass would be higher.
    
    # Determine the filter mode
    filter_mode = (mode == "eol")
    mode_name = "EoL" if filter_mode else "BoL"
        
    power_set = 160 #kW should be in line with one "Power Constraint" value of the df
    FL_set = 120
    N = 3 # Specify scaling factor N
    
    scaling_factors = [1 - i/N for i in range(N)]  # Progressive shrinking from 1 to 0
                
    fig, axs = plt.subplots(nrows=1, ncols=3, figsize=(17, 8))
    axs = axs.flatten()  # Flatten the 2D array of axes to easily iterate through
    
    # Create a colormap and normalize for the color gradient
    norm = mcolors.Normalize(vmin=20, vmax=175)
    cmap = cm.ScalarMappable(norm=norm, cmap='viridis')
    
    # empty list for plot legend icons
    legend_handles  = []
        
    # Iterate through the data, titles, colors, and markers
    for i, (df, title, color, marker) in enumerate(zip(data, titles, colors, markers)):
        ax = axs[i]  # Select the appropriate subplot
        
        # Set labels and grid
        ax.set_xlabel('Corrected Air Flow [g/s]')
        ax.set_ylabel('Compressor Pressure Ratio [-]')
        ax.grid(True)
        ax.set_ylim([1, 6])
        ax.set_xlim([0,300])
        
        # Set the subfigure title
        ax.set_title(titles[i])  # Add subfigure title for each subplot
        
        df = df[(df["eol (t/f)"] == filter_mode) & 
                (df['current_A (Value)'] <= 700) &
                (df['weighting ([0,1])'] == weighting)] # filter out eol points, FL and points above 700 A 
        
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
        center_point = df[(df["Power Constraint (kW)"] == power_set) & (df['Flight Level (100x ft)'] == FL_set)][["Compressor Corrected Air Flow (g/s)", "Compressor Pressure Ratio (-)"]]
        
        # If no point is found, skip scaling and plotting the hulls
        if center_point.empty:
            print(f"Compressot map: No center point found for dataset '{title}', skipping scaled hulls.")
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
    cbar = plt.colorbar(cmap, ax=ax)
    cbar.set_label('System Power [kW]')
    
    # Manually set colorbar ticks from 20 to 175 in 25 steps
    cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
    cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

    # Add title and a legend for the datasets
    fig.suptitle(f'Compressor Pressure Ratio vs Corrected Air Flow, {mode_name}', fontsize=14)

    # Create a custom legend
    fig.legend(legend_handles, [handle.get_label() for handle in legend_handles], loc='lower center', ncol=3, bbox_to_anchor=(0.5, -0.1), fontsize='medium', title='Legend')
    
    fig.tight_layout()

    # Save the plot as a PNG file if saving is True
    if saving:
        file_path = create_plot_save_directory(f'ideal_compressor_map_{mode_name}.png', weighting)
        plt.savefig(file_path, bbox_inches='tight')
    
    # Show the plot
    plt.show() if show_plot else plt.close()
