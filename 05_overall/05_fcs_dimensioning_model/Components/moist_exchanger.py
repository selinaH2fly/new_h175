import CoolProp.HumidAirProp as HAP
import numpy as np
from parameters import Physical_Parameters

class MoistExchanger:
    def __init__(self, air_mass_flow_kg_s_dry=0.086, air_mass_flow_kg_s_wet=0.026,
                 temperature_in_k_dry_in=346.1, pressure_in_pa_dry_in=21700, rh_dry_in=0.05,
                 temperature_in_k_dry_out=337.8, pressure_in_pa_dry_out=211000, rh_dry_out=0.88,
                 temperature_in_k_wet_in=348, pressure_in_pa_wet_in=190000, rh_wet_in=1.0,
                 pressure_in_pa_wet_out=190000):
        # Dry air parameters
        self.air_mass_flow_kg_s_dry = air_mass_flow_kg_s_dry
        self.temperature_in_k_dry_in = temperature_in_k_dry_in
        self.pressure_in_pa_dry_in = pressure_in_pa_dry_in
        self.rh_dry_in = rh_dry_in

        self.temperature_in_k_dry_out = temperature_in_k_dry_out
        self.pressure_in_pa_dry_out = pressure_in_pa_dry_out
        self.rh_dry_out = rh_dry_out

        # Wet air parameters
        self.air_mass_flow_kg_s_wet = air_mass_flow_kg_s_wet
        self.temperature_in_k_wet_in = temperature_in_k_wet_in
        self.pressure_in_pa_wet_in = pressure_in_pa_wet_in
        self.rh_wet_in = rh_wet_in

        self.pressure_in_pa_wet_out = pressure_in_pa_wet_out

        # Use the constants from Physical_Parameters
        params_physics = Physical_Parameters()
        self.R_Air = params_physics.R_Air
        self.R_Vap = params_physics.R_Vap
        self.molar_mass_water = params_physics.molar_mass_water


    def calculate_specific_heat(self, t, p, rh) -> float:
        return HAP.HAPropsSI('C', 'T', t, 'P', p, 'R', rh)

    def calculate_density(self, t, p, rh):
        density = HAP.HAPropsSI('D', 'T', t, 'P', p, 'R', rh)
        return density

    def calculate_dewpoint(self, t, p, rh):
        dew_point_temp = HAP.HAPropsSI('D', 'T', t, 'P', p, 'R', rh)
        return dew_point_temp

    def calculate_saturation_pressure(self, t):
        A = 6.1094
        B = 17.625
        C = 243.04
        return A * np.exp((B * (t - 273.15)) / ((t - 273.15) + C)) * 100

    def calculate_partial_pressure(self, t, rh):
        """
        Calculate the water vapor partial pressure for a given temperature and relative humidity.

        Args:
            temperature_k: Temperature in Kelvin.
            relative_humidity: Relative humidity as a fraction (0-1).

        Returns:
            float: Vapor pressure in Pascals.
        """
        # Calculate saturation pressure for the given temperature
        p_sat = self.calculate_saturation_pressure(t)

        # Calculate partial pressure using saturation pressure and relative humidity
        p_vap = p_sat * rh

        return p_vap

    def calculate_water_transfer(self, p_vap_dry_in, p_vap_dry_out, p_vap_wet_in, v_dot_dry, v_dot_wet, t_dry_in, t_dry_out, t_wet_in):
        """
        Calculate the mass flow rate of water vapor transfer and efficiency.

        Args:
            p_vap_dry_in: Vapor pressure of dry air in Pascals.
            p_vap_dry_out: Vapor pressure of dry air in Pascals.
            p_vap_wet_in: Vapor pressure of wet air in Pascals.
            v_dot_dry: Volume flow rate of dry air in m³/s.
            v_dot_wet: Volume flow rate of wet air in m³/s.
            t_dry_in: Temperature of dry air in Kelvin.
            t_dry_out: Temperature of dry air in Kelvin.
            t_wet_in: Temperature of wet air in Kelvin.

        Returns:
            mass flow rate of water vapor (kg/s), efficiency
        """
        R_water = self.R_Vap

        #ToDo: Can it be in basic physics to calculate n?

        # Calculate number of moles/s
        n_vap_dry_in = (p_vap_dry_in  * v_dot_dry) / (R_water * t_dry_in)
        n_vap_dry_out = (p_vap_dry_out  * v_dot_dry) / (R_water * t_dry_out)
        n_vap_wet_in = (p_vap_wet_in  * v_dot_wet) / (R_water * t_wet_in)

        # Calculate mass flow rates of water vapor
        m_vap_dry_in = molar_mass_water * n_vap_dry_in  # kg/s
        m_vap_dry_out = molar_mass_water * n_vap_dry_out  # kg/s
        m_vap_wet_in = molar_mass_water * n_vap_wet_in  # kg/s

        eta_water_trans = m_vap_dry_out / m_vap_wet_in if m_vap_wet_in != 0 else 0

        m_dot_water_trans = eta_water_trans * m_vap_wet_in - m_vap_dry_in

        return m_dot_water_trans, eta_water_trans

    def calculate_mass_flows(self):
        """
        Calculate the mass flows of air and vapor for both dry and wet air at inlet and outlet.
        Returns:
            Dictionary of mass flow rates.
        """
        # Calculate dry inlet vapor and air mass flows
        x_dry_in = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure(self.temperature_in_k_dry_in,
                                                                               self.rh_dry_in) / (
                               self.pressure_in_pa_dry_in - self.calculate_partial_pressure(
                           self.temperature_in_k_dry_in, self.rh_dry_in))
        m_dot_air_dry_in = self.air_mass_flow_kg_s_dry / (1 + x_dry_in)
        m_dot_vap_dry_in = self.air_mass_flow_kg_s_dry - m_dot_air_dry_in

        # Calculate dry outlet vapor and air mass flows
        x_dry_out = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure(self.temperature_in_k_dry_out,
                                                                                self.rh_dry_out) / (
                                self.pressure_in_pa_dry_out - self.calculate_partial_pressure(
                            self.temperature_in_k_dry_out, self.rh_dry_out))
        m_dot_air_dry_out = m_dot_air_dry_in  # Air mass flow remains the same
        m_dot_vap_dry_out = x_dry_out * m_dot_air_dry_out
        m_dot_dry_out = m_dot_vap_dry_out + m_dot_air_dry_out

        # Calculate wet inlet vapor and air mass flows
        x_wet_in = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure(self.temperature_in_k_wet_in,
                                                                               self.rh_wet_in) / (
                               self.pressure_in_pa_wet_in - self.calculate_partial_pressure(
                           self.temperature_in_k_wet_in, self.rh_wet_in))
        m_dot_air_wet_in = self.air_mass_flow_kg_s_wet / (1 + x_wet_in)
        m_dot_vap_wet_in = self.air_mass_flow_kg_s_wet - m_dot_air_wet_in

        # Calculate wet outlet vapor and air mass flows
        m_dot_air_wet_out = m_dot_air_wet_in
        m_dot_vap_wet_out = m_dot_vap_wet_in - m_dot_vap_dry_in
        m_dot_wet_out = m_dot_air_wet_out + m_dot_vap_wet_out

        # Return calculated mass flows as a dictionary
        return {
            "m_dot_air_dry_in": m_dot_air_dry_in,
            "m_dot_vap_dry_in": m_dot_vap_dry_in,
            "m_dot_air_dry_out": m_dot_air_dry_out,
            "m_dot_vap_dry_out": m_dot_vap_dry_out,
            "m_dot_dry_out": m_dot_dry_out,
            "m_dot_air_wet_in": m_dot_air_wet_in,
            "m_dot_vap_wet_in": m_dot_vap_wet_in,
            "m_dot_air_wet_out": m_dot_air_wet_out,
            "m_dot_vap_wet_out": m_dot_vap_wet_out,
            "m_dot_wet_out": m_dot_wet_out
        }

