# -*- coding: utf-8 -*-
"""
Created on Thu Aug 29 08:48:20 2024

@author: kate.lee
"""
import matplotlib.pyplot as plt
import numpy as np

"""
WARNING: really messy. Will be cleaned up and better documented tomorrow. 
This script will iterate through a nested dictionary of each individual component mass to give the total mass of each subsystem.  

"""
# Defining the input dictionaries for the following: power levels of 125, 150 and 175 kW; and cell count of 400, 450, 500
"""
masses_FCM_400_cells = {'Stack':{'Stack':39.92, 'CVM':1.00, 'SMI':3.00, 'Hose clamps': 0.18, 'Screws':0.09, 'HV+LV Cable': 1.20} \
                               ,'Cathode':{'Filter': 0.5, 'HFM': 0.5, 'Compressor':10.0, 'Compressor inverter':6.0, 'Intercooler':3.0, 'Humidifier': 2.0, 'Valves': 2.6, 'Drain valve': 0.30, 'Water separator': 0.3, 'Cathode pressure control valve': 0.0, 'Sensors': 1.2, 'Silicon hoses':1.76, 'Hose clamps': 0.42, 'Connectors': 0.8, 'Screws': 0.18, 'HV+LV Cable': 0.67, 'Turbine':0.0} \
                               ,'Anode': {'Shut-Off valve':0.2, 'Pressure control valve':0.2, 'Water separator':0, 'Particle filter':0.2, 'Recirculation pump':4.0, 'Drain valve': 0.2, 'Purge valve': 0.1, 'Sensors': 0.80, 'Anode piping':1.01, 'Swagelok connector':0.56, 'Screws':0.09, 'HV+LV Cable': 0.34}\
                               ,'Thermal':{'Coolant pump':4.0, 'TCV':1.0, 'Particle filter':0.22, 'Ionic exchangr':1.0, 'Sensors':0.80+0.80, 'Silicone hoses':1.51+2.02, 'Hose clamps':0.36+0.48, 'Connectors':0.80+0.80, 'Screws':0.09+0.09, 'HV+LV Cable':0.34+0.34, 'Expansion tank':1.0,'HDPU':5.0,'Volume flow control valve':0.5, 'Stack coolant':7.0, 'Other coolant':5.0}\
                               ,'Other':{'FCCU':1.5,'Electrical connectors':0.4,'Unnamed':4.0,'Frame':5.0,'Connectors':2.0,'Screws':0.27, 'HV+LV Cable':0.67}}
    
masses_FCM_450_cells = {'Stack':{'Stack':43.75, 'CVM':1.00, 'SMI':3.00, 'Hose clamps': 0.18, 'Screws':0.09, 'HV+LV Cable': 1.20} \
                               ,'Cathode':{'Filter': 0.5, 'HFM': 0.5, 'Compressor':10.0, 'Compressor inverter':6.0, 'Intercooler':3.0, 'Humidifier': 2.0, 'Valves': 2.6, 'Drain valve': 0.30, 'Water separator': 0.3, 'Cathode pressure control valve': 0.0, 'Sensors': 1.2, 'Silicon hoses':1.76, 'Hose clamps': 0.42, 'Connectors': 0.8, 'Screws': 0.18, 'HV+LV Cable': 0.67, 'Turbine':0.0} \
                               ,'Anode': {'Shut-Off valve':0.2, 'Pressure control valve':0.2, 'Water separator':0, 'Particle filter':0.2, 'Recirculation pump':4.0, 'Drain valve': 0.2, 'Purge valve': 0.1, 'Sensors': 0.80, 'Anode piping':1.01, 'Swagelok connector':0.56, 'Screws':0.09, 'HV+LV Cable': 0.34}\
                               ,'Thermal':{'Coolant pump':4.0, 'TCV':1.0, 'Particle filter':0.22, 'Ionic exchangr':1.0, 'Sensors':0.80+0.80, 'Silicone hoses':1.51+2.02, 'Hose clamps':0.36+0.48, 'Connectors':0.80+0.80, 'Screws':0.09+0.09, 'HV+LV Cable':0.34+0.34, 'Expansion tank':1.0,'HDPU':5.0,'Volume flow control valve':0.5, 'Stack coolant':7.0, 'Other coolant':5.0}\
                               ,'Other':{'FCCU':1.5,'Electrical connectors':0.4,'Unnamed':4.0,'Frame':5.0,'Connectors':2.0,'Screws':0.27, 'HV+LV Cable':0.67}}

masses_FCM_500_cells = {'Stack':{'Stack':47.58, 'CVM':1.00, 'SMI':3.00, 'Hose clamps': 0.18, 'Screws':0.09, 'HV+LV Cable': 1.20} \
                               ,'Cathode':{'Filter': 0.5, 'HFM': 0.5, 'Compressor':10.0, 'Compressor inverter':6.0, 'Intercooler':3.0, 'Humidifier': 2.0, 'Valves': 2.6, 'Drain valve': 0.30, 'Water separator': 0.3, 'Cathode pressure control valve': 0.0, 'Sensors': 1.2, 'Silicon hoses':1.76, 'Hose clamps': 0.42, 'Connectors': 0.8, 'Screws': 0.18, 'HV+LV Cable': 0.67, 'Turbine':0.0} \
                               ,'Anode': {'Shut-Off valve':0.2, 'Pressure control valve':0.2, 'Water separator':0, 'Particle filter':0.2, 'Recirculation pump':4.0, 'Drain valve': 0.2, 'Purge valve': 0.1, 'Sensors': 0.80, 'Anode piping':1.01, 'Swagelok connector':0.56, 'Screws':0.09, 'HV+LV Cable': 0.34}\
                               ,'Thermal':{'Coolant pump':4.0, 'TCV':1.0, 'Particle filter':0.22, 'Ionic exchangr':1.0, 'Sensors':0.80+0.80, 'Silicone hoses':1.51+2.02, 'Hose clamps':0.36+0.48, 'Connectors':0.80+0.80, 'Screws':0.09+0.09, 'HV+LV Cable':0.34+0.34, 'Expansion tank':1.0,'HDPU':5.0,'Volume flow control valve':0.5, 'Stack coolant':7.0, 'Other coolant':5.0}\
                               ,'Other':{'FCCU':1.5,'Electrical connectors':0.4,'Unnamed':4.0,'Frame':5.0,'Connectors':2.0,'Screws':0.27, 'HV+LV Cable':0.67}}
"""
    
