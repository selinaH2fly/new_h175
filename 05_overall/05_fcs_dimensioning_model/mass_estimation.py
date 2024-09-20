# Import the Mass_Parameters class from parameters.py
from parameters import Mass_Parameters

#TODO: Not sure if we need inheritance for this? but okay will work.
class MassCalculator(Mass_Parameters):
    """
    Class which uses the parameters set in parameters.py and uses them to calculate the overall fixed masses of each subsystem.
    """
    def __init__(self):
        # Initialize the parent class
        super().__init__()

    def sum_fixed_mass(self):
        """
        Sums the masses for each subsystem and returns the totals of the fixed mass.

        :return: A dictionary of subsystem masses and the total mass of fixed components in kilograms.
        """
        subsystem_totals = {}
        total_mass = 0.0

        # Iterate over each subsystem and its components
        for subsystem, components in self.masses_FCM_constants.items():
            # Sum the mass of each component in the current subsystem
            subsystem_mass = sum(components.values())
            subsystem_totals[subsystem] = subsystem_mass

            # Add the subsystem mass to the total mass
            total_mass += subsystem_mass

        return subsystem_totals, total_mass


if __name__ == "__main__":
    # Create an instance of MassCalculator
    mass_calculator = MassCalculator()

    # Call the sum_fixed_mass method to calculate and print the subsystem and total masses
    subsystem_totals, total_fixed_mass = mass_calculator.sum_fixed_mass()

"""
ToDo: Add sum of all masses for power dependent components as well as stack and coolant masses for 
different cell count

"""