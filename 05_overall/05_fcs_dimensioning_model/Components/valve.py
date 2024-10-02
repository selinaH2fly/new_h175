class Valve:
    def __init__(self, total_air_mass_flow_kg_s, valve_position_percent=0):
        """
        Initializes the Valve.

        Args:
            total_air_mass_flow_kg_s: Total mass flow rate of air (kg/s) that goes into the system (before splitting to bypass/humidifier).
            valve_position_percent: The valve position in percentage (0-100%) where 0% is fully closed (all air goes to humidifier)
                                    and 100% is fully open (all air bypasses the humidifier).
        """
        self.total_air_mass_flow_kg_s = total_air_mass_flow_kg_s
        self.valve_position_percent = valve_position_percent / 100  # Convert percent to a fraction for calculations


    def get_valve_position(self):
        """
        Returns the current valve position in percentage.
        """
        return self.valve_position_percent * 100

    def calculate_bypass_flow(self):
        """
        Calculates the mass flow rates of air going through the bypass and the main branch based on the valve position.

        Returns:
            Tuple: (mass_flow_bypass_kg_s, mass_flow_main_kg_s)
        """
        # Air mass flow rate through bypass (controlled by valve position)
        mass_flow_bypass_kg_s = self.total_air_mass_flow_kg_s * self.valve_position_percent

        # Air mass flow rate through humidifier (remainder after bypass)
        mass_flow_main_kg_s = self.total_air_mass_flow_kg_s * (1 - self.valve_position_percent)

        return mass_flow_bypass_kg_s, mass_flow_main_kg_s

# Example usage:
if __name__ == "__main__":
    # Example of total air mass flow (kg/s)
    total_air_mass_flow_kg_s = 0.1  # Example mass flow rate in kg/s

    # Create a Valve object with 40% of air bypassing the humidifier
    valve = Valve(total_air_mass_flow_kg_s, valve_position_percent=40)

    # Get the mass flow rates through bypass and humidifier
    mass_flow_bypass, mass_flow_humidifier = valve.calculate_bypass_flow()

    print(f"Mass flow through bypass: {mass_flow_bypass:.4f} kg/s")
    print(f"Mass flow through humidifier: {mass_flow_humidifier:.4f} kg/s")

