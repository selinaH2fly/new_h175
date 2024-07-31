# main.py

import subprocess
import argparse
import json
import numpy as np
import itertools

def build_command(parameter):
    command = [
        "python", "optimize_input_variables.py",
        "--power", str(parameter[0]),
        "--cellcount", str(parameter[1]),
        "--flightlevel", str(parameter[2]),
        "--mode", args.mode
    ]
    return command
 
if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(description="Main script to call optimize_input_variables.py")
    parser.add_argument("-m", "--model", type=str, help="Path to the trained GPR model", default="gpr_model_cell_voltage.pth")
    parser.add_argument("-p", "--power", type=float, nargs='+', help="Power constraint for input variable optimization", default=[20,600])
    parser.add_argument("-n", "--cellcount", type=float, nargs='+', help="Stack cell number for optimizing subject to power constraint", default=[300,300])
    parser.add_argument("-f", "--flightlevel", type=float,  nargs='+', help="Flight level in 100x feets", default=[50, 50])
    parser.add_argument("--mode", type=str, choices=["auto", "manual"], default="auto", help="Mode of operation: 'auto' or 'manual'")

    args = parser.parse_args()
    _step_p = 150
    _step_c = 50
    _step_fl = 100
    
    range_power = np.arange(args.power[0], args.power[1] + 1, _step_p) if (args.power[1] - args.power[0]) % _step_p == 0 else np.append(np.arange(args.power[0], args.power[1], _step_p), args.power[1])
    range_cellcount = np.arange(args.cellcount[0],args.cellcount[1]+_step_c,_step_c)
    range_fl = np.arange(args.flightlevel[0],args.flightlevel[1]+_step_fl,_step_fl)
    
    parameters = list(itertools.product(range_power, range_cellcount, range_fl))
    
    for parameter in parameters:
        
        # Build and execute command
        command = build_command(parameter)
        #result = subprocess.run(command, capture_output=True, text=True)
        # Print the output and error (if any) from the subprocess call
        #print(result.stdout)