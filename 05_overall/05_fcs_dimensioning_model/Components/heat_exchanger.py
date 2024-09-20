import CoolProp.CoolProp as CP

class HeatExchanger:
    """
    A class to model the basic physics of a heat exchanger. 
    This class will later be used as a superclass for multiple heat exchanger types.
    """
    
    def __init__(self, efficiency = 1.0, 
                 primary_fluid = "Air", primary_mdot_in_kg_s = 0, primary_T_in_K = 293.15, primary_T_out_K = 293.15, primary_p_in_Pa = 101325,
                 coolant_fluid = "Water", coolant_mdot_in_kg_s = 0, coolant_T_in_K = 0, coolant_T_out_K = 0, coolant_p_in_Pa = 101325,
                 ALLOWED_FLUIDS = ['Water', 'Air', 'MEG', 'H2']):
        
        self.efficiency = efficiency #TODO use it or kill it 
        # primary fluid or working fluid
        self.primary_fluid = primary_fluid
        self.primary_mdot_in_kg_s = primary_mdot_in_kg_s
        self.primary_T_in_K = primary_T_in_K
        self.primary_T_out_K = primary_T_out_K
        self.primary_p_in_Pa = primary_p_in_Pa  
        self.primary_p_out_Pa = None  
        
        # coolant fluid
        self.coolant_fluid  = coolant_fluid 
        self.coolant_mdot_in_kg_s = coolant_mdot_in_kg_s
        self.coolant_T_in_K = coolant_T_in_K
        self.coolant_T_out_K = None
        self.coolant_p_in_Pa = coolant_p_in_Pa
        self.coolant_p_out_Pa = None  
        self.ALLOWED_FLUIDS = ALLOWED_FLUIDS

        # Check the entered *_fluid strings to match the predefined Fluids for Heat Exchangers
        for fluid in [primary_fluid, coolant_fluid]:
            if fluid not in ALLOWED_FLUIDS:
                raise ValueError(f"Fluid '{fluid}' is not allowed. Choose from: {', '.join(ALLOWED_FLUIDS)}.")
    
    def calculate_specific_heat(self, T_in_K, p_in_Pa, fluid) -> float:
        """
        Calculate the specific heat capacity of a fluid at a given temperature using CoolProp.
        
        Args:
            T_in_K: float of Temperature in Kelvin.
            p_in_Pa: float of Pressure in Pascals.
            fluid: String of a CP fluid type.
            
        Returns:
            Specific heat capacity (J/kg.K)
        """
        return CP.PropsSI('C', 'T', T_in_K, 'P', p_in_Pa, fluid)

    def calculate_heat_flux(self, fluid_type="primary") -> float:
        """
        Calculate the heat flux (Qdot) for the specified fluid (primary or coolant).
        
        Args:
            fluid_type: Either "primary" or "coolant" to specify which fluid to calculate for.
            
        Returns:
            Qdot in W.
        """
        if fluid_type == "primary":
            c_p = self.calculate_specific_heat(self.primary_T_in_K, self.primary_p_in_Pa, self.primary_fluid)
            Qdot_W = c_p * self.primary_mdot_in_kg_s * (self.primary_T_in_K - self.primary_T_out_K)
        elif fluid_type == "coolant":
            c_p = self.calculate_specific_heat(self.coolant_T_in_K, self.coolant_p_in_Pa, self.coolant_fluid)
            Qdot_W = c_p * self.coolant_mdot_in_kg_s * (self.coolant_T_out_K - self.coolant_T_in_K)
        else:
            raise ValueError("Invalid fluid_type. Choose either 'primary' or 'coolant'.")
        
        return Qdot_W

    def calculate_coolant_T_out(self) -> float:
        """
        Calculate the increase in coolant temperature depending on the heat flux from the primary fluid.
        This is only valid if we assume that all of the heat is transferred perfectly into the coolant.
        """
        c_p_coolant = self.calculate_specific_heat(self.coolant_T_in_K, self.coolant_p_in_Pa, self.coolant_fluid)
        Q_dot_primary = self.calculate_heat_flux("primary")
        coolant_T_out_K = self.coolant_T_in_K + (Q_dot_primary / (c_p_coolant * self.coolant_mdot_in_kg_s))
        
        return coolant_T_out_K
                   
class Intercooler(HeatExchanger):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
    #We know: T_in , T_out, mdot, primary
 
class Radiatior(HeatExchanger):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        #For the moment the Radiator is not needed as a component its Qdot will be calculated 
        
class Evaporator(HeatExchanger):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
    
    #OVERWRITE: due to mean cp value we need to overwrite this function
    def calculate_heat_flux(self, fluid_type="primary", mean_cp_H2=14500, dH_V=446000) -> float:
        """
        Calculate the heat flux (Qdot) for the specified fluid (primary or coolant).
        
        Args:
            fluid_type: Either "primary" or "coolant" to specify which fluid to calculate for.
            
        Returns:
            Qdot in W.
        """
        
        if fluid_type == "primary":
            c_p = mean_cp_H2 # TODO: dont use a mean value if possible
            #Due to Phase change from liquid to gass the Qdot has a additional term (Verdapfungsenthalpie)
            Qdot_W = c_p * self.primary_mdot_in_kg_s * (self.primary_T_in_K - self.primary_T_out_K) + self.primary_mdot_in_kg_s * dH_V
        elif fluid_type == "coolant":
            c_p = self.calculate_specific_heat(self.coolant_T_in_K, self.coolant_p_in_Pa, self.coolant_fluid)
            Qdot_W = c_p * self.coolant_mdot_in_kg_s * (self.coolant_T_out_K - self.coolant_T_in_K)
        else:
            raise ValueError("Invalid fluid_type. Choose either 'primary' or 'coolant'.")
        
        return Qdot_W
    #We know: T_Tank, T_out, massflow , primary
    
# %% Example usage of the code:

# # Create an instance of Intercooler
# intercooler = Intercooler(
#     efficiency=0.9,
#     primary_fluid="Water",
#     coolant_fluid="Air",
#     primary_mdot_in_kg_s=2.0,
#     primary_T_in_K=350.0,
#     primary_T_out_K=300.0,
#     primary_p_in_Pa=200000,
#     coolant_mdot_in_kg_s=0.5,
#     coolant_T_in_K=281.0
# )

# # Calculate specific heat
# specific_heat = intercooler.calculate_specific_heat(intercooler.primary_T_in_K,intercooler.primary_p_in_Pa,intercooler.primary_fluid)
# print(f"Specific Heat Capacity: {specific_heat:.2f} J/kg.K")

# # Calculate heatflux 
# Q_dot = intercooler.calculate_heat_flux("primary")
# print(f"Heat Transfer Rate (Qdot): {Q_dot:.2f} kW")


# intercooler.coolant_T_out_K = intercooler.calculate_coolant_T_out()
# print(intercooler.coolant_T_out_K)


# Q_dot = intercooler.calculate_heat_flux("coolant")
# print(f"Heat Transfer Rate (Qdot): {Q_dot:.2f} kW")

#%%
    