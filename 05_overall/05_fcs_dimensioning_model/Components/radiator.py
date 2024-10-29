#import numpy as np
from scipy.interpolate import UnivariateSpline
from parameters import Radiator_Parameters

class Radiator:
    """
    A class to model a liquid/air radiator
    """

    def __init__(self, coolant_flow_m3_s=0.0, nominal_pressure_drop_Pa=500*100, nominal_coolant_flow_m3_s=0.0, mass_by_power_kg_kW="Herve_Radiator_Model", thermal_power_W=1e-3):
        """
        Initialize the radiator with a given pressure drop and coolant flow rate.

        :param coolant_flow_m3_s: Coolant flow rate in [m3/s]
        :param nominal_pressure_drop_Pa: Nominal pressure drop across the radiator in [Pa]
        :param nominal_coolant_flow_m3_s: Coolant flow rate in [m3/s]
        """

        self.coolant_flow_m3_s = coolant_flow_m3_s
        self.nominal_pressure_drop_Pa = nominal_pressure_drop_Pa
        self.nominal_coolant_flow_m3_s = nominal_coolant_flow_m3_s
        # Set default for mass_by_power_kg_kW using Herve_Radiator_Model
        if mass_by_power_kg_kW == "Herve_Radiator_Model":
            radiator_params = Radiator_Parameters()  # Create an instance of Radiator_Parameters
            mass_by_power_kg_kW = radiator_params.mass_by_power_kg_kW#["Herve_Radiator_Model"]
            self.mass_by_power_kg_kW = mass_by_power_kg_kW
            
        self.thermal_power_W = thermal_power_W
        
        # Create an interpolation function using scipy's interp1d
        self.interpolation_function = UnivariateSpline(
            self.mass_by_power_kg_kW["Herve_Radiator_Model"]["T_stack_out"],
            self.mass_by_power_kg_kW["Herve_Radiator_Model"]["mass_by_power"],
            s=0,  # Smooth factor; adjust to prevent overfitting
            ext=0  # Set external values to 0 for extrapolated values
            )
        
    def calculate_pressure_drop(self)->float:
        """
        Calculate the pressure drop across the radiator for a given coolant flow rate.
        The "model" is a simple quadratic relationship between pressure drop and coolant flow rate.

        :return: Pressure drop across the radiator in [Pa]
        """

        pressure_drop_coefficient = self.nominal_pressure_drop_Pa / (self.nominal_coolant_flow_m3_s**2)
        pressure_drop_Pa = pressure_drop_coefficient * self.coolant_flow_m3_s**2

        return pressure_drop_Pa
    
    def get_mass_by_power(self, T_stack_out_degC):
            # Use the interpolation function to return the corresponding mass_by_power value
            mass_by_power_kg_kW = self.interpolation_function(T_stack_out_degC)
            self.mass_by_power_kg_kW = mass_by_power_kg_kW
            
            return mass_by_power_kg_kW
        
    def calculate_mass(self,T_stack_out_degC)->dict:
        """
        Calculate predicted mass of the radiator by utilizing the mass_by_power_kg_kW dict of the class and the thermal_power_W attribute.
        
        Returns:
        - result: A dictionary containing:
            - "mean": Radiator mass in kg based on the mean value of mass_by_power_kg_kW.
            

        """
        self.mass_by_power_kg_kW = self.get_mass_by_power(T_stack_out_degC)
        #print(self.thermal_power_W)
        radiator_mass_kg = self.mass_by_power_kg_kW * (self.thermal_power_W / 1000)
        return radiator_mass_kg
    

# %% Example Usage:

# radiator = Radiator(nominal_pressure_drop_Pa=0.3*1e5, nominal_coolant_flow_m3_s=300/(1000*60))

# radiator.coolant_flow_m3_s = 100/(1000*60)  # 100 l/min in m3/s
# pressure_drop_Pa = radiator.calculate_pressure_drop()
# radiator_mass_kg = radiator.calculate_mass()