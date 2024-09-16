# %% Imports:
import pandas as pd
import os
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import matplotlib.lines as mlines
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score

# Import plot functions defined in a separate file
from get_plots_operating_parameters import plot_cathode_inlet_pressure, plot_cathode_inlet_realtive_humidity, \
    plot_cathode_stoichiomtrey, plot_coolant_inlet_temperature, plot_coolant_outlet_temperature

    
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

    # Change the working directory to the directory containing the .csv file
    file_dir = os.path.dirname(_file_path1)
    os.chdir(file_dir)

    # Create a new directory for plots
    os.makedirs("00_Plots", exist_ok=True)
    os.chdir("00_Plots")
    
    # Sort and prefilter data by index and current
    #df1 =df1[df1["converged (t/f)"] == True]
    df1 = filter_converged_points(df1, tolerance=7)
    df1 = df1.sort_values(by=['idx'])
        
    # Split the data based on 'Specified Cell Count'
    df_400 = df1[df1['Specified Cell Count'] == 400]
    df_450 = df1[df1['Specified Cell Count'] == 450]
    df_500 = df1[df1['Specified Cell Count'] == 500]
    
    data   = [     df_400,       df_450,     df_500]
    titles = ['400 Cells',  '450 Cells','500 Cells']
    colors = [ "tab:blue", "tab:orange",  "tab:red"]
    markers= ["o", "v", "s"]
    
    fl_set = 120 #TODO: Pass that as an argument to the function
    fl_max = max(df1["Flight Level (100x ft)"])
    
    ###########PLOT: Polcurves
    plot_polarization_curves(data, titles, fl_set, saving=saving)

    ###########PLOT: Optimized Operating Parameters

    # create a directory for the plots
    os.makedirs("Optimized_Operating_Parameters", exist_ok=True)
    os.chdir("Optimized_Operating_Parameters")

    # call the plot functions
    plot_cathode_inlet_pressure(data, titles, fl_set, saving=saving)
    plot_cathode_inlet_realtive_humidity(data, titles, fl_set, saving=saving)
    plot_cathode_stoichiomtrey(data, titles, fl_set, saving=saving)
    plot_coolant_inlet_temperature(data, titles, fl_set, saving=saving)
    plot_coolant_outlet_temperature(data, titles, fl_set, saving=saving)

    # go back to the parent directory
    os.chdir("../")
    
    ############PLOT: Polcurves eol vs bol connected
    plot_polarization_curves_bol_eol(df1, titles, colors, fl_set, saving=saving)
    
    ############PLOT: System Power Grid Plot
    plot_power_needs(data, titles, fl_set, saving=saving)
    
    ###########PLOT: H2 consumption
    weights = [1,1,1]#[39.92+ 6.26,43.75+6.01,47.58+5.77] #stack + compressor gewicht
    plot_h2_consumption(data, titles, colors, weights, fl_set, saving=saving)
        
    ###########PLOT: System eff vs Net Power: Flade Plot, 
    plot_system_efficiency(data, titles, colors, fl_set, saving=saving)
    
    #############PLOT: H2 consumption vs Flightlevel:
    H2_consumption_vs_FL(df1, markers, fl_max, saving=saving, mode="bol")
    H2_consumption_vs_FL(df1, markers, fl_max, saving=saving, mode="eol")

    ############Plot Weight estimate
    #Weight/Power Factor
    
    componentsP_dict =  {"Compressor Power (kW)":   0.63,
                         "Turbine Power (kW)":      0}
    
    # New grouped, stacked bar chart function
    plot_mass_estimate(data, titles, colors, componentsP_dict, markers, saving=saving, mode="bol")
    plot_mass_estimate(data, titles, colors, componentsP_dict, markers, saving=saving, mode="eol")  
    
# Go back to origin dir
    os.chdir("../../")
    
# %%    

analyze_data(_file_path1=r"consolidated_20-175kW_400-500_0-150ft__2_std\optimized_parameters_20-175kW_400-500_0-150ft.csv", saving=True) 