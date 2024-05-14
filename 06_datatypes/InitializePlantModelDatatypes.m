%% clear worksapce


%% scripts for project initialization
fprintf("\n\n")
fprintf(2,"Run scripts\n")
fprintf(2,"------------------------------------------------\n")

% Sensors Bus
fprintf("-->\t /datatypes/Busses/definition_bus_sensors.m ...")
definition_bus_sensors
fprintf("\t done! \n")

% Actuators Bus
fprintf("-->\t /datatypes/Busses/definition_bus_actuators.m ...")
definition_bus_actuators
fprintf("\t done! \n")

% SafetyMonitor Bus
fprintf("-->\t /datatypes/Busses/definition_bus_safetyMonitor.m ...")
definition_bus_safetyMonitor
fprintf("\t \t done! \n")

% UI Commands
fprintf("-->\t /datatypes/Structures/definition_bus_interfaces.m ...")
definition_bus_interfaces
fprintf("\t done! \n")

% Parameters
fprintf("-->\t /datatypes/Structures/definition_bus_parameters.m ...")
definition_bus_parameters
fprintf("\t done! \n")

%load config
fprintf("-->configure variant ...")
variant_config;

sim_data_bus_definitions;
init_sim_data_clean;

thermal_plant_h2f175_parameters;
thermal_plant_peripherals_parameters;
thermal_sim_elements;
thermal_variants_config;

ts = 0.02;
% load SIL inputs into workspace for TET measurement with SIL
%load('controllerInputMapping2.mat')

fprintf("\n")
fprintf("succesfully initialized!")
fprintf("\n\n")