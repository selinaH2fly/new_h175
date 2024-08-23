class Radiator:
    """
    A class to model a liquid/air radiator
    """

    def __init__(self, coolant_flow_m3_s=0.0, nominal_pressure_drop_Pa=500*100, nominal_coolant_flow_m3_s=0.0, weight_by_power=1, thermal_power_W=1000):
        """
        Initialize the radiator with a given pressure drop and coolant flow rate.

        :param coolant_flow_m3_s: Coolant flow rate in [m3/s]
        :param nominal_pressure_drop_Pa: Nominal pressure drop across the radiator in [Pa]
        :param nominal_coolant_flow_m3_s: Coolant flow rate in [m3/s]
        """

        self.coolant_flow_m3_s = coolant_flow_m3_s
        self.nominal_pressure_drop_Pa = nominal_pressure_drop_Pa
        self.nominal_coolant_flow_m3_s = nominal_coolant_flow_m3_s
        self.weight_by_power = weight_by_power
        self.thermal_power_W = thermal_power_W

    def calculate_pressure_drop(self)->float:
        """
        Calculate the pressure drop across the radiator for a given coolant flow rate.
        The "model" is a simple quadratic relationship between pressure drop and coolant flow rate.

        :return: Pressure drop across the radiator in [Pa]
        """

        pressure_drop_coefficient = self.nominal_pressure_drop_Pa / (self.nominal_coolant_flow_m3_s**2)
        pressure_drop_Pa = pressure_drop_coefficient * self.coolant_flow_m3_s**2

        return pressure_drop_Pa

    def calculate_weight(self)->float:
        """
        Calculate predicted mass of the radiator.
        
        Args:
        - weight_by_power: The ratio of mass to thermal power removed in kg/kW.
        - thermal_power_W: Required thermal power the radiator must remove in W.
        
        Returns:
        - radiator_weight: The mass in kg.

        """
        radiator_weight = self.weight_by_power * self.thermal_power_W / 1000
        return radiator_weight

# %% Example Usage:

radiator = Radiator(nominal_pressure_drop_Pa=0.3*1e5, nominal_coolant_flow_m3_s=300/(1000*60))

radiator.coolant_flow_m3_s = 100/(1000*60)  # 100 l/min in m3/s
pressure_drop_Pa = radiator.calculate_pressure_drop()
radiator_mass = radiator.calculate_weight()

