import sys
import os
import matplotlib.pyplot as plt
from scipy.interpolate import griddata
import numpy as np

# Add the parent directory to sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

# Now import the Compressor_Parameters class from parameters.py
from parameters import Compressor_Parameters

def evaluate_compressor_map(operating_point_pressure_ratio, operating_point_corrected_massflow_g_s):
    """
    Plots the compressor map with efficiency contours and highlights the specified operating point.

    Parameters:
    - operating_point_pressure_ratio (float): The pressure ratio of the operating point.
    - operating_point_corrected_massflow_g_s (float): The corrected mass flow of the operating point in g/s.
    """
    
    # Create an instance of the Compressor_Parameters class
    cp = Compressor_Parameters()

    # Flatten the 2D arrays to 1D
    pressure_ratio_flat = cp.compressor_map_VSEC15["pressure_ratio"].flatten()
    massflow_flat = cp.compressor_map_VSEC15["corrected_massflow_g_s"].flatten()
    efficiency_flat = cp.compressor_map_VSEC15["efficiency"].flatten()

    # Combine the pressure ratio and mass flow into a single array of coordinates
    points = np.array([pressure_ratio_flat, massflow_flat]).T

    # Interpolate the efficiency at the target pressure ratio and mass flow
    efficiency_interp = griddata(points, efficiency_flat, (operating_point_pressure_ratio, operating_point_corrected_massflow_g_s), method='linear')

    # Create the plot
    plt.figure(figsize=(10, 8))

    # Contour plot for efficiency over pressure ratio and corrected mass flow
    contours = plt.contourf(cp.compressor_map_VSEC15["corrected_massflow_g_s"], cp.compressor_map_VSEC15["pressure_ratio"], cp.compressor_map_VSEC15["efficiency"], levels=15, cmap="viridis")
    plt.colorbar(contours, label="Efficiency")

    # Contour lines for efficiency
    contour_lines = plt.contour(cp.compressor_map_VSEC15["corrected_massflow_g_s"], cp.compressor_map_VSEC15["pressure_ratio"], cp.compressor_map_VSEC15["efficiency"], levels=15, colors='black', linestyles='--')
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
evaluate_compressor_map(1.5, 70.0)
