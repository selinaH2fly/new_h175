import CoolProp.CoolProp as CP
from basic_physics import icao_atmosphere

class Compressor:
    def __init__(self, params_physics, isentropic_efficiency=0.75, electric_efficiency=0.95,
                 air_mass_flow_kg_s=1, pressure_out_Pa=1e5, flight_level_100ft=50,
                 nominal_BoP_pressure_drop_Pa=0.3*1e5, nominal_air_flow_kg_s=0.130, mass_by_power_kg_kW= {"mean": 1.0, "sd": 0.1}):

        self.isentropic_efficiency = isentropic_efficiency
        self.electric_efficiency = electric_efficiency
        self.params_physics = params_physics
        self.air_mass_flow_kg_s = air_mass_flow_kg_s
        self.pressure_out_Pa = pressure_out_Pa
        self.flight_level_100ft = flight_level_100ft
        self.nominal_pressure_drop_Pa = nominal_BoP_pressure_drop_Pa
        self.nominal_air_flow_kg_s = nominal_air_flow_kg_s
        self.mass_by_power_kg_kW = mass_by_power_kg_kW

    def calculate_power(self)->float:
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
        temperature_in_K, pressure_in_Pa = icao_atmosphere(self.flight_level_100ft)

        # Compute the isentropic outlet temperature
        kappa = self.params_physics.specific_heat_ratio # specific heat ratio for H2 and N2 almost equal to air (i.e., 1.4) TODO: snack from coolprop
        isentropic_outlet_temperature_K = temperature_in_K * (self.pressure_out_Pa/pressure_in_Pa)**((kappa-1)/kappa)

        # Compute the specific enthalpies before and after the compressor
        specific_enthalpy_in_J_kg = CP.PropsSI('H', 'T', temperature_in_K, 'P', pressure_in_Pa, 'Air')
        specific_enthalpy_out_J_kg = CP.PropsSI('H', 'T', isentropic_outlet_temperature_K, 'P', self.pressure_out_Pa, 'Air')

        # Compute the isentropic power
        compressor_isentopic_power_W = self.air_mass_flow_kg_s * (specific_enthalpy_out_J_kg - specific_enthalpy_in_J_kg)

        # Compute the electric power
        compressor_shaft_power_W = compressor_isentopic_power_W / self.isentropic_efficiency
        compressor_electric_power_W = compressor_shaft_power_W / self.electric_efficiency

        return compressor_electric_power_W
    
    def calculate_BoP_pressure_drop(self, air_flow_kg_s: float)->float:
        """
        Calculate the pressure drop across the BoP components downstream the compressor for a given air mass flow rate.
        The "model" is a simple quadratic relationship between pressure drop and air mass flow rate.

        :param air_flow_kg_s: Air mass flow rate in [kg/s]
        :return: Pressure drop across the BoP components (compressor out -> cathode in) in [Pa]
        """

        pressure_drop_coefficient = self.nominal_pressure_drop_Pa / (self.nominal_air_flow_kg_s**2)
        pressure_drop_Pa = pressure_drop_coefficient * air_flow_kg_s**2

        return pressure_drop_Pa
    
    def calculate_mass(self)->dict:
        """
        Calculate predicted mass of the compressor utilizing the mass_by_power_kg_kW dict of the class
        
        Returns:
        - result: A dictionary containing:
            - "mean": Compressor mass in kg based on the mean value of mass_by_power_kg_kW.
            - "sd": Compressor mass in kg based on the standard deviation of mass_by_power_kg_kW.

        """
        compressor_el_power_W = self.calculate_power()
        compressor_mass_mean_kg = self.mass_by_power_kg_kW["mean"] * compressor_el_power_W / 1000
        compressor_mass_sd_kg = self.mass_by_power_kg_kW["sd"] * compressor_el_power_W / 1000
        return {
        "mean": compressor_mass_mean_kg,
        "sd": compressor_mass_sd_kg
        }
    
# %% Example Usage:
import parameters   
params_physics = parameters.Physical_Parameters()

C1 = Compressor(params_physics, isentropic_efficiency=0.75, electric_efficiency=0.95,
             air_mass_flow_kg_s=1, pressure_out_Pa=1e5,flight_level_100ft=50)

#electrical power
power_el = C1.calculate_power()
mass = C1.calculate_mass()


