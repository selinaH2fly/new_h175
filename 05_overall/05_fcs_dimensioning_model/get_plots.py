# %% Imports:
import pandas as pd
import os
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.lines as mlines
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score

# %% Plot functions:

# PLOT: Polcurve single bol
def plot_polarization_curves(data, titles, fl_set, saving=True):
    """
    Plots the polarization curves for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    for df, title in zip(data, titles):
        df = df[df['Flight Level (100x ft)'] == fl_set]
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Create a colormap and normalize for the color gradient
        norm = mcolors.Normalize(vmin=df['System Power (kW)'].min(), vmax=min(df['System Power (kW)'].max(), 175))
        cmap = cm.ScalarMappable(norm=norm, cmap='viridis')
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df['current_A (Value)'], df['Cell Voltage (V)'], c=df['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100)

        # Add colorbar for the gradient
        cbar = plt.colorbar(scatter, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Manually set colorbar ticks from 20 to 175 in 25 steps, excluding 25
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

        # Add a red shaded area from 700 A to 800 A
        ax.axvspan(700, 800, color='red', alpha=0.3)
        
        # Set title and labels
        ax.set_title(f'System Polarization Curve, FL {fl_set}, {title}', fontsize=14)
        ax.set_xlabel('Current [A]')
        ax.set_ylabel('Cell Voltage [V]')
        ax.grid(True)
        ax.set_xlim([0, 800])
        ax.set_ylim([0, 1.25])
        fig.tight_layout()

        # Annotate points where 'eol (t/f)' is True
        for i in df[df["eol (t/f)"] == True].index:
            ax.annotate('EOL', 
                        (df['current_A (Value)'][i], df['Cell Voltage (V)'][i]), 
                        textcoords="offset points", 
                        xytext=(2, -20), 
                        ha='center',
                        fontsize=11, 
                        color='black')
            
        # Create a custom legend entry with a colorless circle
        legend_circle = mlines.Line2D([], [], color='none', marker='o', markerfacecolor='none', markeredgecolor='black', markersize=11, linestyle='None', label='System Power [kW]')
        ax.legend(handles=[legend_circle], loc='best')

        # Save the plot as a PNG file if saving is True
        if saving:
            plt.savefig(f'{title}_polarization_curve.png')
        
        # Show the plot
        plt.show()
                

# PLOT: Polcurve bol vs eol connectede points
def plot_polarization_curves_bol_eol(df1, titles, colors, fl_set, saving=True):
    def filter_data(df, eol, cell_counts):
        # Filter data for the specified flight level and EOL condition
        return {
            count: df[(df['Flight Level (100x ft)'] == fl_set) & 
                      (df['Specified Cell Count'] == count) & 
                      (df['eol (t/f)'] == eol)]
            for count in cell_counts
        }

    def plot_data(ax, bol_data, eol_data, titles, colors, highlight_powers, highlight_range=3):
        for count, title, color in zip(bol_data.keys(), titles, colors):
            bol_df, eol_df = bol_data[count], eol_data[count]

            # Plot BOL and EOL data
            ax.scatter(bol_df['current_A (Value)'], bol_df['Cell Voltage (V)'], color=color, label=f'{title} bol', marker="p")
            ax.scatter(eol_df['current_A (Value)'], eol_df['Cell Voltage (V)'], color=color, label=f'{title} eol', marker='X')

            # Connect corresponding BOL and EOL points and annotate
            for power in highlight_powers:
                bol_highlight = bol_df[bol_df["Power Constraint (kW)"].between(power - highlight_range, power + highlight_range)]
                eol_highlight = eol_df[eol_df["Power Constraint (kW)"].between(power - highlight_range, power + highlight_range)]
                
                # Ensure both BOL and EOL points are available
                if not bol_highlight.empty and not eol_highlight.empty:
                    bol_row = bol_highlight.iloc[0]
                    eol_row = eol_highlight.iloc[0]
                    
                    # Draw connection line
                    ax.plot([bol_row['current_A (Value)'], eol_row['current_A (Value)']],
                            [bol_row['Cell Voltage (V)'], eol_row['Cell Voltage (V)']],
                            color=color, alpha=0.5, linestyle='--')
                    
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

    # Highlight power levels
    highlight_powers = [20, 50, 80, 125, 150, 175]
    cell_counts = [400, 450, 500]

    # Filter data for BOL and EOL
    bol_data = filter_data(df1, eol=False, cell_counts=cell_counts)
    eol_data = filter_data(df1, eol=True, cell_counts=cell_counts)

    # Create the plot
    fig, ax = plt.subplots(figsize=(12, 8))
    plot_data(ax, bol_data, eol_data, titles, colors, highlight_powers)

    # Add red shaded area and labels
    ax.axvspan(700, 1300, color='red', alpha=0.2)
    ax.set(title=f"System Polarization Curve, {fl_set}, eol vs bol", xlabel='Current [A]', xlim=[0, 1300], ylabel='Cell Voltage [V]', ylim=[0.3, 1])
    ax.grid(True)
    ax.legend(loc='upper right')

    # Save and show plot
    if saving:
        plt.savefig('Hydrogen_Consumption.png')
    plt.show()


# PLOT: Power Grid, fancy
def annotate_boxes(ax, df, cell_width=1, cell_height=2):
    """
    Annotates each cell in the plot with its corresponding value, taking into account the gaps between columns.
    """
    for i in range(len(df)):
        for j in range(df.shape[1] - 1):
            col_pos = j + (j // 2)  # Column position considering the gaps
            y_pos = i * cell_height-0.5  # Y position for each row
            
            # Get the cell value and handle NaN values
            cell_value = df.iloc[i, j + 1]
            
            if not pd.isna(cell_value):
                # Round the value to the nearest integer
                cell_value = round(cell_value)
                if cell_value == 0:
                    # Annotate the cell with "< 1"
                    ax.text(col_pos + cell_width / 2, y_pos + cell_height / 2, 
                            str("< 1"), color='black', ha='center', va='center')
                else:
                    # Annotate the cell with the value
                    ax.text(col_pos + cell_width / 2, y_pos + cell_height / 2, 
                            str(cell_value), color='black', ha='center', va='center')
            else:
                #Write X to the Box because the value was Nan
                cell_value = "X"
                
                # Annotate the cell with the value
                ax.text(col_pos + cell_width / 2, y_pos + cell_height / 2, 
                        str(cell_value), color='black', ha='center', va='center')
            
def format_data_for_plot(df, components, fl_set, eol_col='eol (t/f)', tolerance=0.01):
    """
    Formats the DataFrame for plotting by separating components based on the eol (t/f) column.
    Also checks if 'Power Constraint (kW)_bol' matches the stack power values within a tolerance and sets NaN if not.

    Parameters:
    - df (pd.DataFrame): The DataFrame to be formatted.
    - components (list): List of component columns to include in the formatted DataFrame.
    - eol_col (str): Name of the column containing 'True' or 'False' values to split by.
    - tolerance (float): The allowed tolerance factor for matching values.

    Returns:
    - pd.DataFrame: A formatted DataFrame for plotting.
    """
    # Create an empty DataFrame to store formatted data
    formatted_df = pd.DataFrame()
    #current = df["current_A (Value)"]
    df = df[df['Flight Level (100x ft)'] == fl_set]
    #Create a DF which has all the powerlevels saved for y axis labels.:
    power_levels = df[df['eol (t/f)'] == False]["Power Constraint (kW)"]
    
    for component in components:
        # Filter out the columns related to the component
        component_df = df[[component, eol_col]].copy()

        # Separate the data based on eol (t/f)
        df_false = component_df[component_df[eol_col] == False].drop(columns=[eol_col]).reset_index(drop=True)
        df_false.columns = [f'{component}_bol']  # Rename the columns of df_false by adding _bol

        df_true = component_df[component_df[eol_col] == True].drop(columns=[eol_col]).reset_index(drop=True)
        df_true.columns = [f'{component}_eol']  # Rename the columns of df_true by adding _eol

        # Append to the formatted DataFrame
        formatted_df = pd.concat([formatted_df, df_false, df_true], axis=1)

    if 'current_A (Value)_bol' in formatted_df.columns and 'current_A (Value)_eol' in formatted_df.columns:
        current_bol = formatted_df['current_A (Value)_bol']
        current_eol = formatted_df['current_A (Value)_eol']
        current_caint = 700 # Threshold value for current

        # Set NaN where values are above 700 current_cait
        formatted_df.loc[current_bol > current_caint, :] = np.nan
        formatted_df.loc[current_eol > current_caint, :] = np.nan
    
    
# Drop columns that should not be in the final DataFrame
    drop_columns = ['Power Constraint (kW)_eol','current_A (Value)_bol','current_A (Value)_eol']
    for drop_column in drop_columns:
        if drop_column in formatted_df.columns:
            formatted_df.drop(drop_column, axis=1, inplace=True)

    return formatted_df, power_levels

def plot_power_needs(data, titles, fl_set, saving=False):
    """
    Plot a heatmap-like representation of power needs by components, with specific formatting.

    Parameters:
    - data (list of pd.DataFrame): List of DataFrames where each DataFrame represents different conditions.
    - titles (list of str): List of titles for each DataFrame.
    - saving (bool): If True, saves the plot to a file. Defaults to False.
    """
    components = ["Power Constraint (kW)",
                  "current_A (Value)",
                  "Compressor Power (kW)",	
                  "Turbine Power (kW)",	
                  "Recirculation Pump Power (kW)",	
                  "Coolant Pump Power (kW)",	
                  "Stack Power (kW)"]
    
    for df1, title in zip(data, titles):
        
        #Formate the data to the needed formate:
        df, power_levels = format_data_for_plot(df1, components, fl_set, eol_col='eol (t/f)')
        
        # Set up the figure and axis
        fig, ax = plt.subplots(figsize=(10, 8))
    
        # Define the colormap and normalization
        cmap = plt.cm.coolwarm
        norm = mcolors.LogNorm(vmin=0.1, vmax=225)  # Logarithmic normalization
    
        # Plot each cell with a gap between every second column
        for i in range(len(df)):
            for j in range(df.shape[1] - 1):
                col_pos = j + (j // 2)  # Calculate position with gaps after every second column
                cell_value = df.iloc[i, j + 1]
                if not pd.isna(cell_value):  # Check if the cell value is NaN
                    y_pos = i * 2  # This matches the actual index directly without inverting
                    ax.imshow([[cell_value]], aspect='auto', cmap=cmap, norm=norm,
                              extent=[col_pos, col_pos + 1, y_pos, y_pos + 1])
        
        annotate_boxes(ax, df, cell_width=1, cell_height=2)
        
        # Adjust xlim to ensure the first cell is fully inside the plot
        total_columns = df.shape[1] - 1 + (df.shape[1] - 2) // 2  # Adjusted number of columns with gaps
        ax.set_xlim(-0.5, total_columns + 0.5)
    
        # Calculate adjusted x-tick positions (centered)
        col_positions = [i + (i // 2) + 0.5 for i in range(df.shape[1] - 1)]
        ax.set_xticks(col_positions)
    
        # Set x-tick labels to alternate between 'Bol' and 'Eol'
        ax.set_xticklabels(['Bol' if i % 2 == 0 else 'Eol' for i in range(df.shape[1] - 1)])
    
        # Adjust y-ticks to be centered on the colored boxes
        y_tick_positions = np.arange(1, len(df) * 2, 2) - 0.5  # Center y-ticks by shifting them down
        ax.set_yticks(y_tick_positions)
        ax.set_yticklabels([f'{round(level)} kW' for level in power_levels.values])
        ax.set_ylim(-0.5, len(df) * 2 - 0.5)
    
        # Add secondary x-axis on top, with centered labels above each pair of boxes
        ax2 = ax.twiny()
        ax2.set_xlim(ax.get_xlim())  # Ensure the limits are the same
    
        # Determine the tick positions for the secondary x-axis
        positions = [1 + 3 * i for i in range((df.shape[1] - 2) // 2 + 1)]  # Positions for labels, adjust to the center
        ax2.set_xticks(positions)
    
        # Adjust labels for the secondary x-axis
        ax2.set_xticklabels([col.replace(' Power (kW)_bol', '').replace(' Power (kW)_eol', '') for col in df.columns[1::2]])
        #ax2.set_xlabel('Components', labelpad=10)
    
        # Add colorbar
        cbar = fig.colorbar(plt.cm.ScalarMappable(norm=norm, cmap=cmap), ax=ax)
        cbar.set_label('Power (kW)')
    
        # Set the title centered between the colored boxes
        title = f"Power Consumption of Components [kW] {title}, FL {fl_set}"
        ax.set_title(title, pad=30, loc='center')
    
        # Save or show the plot
        if saving:
            plt.savefig(f"Component_Powers_{title}.png", bbox_inches='tight')
        else:
            plt.show()

# PLOT: h2_consumption
def plot_h2_consumption(data, titles, colors, weights, fl_set, saving=True):
    
    fig, ax = plt.subplots(figsize=(12, 8))
    fig.tight_layout()
    # Store handles and labels for manual legend creation
    handles = []
    labels = []

    for df, title, color, weight in zip(data, titles, colors, weights):
        df = df[df['Flight Level (100x ft)'] == fl_set]
        for filter_eol, linestyle, marker, label_suffix in [(False, '-', 'p', 'Normal'), (True, '--', 'X', 'EOL')]:
            # Apply the filter based on the function argument
            filtered_df = df[(df["eol (t/f)"] == filter_eol) 
                             &(df["current_A (Value)"] <= 700)]
            
            # Scatter plot for each dataset
            scatter = ax.scatter(filtered_df['System Power (kW)'], 
                                 filtered_df['Hydrogen Consumption (g/s)']/weight, 
                                 s=100, edgecolor='k', color=color, marker=marker)
            
            # Extract x and y data
            x = filtered_df['System Power (kW)']
            y = filtered_df['Hydrogen Consumption (g/s)'] / weight
            
            # Construct the design matrix [x^2, x]
            A = np.vstack([x**2, x]).T
            
            # Perform least squares fitting
            coeffs, _, _, _ = np.linalg.lstsq(A, y, rcond=None)
            
            # Create the polynomial function
            def poly(x):
                return coeffs[0] * x**2 + coeffs[1] * x
            
            # Plot the polynomial fit
            line_x = np.linspace(x.min(), x.max(), 500)
            line_y = poly(line_x)
            line, = ax.plot(line_x, line_y, linestyle=linestyle, color=color, alpha=0.7)
            
            # Add the polynomial formula to the legend
            formula = f'{title} ({label_suffix}) Fit: {coeffs[0]:.2e}x² + {coeffs[1]:.2e}x'
            
            # Collect handles and labels for the legend
            handles.append(scatter)
            labels.append(f'{title} ({label_suffix}) Data')
            handles.append(line)
            labels.append(formula)

    # Create the legend
    ax.legend(handles, labels, loc='best')

    # Set title and labels
    ax.set_title(f'Hydrogen Consumption vs System Power, {fl_set}')
    ax.set_xlabel('System Power [kW]')
    ax.set_ylabel('Hydrogen Consumption [g/s]')
    ax.grid(True)
    
    if saving:
        plt.savefig('H2_Consumption.png', bbox_inches='tight')
    plt.show()
    
# PLOT: H2 consumption over flight level all in one
def H2_consumption_vs_FL(df1, markers, fl_max, saving=True, mode="eol"):

    # List of cell counts and corresponding icons
    cells = [400, 450, 500]
    markers = ["o", "v", "s"]

    # Define power levels to highlight
    highlight_powers = [125, 150, 175]
    highlight_range = 4

    # Create a figure and axis
    fig, ax = plt.subplots(figsize=(12, 8))
    fig.tight_layout()
    
    # Create a colormap and normalize for the color gradient
    norm = mcolors.Normalize(vmin=125, vmax=175)
    cmap = cm.ScalarMappable(norm=norm, cmap='plasma')

    if mode == "eol":
        filter_mode = True
        mode_name = "Eol"
    elif mode == "bol":
        filter_mode = False
        mode_name = "Bol"
        
    # Loop through each cell count and plot the data
    for cell, icon in zip(cells, markers):
        #filter dataframe after cell count and 125-+, 150+-, and 175+-
        df_filtered = df1[(df1['Specified Cell Count'] == cell) 
                          &(df1['System Power (kW)'].between(highlight_powers[0] - highlight_range, highlight_powers[0] + highlight_range) |
                           df1['System Power (kW)'].between(highlight_powers[1] - highlight_range, highlight_powers[1] + highlight_range) |
                           df1['System Power (kW)'].between(highlight_powers[2] - highlight_range, highlight_powers[2] + highlight_range))
                          & (df1["eol (t/f)"] == filter_mode)]

        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df_filtered['Flight Level (100x ft)'], df_filtered['Hydrogen Consumption (g/s)'], 
                             c=df_filtered['System Power (kW)'], cmap='plasma', norm=norm, edgecolor='k', s=100, marker=icon, label=f'{cell} Cells')

    # Add colorbar for the gradient
    cbar = plt.colorbar(cmap, ax=ax)
    cbar.set_label('System Power [kW]')

    # Create custom legend handles
    handles = [plt.Line2D([0], [0], marker=marker, color='w', markerfacecolor='k', markersize=10, linestyle='') for marker in markers]
    labels = [f'{cell} Cells' for cell in cells]

    # Add legend
    ax.legend(handles, labels, loc='upper left')
    
    # Set title and labels
    ax.set_title(f'System Hydrogen Consumption over FL for Different Cell Counts at {mode_name}', fontsize=14, pad=20)
    ax.set_xlabel('Flight Level [100x ft]')
    # Set x-range from 0 to 140 in steps of 20, and include 150
    x_ticks = list(range(0, fl_max, 20))
    ax.set_xlim([0, fl_max])
    ax.set_xticks(x_ticks)

    ax.set_xlim([-1, fl_max+1])
    ax.set_ylabel('Hydrogen Consumption [g/s]')
    ax.set_ylim([1, 6])
    ax.grid(True)

    # Save or show the plot
    if saving:
        plt.savefig(f"H2_over_FL_{mode_name}.png", bbox_inches='tight')
    else:
        plt.show()

#PLOT: Weiht estmate wuth fit:
def plot_weight_estimate(data, titles, colors, components_dict, components_sd_dict, markers, saving=True, mode="bol"):
    
    # Function to perform linear regression and return the formula and R^2
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
        mode_name = "Eol"
    elif mode == "bol":
        filter_mode = False
        mode_name = "Bol"
        
    # The x-axis points to be plotted and searched for
    points = [125, 150, 175]
    
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
        # Filter the df for eol or bol
        df = df[(df["eol (t/f)"] == filter_mode) & (df["current_A (Value)"] <= 700)]

        system_weights_of_points = []
        system_errors_of_points = []
        for point in points:
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
        
        ax.errorbar(points, system_weights_of_points, yerr=system_errors_of_points, fmt=marker, color=color, label=f'{title} System weight estimate',capsize=5)  # Add horizontal lines (caps) to the error bars
        
        # Performing linear regression for each dataset
        slope_, intercept_, r2_, y_pred_ = linear_fit(points, system_weights_of_points)
        
        # Plotting the fitted line with a label for the equation
        ax.plot(points, y_pred_, linestyle='--', color=color, label=f'{title} fit: y={slope_:.2f}x+{intercept_:.2f}')

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
    ax.text(annotation_x, annotation_y + 10, 'Power Density: 1.25 kW/kg', fontsize=10, color='black', ha='center')
    
    # Plot the legend with reordered entries
    ax.legend(labels=labels, bbox_to_anchor=(0.5, -0.1), loc='upper center', ncol=3)
    
    plt.xlabel('System Power (kW)')
    plt.ylabel('System Weight Estimation [kg]')
    plt.title(f'System Weight Estimation vs System Power, {mode}')
    plt.grid(True)
    ax.set_ylim([50, 140])
    
    # Save or show the plot
    if saving:
        plt.savefig(f"Weight_estimation_vs_power_{mode}.png", bbox_inches='tight')
    else:
        plt.show()

   
#%%  
 
def analyze_data(_file_path1, saving=True):
    
    # Load the CSV file into a DataFrame
    df1 = pd.read_csv(_file_path1)

    # Change the working directory to the directory containing the .csv file
    file_dir = os.path.dirname(_file_path1)
    os.chdir(file_dir)

    # Create a new directory for plots
    os.makedirs("00_Plots", exist_ok=True)
    os.chdir("00_Plots")
    
    # Sort and prefilter data by index and current
    df1 =df1[df1["converged (t/f)"] == True]
    df1 = df1.sort_values(by=['idx'])
        
    # Split the data based on 'Specified Cell Count'
    df_400 = df1[df1['Specified Cell Count'] == 400]
    df_450 = df1[df1['Specified Cell Count'] == 450]
    df_500 = df1[df1['Specified Cell Count'] == 500]
    
    data   = [     df_400,       df_450,     df_500]
    titles = ['400 Cells',  '450 Cells','500 Cells']
    colors = [ "tab:blue", "tab:orange",  "tab:red"]
    markers= ["o", "v", "s"]
    
    fl_set = 125
    fl_max = max(df1["Flight Level (100x ft)"])
    
    ###########PLOT: Polcurves
    #plot_polarization_curves(data, titles, fl_set, saving=saving)
    
    ############PLOT: Polcurves eol vs bol connected
    #plot_polarization_curves_bol_eol(df1, titles, colors, fl_set, saving=saving)
    
    ############PLOT: System Power Grid Plot
    plot_power_needs(data, titles, fl_set, saving=saving)
    
    ###########PLOT: H2 consumption
    #weights = [1,1,1]#[39.92+ 6.26,43.75+6.01,47.58+5.77] #stack + compressor gewicht
    #plot_h2_consumption(data, titles, colors, weights, fl_set, saving=saving)
        
    #############PLOT: H2 consumption vs Flightlevel:
    #H2_consumption_vs_FL(df1, markers, fl_max, saving=saving, mode="bol")
    #H2_consumption_vs_FL(df1, markers, fl_max, saving=saving, mode="eol")

    ############Plot Weight estimate
    #Weight/Power Factor
    componentsP_dict =  {"Compressor Power (kW)":   0.63,
                        "Turbine Power (kW)":      0.63,
                        "Recirculation Pump Power (kW)":    7.38,
                        "Coolant Pump Power (kW)": 4.80}
    components_SD_dict = {"Compressor Power (kW)":   0.1,
                        "Turbine Power (kW)":      0.1,
                        "Recirculation Pump Power (kW)":    4.04,
                        "Coolant Pump Power (kW)": 1.66}
    
    #plot_weight_estimate(data, titles, colors, componentsP_dict, components_SD_dict, markers, saving=saving, mode="bol")
    #plot_weight_estimate(data, titles, colors, componentsP_dict, components_SD_dict, markers, saving=saving, mode="eol")
    
# Go back to origin dir
    os.chdir("../../")
# %%    


analyze_data(_file_path1=r"consolidated_20-175kW_400-500_0-150ft__1\optimized_parameters_20-175kW_400-500_0-150ft.csv", saving=True)    

#TODO write init: