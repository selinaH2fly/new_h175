''' This file contains the parameter definitions for the input variable optimization.'''

import numpy as np
import pandas as pd
import os
from collections import namedtuple # Used to create a datacontainer for evaluate_models(x) return

class VariableContainer:
    # Define the named tuple as a class attribute
    ResultModels = namedtuple('ResultModels', [
        'optimized_input', 
        'optimized_cell_voltage_V', 
        'compressor_power_W', 
        'turbine_power_W', 
        'reci_pump_power_W', 
        'coolant_pump_power_W',
        'stack_heat_flux_W', 
        'intercooler_heat_flux_W', 
        'evaporator_heat_flux_W', 
        'radiator_heat_flux_W', 
        'hydrogen_supply_rate_g_s', 
        'system_mass_kg', 
        'fixed_mass', 
        'power_dependent_mass', 
        'compressor_mass_kg', 
        'rezi_pump_mass_kg', 
        'coolant_pump_mass_kg', 
        'radiator_mass_kg', 
        'cellcount_dependent_mass', 
        'H2_dependend_mass', 
        'stack_power_W', 
        'corrected_mass_flow', 
        'pressure_ratio', 
        'optimization_converged',
        'compressor_cor_mass_flow_g_s',
        'compressor_pressure_ratio',
        'system_power_W',
        "cell_voltage_V", 
        "system_efficiency"
    ])

    def __init__(self):
        "Initialize with all fields set to None"
        self.result = self.ResultModels(**{field: None for field in self.ResultModels._fields})

    def update(self, **kwargs):
        "Update the result named tuple with provided keyword arguments."
        self.result = self.result._replace(**kwargs)

class Optimization_Parameters:
    
    def __init__(self):

        # Bounds for the optimization problem TODO: make these a dictionary
        self.bounds = [(20, 2e3),       # current_A
                        (30, 120),      # cathode_rh_in_perc (rH_min = 30% according to P10 manual)
                        (1.6, 5.0),     # stoich_cathode (lambda_min = 1.6 according to P10 manual)
                        (1.1, 3.0),     # pressure_cathode_in_bara (p_max = 2.3 barg according to P10 manual)
                        (60, 90),       # temp_coolant_inlet_degC
                        (60, 90),       # temp_coolant_outlet_degC
                        (1,10),         # stoich_anode
                        (1,5)]          # pressure_anode_in_bara
        
        # Evolutionary algorithm settings: https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.differential_evolution.html
        self.tol = 1e-4                 # tolerance for the optimization: np.std(pop) <= atol + tol * np.abs(np.mean(population_energies))
        self.maxiter = 1                # maximum number of iterations
        self.popsize = 30               # population size for the evolutionary algorithm
        self.recombination = 0.9        # recombination rate \in [0, 1];
        self.strategy = 'best1bin'      # default:'best1bin'
        self.seed = None                # set random seed for reproducibility
        self.init_cell_voltage = 0.7    # cell voltage for init population
        self.brutto_deviation = 1.3     # estimated deviation brutto/netto power
        
class Physical_Parameters:
     
    def __init__(self):

        self.hydrogen_lhv_voltage_equivalent_V = 1.253

        self.sea_level_ambient_pressure_bar = 1.01325
        self.sea_level_ambient_temperature_K = 288.15
        self.temperature_lapse_rate_K_m = 0.0065
        self.oxygen_mol_fraction = 0.2095

        #self.air_molar_mass = 28.97 * 1e-3              # kg/mol
        
        #enthalpy of evaporation of H2
        self.evaporation_enthalpy_J_kg = 446000                               # J/kg 
        
        #this is a "magic number" from Tank team, cp_H2 from 20K till 300K will change, this is a linear estimation.
        #TODO: we would need to integrate for each T and p along the heating process to get cp
        #Docu: https://h2fly.atlassian.net/browse/HWI-428?focusedCommentId=13070
        self.mean_cp_H2 = 14500 #J/kg.K for 20K --> 300K

class Assumptions:
        
    def __init__(self):

        self.hydrogen_loss_factor = 0.05    # fraction of hydrogen lost by purging; note: for \lambda_A > 1, it's inevitable to lose some hydrogen!
        self.flightduration_h = 1.5 # X hours of flightduration (needed for Tank mass calculation)

