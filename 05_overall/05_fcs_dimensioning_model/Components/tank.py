#import CoolProp.CoolProp as CP
#from parameters import Physical_Parameters

class Tank:
    """
    A class to model a H2-Tank
    """

    def __init__(self, massfraction=0.5, H2_mass_kg=0, fixed_mass=10, pressure_bar=5*1e5):
        """
        Initialize the tank. 
        """
        
        self.massfraction
        self.H2_mass_kg
        self.pressure_bar
        self.fixed_mass_kg

    def calculate_mass(self)->float:
        """
        Estimate the total mass of the Tank, 
        which consists of H2 mass, 
        mass of the the tank hull (massfraction*H2mass) and 
        fixed_mass like valves etc.
        """
        tank_mass_kg = self.H2_mass_kg + self.massfraction * self.H2_mass_kg + self.fixed_mass_kg  
        
        return tank_mass_kg