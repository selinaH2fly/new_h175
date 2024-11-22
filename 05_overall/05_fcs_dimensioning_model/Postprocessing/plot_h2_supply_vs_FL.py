# %% Imports:
import pandas as pd
import matplotlib.colors as mcolors
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from get_plot_settings import *




# %% PLOT: H2 supply over flight level all in one
def plot_h2_supply_vs_FL(plot_params,params_general, show_plot, saving=True, mode="eol"):
    """
    Plot of system power vs (system power/hydrogen sonsumption) with polynomial fit.
    
    - df1: DataFrame with all the data.
    - markers: List of strings for plt icons. 
    - fl_set: Int [0, 150] kft, specific FL at which the plot will be generated.
    - saving: Boolean, if True, saves the plots as PNG files.
    - mode: string "eol" or "bol", setting a filter to see eol or bol data.
    """
    data = params_general['data']
    fl_max = params_general['fl_max']
    weightings = params_general['weightings'] 
    cells = params_general['cellcounts']
    colors = params_general['colors']
    markers = params_general['markers']
    titles = params_general['titles']


    # Define power levels to highlight
    highlight_powers = [125, 150, 175]
    for weighting in weightings:
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
        # Loop through each cell count and plot the data
        for df, icon, title in zip(data, markers, titles):

            #Filter the DF for currents in range and the filter omde
            df_filtered =   df[(df["current_A (Value)"] <= 700) & (df["eol (t/f)"] == filter_mode) & (df["weighting ([0,1])"] == weighting)]

            if df_filtered.empty:
                print(f"No data available for H2 Supply vs FL for current_A <= 700, for {mode_name} and weighting {weighting}. Skipping plot.")
                continue 
            #filter dataframe after cell count and 125-+, 150+-, and 175+-
            df_filtered1 = df_filtered[(df_filtered['Power Constraint (kW)'].between(highlight_powers[0] - 1e-3, highlight_powers[0] + 1e-3) |
                                df_filtered['Power Constraint (kW)'].between(highlight_powers[1] - 1e-3, highlight_powers[1] + 1e-3) |
                                df_filtered['Power Constraint (kW)'].between(highlight_powers[2] - 1e-3, highlight_powers[2] + 1e-3))]

            if df_filtered1.empty:
                print(f"No data available for H2 Supply vs FL for Power Constraint (kW). Skipping plot.")
                continue            
            # Scatter plot with color based on 'System Power (kW)'
            ax.scatter(df_filtered1['Flight Level (100x ft)'], df_filtered1['Hydrogen Supply Rate (g/s)'], 
                                c=df_filtered1['System Power (kW)'], cmap='viridis',norm=norm, edgecolor='k', s=100, marker=icon, label=f'{title}')

            # Create custom legend handles
            handles = [plt.Line2D([0], [0], marker=marker, color='w', markerfacecolor='k', markersize=10, linestyle='') for marker in markers]
            labels = [f'{cell} Cells' for cell in cells]
            

            # Set title and axis labels
            plot_params.update({'title': f'System Hydrogen Supply Rate vs FL for Different Cell Counts ({mode_name}), Weighting {weighting}'})

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
        if saving and ax.collections:
            file_path = create_plot_save_directory(f'H2_supply_vs_flightlevel_{mode}_weighting_{weighting}.png', weighting=weighting)
            plt.savefig(file_path, bbox_inches='tight')
        plt.show() if show_plot and ax.collections else plt.close()