masses_FCM_constants = {'Stack':{'Stack':0, 'CVM':1.00, 'SMI':3.00, 'Hose clamps': 0.18, 'Screws':0.09, 'HV+LV Cable': 1.20} \
                               ,'Cathode':{'Filter': 0.5, 'HFM': 0.5, 'Compressor':0, 'Compressor inverter':6.0, 'Intercooler':3.0, 'Humidifier': 2.0, 'Valves': 2.6, 'Drain valve': 0.30, 'Water separator': 0.3, 'Cathode pressure control valve': 0.0, 'Sensors': 1.2, 'Silicon hoses':1.76, 'Hose clamps': 0.42, 'Connectors': 0.8, 'Screws': 0.18, 'HV+LV Cable': 0.67, 'Turbine':0.0} \
                               ,'Anode': {'Shut-Off valve':0.2, 'Pressure control valve':0.2, 'Water separator':0, 'Particle filter':0.2, 'Recirculation pump':4.0, 'Drain valve': 0.2, 'Purge valve': 0.1, 'Sensors': 0.80, 'Anode piping':1.01, 'Swagelok connector':0.56, 'Screws':0.09, 'HV+LV Cable': 0.34}\
                               ,'Thermal':{'Coolant pump':4.0, 'TCV':1.0, 'Particle filter':0.22, 'Ionic exchangr':1.0, 'Sensors':0.80+0.80, 'Silicone hoses':1.51+2.02, 'Hose clamps':0.36+0.48, 'Connectors':0.80+0.80, 'Screws':0.09+0.09, 'HV+LV Cable':0.34+0.34, 'Expansion tank':1.0,'HDPU':5.0,'Volume flow control valve':0.5, 'Stack coolant':7.0, 'Other coolant':5.0}\
                               ,'Other':{'FCCU':1.5,'Electrical connectors':0.4,'Unnamed':4.0,'Frame':5.0,'Connectors':2.0,'Screws':0.27, 'HV+LV Cable':0.67}}    
