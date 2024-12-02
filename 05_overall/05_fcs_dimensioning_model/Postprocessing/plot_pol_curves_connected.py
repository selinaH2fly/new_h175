#%% Imports
import itertools
import pandas as pd
import matplotlib.pyplot as plt
from get_plot_settings import *


def filter_data(data, fl_set, weighting, eol, cell_counts,):
    # Filter data for the specified flight level and EOL condition
    return {
        cells: df[(df['Flight Level (100x ft)'] == fl_set) & 
                  (df['eol (t/f)'] == eol) & 
                  (df['weighting ([0,1])'] == weighting)]
        for df, cells in zip(data, cell_counts)
    }




def plot_data(ax, bol_data, eol_data, titles, colors, highlight_powers, markers_oL, labels):
        for count, title, color in zip(bol_data.keys(), titles, colors):
            bol_df, eol_df = bol_data[count], eol_data[count]

            # Plot BOL and EOL data
            scatters = []
            for i, df in enumerate([bol_df, eol_df]):
                scatter = ax.scatter(
                    df['current_A (Value)'], 
                    df['Cell Voltage (V)'], 
                    color=color, 
                    label= f'{title} {labels[i]}',
                    marker=markers_oL[i]
                )
            scatters.append(scatter)

            # Connect corresponding BOL and EOL points and annotate
            for power in highlight_powers:
                bol_highlight = bol_df[bol_df["Power Constraint (kW)"].between(power - 1e-3, power + 1e-3)]
                eol_highlight = eol_df[eol_df["Power Constraint (kW)"].between(power - 1e-3, power + 1e-3)]
                
                # Ensure both BOL is available for annotation:
                if not bol_highlight.empty:
                    bol_row = bol_highlight.iloc[0]
                    
                    # Determine annotation color (gray if current > 700 A)
                    if bol_row['current_A (Value)'] > 700:
                        annotation_color = 'gray'
                    else:
                        annotation_color = color
                    
                    # Annotate the points with power levels
                    ax.annotate(f'{bol_row["Power Constraint (kW)"]:.0f} kW', 
                                (bol_row['current_A (Value)'], bol_row['Cell Voltage (V)']),
                                textcoords="offset points", xytext=(0, 40), ha='center', color=annotation_color,
                                arrowprops=dict(facecolor=annotation_color, shrink=0.1))
    
                # Ensure both BOL and EOL points are available for connection
                if not bol_highlight.empty and not eol_highlight.empty:
                    bol_row = bol_highlight.iloc[0]
                    eol_row = eol_highlight.iloc[0]    
                    # Draw connection line
                    ax.plot([bol_row['current_A (Value)'], eol_row['current_A (Value)']],
                            [bol_row['Cell Voltage (V)'], eol_row['Cell Voltage (V)']],
                            color=color, alpha=0.5, linestyle='--')

                    
#%% PLOT: Polcurve bol vs eol connected points
def plot_polarization_curves_bol_eol(plot_params, params_general, show_plot, saving=True):
    """
    Plots the polarization curves for multiple datasets into one plot and connects bol and eol operating points.
    aka. Spaghetti Plot.
    Parameters:
    - df1: DataFrame with all the data.
    - titles: List of strings, corresponding to the titles for each dataset.
    - colors: List of strings, corresponding to the colors used inside of th eplot to distinglish different cellcounts.
    - fl_set: Int [0, 150] kft, specific FL at which the plot will be generated.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    data = params_general['data']
    fl_set = params_general['fl']
    weightings = params_general['weightings'] 
    titles = params_general['titles']
    markers = params_general['markers_oL']
    colors = params_general['colors']
    cells = params_general['cellcounts']

    labels = plot_params['label']
    # Highlight power levels
    highlight_powers = [20, 50, 80, 125, 150, 175]


    for weighting, fl in itertools.product(weightings,fl_set): 
        # Filter data for BOL and EOL
        bol_data = filter_data(data, fl, weighting, eol=False, cell_counts=cells)
        eol_data = filter_data(data, fl, weighting, eol=True, cell_counts=cells)

        if all(df.empty for df in bol_data.values() and eol_data.values()):
            print(f"No data available for Bol Eol Polarization Curve at fl {fl} and weighting {weighting}. Skipping plot.")
            continue  # Skip plotting if no data exists
        # Create the plot
        fig, ax = plt.subplots(figsize=(12, 8))
        plot_data(ax, bol_data, eol_data, titles, colors, highlight_powers, markers, labels)
        
        # Set title and axis labels
        plot_params.update({'title': f'System Polarization Curve - EoL vs BoL, FL {fl}, Weighting {weighting}'})
        configure_axes(ax, **plot_params)

        ax.axvspan(700, plot_params['x_lim'][1], color='red', alpha=0.2)
        ax.legend(loc='upper right')

        # Save and show plot
        if saving and ax.collections:
            file_path = create_plot_save_directory((f'bol_eol_polarization_curve_fl_{fl}_weighting_{weighting}.png'), weighting, fl)
            plt.savefig(file_path, bbox_inches='tight')
        plt.show() if show_plot and ax.collections else plt.close()

