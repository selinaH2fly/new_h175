import CoolProp.CoolProp as CP
import math

class Recirculation_Pump:
    
    def __init__(self, params_physics, isentropic_efficiency=0.75, electric_efficiency=0.95, 
                 current_A=100, temperature_in_K=293.15, pressure_in_Pa=1e5, pressure_out_Pa=1e5,
                 n_cell=455, cell_area_m2=300*1e-4, stoich_anode=1.5, fixed_recirculation_ratio=None): 
        """
        Initialize the recirculation pump with a given efficiency and operating conditions.

       Args:
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
        
        # TODO: Use SI units for all parameters!
        self.params_physics = params_physics
        self.isentropic_efficiency = isentropic_efficiency
        self.electric_efficiency = electric_efficiency
        self.current_A = current_A
        self.temperature_in_K = temperature_in_K
        self.pressure_in_Pa = pressure_in_Pa
        self.pressure_out_Pa = pressure_out_Pa
        self.n_cell = n_cell
        self.cell_area_m2 = cell_area_m2
        self.stoich_anode = stoich_anode
        self.stoich_0 = 1.05                            # stoich_0 1.02-1.05 "lost als H2 aus system = ~5%" TODO: rather specify the recirculation ratio!
        self.hydrogen_concentration_supply = 1          # H2 concentration in tank
        self.fixed_recirculation_ratio = fixed_recirculation_ratio
    
    def calculate_power(self)->float:

        temperature_out_K = self.calculate_outlet_temperature()

        # Calculate flows (either based on fixed recirculation ratio or based on nitrogen and hydrogen flow balances)
        if self.fixed_recirculation_ratio is None:
            hydrogen_recirculated_mol_s, nitrogen_recirculated_mol_s = self.calculate_flows()
        else:
            hydrogen_recirculated_mol_s, nitrogen_recirculated_mol_s = self.calculate_flows_fixed_recirculation_ratio(self.fixed_recirculation_ratio)

        reci_total_flow_mol_s = hydrogen_recirculated_mol_s + nitrogen_recirculated_mol_s

        # Ideal gas law (expectation: \dot{m} = 15...20 g/s (!) (@450 cells, 600 Amps, 70/30 ratio at stack outlet))
        reci_total_flow_m3_s = reci_total_flow_mol_s*self.params_physics.ideal_gas_constant*temperature_out_K/self.pressure_out_Pa

        reci_isentropic_power_W = (self.pressure_out_Pa - self.pressure_in_Pa)*reci_total_flow_m3_s
        reci_shaft_power_W = reci_isentropic_power_W/self.isentropic_efficiency
        reci_electric_power_W = reci_shaft_power_W/self.electric_efficiency

        return reci_electric_power_W
        
    def calculate_flows(self):
        """
        Calculate the mass flows of hydrogen and nitrogen in the recirculation pump based on nitrogen and hydrogen flow balances.
        """

        hydrogen_consumption_mol_s = self.current_A*self.n_cell/(2*self.params_physics.faraday)         # consumed hydrogen in stack; mol/s
        hydrogen_recirculated_mol_s = (self.stoich_anode - self.stoich_0)*hydrogen_consumption_mol_s    # recirculated hydrogen; mol/s

        # Nitrogen diffusion flow in stack; TODO: check the formula as it gives very low values
        nitrogen_diffusion_mol_s = (1.2578 + math.log(self.current_A) - 2.6091)* \
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

        hydrogen_consumption_mol_s = self.current_A*self.n_cell/(2*self.params_physics.faraday)         # consumed hydrogen in stack; mol/s
        hydrogen_recirculated_mol_s = (self.stoich_anode - self.stoich_0)*hydrogen_consumption_mol_s    # recirculated hydrogen; mol/s

        nitrogen_recirculated_mol_s = hydrogen_recirculated_mol_s/recirculation_ratio

        return hydrogen_recirculated_mol_s, nitrogen_recirculated_mol_s
        
    def calculate_outlet_temperature(self):

        pressure_ratio = self.pressure_out_Pa/self.pressure_in_Pa
        kappa = self.params_physics.specific_heat_ratio # specific heat ratio for H2 and N2 almost equal to air (i.e., 1.4) TODO: snack from coolprop
        isentropic_outlet_temperature_K = ((self.temperature_in_K) * pressure_ratio**((kappa-1)/kappa))

        return isentropic_outlet_temperature_K
        
 
# %% Example usage:
import parameters   
params_physics = parameters.Physical_Parameters() 

R1 = Recirculation_Pump(params_physics, current_A=200,temperature_in_K=343.15, pressure_in_Pa=2.1*1e5, pressure_out_Pa=2.5*1e5, n_cell=455,
                        cell_area_m2=300*1e-4, stoich_anode = 2.4)

#electrical power
power_el_smart = R1.calculate_power()