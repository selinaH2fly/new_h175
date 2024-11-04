# Import libraries
import os
import numpy as np
import torch
import argparse
import random

# Import custom classes and functions
import parameters
from file_handling import create_experiment_folder, load_gpr_model
from optimization_functions import optimize_inputs_evolutionary

from data_export_csv import export_to_csv
 
def optimize_input_variables(power_constraint_kW=75.0, specified_cell_count=275, flight_level_100ft=50, consider_turbine=True, compressor_map=None, end_of_life=True, constraint=True, multiobjective_weighting=0.0):
    
    # Load parameters
    _params_optimization = parameters.Optimization_Parameters()  

    # Set the random seed for reproducibility
    if _params_optimization.seed is not None:
        random.seed(_params_optimization.seed)
        np.random.seed(_params_optimization.seed)
        torch.manual_seed(_params_optimization.seed)

    print(f"\nOptimization System (Net) Power Constraint: {power_constraint_kW:.0f} kW")
    print(f"Specified Flight Level: {flight_level_100ft} (100x ft)")
    print(f"Specified Cell Count: {specified_cell_count}")

    # Load the trained cell voltage model from the "Trained_Models" folder
    gpr_model_cell_voltage = load_gpr_model(os.path.join(os.getcwd(), "Trained_Models", "gpr_model_cell_voltage.pth"))

    # Load the trained cathode pressure drop model from the "Trained_Models" folder
    gpr_model_cathode_pressure_drop = load_gpr_model(os.path.join(os.getcwd(), "Trained_Models", "gpr_model_cathode_pressure_drop.pth"))

    # Load the trained anode pressure drop model from the "Trained_Models" folder
    gpr_model_anode_pressure_drop = load_gpr_model(os.path.join(os.getcwd(), "Trained_Models", "gpr_model_anode_pressure_drop.pth"))

    # Create a folder to store the training results
    create_experiment_folder(_params_optimization=_params_optimization, type='optimization')
    
    # Optimize the input variables
    results = optimize_inputs_evolutionary(gpr_model_cell_voltage, gpr_model_cathode_pressure_drop, gpr_model_anode_pressure_drop,
                                            flight_level_100ft, cellcount=specified_cell_count,
                                            power_constraint_kW=power_constraint_kW,
                                            consider_turbine=consider_turbine, compressor_map=compressor_map,
                                            end_of_life=end_of_life, multiobjective_weighting=multiobjective_weighting,
                                            constraint=constraint)

    system_power_W = results.stack_power_W          \
                        - results.compressor_power_W \
                        + results.turbine_power_W     \
                        - results.reci_pump_power_W    \
                        - results.coolant_pump_power_W
    
    results = results._replace(system_power_W = system_power_W)

    # Print the optimal input, target variables, and bounds including feature names and target variable
    print("\nOptimized Input Variables:")
    for name, value, bound in zip(gpr_model_cell_voltage.feature_names, results.optimized_input, _params_optimization.bounds):
        lower_bound_formatted = f"{bound[0]}" if abs(bound[0]) < 1e3 else f"{bound[0]:.1e}"
        upper_bound_formatted = f"{bound[1]}" if abs(bound[1]) < 1e3 else f"{bound[1]:.1e}"
        print(f"  {name}: {value:.4f} (Bounds: [{lower_bound_formatted}, {upper_bound_formatted}])")

    print(f"\nOptimized Targets (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):")
    print(f"  Hydrogen Supply Rate: {results.hydrogen_supply_rate_g_s:.4f} g/s (Weighting: {1 - multiobjective_weighting})")
    print(f"  Specific Power: {system_power_W/1000/results.system_mass_kg:.4f} kW/kg (Weighting: {multiobjective_weighting})")

    print(f"\nCell Voltage (s.t. Optimized Input Variables, System Power Constraint, Flighlevel & Cell Count):\n  {results.cell_voltage_V:.4f} V\n")

    # Print the resultant power numbers
    label_width = 45
    value_width = 10
    print("Resultant Power Numbers:")
    print(f"  {'Stack (Gross) Power Estimate:':<{label_width}}  {results.stack_power_W/1000:>{value_width}.2f} kW")
    print(f"  {'Compressor Power Estimate (at FL ' + str(flight_level_100ft) + '):':<{label_width}} -{results.compressor_power_W/1000:>{value_width}.2f} kW")
    print(f"  {'Turbine Power Estimate (at FL ' + str(flight_level_100ft) + '):':<{label_width}} +{results.turbine_power_W/1000:>{value_width}.2f} kW")
    print(f"  {'Recirculation Pump Power Estimate:':<{label_width}} -{results.reci_pump_power_W/1000:>{value_width}.2f} kW")
    print(f"  {'Coolant Pump Power Estimate:':<{label_width}} -{results.coolant_pump_power_W/1000:>{value_width}.2f} kW")
    print("-" * (label_width + value_width + 7))
    print(f"  {'System (Net) Power (s.t. Optimization):':<{label_width}} ={results.system_power_W/1000:>{value_width}.2f} kW")
    print("-" * (label_width + value_width + 7))
    print(f"{'Fixed Dependent Mass:':<{label_width}} {results.fixed_mass:>{value_width+3}.2f} kg")
    print(f"{'Power Dependent Mass - Compressor:':<{label_width}} {results.compressor_mass_kg:>{value_width}.2f} kg")
    print(f"{'Power Dependent Mass - Rezi Pump:':<{label_width}} {results.rezi_pump_mass_kg:>{value_width}.2f} kg")
    print(f"{'Power Dependent Mass - Coolant Pump:':<{label_width}} {results.coolant_pump_mass_kg:>{value_width}.2f} kg")
    print(f"{'Power Dependent Mass - Radiator:':<{label_width}} {results.radiator_mass_kg:>{value_width}.2f} kg")
    print(f"{'Power Dependent Mass:':<{label_width}} {results.power_dependent_mass:>{value_width+3}.2f} kg")
    print(f"{'Cell  Dependent Mass:':<{label_width}} {results.cellcount_dependent_mass:>{value_width+3}.2f} kg")
    print(f"{'H2    Dependent Mass:':<{label_width}} {results.H2_dependend_mass:>{value_width+3}.2f} kg")
    print("-" * (label_width + value_width + 7))
    print(f"{'System Mass:':<{label_width}} {results.system_mass_kg:>{value_width+3}.2f} kg")
    print("-" * (label_width + value_width + 7))
    #results_final = results._asdict()
    
    # Save results to a .csv file 
    export_to_csv(
        results=results,  # Pass the fully populated named tuple
        feature_names=gpr_model_cell_voltage.feature_names, 
        power_constraint_kW=power_constraint_kW, 
        specified_cell_count=specified_cell_count, 
        flight_level_100ft=flight_level_100ft, 
        consider_turbine=consider_turbine, 
        end_of_life=end_of_life, 
        multiobjective_weighting=multiobjective_weighting, 
        filename='optimized_input_data.csv'
    )
    
