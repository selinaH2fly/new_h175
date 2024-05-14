%% clear worksapce
%% heading

fprintf("\n")
fprintf("####################################################################\n")
fprintf("#            htrcl_v1_controller project startup                   #\n")
fprintf("####################################################################\n")
fprintf("\n")
fprintf("This is executed by the script '/scripts/startScript.m' as startup script of simulink project \n")

%% useful git commands

fprintf("\n")
fprintf(2,"git status\n")
fprintf(2,"---------------------------------------------------------------------------------\n")
!git status

fprintf(2, "git log --oneline\n")
fprintf(2,"---------------------------------------------------------------------------------\n")
!git log -10 --pretty=format:"%h%x09%x09%an%x09%x09%ad%x09%s"

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

% OMM Bus
fprintf("-->\t /datatypes/Busses/definition_bus_omm.m ...")
definition_bus_omm
fprintf("\t \t done! \n")

% ESDProperties
fprintf("-->\t /datatypes/Busses/definition_bus_ESDProperties.m ...")
definition_bus_ESDProperties
fprintf("\t \t done! \n")

% SafetyMonitor Bus
fprintf("-->\t /datatypes/Busses/definition_bus_safetyMonitor.m ...")
definition_bus_safetyMonitor
fprintf("\t \t done! \n")

% Monitors Bus
%fprintf("-->\t /datatypes/Structures/definition_bus_monitors.m ...")
%definition_bus_monitors
%fprintf("\t done! \n")

% UI Commands
fprintf("-->\t /datatypes/Structures/definition_bus_interfaces.m ...")
definition_bus_interfaces
fprintf("\t done! \n")

% Parameters
fprintf("-->\t /datatypes/Structures/definition_bus_parameters.m ...")
definition_bus_parameters
fprintf("\t done! \n")

% Safety Monitor Bus 
%fprintf("-->\t /datatypes/Structures/definition_bus_safety_monitors.m ...")
%definition_bus_safety_monitor
%fprintf("\t done! \n")

% Logging Bus
fprintf("-->\t /datatypes/Parameters/definition_bus_logging.m ...")
definition_bus_logging
fprintf("\t done! \n")

% parameter model
fprintf("-->\t /datatypes/Parameters/definition_parameter_model.m ...")
%definition_parameters_model
fprintf("\t done! \n")

% parameter model setpoints
%fprintf("-->\t /datatypes/Parameters/definition_parameter_model_setpoints.m ...")
%definition_parameters_model_setpoints
%fprintf("\t done! \n")

% init parameter Initialization
%fprintf("-->\t /datatypes/Parameter/init_parameter.m ...")
%init_parameter
%fprintf("\t done! \n")

%init local model busses
%fprintf("-->\t /datatypes/Busses/definition_bus_local.m")
%definition_bus_local
%fprintf("\t done! \n")


%define persistent Values
%fprintf("-->\t /datatypes/Busses/definition_persistentValues.m ...")
%definition_bus_persistentValues
%fprintf("\t done! \n")

%load persistent Values
%fprintf("-->\t /scripts/loadPersistentValues.m ...")
%init_persistentValues
%fprintf("\t done! \n")

sim_data_bus_definitions;

%load config
fprintf("-->configure variant ...")
variant_config

sim_data_bus_definitions
init_sim_data_clean

thermal_plant_h2f175_parameters
thermal_plant_peripherals_parameters
thermal_sim_elements

% Generate Parameter List xlsx
% Parameters_BusDef.ExportParameterList("ParameterList.xlsx");

ts = 0.02;
% load SIL inputs into workspace for TET measurement with SIL
%load('controllerInputMapping2.mat')

fprintf("\n")
fprintf("succesfully initialized!")
fprintf("\n\n")