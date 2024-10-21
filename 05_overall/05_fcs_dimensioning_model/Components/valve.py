import numpy as np
from cathode_model_run import ValveParameters


class Valve:
    def __init__(self, total_air_mass_flow_kg_s, valve_position_percent=0):
        """
        Initializes the Valve with total air mass flow rate and valve position.

        Args:
           total_air_mass_flow_kg_s : total mass flow of air before valve entrance
            valve_position_percent: The valve position in percentage (0-100%) where 0% is fully closed
                                    and 100% is fully open.
        """
        # Compute total air mass flow rate in kg/s
        self.total_air_mass_flow_kg_s = total_air_mass_flow_kg_s
        self.valve_position_percent = valve_position_percent
        self.valve_parameters = ValveParameters()  # Access valve map data

    def get_valve_position(self):
        """Returns the current valve position in percentage."""
        return self.valve_position_percent

    def set_valve_position(self, new_valve_position):
        """Update the valve position."""
        self.valve_position_percent = new_valve_position

    def interpolate_mass_flow(self, position, pressure_drop):
        """
        Interpolates the mass flow based on valve position using the valve map data.

        Args:
            position: The valve opening percentage (0-100%).
            pressure_drop: The pressure drop data to use for interpolation
        """
        valve_opening_percentages = np.array(self.valve_parameters.pwm, dtype=float)
        pressure_data = np.array(getattr(self.valve_parameters, pressure_drop), dtype=float)

        if position <= min(valve_opening_percentages):
            return 0  # Return 0 mass flow if position is below the minimum (6%)
        elif position >= max(valve_opening_percentages):
            return max(pressure_data)  # Return max mass flow for position >= 94%

        # Interpolating mass flow between given valve positions
        return np.interp(position, valve_opening_percentages, pressure_data)

#TODO: bypass flow calculation shall go to architecture file

    def calculate_bypass_flow(self, pressure_drop):
        """
        Calculates the bypass and main branch mass flow rates based on the valve position.

        Args:
            pressure_drop: The pressure drop condition to use (e.g., 'pressure_1kpa').
        """
        bypass_mass_flow_g_s = self.interpolate_mass_flow(self.valve_position_percent, pressure_drop)

        # Convert g/s to kg/s
        bypass_mass_flow_kg_s = bypass_mass_flow_g_s / 1000

        # Remaining air mass flow through the main branch (humidifier)
        mass_flow_main_kg_s = self.total_air_mass_flow_kg_s - bypass_mass_flow_kg_s
        return bypass_mass_flow_kg_s, mass_flow_main_kg_s

# Example usage:
if __name__ == "__main__":
    # Example inputs
    valve = Valve(0.165, valve_position_percent=40)

    print(f"Total air mass flow (kg/s): {valve.total_air_mass_flow_kg_s:.4f}")
    print(f"Initial valve position: {valve.get_valve_position()}%")

    # Update valve position
    valve.set_valve_position(94)
    print(f"Updated valve position: {valve.get_valve_position()}%")

    # Get the mass flow rates through bypass and humidifier using 1kPa pressure drop
    mass_flow_bypass, mass_flow_humidifier = valve.calculate_bypass_flow('pressure_5kpa')

    print(f"Mass flow through bypass (kg/s): {mass_flow_bypass:.4f}")
    print(f"Mass flow through humidifier (kg/s): {mass_flow_humidifier:.4f}")