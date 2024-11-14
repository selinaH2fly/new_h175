import os
import pandas as pd

# Define the directory containing CSV files
folder_path = r"C:\Users\tobias.goosmann\Documents\GIT\h175model\03_stack\02_doe_data\06_p10_doe_gpr_GTSuite\simulationresult_GTSuite"
csv_files = [file for file in os.listdir(folder_path) if file.endswith('.csv')]

# check if there are any CSV files
if not csv_files:
    print("No CSV files found in the specified folder.")
    exit()

# Display available CSV files
print("Available CSV files:")
for i, file in enumerate(csv_files, start=1):
    print(f"{i}. {file}")

# select files to load
selected_files = input("Enter file numbers separated by commas or tpye'all' to select all: ")
if selected_files.lower() == 'all':
    selected_files = csv_files
else:
    selected_indices = [int(idx.strip()) - 1 for idx in selected_files.split(',')]
    selected_files = [csv_files[i] for i in selected_indices]

# load and combine seletcted csv files
data_frames = [pd.read_csv(os.path.join(folder_path, file)) for file in selected_files]
combined_data = pd.concat(data_frames, ignore_index=True)

# rename columns if necessary
# rename_columns={
#   # 'old_column_name1 (from GT)': 'new_column_name1 (chosen)',
#   # 'old_column_name2 (from GT)': 'new_column_name2 (chosen)'
# }
rename_columns = {
    'Voltage; Part SubAssemblyExternal-1'                               :'U_Stack_V', # overall performance
    'Current; Part SubAssemblyExternal-1'                               :'I_Stack_A',
    'Electrical Power; Part SubAssemblyExternal-1'                      :'P_el_kW',
    'Fuel Power; Part SubAssemblyExternal-1'                            :'P_fuel_kW',
    'Fuel Efficiency; Part SubAssemblyExternal-1'                       :'efficiency_H2_frac', 
    'Relative Humidity (Outlet); Part An_inlet-1'                       :'RH_an_in_percent', #fluid inlets
    'Relative Humidity (Outlet); Part Cathode_inlet'                    :'RH_cat_in_percent', 
    'Anode Stoichiometric Ratio; Part SubAssemblyExternal-1'            :'stoich_an_1',
    'Cathode Stoichiometric Ratio; Part SubAssemblyExternal-1'          :'stoich_cat_1',
    'Average Pressure (Outlet); Part Coolant_inlet'                     :'p_cool_in_bar',
    'Average Pressure (Outlet); Part An_inlet-1'                        :'p_an_in_bar',
    'Average Pressure (Outlet); Part Cathode_inlet'                     :'p_cat_in_bar',
    'Average Temperature (Outlet); Part Cathode_inlet'                  :'T_cat_in_K',
    'Average Temperature (Outlet); Part An_inlet-1'                     :'T_an_in_K',
    'Average Temperature (Outlet); Part Coolant_inlet'                  :'T_cool_in_K',
    'H2 Anode in; Part RLTCreator-1'                                    :'xH2_an_in_frac',
    'N2 Anode in; Part RLTCreator-1'                                    :'xN2_an_in_frac',
    'H2Ovap Anode in; Part RLTCreator-1'                                :'xH2Ovap_an_in_frac',
    'H2Oliq Anode in; Part RLTCreator-1'                                :'xH2Oliq_an_in_frac',
    'O2 Cathode in; Part RLTCreator-1'                                  :'xO2_cat_in_frac',
    'N2 Cathode in; Part RLTCreator-1'                                  :'xN2_cat_in_frac',
    'H2Ovap Cathode in; Part RLTCreator-1'                              :'xH2Ovap_cat_in_frac',
    'H2Oliq Cathode in; Part RLTCreator-1'                              :'xH2Oliq_cat_in_frac',
    'Average Mass Flow Rate (Outlet); Part An_inlet-1'                  :'m_dot_an_in_g_s',
    'Average Mass Flow Rate (Outlet); Part Cathode_inlet'               :'m_dot_cat_in_g_s',
    'Average Mass Flow Rate (Outlet); Part Coolant_inlet'               :'m_dot_cool_in_g_s',
    'm_dot_an; Part Anode_lambda'                                       :'m_dot_an_in_calc_g_s',
    'm_dot_cath; Part Cathode_lambda'                                   :'m_dot_cat_in_calc_g_s',
    'Volumetric Flow Rate coolant set'                                  :'c_cool_I_l_min_A',
    'Relative Humidity (Outlet); Part An_outlet'                        :'RH_an_out_percent', # fluid outlet values
    'Relative Humidity (Outlet); Part Cathode_outlet'                   :'RH_cat_out_percent',
    'Average Pressure (Outlet); Part Coolant_outlet'                    :'p_cool_out_bar',
    'Average Pressure (Outlet); Part An_outlet'                         :'p_an_out_bar',
    'Average Pressure (Outlet); Part Cathode_outlet'                    :'p_cat_out_bar',
    'Average Temperature (Outlet); Part Cathode_outlet'                 :'T_cat_out_K',
    'Average Temperature (Outlet); Part An_outlet'                      :'T_an_out_K',
    'Average Temperature (Outlet); Part Coolant_outlet'                 :'T_cool_out_K',
    'H2 Anode out; Part RLTCreator-1'                                   :'xH2_an_out_frac',
    'N2 Anode out; Part RLTCreator-1'                                   :'xN2_an_out_frac',
    'H2Ovap Anode out; Part RLTCreator-1'                               :'xH2Ovap_out_frac',
    'H2Oliq Anode out; Part RLTCreator-1'                               :'xH2Oliq_out_frac',
    'O2 Cathode out; Part RLTCreator-1'                                 :'xO2_cat_out_frac',
    'N2 Cathode out; Part RLTCreator-1'                                 :'xN2_cat_out_frac',
    'H2Ovap Cathode out; Part RLTCreator-1'                             :'xH2Ovap_cat_out_frac',
    'H2Oliq Cathode out; Part RLTCreator-1'                             :'xH2Oliq_cat_out_frac',
    'Average Mass Flow Rate (Outlet); Part Cathode_outlet'              :'m_dot_cat_out_g_s',
    'Average Mass Flow Rate (Outlet); Part An_outlet'                   :'m_dot_an_out_g_s',
    'Average Mass Flow Rate (Outlet); Part Coolant_outlet'              :'m_dot_cool_out_g_s',
    'Membrane Humidity; Part SubAssemblyExternal-1'                     :'RH_membrane_percent', # stack internal parameters
    'Membrane Water Content Average; Part SubAssemblyExternal-1'        :'water_mem_av_1',
    'Water_Content_Vol_1; Part SubAssemblyExternal-1'                   :'water_mem_vol1_1',
    'Water_Content_Vol_2; Part SubAssemblyExternal-1'                   :'water_mem_vol2_1',
    'Water_Content_Vol_3; Part SubAssemblyExternal-1'                   :'water_mem_vol3_1',
    'Water_Content_Vol_4; Part SubAssemblyExternal-1'                   :'water_mem_vol4_1',
    'Water_Content_Vol_5; Part SubAssemblyExternal-1'                   :'water_mem_vol5_1',
    'Mass Rate of Hydrogen Crossover; Part SubAssemblyExternal-1'       :'m_dot_H2_cross_g_s',
    'Mass Rate of Nitrogen Crossover; Part SubAssemblyExternal-1'       :'m_dot_N2_cross_g_s',
    'Mass Rate of Water Crossover (Anode); Part SubAssemblyExternal-1'  :'m_dot_H2O_cross_g_s',
    'Mass Rate of Oxygen Crossover; Part SubAssemblyExternal-1'         :'m_dot_O2_cross_g_s',
    'T_degC_Vol_1; Part SubAssemblyExternal-1'                          :'T_vol1_C',
    'T_degC_Vol_2; Part SubAssemblyExternal-1'                          :'T_vol2_C',
    'T_degC_Vol_3; Part SubAssemblyExternal-1'                          :'T_vol3_C',
    'T_degC_Vol_4; Part SubAssemblyExternal-1'                          :'T_vol4_C',
    'T_degC_Vol_5; Part SubAssemblyExternal-1'                          :'T_vol5_C',
    'Output 1; Part Gain-2-1'                                           :'RH_an_vol1_percent',
    'Output 1; Part Gain-3-1'                                           :'RH_an_vol2_percent',
    'Output 1; Part Gain-4-1'                                           :'RH_an_vol3_percent',
    'Output 1; Part Gain-5-1'                                           :'RH_an_vol4_percent',
    'Output 1; Part Gain-6-1'                                           :'RH_an_vol5_percent',
    'Output 1; Part Gain-7-1'                                           :'RH_cat_vol1_percent',
    'Output 1; Part Gain-8-1'                                           :'RH_cat_vol2_percent',
    'Output 1; Part Gain-9-1'                                           :'RH_cat_vol3_percent',
    'Output 1; Part Gain-10-1'                                          :'RH_cat_vol4_percent',
    'Output 1; Part Gain-11-1'                                          :'RH_cat_vol5_percent',
    'Voltage Loss - Activation; Part SubAssemblyExternal-1'             :'eta_act_V',
    'Voltage Loss - Transport; Part SubAssemblyExternal-1'              :'eta_trans_V',
    'Voltage Loss - Ohmic; Part SubAssemblyExternal-1'                  :'eta_ohm_V',
    'Anode Stoichiometry set'                                           :'stoich_an_set_1', # set values
    'Cathode Stoichiometry set'                                         :'stoich_cat_set_1',
    'Temperature anode inlet set'                                       :'T_an_in_set_C',
    'Temperature cathode inlet set'                                     :'T_cat_in_set_C',
    'Temperature coolant inlet set'                                     :'T_cool_in_set_C',
    'factor pressure difference anode2 cathode'                         :'factor_dp_a2c_1',
    'Pressure (Absolute) cathode outlet set'                            :'p_cat_out_set_bar',
    'Pressure (Absolute) coolant outlet set'                            :'p_cool_out_set_bar',
    'Relative Humidity anode inlet set'                                 :'RH_an_in_set_frac',
    'Relative Humidity cathode inlet set'                               :'RH_cat_in_set_frac'
}
combined_data.rename(columns=rename_columns, inplace= True)

