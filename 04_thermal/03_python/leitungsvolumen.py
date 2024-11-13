import numpy
import pandas as pd
########### Input ###############

temp = 60                   # 60 degrees coolant temperature
# v_dot = 30 / 60 / 1000
v_dot = 100 /60/1000      # coolant volume flow at stack / m^3/s

l = 5       # lenght of the tubes / m
d = 0.032   #  diameter (32mm) at stack / m

k = 0.0016 * 10 ** (-3)         # average roughness silicon / mm 
rho = 1035                      #denisty of Glysantin %50/50 @ 80�C / kg/m^3

n_bogen = 10                    #Anzahl 90° Boegen
zeta = 0.25                     # kFaktor des 90° bogens
eta_pump = 0.4                  # Total pump efficiency

### viscosity ###
#vis = 4 * 10 ** (-6)
vis = 1.37 * 10 ** (-6)     # viscosity / m^2/s


#################   Calculation  ###################
r = d/2  # radius of the hose / m 
a = numpy.pi * r ** 2; # cross section area of the hose / m^2
u = v_dot / a
re = u * d / vis
lam = 0.3164 * re ** (-1/4)
print("lambda = %s"%lam)
print("u = %s"%u)
print("re = %s"%re)

#dp_schlauch = 0.3164 * (u * d / vis) ** (-1/4) * l * rho * u ** 2 / (2 * d)
#dp_schlauch = 0.3164 * u ** (7/4) * vis ** (1/4) * l * rho * d ** (-5/4) / 2
dp_schlauch = 0.3164 * (v_dot / (numpy.pi * (d/2) ** 2)) ** (7/4) * vis ** (1/4) * l * rho * d ** (-5/4) / 2
#dp_schlauch = k * 1000 * l * rho * u ** 2 / (2 * d)
#dp_schlauch = lam * l * rho * u ** 2 / (2 * d)
#dp_schlauch = ((lam * l * rho ) / (2) / 100) /d* (u ** 2)  # dp in mbar
print("dp = %s"%dp_schlauch)
#dp_bogen =  zeta * rho /2 /100  * v^2; # dp in Bogen in mbar
#dp_ges = dp_schlauch + n_bogen*dp_bogen


#mass_coolant = A*l *rho

####  coolant pump  ####
#P_pump = dp_ges*100*V_punkt/eta_pump
#mass_pump = 1.66*P_pump/100  #  Annahme der linearen Skalierung aus der trade off study
#mass_total = mass_pump + mass_coolant
#[min_mass, idx_min_mass] = min(mass_total)
#ptwr = (175-0.001*P_pump)/(200+mass_total) #power to weight ratio

# Plots

#figure 1
#plot(d, ptwr)
#hold on
#grid on
#grid minor
#xlabel('diameter / m')
#ylabel('power to weight ratio')
#title('Power to weight ratio')

 
 
#figure 2
#plot (d, mass_coolant)
#hold on
#plot(d,mass_pump)
#plot(d,mass_total)
#plot(min(mass_coolant))
#plot(d(idx_min_mass), min_mass)
#grid on
#grid minor
#xlabel('Hose diameter / m')
#ylabel('coolant mass / kg')
#title('Mass')
#legend('coolant','pump','total')
#axis([min(d) max(d) 0 inf])

#figure 3
#plot(d, P_pump)
#grid on
#grid minor
#xlabel('Hose diameter / m')
#ylabel('P_pump / W')
#title('Pump power')

#figure 4
#plot(d, dp_bogen)
#hold on
#plot(d, dp_schlauch)
#plot(d, dp_ges)
#grid on
#grid minor
#xlabel('Hose diameter / m')
#ylabel('dp / mbar')
#legend('dp_bogen','dp_schlauch','dp_ges')
#title('pressure losses')



