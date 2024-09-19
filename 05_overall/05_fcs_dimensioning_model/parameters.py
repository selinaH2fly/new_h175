''' This file contains the parameter definitions for the input variable optimization.'''

import numpy as np
from Components.stack import Stack
class Optimization_Parameters:
    
    def __init__(self):
        '''TODO: Steffen P. suggests to evaluate the bounds during runtime depending on the current operating point according to the DoE data
        to prevent extrapolation. This is a good idea, but requires a bit more effort. Idea: Make it a constraint in the optimization problem.
        TODO: Include parameters for optimization function (such as maxiter, popsize, etc.)
        '''

        # Bounds for the optimization problem TODO: make these a dictionary
        self.bounds = [(50, 2e3),       # current_A
                        (30, 100),      # cathode_rh_in_perc (rH_min = 30% according to P10 manual)
                        (1.6, 5),       # stoich_cathode (lambda_min = 1.6 according to P10 manual)
                        (1.1, 3.3),     # pressure_cathode_in_bara (p_max = 2.3 barg according to P10 manual)
                        (60, 90),       # temp_coolant_inlet_degC
                        (60, 90)]       # temp_coolant_outlet_degC
        
        # Evolutionary algorithm settings: https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.differential_evolution.html
        self.tol = 1e-4                 # tolerance for the optimization: np.std(pop) <= atol + tol * np.abs(np.mean(population_energies))
        self.maxiter = 1000             # maximum number of iterations
        self.popsize = 30               # population size for the evolutionary algorithm
        self.recombination = 0.9        # recombination rate \in [0, 1];
        self.seed = None                # set random seed for reproducibility

        self.penalty_weight = 1e-6      # penalty factor for power constraint violation TODO: try making this a constraint (instead of a penalty) -> probably needs to define the cell voltage as an input variable!?


class Physical_Parameters:
     
    def __init__(self):

        # TODO: Make all variable names indicative of their units
        # TODO: Don't define constants here that we can get from CoolProp (e.g., molar masses)
        self.hydrogen_lhv_voltage_equivalent = 1.253
        self.hydrogen_hhv_voltage_equivalent = 1.481
        #self.hydrogen_molar_mass = 2.016 * 1e-3         # kg/mol
        #self.nitrogen_molar_mass = 28.0134 * 1e-3       # kg/mol
        #self.faraday = 96485                            # C/mol

        self.sea_level_ambient_pressure_bar = 1.01325
        self.sea_level_ambient_temperature_K = 288.15
        self.temperature_lapse_rate = 0.0065

        #self.specific_gas_constant = 287.05
        #self.gravity = 9.81
        self.specific_heat_ratio = 1.4
        #self.ideal_gas_constant = 8.314
    
        self.oxygen_mol_fraction = 0.2095
        #self.air_molar_mass = 28.97 * 1e-3              # kg/mol        


class Compressor_Parameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}                        # kg/kW

        # Assumption: ~0.3 bar BoP pressure drop downstream the compressor at 130 g/s air flow rate
        self.nominal_BoP_pressure_drop_Pa = 0.3*1e5
        self.nominal_air_flow_kg_s = 0.130

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

class Turbine_Parameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}                        # kg/kW

        # Assumption: ~0.15 bar BoP pressure drop upstream the turbine at 130 g/s air flow rate
        self.nominal_BoP_pressure_drop_Pa = 0.15*1e5
        self.nominal_air_flow_kg_s = 0.130

class Recirculation_Pump_Parameters:
    
    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}                        # kg/kW

        self.fixed_recirculation_ratio = 70/30

        # Assumption: ~0.1 bar constant pressure drop in the recirculation loop
        self.nominal_BoP_pressure_drop_Pa = 0.1*1e5

class Coolant_Pump_Parameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}                        # kg/kW

        # Assumption: ~0.5 bar pressure drop at 10 l/min coolant in LT cooling circuit
        self.nominal_pressure_drop_lt_Pa = 0.5*1e5
        self.nominal_coolant_flow_lt_m3_s = 10/(1000*60)

class Radiator_Parameters:

    def __init__(self):
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}                        # kg/kW

        # Assumption: ~0.4 bar pressure drop at 250 l/min coolant in HT cooling circuit (including hoses and valves)
        self.nominal_pressure_drop_Pa = 0.4*1e5
        self.nominal_coolant_flow_m3_s = 250/(1000*60)

class Stack_Parameters:

     def __init__(self):
             
        self.cell_area_m2 = 300 / (100 * 100)

        self.anode_pressure_drop_coefficients = [4*1e-4, 9.4*1e-3, 49.7]    # cf. PowerLayout, DoE Evaluation
        self.cooling_pressure_drop_coefficients = [6.5e-3, 0.477, 0]        # cf. PowerLayout, DoE Evaluation

class Eol_Parameter:

    def __init__(self):

        self.reference_derating_factor = 0.85
        self.reference_current_density_A_m2 = 2.0 * (100 * 100)             # 2.0 A/cm2 at 300 cm2 cell area results in 600 A

# Mass Estimation of the Subsystems

class Mass_Estimator:
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
            'Compressor': {"mean": 1.0, "sd": 0.1},
            'Recirculation_Pump': {"mean": 1.0, "sd": 0.1},
            'Turbine': {"mean": 1.0, "sd": 0.1},
        }

        # Cell numbers
        self.cell_no = np.array([400, 450, 500])

        # Initialize lists for stack and coolant mass values
        self.m_stack_values = np.zeros(len(self.cell_no))
        self.m_coolant_values = np.zeros(len(self.cell_no))

        # Calculate stack mass and coolant mass for each cell number
        for i, n in enumerate(self.cell_no):
            stack = Stack(cellcount=n)
            self.m_stack_values[i] = stack.calculate_stack_mass()
            self.m_coolant_values[i] = stack.calculate_coolant_mass()

        # Dictionary to store the total mass estimates
        self.subsystem_mass_total = {}

    def sum_fixed_mass(self):
        """Sums the masses for each subsystem and returns the totals of the fixed mass."""
        subsystem_totals = {}
        total_mass = 0
        for subsystem, components in self.masses_FCM_constants.items():
            subsystem_mass = sum(components.values())
            subsystem_totals[subsystem] = subsystem_mass
            total_mass += subsystem_mass
        return subsystem_totals, total_mass

    """
    the masses from compressor, turbine and recirculation pumps are not computed.
    TODO: for each power, the mentioned masses should be added as required.
    
    """
    def estimate_mass(self):
        """Estimate the mass of the subsystems for the given cell number combination."""
        self.subsystem_mass_total = {
            'Stack': np.zeros(len(self.cell_no)),
            'Cathode': np.zeros(len(self.cell_no)),
            'Anode': np.zeros(len(self.cell_no)),
            'Thermal': np.zeros(len(self.cell_no)),
            'Other': np.zeros(len(self.cell_no))
        }

        for i, n in enumerate(self.cell_no):
            # Calculate mass for each subsystem
            temp, total_mass = self.sum_fixed_mass()

            # Stack and coolant mass scale with cell number
            temp['Stack'] += self.m_stack_values[i]
            temp['Thermal'] += self.m_coolant_values[i]

            # Assign the updated subsystem masses to the correct location
            for key, value in temp.items():
                self.subsystem_mass_total[key][i] = value

        return self.subsystem_mass_total
# %% Example Usage:
# Instantiate the class and run the mass estimation
estimator = Mass_Estimator()
mass_estimates = estimator.estimate_mass()

