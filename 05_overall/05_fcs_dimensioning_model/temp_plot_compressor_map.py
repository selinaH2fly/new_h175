import matplotlib.pyplot as plt
import numpy as np
from parameters import Compressor_Parameters

# Function to plot the compressor map
def calculate_speed_grid(compressor_map):
    """
    Generate a speed grid by interpolating speed based on pressure ratio and mass flow.
    This example assumes a simple linear relationship.
    """
    PR = compressor_map['PR']
    mass_flow = compressor_map['mass_flow']
    speed_lines = compressor_map['speed_lines']

    # Create a speed grid assuming linear interpolation between speed lines
    speed_grid = np.zeros((len(mass_flow), len(PR)))

    for i, mf in enumerate(mass_flow):
        for j, pr in enumerate(PR):
            # Simple interpolation: more sophisticated logic may be required for real maps
            if pr < 1.4:
                speed_grid[i, j] = speed_lines[0]
            elif pr < 1.6:
                speed_grid[i, j] = speed_lines[1]
            else:
                speed_grid[i, j] = speed_lines[2]
                
    return speed_grid

# Function to plot the compressor map with both efficiency and speed contours
def plot_compressor_map_with_speed(compressor_map):
    PR = compressor_map['PR']
    mass_flow = compressor_map['mass_flow']
    efficiency_map = compressor_map['efficiency_map']
    speed_grid = calculate_speed_grid(compressor_map)

    # Combine efficiency maps for the contour plot
    combined_efficiency = np.zeros_like(speed_grid)
    for speed in compressor_map['speed_lines']:
        combined_efficiency += compressor_map['efficiency_map'][speed]
    combined_efficiency /= len(compressor_map['speed_lines'])  # Averaging for simplification

    fig, ax = plt.subplots(figsize=(10, 8))

    # Contour plot for efficiency
    efficiency_contours = ax.contourf(PR, mass_flow, combined_efficiency, levels=15, cmap="viridis")
    fig.colorbar(efficiency_contours, ax=ax, label="Efficiency")

    # Contour lines for speed
    speed_contours = ax.contour(PR, mass_flow, speed_grid, levels=compressor_map['speed_lines'], colors='white', linestyles='--')
    ax.clabel(speed_contours, inline=True, fontsize=10, fmt='%d RPM')

    ax.set_title("Compressor Map: Efficiency and Speed Contours")
    ax.set_xlabel("Pressure Ratio (PR)")
    ax.set_ylabel("Mass Flow Rate (kg/s)")
    
    plt.show()

# Plot the compressor map
compressor_params = Compressor_Parameters()
compressor_map = compressor_params.compressor_map

plot_compressor_map_with_speed(compressor_map)