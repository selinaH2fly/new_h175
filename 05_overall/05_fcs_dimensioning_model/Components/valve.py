import numpy as np
from cathode_model_run import ValveParameters


class Valve:
    def __init__(self, total_air_mass_flow_kg_s, valve_position_percent=0, pressure_input_pa=0, pressure_output_pa=0):
        """
        Initializes the Valve with total air mass flow rate, valve position, and pressures.

        Args:
            total_air_mass_flow_kg_s : total mass flow of air before valve entrance
            valve_position_percent: The valve position in percentage (0-100%) where 0% is fully closed
                                    and 100% is fully open.
            pressure_input_pa: The input pressure to the valve in Pa.
            pressure_output_pa: The output pressure from the valve in Pa.
        """
        self.total_air_mass_flow_kg_s = total_air_mass_flow_kg_s
        self.valve_position_percent = valve_position_percent
        self.valve_parameters = ValveParameters()  # Access valve map data
        self.pressure_input_pa = pressure_input_pa
        self.pressure_output_pa = pressure_output_pa


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

    def calculate_pressure_drop(self):
        """Calculate the pressure drop across the valve in kPa."""
        return (self.pressure_input_pa - self.pressure_output_pa) / 1000  # Convert Pa to kPa

    def calculate_bypass_flow(self):
        """
        Calculates the bypass and main branch mass flow rates based on the valve position.
        Uses self.pressure_input_pa and self.pressure_output_pa for pressure values.
        """
        bypass_mass_flow_g_s = self.interpolate_mass_flow(self.valve_position_percent)
        bypass_mass_flow_kg_s = bypass_mass_flow_g_s / 1000

        mass_flow_main_kg_s = self.total_air_mass_flow_kg_s - bypass_mass_flow_kg_s
        return bypass_mass_flow_kg_s, mass_flow_main_kg_s

    def find_valve_position_for_target_flow(self, target_bypass_flow_g_s):
        """
        Finds the valve position percentage that achieves the target bypass flow within a given tolerance.

        Args:
            target_bypass_flow_g_s: The target bypass flow in g/s.
            tolerance: The allowable difference between calculated and target bypass flow in g/s.

        Returns:
            The valve opening percentage to achieve the target bypass flow, or the closest match if not found.
        """
        # Set a default tolerance internally
        tolerance = 0.5  # Adjust tolerance as needed, for example, 0.5 g/s

        # Calculate pressure drop and find closest pressure levels
        pressure_drop_kpa = round(self.calculate_pressure_drop())
        available_pressures = [1, 2, 5, 10, 20, 30]  # Available pressure drops in kPa from ValveParameters

        # Find closest pressure levels for interpolation/extrapolation
        lower_pressure = max([p for p in available_pressures if p <= pressure_drop_kpa], default=None)
        upper_pressure = min([p for p in available_pressures if p >= pressure_drop_kpa], default=None)

        if lower_pressure is None or upper_pressure is None:
            raise ValueError("No available data for extrapolating the desired pressure drop.")

        # Retrieve the data for the two closest pressure levels
        lower_attr = f'pressure_{lower_pressure}kpa'
        upper_attr = f'pressure_{upper_pressure}kpa'
        valve_opening_percentages = np.array(self.valve_parameters.pwm, dtype=float)

        lower_pressure_data = np.array(getattr(self.valve_parameters, lower_attr), dtype=float)
        upper_pressure_data = np.array(getattr(self.valve_parameters, upper_attr), dtype=float)

        # Interpolate mass flow values between the two pressure levels
        interpolated_flow_data = []
        for lower_flow, upper_flow in zip(lower_pressure_data, upper_pressure_data):
            if np.isnan(lower_flow) or np.isnan(upper_flow):
                interpolated_flow_data.append(np.nan)
            else:
                interpolated_value = np.interp(pressure_drop_kpa, [lower_pressure, upper_pressure],
                                               [lower_flow, upper_flow])
                interpolated_flow_data.append(interpolated_value)
        interpolated_flow_data = np.array(interpolated_flow_data)

        # Remove NaN values for interpolation of valve position
        valid_indices = ~np.isnan(interpolated_flow_data)
        valve_opening_percentages = valve_opening_percentages[valid_indices]
        interpolated_flow_data = interpolated_flow_data[valid_indices]

        # Print the range of interpolated flows for debugging
        min_flow, max_flow = min(interpolated_flow_data), max(interpolated_flow_data)
        print(f"Interpolated flow range: {min_flow:.2f} g/s to {max_flow:.2f} g/s")
        print(f"Target bypass flow: {target_bypass_flow_g_s} g/s")

        # If the target flow is outside the interpolated range, return the closest available position
        if target_bypass_flow_g_s <= min_flow + tolerance:
            print("Target flow is lower than available data range. Returning closest lower match.")
            return valve_opening_percentages[0]  # Return minimum opening
        elif target_bypass_flow_g_s >= max_flow - tolerance:
            print("Target flow is higher than available data range. Returning closest upper match.")
            return valve_opening_percentages[-1]  # Return maximum opening

        # Search within interpolated range
        closest_position = None
        closest_difference = float('inf')
        for position in valve_opening_percentages:
            interpolated_flow = np.interp(position, valve_opening_percentages, interpolated_flow_data)
            difference = abs(interpolated_flow - target_bypass_flow_g_s)

            if difference < tolerance:
                return position  # Exact match within tolerance
            elif difference < closest_difference:
                closest_difference = difference
                closest_position = position  # Update closest position

        # Return the closest position if no exact match is found
        if closest_position is not None:
            print(f"No exact match found. Returning closest match at {closest_position}% valve opening.")
        return closest_position


    def print_debug_info(self):
        """Print debug information including pressure difference and total air mass flow."""
        pressure_drop_kpa = self.calculate_pressure_drop()
        print(f"Pressure Difference (kPa): {pressure_drop_kpa} kPa")
        print(f"Total Air Mass Flow (kg/s): {self.total_air_mass_flow_kg_s} kg/s")
        print(f"Pressure Input (Pa): {self.pressure_input_pa}")
        print(f"Pressure Output (Pa): {self.pressure_output_pa}")

if __name__ == "__main__":
    # Define the parameters
    total_air_mass_flow_kg_s = 0.1563
    pressure_input_pa = 314878
    pressure_output_pa = 300000
    target_bypass_flow_g_s = total_air_mass_flow_kg_s * 1000  # Convert to g/s

    # Initialize the valve and set pressures
    valve = Valve(total_air_mass_flow_kg_s, pressure_input_pa=pressure_input_pa, pressure_output_pa=pressure_output_pa)

    # Print debug information
    valve.print_debug_info()

    # Find the valve opening percentage for the desired bypass flow
    valve_position = valve.find_valve_position_for_target_flow(target_bypass_flow_g_s)

    if valve_position is not None:
        print(f"Valve opening percentage to achieve {target_bypass_flow_g_s} g/s bypass flow: {valve_position}%")
    else:
        print("No suitable valve opening percentage found to achieve the target bypass flow.")
