"""This file contains funtions to load and plot Powercell DoE raw data."""

import sys
import mariadb
import matplotlib.pyplot as plt
import numpy as np

# High-level function for loading the data
def load_doe_data():

    # Load the data from mariaDB
    doe_data = load_doe_from_db()

    # Create a dictionary to store the data
    keys =  []
    values = []

    for row in doe_data:
        keys.append(row[0])
        values.append(row[1:])

    doe_data_dict = dict(zip(keys, values))

    # Data not included in the raw data but used as in- or ouputs of the DoE model provided by PC
    processed_doe_data_dict = {}
    processed_doe_data_dict['h2_concentration'] = tuple(a / (a + b) for a, b in zip(doe_data_dict['flow_anode_h2_mfc_total'], doe_data_dict['flow_anode_n2_mfc_total']))
    processed_doe_data_dict['stack_voltage_loss'] = tuple(a - b for a, b in zip(doe_data_dict['metis_CVM_Stack_Voltage'], doe_data_dict['voltage']))
    processed_doe_data_dict['dp_anode_mbar'] = tuple((a - b)*1e3 for a, b in zip(doe_data_dict['pressure_anode_inlet'], doe_data_dict['pressure_anode_outlet']))
    processed_doe_data_dict['dp_cathode_mbar'] = tuple((a - b)*1e3 for a, b in zip(doe_data_dict['pressure_cathode_inlet'], doe_data_dict['pressure_cathode_outlet']))
    processed_doe_data_dict['dp_coolant_mbar'] = tuple((a - b)*1e3 for a, b in zip(doe_data_dict['pressure_coolant_inlet'], doe_data_dict['pressure_coolant_outlet']))

    # Create an input data dictionary
    model_in_keys = ['current', 'h2_concentration',
                     'anode_stoich', 'temp_anode_dewpoint', 'temp_anode_inlet', 'pressure_anode_inlet',
                     'cathode_stoich', 'temp_cathode_dewpoint', 'temp_cathode_inlet', 'pressure_cathode_inlet',
                     'flow_coolant', 'temp_coolant_inlet']
    model_in_dict = assign_input_output_dicts(model_in_keys, doe_data_dict, processed_doe_data_dict)

    # Rename keys of the input data to reflect the units (and keep the order of the keys)
    model_in_dict['current_A'] = model_in_dict.pop('current')
    model_in_dict['h2_concentration'] = model_in_dict.pop('h2_concentration')
    model_in_dict['stoich_anode'] = model_in_dict.pop('anode_stoich')
    model_in_dict['dewp_anode_degC'] = model_in_dict.pop('temp_anode_dewpoint')
    model_in_dict['temp_anode_in_degC'] = model_in_dict.pop('temp_anode_inlet')
    model_in_dict['p_anode_in_barg'] = model_in_dict.pop('pressure_anode_inlet')
    model_in_dict['stoich_cathode'] = model_in_dict.pop('cathode_stoich')
    model_in_dict['dewp_cathode_degC'] = model_in_dict.pop('temp_cathode_dewpoint')
    model_in_dict['temp_cathode_in_degC'] = model_in_dict.pop('temp_cathode_inlet')
    model_in_dict['p_cathode_in_barg'] = model_in_dict.pop('pressure_cathode_inlet')
    model_in_dict['flow_cool_lpm'] = model_in_dict.pop('flow_coolant')
    model_in_dict['temp_cool_in_degC'] = model_in_dict.pop('temp_coolant_inlet')

    # Create an output data dictionary
    model_out_keys = ['voltage', 'stack_voltage_loss', 'CellSense_Avg', 'CellSense_Max', 'CellSense_Min',
                      'CellSense_std', 'dp_anode_mbar', 'dp_cathode_mbar', 'dp_coolant_mbar',
                      'temp_anode_in_out_diff', 'temp_cathode_in_out_diff', 'temp_coolant_in_out_diff']
    model_out_dict = assign_input_output_dicts(model_out_keys, doe_data_dict, processed_doe_data_dict)

    # Rename keys of the output data to reflect the units (and keep the order of the keys)
    model_out_dict['voltage_V'] = model_out_dict.pop('voltage')
    model_out_dict['stack_voltage_loss_V'] = model_out_dict.pop('stack_voltage_loss')
    model_out_dict['cellsense_avg_V'] = model_out_dict.pop('CellSense_Avg')
    model_out_dict['cellsense_max_V'] = model_out_dict.pop('CellSense_Max')
    model_out_dict['cellsense_min_V'] = model_out_dict.pop('CellSense_Min')
    model_out_dict['cellsense_std_mV'] = model_out_dict.pop('CellSense_std')
    model_out_dict['dp_anode_mbar'] = model_out_dict.pop('dp_anode_mbar')
    model_out_dict['dp_cathode_mbar'] = model_out_dict.pop('dp_cathode_mbar')
    model_out_dict['dp_cool_mbar'] = model_out_dict.pop('dp_coolant_mbar')
    model_out_dict['dtemp_anode_degC'] = model_out_dict.pop('temp_anode_in_out_diff')
    model_out_dict['dtemp_cathode_degC'] = model_out_dict.pop('temp_cathode_in_out_diff')
    model_out_dict['dtemp_cool_degC'] = model_out_dict.pop('temp_coolant_in_out_diff')

    # Multiply values in 'dtemp_cathode_degC' and 'dtemp_coolant_degC' by -1
    # This is inline with how PC plots the data and reflects the fact that the temperatures increase (i.e., (t_out - t_in) > 0).
    model_out_dict['dtemp_cathode_degC'] = tuple(-1*a for a in model_out_dict['dtemp_cathode_degC'])
    model_out_dict['dtemp_cool_degC'] = tuple(-1*a for a in model_out_dict['dtemp_cool_degC'])

    return (model_in_dict, model_out_dict)


