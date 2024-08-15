import os
import shutil
import pandas as pd

#working_directory = os.getcwd()
#parameters = [(20, 300, 50), (170, 300, 50), (320, 300, 50), (470, 300, 50), (600, 300, 50)]

def consolidate_experiment_data(parameters):    
    """
    This function will clean up after the loop run of optimize_input_variables.py
    It will:
        collect all folders _gpr_doe_model_optimization_experiment
        moves them into a new dir
        and collectsthe data from each csv file and writes theinto a new csv located in the new dir

    Parameters
    ----------
    parameters : List of lists 
        used in the loop of main.py, only for naming the folder and csv file using min-max of the range.

    Returns
    -------
    None.

    """
    experimentID = 1
    working_directory = os.getcwd()
    
    while True:
        # Define the new directory with the current experimentID
        new_dir = os.path.join(
            working_directory, 
            f'consolidated_{parameters[0][0]}-{parameters[-1][0]}kW_{parameters[0][1]}-{parameters[-1][1]}_{parameters[0][2]}-{parameters[-1][2]}ft__{experimentID}'
        )
        
        # Check if the directory already exists
        if not os.path.exists(new_dir):
            # Create the new directory if it doesn't exist
            os.makedirs(new_dir)
            break
        else:
            # Increment experimentID if directory exists
            experimentID += 1
        
        
    
    # Collect all the directories named X_gpr_doe_model_optimization_experiment
    experiment_dirs = [d for d in os.listdir(working_directory) if os.path.isdir(os.path.join(working_directory, d)) and d.endswith('_gpr_doe_model_optimization_experiment')]
    
    # Create a list to hold all the dataframes
    data_frames = []
    columns = None
    
    for experiment_dir in experiment_dirs:
        src_path = os.path.join(working_directory, experiment_dir)
        dst_path = os.path.join(new_dir, experiment_dir)
    
        # Move the directory to the new directory
        shutil.move(src_path, dst_path)
        
        # Path to the CSV file
        csv_path = os.path.join(dst_path, 'optimized_input_data.csv')
        
        # Read the CSV file
        if os.path.exists(csv_path):
            
            # Store the columns if not already done
            if columns is None:
                df = pd.read_csv(csv_path)
                columns = df.columns
            #read the csv file data in and append dataframe into a list    
            df = pd.read_csv(csv_path, skiprows=1, header=None, names=columns)  # Skip the header row for subsequent files
            data_frames.append(df)  # Append the DataFrame containing only the data rows
    
    # Concatenate all the dataframes
    if data_frames:
        consolidated_df = pd.concat(data_frames, ignore_index=True)
        
        # Write the consolidated data to a new CSV file
        consolidated_csv_path = os.path.join(new_dir, f'optimized_parameters_{parameters[0][0]}-{parameters[-1][0]}kW_{parameters[0][1]}-{parameters[-1][1]}_{parameters[0][2]}-{parameters[-1][2]}ft.csv')
        consolidated_df.to_csv(consolidated_csv_path, index=False, header=columns)
        print(f"Consolidated CSV created at {consolidated_csv_path}")
    else:
        print("No CSV files found to consolidate.")
        
    return consolidated_csv_path