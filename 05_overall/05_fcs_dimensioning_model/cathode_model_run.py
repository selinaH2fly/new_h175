"""
cathode_model_run.py

This file contains parameter classes for various components used in the cathode model, including:
- Input: Contains pressure and temperature values for different stages of the cathode system.
- Compressor_Parameters: Defines parameters for the compressor, including mass flow rate, efficiency, and pressure ratio.
- Intercooler_Parameters: Holds parameters for the intercooler, such as mass flow rate, inlet/outlet temperatures, and pressure drop.
- Humidifier_Parameters: Contains mass flow rates, temperatures, pressures, and relative humidity values for the humidifier.
- Turbine_Parameters: Contains turbine parameters like mass flow rate, inlet temperature, and efficiency.
- Physical_Parameters: Contains physical constants, including the specific gas constants for air and water vapor.
"""

class Input:
    def __init__(self):
        # Pressure initialization in bar (bara)
        self.pressures_bara = {
            "PTC001": 0.7,  # Ambient pressure for FL270
            "PTC211": 2.6,  # Pressure after compressor stage 2
            "PTC301": 2.5,  # Pressure after intercooler, air-air, warm side
            "PTC311": 2.4,  # Pressure after intercooler, air-liq
            "PTC401": 2.3,  # Pressure after humidifier
            "PTC501": 2.1,  # Pressure after stack
            "PTC601": 1.8,  # Pressure after water separator
            "p_8": 1.7      # Pressure at intercooler, air-air, cold side
        }

        # Temperature initialization in degrees Celsius
        self.temperatures_degC = {
            "TTC001": -5,   # Ambient temperature for FL270
            "TTC311": 80,   # Temperature after intercooler, air-liq
            "TTC401": 80,   # Temperature after humidifier, to be calculated
            "TTC501": 80,   # Temperature after stack
            "TTC601": 80,   # Temperature after water separator
            "T_cool": 50    # Temperature of coolant input to IC air-liq
        }

        # Convert pressures and temperatures
        self.pressures_Pa = {key: self.convert_pressure(value) for key, value in self.pressures_bara.items()}
        self.temperatures_K = {key: self.convert_temperature(value) for key, value in self.temperatures_degC.items()}

#TODO: change following to use convert function from basics_physics when that works
    '''
    static method is typically used for utility functions that perform a task in isolation, 
    such as calculations or conversions that don’t depend on instance data
    '''
    @staticmethod
    def convert_pressure(pressure_bara):
        """Convert pressure from bar to Pa."""
        return pressure_bara * 1e5  # 1 bara = 100000 Pa

    @staticmethod
    def convert_temperature(temp_degC):
        """Convert temperature from Celsius to Kelvin."""
        return temp_degC + 273.15


class Physical_Parameters:
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
        self.dry_air_mass_flow_kg_s = 0.165
        self.wet_air_mass_flow_kg_s = 0.155
        self.dry_air_temperature_in_K = 353.3
        self.dry_air_pressure_in_Pa = 246000
        self.dry_air_rh_in = 0.3
        self.dry_air_temperature_out_K = 346.9
        self.dry_air_pressure_out_Pa = 230000
        self.dry_air_rh_out = 0.75
        self.wet_air_temperature_in_K = 353.2
        self.wet_air_pressure_in_Pa = 210000
        self.wet_air_rh_in = 0.99
        self.wet_air_pressure_out_Pa = 196000


class Turbine_Parameters:
    def __init__(self):
        self.mass_flow_rate_kg_s = 0.95
        self.inlet_temp_K = 1200
        self.efficiency = 0.88


# Example usage
if __name__ == "__main__":
    inputs = Input()
    print("Pressures (Pa):", inputs.pressures_Pa)
    print("Temperatures (K):", inputs.temperatures_K)