# remove rows containing the word "unit" in any column
# Filter out rows containing the word "unit" in any string cell
combined_data = combined_data[~combined_data.apply(lambda row: row.apply(lambda x: 'unit' in x.lower() if isinstance(x, str) else False).any(), axis=1)]
combined_data = combined_data.dropna()

# convert all columns to numeric (without this line, calculation fails)
combined_data = combined_data.apply(pd.to_numeric, errors='coerce')
# add new columns and execute calculations
combined_data['m_dot_cool_in_set']  = 72.8 + combined_data['I_Stack_A'] * combined_data['c_cool_I_l_min_A'] 
combined_data['p_an_out_set_bar']   = combined_data['p_cat_out_set_bar'] * combined_data['factor_dp_a2c_1']
combined_data['T_cat_in_C']         = combined_data['T_cat_in_K']   - 273.15
combined_data['T_an_in_C']          = combined_data['T_an_in_K']    - 273.15
combined_data['T_cool_in_C']        = combined_data['T_cool_in_K']  - 273.15
combined_data['T_cat_out_C']        = combined_data['T_cat_out_K']  - 273.15
combined_data['T_an_out_C']         = combined_data['T_an_out_K']   - 273.15
combined_data['T_cool_out_C']       = combined_data['T_cool_out_K'] - 273.15

print(combined_data)
# save combined data to a new CSV
output_path = r"C:\Users\tobias.goosmann\Documents\GIT\h175model\03_stack\02_doe_data\06_p10_doe_gpr_GTSuite\input_data\combined_data.csv"
# output_path = r"C:\Users\tobias.goosmann\Documents\Python_tutorials\genbasics"
combined_data.to_csv(output_path,index=False)
print(f"Combined data saved to {output_path}")