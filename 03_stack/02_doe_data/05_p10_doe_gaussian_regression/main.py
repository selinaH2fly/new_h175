# main.py

import subprocess
import argparse
import json
import numpy as np
import itertools
from collect_data import consolidate_experiment_data
#testing:
from tqdm import tqdm

def build_command(parameter):
    command = [
        "python", "optimize_input_variables.py",
        "--power", str(parameter[0]),
        "--cellcount", str(parameter[1]),
        "--flightlevel", str(parameter[2]),
        "--turbine", str(parameter[3]),
        "--eol", str(parameter[4])
    ]
    return command
 
if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(description="Main script to call optimize_input_variables.py")
    parser.add_argument("-p", "--power", type=float, nargs='+', help="Power constraint for input variable optimization", default=[20,175])
    parser.add_argument("-n", "--cellcount", type=float, nargs='+', help="Stack cell number for optimizing subject to power constraint", default=[400,500])
    parser.add_argument("-f", "--flightlevel", type=float,  nargs='+', help="Flight level in 100x feets", default=[0, 120])
    parser.add_argument("-t", "--turbine", type=str, choices=["true", "false"], default="true", help="Specifies whether recuperation shall be taken into account (default: True).")
    parser.add_argument("--eol", type=str, choices=["true", "false"], default="false", help="Specifies whether cell voltage is derated by a factor of 0.8 to account for end of life (default: False).")

    args = parser.parse_args()
    
    _step_p = 30
    _step_c = 50
    _step_fl = 20
    #TODO: range_power is ugly deined atm. due to not starting at 0 and want to have inclusive bounds.... maybe there is a better way?
    #range_power = np.arange(args.power[0], args.power[1] + 1, _step_p) if (args.power[1] - args.power[0]) % _step_p == 0 else np.append(np.arange(args.power[0], args.power[1], _step_p), args.power[1])
    range_power = np.array([20, 50, 80, 125, 150, 175])
    range_cellcount = np.arange(args.cellcount[0],args.cellcount[1]+_step_c,_step_c)
    range_fl = np.arange(args.flightlevel[0],args.flightlevel[1]+_step_fl,_step_fl)
    
    # Convert turbine and eol to boolean lists
    range_turbine = [True]#[args.turbine.lower() == "true", args.turbine.lower() == "false"]
    range_eol = [args.eol.lower() == "true", args.eol.lower() == "false"]

    # Generate all combinations of parameters
    parameters = list(itertools.product(range_power, range_cellcount, range_fl, range_turbine, range_eol))

    
    for parameter in tqdm(parameters, desc="Optimization Progress", unit="parameter"):
        
        # Build and execute command
        command = build_command(parameter)
        print('\n',command, "\n")
        result = subprocess.run(command, capture_output=True, text=True)
        # Print the output and error (if any) from the subprocess call
        print( "\n", result.stdout, "\n")
    print("Done with Optimization")
        
    consolidate_experiment_data(parameters)