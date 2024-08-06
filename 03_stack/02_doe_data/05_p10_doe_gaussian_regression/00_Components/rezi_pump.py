# -*- coding: utf-8 -*-
"""
Created on Mon Aug  5 10:51:37 2024

@author: wenzel.gassner
"""

import CoolProp.CoolProp as CP
import math

class Rezi_Pump:

    def __init__(self, isentropic_efficiency=0.75, pump_efficiency=0.75):
        self.isentropic_efficiency = isentropic_efficiency
        self.pump_efficiency = pump_efficiency
    

    
    def compressor_power(self, T_in, p_in, p_out, stoich_0, stoich_1, current, C_H2, n_cell):
        T_out = self.temp_out(T_in, p_in, p_out)
        Cp = self.specific_heat(T_in, p_in)
        mass_flow_gr_s = self.mass_flows(stoich_0, stoich_1, current, C_H2, n_cell)[2]

        P_shaft = Cp*mass_flow_gr_s*(T_out-T_in)/1000
        P_isentropic = P_shaft/self.isentropic_efficiency
        P_el = P_isentropic/self.pump_efficiency

        return P_el
        
    
    def mass_flows(self, stoich_0, stoich_1, current, C_H2, n_cell):
        m_H2_stoich = current*2.02*n_cell/(2*96485)                                                  #consumed(stoich) hydrogen in stack
        m_N2_diff = (1.2578 + math.log(current) - 2.6091)*28.02*300*n_cell*(10**(-9))                #diffusion flow of nitrogen in stack
        m_H2_stack = stoich_1*m_H2_stoich                                                            #hydrogen supply in stack
        m_H2_R = (stoich_1-stoich_0)*m_H2_stoich                                                     #hydrogen out from stack = recirculated hydrogen
        r = m_N2_diff*2.02/(m_H2_stoich*28.02)                                                       #molar rate of stack flows
        C_H2_in = C_H2*(stoich_1*(stoich_0-1))/(stoich_0*(stoich_1-1)+C_H2*(stoich_1-stoich_0)*(r-1))   #stack inlet H2 concentration
        C_H2_out = C_H2_in*(stoich_1 - 1)/(stoich_1 + C_H2_in*(r-1))                                 #stack outlet H2 concentration
        m_N2_R = (m_H2_R*28.02/2.02) * ((1-C_H2_out)/C_H2_out)                                       #recirculated nitrogen mass flow
        m_R = m_N2_R + m_H2_R                                                                        #total recirculated mass flow 
        return m_H2_R, m_N2_R , m_R

    
    def mass_fractions(self):
        m_H2 , m_N2, m_tot = self.mass_flows(stoich_0, stoich_1, current, C_H2, n_cell)  
        w_H2 = m_H2/m_tot                                                        #hydrogen mass fraction
        w_N2 = m_N2/m_tot                                                        #nitrogen mass fraction
        return w_H2, w_N2

    
    def temp_out(self, T1, p1, p2):
        e = p2/p1                                                         #pressure ratio
        k = 1.4                                                           #k for H2 and N2 is almost equal to k for Air
        T2 = ((T1+273) * e**((k-1)/k)) - 273                                #tempearture out from compressor
        return T2


    def specific_heat(self, T1, p1):
        w_H2, w_N2 = self.mass_fractions()
        Cp_H2 = CP.PropsSI("C", "P" , (p1*100000), "T", (T1+273), "Hydrogen")       #specific heat hydrogen
        Cp_N2 = CP.PropsSI("C", "P" , (p1*100000), "T", (T1+273), "Nitrogen")       #specific heat nitrogen
        Cp_mix = Cp_H2*w_H2 + Cp_N2*w_N2                                            #specific heat gas mixtrue
        return Cp_mix
 
# %% Example usage:
      
C1 = Rezi_Pump()

#define parameters
n_cell = 450
current = 600
stoich_0 = 1.05
stoich_1 = 2
C_H2 = 0.75
T_in = 65  
p_in = 2.48
p_out = 2.6

#compositions (only for print)
m_H2_stoich = current*2.02*n_cell/(2*96485)                         
m_N2_diff = (1.2578 + math.log(current) - 2.6091)*28.02*300*n_cell*(10**(-9))
r = m_N2_diff*2.02/(m_H2_stoich*28.02)
C_H2_in = C_H2 * (stoich_1*(stoich_0-1))/(stoich_0*(stoich_1-1)+C_H2*(stoich_1-stoich_0)*(r-1))
w_H2, w_N2 = C1.mass_fractions()
C_H2_out = w_H2/(w_H2 + w_N2*(2.02/28.02))
C_N2_out = 1-C_H2_out

#electrical power
power_el = C1.compressor_power(T_in, p_in, p_out, stoich_0, stoich_1, current, C_H2, n_cell)/1000


print("Operating Current:" , current, "A")
print("Tank Molar Composition:", C_H2*100,"% H2 and", round((1-C_H2)*100,4),"% N2") 
print("Stack Inlet Molar Composition:", round(C_H2_in*100,4),"% H2 and", round((1-C_H2_in)*100,4),"% N2") 
print("Stack Outlet Molar Composition:", round(C_H2_out*100,4),"% H2 and", round(C_N2_out*100,4),"% N2") 
print("Electrical Power of Recirculation Pump:", round(power_el,4), "kW")