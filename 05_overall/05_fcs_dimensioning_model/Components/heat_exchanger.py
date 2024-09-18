import CoolProp.CoolProp as CP

class HeatExchanger:
    """
    A class to model the basic physics of a heat exchanger. 
    This class will later be used as superclass for multiple heatexchanger types.
    """
    
    def __init__(self, efficiency = 1.0, 
                 primary_fluid = "Air", primary_mdot_in_kg_s = 0, primary_T_in_K = 293.15, primary_T_out_K = 293.15, primary_p_in_Pa = 101325,
                 coolant_fluid = "Water", coolant_mdot_in_kg_s = 0, coolant_T_in_K = 0, coolant_T_out_K = 0, coolant_p_in_Pa = 101325,
                 ALLOWED_FLUIDS = ['Water', 'Air', 'MEG', 'H2']):
        
        self.efficiency = efficiency
        #primary fluid or working fluid
        self.primary_fluid = primary_fluid
        self.primary_mdot_in_kg_s = primary_mdot_in_kg_s
        self.primary_T_in_K = primary_T_in_K
        self.primary_T_out_K = primary_T_out_K
        self.primary_p_in_Pa = primary_p_in_Pa  
        self.primary_p_out_Pa = None  
        
        #cooling fluid
        self.coolant_fluid  = coolant_fluid 
        self.coolant_mdot_in_kg_s = coolant_mdot_in_kg_s
        self.coolant_T_in_K = coolant_T_in_K
        self.coolant_T_out_K = None
        self.coolant_p_in_Pa = coolant_p_in_Pa
        self.coolant_p_out_Pa = None  
        self.ALLOWED_FLUIDS = ALLOWED_FLUIDS

        #Check the entered *_fluid strings to match the predefined Fluids for Heat Exchangers
        for fluid in [primary_fluid,coolant_fluid]:
            if fluid not in ALLOWED_FLUIDS:
                raise ValueError(f"Fluid '{fluid}' is not allowed. Choose from: {', '.join(ALLOWED_FLUIDS)}.")
               
    def calculate_specific_heat(self,T_in_K,p_in_Pa,fluid) -> float:
        """
        Calculate the specific heat capacity of the primary_fluid at a given temperature using CoolProp.
        
        primary_fluid: The fluid (string)
        temperature: Temperature (K)
        Specific heat capacity (J/kg.K)
        """
        c_p = CP.PropsSI('C', 'T', T_in_K, 'P', p_in_Pa, fluid)
        return  c_p
          
    def calculate_Qdot(self) -> float:
        c_p = self.calculate_specific_heat(self.primary_T_in_K, self.primary_p_in_Pa, self.primary_fluid)
        Qdot_W = c_p * self.primary_mdot_in_kg_s * (self.primary_T_in_K - self.primary_T_out_K) #primary fluid
        #Qdot = c_p * self.secondary_mdot_in_kg_s * (self.secondary_T_in_K - self.secondary_fluid_T_out_K) #secondary fluid
        return Qdot_W/1000 #to convert from W to kW
    
    def calculate_coolant_T_out(self) -> float:
        """
        Calculate the increase in coolant temperature depending on the heat flux from the primary fluid.
        This is only valid if we assume that all of the heat in transfered perfectly into the coolant.

        """
        c_p_coolant = self.calculate_specific_heat(self.coolant_T_in_K, self.coolant_p_in_Pa, self.coolant_fluid)
        Q_dot_primary = self.calculate_Qdot()
        coolant_T_out_K = self.coolant_T_in_K + (Q_dot_primary/c_p_coolant * self.coolant_mdot_in_kg_s)
        return coolant_T_out_K
                   
class Intercooler(HeatExchanger):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
    #T_in , T_out, mdot, primary
    #TODO: Bonus: wie viel Wärmer wird das Kühlmittel durch den Intercooler
 
class Radiatior(HeatExchanger):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        
class Evaporator(HeatExchanger):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
    # T_Tank, T_out, massflow , primary



      
# %% Example usage of teh code:

# Create an instance of Intercooler
intercooler = Intercooler(
    efficiency=0.9,
    primary_fluid="Water",
    primary_mdot_in_kg_s=2.0,
    primary_T_in_K=350.0,
    primary_T_out_K=300.0,
    primary_p_in_Pa=200000,
    coolant_mdot_in_kg_s=0.5,
    coolant_T_in_K=281.0
)

# Calculate specific heat
specific_heat = intercooler.calculate_specific_heat(intercooler.primary_T_in_K,intercooler.primary_p_in_Pa,intercooler.primary_fluid)
print(f"Specific Heat Capacity: {specific_heat:.2f} J/kg.K")

# Calculate heat transfer rate (Qdot)
Q_dot = intercooler.calculate_Qdot()
print(f"Heat Transfer Rate (Qdot): {Q_dot:.2f} W")

t_out_coolant = intercooler.calculate_coolant_T_out()
print(t_out_coolant)

    