# Load the data from mariaDB
def load_doe_from_db():

    # Open connection
    try:
        conn = mariadb.connect(
            user="h2user",
            password="k4LyKghGkzG7",
            host="mariadb.ad.h2fly.de",
            port=3306,
            database="DoE_data_Powercell"
        )
    except mariadb.Error as e:
        print(f"Error connecting to MariaDB Platform: {e}")
        sys.exit(1)

    cur = conn.cursor()  # Get Cursor

    # Extract data via SQL query
    query = "SELECT * FROM TV500873_sheet0;"
    cur.execute(query)
    doe_data = cur.fetchall()

    # Disconnect from mariaDB
    cur.close()
    conn.close()

    return doe_data

# Assign the input and output data to the respective dictionaries
def assign_input_output_dicts(keys, doe_data_dict, processed_doe_data_dict):
    '''
    This function assigns the input and output data to the respective dictionaries.
    '''

    # Create an empty data dictionary
    new_dict = {}

    # Look for the keys in the overall data dictionaries
    for key in keys:
        # Look for the key in the original data dictionary
        if key in doe_data_dict:
            new_dict[key] = doe_data_dict[key]
        # Look for the key in the processed data dictionary
        elif key in processed_doe_data_dict:
            new_dict[key] = processed_doe_data_dict[key]
        else:
            print('Key ' + key + ' not found in the data dictionary!')

    return new_dict

def plot_doe_data(model_in_dict, model_out_dict):
    
    # Create scatter plots of the varied input parameters (cf. illustration provided by Powercell)
    cols = 3
    rows = int(np.ceil((len(model_in_dict)-1)/cols))
    fig, axs = plt.subplots(rows, cols)
    mgr = plt.get_current_fig_manager()
    mgr.resize(1280, 720)
    fig.suptitle('Variation of Input Parameters \n (cf. Illustration provided by Powercell)')
    row, col = 0, 0
    for key in model_in_dict:
        if key != 'current_A':
            axs[row, col].grid(True, zorder=1)
            axs[row, col].scatter(model_in_dict['current_A'], model_in_dict[key], marker='o', facecolor='darkred', edgecolor='black', zorder=2)
            axs[row, col].xaxis.set_label_text('current (A)')
            axs[row, col].yaxis.set_label_text(key)
            col += 1
            if col == cols:
                col = 0
                row += 1

    for ax in axs.flat:
        if ax.get_xlabel() != 'current (A)':
            # Delete the axes
            fig.delaxes(ax)

    plt.tight_layout()
    plt.show(block=False)

    # Create scatter plots of the output parameters (cf. illustration provided by Powercell)
    cols = 3
    rows = int(np.ceil((len(model_out_dict))/cols))
    fig, axs = plt.subplots(rows, cols)
    mgr = plt.get_current_fig_manager()
    mgr.resize(1280, 720)
    fig.suptitle('Variation of Output Parameters \n (cf. Illustration provided by Powercell)')
    row, col = 0, 0
    for key in model_out_dict:
            axs[row, col].grid(True, zorder=1)
            axs[row, col].scatter(model_in_dict['current_A'], model_out_dict[key], marker='o', facecolor='darkred', edgecolor='black', zorder=2)
            axs[row, col].xaxis.set_label_text('current (A)')
            axs[row, col].yaxis.set_label_text(key)
            col += 1
            if col == cols:
                col = 0
                row += 1
    plt.tight_layout()
    plt.draw()

    return plt