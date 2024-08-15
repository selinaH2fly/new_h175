import CoolProp.CoolProp as CP
import math

class Recirculation_Pump:
    
    def __init__(self, params_physics, isentropic_efficiency=0.75, electric_efficiency=0.95, 
                 current_A=100, temperature_in_K=293.15, pressure_in_Pa=1e5, pressure_out_Pa=1e5, n_cell=455, stoich_anode = 1.5): 
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
        self.stoich_anode = stoich_anode
        self.stoich_0 = 1.05                    # stoich_0 1.02-1.05 "lost als H2 aus system = ~5%" TODO: rather specify the recirculation ratio!
        self.C_H2 = 1                           # H2 concentration in tank
    
    def calculate_power(self)->float:

        temperature_out_K = self.calculate_outlet_temperature()

        mass_flow_hydrogen_g_s, mass_flow_nitrogen_g_s = self.calculate_mass_flows()
        mass_flow_reci_g_s = mass_flow_hydrogen_g_s + mass_flow_nitrogen_g_s  # total recirculated mass flow; expectation: 15...20 g/s (@450 cells, 600 Amps, 70/30 ratio at stack outlet)

        mass_fraction_hydrogen = mass_flow_hydrogen_g_s/(mass_flow_hydrogen_g_s + mass_flow_nitrogen_g_s)
        mass_fraction_nitrogen = mass_flow_nitrogen_g_s/(mass_flow_hydrogen_g_s + mass_flow_nitrogen_g_s)

        cp_hydrogen_J_kgK = CP.PropsSI("C", "P", (self.pressure_in_Pa), "T", (self.temperature_in_K), "Hydrogen")       # specific heat hydrogen
        cp_nitrogen_J_kgK = CP.PropsSI("C", "P", (self.pressure_in_Pa), "T", (self.temperature_in_K), "Nitrogen")       # specific heat nitrogen
        cp_mix_J_kgK = cp_hydrogen_J_kgK*mass_fraction_hydrogen + cp_nitrogen_J_kgK*mass_fraction_nitrogen

        reci_shaft_power_W = cp_mix_J_kgK*mass_flow_reci_g_s/1000*(temperature_out_K - self.temperature_in_K)
        reci_isentropic_power_W = reci_shaft_power_W/self.isentropic_efficiency
        reci_electric_power_W = reci_isentropic_power_W/self.electric_efficiency

        return reci_electric_power_W
        
    def calculate_mass_flows(self): 
        m_H2_stoich = self.current_A*2.02*self.n_cell/(2*96485)                                                  #consumed(stoich) hydrogen in stack; massflow consumed for given current; g/s
        m_N2_diff = (1.2578 + math.log(self.current_A) - 2.6091)*28.02*300*self.n_cell*(10**(-9))                #diffusion flow of nitrogen in stack; Voss' magic formula
        m_H2_stack = self.stoich_anode*m_H2_stoich                                                            #hydrogen supply in stack
        m_H2_R = (self.stoich_anode-self.stoich_0)*m_H2_stoich                                                     #hydrogen out from stack = recirculated hydrogen
        r = m_N2_diff*2.02/(m_H2_stoich*28.02)                                                       #molar rate of stack flows ("Stoffmengenverhältnis")
        C_H2_in = self.C_H2*(self.stoich_anode*(self.stoich_0-1))/(self.stoich_0*(self.stoich_anode-1)+self.C_H2*(self.stoich_anode-self.stoich_0)*(r-1))   #stack inlet H2 concentration
        C_H2_out = C_H2_in*(self.stoich_anode - 1)/(self.stoich_anode + C_H2_in*(r-1))                                 #stack outlet H2 concentration; 0.6 .. 0.7 (Voss' expecation)
        m_N2_R = (m_H2_R*28.02/2.02) * ((1-C_H2_out)/C_H2_out)                                       #recirculated nitrogen mass flow

        return m_H2_R, m_N2_R
    
        
    def calculate_outlet_temperature(self):

        pressure_ratio = self.pressure_out_Pa/self.pressure_in_Pa
        kappa = self.params_physics.specific_heat_ratio # specific heat ratio for H2 and N2 almost equal to air (i.e., 1.4) TODO: snack from coolprop
        isentropic_outlet_temperature_K = ((self.temperature_in_K) * pressure_ratio**((kappa-1)/kappa))

        return isentropic_outlet_temperature_K
    
 
# %% Example usage:
import parameters   
params_physics = parameters.Physical_Parameters() 

R1 = Recirculation_Pump(params_physics, current_A=200,temperature_in_K=343.15, pressure_in_Pa=2.1*1e5, pressure_out_Pa=2.5*1e5, n_cell=300, stoich_anode = 2.4)

#electrical power
power_el = R1.calculate_power()
