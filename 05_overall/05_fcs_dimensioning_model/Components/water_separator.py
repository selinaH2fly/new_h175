import numpy as np
import CoolProp.HumidAirProp as HAP
import CoolProp as CP
from cathode_model_run import PhysicalParameters, WaterSeparatorParameters


class WaterSeparator:
    def __init__(self, air_mass_flow_kg_s, temperature_in_K, pressure_in_Pa, relative_humidity):
        """
        Initialize the water separator with input air flow conditions.

        :param air_mass_flow_kg_s: Total air mass flow rate in kg/s
        :param temperature_K: Temperature in Kelvin
        :param pressure_Pa: Pressure in Pascals
        :param relative_humidity: Relative humidity (0 to 1 scale)
        """
        self.air_mass_flow_kg_s = air_mass_flow_kg_s
        self.temperature_in_K = temperature_in_K
        self.pressure_in_Pa = pressure_in_Pa
        self.relative_humidity = relative_humidity
        self.parameters = WaterSeparatorParameters()  # Load parameters from cathode_model_run
        # Physical constants
        params_physics = PhysicalParameters()
        self.R_Air = params_physics.R_air
        self.R_Vap = params_physics.R_water_vapor
        self.P_std = params_physics.P_std
        self.T_std = params_physics.T_std
        self.M_air = params_physics.M_air
        self.R = params_physics.R

        self.air_density_kg_m3 = self.calculate_density()

#TODO: change density method and get from coolprop
    def calculate_density(self):
        """
        Calculate the density of humid air given temperature, pressure, and relative humidity.

        Returns:
        - density_humid_air (float): Density of humid air in kg/m³.
        """
        # Constants
        R_air = 287.06  # J/(kg·K), specific gas constant for dry air
        R_vapor = 461.52  # J/(kg·K), specific gas constant for water vapor

        # Calculate saturation vapor pressure (using Antoine equation approximation for water vapor)
        A, B, C = 8.07131, 1730.63, 233.426  # Antoine constants for water (temperature in Celsius)
        temperature_C = self.temperature_in_K - 273.15  # Convert temperature to Celsius
        P_sat_Pa = 10 ** (A - (B / (temperature_C + C))) * 133.322  # Convert mmHg to Pa

        # Partial pressures of dry air and water vapor
        P_v = self.relative_humidity * P_sat_Pa  # Partial pressure of water vapor
        P_d = self.pressure_in_Pa - P_v  # Partial pressure of dry air

        # Calculate density of humid air
        density_humid_air = (P_d / (R_air * self.temperature_in_K)) + (P_v / (R_vapor * self.temperature_in_K))

        return density_humid_air

    #
    #
    # def calculate_densitycp(self, t, p, rh):
    #     densitycp = HAP.HAPropsSI('D', 'T', t, 'P', p, 'R', rh)
    #     return densitycp

    def get_pressure_drop(self):
        """
        Convert mass flow to volumetric flow rate in m³/min, interpolate the pressure drop
        from the provided map, and convert from hPa to Pa.

        :return: Pressure drop in Pa
        """
        # Convert mass flow from kg/s to m³/min using density
        volume_flow_m3_min = (self.air_mass_flow_kg_s / self.air_density_kg_m3) * 60
        print(f"m3/min: {volume_flow_m3_min:.2f} ")

        # Interpolate pressure drop in hPa
        pressure_drop_hPa = np.interp(
            volume_flow_m3_min,
            self.parameters.mass_flow_map_m3_min,
            self.parameters.pressure_loss_map_hpa
        )

        # Convert pressure drop from hPa to Pa
        pressure_drop_Pa = pressure_drop_hPa * 100
        return pressure_drop_Pa

# #TODO: check why coolprop density is so high!
# # Example usage
# separator = WaterSeparator(
#     air_mass_flow_kg_s=0.085,  # example mass flow in kg/s
#     temperature_K=348,  # example temperature in K
#     pressure_Pa=196000,  # example pressure in Pa
#     relative_humidity=0.9  # example relative humidity (90%)
# )
# pressure_drop = separator.get_pressure_drop()
# print(f"Pressure Drop: {pressure_drop:.2f} Pa")
# density = separator.calculate_density()
# print(f"Density of humid air: {density:.3f} kg/m³")



