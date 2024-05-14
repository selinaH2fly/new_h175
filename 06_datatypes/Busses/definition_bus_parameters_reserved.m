%% Reserved Parameters
% These Parameters are reserved for usage with the x90 c-code and toolchain
% and should not be used in Simulink

flagCheckNameLength = true;

RESERVED_Parameters_BusDef = BusParamDef("RESERVED_Parameters", "Descripton goes here");

busElements = [ ... 
    % signal name                   %dim    %datatype   % sample time   %    
    %% service mode signals
    BusSignalParamDef('s_Parameters_MemBankID'       , 0     , 1,    'int32',  -1,     'real', 'Sample','Fixed',  [],  [],    '',          '', {STREAM_LVL.Release, 1});...
    BusSignalParamDef('s_Parameters_Load_bool'       , 0     , 1,    'boolean',  -1,     'real', 'Sample','Fixed',  [],  [],    '',          '', {STREAM_LVL.Release, 1});...
    BusSignalParamDef('s_Parameters_Save_bool'       , 0     , 1,    'boolean',  -1,     'real', 'Sample','Fixed',  [],  [],    '',          '', {STREAM_LVL.Release, 1});...
    BusSignalParamDef('s_Version_Semantic'           , 0     , 1,    'int32',  -1,     'real', 'Sample','Fixed',  [],  [],    '',          '', {STREAM_LVL.Release, 0});...
    BusSignalParamDef('s_Version_Checksum'           , 0     , 1,    'int32',  -1,     'real', 'Sample','Fixed',  [],  [],    '',          '', {STREAM_LVL.Release, 0});...
    BusSignalParamDef('s_Version_Commit'             , 0     , 1,    'int32',  -1,     'real', 'Sample','Fixed',  [],  [],    '',          '', {STREAM_LVL.Release, 0});...
    %
    ];

RESERVED_Parameters_BusDef.AssignBusElements(busElements);


%% clear working variables

clear busElements
clear busName
