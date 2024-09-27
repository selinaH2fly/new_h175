import CoolProp.HumidAirProp as HAP
import numpy as np


class MoistExchanger:
    def __init__(self, air_flow_rate, temperature, pressure, rh):
        self.air_flow_rate = air_flow_rate  # m^3/s
        self.temperature = temperature  # Celsius
        self.pressure = pressure * 1000  # Pa (from kPa)
        self.rh = rh / 100  # Relative humidity in decimal

    def calculate_cp(self, T, RH, P):
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
        return A * np.exp((B * T) / (T + C)) * 100  # Convert to Pa

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
        self.T_dry_out = T_dry_out  # Celsius
        self.P_dry_out = P_dry_out * 1000  # Pa
        self.RH_dry_out = RH_dry_out / 100  # Relative humidity in decimal
        self.T_wet_in = T_wet_in  # Celsius
        self.P_wet_in = P_wet_in * 1000  # Pa
        self.RH_wet_in = RH_wet_in / 100  # Relative humidity in decimal
        self.P_wet_out = P_wet_out * 1000  # Pa

        # Calculate properties
        self.calculate_properties()

    def calculate_properties(self):
        # Calculate properties for both dry and wet air
        self.Cp_dry = self.calculate_cp(self.temperature, self.rh, self.pressure)
        self.Cp_wet = self.calculate_cp(self.T_wet_in, self.RH_wet_in, self.P_wet_in)

        self.dewpoint_dry_in = self.calculate_dewpoint(self.temperature, self.rh, self.pressure)
        self.dewpoint_dry_out = self.calculate_dewpoint(self.T_dry_out, self.RH_dry_out, self.P_dry_out)
        self.dewpoint_wet_in = self.calculate_dewpoint(self.T_wet_in, self.RH_wet_in, self.P_wet_in)
        self.dewpoint_wet_out = self.calculate_dewpoint(self.T_wet_in, 1, self.P_wet_out)  # RH=1 for saturated vapor

        self.p_sat_dry_in = self.calculate_saturation_pressure(self.temperature)
        self.p_sat_dry_out = self.calculate_saturation_pressure(self.T_dry_out)
        self.p_sat_wet_in = self.calculate_saturation_pressure(self.T_wet_in)

        self.p_vap_dry_in = self.p_sat_dry_in * self.rh
        self.p_vap_dry_out = self.p_sat_dry_out * self.RH_dry_out
        self.p_vap_wet_in = self.p_sat_wet_in * self.RH_wet_in

        # Mass flow of water vapor transfer
        # Wrong Result!!
        self.water_transfer = self.calculate_water_transfer(self.p_vap_wet_in, self.p_vap_dry_out, self.T_dry_out,
                                                            self.RH_dry_out, self.T_wet_in, self.RH_wet_in)
    """
    def display_results(self):
        print("=== Humidifier Results ===")
        print(f"Air Flow Rate: {self.air_flow_rate:.4f} m³/s")

        print(
            f"Dry Air In: T = {self.temperature:.2f} °C, P = {self.pressure / 1000:.2f} kPa, RH = {self.rh * 100:.2f} %")
        print(
            f"Dry Air Out: T = {self.T_dry_out:.2f} °C, P = {self.P_dry_out / 1000:.2f} kPa, RH = {self.RH_dry_out * 100:.2f} %")

        print(
            f"Wet Air In: T = {self.T_wet_in:.2f} °C, P = {self.P_wet_in / 1000:.2f} kPa, RH = {self.RH_wet_in * 100:.2f} %")
        print(f"Wet Air Out: P = {self.P_wet_out / 1000:.2f} kPa")  # Assuming you will calculate T_wet_out

        print(f"Dew Point Dry In: {self.dewpoint_dry_in:.2f} °C")
        print(f"Dew Point Dry Out: {self.dewpoint_dry_out:.2f} °C")
        print(f"Dew Point Wet In: {self.dewpoint_wet_in:.2f} °C")
        print(f"Dew Point Wet Out: {self.dewpoint_wet_out:.2f} °C")

        print(f"Water Vapor Transfer: {self.water_transfer:.4f} kg/s")

        # Add more results as needed


# Example usage
humidifier = Humidifier(
    air_flow_rate=5500 / 60000,  # Convert to m³/s
    T_dry_in=80.3,
    P_dry_in=105,  # kPa
    RH_dry_in=18.8,  # %
    T_dry_out=73.9,
    P_dry_out=101,  # kPa
    RH_dry_out=75.7,  # %
    T_wet_in=80.2,
    P_wet_in=76.6,  # kPa
    RH_wet_in=99,  # %
    P_wet_out=76.6  # kPa
)

humidifier.display_results()
"""