"""
cathode_model_run.py

This file contains parameter classes for various components used in the cathode model, including:
- Input: Contains pressure and temperature values for different stages of the cathode system.
- CompressorParameters: Defines parameters for the compressor, including mass flow rate, efficiency and pressure.
- IntercoolerParameters: Defines  parameters for the intercooler, such as mass flow rate, fluid type, inlet/outlet temperatures.
- HumidifierParameters: Contains dry and wet mass flow rates, temperatures, pressures, and relative humidity values for the humidifier.
- TurbineParameters: Contains turbine parameters like mass flow rate, inlet temperature and efficiency.
- PhysicalParameters: Contains physical constants the specific gas constants for air and water vapor.
"""
import numpy as np
import CoolProp.CoolProp as CP

class Input:
    def __init__(self):
        # Pressure initialization in bar (bara)
        self.pressures_bara = {
            "PTC001": 0.7,  # Ambient pressure for FL100
            "PTC211": 2.6,  # Pressure after compressor
            "PTC301": 2.5,  # Pressure after intercooler, air-air, warm side
            "PTC311": 2.4,  # Pressure after intercooler, air-liq
            "PTC401": 2.3,  # Pressure after humidifier
            "PTC501": 2.1,  # Pressure after stack
            "PTC601": 1.8,  # Pressure after water separator
            "p_8": 1.7      # Pressure at intercooler, air-air, cold side
        }

        # Temperature initialization in degrees Celsius
        self.temperatures_degC = {
            "TTC001": -5,   # Ambient temperature
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


class PhysicalParameters:
    def __init__(self):
        # Retrieve standard pressure using CoolProp (Pa)
        self.P_std = CP.PropsSI("P", "T", 273.15, "Q", 0, "Water")  # Standard pressure in Pa

        # Standard temperature in Kelvin (273.15 K)
        self.T_std = 273.15

        # Retrieve molar mass of air (kg/mol) from CoolProp
        self.M_air = CP.PropsSI("M", "Air")  # Molar mass of air in kg/mol

        # Universal gas constant R (J/(mol·K)) from CoolProp
        self.R = CP.PropsSI("gas_constant","T",300,"P", 101325,"Air");

        # Retrieve the specific gas constant for dry air (J/(kg·K))
        self.R_air = CP.PropsSI('GAS_CONSTANT', 'Air') / self.M_air  # Specific gas constant of air

        # Retrieve the specific gas constant for water vapor (J/(kg·K))
        self.R_water_vapor = CP.PropsSI('GAS_CONSTANT', 'Water') / CP.PropsSI('M',
                                                                      'Water')  # Specific gas constant of water vapor


class CompressorParameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95

        # Compressor map parameters
        self.compressor_map_VSEC15 = {
            "corrected_massflow_g_s": np.array([
                [41.9571206132472, 38.8968738771111, 33.6507366151635, 26.2187088274045, 18.7866810396455, 10.9174751467242],
                [65.1275601868488, 52.0122170319800, 39.3340519822734, 28.8417774583783, 19.2238591448078, 11.3546532518865],
                [90.9210683914242, 76.9313690262308, 65.5647382920111, 45.8917235597078, 34.5250928254882, 23.5956401964307],
                [116.277398490837, 100.101808599832, 86.1121092346390, 74.7454785004193, 58.1327105042521, 41.0827644029226],
                [144.693975326387, 129.392741645706, 116.277398490837, 92.6697808120734, 70.3736974487964, 57.6955323990898],
                [173.547730267098, 155.186249850282, 141.196550485088, 120.649179542460, 100.101808599832, 82.1775062881783],
                [203.275841418134, 179.231045634208, 162.181099532878, 149.065756378009, 135.950413223141, 123.709426278596],
                [231.692418253683, 221.200143729788, 210.270691100731, 192.783566894239, 177.045155108396, 158.246496586418],
                [243.059048987903, 235.627021200144, 228.194993412385, 215.954006467841, 192.346388789077, 171.799017846449]
            ]),
            "pressure_ratio": np.array([
                [1.10176833162121, 1.11158941824291, 1.11170507382629, 1.11186891923607, 1.11203276464585, 1.11220624802092],
                [1.19879372810862, 1.20883648793179, 1.21399279935731, 1.21910092095643, 1.22418976662499, 1.22436325000005],
                [1.32989896983090, 1.34483781601700, 1.35484202397905, 1.36502935328144, 1.36527994037876, 1.36552088951079],
                [1.49515152254502, 1.53452261071936, 1.54458464647310, 1.54971204400278, 1.55007828668347, 1.55045416732944],
                [1.71000000000000, 1.73000000000000, 1.77000000000000, 1.79000000000000, 1.80000000000000, 1.79000000000000],
                [1.98156999232976, 2.01123564946578, 2.06031216867844, 2.10465644693796, 2.10023262087382, 2.08599734615325],
                [2.26376961576786, 2.35695910207329, 2.41097989747529, 2.45028351989266, 2.46032627971583, 2.46547295317607],
                [2.58988944699309, 2.70228739810426, 2.76105007242469, 2.82971093708907, 2.86907238729812, 2.90362449283178],
                [2.77983446675805, 2.87265771038279, 2.94109690184570, 3.03402616308853, 3.10282195926684, 3.17155028968819]
            ]),
            "efficiency": np.array([
                [0.345, 0.33, 0.32, 0.309, 0.24, 0.193],
                [0.505, 0.499, 0.475, 0.437, 0.367, 0.317],
                [0.586, 0.588, 0.571, 0.522, 0.445, 0.429],
                [0.641, 0.643, 0.646, 0.629, 0.589, 0.497],
                [0.655, 0.67, 0.674, 0.672, 0.646, 0.556],
                [0.657, 0.673, 0.688, 0.695, 0.69, 0.644],
                [0.679, 0.69, 0.704, 0.716, 0.701, 0.682],
                [0.675, 0.68, 0.698, 0.72, 0.713, 0.692],
                [0.668, 0.68, 0.695, 0.719, 0.712, 0.701]
            ]),
            "reference_pressure_Pa": 1.01325 * 1e5,
            "reference_temperature_K": 25 + 273.15
        }

class TurbineParameters:

    def __init__(self):

        self.isentropic_efficiency = 0.55
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}

        # Assumption: ~0.15 bar BoP pressure drop upstream the turbine at 130 g/s air flow rate
        self.nominal_BoP_pressure_drop_Pa = 0.15*1e5
        self.nominal_air_flow_kg_s = 0.155
        # Turbine map parameters
        self.turbine_map = {
            "expansion_ratio": np.array([
                [1.20, 1.40, 1.60, 1.80, 1.99, 2.19],
                [1.20, 1.40, 1.60, 1.80, 2.00, 2.20],
                [1.20, 1.40, 1.59, 1.79, 2.00, 2.20],
                [1.20, 1.40, 1.61, 1.81, 1.99, 2.21],
                [1.20, 1.40, 1.60, 1.79, 1.99, 2.20],
                [1.20, 1.41, 1.60, 1.80, 2.00, 2.20]
            ]),
            "corrected_massflow_g_s": np.array([
                [69.10, 84.72, 93.78, 98.53, 101.84, 103.53],
                [69.94, 86.42, 95.59, 99.76, 103.04, 104.77],
                [67.46, 87.19, 95.91, 101.28, 103.68, 104.69],
                [46.80, 85.88, 95.63, 100.63, 103.81, 104.74],
                [34.80, 82.49, 94.61, 100.56, 104.01, 105.32],
                [32.09, 80.90, 95.48, 100.56, 103.50, 105.07]
            ]),
            "isentropic_efficiency": np.array([
                [0.50, 0.47, 0.38, 0.34, 0.31, 0.29],
                [0.56, 0.55, 0.51, 0.48, 0.43, 0.41],
                [0.33, 0.60, 0.63, 0.63, 0.61, 0.59],
                [-0.19, 0.53, 0.62, 0.63, 0.64, 0.64],
                [-0.70, 0.30, 0.60, 0.66, 0.67, 0.68],
                [-0.74, 0.29, 0.58, 0.64, 0.65, 0.66]
            ])
        }