# TODO: move component parameters to component class definitions!?!
class Compressor_Parameters:

    def __init__(self):
        path = os.getcwd()
        print(path)
        compressor_map_Iris = pd.read_csv('../Components/20211113_Verdichterkennfeld_Iris.csv')
        compressor_map_VSEC15 = pd.read_csv('../Components/20211115_Verdichterkennfeld_VSEC15.csv')
        compressor_map_Scalable = pd.read_csv('../Components/20211121_Verdichterkennfeld_Scalable.csv')
        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}

        # Assumption: ~0.3 bar BoP pressure drop downstream the compressor at 130 g/s air flow rate
        self.nominal_BoP_pressure_drop_Pa = 0.3*1e5
        self.nominal_air_flow_kg_s = 0.130

        # Reference variables for airflow correction
        self.reference_pressure_Pa = 1.01325 * 1e5
        self.reference_temperature_K = 25 + 273.15

        # Compressor map parameters
        self.compressor_map_VSEC15 = {
            "corrected_massflow_g_s":np.array(compressor_map_VSEC15["corrected_massflow_g_s"]) ,
            "pressure_ratio":np.array( compressor_map_VSEC15["pressure_ratio"]),
            "efficiency": np.array(compressor_map_VSEC15["efficiency"]), 
            "reference_pressure_Pa":  1.01325 * 1e5,
            "reference_temperature_K": 25 + 273.15
        }
        self.compressor_map_Iris = {
            "corrected_massflow_g_s":np.array(compressor_map_Iris["Massenstrom"]*1000) ,
            "pressure_ratio":np.array( compressor_map_Iris["Druckverhaeltnis"]),
            "efficiency": np.array(compressor_map_Iris["Efficiency"]), 
            "reference_pressure_Pa": 39875,
            "reference_temperature_K": -16 + 273.15
        }
        self.compressor_map_Scalable = {
            "corrected_massflow_g_s":np.array(compressor_map_Scalable["corrected_massflow_g_s"]) ,
            "pressure_ratio":np.array( compressor_map_Scalable["pressure_ratio"]),
            "efficiency": np.array(compressor_map_Scalable["efficiency"]), 
            "reference_pressure_Pa":  1.01325 * 1e5,
            "reference_temperature_K": 25 + 273.15
        }

class Turbine_Parameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}

        # Assumption: ~0.15 bar BoP pressure drop upstream the turbine at 130 g/s air flow rate
        self.nominal_BoP_pressure_drop_Pa = 0.15*1e5
        self.nominal_air_flow_kg_s = 0.130

class Recirculation_Pump_Parameters:
    
    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}

        self.fixed_recirculation_ratio = 70/30

        # Assumption: ~0.1 bar constant pressure drop in the recirculation loop
        self.nominal_BoP_pressure_drop_Pa = 0.1*1e5

class Coolant_Pump_Parameters:

    def __init__(self):

        self.isentropic_efficiency = 0.75
        self.electric_efficiency = 0.95
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}

        # Assumption: ~0.5 bar pressure drop at 10 l/min coolant in LT cooling circuit
        self.nominal_pressure_drop_lt_Pa = 0.5*1e5
        self.nominal_coolant_flow_lt_m3_s = 10/(1000*60)

class Radiator_Parameters:

    def __init__(self):
        self.mass_by_power_kg_kW = {"mean": 1.0, "sd": 0.1}

        # Assumption: ~0.4 bar pressure drop at 250 l/min coolant in HT cooling circuit (including hoses and valves)
        self.nominal_pressure_drop_Pa = 0.4*1e5
        self.nominal_coolant_flow_m3_s = 250/(1000*60)
        self.mass_by_power_kg_kW = {"Herve_Radiator_Model": {"T_stack_out": [60.0,65.0,70.0,75.0,80.0,85.0,90.0,95.0,100.0],
                                                             "mass_by_power": [0.1483,0.0854,0.0625,0.0501,0.0420,0.0358,0.0316,0.0279,0.0253]},
                                    #"mean": 1.0, 
                                    #"sd": 0.1
                                    }
        
class Stack_Parameters:

     def __init__(self):
             
        self.cell_area_m2 = 300 / (100 * 100)

        self.anode_pressure_drop_coefficients = [4*1e-4, 9.4*1e-3, 49.7]    # cf. PowerLayout, DoE Evaluation
        self.cooling_pressure_drop_coefficients = [6.5e-3, 0.477, 0]        # cf. PowerLayout, DoE Evaluation
        self.H2_concentration_fix = 70      #fix H2 concentration in percent default = 70 

