#Old script from Wenzel, not used due to kates stack bar chart.
# %% Imports:
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score

#PLOT: Weight estmate with fit:
def plot_mass_estimate(data, titles, colors, components_dict, components_sd_dict, markers, saving=True, mode="bol"):
    """
    Plot of system mass vs system power with polynomial fit.
    
    - data : List of DataFrames for different cellcounts.
    - titles: List of strings, corresponding to the titles for each dataset.
    - colors: List of strings, corresponding to the colors used inside of th eplot to distinglish different cellcounts.
    - components_dict:
    - components_sd_dict:
    - markers: List of strings for plt icons. 
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    
    def linear_fit(x, y):
        x = np.array(x).reshape(-1, 1)
        y = np.array(y)
        model = LinearRegression().fit(x, y)
        y_pred = model.predict(x)
        slope = model.coef_[0]
        intercept = model.intercept_
        r2 = r2_score(y, y_pred)
        return slope, intercept, r2, y_pred
    
    # Filter option for eol or bol plot:
    if mode == "eol":
        filter_mode = True
        mode_name = "EoL"
    elif mode == "bol":
        filter_mode = False
        mode_name = "BoL"
        
    # The x-axis points to be plotted and searched for
    points = [20, 125, 150, 175]
    
    # Define the values of cell counts numerically
    n_values = np.array([400, 450, 500])
    
    # Calculate m_stack using the formula
    m_stack_values = 0.0766 * n_values + 9.2813  # Equation for PC
    
    # Set up the figure and axis
    fig, ax = plt.subplots(figsize=(10, 8))
    
    # Create lists to store legend handles and labels
    handles = []
    labels = []
    
    # Extract Power of components and calculate total weight for each cell count
    for df, title, color, m_stack_value, marker in zip(data, titles, colors, m_stack_values, markers):
        # Filter the df for eol, bol and beeing below 700 A
        df = df[(df["eol (t/f)"] == filter_mode) & 
                (df["current_A (Value)"] <= 700) &
                (df["Flight Level (100x ft)"] == 120)]
        
        # Extract all power points from the filtered DataFrame
        all_points = sorted(df["System Power (kW)"].unique())
        system_weights_of_points = []
        system_errors_of_points = []
        
        for point in all_points:
            closest_row = df.iloc[(df["System Power (kW)"] - point).abs().argmin()]
            total_weight = 0
            total_error_squared = 0
            for key, mean_value in components_dict.items():
                power_value = closest_row[key]
                error_value = components_sd_dict[key] * power_value
                component_weight = power_value * mean_value
                total_weight += component_weight
                total_error_squared += (error_value ** 2)
            total_weight += m_stack_value
            total_error = np.sqrt(total_error_squared)
            
            system_weights_of_points.append(total_weight)
            system_errors_of_points.append(total_error)
        
        ax.errorbar(all_points, system_weights_of_points, yerr=system_errors_of_points, fmt=marker, color=color, label=f'{title} System weight estimate',capsize=5)  # Add horizontal lines (caps) to the error bars
        
        # Performing linear regression for each dataset
        slope_, intercept_, r2_, y_pred_ = linear_fit(all_points, system_weights_of_points)
        
        # Plotting the fitted line with a label for the equation
        ax.plot(all_points, y_pred_, linestyle='--', color=color, label=f'{title} fit: y={slope_:.2f}x+{intercept_:.2f}')

        labels.append(f'{title} fit: y={slope_:.2f}x+{intercept_:.2f}')
    
    # Adding a text box with the components included
    components_text = "Components Included:\n" + "\n".join(key.replace("Power (kW)", "") for key in components_dict.keys())
    ax.text(0.05, 0.95, components_text, transform=ax.transAxes, fontsize=10,
             verticalalignment='top', bbox=dict(boxstyle="round,pad=0.3", edgecolor='black', facecolor='lightgray'))
    
    # Plotting the power density line (1.25 kW/kg)
    density = 1.25  # Power density (kW/kg)
    density_x = np.linspace(min(points), max(points), 100)
    density_y = density_x / density  # y = x / density
    ax.plot(density_x, density_y, linestyle='-.', color='black')  # No label for the line
    
    # Add annotation text without an arrow
    annotation_x = 150  # Position annotation at x = 150 (adjust as needed)
    annotation_y = annotation_x / density  # Calculate y based on the density line
    ax.text(annotation_x-10, annotation_y + 10, 'Power Density: 1.25 kW/kg', fontsize=10, color='black', ha='center')
    
    # Plot the legend with reordered entries
    ax.legend(labels=labels, bbox_to_anchor=(0.5, -0.1), loc='upper center', ncol=3)
    
    plt.xlabel('System Power (kW)')
    plt.ylabel('System Weight Estimation [kg]')
    plt.title(f'System Weight Estimation vs System Power, {mode_name}')
    plt.grid(True)
    ax.set_ylim([20, 140])
    
    # Save or show the plot
    if saving:
        plt.savefig(f"Weight_estimation_vs_power_{mode}.png", bbox_inches='tight')
    else:
        plt.show()