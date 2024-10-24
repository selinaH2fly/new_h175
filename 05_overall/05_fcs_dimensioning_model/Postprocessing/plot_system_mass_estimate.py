# Import libraries
import sys
import os
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Add the directory containing Components to the Python path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

# Import custom classes and functions
from Components.stack import Stack
from parameters import Mass_Parameters

# %%PLOT a stacked bar chart of each subsystem component mass grouped by power level.         
def plot_system_mass_estimate(data, titles, colors, components_dict, markers, weighting, show_plot, saving=True, mode="bol"):  
    """
    Plot of system mass vs system power as a stack bar chart for each subsystem.
    
    - data : List of DataFrames for different cellcounts.
    - titles: List of strings, corresponding to the titles for each dataset.
    - colors: List of strings, corresponding to the colors used inside of th eplot to distinglish different cellcounts.
    - components_dict:
    - markers: List of strings for plt icons. 
    - saving: Boolean, if True, saves the plots as PNG files.
    - mode: string "eol" or "bol", setting a filter to see eol or bol data.
    """
    
    # Filter option for eol or bol plot: 
    # If sizing for eol, Turbine and Compressor power tend to increase, and thus the estimated cathode mass would be higher.
    
    if mode == "eol":
        filter_mode = True
        mode_name = "EoL"
    elif mode == "bol":
        filter_mode = False
        mode_name = "BoL"
    
    # Get mass constants from parameters.py
    masses_FCM_constants = Mass_Parameters().masses_FCM_constants

    
    # Define a function to sum the constants of each subsystem, as well as a total mass
    def sum_mass(masses: dict):
        subsystem_totals = {}
        total = 0 
        for subsystem, subsystem_dict in masses.items():
            temp = 0
            for value in subsystem_dict.values():
                temp += value
            subsystem_totals[subsystem] = temp
            total += temp
        return subsystem_totals, total
    
    # The x-axis points to be plotted and searched for
    points = [125, 150, 175]
    
    # Define cell numbers we would like to iterate through
    cell_no = np.array([400, 455, 500])
    
    # Get stack and coolant mass from components -> stack
    m_stack_values = np.array([Stack(cellcount=cell).calculate_stack_mass() for cell in cell_no])
    m_coolant_values = np.array([Stack(cellcount=cell).calculate_coolant_mass() for cell in cell_no])

    # Populating the final data array with lists of zeros. Feels like there should be a quicker way.
    subsystem_mass_total = {}
    for power in points:
        subsystem_mass_total[power]={'Stack':np.zeros(len(cell_no)),'Cathode':np.zeros(len(cell_no)),'Anode':np.zeros(len(cell_no)),'Thermal':np.zeros(len(cell_no)), 'Other':np.zeros(len(cell_no))}
    
    # Counter to append the mass value to the correct indice of the array
    max_tracker = 0
    
    # Creating values of horizontal line to show specific power target
    target_specific_power = 1.25    # [kW/kg]
    
    # Initialising lists for the following iteration
    target_masses = []
    cathode_mass = []
    within_tolerance = []
    within_current = []
    
    """
    additional_cathode_mass = []
    additional_anode_mass = []
    additional_thermal_mass = []
    """
    
    # Extract Power of components and therefore the added cathode mass for each component
    for df, title, color, m_stack_value, marker in zip(data, titles, colors, m_stack_values, markers):
        # Filter the df for eol, bol and flight level
        df = df[(df["eol (t/f)"] == filter_mode) & 
                (df["Flight Level (100x ft)"] == 120) &
                (df["weighting ([0,1])"] == weighting)]
        
        # Extract all power points from the filtered DataFrame
        all_points = sorted(df["System Power (kW)"].unique())
        #print(all_points)
        
        # narrow all_points list down to those close 125,150 and 175. Might be a better way to do this.
        tol = 1
        
        def find_closest(values, point):
            converged = True
            values_array = np.array(values)
            index = (np.abs(values_array - point)).argmin()
            # Checking if its the right point. If it different converge the calculated difference will be outside of the tolerance. 
            if np.abs(values_array[index] - point) > tol:
                converged = False
            return values_array[index], converged

        # Find and print the closest values for each target
        closest_values = []
        
        for point in points:
            current_check = True
            closest_value, tolerance_bool = find_closest(all_points, point)
            closest_values.append(closest_value)
            within_tolerance.append(tolerance_bool)
            closest_row = df.iloc[(df["System Power (kW)"] - point).abs().argmin()]
            if closest_row["current_A (Value)"] > 700:
                current_check = False
            
            """
            # Added mass for turbine and compressor
            cathode_mass_add = closest_row["Compressor Power (kW)"] * 0.63 + closest_row["Turbine Power (kW)"]*0.63
            anode_mass_add = closest_row["Recirculation Pump Power (kW)"] * 7.38
            thermal_mass_add = closest_row["Coolant Pump Power (kW)"] * 4.8
            additional_cathode_mass.append(cathode_mass_add)
            additional_anode_mass.append(anode_mass_add)
            additional_thermal_mass.append(thermal_mass_add)
            """
            within_current.append(current_check)
            
            # Code to iterate through dictionary
            
            cathode_weight = 0
            
            for key, mean_value in components_dict.items():
                power_value = closest_row[key]
                component_weight = power_value * mean_value
                cathode_weight += component_weight

            cathode_mass.append(cathode_weight)
            

    #print(cathode_mass)
    # Currently, the outputted lists of the last loop need to be reordered to be the appropriate format for this loop.
    # This is ugly, would like to change. 
    within_tolerance_ordered = [None]* (len(within_tolerance))
    within_current_ordered = [None] * (len(within_current))
    i = 0
    reorder = [0,3,6,1,4,7,2,5,8]
    
    test,total= sum_mass(masses_FCM_constants)
    
    for k in range(0,len(points)):
        # Value of horizontal line for each power level
        target_masses.append(points[k]/target_specific_power)

        for n in range(0,len(cell_no)):
            # Defining a temporary dictionary for each separate test case
            temp,total= sum_mass(masses_FCM_constants)
            
            # Stack and coolant mass scale with cell count.
            temp['Stack'] += m_stack_values[n]
            temp['Thermal']+= m_coolant_values[n]
            
            """
            # Add power based estimates
            temp['Cathode'] += additional_cathode_mass[i]
            temp['Anode'] += additional_anode_mass[i]
            temp['Thermal'] += additional_thermal_mass[i]
            """
            
            # Cathode mass scales with power
            temp['Cathode'] += cathode_mass[reorder[i]]
            
            
            # Reorder our boolean lists to suit overall iteration later. 
            within_tolerance_ordered[reorder[i]] = within_tolerance[i]
            within_current_ordered[reorder[i]] = within_current[i]
            
            # Curently, this total value is just used to track the maximum bar height, to size the y-axis accordingly. Could be refactored to make more efficient. 
            total += m_stack_values[n]
            total += m_coolant_values[n]
            
            total += cathode_mass[reorder[i]]
            
            if total > max_tracker:
                max_tracker = total
            
            # Assigning the updated subsystem masses to the correct location in the nested dictionary. 
            for key,value in temp.items():
                subsystem_mass_total[points[k]][key][n] = value
                
            # iterates between 0 and 8 to allow appropriate assignment to array    
            i += 1      
     

    #The order, from bottom to top, that the components should be in. Place constant components at bottom so the changes are clearer.
    orders = ['Other', 'Anode', 'Thermal','Stack','Cathode']
    
    categories = list(subsystem_mass_total.keys()) 
    n_values = len(subsystem_mass_total[points[0]]['Stack'])  # Number of values for each subsystem


    # Defining bar spacing
    bar_width = 0.25  # Width of each bar
    group_spacing = 0.3 # Spacing between different groups
    bar_spacing = 0.05 # Spacing between bars in the same group

    # Positions of the groups on the x-axis
    x = np.arange(len(categories)) * (n_values * (bar_width + bar_spacing) + group_spacing) #Add spacing between groups and bars

    # Initialize a plot
    fig, ax = plt.subplots(figsize=(12, 6))
    ax.set_axisbelow(True)
    
    # Include major grid lines
    ax.yaxis.grid(True)
    
    # Sample subsystem colours at regular intervals from the colourmap
    cmap = plt.get_cmap('viridis')
    num_colors = len(orders)
    indices = np.linspace(0, 1, num_colors)
    colors = cmap(indices)
    
    # Colours for different cell counts
    label_colors= ['tab:blue', 'tab:orange','tab:red']

    # This index is used to correctly iterate through the boolean lists that check for convergence and current level. 
    plot_index = 0

    # Create lists to store legend handles and labels
    handles = []
    labels = []

    # Iterate through each power
    for i, category in enumerate(categories):
        # Iterate through each cell number
        for j in range(n_values):

            bottom_values = np.zeros(1)
            bar_positions = x[i] + j * (bar_width + bar_spacing)
            total_height = 0
            bar_plotted= False
            
            # Iterate through each subsystem
            for k, order in enumerate(orders):
                value = subsystem_mass_total[category][order][j]
                # If the point has converged, plot a bar. 
                if within_tolerance_ordered[plot_index]:
                    bars = ax.bar(bar_positions, value, bar_width, label=f'{order}' if j == 0 else "", bottom=bottom_values, color=colors[k])
                    bottom_values += value  # Update bottom_values to stack the next bars
                    total_height = bottom_values[0]
                    bar_plotted = True

                    # extract the handles and labels for the legend
                    handles = handles + [bars]
                    labels = labels + [f'{order}']
                else: 
                    # Deciding on height of black cross
                    #total_height += value
                    total_height = 100
                    
            # If the point has not converged, plot a black cross        
            if not bar_plotted:
                x_left = bar_positions - bar_width / 2
                x_right = bar_positions + bar_width / 2
                y_bottom = 0
                y_top = total_height
    
                # Draw the 'X' across the full height and width of the bar
                ax.plot([x_left, x_right], [y_bottom, y_top], color='black', linewidth=2)  # Diagonal from bottom-left to top-right
                ax.plot([x_left, x_right], [y_top, y_bottom], color='black', linewidth=2)  # Diagonal from top-left to bottom-right    
                
            # If the point has converged, but the current exceeds the limit, plot a red cross over the bar
            if bar_plotted and not within_current_ordered[plot_index]:
                x_left = bar_positions - bar_width / 2
                x_right = bar_positions + bar_width / 2
                y_bottom = 0
                y_top = total_height
        
                # Draw the 'X' across the full height and width of the bar
                ax.plot([x_left, x_right], [y_bottom, y_top], color='red', linewidth=2)  # Diagonal from bottom-left to top-right
                ax.plot([x_left, x_right], [y_top, y_bottom], color='red', linewidth=2)  # Diagonal from top-left to bottom-right  
                
                
            # Add text of cell count over each bar that has been plotted. 
            if within_tolerance_ordered[plot_index]:
                ax.text(bar_positions, total_height + 5, f'{cell_no[j]} cells', ha='center', va='bottom', color='black',
                        bbox=dict(facecolor=label_colors[j], edgecolor=label_colors[j], boxstyle='round,pad=0.3', linewidth=1.5, alpha=0.6))
        
            plot_index += 1
            
    # Plot dashed horizontal lines indicating the mass required to achieve the target power density. 
    for i, target in enumerate(target_masses):
        ax.hlines(target, x[i] - bar_width, x[i] + n_values * (bar_width + bar_spacing) - bar_spacing, colors='grey', linestyles='dashed', label=f'Target: {target_specific_power} kW/kg')
        
    # Adding labels and title
    ax.set_xlabel('Net Power [kW]')
    ax.set_ylabel('Mass [kg]')
    ax.set_title(f'Predicted FCM Mass, {mode_name}')
    ax.set_xticks(x + (n_values - 1) * (bar_width + bar_spacing) / 2)
    ax.set_xticklabels(categories)
    ax.set_ylim([0,max_tracker +125])
    
    # Insert texbox explaining crosses. 
    fig.text(0.07, 0.87, r'$\bf{X}$', fontsize=12, ha='left', va='top', color='red')
    fig.text(0.082, 0.87, r': above 700 A', fontsize=12, ha='left', va='top', color='black')
    
    fig.text(0.07, 0.84, r'$\bf{X}$', fontsize=12, ha='left', va='top', color='black')
    fig.text(0.082, 0.84, r' :not converged', fontsize=12, ha='left', va='top', color='black')

    # Concetanate the legend handles and labels
    handles_target_power, labels_target_power = plt.gca().get_legend_handles_labels()
    handles = handles_target_power[0:3] + handles
    labels = labels_target_power[0:3] + labels

    # This is currently required to plot the legend labels in the correct order.
    # And to only plot the 'target mass' label once for the 3 lines. Could be neatened later. 
    legend_order = [7,6,5,4,3,2]
    
    # add legend to plot
    ax.legend([handles[idx] for idx in legend_order],[labels[idx] for idx in legend_order],title='Subsystems', loc='upper right')

    # Adjust layout
    plt.tight_layout(rect=[0, 0, 1, 0.95])
    
    # Save and show the plot
    if saving:
        plt.savefig(f"Weight_estimation_vs_power_{mode}_weighting_{weighting}.png", bbox_inches='tight')

    plt.show() if show_plot else plt.close()
