#%% Imports
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.cm as cm

# %% PLOT: Compressormap from data
def plot_compressor_map(data, titles, fl_set, colors, markers, saving=True):
    """
    Plots the compressor map for multiple datasets in one plot.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - colors: List of colors for each dataset.
    - markers: List of markers for each dataset.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    
    fig, ax = plt.subplots(figsize=(12, 8))
    
    # Create a colormap and normalize for the color gradient
    norm = mcolors.Normalize(vmin=20, vmax=175)
    cmap = cm.ScalarMappable(norm=norm, cmap='viridis')
    
    # Iterate through the data, titles, colors, and markers
    for df, title, color, marker in zip(data, titles, colors, markers):
        df = df[(df["eol (t/f)"] == False) & (df['Flight Level (100x ft)'] == fl_set) & (df['current_A (Value)'] <= 700)] # filter out eol points, FL and points above 700 A 
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df["Compressor Corrected Air Flow (g/s)"]
                             , df["Compressor Pressure Ratio (-)"], 
                             c=df['System Power (kW)'], cmap='viridis', 
                             norm=norm, edgecolor='k', s=100, marker=marker, label=title)
        
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
    
    # Add title and a legend for the datasets
    ax.set_title(f'Compressor Pressure Ratio vs Corrected Air Flow, FL {fl_set}', fontsize=14)
    ax.legend(loc='best')
    fig.tight_layout()

    # Save the plot as a PNG file if saving is True
    if saving:
        plt.savefig('ideal_compressor_map_FL_{fl_set}.png')
    
    # Show the plot
    plt.show()