import numpy as np
from cathode_model_run import ValveParameters


class Valve:
    def __init__(self, total_air_mass_flow_kg_s, valve_position_percent=0, pressure_input_pa=0, pressure_output_pa=0):
        """
        Initializes the Valve with total air mass flow rate, valve position, and pressures.

        Args:
            total_air_mass_flow_kg_s : total mass flow of air before valve entrance.
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

    def get_valve_opening_from_map(self):
        """
        Determines the valve opening percentage and mechanical angle based on the input mass flow rate
        and the pressure drop across the valve.

        Returns:
            tuple: Estimated valve opening percentage (rounded up to the nearest integer) and the
                   corresponding mechanical angle.
        """
        # Convert mass flow to g/s
        mass_flow_g_s = self.total_air_mass_flow_kg_s * 1000  # Convert kg/s to g/s

        # Calculate pressure drop in kPa
        pressure_drop_kpa = (self.pressure_input_pa - self.pressure_output_pa) / 1000

        # Select the appropriate pressure drop data array from ValveParameters
        if pressure_drop_kpa <= 1:
            pressure_data = self.valve_parameters.pressure_1kpa
        elif pressure_drop_kpa <= 2:
            pressure_data = self.valve_parameters.pressure_2kpa
        elif pressure_drop_kpa <= 5:
            pressure_data = self.valve_parameters.pressure_5kpa
        elif pressure_drop_kpa <= 10:
            pressure_data = self.valve_parameters.pressure_10kpa
        elif pressure_drop_kpa <= 20:
            pressure_data = self.valve_parameters.pressure_20kpa
        else:
            pressure_data = self.valve_parameters.pressure_30kpa

        # Interpolate the valve opening (PWM) based on mass flow and selected pressure drop data
        opening_percentage = np.interp(mass_flow_g_s, pressure_data, self.valve_parameters.pwm)

        # Round up to the next highest integer for valve opening percentage
        opening_percentage_rounded = int(np.ceil(opening_percentage))

        # Interpolate the mechanical angle based on the rounded opening percentage
        mechanical_angle = np.interp(opening_percentage_rounded, self.valve_parameters.pwm,
                                     self.valve_parameters.mechanical_angle)

        return opening_percentage_rounded, mechanical_angle

# if __name__ == "__main__":
#     # Define parameters
#     total_air_mass_flow_kg_s = 0.0178
#     pressure_input_pa = 314878
#     pressure_output_pa = 300000
#
#     # Create a Valve instance
#     valve = Valve(total_air_mass_flow_kg_s, pressure_input_pa=pressure_input_pa, pressure_output_pa=pressure_output_pa)
#
#     # Call the method to get the valve opening percentage and mechanical angle
#     valve_opening_percentage, mechanical_angle = valve.get_valve_opening_from_map()
#
#     print(f"Calculated valve opening percentage: {valve_opening_percentage}%")
#     print(f"Corresponding mechanical angle: {mechanical_angle:.2f} degrees")

