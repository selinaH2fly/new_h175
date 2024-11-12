import CoolProp.HumidAirProp as HAP
import numpy as np
from CoolProp.CoolProp import HAPropsSI
from scipy.interpolate import interp1d
from cathode_model_run import PhysicalParameters, HumidifierParameters


class MoistExchanger:
    def __init__(self, dry_air_mass_flow_kg_s=0.166, wet_air_mass_flow_kg_s=0.176,
                 dry_air_temperature_in_K=399, dry_air_pressure_in_Pa=314878, dry_air_rh_in=0.30,
                 dry_air_temperature_out_K=402, dry_air_pressure_out_Pa=300000, dry_air_rh_out=0.88,
                 wet_air_temperature_in_K=355, wet_air_pressure_in_Pa=270000, wet_air_rh_in=0.99,
                 wet_air_pressure_out_Pa=253112, wet_air_temperature_out_K=350,humidifier_map=None, o2_mass_flow_rate=0.0052):

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
        self.wet_air_temperature_out_K = wet_air_temperature_out_K
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
        density_std = 1.185  # kg/m³, standard density of air at 20°C and 101325 Pa

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
            t: Temperature in Kelvin.
            rh: Relative humidity as a fraction (0-1).

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
        P_vapor = self.calculate_partial_pressure(self.dry_air_temperature_in_K, self.dry_air_rh_in)

        x_dry_in = (self.R_Air / self.R_Vap) * (P_vapor / (self.dry_air_pressure_in_Pa - P_vapor))

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
        m_dot_air_vap_in = dry_inlet_flows["m_dot_vap_dry_in"]

        wet_inlet_flows = self.calculate_wet_inlet_mass_flows()
        m_dot_vap_wet_in = wet_inlet_flows["m_dot_vap_wet_in"]

        efficiency = self.get_efficiency() / 100

        m_dot_water_trans = self.calculate_water_transfer_rate()

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
        specific_humidity = HAPropsSI('HumRat', 'T', t, 'P', p, 'RH', rh)

        # Calculate the mass flow rate of water vapor
        vapor_mass_flow = specific_humidity * air_mass_flow
        return vapor_mass_flow

    def calculate_wet_inlet_mass_flows(self):
        """
        Calculate the wet inlet mass flow based on the dry outlet mass flow,
        the reacted O2 mass flow, and the relative humidity at the wet inlet
        (99% RH).
        """
        # Dry side inlet mass flows (from dry outlet flows)
        dry_inlet_flows = self.calculate_dry_inlet_mass_flows()
        m_dot_air_dry_in = dry_inlet_flows["m_dot_air_dry_in"]

        # Adjust for depleted O2 at the wet inlet
        m_dot_air_wet_in = m_dot_air_dry_in - self.o2_mass_flow_rate

        # Target partial pressure of vapor for 99% RH at the wet inlet
        P_vapor = self.calculate_partial_pressure(self.wet_air_temperature_in_K, 0.99)

        # Calculate partial pressure of dry air
        P_air_wet = self.wet_air_pressure_in_Pa - P_vapor

        # Calculate specific humidity (vapor mass per unit dry air mass) at wet inlet
        specific_humidity_wet_in = 0.622 * (P_vapor / P_air_wet)

        # Calculate vapor mass flow at 99% RH
        m_dot_vap_wet_in = m_dot_air_wet_in * specific_humidity_wet_in

        # Calculate the total wet inlet mass flow
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

        m_dot_water_trans = self.calculate_water_transfer_rate()

        m_dot_vap_wet_out = m_dot_vap_wet_in - m_dot_water_trans
        m_dot_air_wet_out = m_dot_air_wet_in
        total_mass_flow_wet_out = m_dot_air_wet_out + m_dot_vap_wet_out

        return {
            "m_dot_air_wet_out": m_dot_air_wet_out,
            "m_dot_vap_wet_out": m_dot_vap_wet_out,
            "total_mass_flow_wet_out": total_mass_flow_wet_out
        }
    def get_efficiency(self):
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

    def calculate_water_transfer_rate(self):
        """
        Calculate the water transfer rate from the wet side to the dry side in a humidifier.

        Returns:
        - water_transfer_rate: Water transfer rate from wet side to dry side (kg/s)
        """
        efficiency = self.get_efficiency() / 100

        dry_inlet_flows = self.calculate_dry_inlet_mass_flows()
        m_dot_air_dry_in = dry_inlet_flows["m_dot_air_dry_in"]
        m_dot_vap_dry_in = dry_inlet_flows["m_dot_vap_dry_in"]


        wet_inlet_flows = self.calculate_wet_inlet_mass_flows()
        m_dot_air_wet_in = wet_inlet_flows["m_dot_air_wet_in"]
        m_dot_vap_wet_in = wet_inlet_flows["m_dot_vap_wet_in"]


        # Calculate partial pressures of water vapor
        P_vapor_dry = self.calculate_partial_pressure(self.dry_air_temperature_in_K, self.dry_air_rh_in)
        P_vapor_wet = self.calculate_partial_pressure(self.wet_air_temperature_in_K, self.wet_air_rh_in)

        # Calculate specific humidities on dry and wet sides
        Y_dry_in = 0.622 * P_vapor_dry / (self.dry_air_pressure_in_Pa - P_vapor_dry)
        Y_wet_in = 0.622 * P_vapor_wet / (self.wet_air_pressure_in_Pa - P_vapor_wet)

        # Calculate the water transfer rate
        water_transfer_rate = efficiency * (m_dot_air_wet_in * Y_wet_in - m_dot_air_dry_in * Y_dry_in)
        m_dot_water_trans = (efficiency / 100) * (m_dot_vap_wet_in - m_dot_vap_dry_in)
       # print(f"m_dot_water_trans: {m_dot_water_trans:.2f} ")
        return m_dot_water_trans

    def calculate_target_vapor_transfer(self, t, target_rh):
        """
        Calculate the target vapor transfer rate required to achieve a specified RH at a given
        temperature and pressure.

        Parameters:
        - target_rh: Target relative humidity as a fraction (e.g., 0.50 for 50% RH)

        Returns:
        - target_vapor_transfer_kg_s: Required vapor transfer rate in kg/s to achieve the target RH
        """
        # Calculate the partial pressure of water vapor for the target RH
        p_vapor_target = self.calculate_partial_pressure(t,target_rh)

        # Calculate the required vapor mass flow using the ideal gas law relationship
        target_vapor_transfer_kg_s = (p_vapor_target * self.dry_air_mass_flow_kg_s * self.R_Air) / \
                                     (self.dry_air_pressure_out_Pa * self.R_Vap + p_vapor_target * self.R_Air)

        return target_vapor_transfer_kg_s

    def calculate_vapor_transfer(self, target_vapor_transfer_kg_s):
        """
        Calculate the necessary dry air mass flow rate through the humidifier
        to achieve a target vapor transfer rate, based on the efficiency map.

        Parameters:
        - target_vapor_transfer_kg_s: Target vapor transfer rate in kg/s.

        Returns:
        - dry_air_mass_flow_g_s: Adjusted dry air mass flow rate in g/s to meet target vapor transfer.
        - interpolated efficiency in percentage.
        """
        # Calculate wet inlet vapor mass flow
        wet_inlet_flows = self.calculate_wet_inlet_mass_flows()
        m_dot_vap_wet_in_kg_s = wet_inlet_flows["m_dot_vap_wet_in"]

        # Initialize dry air mass flow estimate within a reasonable range
        dry_air_mass_flow_kg_s = max(0.01, min(self.dry_air_mass_flow_kg_s, 0.5))  # Initial guess
        tolerance = 0.00001  # kg/s tolerance for convergence
        efficiency = 0  # Initialize efficiency to ensure it is defined

        for _ in range(100):  # Maximum 100 iterations for convergence
            # Calculate required efficiency based on the target vapor transfer
            required_efficiency = target_vapor_transfer_kg_s / m_dot_vap_wet_in_kg_s

            # Convert current dry air mass flow to SLPM for efficiency map interpolation
            sLPM = self.convert_kg_s_to_slpm(dry_air_mass_flow_kg_s)

            # Interpolate efficiency from the map, clamping it between 0 and 100%
            flow_rates = list(self.humidifier_efficiency_map.keys())
            efficiencies = list(self.humidifier_efficiency_map.values())
            interpolator = interp1d(flow_rates, efficiencies, kind='linear', fill_value="extrapolate")
            efficiency = max(0, min(interpolator(sLPM), 100)) / 100  # Convert to fraction

            # Calculate the actual vapor transfer rate based on the interpolated efficiency
            vapor_transfer_actual_kg_s = dry_air_mass_flow_kg_s * efficiency

            # Check if the actual vapor transfer is within the target tolerance
            if abs(vapor_transfer_actual_kg_s - target_vapor_transfer_kg_s) < tolerance:
                break

            # Adjust dry air mass flow estimate within bounds
            adjustment_factor = target_vapor_transfer_kg_s / max(vapor_transfer_actual_kg_s, 0.0001)
            dry_air_mass_flow_kg_s *= adjustment_factor
            dry_air_mass_flow_kg_s = max(0.01, min(dry_air_mass_flow_kg_s, 0.5))  # Limit to avoid divergence

        # Convert final dry air mass flow to g/s
        dry_air_mass_flow_g_s = dry_air_mass_flow_kg_s * 1000
        return dry_air_mass_flow_kg_s, efficiency * 100  # Return efficiency in percentage

    def check_condensation(self):
        """
        Check if condensation occurs in the humidifier.

        Returns:
        - dict: A dictionary indicating if condensation has occurred at the dry and wet outlets.
        """
        # Calculate partial pressure and saturation pressure at the dry outlet
        p_vapor_dry_out = self.calculate_partial_pressure(self.dry_air_temperature_out_K,
                                                          self.calculate_relative_humidity_outlet_dry())
        p_sat_dry_out = self.calculate_saturation_pressure(self.dry_air_temperature_out_K)
        condensation_dry_out = p_vapor_dry_out > p_sat_dry_out

        # Calculate partial pressure and saturation pressure at the wet outlet
        p_vapor_wet_out = self.calculate_partial_pressure(self.wet_air_temperature_out_K,
                                                          self.calculate_relative_humidity_outlet_wet())
        p_sat_wet_out = self.calculate_saturation_pressure(self.wet_air_temperature_out_K)
        condensation_wet_out = p_vapor_wet_out > p_sat_wet_out

        return {
            "condensation_dry_out": condensation_dry_out,
            "condensation_wet_out": condensation_wet_out
        }

    def calculate_relative_humidity_outlet_dry(self):
        """
        Calculate the relative humidity at the dry outlet of a humidifier.

        Returns:
        - RH_dry_out: Relative humidity at the dry outlet (as a decimal, e.g., 0.636 for 63.6%)
        """
        # Calculate dry outlet mass flows
        dry_outlet_flows = self.calculate_dry_outlet_mass_flows()
        m_dot_air_dry_out = dry_outlet_flows["m_dot_air_dry_out"]
        m_dot_vap_dry_out = dry_outlet_flows["m_dot_vap_dry_out"]
        m_dot_total_dry_out = dry_outlet_flows["total_mass_flow_dry_out"]

        # Calculate specific humidity at the dry outlet
        Y_dry_out = m_dot_vap_dry_out/ m_dot_air_dry_out

        # Calculate the partial pressure of water vapor at the dry outlet
        p_vapor_dry_out = Y_dry_out * self.dry_air_pressure_out_Pa / (0.622 + Y_dry_out)

        R_air = self.R_Air
        R_vapor = self.R_Vap

        # Calculate humidity ratio
        x_out = m_dot_vap_dry_out / (m_dot_total_dry_out - m_dot_vap_dry_out)
        partial_pressure_vapor = (x_out  * self.dry_air_pressure_out_Pa) / (x_out + (R_vapor / R_air))


        # Calculate the saturation vapor pressure at the dry outlet temperature
        p_sat_dry_out = self.calculate_saturation_pressure(self.dry_air_temperature_out_K)

        # Calculate relative humidity at the dry outlet
        RH_dry_out = p_vapor_dry_out / p_sat_dry_out

        return RH_dry_out

    def calculate_relative_humidity_outlet_wet(self):
        """
        Calculate the relative humidity at the wet outlet of a humidifier.

        Returns:
        - RH_wet_out: Relative humidity at the wet outlet (as a decimal, e.g., 0.636 for 63.6%)
        """
        # Calculate wet outlet mass flows
        wet_outlet_flows = self.calculate_wet_outlet_mass_flows()
        m_dot_air_wet_out = wet_outlet_flows["m_dot_air_wet_out"]
        m_dot_vap_wet_out = wet_outlet_flows["m_dot_vap_wet_out"]

        # Calculate specific humidity at the wet outlet
        Y_wet_out = m_dot_vap_wet_out / m_dot_air_wet_out

        # Calculate the partial pressure of water vapor at the wet outlet
        p_vapor_wet_out = Y_wet_out * self.wet_air_pressure_out_Pa / (0.622 + Y_wet_out)

        # Calculate the saturation vapor pressure at the wet outlet temperature
        p_sat_wet_out = self.calculate_saturation_pressure(self.wet_air_temperature_out_K)

        # Calculate relative humidity at the wet outlet
        RH_wet_out = p_vapor_wet_out / p_sat_wet_out

        return RH_wet_out


