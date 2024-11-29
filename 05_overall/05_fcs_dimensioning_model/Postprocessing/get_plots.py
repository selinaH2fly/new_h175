# %% Imports:
import numpy as np
import pandas as pd
import os
import sys
import argparse

# Adjust sys.path if running directly
current_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.abspath(os.path.join(current_dir, os.pardir))
sys.path.append(current_dir)
sys.path.append(parent_dir)

import data_processing 
import parameters

# Import plot functions defined in a separate file
from get_plots_operating_parameters import plot_optimized_parameters
from plot_pol_curves import plot_polarization_curves
from plot_pol_curves_connected import plot_polarization_curves_bol_eol
from plot_power_grid import plot_power_needs #annotate_boxes, format_data_for_plot, 
from plot_power_grid_heatflux import plot_power_needs_heatflux
from plot_h2_supply_vs_systempower import plot_h2_supply_vs_systempower
from plot_system_efficiency import plot_system_efficiency
from plot_h2_supply_vs_FL import plot_h2_supply_vs_FL
from plot_system_mass_estimate import plot_system_mass_estimate
from plot_DoE_envelope_constraint import plot_optimized_parameter_DoE_envelope
from plot_compressor_map import plot_compressor_map
from plot_h2_vs_mass import plot_h2_vs_mass
#%%  
def filter_converged_points(df, tolerance=4):
    """
    Filters the DataFrame for rows where the 'System Power (kW)' and 'Power Constraint (kW)'
    columns are within a given tolerance.

    Parameters:
    - df: DataFrame to filter
    - tolerance: Maximum allowable difference between 'System Power (kW)' and 'Power Constraint (kW)'

    Returns:
    - Filtered DataFrame
    """
    # Compute the absolute difference between the two columns
    df['Difference'] = abs(df['System Power (kW)'] - df['Power Constraint (kW)'])
    
    # Filter the DataFrame based on the tolerance
    filtered_df = df[df['Difference'] <= tolerance]
    
    # Drop the helper column used for filtering
    filtered_df = filtered_df.drop(columns=['Difference'])
    
    return filtered_df

# Sort and prefilter data by index and current
def sort_prefilter_df(df, current_upper_bound):
    df = filter_converged_points(df, tolerance=7)
    df = df.sort_values(by=['idx'])
    df = df.reset_index(drop=True)
    df = df[(df["current_A (Value)"] < current_upper_bound)]
    return df

# Split the data based on 'Specified Cell Count'
def split_data_based_on_cell_count(df): 
    return  [group for _, group in df.groupby('Specified Cell Count')]


def get_unique_values(df, column_name): 
    return sorted(df[column_name].unique())

def get_min_max_values_axes(axes, df, scale_min=0.9, scale_max=1.1): 
    min_max_list=  [
        (np.round(df[axis].min() * scale_min), np.round(df[axis].max() * scale_max)) 
        for axis in axes
    ]
    return min_max_list[0] if len(axes) == 1 else min_max_list


def check_empty_df(df): 
    return df.empty