# Entry point of the script
if __name__ == '__main__':
    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Optimize input variables using a trained Gaussian process regression model")
    parser.add_argument("-p", "--power", type=float, default=150.0, help="Power constraint for input variable optimization")
    parser.add_argument("-n", "--cellcount", type=int, default=455, help="Stack cell number for optimizing subject to power constraint")
    parser.add_argument("-f", "--flightlevel", type=int, default=120, help="Flight level in 100x feets")
    parser.add_argument("-t", "--turbine", type=str, choices=["True", "False"], default="True", help="Specifies whether recuperation shall be taken into account (default: True).")
    parser.add_argument("--map", type=str, choices=["None", "VSEC15"], default="None", help="Specifies the compressor map to be used (default: None).")
    parser.add_argument("--eol", type=str, choices=["True", "False"], default="False", help="Specifies whether cell voltage is derated by a factor of 0.85 to account for end of life (default: False).")
    parser.add_argument("--constraint", type=str, choices=["True","False"], default="True", help="Activates the DoE envelope constraint condition for the optimizer. (default: True)")
    parser.add_argument("-w", "--weighting", type=float, default=1.0, help="Weighting factor for multiobjective-optimization; 0 -> optimization for efficiency (default), 1 -> optimization for (power-specific) mass.")
    args = parser.parse_args()

    # Convert string inputs
    consider_turbine = args.turbine == "True"
    end_of_life = args.eol == "True"
    compressor_map = args.map if args.map != "None" else None
    constraint = args.constraint == "True"

    # Call the optimize_with_trained_model function
    optimize_input_variables(power_constraint_kW=args.power, specified_cell_count=args.cellcount, flight_level_100ft=args.flightlevel, consider_turbine=consider_turbine, compressor_map=compressor_map,
                             end_of_life=end_of_life, constraint=constraint, multiobjective_weighting=args.weighting)