% Constants and parameters 

%%=============================
% Standard Parameters
%=============================
R = 8.3145;             % universal gas constant [J/(kg*K)]
F = 96485.33;           % Faraday constant [C/mol]
rho_H2_std = 0.0899;    % density hydrogen [kg/(m^3)] at normal conditions (p = 1.013 bar and T = 0 °C)
rho_N2_std = 1.2506;    % density nitrogen [kg/(m^3)] at normal conditions (p = 1.013 bar and T = 0 °C)
rho_O2_std = 1.429;     % density oxygen [kg/(m^3)] at normal conditions (p = 1.013 bar and T = 0 °C)
rho_air_std = 1.2;      % density oxygen [kg/(m^3)] at normal conditions (p = 1.013 bar and T = 0 °C)
T_std=273;			    % Standard temperarure in K
T_env=273+20;			% Environment temperarure in K
T_max=273+80;			% Max temperarure in K
T_1=273+75;			    % wish temperarure in K
p_std=1.01325;          % Standard Pressure in bar
M_Water = 18.015*10^(-3);     % molar mass hydrogen [mol*kg^(-1)]

%=============================
% Stack Parameters
%=============================
n_cell = 455;                   % number of cells in stack [-]
A_Cell = 300;                   % active cell area [cm^2]
I_stack = [0 1.296 10.56 23.94 46.06 61.5 69.84 91.53 114.5 136.1 180.8 226.6 271.2 315.4 360 405.5 450.1 495.1 540.1 570.1];
U_stack = [1.23 0.9681 0.8977 0.8681 0.8393 0.8216 1.6 0.8033 0.7908 0.7783 0.7541 0.7366 0.7198 0.7023 0.6855 0.6673 0.6557 0.6359 0.614 0.5993];

%=============================
% Anode Parameters
%=============================
Lambda_A_0 = 1.05;
Lambda_A_1 = 1.5;
c_H2_0 = 1;           % concentration of hydrogen at tank
c_H2_1 = 0.7;         % concentration of hydrogen anode outlet
V_dot_H2_const=6.97;  %[ml/cell*A*min],H2 Volumetric flow rate 
Kv_ASV=0.8 	;	      %  Kv value of shut-off valve
Kv_APRV=0.8;          %  Kv value of proportional control valve	
Kv_APV=0.64;	      %  Kv value of purge valve	  
Kv_ADV=0.64;          %  Kv value of drain valve	
valve_opening_Purge = 1;       % If Purge valve is on/off, on=1, off=0
valve_opening_Drain = 1;       % If Drain valve is on/off, on=1, off=0
M_Hydrogen = 2.016*10^(-3);     % molar mass hydrogen [mol*kg^(-1)]

%=============================
% Cathode Parameters
%=============================
c_O2_0 = 0.2095;               % concentration oxygen
RH_0 = 0.5;                    % Relative humidity
M_Oxygen = 31.998*10^(-3);     % molar mass hydrogen [mol*kg^(-1)]
M_Air = 28.964*10^(-3);        % molar mass air [mol/kg]
R_Air = R/M_Air/1000;          % Specific gas constant for dry air in kJ/kg*K
P_sat_const = 0.611; % Saturation vapor pressure constant in kPa
I_stoic = [0, 100, 200, 300, 400, 450, 600];
stoic_cathode = [2.3, 2.3, 2.2, 2, 1.8, 1.6, 1.6];
cp_Air = 1005;                      % isobaric specific heat air [J/(kg*K)]
isentropic_coefficient_Air = 1.41;  % isentropic coefficient gamma (kappa) air [-]
eta_Compressor = 0.6;
eta_Motor = 0.95;
eta_PE = 0.95;
%=============================
% Cooling Parameters
%=============================
c_glycol_0 = 0.5;           % concentration glycol
V_dot_cooling = 120/60000;         %[m3/s]
I_cool = [0 20 45 100 250 350 400 600];
T_inlet = [50 50 55 68 68 68 68 68];
%=============================
% Electrical Parameters
%=============================