class Humidifier(MoistExchanger):
    def __init__(self, **kwargs):
        """
        Initialize the Humidifier class and pass any relevant arguments to the parent class.
        """
        super().__init__(**kwargs)


# %% Example usage of the code:
# Create an instance of Humidifier
humidifier = Humidifier(
    air_mass_flow_kg_s_dry=0.09,
    air_mass_flow_kg_s_wet=0.053,
    temperature_in_k_dry_in=353.3,
    pressure_in_pa_dry_in=105000,
    rh_dry_in=0.18,
    temperature_in_k_dry_out=346.9,
    pressure_in_pa_dry_out=101000,
    rh_dry_out=0.75,
    temperature_in_k_wet_in=353.2,
    pressure_in_pa_wet_in=76000,
    rh_wet_in=0.99,
    pressure_in_pa_wet_out=76000
)

# # Calculate specific heat
# specific_heat = humidifier.calculate_specific_heat(humidifier.temperature_in_k_dry_in, humidifier.pressure_in_pa_dry_in, humidifier.rh_dry_in)
# print(f"Specific Heat Capacity: {specific_heat:.2f} J/kg.K")
#
# # Calculate and print dew point temperature
# dew_point_temp_wet_in = humidifier.calculate_dewpoint(humidifier.temperature_in_k_wet_in, humidifier.pressure_in_pa_wet_in, humidifier.rh_wet_in)
# print(f"Dew Point Temperature Wet In: {dew_point_temp_wet_in-273:.2f} K")
#
# # Calculate and print dew point temperature
# dew_point_temp_dry_in = humidifier.calculate_dewpoint(humidifier.temperature_in_k_dry_in, humidifier.pressure_in_pa_dry_in, humidifier.rh_dry_in)
# print(f"Dew Point Temperature Dry In: {dew_point_temp_dry_in-273:.2f} K")
#
# # For dry air inlet
# p_sat_dry_in = humidifier.calculate_saturation_pressure(humidifier.temperature_in_k_dry_in)
# print(f"Saturation pressure (dry air inlet): {p_sat_dry_in:.2f} Pa")
#
# # For dry air inlet
# p_vap_dry_in = humidifier.calculate_partial_pressure(humidifier.temperature_in_k_dry_in, humidifier.rh_dry_in)
# print(f"Vapor pressure (dry air inlet): {p_vap_dry_in:.2f} Pa")
#
# # For dry air outlet
# p_vap_dry_out = humidifier.calculate_partial_pressure(humidifier.temperature_in_k_dry_out, humidifier.rh_dry_out)
# print(f"Vapor pressure (dry air outlet): {p_vap_dry_out:.2f} Pa")
#
# # For wet air inlet
# p_vap_wet_in = humidifier.calculate_partial_pressure(humidifier.temperature_in_k_wet_in, humidifier.rh_wet_in)
# print(f"Vapor pressure (wet air inlet): {p_vap_wet_in:.2f} Pa")

# Calculate mass flows
# mass_flows = humidifier.calculate_mass_flows()
# print(f"Mass flows: {mass_flows}")