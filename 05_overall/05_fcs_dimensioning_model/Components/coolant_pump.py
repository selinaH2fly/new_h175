import CoolProp.CoolProp as CP

class Coolant_Pump:
    """
    A class to model a pump with methods to calculate:
        power, coolant state, and volume flow.
    """

    def __init__(self, isentropic_efficiency=0.75, electric_efficiency=0.95, head_Pa=0.0, coolant_flow_m3_s=0.0, mass_by_power_kg_kW={"mean": 1.0, "sd": 0.1}):
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
        self.mass_by_power_kg_kW = mass_by_power_kg_kW

    def calculate_power(self) -> float:
        """
        Calculate the power consumed by the pump based on the pump head and coolant flow rate.

        :return: Electrical power consumed by the pump in [W]
        """
        
        pump_shaft_power_W = self.head_Pa * self.coolant_flow_m3_s / self.isentropic_efficiency
        pump_electrical_power_W = pump_shaft_power_W / self.electric_efficiency

        return float(pump_electrical_power_W)
    
    def calculate_mass(self)->dict:
        """
        Calculate predicted mass of the pump utilizing the mass_by_power_kg_kW dict of the class
        
        Returns:
        - result: A dictionary containing:
            - "mean": Pump mass in kg based on the mean value of mass_by_power_kg_kW.
            - "sd": Pump mass in kg based on the standard deviation of mass_by_power_kg_kW.

        """
        pump_el_power_W = self.calculate_power()
        pump_mass_mean_kg = self.mass_by_power_kg_kW["mean"] * pump_el_power_W / 1000
        pump_mass_sd_kg = self.mass_by_power_kg_kW["sd"] * pump_el_power_W / 1000
        return {
        "mean": pump_mass_mean_kg,
        "sd": pump_mass_sd_kg
        }
        pass #TODO do mass calc if needed

# %% Example USsage:

    
coolant_pump = Coolant_Pump(isentropic_efficiency=0.75, electric_efficiency=0.95, head_Pa=2e7, coolant_flow_m3_s=0.5)
coolant_pump_power_W = coolant_pump.calculate_power()
coolant_pump_mass_kg = coolant_pump.calculate_mass()