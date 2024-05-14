flagCheckNameLength = true;


%% CAT_ManualMode

AN_ManualMode_BusDef = BusDef("AN_ManualMode", "Descripton goes here");


busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    % Anode Sensors
    BusSignalDef('s_APRV1_ManualMode_bool'       , 1,    'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_APRV1_ManualMode_signal'     , 1,    'single',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_APRV2_ManualMode_bool'       , 1,    'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_APRV2_ManualMode_signal'     , 1,    'single',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_APRV3_ManualMode_bool'       , 1,    'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_APRV3_ManualMode_signal'     , 1,    'single',       -1,    'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    ];

AN_ManualMode_BusDef.AssignBusElements(busElements);

AN_ManualMode_BusDef.GenerateRespectiveDatatypeStructures();

%% CAT_ManualMode

CAT_ManualMode_BusDef = BusDef("CAT_ManualMode", "Descripton goes here");


busElements = [ ...
    % signal name               %dim    %datatype   % sample time   %
    % Anode Sensors
    BusSignalDef('s_ETV_ManualMode_bool'        , 1,    'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_ETV_ManualMode_signal'      , 1,    'single',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_EATBV_ManualMode_bool'      , 1,    'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_EATBV_ManualMode_signal'    , 1,    'single',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_TDV_ManualMode_bool'        , 1,    'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_TDV_ManualMode_signal'      , 1,    'boolean',       -1,    'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_CBV_ManualMode_bool'        , 1,    'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_CBV_ManualMode_signal'      , 1,    'single',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    ];

CAT_ManualMode_BusDef.AssignBusElements(busElements);

CAT_ManualMode_BusDef.GenerateRespectiveDatatypeStructures();

%% TH_ManualMode

TH_ManualMode_IN_BusDef = BusDef("TH_ManualMode", "Descripton goes here");

busElements = [ ...
    % signal name               %dim    %datatype   % sample time   %
    % Anode Sensors
    BusSignalDef('s_TCV_ManualMode_bool'        , 1,    'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_TCV_ManualMode_signal'      , 1,    'single',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_TCP_ManualMode_bool'        , 1,    'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_TCP_ManualMode_signal'      , 1,    'single',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    ];

TH_ManualMode_IN_BusDef.AssignBusElements(busElements);

TH_ManualMode_IN_BusDef.GenerateRespectiveDatatypeStructures();

%% SystemHealth

SystemHealth_BusDef = BusDef("SystemHealth", "This bus holds information about the operation and health state of the system");

busElements = [ ...
    % signal name               %dim    %datatype   % sample time   %
    % Anode Sensors
    BusSignalDef('s_I_A_StN_Get'            , 1,    'single',                  -1,     'real', 'Sample','Fixed',  [],  [],    'A',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_OperationState_enum'    , 1,    'Enum: OPERATION_STATE',    -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_IREQ_State_enum'        , 1,    'Enum: IREQ_STATE',    -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_IREQ_State_Safety_enum' , 1,    'Enum: IREQ_STATE_SAFETY',    -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_CurReqDerated_I_A'      , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_CurReqDelayed_I_A'      , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_CurReqAllowed_I_A'      , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_CurReqToSubsystems_I_A' , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_CurReqToLoad_I_A'       , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_CurReqExtern_I_A'       , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_DeratingSurge_bool'     , 1,    'boolean',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_DeratingTemp_bool'      , 1,    'boolean',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_DeratingHX_bool'        , 1,    'boolean',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    ];

SystemHealth_BusDef.AssignBusElements(busElements);

SystemHealth_BusDef.GenerateRespectiveDatatypeStructures();
clear busElements
clear busName