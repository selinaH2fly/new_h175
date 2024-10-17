# main.py

import subprocess
import argparse
#import json
import numpy as np
import itertools
from collect_data import consolidate_experiment_data
from Postprocessing.get_plots import analyze_data
from tqdm import tqdm
from concurrent.futures import ProcessPoolExecutor, as_completed

def save_failed_case(parameter, error_message):
    with open("failed_cases.txt", "a") as file:
        file.write(f"Parameter: {parameter}, Error: {error_message}\n")
        
def build_command(parameter):
    command = [
        "python", "model_run.py",
        "--power", str(parameter[0]),
        "--cellcount", str(parameter[1]),
        "--flightlevel", str(parameter[2]),
        "--turbine", str(parameter[3]),
        "--map", str(parameter[4]),
        "--eol", str(parameter[5]),
        "--constraint", str(parameter[6]),
        "--weighting", str(parameter[7])
    ]
    return command

def run_subprocess(parameter):
    command = build_command(parameter)
    result = subprocess.run(command, capture_output=True, text=True)
    if result.returncode != 0:
        # Log the error for failed cases
        save_failed_case(parameter, result.stderr)
        return (False, parameter, result.stderr)
    return (True, parameter, result.stdout)

if __name__ == '__main__':
    #import argparse

    parser = argparse.ArgumentParser(description="Main script to call optimize_input_variables.py")
    parser.add_argument("-p", "--power", type=float, nargs='+', help="Power constraint for input variable optimization", default=[20,175])
    parser.add_argument("-n", "--cellcount", type=float, nargs='+', help="Stack cell number for optimizing subject to power constraint", default=[400,455,500])
    parser.add_argument("-f", "--flightlevel", type=float,  nargs='+', help="Flight level in 100x feets", default=[0,100])
    # parser.add_argument("-t", "--turbine", type=str, choices=["True"], default="True", help="Specifies whether recuperation shall be taken into account (default: True).")
    parser.add_argument("--map", type=str, choices=["None", "VSEC15"], default="None", help="Specifies the compressor map to be used (default: None).")
    # parser.add_argument("--eol", type=str, choices=["True", "False"], default="False", help="Specifies whether cell voltage is derated by a factor of 0.8 to account for end of life (default: False).")
    parser.add_argument("--testing", type=str, choices=["True", "False"], default="False", help="Specifies whether a short test run is initiated.")
    parser.add_argument("--constraint", type=str, choices=["True","False"], default="True", help="Activates the DoE envelope constraint condition for the optimizer. (default: True)")
    
    args = parser.parse_args()
    
    if args.testing == "True":
        range_power = np.array([20, 100, 175])
        range_cellcount = np.array([455])
        range_fl = np.array([0])
        # Convert turbine and eol to boolean lists
        range_turbine =[True]#, args.turbine.lower() == "false"]
        range_eol = [False]
        range_map = [args.map]
        range_DoE_constraint = [args.constraint]
        #Handle downstream data and plots
        saving = False
        dir_prefix = "testing__"
        weighting = 0

    elif args.testing == "False":
      
        _step_p = 5
        _step_c = 50
        _step_fl = 30
        #range_power is ugly deined atm. due to not starting at 0 and want to have inclusive bounds.... maybe there is a better way?
        range_power = np.arange(args.power[0], args.power[1] + 1, _step_p) if (args.power[1] - args.power[0]) % _step_p == 0 else np.append(np.arange(args.power[0], args.power[1], _step_p), args.power[1])
        #range_power = np.array([20, 50, 80, 125, 150, 175])
        range_cellcount = [400, 455, 500]#np.arange(args.cellcount[0],args.cellcount[1]+_step_c,_step_c)
        range_fl = [120]#np.arange(args.flightlevel[0],args.flightlevel[1]+_step_fl,_step_fl)
        
        # Convert turbine and eol to boolean lists
        range_turbine =[True]
        range_eol = [False]
        range_map = [args.map]
        range_DoE_constraint = [args.constraint]
        weighting = [0,1]
        #Handle downstream data and plots
        saving = True
        dir_prefix =""
        
    else:
        print("User Error: wrong input for --testing, sould be True/False")

    # Generate all combinations of parameters
    parameters = list(itertools.product(range_power, range_cellcount, range_fl, range_turbine, range_map, range_eol, range_DoE_constraint, weighting))
    
    # Start parallel execution using ProcessPoolExecutor
    max_workers = min(26, len(parameters))  # Define the number of processes based on available resources
    
    with ProcessPoolExecutor(max_workers=max_workers) as executor:
        futures = {executor.submit(run_subprocess, param): param for param in parameters}

        # Show progress bar using tqdm
        for future in tqdm(as_completed(futures), total=len(futures), desc="Optimization Progress"):
            success, param, output = future.result()
            if success:
                print(f"Success for parameter {param}: {output}")
            else:
                print(f"Failed for parameter {param}: {output}")
    
    print("Done with batch run... Gathering data and starting plotting...")

    # Consolidate data and analyze results
    path_to_data = consolidate_experiment_data(parameters, dir_prefix)
    analyze_data(_file_path1=path_to_data, saving=saving)