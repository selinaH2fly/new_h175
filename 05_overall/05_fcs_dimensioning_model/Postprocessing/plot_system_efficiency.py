# %% Imports:
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# %% PLOT: system efficiency (aka Flade plot)
def plot_system_efficiency(data, titles, colors, fl_set, markers_oL, weighting, show_plot, saving=True):
    """
    Plot of system power vs (system power/hydrogen sonsumption) with polynomial fit.
    aka. Flade Plot.
    
    - data : List of DataFrames for different cellcounts.
    - titles: List of strings, corresponding to the titles for each dataset.
    - colors: List of strings, corresponding to the colors used inside of th eplot to distinglish different cellcounts.
    - fl_set: Int [0, 150] kft, specific FL at which the plot will be generated.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    
    fig, ax = plt.subplots(figsize=(12, 8))
    fig.tight_layout()
    # Store handles and labels for manual legend creation
    handles = []
    labels = []

    for df, title, color in zip(data, titles, colors):
        df = df[(df['Flight Level (100x ft)'] == fl_set) & (df["weighting ([0,1])"] == weighting)]
        for filter_eol, linestyle, marker, label_suffix in [(False, '-', markers_oL[0], 'BoL'), (True, '--', markers_oL[1], 'EoL')]:
            # Apply the filter based on the function argument
            filtered_df = df[(df["eol (t/f)"] == filter_eol) 
                             &(df["current_A (Value)"] <= 700)]
            
            # Scatter plot for each dataset TODO: magic 33.3 to params
            scatter = ax.scatter(filtered_df['System Power (kW)'], 
                                 (filtered_df['System Power (kW)'] / (filtered_df['Hydrogen Supply Rate (g/s)']* 33.33 * 3600))*1000, 
                                 s=100, edgecolor='k', color=color, marker=marker)
            
            # Extract x and y data
            x = filtered_df['System Power (kW)']
            y = (filtered_df['System Power (kW)'] / (filtered_df['Hydrogen Supply Rate (g/s)']* 33.33 * 3600))*1000
            
            # Construct the design matrix [x^2, x, 1]
            A = np.vstack([x**2, x**1, x**0]).T
            
            # Perform least squares fitting
            coeffs, _, _, _ = np.linalg.lstsq(A, y, rcond=None)
            
            # Create the polynomial function
            def poly(x):
                return coeffs[0] * x**2 + coeffs[1] * x + coeffs[2]
            
            # Plot the polynomial fit
            line_x = np.linspace(x.min(), x.max(), 500)
            line_y = poly(line_x)
            line, = ax.plot(line_x, line_y, linestyle=linestyle, color=color, alpha=0.7)
            
            # Add the polynomial formula to the legend
            formula = f'{title} ({label_suffix}) Fit: {coeffs[0]:.2e}x² + {coeffs[1]:.2e}x + {coeffs[2]:.2e}'
            
            
            # Collect handles and labels for the legend
            handles.append(scatter)
            labels.append(f'{title} ({label_suffix}) Data')
            handles.append(line)
            labels.append(formula)

    # Create the legend
    ax.legend(handles, labels, loc='best')

    # Set title and labels
    ax.set_title(f'System Efficiency vs System Net Power, FL {fl_set}')
    ax.set_xlabel('System Power [kW]')
    ax.set_ylabel('System Efficiency [-]')
    ax.grid(True)
    
    if saving:
        plt.savefig(f'System_Efficiency_vs_Power_weighting_{weighting}.png', bbox_inches='tight')
    plt.show() if show_plot else plt.close()
