import sys
import os
import matplotlib.pyplot as plt
from scipy.interpolate import griddata
import numpy as np

# Add the parent directory to sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

# Now import the Compressor_Parameters class from parameters.py
from parameters import Compressor_Parameters

def plot_compressor_map(operating_point_pressure_ratio, operating_point_corrected_massflow_g_s):
    """
    Plots the compressor map with efficiency contours and highlights the specified operating point
    using the original unevenly spaced grid.
    
    Parameters:
    - operating_point_pressure_ratio (float): The pressure ratio of the operating point.
    - operating_point_corrected_massflow_g_s (float): The corrected mass flow of the operating point in g/s.
    """
    
    # Create an instance of the Compressor_Parameters class
    cp = Compressor_Parameters()

    # Extract the original grid points and efficiency values
    corrected_massflows = cp.compressor_map_VSEC15["corrected_massflow_g_s"]
    pressure_ratios = cp.compressor_map_VSEC15["pressure_ratio"]
    efficiencies = cp.compressor_map_VSEC15["efficiency"]

    # Flatten the original grid points and efficiency values for interpolation
    points = np.array([corrected_massflows.flatten(), pressure_ratios.flatten()]).T
    values = efficiencies.flatten()

    # Interpolate the efficiency at the target pressure ratio and mass flow
    efficiency_interp = griddata(np.array([corrected_massflows.flatten(), pressure_ratios.flatten()]).T, efficiencies.flatten(),
                                 (operating_point_corrected_massflow_g_s, operating_point_pressure_ratio), method='linear', rescale=True)

    # Create the plot
    plt.figure(figsize=(10, 8))

    # Contour plot for efficiency over pressure ratio and corrected mass flow using the original data
    contours = plt.contourf(corrected_massflows, pressure_ratios, efficiencies, levels=30, cmap="viridis")
    plt.colorbar(contours, label="Efficiency")

    # Contour lines for efficiency
    contour_lines = plt.contour(corrected_massflows, pressure_ratios, efficiencies, levels=30, colors='black', linestyles='--')
    plt.clabel(contour_lines, inline=True, fontsize=10, fmt="%.2f")

    # Highlight the operating point
    plt.plot(operating_point_corrected_massflow_g_s, operating_point_pressure_ratio, 'ro', markersize=10,
             label=f'Operating Point\nPR={operating_point_pressure_ratio}, Massflow={operating_point_corrected_massflow_g_s} g/s, Interpolated Efficiency: {efficiency_interp:.2f}')

    plt.grid(True)

    # Labels and title
    plt.title("Compressor Map: Pressure Ratio vs Corrected Mass Flow with Efficiency Contours")
    plt.xlabel("Corrected Mass Flow (g/s)")
    plt.ylabel("Pressure Ratio")
    plt.legend()

    # Display the plot
    plt.show()


# Example usage of the function:
plot_compressor_map(1.6, 60.0)
plot_compressor_map(1.6, 70.0)
plot_compressor_map(1.6, 80.0)
plot_compressor_map(1.6, 90.0)

