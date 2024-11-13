import pandas as pd
import matplotlib.pyplot as plt

#%%%%%%% input %%%%%%%%%%%%%
dm_a = 0.167       # air massflow

#% first intercooler:
ef_1 = 0.8         # effectivity of the first intercooler
t_a_1in = 250      # air inlet temperature
t_co_1in = 85      # coolant input temperature+
dv_1co = 0.1       # coolant flow in l/s

#%second intercooler:
ef_2 = 0.6     # effectivity of the second intercooler
t_a_2out = 75      # air outlet temperature
t_co_2in = 67      # coolant input temperature
dv_2co = 0.1       # coolant flow in l/s

#%%%%%%%%%%%%% fluid properties %%%%%%%%%%%%

d_co = 1041      # coolant density
cp_co = 3503     # coolant thermal capacity

#R = 287;        # ideal gas constant
#a = 1.41;      % isentropic coefficient
cp_a = 1006    # air thermal capacity


#%%%%%%%%%%%%% calculation %%%%%%%%%%
dv_1co_list = []
t_co_1out_list = []
q1_list = []
q2_list = []

while dv_1co < 0.2:

    dc_1co = dv_1co * d_co * cp_co / 1000      # capacity flow coolant
    dc_2co = dv_2co * d_co * cp_co / 1000      # capacity flow coolant

    # first intercooler:
    t_a_1out = t_a_1in - ef_1 * (t_a_1in - t_co_1in)    #air outlet temp
    q_1 = dm_a * cp_a * (t_a_1in - t_a_1out)   # heat flow
    t_co_1out = t_co_1in +  q_1 / dc_1co       # coolant outlet temp

    # second intercooler:
    t_a_2in = t_a_1out;         #second air inlet temp equals first outlet temp
    ef_2 = (t_a_2in - t_a_2out) / (t_a_2in - t_co_2in)
    #t_a_2out_new = t_a_2in - ef_2 * (t_a_2in - t_co_2in)    #air outlet temp
    q_2 = dm_a * cp_a * (t_a_2in - t_a_2out)    #heatflow
    t_co_2out = t_co_2in +  q_2 / dc_2co       # coolant outlet temp

    dv_1co_list.append(dv_1co)
    t_co_1out_list.append(t_co_1out)
    q1_list.append(q_1)
    q2_list.append(q_2)

    dv_1co += 0.001

print(ef_2)


plt.plot(dv_1co_list, t_co_1out_list)
plt.title('first intercooler')
plt.xlabel('Coolant flow [l/s]')
plt.grid()
plt.ylabel('Coolant temperature [K]')
plt.show()

plt.plot(dv_1co_list, q1_list, label="1HX")
plt.plot(dv_1co_list ,q2_list, label="2HX")
plt.title('Heatflow both intercoolers')
plt.legend
plt.xlabel('Coolant flow [l/s]')
plt.grid()
plt.ylabel('Heatstream [W]')
plt.show()