"""
Comments on dictionary formatting:
    - Currently inputted manually, may later be automated
    - Stack, Compressor and masses will later be calculated and overwritten based on power and replaced.
    - Turbine mass not currently on spreadsheet, but has been added to end of the Cathode dictionary. 
    - Thermal system currently includes masses for HT Components, LT Components and the coolant.
    - Repeated Components in HT+LT systems are summed to avoid repeating keys in the same dictionary. 
    - Other currently include masses for the E/E (FCCU) and Housing
    - External components such as radiator and DCDC Converter not included, so system mass summed is the FCM, not FCS.
    - In masses_FCM_constants the masses of components which vary with cell number and power are set to zero, and will be added later. 
"""

# Defining function to sum each subsystem, as well as a total mass
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

"""
# test function 
ex = {'one':{'a': 1.0, 'b':2.0, 'c':3.0}, 'two':{'a2':1.1, 'b':2.1, 'c':3.0}}
subsystem_totals, total = sum_mass(ex)
print(subsystem_totals)     # {'one': 6.0, 'two': 6.2}
print(total)                # 12.2


subsystem_totals_500_cells, total_500_cells = sum_mass(masses_FCM_500_cells)
print(subsystem_totals_500_cells)
print(total_500_cells)
"""

def plot_mass_estimate(masses_dict_constant:dict, saving=True, mode="bol"):   
    # The x-axis points to be plotted and searched for
    points = [125, 150, 175]
    
    # Define cell number we would like to iterate through
    cell_no = np.array([400, 450, 500])
    
    # These points are currently taken as constants from V1.2 documentation.
    # Values of 100 are placeholders as operation deemed unfeasible
    # They should eventually be properly integrated. 
    # Called by points_comp_power[Power level, Cell count]
    
    points_comp_power = [[28,27,26],[0, 37,35], [0,0, 46]]
    points_turb_power = [[7,7,6],[0,9,8],[0,0,11]]
    
    
    # Calculate m_stack using the formula
    m_stack_values = 0.0766 * cell_no + 9.2813  # Equation for PC
    
    subsystem_mass_total = {}
    #Populating the final array with lists of zeros. Feels like there should be a quicker way.
    for power in points:
        subsystem_mass_total[power]={'Stack':np.zeros(len(cell_no)),'Cathode':np.zeros(len(cell_no)),'Anode':np.zeros(len(cell_no)),'Thermal':np.zeros(len(cell_no)), 'Other':np.zeros(len(cell_no))}
    #print(subsystem_mass_total)

    # Counter to append the mass value to the correct indice of the array
    max_tracker = 0
    plot_bar = []
    
    for k in range(0,len(points)):
        #i = 0
        for n in range(0,len(cell_no)):
            # Defining a temporary dictionary for each separate test case
            temp,total= sum_mass(masses_dict_constant)
            
            # Current way of assessing if data is true, so that plotting of this bar is passed.
            # Later compressor and turbine power will be called directly from the component class. 
            # This boolean should be dependent on whether the current exceeds 700A to reach required power. 
            data_valid = True
            if points_comp_power[k][n] == 0:
                data_valid = False
            plot_bar.append(data_valid)
                
            temp['Stack'] += m_stack_values[n]
            temp['Cathode']+= points_comp_power[k][n]*0.63
            temp['Cathode']+= points_turb_power[k][n]*0.63
            
            total += m_stack_values[n]
            total += points_comp_power[k][n]*0.63
            total += points_turb_power[k][n]*0.63
            
            if total > max_tracker:
                max_tracker = total
            
            
            for key,value in temp.items():
                subsystem_mass_total[points[k]][key][n] = value

            #i += 1
        
            
    print(plot_bar)
   #print(subsystem_mass_total)
    
    categories = list(subsystem_mass_total.keys())  # ['A', 'B', 'C']

    #The order, from bottom to top, that the components should be in. Place constant components at bottom so the changes are clearer.
    orders = ['Other', 'Anode', 'Thermal','Stack','Cathode']
    legend_order = [4,3,2,1,0]
    #orders = list(subsystem_mass_total[f'{points[0]}'].keys())  

    n_values = len(subsystem_mass_total[points[0]]['Stack'])  # Number of values for each subsystem

    #print(categories)
    #print(orders)
    #print(n_values)

    # Number of categories and width of each bar
    n_categories = len(categories)
    bar_width = 0.25  # Width of each bar
    group_spacing = 0.3 # Spacing between different groups
    bar_spacing = 0.05 # Spacing between bars in the same group
    #group_width = bar_width * n_values  # Total width of a group of bars

    # Positions of the groups on the x-axis
    x = np.arange(n_categories) * (n_values * (bar_width + bar_spacing) + group_spacing) #Add spacing between groups and bars

    # Initialize a plot
    fig, ax = plt.subplots(figsize=(12, 6))
    
    #print(bar_positions)
    ax.set_axisbelow(True)
    ax.yaxis.grid(True)
    
    #colors = ['#ff9999','#66b3ff','#99ff99','#ffcc99', '#cc99ff']
    cmap = plt.get_cmap('viridis')
    num_colors = len(orders)
    #num_colors=5
    #print(num_colors)
    indices = np.linspace(0, 1, num_colors)

    # Sample the colormap at these points
    colors = cmap(indices)
    
    #colors = [cmap(mcolors.Normalize(vmin=125, vmax=175)(power)) for power in highlight_powers]
    
    label_colors= ['tab:blue', 'tab:orange','tab:red']
    #print(subsystem_mass_total[max(points)]['Cathode'])

    plot_index = 0

    for i, category in enumerate(categories):
        for j in range(n_values):
            if not plot_bar[plot_index]:
                plot_index += 1
                continue
            
            bottom_values = np.zeros(1)
            bar_positions = x[i] + j * (bar_width + bar_spacing)
            
            for k, order in enumerate(orders):
                value = subsystem_mass_total[category][order][j]
                bars = ax.bar(bar_positions, value, bar_width, label=f'{order}' if j == 0 else "", bottom=bottom_values, color=colors[k])
                bottom_values += value  # Update bottom_values to stack the next bars

                
            for bar in bars:
                height = bar.get_height() + bar.get_y() +10
                ax.text(bar.get_x() + bar.get_width() / 2, height, f'{cell_no[j]} cells', ha='center', va='bottom', color='black',
                    bbox=dict(facecolor=label_colors[j], edgecolor=label_colors[j], boxstyle='round,pad=0.3', linewidth=1.5, alpha=0.6))

            #print(plot_index)
            plot_index += 1
        
    # Adding labels and title
    ax.set_xlabel('Net Power [kW]')
    ax.set_ylabel('Mass [kg]')
    ax.set_title('Predicted FCM Mass for each Net Power')
    ax.set_xticks(x + (n_values - 1) * (bar_width + bar_spacing) / 2)
    ax.set_xticklabels(categories)
    #ax.set_ylim([0, max(subsystem_mass_total[max(points)]['Cathode'])])
    ax.set_ylim([0,max_tracker +100])
    handles, labels = plt.gca().get_legend_handles_labels()

    #add legend to plot
    plt.legend([handles[idx] for idx in legend_order],[labels[idx] for idx in legend_order],title='Subsystems', loc='upper right')
    
    #ax.legend(title='Subsystems')

    # Show the plot
    plt.tight_layout()
    plt.show()
    
    
plot_mass_estimate(masses_FCM_constants)


