import CoolProp.HumidAirProp as HAP
import numpy as np
from scipy.interpolate import interp1d
from cathode_model_run import PhysicalParameters, HumidifierParameters

class MoistExchanger:
    def __init__(self, dry_air_mass_flow_kg_s=0.086, wet_air_mass_flow_kg_s=0.026,
                 dry_air_temperature_in_K=346.1, dry_air_pressure_in_Pa=21700, dry_air_rh_in=0.05,
                 dry_air_temperature_out_K=337.8, dry_air_pressure_out_Pa=211000, dry_air_rh_out=0.88,
                 wet_air_temperature_in_K=348, wet_air_pressure_in_Pa=190000, wet_air_rh_in=1.0,
                 wet_air_pressure_out_Pa=190000, humidifier_map=None):

        # Assign humidifier_map to an instance attribute
        self.humidifier_map = humidifier_map  # Now this attribute can be accessed throughout the class

        # Dry air parameters
        self.dry_air_mass_flow_kg_s = dry_air_mass_flow_kg_s
        self.dry_air_temperature_in_K = dry_air_temperature_in_K
        self.dry_air_pressure_in_Pa = dry_air_pressure_in_Pa
        self.dry_air_rh_in = dry_air_rh_in
        self.dry_air_temperature_out_K = dry_air_temperature_out_K
        self.dry_air_pressure_out_Pa = dry_air_pressure_out_Pa
        self.dry_air_rh_out = dry_air_rh_out

        # Wet air parameters
        self.wet_air_mass_flow_kg_s = wet_air_mass_flow_kg_s
        self.wet_air_temperature_in_K = wet_air_temperature_in_K
        self.wet_air_pressure_in_Pa = wet_air_pressure_in_Pa
        self.wet_air_rh_in = wet_air_rh_in
        self.wet_air_pressure_out_Pa = wet_air_pressure_out_Pa

        # Use the constants from PhysicalParameters
        params_physics = PhysicalParameters()
        self.R_Air = params_physics.R_air
        self.R_Vap = params_physics.R_water_vapor
        self.P_std = params_physics.P_std
        self.T_std = params_physics.T_std
        self.M_air = params_physics.M_air
        self.R = params_physics.R

        # Retrieve the humidifier maps from HumidifierParameters
        humidifier_params = HumidifierParameters()
        self.humidifier_efficiency_map = humidifier_params.humidifier_efficiency_map
        self.pressure_drop_map = humidifier_params.pressure_drop_map

    def calculate_specific_heat(self, t, p, rh) -> float:
        return HAP.HAPropsSI('C', 'T', t, 'P', p, 'R', rh)

    def calculate_density(self, t, p, rh):
        density = HAP.HAPropsSI('D', 'T', t, 'P', p, 'R', rh)
        return density

    def calculate_dewpoint(self, t, p, rh):
        dew_point_temp = HAP.HAPropsSI('D', 'T', t, 'P', p, 'R', rh)
        return dew_point_temp

    def calculate_reacted_o2_mass_flow(self,current_A, cellcount):
        """
        Calculate the reacted O2 mass flow rate in a fuel cell stack.

        Parameters:
        current_A, cellcount=275: Current per cell in amperes (A).
        cellcount: Number of cells in the stack.

        Returns:
        float: Reacted O2 mass flow rate in kg/s.
        """
        #TODO transfer to basic physics?
        #TODO grab constants from coolprop

        M_O2 = 0.032  # Molar mass of O2 in kg/mol
        F = 96485  # Faraday's constant in C/mol
        efficiency_factor = 0.23  # Efficiency factor

        # Calculate reacted O2 mass flow rate
        o2_mass_flow_rate = (current_A * cellcount * M_O2) / (4 * F * efficiency_factor)

        return o2_mass_flow_rate

    def convert_kg_s_to_slpm(self, kg_s):
        """
        Convert kg/s to SLPM using the density-based method.
        """
        density_std = 1.225  # kg/m³, standard density of air at 0°C and 101325 Pa
        return (kg_s * 1000 / density_std) * 60


    def interpolate_dry_pressure_drop(self):
        # Convert dry mass flow rate from kg/s to SLPM
        mass_flow_slpm = self.convert_kg_s_to_slpm(self.dry_air_mass_flow_kg_s)

        # Extract flow rates and corresponding dry pressure drops
        flow_rates = list(self.pressure_drop_map.keys())
        dry_pressure_drops = [self.pressure_drop_map[flow]["dry_side"] for flow in flow_rates]

        # Interpolate the dry pressure drop
        interpolator = interp1d(flow_rates, dry_pressure_drops, kind='linear', fill_value="extrapolate")
        return interpolator(mass_flow_slpm)

    def interpolate_wet_pressure_drop(self):
        # Convert wet mass flow rate from kg/s to SLPM
        mass_flow_slpm = self.convert_kg_s_to_slpm(self.wet_air_mass_flow_kg_s)

        # Extract flow rates and corresponding wet pressure drops
        flow_rates = list(self.pressure_drop_map.keys())
        wet_pressure_drops = [self.pressure_drop_map[flow]["wet_side"] for flow in flow_rates]

        # Interpolate the wet pressure drop
        interpolator = interp1d(flow_rates, wet_pressure_drops, kind='linear', fill_value="extrapolate")
        return interpolator(mass_flow_slpm)

    @staticmethod
    def calculate_saturation_pressure(t):
        """
        Calculate the saturation pressure of water vapor at a given temperature.
        """
        A = 6.1094
        B = 17.625
        C = 243.04
        return A * np.exp((B * (t - 273.15)) / ((t - 273.15) + C)) * 100

    def calculate_humidity_ratio(self, t, p, rh):
        """
        Calculate the humidity ratio for a given temperature, total pressure, and relative humidity.

        Args:
            t (float): Temperature in Kelvin.
            p (float): Total pressure in Pascals.
            rh (float): Relative humidity as a fraction (0-1).

        Returns:
            float: Humidity ratio (dimensionless).
        """
        # Calculate the partial pressure of water vapor
        p_vap = self.calculate_partial_pressure_rh(t, rh)

        # Humidity ratio formula
        humidity_ratio = 0.622 * p_vap / (p - p_vap)

        return humidity_ratio

    def calculate_partial_pressure_rh(self, t, rh):
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
        p_vap_rh = p_sat * rh

        return p_vap_rh

    def calculate_partial_pressure_mdot(self, m_dot_vap, m_dot_air, p):
        """
        Calculate the partial pressure of water vapor based on mass flow rates of vapor and air.

        Args:
            m_dot_vap (float): Mass flow rate of water vapor.
            m_dot_air (float): Mass flow rate of dry air.
            p (float): Pressure of the air-vapor mixture at the outlet.

        Returns:
            float: Partial pressure of water vapor.
        """
        p_vap_mdot = (m_dot_vap / (m_dot_air + m_dot_vap)) * p

        return p_vap_mdot


    def calculate_rh_dry_out(self):
        """
        Calculate the relative humidity (RH) at the outlet (dry air out) using outlet temperature,
        outlet pressure, and mass flow rates.

        Returns:
            float: Relative humidity at the dry air outlet.
        """
        # Get dry outlet mass flows
        dry_outlet_flows = self.calculate_dry_outlet_mass_flows()
        m_dot_air_dry_out = dry_outlet_flows["m_dot_air_dry_out"]
        m_dot_vap_dry_out = dry_outlet_flows["m_dot_vap_dry_out"]

        # Calculate the outlet saturation pressure using the dry air outlet temperature
        p_sat_out = self.calculate_saturation_pressure(self.dry_air_temperature_out_K)

        # Use the new method to calculate the partial pressure of water vapor at the outlet
        p_vap_dry_out = self.calculate_partial_pressure_mdot(m_dot_vap_dry_out, m_dot_air_dry_out,
                                                             self.dry_air_pressure_out_Pa)

        # Calculate relative humidity (RH)
        relative_humidity_outlet = p_vap_dry_out / p_sat_out if p_sat_out != 0 else 0

        return relative_humidity_outlet

    def calculate_dry_inlet_mass_flows(self):
        """
        Calculate the mass flows of air and vapor for the dry air at the inlet.

        Returns:
            Dictionary of dry inlet air and vapor mass flow rates.
        """
        # Calculate humidity ratio for dry inlet
        x_dry_in = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure_rh(
            self.dry_air_temperature_in_K, self.dry_air_rh_in) / (
                           self.dry_air_pressure_in_Pa - self.calculate_partial_pressure_rh(
                       self.dry_air_temperature_in_K, self.dry_air_rh_in)
                   )

        # Calculate dry inlet air and vapor mass flows
        m_dot_air_dry_in = self.dry_air_mass_flow_kg_s / (1 + x_dry_in)
        m_dot_vap_dry_in = self.dry_air_mass_flow_kg_s - m_dot_air_dry_in

        return {
            "m_dot_air_dry_in": m_dot_air_dry_in,
            "m_dot_vap_dry_in": m_dot_vap_dry_in
        }
    def calculate_dry_outlet_mass_flows(self):
        """
        Calculate the mass flows of air and vapor for the dry air at the outlet, considering
        the water transfer rate.

        Returns:
            Dictionary of dry outlet air and vapor mass flow rates.
        """

        # Get dry inlet mass flows
        dry_inlet_flows = self.calculate_dry_inlet_mass_flows()
        m_dot_air_dry_out = dry_inlet_flows["m_dot_air_dry_in"]  # m_dot_air_dry_out = m_dot_air_dry_in
        m_dot_vap_dry_in = dry_inlet_flows["m_dot_vap_dry_in"]

        # Calculate the total water transfer rate
        m_dot_water_trans, _ = self.calculate_water_transfer()  # water_transfer_efficiency not used directly here

        # Calculate vapor mass flow at the dry air outlet
        m_dot_vap_dry_out = m_dot_vap_dry_in + m_dot_water_trans

        # Total mass flow at the dry outlet
        m_dot_dry_out = m_dot_air_dry_out + m_dot_vap_dry_out

        return {
            "m_dot_air_dry_out": m_dot_air_dry_out,
            "m_dot_vap_dry_out": m_dot_vap_dry_out,
            "m_dot_dry_out": m_dot_dry_out
        }
    def calculate_wet_inlet_mass_flow(self, o2_mass_flow_rate):
        """
        Calculate the wet inlet mass flow based on the dry outlet mass flow,
        the reacted O2 mass flow, and the relative humidity at the wet inlet.

        Parameters:
            o2_mass_flow_rate (float): The mass flow rate of reacted O2 (kg/s).

        Returns:
            dict: Dictionary containing the wet inlet air and vapor mass flow rates.
        """
        # Calculate the dry air mass flow at the outlet
        dry_outlet_flows = self.calculate_dry_outlet_mass_flows()
        m_dot_air_dry_out = dry_outlet_flows["m_dot_air_dry_out"]
        m_dot_vap_dry_out = dry_outlet_flows["m_dot_vap_dry_out"]

        # Adjust for reacted O2 at the wet inlet
        m_dot_air_wet_in = m_dot_air_dry_out - o2_mass_flow_rate  # Subtract reacted O2 for the initial dry air flow

        # Calculate humidity ratio at the wet inlet
        x_wet_in = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure_rh(
            self.wet_air_temperature_in_K, self.wet_air_rh_in
        ) / (
            self.wet_air_pressure_in_Pa - self.calculate_partial_pressure_rh(
                self.wet_air_temperature_in_K, self.wet_air_rh_in
            )
        )

        # Calculate wet inlet vapor mass flow
        m_dot_vap_wet_in = x_wet_in * m_dot_air_wet_in  # Vapor flow based on humidity ratio

        # Total wet inlet mass flow
        m_dot_wet_in = m_dot_air_wet_in + m_dot_vap_wet_in

        return {
            "m_dot_air_wet_in": m_dot_air_wet_in,
            "m_dot_vap_wet_in": m_dot_vap_wet_in,
            "m_dot_wet_in": m_dot_wet_in
        }

    def calculate_wet_outlet_mass_flows(self):
        """
        Calculate the mass flows of air and vapor for the wet air at the outlet.

        Returns:
            Dictionary of wet outlet air and vapor mass flow rates.
        """
        # Get wet inlet mass flows first
        wet_inlet_flows = self.calculate_wet_inlet_mass_flows()
        m_dot_air_wet_in = wet_inlet_flows["m_dot_air_wet_in"]
        m_dot_vap_wet_in = wet_inlet_flows["m_dot_vap_wet_in"]

        # Calculate dry inlet vapor flow for wet outlet calculation
        dry_inlet_flows = self.calculate_dry_inlet_mass_flows()
        m_dot_vap_dry_in = dry_inlet_flows["m_dot_vap_dry_in"]

        # Wet outlet air mass flow remains the same
        m_dot_air_wet_out = m_dot_air_wet_in
        m_dot_vap_wet_out = m_dot_vap_wet_in - m_dot_vap_dry_in
        m_dot_wet_out = m_dot_air_wet_out + m_dot_vap_wet_out

        return {
            "m_dot_air_wet_out": m_dot_air_wet_out,
            "m_dot_vap_wet_out": m_dot_vap_wet_out,
            "m_dot_wet_out": m_dot_wet_out
        }

    def calculate_efficiency(self):
        """
        Calculate the efficiency of water transfer. Use the humidifier efficiency map if provided.
        """
        # Get mass flows from the separate methods
        dry_outlet_mass_flows = self.calculate_dry_outlet_mass_flows()
        wet_inlet_mass_flows = self.calculate_wet_inlet_mass_flows()
        m_vap_dry_out = dry_outlet_mass_flows["m_dot_vap_dry_out"]
        m_vap_wet_in = wet_inlet_mass_flows["m_dot_vap_wet_in"]

        if self.humidifier_map is not None:
            # Convert dry mass flow rate from kg/s to SLPM
            mass_flow_slpm = self.convert_kg_s_to_slpm(self.dry_air_mass_flow_kg_s)

            # Extract SLPM values and efficiency percentages from the efficiency map
            slpm_values = list(self.humidifier_efficiency_map.keys())
            efficiency_values = [eff / 100 for eff in self.humidifier_efficiency_map.values()]  # Convert to fractions

            # Interpolate efficiency based on SLPM mass flow
            calculated_efficiency = np.interp(mass_flow_slpm, slpm_values, efficiency_values)
        else:
            # Calculate efficiency without map
            calculated_efficiency = m_vap_dry_out / m_vap_wet_in if m_vap_wet_in != 0 else 0

        return calculated_efficiency

    def calculate_water_transfer(self):
        """
        Calculate the mass flow rate of water vapor transfer using humidity ratios.

        Returns:
            tuple: mass flow rate of water vapor transfer (kg/s), water transfer efficiency
        """
        # Calculate humidity ratios at the wet air inlet and dry air inlet/outlet
        humidity_ratio_wet_in = self.calculate_humidity_ratio(
            self.wet_air_temperature_in_K, self.wet_air_pressure_in_Pa, self.wet_air_rh_in
        )
        humidity_ratio_dry_in = self.calculate_humidity_ratio(
            self.dry_air_temperature_in_K, self.dry_air_pressure_in_Pa, self.dry_air_rh_in
        )

        # Determine water vapor transfer based on the difference in humidity ratios and dry air mass flow
        m_dot_water_trans = self.dry_air_mass_flow_kg_s * (humidity_ratio_wet_in - humidity_ratio_dry_in)

        # Calculate water transfer efficiency if using the humidifier efficiency map
        water_transfer_efficiency = self.calculate_efficiency()

        return m_dot_water_trans, water_transfer_efficiency

