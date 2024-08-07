# main.py

import subprocess
import argparse
import json
import numpy as np
import itertools
from collect_data import consolidate_experiment_data

def build_command(parameter):
    command = [
        "python", "optimize_input_variables.py",
        "--power", str(parameter[0]),
        "--cellcount", str(parameter[1]),
        "--flightlevel", str(parameter[2]),
        "--turbine", args.turbine
    ]
    return command
 
if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(description="Main script to call optimize_input_variables.py")
    parser.add_argument("-p", "--power", type=float, nargs='+', help="Power constraint for input variable optimization", default=[20,20])
    parser.add_argument("-n", "--cellcount", type=float, nargs='+', help="Stack cell number for optimizing subject to power constraint", default=[500,500])
    parser.add_argument("-f", "--flightlevel", type=float,  nargs='+', help="Flight level in 100x feets", default=[120, 120])
    parser.add_argument("-t", "--turbine", type=str, choices=["true", "false"], default="true", help="Specifies whether recuperation shall be taken into account (default: True).")

    args = parser.parse_args()
    
    _step_p = 40
    _step_c = 50
    _step_fl = 20
    #TODO: range_power is ugly deined atm. due to not starting at 0 and want to have inclusive bounds.... maybe there is a better way?
    range_power = np.arange(args.power[0], args.power[1] + 1, _step_p) if (args.power[1] - args.power[0]) % _step_p == 0 else np.append(np.arange(args.power[0], args.power[1], _step_p), args.power[1])
    range_cellcount = np.arange(args.cellcount[0],args.cellcount[1]+_step_c,_step_c)
    range_fl = np.arange(args.flightlevel[0],args.flightlevel[1]+_step_fl,_step_fl)
    
    parameters = list(itertools.product(range_power, range_cellcount, range_fl))
    
    for parameter in parameters:
        
        # Build and execute command
        command = build_command(parameter)
        print(command)
        result = subprocess.run(command, capture_output=True, text=True)
        # Print the output and error (if any) from the subprocess call
        print(result.stdout)
    print("Done with Optimization")
        
    consolidate_experiment_data(parameters)