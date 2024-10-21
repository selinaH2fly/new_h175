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

    def interpolate_mass_flow(self, position, pressure_input_pa, pressure_output_pa):
        """
        Interpolates the mass flow based on valve position and pressure difference.

        Args:
            position: The valve opening percentage (0-100%).
            pressure_input_pa: The input pressure (in Pa).
            pressure_output_pa: The output pressure (in Pa).
        """
        # Convert pressures from Pa to kPa for matching with the attribute
        pressure_input_kpa = pressure_input_pa / 1000
        pressure_output_kpa = pressure_output_pa / 1000

        # Calculate pressure difference (in kPa)
        pressure_difference = pressure_input_kpa - pressure_output_kpa

        # Check if the pressure difference is valid
        if pressure_difference <= 0:
            return 0  # No flow if the output pressure is equal to or greater than input pressure

        # Round the pressure difference to the nearest integer for attribute access
        pressure_difference_rounded = round(pressure_difference)

        # Create the attribute name
        pressure_attr = f'pressure_{pressure_difference_rounded}kpa'

        # Check if the attribute exists
        if not hasattr(self.valve_parameters, pressure_attr):
            raise ValueError(f"Pressure data for {pressure_difference_rounded} kPa not available.")

        valve_opening_percentages = np.array(self.valve_parameters.pwm, dtype=float)
        pressure_data = np.array(getattr(self.valve_parameters, pressure_attr), dtype=float)

        if position <= min(valve_opening_percentages):
            return 0  # Return 0 mass flow if position is below the minimum (6%)
        elif position >= max(valve_opening_percentages):
            return max(pressure_data)  # Return max mass flow for position >= 94%

        # Interpolating mass flow between given valve positions
        return np.interp(position, valve_opening_percentages, pressure_data)

    #TODO: bypass flow calculation shall go to architecture file
    def calculate_bypass_flow(self, pressure_input_pa, pressure_output_pa):
        """
        Calculates the bypass and main branch mass flow rates based on the valve position.

        Args:
            pressure_input_pa: The input pressure (in Pa).
            pressure_output_pa: The output pressure (in Pa).
        """
        bypass_mass_flow_g_s = self.interpolate_mass_flow(self.valve_position_percent, pressure_input_pa,
                                                          pressure_output_pa)

        # Convert g/s to kg/s
        bypass_mass_flow_kg_s = bypass_mass_flow_g_s / 1000

        # Remaining air mass flow through the main branch (humidifier)
        mass_flow_main_kg_s = self.total_air_mass_flow_kg_s - bypass_mass_flow_kg_s
        return bypass_mass_flow_kg_s, mass_flow_main_kg_s


# # Example usage:
# if __name__ == "__main__":
#     # Example inputs
#     valve = Valve(0.165, valve_position_percent=40)
#
#     print(f"Total air mass flow (kg/s): {valve.total_air_mass_flow_kg_s:.4f}")
#     print(f"Initial valve position: {valve.get_valve_position()}%")
#
#     # Update valve position
#     valve.set_valve_position(94)
#     print(f"Updated valve position: {valve.get_valve_position()}%")
#
#     # Get the mass flow rates through bypass and humidifier using input and output pressures
#     mass_flow_bypass, mass_flow_humidifier = valve.calculate_bypass_flow(130000, 125000)  # Example pressures in bara
#
#     print(f"Mass flow through bypass (kg/s): {mass_flow_bypass:.4f}")
#     print(f"Mass flow through humidifier (kg/s): {mass_flow_humidifier:.4f}")
