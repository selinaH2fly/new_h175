import numpy as np

class Training_Parameters:

    def __init__(self):
        self.iterations = 10e3
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
        self.log_interval = 1000
        # self.save_interval = 50000
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