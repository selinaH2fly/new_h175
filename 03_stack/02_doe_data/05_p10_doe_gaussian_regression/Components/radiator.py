class Radiator:
    """
    A class to model a liquid/air radiator with methods to calculate.
    """

    def __init__(self, pressure_drop_Pa=500*100, coolant_flow_kg_s=0.0):
        """
        Initialize the radiator with a given pressure drop and coolant flow rate.

        :param pressure_drop_Pa: Pressure drop across the radiator in [Pascals]
        :param coolant_flow_kg_s: Coolant flow rate in [kg/s]
        """

        self.pressure_drop_Pa = pressure_drop_Pa
        self.coolant_flow_kg_s = coolant_flow_kg_s

    
    def calculate_weight(self)->float:
        #TODO:
        #Do weight estimation here.
        # Placeholder implementation, update with actual logic
        return None

# %% Example usage:
    
radiator = Radiator(pressure_drop_Pa=2e7, coolant_flow_kg_s=3.0)