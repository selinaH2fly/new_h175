import CoolProp.CoolProp as CP
import random

class Pump:
    """
    A class to model a pump with methods to calculate:
        power, coolant state, and volume flow.
    """

    def __init__(self, pump_efficiency=0.8):
        """
        Initialize the pump with a given efficiency.
        :param pump_efficiency: Efficiency of the pump (default is 0.8)
        """
        self.pump_efficiency = pump_efficiency

    def pump_power(self, current, temperature, pressure_in, pressure_out):
        """
        Calculate the pump power based on the current.
        :param current: Operating current
        :param temperature: Coolant temperature
        :param pressure_in: Inlet pressure
        :param pressure_out: Outlet pressure
        :return: Power of the pump in kW
        """
        coolant_flow = self.get_volume_flow(current, temperature, pressure_in, pressure_out)  # Get the coolant flow rate

        # Calculate power based on flow rate, pressure difference, and pump efficiency
        power = coolant_flow * 0.1 * (pressure_out - pressure_in) / (self.pump_efficiency * 60)

        return power

    def get_volume_flow(self, current, temperature, pressure_in, pressure_out):
        """
        Calculate the volume flow rate of the coolant based on the current.
        :param current: Operating current
        :param temperature: Coolant temperature
        :param pressure_in: Inlet pressure
        :param pressure_out: Outlet pressure
        :return: Volume flow rate in l/min
        """
        ref_temp = temperature - current / 40  # Reference temperature
        ref_flow = (20 * current + 2620) / 43  # Reference flow rate

        # Calculate density of water at reference and operating conditions
        ref_rho = CP.PropsSI("D", "P", pressure_out * 100000, "T", (ref_temp + 273), "Water")
        op_rho = CP.PropsSI("D", "P", pressure_in * 100000, "T", (temperature + 273), "Water")

        # Adjust flow rate based on density ratio
        op_flow = ref_flow * (ref_rho / op_rho)

        return op_flow

# Example usage:
p1 = Pump()
current_set = 500

# Generate parameters for testing
temperature = 0.1 * current_set + 30
pressure_in = 2 + random.uniform(-1, 1)
pressure_out = pressure_in + current_set * random.uniform(0.95, 1.05) / 1000

deltaP = pressure_in - pressure_out
vol_flow = p1.get_volume_flow(current_set, temperature, pressure_in, pressure_out)
power = p1.pump_power(current_set, temperature, pressure_in, pressure_out)

# Print results:
print("Operating Current:", current_set, "A")
print("Coolant Flow:", round(vol_flow, 4), "l/min")
print("Stack Pressure Drop:", f"{deltaP:.6f}", "bar")
print("Recirculation Pump Power:", round(power, 6), "kW")
