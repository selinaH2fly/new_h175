import numpy as np
from parameters import Valve_Parameters
from basic_physics import compute_air_mass_flow

class Valve:
    def __init__(self, stoichiometry, current_A, cellcount=275, valve_position_percent=0):
        """
        Initializes the Valve with total air mass flow rate and valve position.

        Args:
            stoichiometry: Stoichiometric ratio for air flow calculation.
            current_A: Current in Amperes for calculating air flow.
            cellcount: Number of cells (default is 275).
            valve_position_percent: The valve position in percentage (0-100%) where 0% is fully closed
                                    and 100% is fully open.
        """
        # Compute total air mass flow rate in kg/s
        self.total_air_mass_flow_kg_s = compute_air_mass_flow(stoichiometry, current_A, cellcount)
        self.valve_position_percent = valve_position_percent
        self.valve_parameters = Valve_Parameters()  # Access valve map data

    def get_valve_position(self):
        """Returns the current valve position in percentage."""
        return self.valve_position_percent

    def set_valve_position(self, new_valve_position):
        """Update the valve position."""
        self.valve_position_percent = new_valve_position

    def interpolate_mass_flow(self, position):
        """
        Interpolates the mass flow based on valve position using the valve map data.
        """
        valve_opening_percentages = np.array(list(self.valve_parameters.bypass_valve_flow_map.keys()), dtype=float)
        mass_flow_rates_g_s = np.array(list(self.valve_parameters.bypass_valve_flow_map.values()), dtype=float)

        if position <= min(valve_opening_percentages):
            return 0  # Return 0 mass flow if position is below the minimum (6%)
        elif position >= max(valve_opening_percentages):
            return max(mass_flow_rates_g_s)  # Return max mass flow for position >= 94%

        # Interpolating mass flow between given valve positions
        return np.interp(position, valve_opening_percentages, mass_flow_rates_g_s)

    def calculate_bypass_flow(self):
        """
        Calculates the bypass and main branch mass flow rates based on the valve position.
        """
        bypass_mass_flow_g_s = self.interpolate_mass_flow(self.valve_position_percent)

        # Convert g/s to kg/s
        bypass_mass_flow_kg_s = bypass_mass_flow_g_s / 1000

        # Remaining air mass flow through the main branch (humidifier)
        mass_flow_main_kg_s = self.total_air_mass_flow_kg_s - bypass_mass_flow_kg_s
        return bypass_mass_flow_kg_s, mass_flow_main_kg_s


# Example usage:
if __name__ == "__main__":
    # Example inputs
    stoichiometry = 2.3 # Example stoichiometry value
    current_A = 650.0     # Example current in Amperes

    # Create a Valve object with initial valve position
    valve = Valve(stoichiometry, current_A, valve_position_percent=40)

    # Print initial total air mass flow rate
    print(f"Total air mass flow (kg/s): {valve.total_air_mass_flow_kg_s:.4f}")
    print(f"Initial valve position: {valve.get_valve_position()}%")

    # Update valve position
    valve.set_valve_position(60)
    print(f"Updated valve position: {valve.get_valve_position()}%")

    # Get the mass flow rates through bypass and humidifier
    mass_flow_bypass, mass_flow_humidifier = valve.calculate_bypass_flow()

    print(f"Mass flow through bypass: {mass_flow_bypass:.4f} kg/s")
    print(f"Mass flow through humidifier: {mass_flow_humidifier:.4f} kg/s")
