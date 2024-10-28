# Import custom classes and functions
import numpy as np
import cathode_model_run
from Components.moist_exchanger import Humidifier
from Components.valve import Valve

# Simulation function
def run_simulation(dry_air_mass_flow_kg_s, wet_air_mass_flow_kg_s, dry_air_temperature_in_K,
                   dry_air_pressure_in_Pa, dry_air_rh_in, dry_air_temperature_out_K,
                   dry_air_pressure_out_Pa, wet_air_temperature_in_K, wet_air_pressure_in_Pa,
                   wet_air_rh_in, wet_air_pressure_out_Pa, valve_position):
    
    # Load parameters
    _params_physics = cathode_model_run.PhysicalParameters()
    _params_humidifier = cathode_model_run.HumidifierParameters()
    _params_valve = cathode_model_run.ValveParameters()

    # Instantiate the componenets
    humidifier = Humidifier(
        dry_air_mass_flow_kg_s=dry_air_mass_flow_kg_s,
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

    valve= Valve(
        total_air_mass_flow_kg_s = dry_air_mass_flow_kg_s,
        valve_position_percent = valve_position_percent,

    )


    # Calculate the mass flow from the humidifier
    humidifier_water_transfer, humidifier_efficiency = humidifier.calculate_water_transfer()

    # Calculate total mass flow from both components
    total_mass_flow_kg_s = calculate_total_output_flow(humidifier_flow, valve_flow)

    # Update the mass flow in the MoistExchanger
    humidifier.dry_air_mass_flow_kg_s = total_mass_flow_kg_s

    # Calculate the relative humidity at the dry air outlet
    rh_dry_out_result = humidifier.calculate_rh_dry_out()

    return {
        'humidifier_flow': humidifier_water_transfer,
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



def calculate_bypass_flow(pressure_input_pa, pressure_output_pa):
    """
    Calculates the bypass and main branch mass flow rates based on the valve position.

    Args:
        pressure_input_pa: The input pressure (in Pa).
        pressure_output_pa: The output pressure (in Pa).
    """
    bypass_mass_flow_g_s = Valve.interpolate_mass_flow(valve_position_percent, pressure_input_pa,pressure_output_pa)

    # Convert g/s to kg/s
    bypass_mass_flow_kg_s = bypass_mass_flow_g_s / 1000

    # Remaining air mass flow through the main branch (humidifier)
    mass_flow_main_kg_s = total_air_mass_flow_kg_s - bypass_mass_flow_kg_s
    return bypass_mass_flow_kg_s, mass_flow_main_kg_s

# Parallel flow calculation function
def calculate_total_output_flow(humidifier_flow, valve_flow):
    return humidifier_flow + valve_flow



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
        dry_air_mass_flow_kg_s = mass_flow_through_valve[index] / 1000  # Convert g/s to kg/s

        # Run the parallel simulation
        simulation_result = run_simulation(
            dry_air_mass_flow_kg_s=dry_air_mass_flow_kg_s,
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
            valve_position=valve_position_percent  # Pass the valve opening position
        )

        results.append(simulation_result)

    # Print the results
    for idx, result in enumerate(results):
        print(f"Valve Opening: {valve_openings[idx]}%, "
              f"Humidifier Flow (kg/s): {result['humidifier_flow']:.4f}, "
              f"Bypass Flow (kg/s): {result['bypass_flow']:.4f}, "
              f"Total Mass Flow (kg/s): {result['total_mass_flow']:.4f}, "
              f"Calculated RH Dry Out: {result['rh_dry_out']:.2f}%")
