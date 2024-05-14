% This script creates "sim_data" buses carrying simulated data of interest
% that are not containted in the real-world sensor reading.

%% thermal simulation data

ThermalSim = Simulink.Bus;

thermal_sim_elements(1) = Simulink.BusElement;
thermal_sim_elements(1).Name = 's_p_bara_CLSto_Sim';
thermal_sim_elements(1).DataType = 'single';

thermal_sim_elements(2) = Simulink.BusElement;
thermal_sim_elements(2).Name = 's_VDot_lpm_STCL_Sim';
thermal_sim_elements(2).DataType = 'single';

thermal_sim_elements(3) = Simulink.BusElement;
thermal_sim_elements(3).Name = 's_VDot_lpm_MixCold_Sim';
thermal_sim_elements(3).DataType = 'single';

thermal_sim_elements(4) = Simulink.BusElement;
thermal_sim_elements(4).Name = 's_VDot_lpm_MixHot_Sim';
thermal_sim_elements(4).DataType = 'single';

thermal_sim_elements(5) = Simulink.BusElement;
thermal_sim_elements(5).Name = 's_VDot_lpm_ByP_Sim';
thermal_sim_elements(5).DataType = 'single';

thermal_sim_elements(6) = Simulink.BusElement;
thermal_sim_elements(6).Name = 's_VDot_lpm_Rad_Sim';
thermal_sim_elements(6).DataType = 'single';

ThermalSim.Elements = thermal_sim_elements;

