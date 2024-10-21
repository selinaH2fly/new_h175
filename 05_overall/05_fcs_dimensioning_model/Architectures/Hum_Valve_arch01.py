# Import custom classes and functions
import numpy as np
import cathode_model_run
from Components.moist_exchanger import Humidifier
from Components.valve import Valve


# Bypass valve calculation function
def calculate_bypass_flow(total_air_mass_flow_kg_s, valve_position_percent, pressure_in, pressure_out):
    pressure_difference = pressure_in - pressure_out
    bypass_mass_flow_kg_s = (valve_position_percent / 100) * pressure_difference * total_air_mass_flow_kg_s / 1000

    # Remaining air mass flow through the main branch (humidifier)
    mass_flow_main_kg_s = total_air_mass_flow_kg_s - bypass_mass_flow_kg_s

    # Ensure flow values are non-negative
    bypass_mass_flow_kg_s = max(0, bypass_mass_flow_kg_s)
    mass_flow_main_kg_s = max(0, mass_flow_main_kg_s)

    return bypass_mass_flow_kg_s, mass_flow_main_kg_s  # Return both bypass and main flow


def calculate_parallel_flow(humidifier_flow, valve_flow):
    return humidifier_flow + valve_flow


# Simulation function
def run_parallel_simulation(dry_air_mass_flow_kg_s, wet_air_mass_flow_kg_s, dry_air_temperature_in_K,
                            dry_air_pressure_in_Pa, dry_air_rh_in, dry_air_temperature_out_K,
                            dry_air_pressure_out_Pa, wet_air_temperature_in_K, wet_air_pressure_in_Pa,
                            wet_air_rh_in, wet_air_pressure_out_Pa, valve_position_percent):
    # Instantiate parameters
    _params_physics = cathode_model_run.PhysicalParameters()
    _params_humidifier = cathode_model_run.HumidifierParameters()
    _params_valve = cathode_model_run.ValveParameters()

    # Calculate bypass flow using the Valve class
    bypass_mass_flow_kg_s, mass_flow_main_kg_s = calculate_bypass_flow(
        dry_air_mass_flow_kg_s,
        valve_position_percent,
        dry_air_pressure_in_Pa,
        dry_air_pressure_out_Pa
    )

    # Instantiate the humidifier using the mass flow through the main branch
    humidifier = Humidifier(
        dry_air_mass_flow_kg_s=mass_flow_main_kg_s,
        dry_air_temperature_in_K=dry_air_temperature_in_K,
        dry_air_pressure_in_Pa=dry_air_pressure_in_Pa,
        dry_air_rh_in=dry_air_rh_in,
        dry_air_temperature_out_K=dry_air_temperature_out_K,
        dry_air_pressure_out_Pa=dry_air_pressure_out_Pa,
        dry_air_rh_out=_params_humidifier.dry_air_rh_out,
        wet_air_mass_flow_kg_s=wet_air_mass_flow_kg_s,
        wet_air_temperature_in_K=wet_air_temperature_in_K,
        wet_air_pressure_in_Pa=wet_air_pressure_in_Pa,
        wet_air_rh_in=wet_air_rh_in,
        wet_air_pressure_out_Pa=wet_air_pressure_out_Pa
    )

    # Calculate the mass flow from the humidifier
    humidifier_water_transfer, humidifier_efficiency = humidifier.calculate_water_transfer()

    # Calculate total mass flow from both components
    total_mass_flow_kg_s = calculate_parallel_flow(humidifier_water_transfer, bypass_mass_flow_kg_s)

    # Update the mass flow in the MoistExchanger
    humidifier.dry_air_mass_flow_kg_s = total_mass_flow_kg_s

    # Calculate the relative humidity at the dry air outlet
    rh_dry_out_result = humidifier.calculate_rh_dry_out()

    return {
        'humidifier_flow': humidifier_water_transfer,
        'bypass_flow': bypass_mass_flow_kg_s,
        'total_mass_flow': total_mass_flow_kg_s,
        'rh_dry_out': rh_dry_out_result * 100  # Convert to percentage
    }


# Example input data for various valve openings
valve_openings = [0, 30, 60, 100]  # Valve openings in percentage
rh_dry_out_values = [56, 9, 53, 4, 37, 3, 34, 5]  # RH dry out values
mass_flow_through_valve = [0, 21, 5, 31, 33, 8]  # Mass flow through the valve in g/s
mass_flow_compressor = 47  # Mass flow from the compressor in g/s
temperature_dry_in = [52.5, 51.6, 51, 50.7]  # Dry air inlet temperatures in °C
temperature_dry_out = [57.3, 55.9, 55.5, 55.2]  # Dry air outlet temperatures in °C
pressure_dry_in = [1.28, 1.27, 1.26, 1.25]  # Dry air inlet pressures in bara
pressure_dry_out = [1.25, 1.24, 1.25, 1.24]  # Dry air outlet pressures in bara

# Run the simulations for each valve opening
if __name__ == "__main__":
    results = []
    for index, valve_position_percent in enumerate(valve_openings):
        # Convert pressure from bara to Pa
        dry_air_pressure_in_Pa = pressure_dry_in[index] * 1e5
        dry_air_pressure_out_Pa = pressure_dry_out[index] * 1e5

        # Use corresponding temperature and humidity values
        dry_air_temperature_in_K = temperature_dry_in[index] + 273.15  # Convert to Kelvin
        dry_air_temperature_out_K = temperature_dry_out[index] + 273.15  # Convert to Kelvin
        dry_air_rh_in = rh_dry_out_values[index] / 100  # Convert RH to fraction
        wet_air_mass_flow_kg_s = mass_flow_through_valve[index] / 1000  # Convert g/s to kg/s

        # Run the parallel simulation
        simulation_result = run_parallel_simulation(
            dry_air_mass_flow_kg_s=mass_flow_compressor / 1000,  # Convert g/s to kg/s
            wet_air_mass_flow_kg_s=wet_air_mass_flow_kg_s,
            dry_air_temperature_in_K=dry_air_temperature_in_K,
            dry_air_pressure_in_Pa=dry_air_pressure_in_Pa,
            dry_air_rh_in=dry_air_rh_in,
            dry_air_temperature_out_K=dry_air_temperature_out_K,
            dry_air_pressure_out_Pa=dry_air_pressure_out_Pa,
            wet_air_temperature_in_K=353.2,  # Assuming a fixed wet air inlet temperature
            wet_air_pressure_in_Pa=210000,  # Assuming a fixed wet air inlet pressure
            wet_air_rh_in=1.0,  # Assuming wet air inlet is saturated
            wet_air_pressure_out_Pa=196000,  # Assuming a fixed wet air outlet pressure
            valve_position_percent=valve_position_percent
        )

        results.append(simulation_result)

    # Print the results
    for idx, result in enumerate(results):
        print(f"Valve Opening: {valve_openings[idx]}%, "
              f"Humidifier Flow (kg/s): {result['humidifier_flow']:.4f}, "
              f"Bypass Flow (kg/s): {result['bypass_flow']:.4f}, "
              f"Total Mass Flow (kg/s): {result['total_mass_flow']:.4f}, "
              f"Calculated RH Dry Out: {result['rh_dry_out']:.2f}%")