class Humidifier(MoistExchanger):
    def __init__(self, **kwargs):
        """
        Initialize the Humidifier class and pass any relevant arguments to the parent class.
        """
        super().__init__(**kwargs)

# Create an instance of the Humidifier (MoistExchanger subclass)
humidifier = Humidifier(
    dry_air_mass_flow_kg_s=0.045,
    wet_air_mass_flow_kg_s=0.030,
    dry_air_temperature_in_K=339.6,
    dry_air_pressure_in_Pa=145000,
    dry_air_rh_in=0.1,
    dry_air_temperature_out_K=337.3,
    dry_air_pressure_out_Pa=141000,
    wet_air_temperature_in_K=353.2,
    wet_air_pressure_in_Pa=210000,
    wet_air_rh_in=0.99,
    wet_air_pressure_out_Pa=196000,
    humidifier_map=True
)

# Calculate humidity ratio at dry air inlet
humidity_ratio_dry_in = humidifier.calculate_humidity_ratio(
    humidifier.dry_air_temperature_in_K, humidifier.dry_air_pressure_in_Pa, humidifier.dry_air_rh_in
)
print(f"Humidity Ratio at Dry Air Inlet: {humidity_ratio_dry_in:.4f}")

# Calculate humidity ratio at wet air inlet
humidity_ratio_wet_in = humidifier.calculate_humidity_ratio(
    humidifier.wet_air_temperature_in_K, humidifier.wet_air_pressure_in_Pa, humidifier.wet_air_rh_in
)
print(f"Humidity Ratio at Wet Air Inlet: {humidity_ratio_wet_in:.4f}")

o2_mass_flow = humidifier.calculate_reacted_o2_mass_flow(600, 455)
print(f"Reacted O2 mass flow rate: {o2_mass_flow:.6f} kg/s")
# calculate water transfer
m_dot_water_trans, water_transfer_efficiency = humidifier.calculate_water_transfer()
print(f"Mass Flow of Water transfer: {m_dot_water_trans:.2f} kg/s")

# Example parameters
current_A = 600  # Current per cell in A
cellcount = 455  # Number of cells in the stack

