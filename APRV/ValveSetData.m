%% Set data point for proportioanl valve flow rate calculation

hysteresisValve = 0.15;  %from Datasheet
responseTimeValve = 0.03; %from Datasheet

%The Relationship between Cv and Kv is
%Cv = 1.156 Kv OR Kv = 0.864 Cv.
flowCoefficientValve = 1.156 * 0.32;   %CV value 


T_S = 273;                          %Standard temperature, k
p_S = 1.01;                         %Standard pressure, bar
pinlet = 12;                        %in bara
poutlet = 1.2;                       %in bara
N2 = 6950 ;                         %Numerical Constants for Flow Equations
StddensityHydrogen = 0.0899;        %Standard density
SpecificGravityHydrogen = 0.0696;
universalGasConstant1 = 8.3145;     %J·K-1·mol-1
universalGasConstant2 = 0.08314;    %L·atm·K-1·mol-1
molarMassHydrogen = 2.016;           %g·mol-1

OperatingTemperature = T_S+27;   

%%Calculating density of hydrogen for specific pressure and temperature 

densityHydrogen = poutlet*(molarMassHydrogen/1000)/(universalGasConstant2*0.001)/OperatingTemperature;


