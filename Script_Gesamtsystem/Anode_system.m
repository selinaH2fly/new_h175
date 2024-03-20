%% Matlab script for the Anode system for PS100 as a stationary calculating tool. 

%
%
clear
clc


%% Ask for pressure and temperature and current
I       = input('Enter the required current from stack (A): '); 
p_PT6114  = input('Enter the outlet pressure of the anode (bar), PAsti: '); 
p_H2_0  = input('Enter the outlet pressure of the tank (bar): '); 
T_0  = input('Enter the outlet temperature of the tank (degree celcius): '); 
T_H2_0 = T_0 +273;	

%%=============================
% Standard Parameters
%=============================
R = 8.3145;             % universal gas constant [J/(kg*K)]
F = 96485.33;           % Faraday constant [C/mol]
rho_H2_std = 0.0899;    % density hydrogen [kg/(m^3)] at normal conditions (p = 1.013 bar and T = 0 °C)
rho_N2_std = 1.2506;    % density nitrogen [kg/(m^3)] at normal conditions (p = 1.013 bar and T = 0 °C)
T_std=273;			    % Standard temperarure in K
T_env=273+20;			% Environment temperarure in K
T_max=273+80;			% Max temperarure in K
p_std=1.01325;          % Standard Pressure in bar
M_Water = 18.015*10^(-3);     % molar mass H2O [mol*kg^(-1)]

%=============================
% Anode Parameters
%=============================
n_cell = 455;         % number of cells in stack [-]
Lambda_A_0 = 1.05;
c_H2_0 = 1;           % concentration of hydrogen at tank
V_dot_H2_const=6.97;  %[ml/cell*A*min],H2 Volumetric flow rate 
Kv_ASV=0.8 	;	      %  Kv value of shut-off valve
Kv_APRV=0.8;          %  Kv value of proportional control valve	
Kv_APV=0.64;	      %  Kv value of purge valve	  
Kv_ADV=0.64;          %  Kv value of drain valve	
valve_opening_Purge = 1;       % If Purge valve is on/off, on=1, off=0
valve_opening_Drain = 1;       % If Drain valve is on/off, on=1, off=0
M_Hydrogen = 2.016*10^(-3);     % molar mass hydrogen [mol*kg^(-1)]



%=============================
% Anode Calculation
%=============================

T_H2_0 = T_0 +273;	


% Calculation for ASV VL6110

[V_dot_ASV, m_dot_ASV, m_dot_H2_ASV] =  Valveflow(p_H2_0,T_H2_0,c_H2_0,Kv_ASV,p_PT6114,p_std,T_std,rho_H2_std,0);


% Calculation for Purge Valve APV VL6135

[V_dot_Purge, m_dot_APV, m_dot_H2_APV] =  Valveflow(p_PT6114,353,1,Kv_APV,p_std,p_std,T_std,rho_H2_std,rho_N2_std);

m_dot_Purge = m_dot_APV * valve_opening_Purge ;

m_dot_H2_Purge = m_dot_H2_APV * valve_opening_Purge ;


% Calculation for Drain Valve ADV VL6134

[V_dot_Drain, m_dot_ADV, m_dot_H2_ADV] =  Valveflow(p_PT6114,300,1,Kv_ADV,1,p_std,T_H2_0,rho_H2_std,rho_N2_std);

m_dot_Drain = m_dot_ADV * valve_opening_Drain ;


% H2-mass flow
% 0 denotes the tank, 1 denotes anode outlet (Stack inlet), 
% 2 denotes stack outlet (Recirculation inlet)

m_dot_H2_Stoich = M_Hydrogen * ((n_cell * I) / (2 * F)) * 1000;

%V_N_H2_0 = m_dot_H2_0/rho_H2_std/1000*3600;

m_dot_H2 = m_dot_H2_Stoich + m_dot_H2_Purge;

lambda_A = m_dot_H2 / m_dot_H2_Stoich;

