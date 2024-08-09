import CoolProp.CoolProp as CP

class Coolant_Pump:
    """
    A class to model a pump with methods to calculate:
        power, coolant state, and volume flow.
    """

    def __init__(self, isentropic_efficiency=0.75, electrical_efficiency=0.95, head_Pa=0.0, coolant_flow_kg_s=0.0):
        """
        Initialize the pump with a given efficiency and operating conditions.

        :param isentropic_efficiency: Efficiency of the pump (default is 0.75)
        :param electrical_efficiency: Electrical efficiency of the pump (default is 0.95)
        :param head_Pa: Pump head in [Pascals] (default is 0.0)
        :param coolant_flow_kg_s: Coolant flow rate in [kg/s] (default is 0.0)
        """

        self.isentropic_efficiency = isentropic_efficiency
        self.electrical_efficiency = electrical_efficiency
        self.head_Pa = head_Pa
        self.coolant_flow_kg_s = coolant_flow_kg_s

    def calculate_power(self) -> float:
        """
        Calculate the power consumed by the pump based on the pump head and coolant flow rate.

        :return: Electrical power consumed by the pump in [W]
        """
        
        pump_shaft_power_W = self.head_Pa * self.coolant_flow_kg_s / self.isentropic_efficiency
        pump_electrical_power_W = pump_shaft_power_W / self.electrical_efficiency

        return pump_electrical_power_W
    
    def calculate_weight(self)->float:
        #TODO:
        #Do weight estimation here.
        # Placeholder implementation, update with actual logic
        return None

# %% Example usage:

    
coolant_pump = Coolant_Pump(isentropic_efficiency=0.75, electrical_efficiency=0.95, pump_head_Pa=2e7, coolant_flow_kg_s=3.0)
coolant_pump_power_W = coolant_pump.calculate_power()

