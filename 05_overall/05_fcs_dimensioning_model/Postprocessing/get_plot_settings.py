import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.cm as cm
import matplotlib.lines as mlines
import os
import sys


def set_plot_settings(data, titles, fl_set, x_label, y_label, fig_size, label, legend, colormap, weighting, saving=True):
    fig, ax = get_figure(fig_size)
    df = filter_data_by_flight_level(data, fl_set, weighting)

def get_figure(fig_size):
    fig, ax = plt.subplots(figsize=fig_size)
    return fig, ax


def filter_data_by_flight_level(df, fl_set, weighting):
    df = df[(df['Flight Level (100x ft)'] == fl_set) & (df['weighting ([0,1])'] == weighting)]
    return df




def create_plot_save_directory(filename, weighting, directory=""):
    if directory != "": 
        folder_name = f'{directory}/weighting_{weighting}'
    else: 
        folder_name = f'weighting_{weighting}'
    folder_path = os.path.join(os.getcwd(), folder_name)
    file_path = os.path.join(folder_path, filename)
    os.makedirs(folder_path, exist_ok=True)
    return file_path
 

def configure_axes(ax, title="", xlabel="", xlim=None, ylabel="", ylim=None):
        ax.set_title(title)
        ax.set_xlabel(xlabel)
        ax.set_xlim(xlim)
        ax.set_ylabel(ylabel)
        ax.set_ylim(ylim)
        ax.grid(True)

def create_legend(ax, markers_oL):
        legend_bol = mlines.Line2D([], [], color='none', marker=markers_oL[0], 
                                      markerfacecolor='none', markeredgecolor='black', 
                                      markersize=11, linestyle='None', label='System Power BoL [kW]')
        legend_eol = mlines.Line2D([], [], color='none', marker=markers_oL[1],
                                      markerfacecolor='none', markeredgecolor='black', 
                                      markersize=11, linestyle='None', label='System Power EoL [kW]')
        
        ax.legend(handles=[legend_bol,legend_eol], loc='best')

def create_colormap(): 
        norm = mcolors.Normalize(vmin=20, vmax=175)
        cmap = cm.ScalarMappable(norm=norm, cmap='viridis')
        return norm, cmap


def seperate_bol_eol(df):
        df_bol = df[df["eol (t/f)"] == False]
        df_eol = df[df["eol (t/f)"] == True]
        return df_bol, df_eol



def add_colorbar(cmap, ax):
        # Add colorbar for the gradient
        cbar = plt.colorbar(cmap, ax=ax)
        cbar.set_label('System Power [kW]')
        
        # Set custom colorbar ticks
        cbar.set_ticks([20, 50, 75, 100, 125, 150, 175])
        cbar.ax.set_yticklabels([f'{int(t)} kW' for t in cbar.get_ticks()])