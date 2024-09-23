import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


def plot_optimized_parameter_DoE_envelope(df1,Optimized_DoE_data_variables, saving=False):

    # plot optimal input parameters in DoE-Data     
    for index, row in df1.iterrows():
        # get the optimized input variables
        optimal_input = df1.iloc[index,4:10]

        #get in a ugly way the sim setup (sim_info) to add this in a textbox to the plots
        sim_info = pd.concat([df1.iloc[index,:4], df1.iloc[index, -2:-1]], axis=1)
        #test[testspalte] = sim_info[0].fillna(sim_info[1])
        info_variables = sim_info.index.tolist()
        sim_info = df1[info_variables].iloc[index,:]
        #plot_info = '\n'.join([f"{name}: {info}" for name, info in zip(df['Name'], df['Info'])])

        # plot the data
        fig, axs = plt.subplots(2, 3, figsize=(20, 8))
        fig.text(0.8, 0.8, sim_info, fontsize=18, ha='center', va='center', bbox=dict(facecolor='lightgrey', alpha=0.5))
        for plots in range(len(optimal_input)-1):
            x = Optimized_DoE_data_variables.iloc[:,0]
            y = Optimized_DoE_data_variables.iloc[:,plots+1]
            
            # Informationen, die im Kasten erscheinen sollen
            #sim_setup = "\n".join([f"{var}: {wert:.2f}" for var, wert in sim_case])

        # Füge den Informationskasten zum Plot hinzu
            #plt.text(8, 0.5, sim_setup, fontsize=12, bbox=dict(facecolor='yellow', alpha=0.5))

            if plots < 2:
                axs[0,plots].scatter(x, y, color='black', label=f'{Optimized_DoE_data_variables.columns[plots+1]} - Current')
                axs[0,plots].scatter(optimal_input[0], optimal_input[plots+1], color='red', marker='x', s=100, label=f'Opt_Input')
    
                axs[0,plots].set_xlabel(f'{Optimized_DoE_data_variables.columns[0]}')
                axs[0,plots].set_ylabel(f'{Optimized_DoE_data_variables.columns[plots+1]}')
                y_min=Optimized_DoE_data_variables.iloc[:,plots+1].min()
                y_max=Optimized_DoE_data_variables.iloc[:,plots+1].max()
                axs[0, plots].set_ylim([y_min-y_min*0.1, y_max+y_max*0.1])  # Skalierung mit 10% Puffer
                axs[0,plots].legend(loc='lower center', bbox_to_anchor=(0.5, 1.02), ncol=2)
    
            else:
                axs[1,plots-2].scatter(x, y, color='black', label=f'{Optimized_DoE_data_variables.columns[plots+1]} - Current')
                axs[1,plots-2].scatter(optimal_input[0], optimal_input[plots+1], color='red', marker='x', s=100, label=f'Opt_Input')
    
                axs[1,plots-2].set_xlabel(f'{Optimized_DoE_data_variables.columns[0]}')
                axs[1,plots-2].set_ylabel(f'{Optimized_DoE_data_variables.columns[plots+1]}')
                y_min=Optimized_DoE_data_variables.iloc[:,plots+1].min()
                y_max=Optimized_DoE_data_variables.iloc[:,plots+1].max()
                axs[1, plots-2].set_ylim([y_min-y_min*0.1, y_max+y_max*0.1])  # Skalierung mit 10% Puffer
                axs[1,plots-2].legend(loc='lower center', bbox_to_anchor=(0.5, 1.02), ncol=2)

        fig.delaxes(axs[0, 2])  # Entfernt den ungenutzten Platz im Grid
        plt.tight_layout()
    
       
        # Save or show the plot
        if saving:
            plt.savefig(f"DoE_envelope_constraint_idx_{sim_info.iloc[0]}_PC_{sim_info.iloc[1]}_Cell_{sim_info.iloc[2]}_FL_{sim_info.iloc[3]}_EOL_{sim_info.iloc[4]}.png", bbox_inches='tight')
        else:
            plt.show()
            plt.close(fig)
