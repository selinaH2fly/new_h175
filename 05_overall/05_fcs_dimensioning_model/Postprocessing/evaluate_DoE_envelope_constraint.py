import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import textwrap

def plot_optimized_parameter_DoE_envelope(df1,Optimized_DoE_data_variables, saving=False):

    parameter_list = ["current_A (Value)",
    "cathode_rh_in_perc (Value)",
    "stoich_cathode (Value)",
    "pressure_cathode_in_bara (Value)",
    "temp_coolant_inlet_degC (Value)",
    "temp_coolant_outlet_degC (Value)",
    ]
    #df1 = df1.reset_index(drop=True)
    df1_red = df1[parameter_list]

    # plot optimal input parameters in DoE-Data     

    for index, row in df1.iterrows():
        # get the optimized input variables
        optimal_input = df1_red.iloc[index]

        # Format the simulation info text
        sim_info_text = f"""
        Index: {df1["idx"].iloc[index]}
        Power Constraint: {df1["Power Constraint (kW)"].iloc[index]}
        Cell Count: {df1["Specified Cell Count"].iloc[index]} 
        FL: {df1["Flight Level (100x ft)"].iloc[index]}
        EOL: {df1["eol (t/f)"].iloc[index]}
        """
        # plot the data
        fig, axs = plt.subplots(2, 3, figsize=(20, 8))
        props = dict(boxstyle='round,pad=0.5',facecolor='lightgrey', edgecolor='black')
        fig.text(0.75, 0.65, sim_info_text, fontsize=14, bbox=props, family="monospace")
        for plots in range(len(optimal_input)-1):
            DoE_position = plots+1
            x = Optimized_DoE_data_variables.iloc[:,0]
            y = Optimized_DoE_data_variables.iloc[:,DoE_position]
            

        # Füge den Informationskasten zum Plot hinzu
            #plt.text(8, 0.5, sim_setup, fontsize=12, bbox=dict(facecolor='yellow', alpha=0.5))

            if plots < 2:
                axs[0,plots].scatter(x, y, color='black', label=f'{Optimized_DoE_data_variables.columns[DoE_position]} - Current')
                axs[0,plots].scatter(optimal_input.iloc[0], optimal_input.iloc[DoE_position], color='red', marker='x', s=100, label=f'Opt_Input')
    
                axs[0,plots].set_xlabel(f'{Optimized_DoE_data_variables.columns[0]}')
                axs[0,plots].set_ylabel(f'{Optimized_DoE_data_variables.columns[DoE_position]}')
                y_min=Optimized_DoE_data_variables.iloc[:,DoE_position].min()
                y_max=Optimized_DoE_data_variables.iloc[:,DoE_position].max()
                axs[0, plots].set_ylim([y_min-y_min*0.1, y_max+y_max*0.1])  # Skalierung mit 10% Puffer
                axs[0,plots].legend(loc='lower center', bbox_to_anchor=(0.5, 1.02), ncol=2)
    
            else:
                axs[1,plots-2].scatter(x, y, color='black', label=f'{Optimized_DoE_data_variables.columns[DoE_position]} - Current')
                axs[1,plots-2].scatter(optimal_input.iloc[0], optimal_input.iloc[DoE_position], color='red', marker='x', s=100, label=f'Opt_Input')
    
                axs[1,plots-2].set_xlabel(f'{Optimized_DoE_data_variables.columns[0]}')
                axs[1,plots-2].set_ylabel(f'{Optimized_DoE_data_variables.columns[DoE_position]}')
                y_min=Optimized_DoE_data_variables.iloc[:,DoE_position].min()
                y_max=Optimized_DoE_data_variables.iloc[:,DoE_position].max()
                axs[1, plots-2].set_ylim([y_min-y_min*0.1, y_max+y_max*0.1])  # Skalierung mit 10% Puffer
                axs[1,plots-2].legend(loc='lower center', bbox_to_anchor=(0.5, 1.02), ncol=2)

        fig.delaxes(axs[0, 2])  # Entfernt den ungenutzten Platz im Grid
        plt.tight_layout()
        
       
        # Save or show the plot
        if saving:
            #plt.show()
            plt.savefig(f'DoE_envelope_constraint_idx_{df1["idx"].iloc[index]}_PC_{df1["Power Constraint (kW)"].iloc[index]}_Cell_{df1["Specified Cell Count"].iloc[index]}_FL_{df1["Flight Level (100x ft)"].iloc[index]}_EOL_{df1["eol (t/f)"].iloc[index]}.png', bbox_inches='tight')
            plt.close()
        else:
            plt.show()
            plt.close()
