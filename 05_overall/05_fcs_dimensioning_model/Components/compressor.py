import CoolProp.CoolProp as CP
from scipy.interpolate import griddata
from scipy.spatial import ConvexHull
import numpy as np
import matplotlib.pyplot as plt
from parameters import Mass_Estimator


class Compressor:
    def __init__(self, params_physics, mass_estimator: Mass_Estimator,isentropic_efficiency=0.75, electric_efficiency=0.95,
                 air_mass_flow_kg_s=1, temperature_in_K=293.15, pressure_in_Pa=1.013e5, pressure_out_Pa=1.013e5,
                 nominal_BoP_pressure_drop_Pa=0.3*1e5, nominal_air_flow_kg_s=0.130, compressor_map=None
                 ):

        self.isentropic_efficiency = isentropic_efficiency
        self.electric_efficiency = electric_efficiency
        self.params_physics = params_physics
        self.air_mass_flow_kg_s = air_mass_flow_kg_s
        self.temperature_in_K = temperature_in_K
        self.pressure_in_Pa = pressure_in_Pa        
        self.pressure_out_Pa = pressure_out_Pa
        self.nominal_pressure_drop_Pa = nominal_BoP_pressure_drop_Pa
        self.nominal_air_flow_kg_s = nominal_air_flow_kg_s
        self.compressor_map = compressor_map

        # Ensure the component is available in masses_FCM_depended; raise error if missing
        if 'Compressor' not in mass_estimator.masses_FCM_depended:
            raise ValueError(f"Component 'Compressor' not found in mass estimator's dependent masses.")

        # Retrieve mass data from the mass_estimator instance
        self.mass_by_power_kg_kW = mass_estimator.masses_FCM_depended['Compressor']

    def calculate_power(self) -> float:
        """
        Calculate the electrical power consumed by the compressor using a real-world compressor map.

        Returns:
        - compressor_el_power_W: The electrical power required for the compressor in Watts.
        """

        # Compute the specific heat ratio of air
        specific_heat_ratio = CP.PropsSI('C', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Air') / \
            CP.PropsSI('O', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Air')

        # Compute the isentropic outlet temperature
        isentropic_outlet_temperature_K = self.temperature_in_K * (self.pressure_out_Pa/self.pressure_in_Pa)**((specific_heat_ratio-1)/specific_heat_ratio)

        # Compute the specific enthalpies before and after the compressor
        specific_enthalpy_in_J_kg = CP.PropsSI('H', 'T', self.temperature_in_K, 'P', self.pressure_in_Pa, 'Air')
        specific_enthalpy_out_J_kg = CP.PropsSI('H', 'T', isentropic_outlet_temperature_K, 'P', self.pressure_out_Pa, 'Air')

        # Compute the isentropic power
        compressor_isentropic_power_W = self.air_mass_flow_kg_s * (specific_enthalpy_out_J_kg - specific_enthalpy_in_J_kg)

        # Determine the operating point if a real-world compressor map is provided
        if self.compressor_map is not None:
            efficiency, _ = self._interpolate_efficiency()
            compressor_shaft_power_W = compressor_isentropic_power_W / efficiency
        else:
            compressor_shaft_power_W = compressor_isentropic_power_W / self.isentropic_efficiency

        # Compute the electric power
        compressor_electric_power_W = compressor_shaft_power_W / self.electric_efficiency

        return compressor_electric_power_W
    
    def _interpolate_efficiency(self) -> float:
        """
        Interpolates the efficiency from the compressor map based on the current operating point.

        Returns:
        - Efficiency at the given operating point.
        """
        pressure_ratio = self.pressure_out_Pa / self.pressure_in_Pa
        mass_flow_g_s = self.air_mass_flow_kg_s * 1000
        corrected_mass_flow_g_s = mass_flow_g_s * (self.pressure_in_Pa / self.compressor_map['reference_pressure_Pa']) * \
            np.sqrt(self.temperature_in_K / self.compressor_map['reference_temperature_K'])

        # Assign the compressor map arrays and flatten to 1D
        map_pressure_ratio = self.compressor_map['pressure_ratio'].flatten()
        map_mass_flow_g_s= self.compressor_map['corrected_massflow_g_s'].flatten()
        map_efficiency = self.compressor_map['efficiency'].flatten()

        # Interpolate the efficiency at the target pressure ratio and mass flow
        efficiency = griddata(np.array([map_mass_flow_g_s, map_pressure_ratio]).T, map_efficiency,
                                (corrected_mass_flow_g_s, pressure_ratio), method='linear', rescale=True, fill_value=1e-3)

        return efficiency.item(), [pressure_ratio, corrected_mass_flow_g_s]
    
    def plot_compressor_map(self):
        """
        Plots the compressor map with efficiency contours and highlights the specified operating point
        using the original unevenly spaced grid.
        """

        # Interpolate the efficiency at the target pressure ratio and mass flow
        efficiency_interp, [operating_point_pressure_ratio, operating_point_corrected_massflow_g_s] = self._interpolate_efficiency()

        # Map to convex hull
        massflow_convex_hull, pressure_ratio_convex_hull, efficiency_convex_hull, convex_hull, flattened_map = self._map_to_convex_hull()

        # Create the plot
        plt.figure(figsize=(10, 8))

         # Plot the convex hull edges
        for simplex in convex_hull.simplices:
            plt.plot(flattened_map[simplex, 0], flattened_map[simplex, 1], 'gray', linestyle='--', linewidth=2)

        # Contour plot for efficiency over pressure ratio and corrected mass flow
        contours = plt.contourf(massflow_convex_hull, pressure_ratio_convex_hull, efficiency_convex_hull, levels=30, cmap="viridis")
        plt.colorbar(contours, label="Efficiency")

        # Contour lines for efficiency
        contour_lines = plt.contour(massflow_convex_hull, pressure_ratio_convex_hull, efficiency_convex_hull, levels=30, colors='black', linestyles='--')
        plt.clabel(contour_lines, inline=True, fontsize=10, fmt="%.2f")

        # Highlight the operating point
        plt.plot(operating_point_corrected_massflow_g_s, operating_point_pressure_ratio, 'ro', markersize=10,
                label=f'Optimized Operating Point\nPR={operating_point_pressure_ratio:.2f}, Corrected Massflow={operating_point_corrected_massflow_g_s:.1f} g/s, Efficiency: {efficiency_interp:.2f}')

        plt.grid(True)

        # Labels and title
        plt.title("Compressor Map: Pressure Ratio vs Corrected Mass Flow")
        plt.xlabel("Corrected Mass Flow (g/s)")
        plt.ylabel("Pressure Ratio")
        plt.legend(loc='upper left')

        # Display the plot
        # plt.show()
        plt.savefig('compressor_map_operating_point.png', bbox_inches='tight')
    
    def _map_to_convex_hull(self):

        # Extract the original grid points and efficiency values
        corrected_massflows = self.compressor_map["corrected_massflow_g_s"]
        pressure_ratios = self.compressor_map["pressure_ratio"]
        efficiencies = self.compressor_map["efficiency"]

        # Flatten the input arrays
        flattened_massflow = corrected_massflows.flatten()
        flattened_pressure_ratio = pressure_ratios.flatten()
        flattened_efficiency = efficiencies.flatten()

        # Combine massflow and pressure_ratio into points
        points = np.array([flattened_massflow, flattened_pressure_ratio]).T

        # Compute the convex hull
        hull = ConvexHull(points)
        
        # Get the points that define the convex hull
        hull_points = points[hull.vertices]
        
        # Generate a grid that spans the convex hull
        grid_massflow, grid_pressure_ratio = np.meshgrid(
            np.linspace(hull_points[:, 0].min(), hull_points[:, 0].max(), 100),
            np.linspace(hull_points[:, 1].min(), hull_points[:, 1].max(), 100)
        )

        # Interpolate efficiency values over the grid
        grid_efficiency = griddata(points, flattened_efficiency, (grid_massflow, grid_pressure_ratio), method='linear', rescale=True)

        return grid_massflow, grid_pressure_ratio, grid_efficiency, hull, points

    
    def calculate_BoP_pressure_drop(self)->float:
        """
        Calculate the pressure drop across the BoP components downstream the compressor for a given air mass flow rate.
        The "model" is a simple quadratic relationship between pressure drop and air mass flow rate.

        :param air_flow_kg_s: Air mass flow rate in [kg/s]
        :return: Pressure drop across the BoP components (compressor out -> cathode in) in [Pa]
        """

        pressure_drop_coefficient = self.nominal_pressure_drop_Pa / (self.nominal_air_flow_kg_s**2)
        pressure_drop_Pa = pressure_drop_coefficient * self.air_mass_flow_kg_s**2

        return pressure_drop_Pa
    
    def calculate_mass(self)->dict:
        """
        Calculate predicted mass of the compressor utilizing the mass_by_power_kg_kW dict of the class
        
        Returns:
        - result: A dictionary containing:
            - "mean": Compressor mass in kg based on the mean value of mass_by_power_kg_kW.
            - "sd": Compressor mass in kg based on the standard deviation of mass_by_power_kg_kW.

        """
        compressor_el_power_W = self.calculate_power()
        compressor_mass_mean_kg = self.mass_by_power_kg_kW["mean"] * compressor_el_power_W / 1000
        compressor_mass_sd_kg = self.mass_by_power_kg_kW["sd"] * compressor_el_power_W / 1000
        return {
        "mean": compressor_mass_mean_kg,
        "sd": compressor_mass_sd_kg
        }
    
# %% Example Usage:
import parameters   
params_physics = parameters.Physical_Parameters()
mass_estimator = Mass_Estimator()

C1 = Compressor(params_physics,mass_estimator, isentropic_efficiency=0.75, electric_efficiency=0.95,
             air_mass_flow_kg_s=1, pressure_in_Pa=1e5, pressure_out_Pa=2e5)

power_el = C1.calculate_power()
mass = C1.calculate_mass()