m_dot_H2_1 = I*lambda_A*V_dot_H2_const.*n_cell/(c_H2_0/100*1000)/1000*60*rho_H2_std*10/3600;

m_dot_H2_2 = m_dot_H2_1-m_dot_H2_Stoich;

% Assuming pressure is constant over ASV
% Calculation of required Kv

Kv_APRV_min = kv_prv_min(m_dot_H2,rho_H2_std,T_H2_0,p_H2_0,p_PT6114);
 
Opening_APRV1 = (Kv_APRV_min/Kv_APRV)*100;
Opening_APRV = find_max_opening(Opening_APRV1, 100);


% Calculation for APRV VL6112

[V_dot_APRV, m_dot_APRV, m_dot_H2_APRV] =  Valveflow(p_H2_0,T_H2_0,c_H2_0,Kv_APRV_min,p_PT6114,p_std,T_std,rho_H2_std,0);


% %% Display the results
fprintf('                   \n');
fprintf('------------------\n');
fprintf('Displaying Results\n');
fprintf('------------------\n');
fprintf('                   \n');
fprintf('Required Hydrogen Mass Flow at stack for %d A Current: %.4f g/s\n', I, m_dot_H2_Stoich);
fprintf('Hydrogen Mass Flow from tank: %.4f g/s\n', m_dot_H2);
fprintf('Required percentage opening of APRV: %.4f\n', Opening_APRV);
fprintf('Recirculated Mass Flow : %.4f g/s\n', m_dot_H2_2);
fprintf('Total Mass Flow through Purge valve: %.4f g/s\n', m_dot_H2_Purge);

%% Functions
%-------------

function [V_dot, m_dot, m_dot_H2] = Valveflow(p1,T1,C_H2,Kv,p2,p_std,T_std,...
                                              rho_H2_std,rho_N2_std)
dp = p1 - p2;   % Pressure difference
rho_std = rho_H2_std*C_H2 + rho_N2_std*(1-C_H2);    % density of gas mixture

% distinction of flow characteristics based on pressure drop
if p2/p1 > 0.5
    % low pressure drop - subsonic flow
    V_dot_std_cmph = Kv*514*sqrt(abs((p2*dp)/(T1*rho_std)));    % at standard conditions
  
else 
    % high pressure drop - sonic flow (independent of downstream pressure)
    V_dot_std_cmph = Kv*257*p1*sqrt(1/(T1*rho_std));            % at standard conditions
end

V_dot_cmph = V_dot_std_cmph*(p_std/p1)*(T1/T_std);       % volumetric flow rate [m^3/h] at operating conditions
m_dot = V_dot_std_cmph*rho_std;             % total mass flow rate [kg/h]
m_dot_H2 = V_dot_std_cmph*rho_H2_std*C_H2;  % total hydrogen mass flow rate [kg/h]


% unit conversions
cmph_to_lpm = 1000/60;
V_dot = V_dot_cmph * cmph_to_lpm;   % volumetric flow rate [LPM]
kgph_to_gps = 1000/3600;
m_dot = m_dot*kgph_to_gps;          % total mass flow rate [g/s]
m_dot_H2 = m_dot_H2*kgph_to_gps;    % hydrogen mass flow rate [g/s]
end


function Kv_H2 =  kv_prv_min(m_dot,rho_H2_std,T,p1,p2)
 
V_dot_N = (m_dot * 3600/1000) / rho_H2_std;
 
dp = p1 - p2;   % Pressure difference
if(p2 >= (p1 / 2)) 
    Kv_H2 = (V_dot_N / 514) * sqrt((T * rho_H2_std) / (p2 * dp));
else
     Kv_H2 = (V_dot_N / (257*p1)) * sqrt(T * rho_H2_std);
end
end


function max_value = find_max_opening(a, b)
    % Check if a is greater than or equal to b
    if a >= b
        max_value = b; % If true, return a
    else
        max_value = a; % If false, return b
    end
end
