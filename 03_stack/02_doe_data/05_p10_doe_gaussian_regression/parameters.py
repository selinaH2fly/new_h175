import numpy as np

class Training_Parameters:

    def __init__(self):
        self.iterations = 20e3
        # self.iterations = 100
        self.learning_rate = 5e-3
        # self.split_ratio = 0.8
        # self.seed = 42
        self.seed = None

# class Model_Parameters:

#     def __init__(self):
#         self.hidden_layer_size_1 = 64
#         self.hidden_layer_size_2 = 64

class Logging_Parameters:

    def __init__(self):
        self.log_interval = 500
        # self.save_interval = 50000

class Optimization_Parameters:
    
    def __init__(self):
        '''TODO: Steffen P. suggests to evaluate the bounds during runtime depending on the current operating point according to the DoE data
        to prevent extrapolation. This is a good idea, but requires a bit more effort. Idea: Make it a constraint in the optimization problem.
        TODO: Include parameters for optimization function (such as maxiter, popsize, etc.)
        '''
        self.bounds = [(50, 1e6),       # current_A
                        (30, 100),      # cathode_rh_in_perc (rH_min = 30% according to P10 manual)
                        (1.6, 5),       # stoich_cathode (lambda_min = 1.6 according to P10 manual)
                        (1.1, 3.3),     # pressure_cathode_in_bara (p_max = 2.3 barg according to P10 manual)
                        (60, 90),       # temp_coolant_inlet_degC
                        (60, 90)]       # temp_coolant_outlet_degC
        self.seed = None

        
class Physical_Parameters:
     
    def __init__(self):
        self.hydrogen_lhv_voltage_equivalent = 1.253
        self.hydrogen_hhv_voltage_equivalent = 1.481
        self.hydrogen_molar_mass = 2.016 * 1e-3         # kg/mol
        self.nitrogen_molar_mass = 28.0134 * 1e-3       # kg/mol
        self.faraday = 96485                            # C/mol

        self.sea_level_ambient_pressure_bar = 1.01325
        self.sea_level_ambient_temperature_K = 288.15
        self.temperature_lapse_rate = 0.0065

        self.specific_gas_constant = 287.05
        self.gravity = 9.81
        self.specific_heat_ratio = 1.4
        self.ideal_gas_constant = 8.314
    
        self.oxygen_mol_fraction = 0.2095
        self.air_molar_mass = 28.97 * 1e-3              # kg/mol        


class Compressor_Parameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95

class Turbine_Parameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75

class Recirculation_Pump_Parameters:
    
    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95

class Coolant_Pump_Parameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95

class Radiator_Parameters:

    def __init__(self):

        self.pressure_drop_Pa = 0.3*1e5 # roughly 300 mbar constant pressure drop according to Chris B.

class Eol_Parameter:

    def __init__(self):

        self.eol_factor = 0.85