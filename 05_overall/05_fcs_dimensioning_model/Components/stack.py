class Stack:
    """
    A class to model a fuel cell stack
    """

    def __init__(self, nominal_pressure_drop_anode_Pa=0.2*1e5, nominal_flow_anode_m3_s=0.02):
        """
        Initialize the radiator with a given pressure drop and coolant flow rate.

        :param nominal_pressure_drop_anode_Pa: Nominal pressure drop across the anode in [Pa]
        :param nominal_flow_anode_m3_s: Nominal anode flow rate in [m3/s]
        """

        self.nominal_pressure_drop_anode_Pa = nominal_pressure_drop_anode_Pa
        self.nominal_flow_anode_m3_s = nominal_flow_anode_m3_s

    def calculate_pressure_drop_anode(self, flow_anode_m3_s: float)->float:
        """
        Calculate the pressure drop across the anode for a given flow rate.
        The "model" is a simple quadratic relationship between pressure drop and flow rate.

        :param flow_anode_m3_s: Anode gas flow rate in [m3/s]
        :return: Pressure drop across the anode in [Pa]
        """

        pressure_drop_coefficient = self.nominal_pressure_drop_anode_Pa / (self.nominal_flow_anode_m3_s**2)
        pressure_drop_Pa = pressure_drop_coefficient * flow_anode_m3_s**2

        return pressure_drop_Pa

    def calculate_weight(self)->float:
        # TODO: Do weight estimation here.
        # Placeholder implementation, update with actual logic
        return None

# %% Example Usage:

stack = Stack(nominal_pressure_drop_anode_Pa=0.3*1e5, nominal_flow_anode_m3_s=0.018)

anode_flow_kg_s = 1.4*1e-3
anode_flow_m3_s = anode_flow_kg_s/0.083

pressure_drop_anode_Pa = stack.calculate_pressure_drop_anode(flow_anode_m3_s=anode_flow_m3_s)
print(f"Pressure drop across the anode: {pressure_drop_anode_Pa*1e-5:.2f} bar")