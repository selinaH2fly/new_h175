# %% Imports:
import pandas as pd
import matplotlib.colors as mcolors
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from get_plot_settings import *




# %% PLOT: H2 supply over flight level all in one
def plot_h2_supply_vs_FL(plot_params, df1, markers, fl_max, weighting, show_plot, saving=True, mode="eol"):
    """
    Plot of system power vs (system power/hydrogen sonsumption) with polynomial fit.
    
    - df1: DataFrame with all the data.
    - markers: List of strings for plt icons. 
    - fl_set: Int [0, 150] kft, specific FL at which the plot will be generated.
    - saving: Boolean, if True, saves the plots as PNG files.
    - mode: string "eol" or "bol", setting a filter to see eol or bol data.
    """
    # List of cell counts and corresponding icons
    cells = [400, 455, 500]
    markers = ["o", "v", "s"]

    # Define power levels to highlight
    highlight_powers = [125, 150, 175]

    # Create a figure and axis
    fig, ax = plt.subplots(figsize=(12, 8))
    fig.tight_layout()
    
    # Create a colormap and normalize for the color gradient
    norm = mcolors.Normalize(plot_params['vmin'], plot_params['vmax'])
    # cmap = cm.ScalarMappable(norm=norm, cmap='plasma')
    # Plasma colormap for the three specific levels
    cmap = plt.get_cmap('viridis')
    colors = [cmap(mcolors.Normalize(plot_params['vmin'], plot_params['vmax'])(power)) for power in highlight_powers]
        
    filter_mode, mode_name = getMode(mode)

    #Filter the DF for currents in range and the filter omde
    df1 = df1[(df1["current_A (Value)"] <= 700) & (df1["eol (t/f)"] == filter_mode) & (df1["weighting ([0,1])"] == weighting)]
    if df1.empty:
        print(f"No data available for H2 Supply vs FL for current_A <= 700 or weighting {weighting}. Skipping plot.")
        return  # Skip plotting if no data exists   
    # Loop through each cell count and plot the data
    for cell, icon in zip(cells, markers):
        #filter dataframe after cell count and 125-+, 150+-, and 175+-
        df_filtered = df1[(df1['Specified Cell Count'] == cell) 
                          &(df1['Power Constraint (kW)'].between(highlight_powers[0] - 1e-3, highlight_powers[0] + 1e-3) |
                            df1['Power Constraint (kW)'].between(highlight_powers[1] - 1e-3, highlight_powers[1] + 1e-3) |
                            df1['Power Constraint (kW)'].between(highlight_powers[2] - 1e-3, highlight_powers[2] + 1e-3))]

        # Scatter plot with color based on 'System Power (kW)'
        ax.scatter(df_filtered['Flight Level (100x ft)'], df_filtered['Hydrogen Supply Rate (g/s)'], 
                             c=df_filtered['System Power (kW)'], cmap='viridis',norm=norm, edgecolor='k', s=100, marker=icon, label=f'{cell} Cells')

         # Create custom legend handles
        handles = [plt.Line2D([0], [0], marker=marker, color='w', markerfacecolor='k', markersize=10, linestyle='') for marker in markers]
        labels = [f'{cell} Cells' for cell in cells]
        

        # Set title and axis labels
        plot_params.update({'title': f'System Hydrogen Supply Rate vs FL for Different Cell Counts ({mode_name})'})
        plot_params.update({'x_lim':[-1, fl_max + 1]})
        plot_params.update({'y_lim': [1, 5]})
        configure_axes(ax, **plot_params)


        # Add legend
        ax.legend(handles, labels, loc='upper left')
        
        # Set x-range from 0 to 140 in steps of 30, and include 150
        x_ticks = list(range(0, fl_max + 1, 30))
        ax.set_xticks(x_ticks)


        
        # Position the boxes vertically in the middle with spacing and labels below
        box_x = 1.02  # Position on the right side, outside the plot
        box_y_start = 0.7  # Start the boxes a bit lower to center them vertically
        box_width = 0.05
        box_height = 0.08
        box_spacing = 0.15  # Increase the spacing between boxes
        text_spacing = 0.02
        
        for i, (power, color) in enumerate(zip(reversed(highlight_powers), reversed(colors))):
            rect = patches.Rectangle((box_x, box_y_start - i * (box_height + box_spacing)), box_width, box_height, linewidth=1, edgecolor='k', facecolor=color, transform=ax.transAxes, clip_on=False)
            ax.add_patch(rect)
            ax.text(box_x + box_width / 2, box_y_start - i * (box_height + box_spacing) - text_spacing, f'{power} kW', va='top', ha='center', transform=ax.transAxes, fontsize=12)
        
    # Save and show the plot
    if saving:
        file_path = create_plot_save_directory(f'H2_supply_vs_flightlevel_{mode}_weighting_{weighting}.png', weighting)
        plt.savefig(file_path, bbox_inches='tight')
    plt.show() if show_plot and ax.collections else plt.close()





