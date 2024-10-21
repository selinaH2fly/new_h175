# Import custom classes and functions
import numpy as np
import cathode_model_run
from Components.moist_exchanger import Humidifier
from Components.valve import Valve


class HumidifierValveArchitecture01:
    def __init__(self, total_air_mass_flow_kg_s, valve_position_percent, pressure_drop,
                 humidifier_parameters):
        """
        Initializes the humidifier and valve system architecture.

        Args:
            total_air_mass_flow_kg_s: Total mass flow rate entering the system (kg/s).
            valve_position_percent: Valve opening percentage (0-100%).
            pressure_drop: Pressure drop condition for interpolation (e.g., 'pressure_1kpa').
            humidifier_parameters: Parameters for initializing the humidifier (MoistExchanger).
        """
        # Initialize the Valve
        self.valve = Valve(total_air_mass_flow_kg_s, valve_position_percent)
        self.pressure_drop_condition = pressure_drop

        # Calculate the mass flow split between bypass and humidifier
        self.bypass_mass_flow_kg_s, self.humidifier_mass_flow_kg_s = self.valve.calculate_bypass_flow(
            pressure_drop)

        # Initialize the Humidifier (MoistExchanger)
        humidifier_parameters[
            'dry_air_mass_flow_kg_s'] = self.humidifier_mass_flow_kg_s  # Adjust the mass flow for humidifier
        self.humidifier = MoistExchanger(**humidifier_parameters)

    def run_simulation(self):
        """
        Runs the simulation for the humidifier and valve system.

        Returns:
            Dictionary containing bypass flow, humidifier flow, and efficiency.
        """
        # Calculate water transfer and efficiency in the humidifier
        water_transfer, efficiency = self.humidifier.calculate_water_transfer()

        return {
            'bypass_mass_flow_kg_s': self.bypass_mass_flow_kg_s,
            'humidifier_mass_flow_kg_s': self.humidifier_mass_flow_kg_s,
            'water_transfer_kg_s': water_transfer,
            'humidifier_efficiency': efficiency
        }


# Example usage of HumidifierValveArchitecture:
if __name__ == "__main__":
    # Define the total air mass flow rate (kg/s)
    total_air_mass_flow_kg_s = 0.2

    # Define the initial valve position percentage (0-100%)
    valve_position_percent = 50

    # Define the pressure drop condition (e.g., 'pressure_5kpa', 'pressure_1kpa', etc.)
    pressure_drop_condition = 'pressure_5kpa'

    # Define the parameters for the humidifier (MoistExchanger)
    humidifier_parameters = {
        'dry_air_temperature_in_K': 353.3,
        'dry_air_pressure_in_Pa': 246000,
        'dry_air_rh_in': 0.3,
        'dry_air_temperature_out_K': 346.9,
        'dry_air_pressure_out_Pa': 230000,
        'dry_air_rh_out': 0.75,
        'wet_air_temperature_in_K': 353.2,
        'wet_air_pressure_in_Pa': 210000,
        'wet_air_rh_in': 0.99,
        'wet_air_pressure_out_Pa': 196000
    }

    # Create the architecture model
    humidifier_valve_system = HumidifierValveArchitecture(total_air_mass_flow_kg_s, valve_position_percent,
                                                          pressure_drop_condition, humidifier_parameters)

    # Run the simulation
    results = humidifier_valve_system.run_simulation()

    # Print the results
    print(f"Bypass mass flow rate (kg/s): {results['bypass_mass_flow_kg_s']:.4f}")
    print(f"Humidifier mass flow rate (kg/s): {results['humidifier_mass_flow_kg_s']:.4f}")
    print(f"Water transfer rate (kg/s): {results['water_transfer_kg_s']:.4f}")
    print(f"Humidifier efficiency: {results['humidifier_efficiency']:.2f}")
