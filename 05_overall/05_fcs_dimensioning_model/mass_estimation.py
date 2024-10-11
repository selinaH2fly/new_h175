def sum_fixed_mass(masses_FCM_constants_dict):
    """
    Sums the masses for each subsystem and returns the totals of the fixed mass.

    :return: A dictionary of subsystem masses and the total mass of fixed components in kilograms.
    """

    subsystem_constant_mass_dict = {}
    total_constant_mass = 0.0

    # Iterate over each subsystem and its components
    for subsystem, components in masses_FCM_constants_dict.items():

        # Sum the mass of each component in the current subsystem
        subsystem_mass = sum(components.values())
        subsystem_constant_mass_dict[subsystem] = subsystem_mass

        # Add the subsystem mass to the total mass
        total_constant_mass += subsystem_mass

    return subsystem_constant_mass_dict, total_constant_mass

def sum_power_dependent_mass(masses_FCM_power_depended_dict):
    """
    Sums the masses for each subsystem and returns the totals of the power dependent mass.

    :return: A dictionary of subsystem masses and the total mass of power dependent components in kilograms.
    """

    subsystem_power_dependent_mass_dict = {}
    total_power_dependent_mass = 0.0

    # TODO: Implement the function

    return subsystem_power_dependent_mass_dict, total_power_dependent_mass

def sum_cellcount_dependent_mass(masses_FCM_cellcount_dependent_dict):
    """
    Sums the masses for each subsystem and returns the totals of the cellcount dependent mass.

    :return: A dictionary of subsystem masses and the total mass of cellcount dependent components in kilograms.
    """

    subsystem_cellcount_dependent_mass_dict = {}
    total_cellcount_dependent_mass = 0.0

    # TODO: Implement the function

    return subsystem_cellcount_dependent_mass_dict, total_cellcount_dependent_mass


if __name__ == "__main__":

    import parameters
    
    # Load the parameters
    _params_masses = parameters.Mass_Parameters()

    # Call the sum_fixed_mass method to calculate and print the subsystem and total masses
    subsystem_constant_mass_dict, total_constant_mass = sum_fixed_mass(masses_FCM_constants_dict=_params_masses.masses_FCM_constants)


    print("\nFixed Masses:")
    for subsystem, mass in subsystem_constant_mass_dict.items():
        print(f"  {subsystem:<{10}}: {mass:.2f} kg")