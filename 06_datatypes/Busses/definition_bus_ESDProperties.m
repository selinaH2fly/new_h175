flagCheckNameLength = true;

%% ESD Bus

busName = "ESDProperties";

ESDProperties_BusDef = BusParamDef("ESDProperties", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %    
    BusSignalParamDef('s_CoolingMode'          , STCL_STATE_SAFETY.Safe          , 1,  'Enum: STCL_STATE_SAFETY' ,   -1  , 'real', 'Sample','Fixed',   [], [],     '', '', {STREAM_LVL.Debug, 1});...
    BusSignalParamDef('s_CompressorOff'        , false                           , 1,  'boolean'                 ,   -1  , 'real', 'Sample','Fixed',   [], [],     '', '', {STREAM_LVL.Debug, 1});...
    BusSignalParamDef('s_ClosedASV'            , false                           , 1,  'boolean'                 ,   -1  , 'real', 'Sample','Fixed',   [], [],     '', '', {STREAM_LVL.Debug, 1});...
    BusSignalParamDef('s_DisconnectLoadMode'   , ESD_DLM.OpenRelays              , 1,  'Enum: ESD_DLM'           ,   -1  , 'real', 'Sample','Fixed',   [], [],     '', '', {STREAM_LVL.Debug, 1});...
    BusSignalParamDef('s_SD_Procedure'         , SD_PROCEDURE.SD_NONE            , 1,  'Enum: SD_PROCEDURE'      ,   -1  , 'real', 'Sample','Fixed',   [], [],     '', '', {STREAM_LVL.Debug, 1});...
    ];

ESDProperties_BusDef.AssignBusElements(busElements);

%% Generate Sensor Busses

ESDProperties_BusDef.GenerateRespectiveDatatypeStructures();
