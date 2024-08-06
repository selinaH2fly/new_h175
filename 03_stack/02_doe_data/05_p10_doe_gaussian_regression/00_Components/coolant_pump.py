import CoolProp.CoolProp as CP

class Pump:
    """
    A class to model a pump with methods to calculate:
        power, coolant state, and volume flow.
    """

    def __init__(self, pump_efficiency=0.8, current=0.0, temperature=0.0, pressure_in=0.0, pressure_out=0.0):
        """
        Initialize the pump with a given efficiency and operating conditions.
        :param pump_efficiency: Efficiency of the pump (default is 0.8)
        :param current: Operating current in [Amperes] (default is 0.0)
        :param temperature: Coolant temperature in [Celsius] (default is 0.0)
        :param pressure_in: Inlet pressure in [bara] (default is 0.0)
        :param pressure_out: Outlet pressure in [bara] (default is 0.0)
        """

        self.pump_efficiency = pump_efficiency  #[/]
        self.current = current                  #[A]
        self.temperature = temperature          #[°C]
        self.pressure_in = pressure_in          #[bar(a)]
        self.pressure_out = pressure_out        #[bar(a)]
    
    
    def calculate_power(self) -> float:
        """
        Calculate the pump power based on the current, temperature, and pressures.
        
        :param current: Operating current in [Amperes]
        :param temperature: Coolant temperature in [Celsius]
        :param pressure_in: Inlet pressure in [bara]
        :param pressure_out: Outlet pressure in [bara]
        :return: Power of the pump in [kW]
        """
        coolant_flow = self.calculate_volume_flow()

        # Calculate power based on flow rate, pressure difference, and pump efficiency
        power = coolant_flow * 0.1 * (self.pressure_out - self.pressure_in) / (self.pump_efficiency * 60)

        return power
    
    def calculate_volume_flow(self) -> float:
        """
        Calculate the volume flow rate of the coolant based on the current.
        :param current: Operating current in [Amperes]
        :param temperature: Coolant temperature in [Celsius]
        :param pressure_in: Inlet pressure in [bara]
        :param pressure_out: Outlet pressure in [bara]
        :return: Volume flow rate in [l/min]
        """
        #TODO check where the ref_* are coming from?! --> EES?
        
        ref_temp = self.temperature - self.current / 40  # Reference temperature
        ref_flow = (20 * self.current + 2620) / 43  # Reference flow rate

        # Calculate density of water at reference and operating conditions
        ref_rho = CP.PropsSI("D", "P", self.pressure_out * 100000, "T", (ref_temp + 273), "Water")
        op_rho = CP.PropsSI("D", "P", self.pressure_in * 100000, "T", (self.temperature + 273), "Water")

        # Adjust flow rate based on density ratio
        op_flow = ref_flow * (ref_rho / op_rho)

        return op_flow
    
    def calculate_weight(self)->float:
        #TODO:
        #Do weight estimation here.
        # Placeholder implementation, update with actual logic
        return None

# %% Example usage:

    
pump = Pump(current=500, temperature=25.0, pressure_in=1.0, pressure_out=5.0)
power = pump.calculate_power()
volume_flow = pump.calculate_volume_flow()