def analyze_data(_file_path1, saving=True):
    
    # Load the CSV file into a DataFrame
    df1 = pd.read_csv(_file_path1)
    #df1 = df1.loc[df1['Specified Cell Count'] != 455]

    # Change the working directory to the directory containing the .csv file
    file_dir = os.path.dirname(_file_path1)
    os.chdir(file_dir)
    
    # Load the DoE High AMP Data
    DoE_data, _ = data_processing.load_high_amp_doe_data()
    
    # reduce DoE-Data to optimized parameters
    Optimized_DoE_data_variables = data_processing.voltage_input_data_dict(DoE_data,parameters.Physical_Parameters())
    Optimized_DoE_data_variables = pd.DataFrame(Optimized_DoE_data_variables)
    current_upper_bound = Optimized_DoE_data_variables["current_A"].max()
    
    # Create a new directory for plots
    os.makedirs("00_Plots", exist_ok=True)
    os.chdir("00_Plots")
    
    # Sort and prefilter data
    #df1 =df1[df1["converged (t/f)"] == True]
    df1 = sort_prefilter_df(df1, current_upper_bound)

    if check_empty_df(df1): 
        print("df is empty after prefilter, skip plotting")
        return

    # get flight level, weighting, cellcounts from csv
    fl_set = get_unique_values(df1, 'Flight Level (100x ft)')
    weighting = get_unique_values(df1, 'weighting ([0,1])')
    cellcounts = get_unique_values(df1, 'Specified Cell Count')


    # Split the data
    data = split_data_based_on_cell_count(df1)

    titles = [f'{cells} Cells' for cells in cellcounts]
    fl_max = max(df1["Flight Level (100x ft)"])
    
    ########Plot general:   
    params_general = {
    'data': data,
    'fl': fl_set, 
    'fl_max' : fl_max,
    'weightings': weighting,
    'cellcounts': cellcounts, 
    'titles' : titles,
    'colors': [ "tab:blue", "tab:orange",  "tab:red"], 
    'markers': ["o", "v", "s"],
    'markers_oL':  ["o","P"],  
    'show_plot' : False, 
    }

    ########Plot test:   
    plot_params_h2_vs_mass = {
    'title': '', 
    'x_label': 'System Mass [kg]', 
    'x_lim': get_min_max_values_axes(['System Mass (kg)'], df1), 
    'y_label': 'Hydrogen Supply Rate [g/s]',
    'y_lim': get_min_max_values_axes(['Hydrogen Supply Rate (g/s)'], df1), 
    'label' : ["H2 supply", "system mass"], 
    'vmin' : 100, 
    'vmax' : 150
    }
    plot_h2_vs_mass(plot_params_h2_vs_mass, params_general, show_plot=params_general['show_plot'], saving=saving)
    
    ###########PLOT: Polcurves
    plot_params_polarization_curves = {
    'title': '', 
    'x_label': 'Current [A]', 
    'x_lim': get_min_max_values_axes(['current_A (Value)'], df1),
    'y_label': 'Cell Voltage [V]',
    'y_lim': get_min_max_values_axes(['Cell Voltage (V)'], df1, scale_min=0.5),  
    'label' : [ 'BoL', 'EoL'], 
    'vmin' : 120, 
    'vmax' : 150
    }
    plot_polarization_curves(plot_params_polarization_curves, params_general, show_plot=params_general['show_plot'], saving=saving)
    
    ############PLOT: Polcurves eol vs bol connected
    plot_params_polarization_curves_bol_eol = {
    'title': '', 
    'x_label': 'Current [A]', 
    'x_lim': get_min_max_values_axes(['current_A (Value)'], df1), 
    'y_label': 'Cell Voltage [V]',
    'y_lim': get_min_max_values_axes(['Cell Voltage (V)'], df1, scale_min=0.5),  
    'label' : [ 'BoL', 'EoL'], 
    }
    plot_polarization_curves_bol_eol(plot_params_polarization_curves_bol_eol, params_general, show_plot=params_general['show_plot'], saving=saving)
    
    ############PLOT: System Power Grid Plot
    plot_params_power_needs = {
    'title': '', 
    'vmin' : 0.1, 
    'vmax' : 225, 
    'power_range' : [130,135,140,145,150], 
    # Adjust labels for the secondary x-axis
    'names': ["Compressor (+)", "Turbine (-)", "Reci. Pump (+)", "Coolant Pump (+)", "Stack (-)"],   
    # List of pd column names of data for components which will be considered.
    'components' :  ["Power Constraint (kW)",
                  "current_A (Value)",
                  "Compressor Power (kW)",	
                  "Turbine Power (kW)",	
                  "Recirculation Pump Power (kW)",	
                  "Coolant Pump Power (kW)",	
                  "Stack Power (kW)"]
    }      
    plot_power_needs(plot_params_power_needs, params_general, show_plot=params_general['show_plot'], saving=saving)
    
    ############PLOT: System Power Grid Plot Heat Flux
    plot_params_power_needs_heatflux = {
    'title': '', 
    'vmin' : 0.1, 
    'vmax' : 225, 
    'power_range' : [130,135,140,145,150], 
    'names': ["Stack (+)", "Intercooler (+)", "Evaporator (-)", "Radiator (+)"],   
    'components' :  ["Power Constraint (kW)",
                  "current_A (Value)",
                  "Stack Heat Flux (kW)",	
                  "Intercooler Heat Flux (kW)",	
                  "Evaporator Heat Flux (kW)",	
                  "Radiator Heat Flux (kW)"]
    }
    plot_power_needs_heatflux(plot_params_power_needs_heatflux, params_general, show_plot=params_general['show_plot'], saving=saving)    
   

    ###########PLOT: H2 supply
    plot_params_supply_vs_systempower = {
    'title': '', 
    'x_label': 'System Power [kW]', 
    'x_lim': get_min_max_values_axes(['System Power (kW)'], df1),
    'y_label': 'Hydrogen Supply Rate [g/s]',
    'y_lim': get_min_max_values_axes(['Hydrogen Supply Rate (g/s)'], df1),  
    }
    plot_h2_supply_vs_systempower(plot_params_supply_vs_systempower, params_general, show_plot=params_general['show_plot'], saving=saving)

    ###########PLOT: System eff vs Net Power: Flade Plot, 
    plot_params_system_efficiency = {
    'title': '', 
    'x_label': 'System Power [kW]', 
    'x_lim': get_min_max_values_axes(['System Power (kW)'], df1), 
    'y_label': 'System Efficiency [-]',
    'y_lim': None,  
    }
    plot_system_efficiency(plot_params_system_efficiency, params_general, show_plot=params_general['show_plot'], saving=saving)
    
    #############PLOT: H2 supply vs Flightlevel:
    plot_params_supply_vs_FL = {
        'title': '', 
        'x_label': 'Flight Level [100x ft]', 
        'x_lim': get_min_max_values_axes(['Flight Level (100x ft)'], df1), 
        'y_label': 'Hydrogen Supply Rate [g/s]',
        'y_lim': get_min_max_values_axes(['Hydrogen Supply Rate (g/s)'], df1), 
        'vmin' : 125, 
        'vmax' : 175, 
    }
    plot_h2_supply_vs_FL(plot_params_supply_vs_FL, params_general, show_plot=params_general['show_plot'], saving=saving, mode="bol")
    plot_h2_supply_vs_FL(plot_params_supply_vs_FL, params_general, show_plot=params_general['show_plot'], saving=saving, mode="eol")

    ############Plot Weight estimate
    #Weight/Power Factor
    plot_params_system_mass_estimate = {
        'title': '', 
        'x_label': 'Net Power [kW]', 
        'x_lim': None,
        'y_label': 'Mass [kg]',
        'y_lim': get_min_max_values_axes(['System Mass (kg)'], df1),  
    }
    componentsP_dict =  {"Compressor Power (kW)":   0.63,
                         "Turbine Power (kW)":      0}
    
    # New grouped, stacked bar chart function
    ## NOCHMAL ANSCHAUEN
    #plot_system_mass_estimate(plot_params_system_mass_estimate, params_general, componentsP_dict, show_plot=params_general['show_plot'], saving=saving, mode="bol")
    #plot_system_mass_estimate(plot_params_system_mass_estimate, params_general, componentsP_dict, show_plot=params_general['show_plot'], saving=saving, mode="eol")

    ###########PLOT: Compressormap
    plot_params_compressor_map = {
        'title': '', 
        'x_label': 'Corrected Air Flow [g/s]', 
        'x_lim': get_min_max_values_axes(['Compressor Corrected Air Flow (g/s)'], df1),  
        'y_label': 'Compressor Pressure Ratio [-]',
        'y_lim': get_min_max_values_axes(['Compressor Pressure Ratio (-)'], df1),  
        'vmin' : 20, 
        'vmax' : 175, 

    }
    plot_compressor_map(plot_params_compressor_map, params_general, show_plot=params_general['show_plot'], saving=saving, mode="bol")
    plot_compressor_map(plot_params_compressor_map, params_general, show_plot=params_general['show_plot'], saving=saving, mode="eol")
        
    ###########PLOT: optimized parameters in DoE envelope
    os.makedirs("DoE_Envelope_Evaluation", exist_ok=True)
    os.chdir("DoE_Envelope_Evaluation")
    
    #plot_optimized_parameter_DoE_envelope(df1, Optimized_DoE_data_variables, saving=saving)
    os.chdir("../")

    ##########PLOT: Optimized Operating Parameters


    # define opt parametersfor plotting
    # sequence is important here!
    plot_optimized_params = {
        'title': '', 
        'x_label': 'Current [A]', 
        'x_lim': get_min_max_values_axes(['current_A'], Optimized_DoE_data_variables, scale_min=0.3),
        'y_label': '',
        'y_lim': None,  
        'opt_parameters' : ['cathode_rh_in_perc (Value)',
                      'stoich_cathode (Value)',
                      'pressure_cathode_in_bara (Value)',
                      'temp_coolant_inlet_degC (Value)',
                      'temp_coolant_outlet_degC (Value)',
                      'stoich_anode (Value)', 
                      'pressure_anode_in_bara (Value)'], 
        'yranges' : None, 
        'vmin' : 20, 
        'vmax' : 150, 
 
    }


    yranges = get_min_max_values_axes(['cathode_rh_in_perc',
                      'stoich_cathode',
                      'pressure_cathode_in_bara',
                      'temp_coolant_inlet_degC',
                      'temp_coolant_outlet_degC',
                      'stoich_anode', 
                      'pressure_anode_in_bara'], Optimized_DoE_data_variables, scale_max=1.5)
    plot_optimized_params.update({'yranges':  yranges})

    for i, (plot_optimized_params['opt_parameters'], plot_optimized_params['yranges']) in enumerate(zip(plot_optimized_params['opt_parameters'],plot_optimized_params['yranges'])):
        #We will plot current df.iloc[0] with the last column df.iloc[-1], therefore we pass columns 0:n
        doe_data_column = Optimized_DoE_data_variables.iloc[:,0:i+2] 
        plot_optimized_parameters(plot_optimized_params, params_general, doe_data_column, show_plot=params_general['show_plot'], saving=saving)

    # go back to the parent directory
    os.chdir("../")
    
    # Go back to origin dir
    os.chdir("../../")
    
# %%    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Main script to call get_plots.py")
    parser.add_argument("-f", "--filepath", type=str, help="path to csv file", default=r"05_overall\05_fcs_dimensioning_model\test_data\optimized_parameters_30-150kW_400-500_100-100ft.csv")

    parser.add_argument("-s", "--saving", type=str, choices=["True", "False"], default="True", help="Whether to save plots as .png files")
    args = parser.parse_args()
    
    # Convert 'True'/'False' string to boolean
    saving = args.saving == "True"
    
    # Run analyze_data as an example if the script is called directly
    analyze_data(args.filepath, saving)