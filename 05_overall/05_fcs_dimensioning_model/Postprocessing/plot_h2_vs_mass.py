import matplotlib.pyplot as plt
import numpy as np
import matplotlib.colors as mcolors
import matplotlib.cm as cm
from scipy.spatial import ConvexHull

def plot_h2_vs_mass(data, titles, colors, fl_set, saving=True):
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
    
    weightings = [0, 1]  # Only plot weightings 0 and 1
    markers = ['o', 'D']  # Circle for weighting 0, Diamond for weighting 1
    
    fig, axs = plt.subplots(1, 3, figsize=(18, 6))
    
    eol = False  # Assuming eol remains constant in all cases
    label = ["H2 supply", "system mass"]

    for ax, df, title, color in zip(axs, data, titles, colors):
        df_filtered = df[(df['Flight Level (100x ft)'] == fl_set) &
                         (df['eol (t/f)'] == eol)]
        
        if df_filtered.empty:
            print(f"No data available for {title} at FL {fl_set}. Skipping subplot.")
            continue  # Skip plotting if no data exists

        all_points_x = []
        all_points_y = []
        all_power = []  # Collect 'System Power (kW)' for coloring

        # Set up colormap for 'System Power (kW)'
        norm = mcolors.Normalize(vmin=20, vmax=175)
        cmap = cm.ScalarMappable(norm=norm, cmap='viridis')
        
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
        ax.set_title(f'{title} Cells, FL {fl_set}')
        ax.set_xlabel('System Mass [kg]')
        ax.set_xlim([90, 135])
        ax.set_ylabel('Hydrogen Supply Rate [g/s]')
        ax.grid(True)
        ax.legend([f"Optimized: {label[0]}", f"Optimized: {label[1]}"], loc='lower right')

    # Add colorbar for the gradient
    cbar = plt.colorbar(cmap, ax=ax)
    cbar.set_label('System Power [kW]')
    
    # Set custom colorbar ticks
    cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
    cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])
    
    # Adjust layout after adding all subplots
    plt.tight_layout(pad=2.0)
    
    if saving:
        plt.savefig(f'H2_Supply_Comparison_FL{fl_set}.png', bbox_inches='tight')
    plt.show()

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