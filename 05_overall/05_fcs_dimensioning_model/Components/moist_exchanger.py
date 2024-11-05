import CoolProp.HumidAirProp as HAP
import numpy as np
from CoolProp.CoolProp import HAPropsSI
from scipy.interpolate import interp1d
from cathode_model_run import PhysicalParameters, HumidifierParameters


class MoistExchanger:
    def __init__(self, dry_air_mass_flow_kg_s=0.086, wet_air_mass_flow_kg_s=0.026,
                 dry_air_temperature_in_K=346.1, dry_air_pressure_in_Pa=21700, dry_air_rh_in=0.05,
                 dry_air_temperature_out_K=337.8, dry_air_pressure_out_Pa=211000, dry_air_rh_out=0.88,
                 wet_air_temperature_in_K=348, wet_air_pressure_in_Pa=190000, wet_air_rh_in=1.0,
                 wet_air_pressure_out_Pa=190000, humidifier_map=None, o2_mass_flow_rate=0.0025):

        # Initialize all given parameters
        self.o2_mass_flow_rate = o2_mass_flow_rate
        self.dry_air_mass_flow_kg_s = dry_air_mass_flow_kg_s
        self.dry_air_temperature_in_K = dry_air_temperature_in_K
        self.dry_air_pressure_in_Pa = dry_air_pressure_in_Pa
        self.dry_air_rh_in = dry_air_rh_in
        self.dry_air_temperature_out_K = dry_air_temperature_out_K
        self.dry_air_pressure_out_Pa = dry_air_pressure_out_Pa
        self.dry_air_rh_out = dry_air_rh_out
        self.wet_air_mass_flow_kg_s = wet_air_mass_flow_kg_s
        self.wet_air_temperature_in_K = wet_air_temperature_in_K
        self.wet_air_pressure_in_Pa = wet_air_pressure_in_Pa
        self.wet_air_rh_in = wet_air_rh_in
        self.wet_air_pressure_out_Pa = wet_air_pressure_out_Pa

        # Physical constants
        params_physics = PhysicalParameters()
        self.R_Air = params_physics.R_air
        self.R_Vap = params_physics.R_water_vapor
        self.P_std = params_physics.P_std
        self.T_std = params_physics.T_std
        self.M_air = params_physics.M_air
        self.R = params_physics.R

        # Humidifier parameters
        humidifier_params = HumidifierParameters()
        self.humidifier_efficiency_map = humidifier_params.humidifier_efficiency_map
        self.pressure_drop_map = humidifier_params.pressure_drop_map

    def calculate_specific_heat(self, t, p, rh) -> float:
        return HAP.HAPropsSI('C', 'T', t, 'P', p, 'R', rh)

    def calculate_density(self, t, p, rh):
        density = HAP.HAPropsSI('D', 'T', t, 'P', p, 'R', rh)
        return density

    def calculate_dewpoint(self, t, p, rh):
        dew_point_temp = HAP.HAPropsSI('DewPoint', 'T', t, 'P', p, 'R', rh)
        return dew_point_temp

    def convert_kg_s_to_slpm(self, kg_s):
        """
        Convert mass flow rate from kg/s to SLPM (standard liters per minute) using density.

        Parameters:
        - mass_flow_kg_s: float, mass flow rate in kg/s

        Returns:
        - flow_rate_slpm: float, volume flow rate in SLPM
        """
        density_std = 1.225  # kg/m³, standard density of air at 0°C and 101325 Pa

        # Calculate the volume flow rate at standard conditions in m³/s
        volume_flow_m3_s = kg_s / density_std

        # Convert m³/s to SLPM
        flow_rate_slpm = volume_flow_m3_s * 1000 * 60

        return flow_rate_slpm

    def interpolate_dry_pressure_drop(self):
        # Convert dry mass flow rate from kg/s to SLPM
        mass_flow_slpm = self.convert_kg_s_to_slpm(self.dry_air_mass_flow_kg_s)

        # Extract flow rates and corresponding dry pressure drops
        flow_rates = list(self.pressure_drop_map.keys())
        dry_pressure_drops = [self.pressure_drop_map[flow]["dry_side"] for flow in flow_rates]

        # Interpolate the dry pressure drop
        interpolator = interp1d(flow_rates, dry_pressure_drops, kind='linear', fill_value="extrapolate")
        dry_pressure_drop = interpolator(mass_flow_slpm) * 1000  # Convert from kPa to Pa
        return dry_pressure_drop

    def interpolate_wet_pressure_drop(self):
        # Convert wet mass flow rate from kg/s to SLPM
        mass_flow_slpm = self.convert_kg_s_to_slpm(self.wet_air_mass_flow_kg_s)

        # Extract flow rates and corresponding wet pressure drops
        flow_rates = list(self.pressure_drop_map.keys())
        wet_pressure_drops = [self.pressure_drop_map[flow]["wet_side"] for flow in flow_rates]

        # Interpolate the wet pressure drop
        interpolator = interp1d(flow_rates, wet_pressure_drops, kind='linear', fill_value="extrapolate")
        wet_pressure_drop = interpolator(mass_flow_slpm) * 1000  # Convert from kPa to Pa
        return wet_pressure_drop

    def calculate_saturation_pressure(self, t):
        """
         Calculate the saturation pressure of water vapor at a given temperature.

         This function uses the August-Roche-Magnus (or Magnus-Tetens or Magnus) equation to calculate
         the saturation pressure in pascals (Pa).

         Args:
             t (float): Temperature in Kelvin at which to calculate the saturation pressure.
                        Note: The input temperature is expected to be in Kelvin.

         Returns:
             float: The saturation pressure of water vapor at the specified temperature in pascals (Pa).
         """

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

    def calculate_partial_pressure_with_mass_flows(self, m_dot_total, m_dot_vapor, total_pressure_pa):
        """
        Calculate the partial pressure of water vapor using mass flow rates and total conditions.
        """
        # Use the instance variables directly
        R_air = self.R_Air
        R_vapor = self.R_Vap

        # Calculate humidity ratio
        x = m_dot_vapor / (m_dot_total - m_dot_vapor)
        partial_pressure_vapor = (x * total_pressure_pa) / (x + (R_vapor / R_air))

        return partial_pressure_vapor

    def calculate_dry_inlet_mass_flows(self):
        """
        Calculate the mass flows of air and vapor for the dry air at the inlet,
        and return the total mass flow as well.

        Returns:
            Dictionary with dry inlet air and vapor mass flow rates, and total dry inlet mass flow rate.
        """
        # Calculate humidity ratio for dry inlet
        x_dry_in = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure(
            self.dry_air_temperature_in_K, self.dry_air_rh_in) / (
                           self.dry_air_pressure_in_Pa - self.calculate_partial_pressure(
                       self.dry_air_temperature_in_K, self.dry_air_rh_in)
                   )

        # Calculate dry inlet air and vapor mass flows
        m_dot_air_dry_in = self.dry_air_mass_flow_kg_s / (1 + x_dry_in)
        m_dot_vap_dry_in = self.dry_air_mass_flow_kg_s - m_dot_air_dry_in

        # Calculate total dry inlet mass flow
        total_mass_flow_dry_in = m_dot_air_dry_in + m_dot_vap_dry_in

        return {
            "m_dot_air_dry_in": m_dot_air_dry_in,
            "m_dot_vap_dry_in": m_dot_vap_dry_in,
            "total_mass_flow_dry_in": total_mass_flow_dry_in
        }

    def calculate_dry_outlet_mass_flows(self):
        """
        Calculate the mass flows of air and vapor for the dry air at the outlet.
        """
        dry_inlet_flows = self.calculate_dry_inlet_mass_flows()
        m_dot_air_dry_in = dry_inlet_flows["m_dot_air_dry_in"]
        wet_inlet_flows = self.calculate_wet_inlet_mass_flows()
        m_dot_vap_wet_in = wet_inlet_flows["m_dot_vap_wet_in"]
        efficiency = self.calculate_efficiency() / 100


        m_dot_air_dry_out = m_dot_air_dry_in
        m_dot_vap_dry_out = efficiency * m_dot_vap_wet_in
        total_mass_flow_dry_out = m_dot_vap_dry_out + m_dot_air_dry_out

        return {
            "m_dot_air_dry_out": m_dot_air_dry_out,
            "m_dot_vap_dry_out": m_dot_vap_dry_out,
            "total_mass_flow_dry_out": total_mass_flow_dry_out
        }

    def calculate_vapor_mass_flow(self,t,p,rh, air_mass_flow):
        """
        Calculate the mass flow rate of water vapor in a humid air mixture.

        Parameters:
        - temperature (float): Temperature in Kelvin
        - pressure (float): Pressure in Pascal
        - relative_humidity (float): Relative humidity as a fraction (0.0 - 1.0)
        - dry_air_mass_flow (float): Mass flow rate of dry air in kg/s

        Returns:
        - vapor_mass_flow (float): Mass flow rate of water vapor in kg/s
        """
        # Calculate specific humidity (omega) using CoolProp
        specific_humidity = HAPropsSI('HumRat', 'T', temperature, 'P', pressure, 'RH', relative_humidity)

        # Calculate the mass flow rate of water vapor
        vapor_mass_flow = specific_humidity * air_mass_flow
        return vapor_mass_flow

    def calculate_wet_inlet_mass_flows(self):
        """
        Calculate the wet inlet mass flow based on the dry outlet mass flow,
        the reacted O2 mass flow, and the relative humidity at the wet inlet.
        """
        dry_inlet_flows = self.calculate_dry_inlet_mass_flows()
        m_dot_air_dry_in = dry_inlet_flows["m_dot_air_dry_in"]

        # Adjust for reacted O2 at the wet inlet using self.o2_mass_flow_rate
        m_dot_air_wet_in = m_dot_air_dry_in - self.o2_mass_flow_rate

        x_wet_in = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure(
            self.wet_air_temperature_in_K, self.wet_air_rh_in) / (
                           self.wet_air_pressure_in_Pa - self.calculate_partial_pressure(
                       self.wet_air_temperature_in_K, self.wet_air_rh_in)
                   )

        m_dot_vap_wet_in = m_dot_air_wet_in * x_wet_in
        total_mass_flow_wet_in = m_dot_air_wet_in + m_dot_vap_wet_in

        return {
            "m_dot_air_wet_in": m_dot_air_wet_in,
            "m_dot_vap_wet_in": m_dot_vap_wet_in,
            "total_mass_flow_wet_in": total_mass_flow_wet_in
        }

    def calculate_wet_outlet_mass_flows(self):
        """
        Calculate the wet outlet mass flow based on the wet inlet mass flows and
        the water transfer mass flow.
        """
        wet_inlet_flows = self.calculate_wet_inlet_mass_flows()
        m_dot_air_wet_in = wet_inlet_flows["m_dot_air_wet_in"]
        m_dot_vap_wet_in = wet_inlet_flows["m_dot_vap_wet_in"]

        m_dot_water_trans = self.calculate_water_transfer()

        m_dot_vap_wet_out = m_dot_vap_wet_in - m_dot_water_trans
        m_dot_air_wet_out = m_dot_air_wet_in
        total_mass_flow_wet_out = m_dot_air_wet_out + m_dot_vap_wet_out

        return {
            "m_dot_air_wet_out": m_dot_air_wet_out,
            "m_dot_vap_wet_out": m_dot_vap_wet_out,
            "total_mass_flow_wet_out": total_mass_flow_wet_out
        }
    def calculate_efficiency(self):
        """
        Interpolate the efficiency based on the dry air mass flow rate in sLPM using the humidifier efficiency map.
        Clamps the interpolated efficiency to a maximum of 100 and a minimum of 0.

        Returns:
            float: Interpolated and clamped efficiency.
        """
        # Convert dry mass flow rate from kg/s to SLPM
        mass_flow_slpm = self.convert_kg_s_to_slpm(self.dry_air_mass_flow_kg_s)

        # Extract the flow rates and efficiencies for interpolation
        flow_rates = list(self.humidifier_efficiency_map.keys())
        efficiencies = list(self.humidifier_efficiency_map.values())

        # Interpolate efficiency based on the converted flow rate
        interpolator = interp1d(flow_rates, efficiencies, kind='linear', fill_value="extrapolate")
        efficiency = interpolator(mass_flow_slpm)

        # Clamp efficiency to be between 0 and 100
        efficiency = max(0, min(efficiency, 100))

        return efficiency

    def calculate_water_transfer(self):
        """
        Calculate the mass flow rate of water vapor transfer and efficiency.

        Returns:
            mass flow rate of water vapor transfer (kg/s)
        """
        # Calculate efficiency
        transfer_efficiency = self.calculate_efficiency() / 100

        # Get mass flows using the individual methods
        dry_inlet_mass_flows = self.calculate_dry_inlet_mass_flows()
        wet_inlet_mass_flows = self.calculate_wet_inlet_mass_flows()

        # Retrieve relevant mass flow rates
        m_vap_dry_in = dry_inlet_mass_flows["m_dot_vap_dry_in"]
        m_vap_wet_in = wet_inlet_mass_flows["m_dot_vap_wet_in"]

        # Calculate the mass flow rate of water vapor transfer
        m_dot_water_trans = transfer_efficiency * (m_vap_wet_in - m_vap_dry_in)

        return m_dot_water_trans

    def calculate_rh_dry_out(self):
        """
        Calculate the relative humidity at the dry outlet.

        Returns:
            float: Relative humidity at the dry outlet as a percentage.
        """
        # Calculate dry outlet mass flows
        dry_outlet_flows = self.calculate_dry_outlet_mass_flows()
        m_dot_air_dry_out = dry_outlet_flows["m_dot_air_dry_out"]
        m_dot_vap_dry_out = dry_outlet_flows["m_dot_vap_dry_out"]
        total_mass_flow_dry_out = dry_outlet_flows["total_mass_flow_dry_out"]

        # Calculate partial pressure of water vapor at the dry outlet using mass flows and total pressure
        partial_pressure_vap_dry_out = self.calculate_partial_pressure_with_mass_flows(
            total_mass_flow_dry_out, m_dot_vap_dry_out, self.dry_air_pressure_out_Pa
        )

        # Calculate the saturation pressure at the dry outlet temperature
        saturation_pressure_dry_out = self.calculate_saturation_pressure(self.dry_air_temperature_out_K)

        # Calculate relative humidity at the dry outlet
        rh_dry_out = (partial_pressure_vap_dry_out / saturation_pressure_dry_out) * 100  # in percentage

        return rh_dry_out


class Humidifier(MoistExchanger):
    def __init__(self, **kwargs):
        """
        Initialize the Humidifier class and pass any relevant arguments to the parent class.
        """
        super().__init__(**kwargs)



