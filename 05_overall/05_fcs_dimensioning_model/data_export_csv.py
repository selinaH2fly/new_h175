# -*- coding: utf-8 -*-
"""
Created on Fri Jul 26 12:47:08 2024

@author: wenzel.gassner
"""
    
import csv
import os

def export_to_csv(feature_names, optimal_input, bounds, hydrogen_mass_flow_g_s, cell_voltage, 
                  system_power_kW, compressor_power_kW, turbine_power_kW, reci_pump_power_kW, coolant_pump_power_kW, stack_power_kW,
                  power_constraint_kW, specified_cell_count, flight_level_100ft, consider_turbine, end_of_life, converged, filename='optimized_input_data.csv'):
    # Get the current directory
    current_dir = os.getcwd()
    
    # Extract the number from the directory name to use it as index in the csv
    dir_name = os.path.basename(current_dir)
    idx = dir_name.split('_')[0]
    
    # Check if the file already exists to determine if we need to write the header
    file_exists = os.path.isfile(filename)
    
    with open(filename, 'a', newline='') as file:
        writer = csv.writer(file)
        
        # Write the header if the file does not exist
        if not file_exists:
            header = ['idx','Power Constraint (kW)', 'Specified Cell Count', 'Flight Level (100x ft)']
            header.extend([f'{name} (Value)' for name in feature_names])
            header.extend([f'{name} (Lower Bound)' for name in feature_names])
            header.extend([f'{name} (Upper Bound)' for name in feature_names])
            header.extend(['Hydrogen Consumption (g/s)', 'Cell Voltage (V)', 
                           'System Power (kW)', 'Compressor Power (kW)', "Turbine Power (kW)", "Recirculation Pump Power (kW)",
                           'Coolant Pump Power (kW)', "Stack Power (kW)", "turbine (t/f)","eol (t/f)", "converged (t/f)"])
            writer.writerow(header)
        
        # Write the data
        data = [idx,power_constraint_kW, specified_cell_count, flight_level_100ft]
        data.extend([f'{value:.4f}' for value in optimal_input])
        data.extend([f'{bound[0]:.4f}' for bound in bounds])
        data.extend([f'{bound[1]:.4f}' for bound in bounds])
        data.extend([f'{hydrogen_mass_flow_g_s:.4f}', f'{cell_voltage:.4f}', 
                     f'{system_power_kW:.2f}', f'{compressor_power_kW:.2f}', 
                     f'{turbine_power_kW:.2f}', f'{reci_pump_power_kW:.2f}',
                     f'{coolant_pump_power_kW:.2f}', f'{stack_power_kW:.2f}',
                     f'{consider_turbine}', f'{end_of_life}', f'{converged}'])
        writer.writerow(data)