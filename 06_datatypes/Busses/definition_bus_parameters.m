flagCheckNameLength = true;

%% define sub-busses

parameterValues = {};

Parameters_BusDef = BusParamDef("Parameters", "Description goes here");  

definition_bus_parameters_anode
AN_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(AN_Parameters_BusDef);

definition_bus_parameters_cathode
CAT_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(CAT_Parameters_BusDef);

definition_bus_parameters_thermal
TH_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(TH_Parameters_BusDef);

definition_bus_parameters_ecooling
ECCL_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(ECCL_Parameters_BusDef);

definition_bus_parameters_electrical
EL_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(EL_Parameters_BusDef);

definition_bus_parameters_omm
OMM_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(OMM_Parameters_BusDef);
 
definition_bus_parameters_emergency
EM_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(EM_Parameters_BusDef);
 
definition_bus_parameters_safetyMonitor
SM_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(SM_Parameters_BusDef);

definition_bus_parameters_mbc
MBC_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(MBC_Parameters_BusDef);
 
definition_bus_parameters_general
GEN_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(GEN_Parameters_BusDef);
 
definition_bus_parameters_service
SERVICE_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(SERVICE_Parameters_BusDef);
 
definition_bus_parameters_reserved
RESERVED_Parameters_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Parameters_BusDef.AssignBusElements(RESERVED_Parameters_BusDef);

Parameters_BusDef.GenerateRespectiveDatatypeStructures();

%% build parameters bus

%busName = "Parameters";
%busElements = { ... 
    % signal name               %dim    %datatype   % sample time   %
    % Anode Sensors
%    {'b_AN_Parameters'      , 1,    'Bus: AN_Parameters',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_CAT_Parameters'     , 1,    'Bus: CAT_Parameters',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_TH_Parameters'      , 1,    'Bus: TH_Parameters',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_ECCL_Parameters'    , 1,    'Bus: ECCL_Parameters',     -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_EL_Parameters'      , 1,    'Bus: EL_Parameters',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_SM_Parameters'      , 1,    'Bus: SM_Parameters',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_OMM_Parameters'     , 1,    'Bus: OMM_Parameters',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_EM_Parameters'      , 1,    'Bus: EM_Parameters',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_MBC_Parameters'     , 1,    'Bus: MBC_Parameters',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_GEN_Parameters'     , 1,    'Bus: GEN_Parameters',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_SERVICE_Parameters' , 1,    'Bus: SERVICE_Parameters',  -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    {'b_RESERVED_Parameters', 1,    'Bus: RESERVED_Parameters', -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}};...
%    };
%declareBusAndInitStructAndMeta(busName, busElements, flagCheckNameLength);

% init parameter struct
%initTopLevelParameterBusses(busName);

%% clear working variables

clear busElements
clear busName
