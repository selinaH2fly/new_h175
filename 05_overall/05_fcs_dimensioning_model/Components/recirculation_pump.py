import CoolProp.CoolProp as CP
import math
from scipy.constants import physical_constants
from parameters import Mass_Parameters

class Recirculation_Pump:
    
    def __init__(self, mass_estimator: Mass_Parameters, isentropic_efficiency=0.75, electric_efficiency=0.95, 
                 current_A=100, temperature_in_K=293.15, pressure_in_Pa=1e5, pressure_out_Pa=1e5,
                 n_cell=455, cell_area_m2=300*1e-4, stoich_anode=1.5, nominal_BoP_pressure_drop_Pa=0.1*1e5,
                 fixed_recirculation_ratio=None):
        """
        Initialize the recirculation pump with a given efficiency and operating conditions.

       Args:
        - mass_estimator: calls dict from parameters
        - isentropic_efficiency: Efficiency of the pump (default is 0.75)
        - electric_efficiency: Electric efficiency of the pump (default is 0.95)
        - current_A: Current in Amperes (default is 100)
        - temperature_in_K: Inlet temperature in Kelvin (default is 293.15)
        - pressure_in_Pa: Inlet pressure in Pascals (default is 1e5)
        - pressure_out_Pa: Outlet pressure in Pascals (default is 1e5)
        - n_cell: Number of cells in the stack (default is 455)
        - stoich_anode: Stoichiometry at the anode (default is 1.5)
        - fixed_recirculation_ratio: Fixed volumetric ratio of recirculated hydrogen/nitrogen (default is None)

        Returns:
        - reci_electric_power_W: Electrical power consumed by the recirculation pump in Watts.
        """
        
        self.isentropic_efficiency = isentropic_efficiency
        self.electric_efficiency = electric_efficiency
        self.current_A = current_A
        self.temperature_in_K = temperature_in_K
        self.pressure_in_Pa = pressure_in_Pa
        self.pressure_out_Pa = pressure_out_Pa
        self.n_cell = n_cell
        self.cell_area_m2 = cell_area_m2
        self.stoich_anode = stoich_anode
        self.nominal_BoP_pressure_drop = nominal_BoP_pressure_drop_Pa
        self.fixed_recirculation_ratio = fixed_recirculation_ratio

        # TODO: No constant parameters in the class definition. Move to parameters.py
        self.stoich_0 = 1.05                            # stoich_0 1.02-1.05 "lost als H2 aus system = ~5%" TODO: rather specify the recirculation ratio!
        self.hydrogen_concentration_supply = 1          # H2 concentration in tank

        # Ensure the component is available in masses_FCM_depended; raise error if missing
        if 'Recirculation_Pump' not in mass_estimator.masses_FCM_power_depended:
            raise ValueError("Component 'Recirculation_Pump' not found in mass estimator's dependent masses.")

        # Retrieve mass data from the mass_estimator instance
        self.mass_by_power_kg_kW = mass_estimator.masses_FCM_power_depended['Recirculation_Pump']

    def calculate_power(self)->float:
        """
        Calculate the electrical power consumed by the recirculation pump.
        
        Returns:
        - reci_electric_power_W: Electrical power consumed by the recirculation pump in Watts.
        """

        # Calculate the recirculated flows (either based on fixed recirculation ratio or based on nitrogen and hydrogen flow balances)
        if self.fixed_recirculation_ratio is None:
            hydrogen_recirculated_mol_s, nitrogen_recirculated_mol_s = self.calculate_flows()
        else:
            hydrogen_recirculated_mol_s, nitrogen_recirculated_mol_s = self.calculate_flows_fixed_recirculation_ratio(self.fixed_recirculation_ratio)

        # Compute the mass flows
        hydrogen_recirculated_kg_s = hydrogen_recirculated_mol_s*CP.PropsSI('M', 'Hydrogen')
        nitrogen_recirculated_kg_s = nitrogen_recirculated_mol_s*CP.PropsSI('M', 'Nitrogen')

        # Compute the isentropic outlet temperature
        
        cp_h =  CP.PropsSI('Cpmass', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Hydrogen')
        cv_h =  CP.PropsSI('Cvmass', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Hydrogen')

        cp_n =  CP.PropsSI('Cpmass', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Nitrogen')
        cv_n =  CP.PropsSI('Cvmass', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Nitrogen')

        kappa_h = cp_h/cv_h 
        kappa_n = cp_n/cv_n

        # compute kappa 
        isentropic_outlet_temperature_K_h = self.temperature_in_K * (self.pressure_out_Pa/self.pressure_in_Pa)**((kappa_h-1)/kappa_h)
        isentropic_outlet_temperature_K_n = self.temperature_in_K * (self.pressure_out_Pa/self.pressure_in_Pa)**((kappa_n-1)/kappa_n)
        
        # Compute the specific enthalpies of the species before and after the recirculation pump
        specific_enthalpy_hydrogen_in_J_kg = CP.PropsSI('H', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Hydrogen')
        specific_enthalpy_nitrogen_in_J_kg = CP.PropsSI('H', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Nitrogen')
        specific_enthalpy_hydrogen_out_J_kg = CP.PropsSI('H', 'T', isentropic_outlet_temperature_K_h, 'P', self.pressure_out_Pa, 'Hydrogen')
        specific_enthalpy_nitrogen_out_J_kg = CP.PropsSI('H', 'T', isentropic_outlet_temperature_K_n, 'P', self.pressure_out_Pa, 'Nitrogen')

        # Compute the isentropic power
        reci_isentropic_power_W = hydrogen_recirculated_kg_s*(specific_enthalpy_hydrogen_out_J_kg - specific_enthalpy_hydrogen_in_J_kg) + \
            nitrogen_recirculated_kg_s*(specific_enthalpy_nitrogen_out_J_kg - specific_enthalpy_nitrogen_in_J_kg)        

        # Compute the electric power
        reci_shaft_power_W = reci_isentropic_power_W/self.isentropic_efficiency
        reci_electric_power_W = reci_shaft_power_W/self.electric_efficiency

        return reci_electric_power_W
        
    def calculate_flows(self):
        """
        Calculate the mass flows of hydrogen and nitrogen in the recirculation pump based on nitrogen and hydrogen flow balances.
        """

        hydrogen_consumption_mol_s = self.current_A*self.n_cell/(2*(physical_constants['Faraday constant'][0]))         # consumed hydrogen in stack; mol/s
        hydrogen_recirculated_mol_s = (self.stoich_anode - self.stoich_0)*hydrogen_consumption_mol_s    # recirculated hydrogen; mol/s

        # Nitrogen diffusion flow in stack; TODO: check the formula as it gives very low values
        nitrogen_diffusion_mol_s = (1.2578 * math.log(self.current_A) - 2.6091)* \
            self.cell_area_m2*1e4*self.n_cell*(10**(-9))                                                # Stephan Voss' magic formulat for diffusion flow of nitrogen in stack; mol/s

        stack_flow_ratio = nitrogen_diffusion_mol_s/hydrogen_consumption_mol_s                          # ratio of stack flows (helper variable)

        # Concentrations (established by StRudolph; double checked by SteNo)
        hydrogen_concentration_in = (self.hydrogen_concentration_supply*self.stoich_anode*(self.stoich_0 - 1))/ \
            (self.stoich_0*(self.stoich_anode - 1) + self.hydrogen_concentration_supply*(self.stoich_anode - self.stoich_0)*(stack_flow_ratio - 1))
        hydrogen_concentration_out = hydrogen_concentration_in*(self.stoich_anode - 1)/ \
            (self.stoich_anode + hydrogen_concentration_in*(stack_flow_ratio - 1))
        
        # Recirculated nitrogen flow (established by StRudolph; double checked by SteNo)
        nitrogen_recirculated_mol_s = hydrogen_recirculated_mol_s*(1 - hydrogen_concentration_out)/hydrogen_concentration_out

        return hydrogen_recirculated_mol_s, nitrogen_recirculated_mol_s
    
    def calculate_flows_fixed_recirculation_ratio(self, recirculation_ratio=70/30):
        """
        Calculate the mass flows of hydrogen and nitrogen in the recirculation pump for a fixed recirculation ratio.
        
        Args:
        - recirculation_ratio: Fixed volumetric ratio of recirculated hydrogen/nitrogen."""

        hydrogen_consumption_mol_s = self.current_A*self.n_cell/(2*(physical_constants['Faraday constant'][0]))         # consumed hydrogen in stack; mol/s
        hydrogen_recirculated_mol_s = (self.stoich_anode - self.stoich_0)*hydrogen_consumption_mol_s    # recirculated hydrogen; mol/s

        nitrogen_recirculated_mol_s = hydrogen_recirculated_mol_s/recirculation_ratio

        return hydrogen_recirculated_mol_s, nitrogen_recirculated_mol_s
    
    def calculate_BoP_pressure_drop(self):
        """
        Calculate the pressure drop across the BoP components in the recirculation loop.
        """

        # # TODO: refactor as this a largely copy-paste from calculate_power
        # recirculation_ratio = 70/30
        # hydrogen_recirculated_mol_s, nitrogen_recirculated_mol_s = self.calculate_flows_fixed_recirculation_ratio(recirculation_ratio)
        # reci_total_flow_mol_s = hydrogen_recirculated_mol_s + nitrogen_recirculated_mol_s

        # # Ideal gas law to calculate the total flow rate
        # temperature_out_K = self.calculate_outlet_temperature()
        # reci_total_flow_m3_s = reci_total_flow_mol_s*self.params_physics.ideal_gas_constant*temperature_out_K/self.pressure_out_Pa # expectation: \dot{m} = 15...20 g/s (!) (@450 cells, 600 Amps, 70/30 ratio at stack outlet)

        # pressure_drop_coefficient = self.nominal_BoP_pressure_drop / (self.nominal_flow_m3_s**2)
        # pressure_drop_Pa = pressure_drop_coefficient * reci_total_flow_m3_s**2

        # Constant pressure drop assumed since, for whatever reason, the shit above doesn't give meaningful results :-(
        pressure_drop_Pa = self.nominal_BoP_pressure_drop

        return pressure_drop_Pa
    
    def calculate_mass(self)->dict:
        """
        Calculate predicted mass of the pump utilizing the mass_by_power_kg_kW dict of the class.
        
        Returns:
        - result: A dictionary containing:
            - "mean": Pump mass in kg based on the mean value of mass_by_power_kg_kW.
            - "sd": Pump mass in kg based on the standard deviation of mass_by_power_kg_kW.


        """
        pump_el_power_W = self.calculate_power()
        pump_mass_mean_kg = self.mass_by_power_kg_kW["mean"] * pump_el_power_W / 1000
        pump_mass_sd_kg = self.mass_by_power_kg_kW["sd"] * pump_el_power_W / 1000
        return {
        "mean": pump_mass_mean_kg,
        "sd": pump_mass_sd_kg
        }
 
# %% Example Usage:
mass_estimator = Mass_Parameters()

R1 = Recirculation_Pump(mass_estimator, current_A=200,temperature_in_K=343.15, pressure_in_Pa=2.1*1e5, pressure_out_Pa=2.5*1e5, n_cell=455,
                        cell_area_m2=300*1e-4, stoich_anode = 2.4)

R2 = Recirculation_Pump(mass_estimator, current_A=200,temperature_in_K=343.15, pressure_in_Pa=2.1*1e5, pressure_out_Pa=2.5*1e5, n_cell=455,
                        cell_area_m2=300*1e-4, stoich_anode = 2.4, fixed_recirculation_ratio=70/30)

# Calculate electrical power
electrical_power_W_smart = R1.calculate_power()
electrical_power_W_fixed_ratio = R2.calculate_power()

# Calculate mass
pump_mass = R1.calculate_mass()