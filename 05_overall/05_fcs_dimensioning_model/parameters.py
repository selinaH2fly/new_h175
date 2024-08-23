''' This file contains the parameter definitions for the input variable optimization.'''

class Optimization_Parameters:
    
    def __init__(self):
        '''TODO: Steffen P. suggests to evaluate the bounds during runtime depending on the current operating point according to the DoE data
        to prevent extrapolation. This is a good idea, but requires a bit more effort. Idea: Make it a constraint in the optimization problem.
        TODO: Include parameters for optimization function (such as maxiter, popsize, etc.)
        '''

        # Bounds for the optimization problem
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

        # Assumption: ~0.3 bar BoP pressure drop downstream the compressor at 130 g/s air flow rate
        self.nominal_BoP_pressure_drop_Pa = 0.3*1e5
        self.nominal_air_flow_kg_s = 0.130

class Turbine_Parameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75

        # Assumption: ~0.15 bar BoP pressure drop upstream the turbine at 130 g/s air flow rate
        self.nominal_BoP_pressure_drop_Pa = 0.15*1e5
        self.nominal_air_flow_kg_s = 0.130

class Recirculation_Pump_Parameters:
    
    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95

        self.fixed_recirculation_ratio = 70/30

        # Assumption: ~0.1 bar constant pressure drop in the recirculation loop
        self.nominal_BoP_pressure_drop_Pa = 0.1*1e5

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

class Stack_Parameters:

     def __init__(self):
             
        self.cell_area_m2 = 300*1e-4

        self.anode_pressure_drop_coefficients = [4*1e-4, 9.4*1e-3, 49.7] # cf. PowerLayout, DoE Evaluation
        self.cooling_pressure_drop_coefficients = [6.5e-3, 0.477, 0] # cf. PowerLayout, DoE Evaluation



class Eol_Parameter:

    def __init__(self):

        self.eol_factor = 0.85