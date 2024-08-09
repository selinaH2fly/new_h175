import CoolProp.CoolProp as CP

class Coolant_Pump:
    """
    A class to model a pump with methods to calculate:
        power, coolant state, and volume flow.
    """

    def __init__(self, pump_efficiency=0.8, pump_head_Pa=0.0, coolant_flow_kg_s=0.0):
        """
        Initialize the pump with a given efficiency and operating conditions.

        :param pump_efficiency: Efficiency of the pump (default is 0.8)
        :param pump_head_Pa: Pump head in [Pascals] (default is 0.0)
        :param coolant_flow_kg_s: Coolant flow rate in [kg/s] (default is 0.0)
        """

        self.pump_efficiency = pump_efficiency
        self.pump_head_Pa = pump_head_Pa
        self.coolant_flow_kg_s = coolant_flow_kg_s

    def calculate_power(self) -> float:
        """
        Calculate the power consumed by the pump based on the pump head and coolant flow rate.

        :return: Power of the pump in [W]
        """
        
        pump_power_W = self.pump_head_Pa * self.coolant_flow_kg_s / self.pump_efficiency

        return pump_power_W
    
    def calculate_weight(self)->float:
        #TODO:
        #Do weight estimation here.
        # Placeholder implementation, update with actual logic
        return None

# %% Example usage:

    
coolant_pump = Coolant_Pump(pump_efficiency=0.8, pump_head_Pa=2e7, coolant_flow_kg_s=3.0)
coolant_pump_power_W = coolant_pump.calculate_power()

