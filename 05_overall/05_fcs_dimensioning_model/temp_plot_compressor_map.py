import matplotlib.pyplot as plt
from parameters import Compressor_Parameters

# Create an instance of the Compressor_Parameters class
cp = Compressor_Parameters()

# Create the plot
plt.figure(figsize=(10, 8))

# Contour plot for efficiency over pressure ratio and corrected mass flow
contours = plt.contourf(cp.VSEC15_c200_mdot_TLU, cp.VSEC15_c200_pr_TLU, cp.VSEC15_c200_eta_TLU, levels=15, cmap="viridis")
plt.colorbar(contours, label="Efficiency")

# Contour lines for efficiency
contour_lines = plt.contour(cp.VSEC15_c200_mdot_TLU, cp.VSEC15_c200_pr_TLU, cp.VSEC15_c200_eta_TLU, levels=15, colors='black', linestyles='--')
plt.clabel(contour_lines, inline=True, fontsize=10, fmt="%.2f")

plt.grid(True)

# Labels and title
plt.title("Compressor Map: Pressure Ratio vs Corrected Mass Flow with Efficiency Contours")
plt.xlabel("Corrected Mass Flow (kg/s)")
plt.ylabel("Pressure Ratio")

# Display the plot
plt.show()