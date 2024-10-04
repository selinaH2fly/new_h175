#%% Imports
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.lines as mlines
import matplotlib.cm as cm
import numpy as np
from scipy.spatial import ConvexHull

# %% PLOT: Compressormap from data
def plot_compressor_map(data, titles, colors, markers, saving=True, mode="bol"):
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
    
    if mode == "eol":
        filter_mode = True
        mode_name = "EoL"
    elif mode == "bol":
        filter_mode = False
        mode_name = "BoL"
            
    fig, ax = plt.subplots(figsize=(12, 8))
    
    # Create a colormap and normalize for the color gradient
    norm = mcolors.Normalize(vmin=20, vmax=175)
    cmap = cm.ScalarMappable(norm=norm, cmap='viridis')
    
    # empty list for plot legend icons
    legend_icons  = []
    
    # Iterate through the data, titles, colors, and markers
    for df, title, color, marker in zip(data, titles, colors, markers):
        df = df[(df["eol (t/f)"] == filter_mode) & (df['current_A (Value)'] <= 700)] # filter out eol points, FL and points above 700 A 
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df["Compressor Corrected Air Flow (g/s)"]
                             , df["Compressor Pressure Ratio (-)"], 
                             c=df['System Power (kW)'], cmap='viridis', 
                             norm=norm, edgecolor='k', s=100, marker=marker, label=title)
        
        # Prepare data for Convex Hull (x and y coordinates)
        points = np.column_stack((df["Compressor Corrected Air Flow (g/s)"], df["Compressor Pressure Ratio (-)"]))
        
        # Compute the convex hull
        hull = ConvexHull(points)
        
        # Plot the convex hull as a polygon by connecting points
        for simplex in hull.simplices:
            ax.plot(points[simplex, 0], points[simplex, 1], color=color, linestyle ='--', lw=2, zorder=0, alpha=0.5)  #dashed line for hull edges
            
        legend_icons.append( mlines.Line2D([], [], color='none', marker=marker, 
                                      markerfacecolor='none', markeredgecolor=color, 
                                      markersize=11, linestyle='None', label=title))
        
    # Add colorbar for the gradient
    cbar = plt.colorbar(cmap, ax=ax)
    cbar.set_label('System Power [kW]')
    
    # Manually set colorbar ticks from 20 to 175 in 25 steps
    cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
    cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

    # Set labels and grid
    ax.set_xlabel('Corrected Air Flow [g/s]')
    ax.set_ylabel('Compressor Pressure Ratio [-]')
    ax.grid(True)
    ax.set_ylim([1, 8])
    ax.set_xlim([0,300])
    
    # Add title and a legend for the datasets
    ax.set_title(f'Compressor Pressure Ratio vs Corrected Air Flow, {mode_name}', fontsize=14)
    
    # Create a custom legend (optional)
    ax.legend(handles=[legend for legend in legend_icons], loc='best')    
    
    fig.tight_layout()

    # Save the plot as a PNG file if saving is True
    if saving:
        plt.savefig(f'ideal_compressor_map_{mode_name}.png')
    
    # Show the plot
    plt.show()