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

    def pump_power(self, current):
        """
        Calculate the pump power based on the current.
        :param current: Operating current
        :return: Power of the pump in kW
        """
        coolant_flow = self.get_volume_flow(current)  # Get the coolant flow rate
        temperature, pressure_in, pressure_out = self.coolant_state(current)  # Get the coolant state

        # Calculate power based on flow rate, pressure difference, and pump efficiency
        power = coolant_flow * 0.1 * (pressure_out - pressure_in) / (self.pump_efficiency * 60)

        return power

    def coolant_state(self, current):
        """
        Determine the coolant state based on the current.
        :param current: Operating current
        :return: Tuple containing temperature, inlet pressure, and outlet pressure
        """
        #TODO: This function is using random!!!
        temperature = 0.1 * current + 30  # Simple linear relationship for temperature
        pressure_inlet = 2 + random.uniform(-1, 1)  # Randomized inlet pressure
        pressure_outlet = pressure_inlet + current * random.uniform(0.95, 1.05) / 1000  # Outlet pressure

        return temperature, pressure_inlet, pressure_outlet

    def get_volume_flow(self, current):
        """
        Calculate the volume flow rate of the coolant based on the current.
        :param current: Operating current
        :return: Volume flow rate in l/min
        """
        op_temp, op_pressure, ref_pressure = self.coolant_state(current)  # Get the operating state
        ref_temp = op_temp - current / 40  # Reference temperature
        ref_flow = (20 * current + 2620) / 43  # Reference flow rate

        # Calculate density of water at reference and operating conditions
        ref_rho = CP.PropsSI("D", "P", ref_pressure * 100000, "T", (ref_temp + 273), "Water")
        op_rho = CP.PropsSI("D", "P", op_pressure * 100000, "T", (op_temp + 273), "Water")

        # Adjust flow rate based on density ratio
        op_flow = ref_flow * (ref_rho / op_rho)

        return op_flow

#Example usage:
p1 = Pump()
current_set = 500
temp, p_stack_out, p_stack_in = p1.coolant_state(current_set)
deltaP = p_stack_in - p_stack_out
vol_flow = p1.get_volume_flow(current_set)
power = p1.pump_power(current_set)

#Print results:
print("Operating Current:" , current_set, "A")
print("Coolant Flow:", round(vol_flow, 4), "l/min")
print("Stack Pressure Drop:", f"{deltaP:.6f}", "bar")
print("Recirculation Pump Power:" , round(power, 6), "kW")