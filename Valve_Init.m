%% load Hydrogen Property
load('HydrogenProperty.mat')

%%Define constants
T_S = 273;                          %Standard temperature, k
p_S = 1.01;                         %Standard pressure, bar
pinlet = 12;                        %in bara
poutlet = 1.0;                       %in bara
N2 = 6950 ;                         %Numerical Constants for Flow Equations
densityHydrogen = 0.0899;        %Standard density
SpecificGravityHydrogen = 0.0696;
universalGasConstant1 = 8.3145;     %J·K-1·mol-1
universalGasConstant2 = 0.08314;    %L·atm·K-1·mol-1
molarMassHydrogen = 2.016e-3;		% Hydrogen Molar Mass (kg.mol-1)
OperatingTemperature = T_S+25;   
anodeInletPathVolume = 0.03584;
