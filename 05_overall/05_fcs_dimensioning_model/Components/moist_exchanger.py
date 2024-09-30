import CoolProp.HumidAirProp as HAP
import numpy as np


class MoistExchanger:
    """
    A class to model the basic physics of a moisture exchanger.
    This class will later be used as a superclass for multiple moisture exchanger types.
    """

    def __init__(self, air_mass_flow_kg_s_dry=0.086, air_mass_flow_kg_s_wet=0.026,
                 temperature_in_K_dry_in=346.1, pressure_in_Pa_dry_in=21700, rh_dry_in=0.05,
                 temperature_in_K_dry_out=337.8, pressure_in_Pa_dry_out=211000, rh_dry_out=0.88,
                 temperature_in_K_wet_in=348, pressure_in_Pa_wet_in=190000, rh_wet_in=1.0,
                 pressure_in_Pa_wet_out=190000):
        # Dry air parameters
        self.air_mass_flow_kg_s_dry = air_mass_flow_kg_s_dry
        self.temperature_in_K_dry_in = temperature_in_K_dry_in
        self.pressure_in_Pa_dry_in = pressure_in_Pa_dry_in
        self.rh_dry_in = rh_dry_in

        self.temperature_in_K_dry_out = temperature_in_K_dry_out
        self.pressure_in_Pa_dry_out = pressure_in_Pa_dry_out
        self.rh_dry_out = rh_dry_out

        # Wet air parameters
        self.air_mass_flow_kg_s_wet = air_mass_flow_kg_s_wet
        self.temperature_in_K_wet_in = temperature_in_K_wet_in
        self.pressure_in_Pa_wet_in = pressure_in_Pa_wet_in
        self.rh_wet_in = rh_wet_in

        self.pressure_in_Pa_wet_out = pressure_in_Pa_wet_out

    def calculate_specific_heat(self, T, RH, P):
        # Calculate specific heat capacity of moist air (Cp) using CoolProp
        return HAP.HAPropsSI('C', 'T', T + 273.15, 'P', P, 'R', RH)

    def calculate_dewpoint(self, T, RH, P):
        # Calculate dew point temperature
        return HAP.HAPropsSI('D', 'T', T + 273.15, 'P', P, 'R', RH) - 273.15

    def calculate_saturation_pressure(self, T):
        # Calculate saturation pressure using August-Roche-Magnus equation
        A = 6.1094  # hPa
        B = 17.625
        C = 243.04  # °C
        return A * np.exp((B * T) / (T + C)) * 100

    def calculate_water_transfer(self, p_vap_wet_in, p_vap_dry_out, T_dry_out, RH_dry_out, T_wet_in, RH_wet_in):
        # Calculate mass flow of water vapor
        m_dot_vap_dry_out = (p_vap_dry_out * 1e5) / (
                HAP.HAPropsSI('R', 'T', T_dry_out + 273.15, 'P', RH_dry_out, 'R', RH_dry_out) * (T_dry_out + 273.15))
        m_dot_vap_wet_in = (p_vap_wet_in * 1e5) / (
                HAP.HAPropsSI('R', 'T', T_wet_in + 273.15, 'P', RH_wet_in, 'R', RH_wet_in) * (T_wet_in + 273.15))
        return m_dot_vap_dry_out - m_dot_vap_wet_in


class Humidifier(MoistExchanger):
    def __init__(self, air_flow_rate, T_dry_in, P_dry_in, RH_dry_in,
                 T_dry_out, P_dry_out, RH_dry_out,
                 T_wet_in, P_wet_in, RH_wet_in, P_wet_out):
        super().__init__(air_flow_rate, T_dry_in, P_dry_in, RH_dry_in)
        self.T_dry_out = T_dry_out
        self.P_dry_out = P_dry_out * 1000
        self.RH_dry_out = RH_dry_out / 100
        self.T_wet_in = T_wet_in
        self.P_wet_in = P_wet_in * 1000
        self.RH_wet_in = RH_wet_in / 100
        self.P_wet_out = P_wet_out * 1000

        # Calculate properties
        self.calculate_properties()

    def calculate_properties(self):
        # Calculate properties for both dry and wet air
        self.Cp_dry = self.calculate_specific_heat(self.temperature, self.rh, self.pressure)
        self.Cp_wet = self.calculate_specific_heat(self.T_wet_in, self.RH_wet_in, self.P_wet_in)

        self.dewpoint_dry_in = self.calculate_dewpoint(self.temperature, self.rh, self.pressure)
        self.dew
