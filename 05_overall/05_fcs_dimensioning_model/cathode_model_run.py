"""
cathode_model_run.py

This file contains parameter classes for various components used in the cathode model, including:
- Pressure_Parameters: Contains pressure values for different stages of the cathode system, with conversions from bar to Pa.
- Compressor_Parameters: Defines parameters for the compressor, including mass flow rate, efficiency, and pressure ratio.
- Intercooler_Parameters: Holds parameters for the intercooler, such as mass flow rate, inlet/outlet temperatures, and pressure drop.
- Humidifier_Parameters: Contains mass flow rates, temperatures, pressures, and relative humidity values for the humidifier.
- Turbine_Parameters: Contains turbine parameters like mass flow rate, inlet temperature, and efficiency.
- Physical_Parameters: Contains physical constants, including the specific gas constants for air and water vapor.
"""

class Input:
    def __init__(self):
        # Pressure initialization in bar (bara)
        self.PTC001_p_bara = 0.7  # Ambient pressure for FL270
        self.PTC211_p_bara = 2.6  # Pressure after compressor stage 2
        self.PTC301_p_bara = 2.5  # Pressure after intercooler, air-air, warm side
        self.PTC311_p_bara = 2.4  # Pressure after intercooler, air-liq
        self.PTC401_p_bara = 2.3  # Pressure after humidifier
        self.PTC501_p_bara = 2.1  # Pressure after stack
        self.PTC601_p_bara = 1.8  # Pressure after water separator
        self.p_8 = 1.7  # Pressure at intercooler, air-air, cold side

    #TODO: change later to convert funct when that works
        # Convert from bara to Pa manually
        self.PTC001_p_Pa = self.PTC001_p_bara * 1e5  # 1 bara = 100000 Pa
        self.PTC211_p_Pa = self.PTC211_p_bara * 1e5
        self.PTC301_p_Pa = self.PTC301_p_bara * 1e5
        self.PTC311_p_Pa = self.PTC311_p_bara * 1e5
        self.PTC401_p_Pa = self.PTC401_p_bara * 1e5
        self.PTC501_p_Pa = self.PTC501_p_bara * 1e5
        self.PTC601_p_Pa = self.PTC601_p_bara * 1e5
        self.p_8_Pa = self.p_8 * 1e5

        # Temperature initialization in degrees Celsius
        self.TTC001_T_degC = -5     # Ambient temperature for FL270
        self.TTC311_T_degC = 80     # Temperature after intercooler, air-liq
        self.TTC401_T_degC = 80      # Temperature after humidifier, to be calculated
        self.TTC501_T_degC = 80      # Temperature after stack
        self.TTC601_T_degC = 80      # Temperature after water separator
        self.T_cool = 50             # Temperature of coolant input to IC air-liq
    # TODO: change later to convert funct when that works
        # Convert temperatures to Kelvin
        self.TTC001_T_K = self.TTC001_T_degC + 273.15
        self.TTC311_T_K = self.TTC311_T_degC + 273.15
        self.TTC401_T_K = self.TTC401_T_degC + 273.15
        self.TTC501_T_K = self.TTC501_T_degC + 273.15
        self.TTC601_T_K = self.TTC601_T_degC + 273.15
        self.T_cool_K = self.T_cool + 273.15

class PhysicalParameters:
    def __init__(self):
        self.R_air = 287.06  # Specific gas constant for air [J/(kg*K)]
        self.R_water_vapor = 461.52  # Specific gas constant for water vapor [J/(kg*K)]

class Compressor_Parameters:
    def __init__(self):
        self.mass_flow_rate_kg_s = 1.2
        self.efficiency = 0.85
        self.pressure_ratio = 2.5

class Intercooler_Parameters:
    def __init__(self):
        self.mass_flow_rate_kg_s = 1.1
        self.inlet_temp_K = 400
        self.outlet_temp_K = 310
        self.pressure_drop_Pa = 20000

class Humidifier_Parameters:
    def __init__(self):
        self.dry_air_mass_flow_kg_s = 0.09
        self.wet_air_mass_flow_kg_s = 0.053
        self.dry_air_temperature_in_K = 353.3
        self.dry_air_pressure_in_Pa = 105000
        self.dry_air_rh_in = 0.18
        self.dry_air_temperature_out_K = 346.9
        self.dry_air_pressure_out_Pa = 101000
        self.dry_air_rh_out = 0.75
        self.wet_air_temperature_in_K = 353.2
        self.wet_air_pressure_in_Pa = 76000
        self.wet_air_rh_in = 0.99
        self.wet_air_pressure_out_Pa = 76000

class Turbine_Parameters:
    def __init__(self):
        self.mass_flow_rate_kg_s = 0.95
        self.inlet_temp_K = 1200
        self.efficiency = 0.88


#
# # Example usage
# if __name__ == "__main__":
#     pressures = PressureParameters()
#     compressor = CompressorParameters()
#     intercooler = IntercoolerParameters()
#     humidifier = HumidifierParameters()
#     turbine = TurbineParameters()
#     physical = PhysicalParameters()
#
#     pressures.print_pressures()