class IntercoolerParameters:
    def __init__(self):
        self.efficiency = 0.49
        self.primary_fluid = "Air"
        self.coolant_fluid = "INCOMP::MEG-50%"  # 50% Ethylene Glycol (MEG) and 50% Water, i.e., Glysantin
        self.ALLOWED_FLUIDS = ['Water', 'Air', 'MEG', 'H2','INCOMP::MEG-50%']

class HumidifierParameters:

    def __init__(self):
        self.dry_air_mass_flow_kg_s = 0.175
        self.wet_air_mass_flow_kg_s = 0.155
        self.dry_air_temperature_in_K = 353.3
        self.dry_air_pressure_in_Pa = 246000
        self.dry_air_rh_in= 0.3
        self.dry_air_temperature_out_K = 346.9
        self.dry_air_pressure_out_Pa = 230000
        self.dry_air_rh_out = 0.75
        self.wet_air_temperature_in_K = 353.2
        self.wet_air_pressure_in_Pa = 210000
        self.wet_air_rh_in = 0.99
        self.wet_air_pressure_out_Pa = 196000

        # Flow rate to efficiency map Fumatech (in SLPM: Standard Liters per Minute, Efficiency in %)
        self.humidifier_efficiency_map = {
            2000: 61.0,
            3000: 50.0,
            4000: 45.5,
            5000: 42.0
        }

