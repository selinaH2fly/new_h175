import numpy as np
import CoolProp.HumidAirProp as HAP
import CoolProp as CP
from cathode_model_run import PhysicalParameters, AirFilterParameters


class FuelCellAirFilter:
    def __init__(self, air_mass_flow_kg_s, temperature_in_K, pressure_in_Pa, relative_humidity):
        """
        Initialize the air filter with input air flow conditions.

        :param air_mass_flow_kg_s: Total air mass flow rate in kg/s
        :param temperature_in_K: Temperature in Kelvin
        :param pressure_in_Pa: Pressure in Pascals
        :param relative_humidity: Relative humidity (0 to 1 scale)
        """
        self.air_mass_flow_kg_s = air_mass_flow_kg_s
        self.temperature_in_K = temperature_in_K
        self.pressure_in_Pa = pressure_in_Pa
        self.relative_humidity = relative_humidity
        self.parameters = AirFilterParameters()  # Load parameters from cathode_model_run

        # Physical constants
        params_physics = PhysicalParameters()
        self.R_Air = params_physics.R_air
        self.R_Vap = params_physics.R_water_vapor
        self.P_std = params_physics.P_std
        self.T_std = params_physics.T_std
        self.M_air = params_physics.M_air
        self.R = params_physics.R

        self.air_density_kg_m3 = self.calculate_density()

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

    def get_pressure_drop(self):
        """
        Convert mass flow to volumetric flow rate in thousands of liters per minute,
        and interpolate the pressure drop from the provided map (in Pascals).

        :return: Pressure drop in Pa
        """
        # Convert mass flow from kg/s to m³/min using density, then to thousand l/min
        volume_flow_thousand_l_min = (self.air_mass_flow_kg_s / self.air_density_kg_m3) * 60
        # Interpolate pressure drop in Pa
        pressure_drop_Pa = np.interp(
            volume_flow_thousand_l_min,
            self.parameters.mass_flow_map_lpm,
            self.parameters.pressure_loss_map_pa
        )

        return pressure_drop_Pa


# # Example usage of FuelCellAirFilter class
#
# # Define example input parameters
# example_air_mass_flow_kg_s = 0.166       # Air mass flow in kg/s
# example_temperature_in_K = 273+80          # Air temperature in Kelvin
# example_pressure_in_Pa = 196000          # Air pressure in Pascals
# example_relative_humidity = 0.8          # Relative humidity (0.9 represents 90%)
#
# # Initialize the FuelCellAirFilter instance
# air_filter = FuelCellAirFilter(
#     air_mass_flow_kg_s=example_air_mass_flow_kg_s,
#     temperature_in_K=example_temperature_in_K,
#     pressure_in_Pa=example_pressure_in_Pa,
#     relative_humidity=example_relative_humidity
# )
#
# # Calculate the pressure drop across the air filter
# pressure_drop = air_filter.get_pressure_drop()
# print(f"Calculated Pressure Drop: {pressure_drop:.2f} Pa")
#
# # Calculate the density of humid air using two methods
# density = air_filter.calculate_density()
# check_density = air_filter.calculate_density()
#
# # Display the results
# print(f"Density of humid air (calculated): {density:.3f} kg/m³")
