# -*- coding: utf-8 -*-
"""
Created on Mon Aug  5 10:51:37 2024

@author: wenzel.gassner
"""

import CoolProp.CoolProp as CP
import math

class Recirculation_Pump:
    
    def __init__(self, isentropic_efficiency=0.75, pump_efficiency=0.75, 
                 current=1, temperature_in=0.0, pressure_in=0.0, pressure_out=0.0, n_cell=0.0, stoich_anode = 3.0): # pump eher 0.60...? 
        """
        Initialize the recirculation pump with a given efficiency and operating conditions.

        Parameters
        ----------
        isentropic_efficiency : TYPE, optional
            DESCRIPTION. The default is 0.75.
        pump_efficiency : TYPE, optional
            DESCRIPTION. The default is 0.75.
        current : TYPE, optional
            DESCRIPTION. The default is 0.0.
        temperature : TYPE, optional
            DESCRIPTION. The default is 0.0.
        pressure_in : TYPE, optional
            DESCRIPTION. The default is 0.0.
        pressure_out : TYPE, optional
            DESCRIPTION. The default is 0.0.
        n_cell : TYPE, optional
            DESCRIPTION. The default is 0.0.
        stoich_anode : TYPE, optional
            Anoden lambda. The default is 3.0.
        stoich_0 : TYPE, optional
            Stack lambda. (reziculation) The sould be between 1.02 and 1.05
            
        """
        
        # TODO: Use SI units for all parameters!
        self.isentropic_efficiency = isentropic_efficiency
        self.pump_efficiency = pump_efficiency
        self.current = current                  # [A]
        self.temperature_in = temperature_in    # [°C]
        self.pressure_in = pressure_in          # [bar(a)]
        self.pressure_out = pressure_out        # [bar(a)]
        self.n_cell = n_cell                    # [/]
        self.stoich_anode = stoich_anode
        self.stoich_0=1.05                      # stoich_0 1.02-1.05 "lost als H2 aus system = ~5%"
        self.C_H2 = 1
    
    def calculate_power(self)->float:#, T_in, p_in, p_out, stoich_0, stoich_anode, current, C_H2, n_cell):
        T_out = self.temp_out()
        Cp = self.specific_heat()
        mass_flow_gr_s = self.mass_flows()[2]

        P_shaft = Cp*mass_flow_gr_s*(T_out-self.temperature_in)/1000
        P_isentropic = P_shaft/self.isentropic_efficiency
        P_el = P_isentropic/self.pump_efficiency

        return P_el # kW?
        
    def mass_flows(self): 
        m_H2_stoich = self.current*2.02*self.n_cell/(2*96485)                                                  #consumed(stoich) hydrogen in stack
        m_N2_diff = (1.2578 + math.log(self.current) - 2.6091)*28.02*300*self.n_cell*(10**(-9))                #diffusion flow of nitrogen in stack
        m_H2_stack = self.stoich_anode*m_H2_stoich                                                            #hydrogen supply in stack
        m_H2_R = (self.stoich_anode-self.stoich_0)*m_H2_stoich                                                     #hydrogen out from stack = recirculated hydrogen
        r = m_N2_diff*2.02/(m_H2_stoich*28.02)                                                       #molar rate of stack flows
        C_H2_in = self.C_H2*(self.stoich_anode*(self.stoich_0-1))/(self.stoich_0*(self.stoich_anode-1)+self.C_H2*(self.stoich_anode-self.stoich_0)*(r-1))   #stack inlet H2 concentration
        C_H2_out = C_H2_in*(self.stoich_anode - 1)/(self.stoich_anode + C_H2_in*(r-1))                                 #stack outlet H2 concentration
        m_N2_R = (m_H2_R*28.02/2.02) * ((1-C_H2_out)/C_H2_out)                                       #recirculated nitrogen mass flow
        m_R = m_N2_R + m_H2_R                                                                        #total recirculated mass flow 
        return m_H2_R, m_N2_R , m_R

    
    def mass_fractions(self):
        m_H2 , m_N2, m_tot = self.mass_flows()  
        w_H2 = m_H2/m_tot                                                        #hydrogen mass fraction
        w_N2 = m_N2/m_tot                                                        #nitrogen mass fraction
        return w_H2, w_N2

    
    def temp_out(self):
        e = self.pressure_out/self.pressure_in                                                        #pressure ratio
        k = 1.4                                                           #k for H2 and N2 is almost equal to k for Air
        T2 = ((self.temperature_in+273) * e**((k-1)/k)) - 273                                #tempearture out from pump
        return T2# isentrop recirculation pump temperature out


    def specific_heat(self):
        w_H2, w_N2 = self.mass_fractions()
        Cp_H2 = CP.PropsSI("C", "P" , (self.pressure_in*100000), "T", (self.temperature_in+273), "Hydrogen")       #specific heat hydrogen
        Cp_N2 = CP.PropsSI("C", "P" , (self.pressure_in*100000), "T", (self.temperature_in+273), "Nitrogen")       #specific heat nitrogen
        Cp_mix = Cp_H2*w_H2 + Cp_N2*w_N2                                            #specific heat gas mixtrue
        return Cp_mix
 
# %% Example usage:
      
C1 = Recirculation_Pump(current=200,temperature_in=65, pressure_in=2.1, pressure_out=2.5,n_cell=300, stoich_anode = 2.4)

#electrical power
power_el = C1.calculate_power()