class ValveParameters:
    def __init__(self):
        """
        This class contains the empirical data for the bypass valve opening percentages and
        the corresponding mass flow rates in g/s, represented in dictionary format.
        """
        # Data from the T50 Test Result for Fully Closed to Full Open
        self.pwm = [6, 20, 30, 40, 50, 60, 70, 80, 90, 94]  # PWM percentages
        self.mechanical_angle = [0.8, 14, 23.4, 32.8, 42.2, 51.5, 60.9, 70.3, 79.7, 83.5]  # Mechanical angles
        self.can_control = [10, 166, 278, 389, 501, 611, 722, 834, 945, 990]  # CAN control values

        # Pressure drop data (kPa) for different conditions
        self.pressure_1kpa = [0.00, 8.70, 16.21, 23.40, 32.90, 43.60, 56.80, 70.70, 78.60, 78.70]
        self.pressure_2kpa = [0.00, 11.80, 22.30, 33.18, 46.00, 61.50, 79.60, 98.18, 110.00, 112.00]
        self.pressure_5kpa = [0.00, 19.06, 36.70, 51.50, 73.20, 124.80, np.nan, np.nan, np.nan, np.nan]
        self.pressure_10kpa = [0.00, 26.28, 52.50, 74.00, 169.70, 186.70, np.nan, np.nan, np.nan, np.nan]
        self.pressure_20kpa = [0.00, 35.28, 69.60, np.nan, 252.20, np.nan, np.nan, np.nan, np.nan, np.nan]
        self.pressure_30kpa = [0.00, 40.19, 227.50, 261.00, 282.60, 295.20, 303.30, 305.00, 311.00, 311.80]

##TODO It should be omitted
class Mass_Parameters:
    def __init__(self):
        # Mass estimates for fixed mass components
        self.masses_FCM_constants = {
            'Stack': {'Stack': 0, 'CVM': 0.5, 'SMI': 1.5, 'Hose clamps': 0.18, 'Screws': 0.09, 'HV+LV Cable': 1.20},
            'Cathode': {'Filter': 0.2, 'HFM': 0.1, 'Compressor': 0, 'Compressor inverter': 6.0, 'Intercooler': 1.0,
                        'Humidifier': 1.0,
                        'Valves': 1.5, 'Drain valve': 0.05, 'Water separator': 0.2,
                        'Cathode pressure control valve': 0.0,
                        'Sensors': 0.3, 'Silicon hoses': 0.5, 'Hose clamps': 0.12, 'Connectors': 0.8,
                        'Screws': 0.18,
                        'HV+LV Cable': 0.67, 'Turbine': 0.0},
            'Anode': {'Shut-Off valve': 0.2, 'Pressure control valve': 0.2, 'Water separator': 0,
                      'Particle filter': 0.2,
                      'Recirculation pump': 4.0, 'Drain valve': 0.2, 'Purge valve': 0.1, 'Sensors': 0.2,
                      'Anode piping': 0.5,
                      'Swagelok connector': 0.28, 'Screws': 0.09, 'HV+LV Cable': 0.34},
            'Thermal': {'Coolant pump': 3.0, 'TCV': 0.5, 'Particle filter': 0.1, 'Ionic exchanger': 1.0,
                        'Sensors': 0.2 + 0.20,
                        'Silicone hoses': 0.5 + 0.5, 'Hose clamps': 0.12 + 0.12, 'Connectors': 0.80 + 0.80,
                        'Screws': 0.09 + 0.09,
                        'HV+LV Cable': 0.34, 'Expansion tank': 0.20, 'Volume flow control valve': 0.5,
                        'Stack coolant': 0,
                        'Other coolant': 5.0},
            'Other': {'FCCU': 0.5, 'Electrical connectors': 0.4, 'HDPU': 5.0, 'Frame': 2.0, 'Connectors': 1.0,
                      'Screws': 0.27,
                      'HV+LV Cable': 0.0}
        }
        # Mass estimates for dependent mass components, change the values as needed
        self.masses_FCM_depended = {
            'Compressor': {"mean": 0.0, "sd": 0.0},
            'Recirculation_Pump': {"mean": 0.0, "sd": 0.0},
            'Turbine': {"mean": 0.0, "sd": 0.0},
        }