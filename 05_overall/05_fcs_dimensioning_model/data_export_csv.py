# -*- coding: utf-8 -*-
"""
Created on Fri Jul 26 12:47:08 2024

@author: wenzel.gassner
"""
    
import csv
import os

def export_to_csv(results, feature_names, power_constraint_kW, specified_cell_count, 
                  flight_level_100ft, consider_turbine, end_of_life, 
                  multiobjective_weighting, filename='optimized_input_data.csv'):
    """
    Export optimization results to a CSV file.
    
    Parameters:
    - results: Instance of ResultModels containing optimization results.
    - feature_names: List of feature names for the optimized input variables.
    - power_constraint_kW: Power constraint in kW.
    - specified_cell_count: Specified cell count.
    - flight_level_100ft: Flight level in 100 ft units.
    - consider_turbine: Boolean indicating if the turbine is considered.
    - end_of_life: Boolean indicating end-of-life condition.
    - multiobjective_weighting: Weighting value for multi-objective optimization.
    - filename: CSV file name for saving the data.
    """
    
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
            header.extend(['Hydrogen Supply Rate (g/s)', 'Cell Voltage (V)', 
                           'System Power (kW)', 'Compressor Power (kW)', "Turbine Power (kW)", "Recirculation Pump Power (kW)",
                           'Coolant Pump Power (kW)', "Stack Power (kW)", "Compressor Corrected Air Flow (g/s)", "Compressor Pressure Ratio (-)",
                           "Stack Heat Flux (kW)", "Intercooler Heat Flux (kW)","Evaporator Heat Flux (kW)","Radiator Heat Flux (kW)", "System Mass (kg)",
                           "fixed Mass (kg)","power dependent Mass (kg)", "Cell dependent Mass (kg)","H2 dependent Mass (kg)",  
                           "turbine (t/f)","eol (t/f)", "weighting ([0,1])", "converged (t/f)"])
            writer.writerow(header)
            
        # Prepare data for export, converting relevant fields to the desired units
        data = [idx, power_constraint_kW, specified_cell_count, flight_level_100ft]
        data.extend([f'{value:.4f}' for value in results.optimized_input])  # Optimized input values
        data.extend([
            f'{results.hydrogen_supply_rate_g_s:.4f}', f'{results.cell_voltage_V:.4f}', 
            f'{results.system_power_W / 1000:.2f}', f'{results.compressor_power_W / 1000:.2f}', 
            f'{results.turbine_power_W / 1000:.2f}', f'{results.reci_pump_power_W / 1000:.2f}',
            f'{results.coolant_pump_power_W / 1000:.2f}', f'{results.stack_power_W / 1000:.2f}',
            f'{results.compressor_cor_mass_flow_g_s:.2f}', f'{results.compressor_pressure_ratio:.2f}',
            f'{results.stack_heat_flux_W / 1000:.2f}', f'{results.intercooler_heat_flux_W / 1000:.2f}',
            f'{results.evaporator_heat_flux_W / 1000:.2f}', f'{results.radiator_heat_flux_W / 1000:.2f}', 
            f'{results.system_mass_kg:.2f}', f'{results.fixed_mass:.2f}', f'{results.power_dependent_mass:.2f}',
            f'{results.cellcount_dependent_mass:.2f}',f'{results.H2_dependend_mass:.2f}',
            f'{consider_turbine}', f'{end_of_life}', 
            f'{multiobjective_weighting}', f'{results.optimization_converged}'
        ])
        
        # Write the data row to the CSV
        writer.writerow(data)
        #print("data written to csv.")