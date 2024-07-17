import CoolProp.CoolProp as CP

class Compressor:
    def __init__(self, params_physics, isentropic_efficiency=0.75, electric_efficiency=0.95):

        self.isentropic_efficiency = isentropic_efficiency
        self.electric_efficiency = electric_efficiency
        self.params_physics = params_physics

    def compressor_power(self, air_mass_flow_kg_s, pressure_out_Pa, flight_level_100ft=50):
        """
        Calculate the electrical power consumed by the compressor.

        Args:
        - air_mass_flow_kg_s: The air mass flow rate in kg/s.
        - pressure_in_Pa: The inlet pressure in Pascals.
        - pressure_out_Pa: The outlet pressure in Pascals.
        - temperature_in_K: The inlet temperature in Kelvin.

        Returns:
        - compressor_el_power_W: The electrical power required for the compressor in Watts.
        """

        # Evaluate the temperature and pressure at the given flight level
        temperature_in_K, pressure_in_Pa = self.icao_atmosphere(flight_level_100ft)

        # Calculate the pressure ratio
        pressure_ratio = pressure_out_Pa / pressure_in_Pa

        # Calculate the specific work input to the compressor (isentropic work)
        specific_compressor_work_isentropic = CP.PropsSI('C', 'T', temperature_in_K, 'P', pressure_in_Pa, 'Air') * temperature_in_K * \
            ((pressure_ratio ** ((self.params_physics.specific_heat_ratio - 1) / self.params_physics.specific_heat_ratio)) - 1)
        
        # Adjust for isentropic efficiency
        specific_compressor_work = specific_compressor_work_isentropic / self.isentropic_efficiency

        # Multiply by the flow rate to get the total power requirement
        compressor_power_W = specific_compressor_work * air_mass_flow_kg_s

        # Calculate the electrical power required
        compressor_el_power_W = compressor_power_W / self.electric_efficiency

        return compressor_el_power_W
    
    def icao_atmosphere(self, flight_level_100ft):
        """
        Calculate the temperature and pressure at a given altitude using the ICAO atmosphere model.
        """

        # Calculate the altitude in meters
        altitude_m = flight_level_100ft * 100 * 0.3048

        # Calculate the temperature and pressure at the given altitude
        temperature_K = self.params_physics.sea_level_ambient_temperature_K - self.params_physics.temperature_lapse_rate * altitude_m
        pressure_Pa = self.params_physics.sea_level_ambient_pressure_bar*1e5 * \
            (1 - self.params_physics.temperature_lapse_rate * altitude_m / self.params_physics.sea_level_ambient_temperature_K) ** \
                (self.params_physics.gravity / (self.params_physics.specific_gas_constant * self.params_physics.temperature_lapse_rate))

        return temperature_K, pressure_Pa
