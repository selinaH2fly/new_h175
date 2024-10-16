import sys
import os
import matplotlib.pyplot as plt
from scipy.interpolate import griddata
import numpy as np
from scipy.spatial import ConvexHull, Delaunay

# Add the parent directory to sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

# Now import the CompressorParameters class from parameters.py
from parameters import Compressor_Parameters

def plot_compressor_map(operating_point_pressure_ratio, operating_point_corrected_massflow_g_s):
    """
    Plots the compressor map with efficiency contours and highlights the specified operating point
    using the original unevenly spaced grid.
    
    Parameters:
    - operating_point_pressure_ratio (float): The pressure ratio of the operating point.
    - operating_point_corrected_massflow_g_s (float): The corrected mass flow of the operating point in g/s.
    """
    
    # Create an instance of the CompressorParameters class
    cp = Compressor_Parameters()

    # Extract the original grid points and efficiency values
    corrected_massflows = cp.compressor_map_VSEC15["corrected_massflow_g_s"]
    pressure_ratios = cp.compressor_map_VSEC15["pressure_ratio"]
    efficiencies = cp.compressor_map_VSEC15["efficiency"]

    # Flatten the input arrays
    flattened_massflow = corrected_massflows.flatten()
    flattened_pressure_ratio = pressure_ratios.flatten()
    flattened_efficiency = efficiencies.flatten()

    # Combine massflow and pressure_ratio into points
    points = np.array([flattened_massflow, flattened_pressure_ratio]).T

    # Compute the convex hull
    hull = ConvexHull(points)
    
    # Get the points that define the convex hull
    hull_points = points[hull.vertices]
    
    # Generate a grid that spans the convex hull
    grid_massflow, grid_pressure_ratio = np.meshgrid(
        np.linspace(hull_points[:, 0].min(), hull_points[:, 0].max(), 100),
        np.linspace(hull_points[:, 1].min(), hull_points[:, 1].max(), 100)
    )

    # Interpolate efficiency values over the grid
    grid_efficiency = griddata(points, flattened_efficiency, (grid_massflow, grid_pressure_ratio), method='linear', rescale=True)


    # Interpolate the efficiency at the target pressure ratio and mass flow
    efficiency_interp = griddata(np.array([flattened_massflow, flattened_pressure_ratio]).T, flattened_efficiency,
                                 (operating_point_corrected_massflow_g_s, operating_point_pressure_ratio), method='linear', rescale=True)

    # Create the plot
    plt.figure(figsize=(10, 8))

    for simplex in hull.simplices:
            plt.plot(points[simplex, 0], points[simplex, 1], 'gray', linestyle='--', linewidth=2)

    plt.grid(True)

    # Contour plot for efficiency over pressure ratio and corrected mass flow
    contours = plt.contourf(grid_massflow, grid_pressure_ratio, grid_efficiency, levels=30, cmap="viridis")
    plt.colorbar(contours, label="Efficiency")

    # Contour lines for efficiency
    contour_lines = plt.contour(grid_massflow, grid_pressure_ratio, grid_efficiency, levels=30, colors='black', linestyles='--')
    plt.clabel(contour_lines, inline=True, fontsize=10, fmt="%.2f")

    # Highlight the operating point
    # plt.plot(operating_point_corrected_massflow_g_s, operating_point_pressure_ratio, 'ro', markersize=10,
    #          label=f'Operating Point\nPR={operating_point_pressure_ratio}, Massflow={operating_point_corrected_massflow_g_s} g/s, Interpolated Efficiency: {efficiency_interp:.2f}')

     # Labels and title
    plt.title("Compressor Map: Pressure Ratio vs Corrected Mass Flow")
    plt.xlabel("Corrected Mass Flow (g/s)")
    plt.ylabel("Pressure Ratio")
    # plt.legend(loc='upper left')

    # Display the plot
    # plt.show()
    plt.savefig('compressor_map.png', bbox_inches='tight')

# Example usage:
# clipped_massflow, clipped_pressure_ratio, clipped_efficiency = clip_compressor_map_to_convex_hull(massflow, pressure_ratio, efficiency)


# Example usage of the function:
plot_compressor_map(3.06, 115.60)


