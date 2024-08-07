# -*- coding: utf-8 -*-
"""
Created on Wed Aug  7 11:24:48 2024

@author: wenzel.gassner
"""

import CoolProp.CoolProp as CP
from basic_physics import icao_atmosphere

class Compressor:
    def __init__(self, params_physics, isentropic_efficiency=0.75, electric_efficiency=0.95,
                 air_mass_flow_kg_s=1, pressure_out_Pa=1e5,flight_level_100ft=50):

        self.isentropic_efficiency = isentropic_efficiency
        self.electric_efficiency = electric_efficiency
        self.params_physics = params_physics
        self.air_mass_flow_kg_s = air_mass_flow_kg_s
        self.pressure_out_Pa = pressure_out_Pa
        self.flight_level_100ft = flight_level_100ft

    def calculate_power(self):
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
        self.temperature_in_K, self.pressure_in_Pa = icao_atmosphere(self.flight_level_100ft)

        # Calculate the pressure ratio
        pressure_ratio = self.pressure_out_Pa / self.pressure_in_Pa

        # Calculate the specific work input to the compressor (isentropic work)
        specific_compressor_work_isentropic = CP.PropsSI('C', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Air') * self.temperature_in_K * \
            ((pressure_ratio ** ((self.params_physics.specific_heat_ratio - 1) / self.params_physics.specific_heat_ratio)) - 1)
        
        # Adjust for isentropic efficiency
        specific_compressor_work = specific_compressor_work_isentropic / self.isentropic_efficiency

        # Multiply by the flow rate to get the total power requirement
        compressor_power_W = specific_compressor_work * self.air_mass_flow_kg_s

        # Calculate the electrical power required
        compressor_el_power_W = compressor_power_W / self.electric_efficiency

        return compressor_el_power_W
    
# %% Example usage:
import parameters   
params_physics = parameters.Physical_Parameters() 
C1 = Compressor(params_physics, isentropic_efficiency=0.75, electric_efficiency=0.95,
             air_mass_flow_kg_s=0.01, pressure_out_Pa=1e5,flight_level_100ft=50)

#electrical power
power_el = C1.calculate_power()