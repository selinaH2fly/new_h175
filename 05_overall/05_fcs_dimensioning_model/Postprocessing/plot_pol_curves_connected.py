#%% Imports
import pandas as pd
import matplotlib.pyplot as plt

#%% PLOT: Polcurve bol vs eol connected points
def plot_polarization_curves_bol_eol(df1, titles, colors, fl_set, markers_oL, weighting, show_plot, saving=True):
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
    
    def filter_data(df, eol, cell_counts):
        # Filter data for the specified flight level and EOL condition
        return {
            count: df[(df['Flight Level (100x ft)'] == fl_set) & 
                      (df['Specified Cell Count'] == count) & 
                      (df['eol (t/f)'] == eol) &
                      (df['weighting ([0,1])'] == weighting)]
            for count in cell_counts
        }

    def plot_data(ax, bol_data, eol_data, titles, colors, highlight_powers):
        for count, title, color in zip(bol_data.keys(), titles, colors):
            bol_df, eol_df = bol_data[count], eol_data[count]

            # Plot BOL and EOL data
            ax.scatter(bol_df['current_A (Value)'], bol_df['Cell Voltage (V)'], color=color, label=f'{title}, BoL', marker=markers_oL[0])
            ax.scatter(eol_df['current_A (Value)'], eol_df['Cell Voltage (V)'], color=color, label=f'{title}, EoL', marker=markers_oL[1])

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
                    
    # Highlight power levels
    highlight_powers = [20, 50, 80, 125, 150, 175]
    cell_counts = [400, 455, 500]

    # Filter data for BOL and EOL
    bol_data = filter_data(df1, eol=False, cell_counts=cell_counts)
    eol_data = filter_data(df1, eol=True, cell_counts=cell_counts)

    # Create the plot
    fig, ax = plt.subplots(figsize=(12, 8))
    plot_data(ax, bol_data, eol_data, titles, colors, highlight_powers)

    # Add red shaded area and labels
    ax.axvspan(700, 1000, color='red', alpha=0.2)
    ax.set(title=f"System Polarization Curve - EoL vs BoL, FL {fl_set}", xlabel='Current [A]', xlim=[0, 1000], ylabel='Cell Voltage [V]', ylim=[0.3, 1])
    ax.grid(True)
    ax.legend(loc='upper right')
    ax.set_xlim([0, 800])
    # Save and show plot
    if saving:
        plt.savefig('bol_eol_polarization_curve.png', bbox_inches='tight')
    plt.show() if show_plot else plt.close()
