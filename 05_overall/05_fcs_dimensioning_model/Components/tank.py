#import CoolProp.CoolProp as CP
#from parameters import Physical_Parameters

class Tank:
    """
    A class to model a H2-Tank
    """

    def __init__(self, massfraction=0.5, H2_mass_kg=0, fixed_mass_kg=10, pressure_bar=5*1e5):
        """
        Initialize the tank. 
        """
        
        self.massfraction =  massfraction
        self.H2_mass_kg = H2_mass_kg
        self.pressure_bar = pressure_bar
        self.fixed_mass_kg = fixed_mass_kg
        self.tank_wet_mass_kg = None
        self.tank_dry_mass_kg = None
        
    def calculate_H2_mass(self, flight_duration_h, H2_supply_rate_g_s)->float:
        flight_duration_s = flight_duration_h * 3600
        self.H2_mass_kg = (flight_duration_s * H2_supply_rate_g_s)/1000 
        return self.H2_mass_kg    
        
        
    def calculate_mass(self)->float:
        """
        Estimate the total mass of the Tank, 
        which consists of H2 mass, 
        mass of the the tank hull (massfraction*H2mass) and 
        fixed_mass like valves etc.
        
        returns: dry mass [kg], wet mass [kg]
        """
        tank_dry_mass_kg = self.massfraction * self.H2_mass_kg + self.fixed_mass_kg
        
        tank_wet_mass_kg = self.H2_mass_kg + tank_dry_mass_kg
        
        self.tank_dry_mass_kg = tank_dry_mass_kg
        self.tank_wet_mass_kg = tank_wet_mass_kg
        
        return tank_dry_mass_kg, tank_wet_mass_kg