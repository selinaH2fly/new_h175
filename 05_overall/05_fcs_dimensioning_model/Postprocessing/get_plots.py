# %% Imports:
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
from evaluate_DoE_envelope_constraint import plot_optimized_parameter_DoE_envelope
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
 
def analyze_data(_file_path1, saving=True):
    
    # Load the CSV file into a DataFrame
    df1 = pd.read_csv(_file_path1)

    # for testing, weighting comes actually from csv
    df1['weighting']=0


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
    
    # Sort and prefilter data by index and current
    #df1 =df1[df1["converged (t/f)"] == True]
    df1 = filter_converged_points(df1, tolerance=7)
    df1 = df1.sort_values(by=['idx'])
    df1 = df1.reset_index(drop=True)
    df1 = df1[(df1["current_A (Value)"] < current_upper_bound)]
    
    # Split the data based on 'Specified Cell Count'
    df_400 = df1[(df1['Specified Cell Count'] == 400)]
    df_455 = df1[(df1['Specified Cell Count'] == 455)]
    df_500 = df1[(df1['Specified Cell Count'] == 500)] 
    
    data   = [     df_400,       df_455,     df_500]
    titles = ['400 Cells',  '455 Cells','500 Cells']
    colors = [ "tab:blue", "tab:orange",  "tab:red"]
    markers= ["o", "v", "s"]
    markers_oL = ["o","P"]
    
    fl_set = 120 #TODO: Pass that as an argument to the function
    fl_max = max(df1["Flight Level (100x ft)"])
    weighting=0

    ########Plot test:
        
    #plot_h2_vs_mass(data, titles, colors, fl_set)
    #plot_h2_vs_mass(data, titles, colors, fl_set, 0.5)
    #plot_h2_vs_mass(data, titles, colors, fl_set, 1)
    
    ###########PLOT: Polcurves
    plot_polarization_curves(data, titles, fl_set, markers_oL, weighting, saving=saving)
    
    ############PLOT: Polcurves eol vs bol connected
    plot_polarization_curves_bol_eol(df1, titles, colors, fl_set, markers_oL, weighting, saving=saving)
    
    ############PLOT: System Power Grid Plot
    #List of pd column names of data for components which will be considered.
    components = ["Power Constraint (kW)",
                  "current_A (Value)",
                  "Compressor Power (kW)",	
                  "Turbine Power (kW)",	
                  "Recirculation Pump Power (kW)",	
                  "Coolant Pump Power (kW)",	
                  "Stack Power (kW)"]
    
    plot_power_needs(data, titles, fl_set, components, weighting, saving=saving)
    
    ############PLOT: System Power Grid Plot Heat Flux
    #List of pd column names of data for components which will be considered.
    components = ["Power Constraint (kW)",
                  "current_A (Value)",
                  "Stack Heat Flux (kW)",	
                  "Intercooler Heat Flux (kW)",	
                  "Evaporator Heat Flux (kW)",	
                  "Radiator Heat Flux (kW)"]
    
    plot_power_needs_heatflux(data, titles, fl_set, components, weighting, saving=saving)    
        
    ###########PLOT: H2 supply
    plot_h2_supply_vs_systempower(data, titles, colors, fl_set, markers_oL, weighting, saving=saving)
    
    ###########PLOT: System eff vs Net Power: Flade Plot, 
    plot_system_efficiency(data, titles, colors, fl_set, markers_oL, weighting, saving=saving)
    
    #############PLOT: H2 supply vs Flightlevel:
    plot_h2_supply_vs_FL(df1, markers, fl_max, weighting, saving=saving, mode="bol")
    plot_h2_supply_vs_FL(df1, markers, fl_max, weighting, saving=saving, mode="eol")

    ############Plot Weight estimate
    #Weight/Power Factor
    
    componentsP_dict =  {"Compressor Power (kW)":   0.63,
                         "Turbine Power (kW)":      0}
    
    # New grouped, stacked bar chart function
    plot_system_mass_estimate(data, titles, colors, componentsP_dict, markers, weighting, saving=saving, mode="bol")
    plot_system_mass_estimate(data, titles, colors, componentsP_dict, markers, weighting, saving=saving, mode="eol")
    
    ###########PLOT: Compressormap
    plot_compressor_map(data, titles, colors, markers, weighting, saving=True, mode="bol")
    plot_compressor_map(data, titles, colors, markers, weighting, saving=True, mode="eol")
        
    ###########PLOT: optimized parameters in DoE envelope
    os.makedirs("DoE_Envelope_Evaluation", exist_ok=True)
    os.chdir("DoE_Envelope_Evaluation")
    
    #plot_optimized_parameter_DoE_envelope(df1, Optimized_DoE_data_variables, saving=saving)
    os.chdir("../")

    ##########PLOT: Optimized Operating Parameters

    # create a directory for the plots
    os.makedirs("Optimized_Operating_Parameters", exist_ok=True)
    os.chdir("Optimized_Operating_Parameters")

    # define opt parametersfor plotting
    # sequence is important here!
    opt_parameters = ['cathode_rh_in_perc (Value)',
                      'stoich_cathode (Value)',
                      'pressure_cathode_in_bara (Value)',
                      'temp_coolant_inlet_degC (Value)',
                      'temp_coolant_outlet_degC (Value)']
    # define ranges of plots
    yranges = [[0,140],[1,6],[1,3.4],[50,100],[50,100]]
    
    for i, (opt_parameter, yrange) in enumerate(zip(opt_parameters,yranges)):
        #We will plot current df.iloc[0] with the last column df.iloc[-1], therefore we pass columns 0:n
        doe_data_column = Optimized_DoE_data_variables.iloc[:,0:i+2] 
        plot_optimized_parameters(data, doe_data_column, titles, fl_set, markers_oL, opt_parameter, yrange, saving=True)

    # go back to the parent directory
    os.chdir("../")
    
    # Go back to origin dir
    os.chdir("../../")
    
# %%    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Main script to call get_plots.py")
    parser.add_argument("-f", "--filepath", type=str, help="path to csv file", default=r"..\test_data\optimized_parameters_20-175kW_400-500_0-120ft.csv")

    parser.add_argument("-s", "--saving", type=str, choices=["True", "False"], default="True", help="Whether to save plots as .png files")
    args = parser.parse_args()
    
    # Convert 'True'/'False' string to boolean
    saving = args.saving == "True"
    
    # Run analyze_data as an example if the script is called directly
    analyze_data(args.filepath, saving)