class Humidifier(MoistExchanger):
    def __init__(self, **kwargs):
        """
        Initialize the Humidifier class and pass any relevant arguments to the parent class.
        """
        super().__init__(**kwargs)


# # Initialize a Humidifier instance with default values
# humidifier = Humidifier(
#     dry_air_mass_flow_kg_s=0.166,
#     o2_mass_flow_rate=0.0052,
#     dry_air_temperature_in_K=399,
#     dry_air_rh_in=0.3,
#     dry_air_temperature_out_K=402,
#     dry_air_pressure_out_Pa=300000,
#     wet_air_temperature_in_K=355,
#     wet_air_pressure_in_Pa=270000,
#     wet_air_rh_in=0.99,
#     wet_air_temperature_out_K = 350,
#
# )
#
# # Proceed with final calculations based on the last state of `compressor`
# humidifier.dry_mass_flow_slpm = humidifier.convert_kg_s_to_slpm(humidifier.dry_air_mass_flow_kg_s)
# humidifier.wet_air_pressure_out_Pa = humidifier.wet_air_pressure_in_Pa - humidifier.interpolate_wet_pressure_drop()
# humidifier.dry_air_pressure_in_Pa = humidifier.dry_air_pressure_out_Pa + humidifier.interpolate_dry_pressure_drop()
#
# # Calculate efficiency of water transfer in the humidifier
# humidifier.efficiency = humidifier.get_efficiency()
#
# # Calculate the humidifier's dry and wet inlet mass flows
# humidifier.drymassin = humidifier.calculate_dry_inlet_mass_flows()
# humidifier.wetmassin = humidifier.calculate_wet_inlet_mass_flows()
#
# # Calculate water transfer rate and outlet mass flows in the humidifier
# humidifier.m_dot_water_trans = humidifier.calculate_water_transfer_rate()
# humidifier.drymassout = humidifier.calculate_dry_outlet_mass_flows()
# humidifier.wetmassout = humidifier.calculate_wet_outlet_mass_flows()
# humidifier.total_mass_flow_wet_out_kg_s = humidifier.wetmassout["total_mass_flow_wet_out"]
#
# # Calculate relative humidity at the humidifier's outlets
# humidifier.RH_dry_out = 100 * humidifier.calculate_relative_humidity_outlet_dry()
# humidifier.RH_wet_out = 100 * humidifier.calculate_relative_humidity_outlet_wet()
#
#
#print("Efficiency:", humidifier.get_efficiency())
# print("Water Transfer Rate:", humidifier.calculate_water_transfer_rate())
# # print("Condensation Check:", humidifier.check_condensation())
#
# print(f"Relative Humidity at Dry Outlet: {humidifier.RH_dry_out:.2f} %")
# print(f"Relative Humidity at Wet Outlet: {humidifier.RH_wet_out:.2f} %")
#
# print(f"dry air in: {humidifier.drymassin['m_dot_air_dry_in']:.4f} ")
# print(f"dry vap in : {humidifier.drymassin['m_dot_vap_dry_in']:.4f}")
#
# print(f"wet air in: {humidifier.wetmassin['m_dot_air_wet_in']:.4f} ")
# print(f"wet vap in : {humidifier.wetmassin['m_dot_vap_wet_in']:.4f}")
# print(f"wet total in : {humidifier.wetmassin['total_mass_flow_wet_in']:.4f}")
#
# print(f"dry air out : {humidifier.drymassout['m_dot_air_dry_out']:.4f} ")
# print(f"dry vap out : {humidifier.drymassout['m_dot_vap_dry_out']:.4f}")
# print(f"dry total out : {humidifier.drymassout['total_mass_flow_dry_out']:.4f}")