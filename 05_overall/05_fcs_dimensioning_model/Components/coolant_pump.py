import CoolProp.CoolProp as CP

class Coolant_Pump:
    """
    A class to model a pump with methods to calculate:
        power, coolant state, and volume flow.
    """

    def __init__(self, isentropic_efficiency=0.75, electric_efficiency=0.95, head_Pa=0.0, coolant_flow_m3_s=0.0, weight_by_power=1):
        """
        Initialize the pump with a given efficiency and operating conditions.

        :param isentropic_efficiency: Efficiency of the pump (default is 0.75)
        :param electric_efficiency: Electric efficiency of the pump (default is 0.95)
        :param head_Pa: Pump head in [Pascals] (default is 0.0)
        :param coolant_flow_m3_s: Coolant flow rate in [m3/s] (default is 0.0)
        """

        self.isentropic_efficiency = isentropic_efficiency
        self.electric_efficiency = electric_efficiency
        self.head_Pa = head_Pa
        self.coolant_flow_m3_s = coolant_flow_m3_s
        self.weight_by_power = weight_by_power

    def calculate_power(self) -> float:
        """
        Calculate the power consumed by the pump based on the pump head and coolant flow rate.

        :return: Electrical power consumed by the pump in [W]
        """
        
        pump_shaft_power_W = self.head_Pa * self.coolant_flow_m3_s / self.isentropic_efficiency
        pump_electrical_power_W = pump_shaft_power_W / self.electric_efficiency

        return pump_electrical_power_W
    
    def calculate_weight(self)->float:
        """
        Calculate predicted mass of the pump.
        
        Args:
        - weight_by_power: The ratio of mass to electrical power in kg/kW.
        
        Returns:
        - pump_weight: The mass in kg.

        """
        pump_el_power_W = self.calculate_power()
        pump_weight = self.weight_by_power * pump_el_power_W / 1000
        return pump_weight

# %% Example USsage:

    
coolant_pump = Coolant_Pump(isentropic_efficiency=0.75, electric_efficiency=0.95, head_Pa=2e7, coolant_flow_m3_s=0.5)
coolant_pump_power_W = coolant_pump.calculate_power()
coolant_pump_mass = coolant_pump.calculate_weight()


