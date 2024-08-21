''' This file contains the parameter definitions for the input variable optimization.'''

class Optimization_Parameters:
    
    def __init__(self):
        '''TODO: Steffen P. suggests to evaluate the bounds during runtime depending on the current operating point according to the DoE data
        to prevent extrapolation. This is a good idea, but requires a bit more effort. Idea: Make it a constraint in the optimization problem.
        TODO: Include parameters for optimization function (such as maxiter, popsize, etc.)
        '''
        self.bounds = [(50, 2e3),       # current_A
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

        # Assumption: ~0.5 bar pressure drop at 10 l/min coolant in LT cooling circuit
        self.nominal_pressure_drop_lt_Pa = 0.5*1e5
        self.nominal_coolant_flow_lt_m3_s = 10/(1000*60)

class Radiator_Parameters:

    def __init__(self):

        # Assumption: ~0.4 bar pressure drop at 250 l/min coolant in HT cooling circuit (including hoses and valves)
        self.nominal_pressure_drop_Pa = 0.4*1e5
        self.nominal_coolant_flow_m3_s = 250/(1000*60)

# class Stack_Parameters:

#     def __init__(self):


class Eol_Parameter:

    def __init__(self):

        self.eol_factor = 0.85