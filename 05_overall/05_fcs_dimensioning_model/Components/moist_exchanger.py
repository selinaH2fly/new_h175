import CoolProp.HumidAirProp as HAP
import numpy as np
from cathode_model_run import PhysicalParameters  # TODO change to cathode_model_run?


class MoistExchanger:
    def __init__(self, dry_air_mass_flow_kg_s=0.086, wet_air_mass_flow_kg_s=0.026,
                 dry_air_temperature_in_K=346.1, dry_air_pressure_in_Pa=21700, dry_air_rh_in=0.05,
                 dry_air_temperature_out_K=337.8, dry_air_pressure_out_Pa=211000, dry_air_rh_out=0.88,
                 wet_air_temperature_in_K=348, wet_air_pressure_in_Pa=190000, wet_air_rh_in=1.0,
                 wet_air_pressure_out_Pa=190000, humidifier_map=None):
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

        # Use the constants from Physical_Parameters
        params_physics = PhysicalParameters()
        self.R_Air = params_physics.R_air
        self.R_Vap = params_physics.R_water_vapor
        self.P_std = params_physics.P_std
        self.T_std = params_physics.T_std
        self.M_air = params_physics.M_air
        self.R = params_physics.R

        # Set the humidifier map option
        self.humidifier_efficiency_map = humidifier_map




    def convert_slpm_to_kg_s(self, slpm):
        """
        Convert SLPM to kg/s using the standard conditions.
	 """
        P_std = 101325  # Pa (Standard Pressure)
        T_std = 273.15  # K (Standard Temperature)
        M_air = 0.0289647  # kg/mol (Molar mass of air)
        R = 8.314  # J/(mol·K) (Gas constant)

        # Conversion formula: (SLPM to kg/s)
        return slpm / 60 * (P_std * M_air) / (R * T_std)

    def calculate_specific_heat(self, t, p, rh) -> float:
        return HAP.HAPropsSI('C', 'T', t, 'P', p, 'R', rh)

    def calculate_density(self, t, p, rh):
        density = HAP.HAPropsSI('D', 'T', t, 'P', p, 'R', rh)
        return density

    def calculate_dewpoint(self, t, p, rh):
        dew_point_temp = HAP.HAPropsSI('D', 'T', t, 'P', p, 'R', rh)
        return dew_point_temp

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

    def calculate_mass_flows(self):
        """
        Calculate the mass flows of air and vapor for both dry and wet air at inlet and outlet.

        Returns:
            Dictionary of mass flow rates.
        """

        # Calculate dry inlet vapor and air mass flows
        x_dry_in = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure(
            self.dry_air_temperature_in_K, self.dry_air_rh_in) / (
                           self.dry_air_pressure_in_Pa - self.calculate_partial_pressure(
                       self.dry_air_temperature_in_K, self.dry_air_rh_in)
                   )

        m_dot_air_dry_in = self.dry_air_mass_flow_kg_s / (1 + x_dry_in)
        m_dot_vap_dry_in = self.dry_air_mass_flow_kg_s - m_dot_air_dry_in

        # Calculate dry outlet vapor and air mass flows
        x_dry_out = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure(
            self.dry_air_temperature_out_K, self.dry_air_rh_out) / (
                            self.dry_air_pressure_out_Pa - self.calculate_partial_pressure(
                        self.dry_air_temperature_out_K, self.dry_air_rh_out)
                    )

        m_dot_air_dry_out = m_dot_air_dry_in  # Air mass flow remains the same
        m_dot_vap_dry_out = x_dry_out * m_dot_air_dry_out
        m_dot_dry_out = m_dot_vap_dry_out + m_dot_air_dry_out

        # Calculate wet inlet vapor and air mass flows
        x_wet_in = (self.R_Air / self.R_Vap) * self.calculate_partial_pressure(
            self.wet_air_temperature_in_K, self.wet_air_rh_in) / (
                           self.wet_air_pressure_in_Pa - self.calculate_partial_pressure(
                       self.wet_air_temperature_in_K, self.wet_air_rh_in)
                   )

        m_dot_air_wet_in = self.wet_air_mass_flow_kg_s / (1 + x_wet_in)
        m_dot_vap_wet_in = self.wet_air_mass_flow_kg_s - m_dot_air_wet_in

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


    def calculate_efficiency(self):
        """
        Calculate the efficiency of water transfer. Use the humidifier efficiency map if provided.

        Returns:
            Efficiency of water transfer.
        """
        # Get mass flows from calculate_mass_flows
        flow_data = self.calculate_mass_flows()

        # Retrieve relevant mass flow rates from the flow_data dictionary
        m_vap_dry_out = flow_data["m_dot_vap_dry_out"]
        m_vap_wet_in = flow_data["m_dot_vap_wet_in"]

        if self.humidifier_efficiency_map is not None:
            # Convert SLPM values in the map to kg/s for interpolation
            slpm_values = self.humidifier_efficiency_map['mass_flow']
            mass_flow_kg_s_values = [self.convert_slpm_to_kg_s(slpm) for slpm in slpm_values]

            # Interpolate efficiency using the dry air mass flow and the converted kg/s values
            efficiency = np.interp(self.dry_air_mass_flow_kg_s, mass_flow_kg_s_values,
                                   self.humidifier_efficiency_map['efficiency'])
        else:
            # Calculate efficiency as in the original approach
            efficiency = m_vap_dry_out / m_vap_wet_in if m_vap_wet_in != 0 else 0

        return efficiency

    def calculate_water_transfer(self):
        """
        Calculate the mass flow rate of water vapor transfer and efficiency using internal attributes.

        Returns:
            mass flow rate of water vapor (kg/s), efficiency
        """
        # Calculate efficiency
        water_transfer_efficiency = self.calculate_efficiency()

        # Get mass flows from calculate_mass_flows
        flow_data = self.calculate_mass_flows()

        # Retrieve relevant mass flow rates from the flow_data dictionary
        m_vap_dry_in = flow_data["m_dot_vap_dry_in"]
        m_vap_wet_in = flow_data["m_dot_vap_wet_in"]

        # Calculate the mass flow rate of water vapor transfer
        m_dot_water_trans = water_transfer_efficiency * m_vap_wet_in - m_vap_dry_in

        return m_dot_water_trans, water_transfer_efficiency

    def calculate_rh_dry_out(self):
        """
        Calculate the relative humidity (RH) at the outlet (dry air out) using outlet temperature,
        outlet pressure, and mass flow rates.

        Returns:
            float: Relative humidity at the dry air outlet.
        """
        # Get the flow data
        flow_data = self.calculate_mass_flows()

        # Retrieve relevant mass flow rates
        m_dot_air_dry_out = flow_data["m_dot_air_dry_out"]
        m_dot_vap_dry_out = flow_data["m_dot_vap_dry_out"]

        # Calculate the outlet saturation pressure using the dry air outlet temperature
        p_sat_out = self.calculate_saturation_pressure(self.dry_air_temperature_out_K)

        # Calculate the partial pressure of water vapor at the outlet
        # The partial pressure can be calculated as (mass flow of vapor) / (mass flow of air + mass flow of vapor) * outlet pressure
        p_vap_dry_out = (m_dot_vap_dry_out / (m_dot_air_dry_out + m_dot_vap_dry_out)) * self.dry_air_pressure_out_Pa

        # Calculate relative humidity (RH)
        rh_dry_out = p_vap_dry_out / p_sat_out if p_sat_out != 0 else 0

        return rh_dry_out

class Humidifier(MoistExchanger):
    def __init__(self, **kwargs):
        """
        Initialize the Humidifier class and pass any relevant arguments to the parent class.
        """
        super().__init__(**kwargs)


# %% Example usage of the code:
# Create an instance of Humidifier
humidifier = Humidifier(
    dry_air_mass_flow_kg_s=0.045,
    wet_air_mass_flow_kg_s=0.045,
    dry_air_temperature_in_K=339.6,
    dry_air_pressure_in_Pa=145000,
    dry_air_rh_in=0.08,
    dry_air_temperature_out_K=337.3,
    dry_air_pressure_out_Pa=141000,
    wet_air_temperature_in_K=353.2,
    wet_air_pressure_in_Pa=210000,
    wet_air_rh_in=0.99,
    wet_air_pressure_out_Pa=196000
)

# Calculate RH at dry air outlet
rh_dry_out = humidifier.calculate_rh_dry_out()
print(f"Calculated RH dry out: {rh_dry_out * 100:.2f}%")
