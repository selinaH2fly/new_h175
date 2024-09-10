import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
import sys
import os

# Import parameters.py from the parent directory
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from parameters import Optimization_Parameters
_params_optimization = Optimization_Parameters()

# Plot the optimized cathode inlet pressure for each dataset
def plot_cathode_inlet_pressure(data, titles, fl_set, saving=True):
    """
    Plots the optimized operating paramter for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - fl_set: Integer, the flight level to be plotted.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    for df, title in zip(data, titles):
        df = df[df['Flight Level (100x ft)'] == fl_set]
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Create a colormap and normalize for the color gradient
        norm = mcolors.Normalize(vmin=20, vmax=175)

        # plot min/max bounds according to parameters.py
        lower_bound = ax.axhline(min(_params_optimization.bounds[3]), color='black', linestyle='--', label='Cathode Inlet Pressure Bounds', zorder=0)
        upper_bound = ax.axhline(max(_params_optimization.bounds[3]), color='black', linestyle='--', zorder=0)
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df['current_A (Value)'], df['pressure_cathode_in_bara (Value)'], c=df['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100, zorder=1)

        # Add colorbar for the gradient
        cbar = plt.colorbar(scatter, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Manually set colorbar ticks from 20 to 175 in 25 steps, excluding 25
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

        # Add a red shaded area from 700 A to 800 A
        ax.axvspan(700, 800, color='red', alpha=0.3)

        # Set title and labels
        ax.set_title(f'Optimized Operating Parameters: Cathode Inlet Pressure, FL {fl_set}, {title}', fontsize=14)
        ax.set_xlabel('Current [A]')
        ax.set_ylabel(f'Cathode Inlet Pressure [Bar(a)]')
        ax.grid(True)
        ax.set_xlim([0, 800])
        ax.set_ylim([1, 3.5])
        fig.tight_layout()

        # Annotate points where 'eol (t/f)' is True
        for i in df[df["eol (t/f)"] == True].index:
            ax.annotate('EoL', 
                        (df['current_A (Value)'][i], df['pressure_cathode_in_bara (Value)'][i]), 
                        textcoords="offset points", 
                        xytext=(2, -20), 
                        ha='center',
                        fontsize=11, 
                        color='black')
            
        # Create a custom legend entry with a colorless circle
        legend_circle = mlines.Line2D([], [], color='none', marker='o', markerfacecolor='none', markeredgecolor='black', markersize=11, linestyle='None', label='System Power [kW]')
        ax.legend(handles=[legend_circle, lower_bound], loc='best')

        # Save the plot as a PNG file if saving is True
        if saving:
            plt.savefig(f'{title}_cathode_inlet_pressure.png')


# Plot the optimized cathode inlet rel. humidity for each dataset
def plot_cathode_inlet_realtive_humidity(data, titles, fl_set, saving=True):
    """
    Plots the optimized operating paramter for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - fl_set: Integer, the flight level to be plotted.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    for df, title in zip(data, titles):
        df = df[df['Flight Level (100x ft)'] == fl_set]
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Create a colormap and normalize for the color gradient
        norm = mcolors.Normalize(vmin=20, vmax=175)

        # plot min/max bounds according to parameters.py
        lower_bound = ax.axhline(min(_params_optimization.bounds[1]), color='black', linestyle='--', label='Cathode Inlet rel. Humidity Bounds', zorder=0)
        upper_bound = ax.axhline(max(_params_optimization.bounds[1]), color='black', linestyle='--', zorder=0)
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df['current_A (Value)'], df['cathode_rh_in_perc (Value)'], c=df['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100, zorder=1)

        # Add colorbar for the gradient
        cbar = plt.colorbar(scatter, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Manually set colorbar ticks from 20 to 175 in 25 steps, excluding 25
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

        # Add a red shaded area from 700 A to 800 A
        ax.axvspan(700, 800, color='red', alpha=0.3)

        # Set title and labels
        ax.set_title(f'Optimized Operating Parameters: Cathode Inlet rel. Humidity, FL {fl_set}, {title}', fontsize=14)
        ax.set_xlabel('Current [A]')
        ax.set_ylabel(f'Cathode Inlet rel. Humidity [%]')
        ax.grid(True)
        ax.set_xlim([0, 800])
        ax.set_ylim([0, 110])
        fig.tight_layout()

        # Annotate points where 'eol (t/f)' is True
        for i in df[df["eol (t/f)"] == True].index:
            ax.annotate('EoL', 
                        (df['current_A (Value)'][i], df['cathode_rh_in_perc (Value)'][i]), 
                        textcoords="offset points", 
                        xytext=(2, -20), 
                        ha='center',
                        fontsize=11, 
                        color='black')
            
        # Create a custom legend entry with a colorless circle
        legend_circle = mlines.Line2D([], [], color='none', marker='o', markerfacecolor='none', markeredgecolor='black', markersize=11, linestyle='None', label='System Power [kW]')
        ax.legend(handles=[legend_circle, lower_bound], loc='best')

        # Save the plot as a PNG file if saving is True
        if saving:
            plt.savefig(f'{title}_cathode_inlet_rel_humidity.png')

# Plot the optimized cathode stocihiometry for each dataset
def plot_cathode_stoichiomtrey(data, titles, fl_set, saving=True):
    """
    Plots the optimized operating paramter for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - fl_set: Integer, the flight level to be plotted.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    for df, title in zip(data, titles):
        df = df[df['Flight Level (100x ft)'] == fl_set]
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Create a colormap and normalize for the color gradient
        norm = mcolors.Normalize(vmin=20, vmax=175)

        # plot min/max bounds according to parameters.py
        lower_bound = ax.axhline(min(_params_optimization.bounds[2]), color='black', linestyle='--', label='Cathode Inlet Stoichiometry Bounds', zorder=0)
        upper_bound = ax.axhline(max(_params_optimization.bounds[2]), color='black', linestyle='--', zorder=0)
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df['current_A (Value)'], df['stoich_cathode (Value)'], c=df['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100, zorder=1)

        # Add colorbar for the gradient
        cbar = plt.colorbar(scatter, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Manually set colorbar ticks from 20 to 175 in 25 steps, excluding 25
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

        # Add a red shaded area from 700 A to 800 A
        ax.axvspan(700, 800, color='red', alpha=0.3)

        # Set title and labels
        ax.set_title(f'Optimized Operating Parameters: Cathode Sroichiometry, FL {fl_set}, {title}', fontsize=14)
        ax.set_xlabel('Current [A]')
        ax.set_ylabel(f'Cathode Inlet Stoichiometry [-]')
        ax.grid(True)
        ax.set_xlim([0, 800])
        ax.set_ylim([1, 6])
        fig.tight_layout()

        # Annotate points where 'eol (t/f)' is True
        for i in df[df["eol (t/f)"] == True].index:
            ax.annotate('EoL', 
                        (df['current_A (Value)'][i], df['stoich_cathode (Value)'][i]), 
                        textcoords="offset points", 
                        xytext=(2, -20), 
                        ha='center',
                        fontsize=11, 
                        color='black')
            
        # Create a custom legend entry with a colorless circle
        legend_circle = mlines.Line2D([], [], color='none', marker='o', markerfacecolor='none', markeredgecolor='black', markersize=11, linestyle='None', label='System Power [kW]')
        ax.legend(handles=[legend_circle, lower_bound], loc='best')

        # Save the plot as a PNG file if saving is True
        if saving:
            plt.savefig(f'{title}_cathode_stoichiometry.png')

# Plot the optimized coolant inlet temperature for each dataset
def plot_coolant_inlet_temperature(data, titles, fl_set, saving=True):
    """
    Plots the optimized operating paramter for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - fl_set: Integer, the flight level to be plotted.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    for df, title in zip(data, titles):
        df = df[df['Flight Level (100x ft)'] == fl_set]
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Create a colormap and normalize for the color gradient
        norm = mcolors.Normalize(vmin=20, vmax=175)

        # plot min/max bounds according to parameters.py
        lower_bound = ax.axhline(min(_params_optimization.bounds[4]), color='black', linestyle='--', label='Coolant Inlet Temperature Bounds', zorder=0)
        upper_bound = ax.axhline(max(_params_optimization.bounds[4]), color='black', linestyle='--', zorder=0)
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df['current_A (Value)'], df['temp_coolant_inlet_degC (Value)'], c=df['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100, zorder=1)

        # Add colorbar for the gradient
        cbar = plt.colorbar(scatter, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Manually set colorbar ticks from 20 to 175 in 25 steps, excluding 25
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

        # Add a red shaded area from 700 A to 800 A
        ax.axvspan(700, 800, color='red', alpha=0.3)

        # Set title and labels
        ax.set_title(f'Optimized Operating Parameters: Coolant Temperature at Stack Inlet, FL {fl_set}, {title}', fontsize=14)
        ax.set_xlabel('Current [A]')
        ax.set_ylabel(f'Coolant Inlet Temperature [°C]')
        ax.grid(True)
        ax.set_xlim([0, 800])
        ax.set_ylim([50, 100])
        fig.tight_layout()

        # Annotate points where 'eol (t/f)' is True
        for i in df[df["eol (t/f)"] == True].index:
            ax.annotate('EoL', 
                        (df['current_A (Value)'][i], df['temp_coolant_inlet_degC (Value)'][i]), 
                        textcoords="offset points", 
                        xytext=(2, -20), 
                        ha='center',
                        fontsize=11, 
                        color='black')
            
        # Create a custom legend entry with a colorless circle
        legend_circle = mlines.Line2D([], [], color='none', marker='o', markerfacecolor='none', markeredgecolor='black', markersize=11, linestyle='None', label='System Power [kW]')
        ax.legend(handles=[legend_circle, lower_bound], loc='best')

        # Save the plot as a PNG file if saving is True
        if saving:
            plt.savefig(f'{title}_coolant_inlet.png')

# Plot the optimized coolant outlet temperature for each dataset
def plot_coolant_outlet_temperature(data, titles, fl_set, saving=True):
    """
    Plots the optimized operating paramter for multiple datasets.

    Parameters:
    - data: List of DataFrames, where each DataFrame contains the data to be plotted.
    - titles: List of strings, corresponding to the titles for each dataset.
    - fl_set: Integer, the flight level to be plotted.
    - saving: Boolean, if True, saves the plots as PNG files.
    """
    for df, title in zip(data, titles):
        df = df[df['Flight Level (100x ft)'] == fl_set]
        fig, ax = plt.subplots(figsize=(12, 8))
        
        # Create a colormap and normalize for the color gradient
        norm = mcolors.Normalize(vmin=20, vmax=175)

        # plot min/max bounds according to parameters.py
        lower_bound = ax.axhline(min(_params_optimization.bounds[5]), color='black', linestyle='--', label='Coolant Outlet Temperature Bounds', zorder=0)
        upper_bound = ax.axhline(max(_params_optimization.bounds[5]), color='black', linestyle='--', zorder=0)
        
        # Scatter plot with color based on 'System Power (kW)'
        scatter = ax.scatter(df['current_A (Value)'], df['temp_coolant_outlet_degC (Value)'], c=df['System Power (kW)'], cmap='viridis', norm=norm, edgecolor='k', s=100, zorder=1)

        # Add colorbar for the gradient
        cbar = plt.colorbar(scatter, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Manually set colorbar ticks from 20 to 175 in 25 steps, excluding 25
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])

        # Add a red shaded area from 700 A to 800 A
        ax.axvspan(700, 800, color='red', alpha=0.3)

        # Set title and labels
        ax.set_title(f'Optimized Operating Parameters: Coolant Temperature at Stack Outlet, FL {fl_set}, {title}', fontsize=14)
        ax.set_xlabel('Current [A]')
        ax.set_ylabel(f'Coolant Outlet Temperature [°C]')
        ax.grid(True)
        ax.set_xlim([0, 800])
        ax.set_ylim([50, 100])
        fig.tight_layout()

        # Annotate points where 'eol (t/f)' is True
        for i in df[df["eol (t/f)"] == True].index:
            ax.annotate('EoL', 
                        (df['current_A (Value)'][i], df['temp_coolant_outlet_degC (Value)'][i]), 
                        textcoords="offset points", 
                        xytext=(2, -20), 
                        ha='center',
                        fontsize=11, 
                        color='black')
            
        # Create a custom legend entry with a colorless circle
        legend_circle = mlines.Line2D([], [], color='none', marker='o', markerfacecolor='none', markeredgecolor='black', markersize=11, linestyle='None', label='System Power [kW]')
        ax.legend(handles=[legend_circle, lower_bound], loc='best')

        # Save the plot as a PNG file if saving is True
        if saving:
            plt.savefig(f'{title}_coolant_outlet.png')



            

