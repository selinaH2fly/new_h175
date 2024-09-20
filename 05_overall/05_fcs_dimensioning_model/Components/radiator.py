class Radiator:
    """
    A class to model a liquid/air radiator
    """

    def __init__(self, coolant_flow_m3_s=0.0, nominal_pressure_drop_Pa=500*100, nominal_coolant_flow_m3_s=0.0, mass_by_power_kg_kW={"mean": 1.0, "sd": 0.1}, thermal_power_W=1000):
        """
        Initialize the radiator with a given pressure drop and coolant flow rate.

        :param coolant_flow_m3_s: Coolant flow rate in [m3/s]
        :param nominal_pressure_drop_Pa: Nominal pressure drop across the radiator in [Pa]
        :param nominal_coolant_flow_m3_s: Coolant flow rate in [m3/s]
        """

        self.coolant_flow_m3_s = coolant_flow_m3_s
        self.nominal_pressure_drop_Pa = nominal_pressure_drop_Pa
        self.nominal_coolant_flow_m3_s = nominal_coolant_flow_m3_s
        self.mass_by_power_kg_kW = mass_by_power_kg_kW
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

    def calculate_mass(self)->dict:
        """
        Calculate predicted mass of the radiator by utilizing the mass_by_power_kg_kW dict of the class and the thermal_power_W attribute.
        
        Returns:
        - result: A dictionary containing:
            - "mean": Radiator mass in kg based on the mean value of mass_by_power_kg_kW.
            - "sd": Radiator mass in kg based on the standard deviation of mass_by_power_kg_kW.

        """
        # radiator_mass_mean_kg = self.mass_by_power_kg_kW["mean"] * self.thermal_power_W / 1000
        # radiator_mass_sd_kg = self.mass_by_power_kg_kW["sd"] * self.thermal_power_W / 1000
        # return {
        # "mean": radiator_mass_mean_kg,
        # "sd": radiator_mass_sd_kg
        # }
        pass #TODO do mass calc if needed

# %% Example Usage:

radiator = Radiator(nominal_pressure_drop_Pa=0.3*1e5, nominal_coolant_flow_m3_s=300/(1000*60))

radiator.coolant_flow_m3_s = 100/(1000*60)  # 100 l/min in m3/s
pressure_drop_Pa = radiator.calculate_pressure_drop()
radiator_mass_kg = radiator.calculate_mass()