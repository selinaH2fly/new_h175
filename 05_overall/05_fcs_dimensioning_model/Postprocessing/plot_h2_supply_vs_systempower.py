# %% Imports:
import itertools
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from get_plot_settings import *



def print_example_between_points(data): 
    if len(data) == 3:
            _H2_400 = data[0][(data[0]["Flight Level (100x ft)"] == 120) & 
                            (data[0]["Power Constraint (kW)"] == 125) &
                            (data[0]["eol (t/f)"] == False)]["Hydrogen Supply Rate (g/s)"].iloc[0]
        
            _H2_500 = data[2][(data[2]["Flight Level (100x ft)"] == 120) & 
                            (data[2]["Power Constraint (kW)"] == 125) &
                            (data[2]["eol (t/f)"] == False)]["Hydrogen Supply Rate (g/s)"].iloc[0]
            
            _H2_500_eol = data[2][(data[2]["Flight Level (100x ft)"] == 120) & 
                                (data[2]["Power Constraint (kW)"] == 125) &
                                (data[2]["eol (t/f)"] == True)]["Hydrogen Supply Rate (g/s)"].iloc[0]
            
            print("H2 Supply Rate, FL 120, 125 kW, BoL, 400 vs 500 cells:")
            print(f"{100-(_H2_500/_H2_400*100):.2f} % ")
            
            print("H2 Supply Rate, FL 120, 125 kW, 500 cells, BoL vs EoL:")
            print(f"{(_H2_500_eol/_H2_500)*100-100:.2f} % ")


# %% PLOT: h2_supply
def plot_h2_supply_vs_systempower(plot_params, params_general, show_plot, saving=True):
    """
    Plot of H2 supply vs system power with polynomial fit.
    Further it prints an nummerical comparison between 400-500 cells and 500 stack @ bol and eol
    
    - data : List of DataFrames for different cellcounts.
    - titles: List of strings, corresponding to the titles for each dataset.
    - colors: List of strings, corresponding to the colors used inside of th eplot to distinglish different cellcounts.
    - fl_set: Int [0, 150] kft, specific FL at which the plot will be generated.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    
    # Print out nummerical example between points:
    #1: 400 vs 500, BoL, FL 120, 125 kW:
    #print_example_between_points(data)
    data = params_general['data']
    fl_set = params_general['fl']
    weightings = params_general['weightings'] 
    titles = params_general['titles']
    colors = params_general['colors']
    markers = params_general['markers_oL']


    # Store handles and labels for manual legend creation
    handles = []
    labels = []
    for weighting, fl in itertools.product(weightings, fl_set):     
        fig, ax = plt.subplots(figsize=(12, 8))
        fig.tight_layout()
        for df, title, color in zip(data, titles, colors):
            df = filter_data_by_f1_and_weight(df, fl, weighting)
            if df.empty:
                print(f"No data available for H2 Supply {title} at FL {fl} or for weighting {weighting}. Skipping plot.")
                continue  # Skip plotting if no data exists   
            for filter_eol, linestyle, marker, label_suffix in [(False, '-', markers[0], 'BoL'), (True, '--', markers[1], 'EoL')]:
                # Apply the filter based on the function argument
                filtered_df = df[(df["eol (t/f)"] == filter_eol) 
                                &(df["current_A (Value)"] <= 700)]
                
                # Scatter plot for each dataset
                scatter = ax.scatter(filtered_df['System Power (kW)'], 
                                    (filtered_df['Hydrogen Supply Rate (g/s)']), 
                                    s=100, edgecolor='k', color=color, marker=marker)
                
                # Extract x and y data
                x = filtered_df['System Power (kW)']
                y = filtered_df['Hydrogen Supply Rate (g/s)']
                
                # Construct the design matrix [x^2, x]
                A = np.vstack([x**2, x]).T
                
                # Perform least squares fitting
                coeffs, _, _, _ = np.linalg.lstsq(A, y, rcond=None)
                

                
                #create and Plot the polynomial fit
                line = create_plot_polynomial_function(ax, x, linestyle, color, coeffs)

                
                # Add the polynomial formula to the legend
                formula = f'{title} ({label_suffix}) Fit: {coeffs[0]:.2e}x² + {coeffs[1]:.2e}x'
                
                # Collect handles and labels for the legend
                handles_lables_for_legends(handles, labels, scatter, title, label_suffix, line, formula)


        # Create the legend
        ax.legend(handles, labels, loc='best')
        handles.clear()
        labels.clear()

        # Set title and axis labels
        plot_params.update({'title': f'Hydrogen Supply Rate vs System Net Power, FL {fl}, Weighting {weighting}'})
        configure_axes(ax, **plot_params)

        
        if saving and ax.collections:
            file_path = create_plot_save_directory(f'H2_Supply__FL_{fl}_weighting_{weighting}.png', weighting)
            plt.savefig(file_path, bbox_inches='tight')        
        plt.show() if show_plot and ax.collections else plt.close()

