import numpy as np

class Training_Parameters:

    def __init__(self):
        self.iterations = 1e3
        # self.iterations = 100
        self.learning_rate = 0.01
        # self.split_ratio = 0.8
        # self.seed = 42
        self.seed = None

# class Model_Parameters:

#     def __init__(self):
#         self.hidden_layer_size_1 = 64
#         self.hidden_layer_size_2 = 64

class Logging_Parameters:

    def __init__(self):
        self.log_interval = 10
        # self.save_interval = 50000

class Optimization_Parameters:
    
    def __init__(self):
        # self.grid_resolution = 100
        self.bounds = [(50, 700),      # current_A
                        (0, 100),        # cathode_rh_in_perc
                        (1, 5),          # stoich_cathode
                        (1.5, 3),        # pressure_cathode_in_bara
                        (40, 90),]       # temp_coolant_outlet_degC
        self.seed = None

        
class Physical_Parameters:
     
    def __init__(self):
        self.hydrogen_lhv_voltage_equivalent = 1.253
        self.hydrogen_hhv_voltage_equivalent = 1.481

        self.sea_level_ambient_pressure_bar = 1.01325
        self.sea_level_ambient_temperature_K = 288.15
        self.temperature_lapse_rate = 0.0065

        self.specific_gas_constant = 287.05
        self.gravity = 9.81
        self.specific_heat_ratio = 1.4
    
        self.oxygen_mol_fraction = 0.2095
        self.air_molar_mass = 28.97


          