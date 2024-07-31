# main.py

import subprocess
import argparse
import json
# def main(power_constraint_kW, specified_cell_count, flight_level_100ft):

#     # Define arguments for training
#     target = 'cell_voltage'
#     cutoff = 50.0
#     pretrained_model = None
#     mode = "auto"

#     # Call the training script
#     #subprocess.run(['python', 'train_gpr_model.py', '-t', target, '-c', str(cutoff), '-m', str(pretrained_model)])

#     # Define arguments for optimization
#     model_path = f'gpr_model_{target}.pth'

#     # Call the optimization script
#     subprocess.run(['python', 'optimize_input_variables.py', '-m', model_path, '-p', str(power_constraint_kW), '-n', \
#                     str(specified_cell_count), '-f', str(flight_level_100ft), "--mode", str(mode)])

# if __name__ == '__main__':

#     parser = argparse.ArgumentParser(description="Train and optimize a Gaussian process regression model on Powercell DoE data")
#     parser.add_argument("-p", "--power", type=float, help="Power constraint for input variable optimization", default=75.0)
#     parser.add_argument("-n", "--cellcount", type=int, help="Stack cell number for optimizing subject to power constraint", default=275)
#     parser.add_argument("-f", "--flightlevel", type=int, help="Flight level in 100x feets", default=50)

#     args = parser.parse_args()

#     main(args.power, args.cellcount, args.flightlevel, args.mode)


def build_command(args):
    command = [
        "python", "optimize_input_variables.py",
        "--model", args.model,
        "--power", str(args.power),
        "--cellcount", str(args.cellcount),
        "--flightlevel", str(args.flightlevel),
        "--mode", args.mode
    ]
    return command

    
if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(description="Main script to call optimize_input_variables.py")
    parser.add_argument("-m", "--model", type=str, help="Path to the trained GPR model", default="gpr_model_cell_voltage.pth")
    parser.add_argument("-p", "--power", type=float, help="Power constraint for input variable optimization", default=120.0)
    parser.add_argument("-n", "--cellcount", type=int, help="Stack cell number for optimizing subject to power constraint", default=275)
    parser.add_argument("-f", "--flightlevel", type=int, help="Flight level in 100x feets", default=50)
    parser.add_argument("--mode", type=str, choices=["auto", "manual"], default="auto", help="Mode of operation: 'auto' or 'manual'")

    args = parser.parse_args()

    # Build and execute command
    command = build_command(args)
    result = subprocess.run(command, capture_output=True, text=True)
    # Print the output and error (if any) from the subprocess call
    print("Output:")
    print(result.stdout)
    print("Errors:")
    print(result.stderr)