class Intercooler_Parameters:

    def __init__(self):
        self.efficiency = 1.0
        
        self.primary_fluid = "Air" 
        self.coolant_fluid = "INCOMP::MEG-50%"# 50% Ethylene Glycol (MEG) and 50% Water, i.e., Glysantin
        self.ALLOWED_FLUIDS = ['Water', 'Air', 'MEG', 'H2','INCOMP::MEG-50%']

class Evaporator_Parameters:
    
    def __init__(self):
        
        self.efficiency = 1.0
        self.primary_fluid = "H2"
        self.primary_T_in_K = 20.0
        self.primary_T_out_K = 300.0
        self.primary_p_in_Pa = 3.5*1e5 #5->3.5 TODO: this is equal to the tank pressure, use it directly
        
        self.coolant_fluid = "INCOMP::MEG-50%"# 50% Ethylene Glycol (MEG) and 50% Water, i.e., Glysantin
        self.ALLOWED_FLUIDS = ['H2','INCOMP::MEG-50%']
    
class Eol_Parameters:

    def __init__(self):

        self.reference_derating_factor = 0.85
        self.reference_current_density_A_m2 = 2.0 * (100 * 100)             # 2.0 A/cm2 at 300 cm2 cell area results in 600 A

class Tank_Parameters:

     def __init__(self):
             
        self.massfraction = 1   #eigentlich 0.5 dry to wet aber 1:1 einfacher
        self.fixed_mass_kg = 10 #TODO: move this to the massestimator later, Number provided by Chris B.
        self.pressure_bar = 3.5*1e5
        
class Mass_Parameters:
    def __init__(self):
        # Mass estimates for fixed mass components
        # Components with 0 will be scaled masses, resembled by the first line of each component.
        self.masses_FCM_constants = {
            'Stack': {'Stack': 0, 
                      'CVM': 0.5, 'SMI': 1.5, 'Hose clamps': 0.18, 'Screws': 0.09, 'HV+LV Cable': 1.20},
            
            'Cathode': {'Compressor': 0, 'Turbine': 0.0,
                        'Filter': 0.2, 'HFM': 0.1,  'Compressor inverter': 4.4, 'Intercooler': 1.0,'Humidifier': 1.0,
                        'Valves': 1.5, 'Drain valve': 0.05, 'Water separator': 0.2,'Cathode pressure control valve': 0.0,
                        'Sensors': 0.3, 'Silicon hoses': 0.5, 'Hose clamps': 0.12, 'Connectors': 0.8,
                        'Screws': 0.18, 'HV+LV Cable': 0.67},
            
            'Anode': {'Recirculation pump': 0.0, 
                      'Shut-Off valve': 0.2, 'Pressure control valve': 0.2, 'Water separator': 0,
                      'Particle filter': 0.2, 'Drain valve': 0.2, 'Purge valve': 0.1, 'Sensors': 0.2,
                      'Anode piping': 0.5, 'Swagelok connector': 0.28, 'Screws': 0.09, 'HV+LV Cable': 0.34},
            
            'Thermal': {'Coolant pump': 0, 'Stack coolant': 0, 
                        'TCV': 0.5, 'Particle filter': 0.1, 'Ionic exchanger': 1.0,'Sensors': 0.2 + 0.20,
                        'Silicone hoses': 0.5 + 0.5, 'Hose clamps': 0.12 + 0.12, 'Connectors': 0.80 + 0.80,
                        'Screws': 0.09 + 0.09, 'HV+LV Cable': 0.34 + 0, 'Expansion tank': 0.20, 'Volume flow control valve': 0.5,
                        'Other coolant': 5.0},#other coolant = Coolantother than in stack
            
            'Other': {'FCCU': 0.5, 'Electrical connectors': 0.4, 'HDPU': 5.0, 'Frame': 2.0, 'Connectors': 1.0,
                      'Screws': 0.27,
                      'HV+LV Cable': 0.0,
                      'HV DCDC': 12.5,
                      "LV DCDC": 0.6}
        }
        # Mass estimates for dependent mass components, change the values as needed
        self.masses_FCM_power_depended = {
            'Compressor': {"mean": 0.63, "sd": 0.0},
            'Turbine': {"mean": 0.63, "sd": 0.0}, #TODO: Turbine weight is already captured by the compressor, still massestimator needs this to initiate the class in optimisation_function.py...  
            'Recirculation_Pump': {"mean": 4.0, "sd": 0}, # Chris Burger suggested 28.10.24
            'Coolant pump': {"mean": 1.66, "sd": 0}#,
            #'Turbine': {"mean": 0.0, "sd": 0.0},
        }