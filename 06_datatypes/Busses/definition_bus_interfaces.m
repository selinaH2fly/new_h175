flagCheckNameLength = true;

%% UserInterface_OUT

UserInterface_OUT_BusDef = BusDef("UserInterface_OUT", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    % Anode Sensors
    BusSignalDef('s_HCTRL_Ext_AlarmShutdown'                         , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmSensorCheck10'                    , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmSensorCheck11'                    , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmSensorCheck20'                    , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_HCTRL_Ext_AlarmSensorCheck21'   , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_HCTRL_Ext_AlarmCmpPrt_Warn10'   , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmCmpPrt_Warn11'   , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmCmpPrt_Warn20'   , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmCmpPrt_Warn21'   , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmCmpPrt_Caut10'   , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmCmpPrt_Caut11'   , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmCmpPrt_Caut20'   , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmCmpPrt_Caut21'   , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmFaultID10'       , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmFaultID11'       , 1,    'uint32',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_AlarmStop'                             , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_Warning'                               , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_CurReq'                                , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_enum_StateAct'                         , 1,    'Enum: OMM_STATE_FOR_LABVIEW',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_StartPrecondDe'                        , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_NumOfStartup'                          , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_PowLimReason'                          , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_MinPow'                                , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_MaxPow'                                , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_MinCur'                                , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_MaxCur'                                , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_PurgeActive'                           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_SM_State_enum'                                   , 1,    'Enum: SM_STATE',       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_SM_Component_enum'                               , 1,    'Enum: SM_COMPONENT',   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_SM_StateWhileFault_enum'                         , 1,    'Enum: OMM_STATE',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_SensorsCheck_AllOK_bool'                         , 1 ,   'boolean',   		    -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_FaultySensorsList_enum'                          , 31 ,  'Enum: SENSOR',   		-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_SM_CmpPrt_AllOK_bool'               , 1 ,   'boolean',   		    -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_SM_List_CmpPrt_Component'           , 30 ,  'Enum: SM_COMPONENT',   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_SM_List_CmpPrt_Issue'               , 30 ,  'Enum: SM_STATE',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('b_SafetyMonitorWhileFault'                         , 1 ,   'Bus: SM',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_AutoShutdown_Electrical'                         , 1 ,   'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_CurReqSubsys'                          , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    BusSignalDef('s_HCTRL_Ext_ManualMode_PIN_FB'                     , 1,    'Enum: PIN_CHECK',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    ];

UserInterface_OUT_BusDef.AssignBusElements(busElements);

UserInterface_OUT_BusDef.GenerateRespectiveDatatypeStructures();


%% UserInterface_IN

UserInterface_IN_BusDef = BusDef("UserInterface_IN", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    % Anode Sensors
    BusSignalDef('s_Ext_CurReq'                 , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'request current from System'                                               , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_PowReq'                 , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  ''                                                                          , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_RequestType'            , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Powerrequest = 0 ; Current request = 1'                                    , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_enum_StateReq'          , 1,    'Enum: OMM_STATE_CMD',  -1,     'real', 'Sample','Fixed',  [],  [],    '',  'request for system state'                                                  , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_ResetAlarmSD'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'reset all errors'                                                          , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_ResetAlarmStop'         , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'reset all errors'                                                          , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_ResetWarning'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'reset all errors'                                                          , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CoolPumpHTReq'          , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'request to activate HT circuit (Valeo pumps and valves). Only in standby'  , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CoolPumpLTReq'          , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'request to activate LT circuit (EMP pump and valves).Only in standby'      , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_PurgeReq'               , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'request to purge anode. Only in standby'                                   , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_PurgeManualTrigger'     , 1,    'boolean',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Purge signal when manual mode is activated'                                , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_DrainManualTrigger'     , 1,    'boolean',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Drain signal when manual mode is activated'                                , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_DrainManualTrigger2'     , 1,    'boolean',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Drain signal when manual mode is activated'                                , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_TCVManuallyEnable'      , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable TCV Opening Manually'                                               , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_TCVManually'            , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening percentage for TCV when manual mode is activated'                  , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CHUBVdManuallyEnable'   , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable CHUBVd Opening Manually'                                            , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CHUBVdManually'         , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening Percentage for CHUBVd when manual mode is activated'               , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CHUBVwManuallyEnable'   , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable CHUBVw Opening Manully'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CHUBVwManually'         , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening Percentage for ASV when manual mode is activated'               , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_ASVManuallyEnable'      , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    ''       ,  'Enable ARP1 Operation Manually'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_ASVManually'            , 1,    'boolean',               -1,     'real', 'Sample','Fixed',  [],  [],    'rpm'    ,   'rpm for ARP1 when manual mode is activated'                                , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_APRV1ManuallyEnable'     , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    ''       ,  'Enable ARP1 Operation Manually'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_APRV1Manually'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    'rpm'    ,   'rpm for ARP1 when manual mode is activated'                                , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_APRV2ManuallyEnable'     , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    ''       ,  'Enable ARP1 Operation Manually'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_APRV2Manually'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    'rpm'    ,   'rpm for ARP1 when manual mode is activated'                                , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_APRV3ManuallyEnable'     , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    ''       ,  'Enable ARP1 Operation Manually'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_APRV3Manually'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    'rpm'    ,   'rpm for ARP1 when manual mode is activated'                                , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_ARP1ManuallyEnable'     , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    ''       ,  'Enable ARP1 Operation Manually'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_ARP1Manually'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    'rpm'    ,   'rpm for ARP1 when manual mode is activated'                                , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_ARP2ManuallyEnable'     , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable ARP2 Operation Manually'                                             , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_ARP2Manually'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    'rpm',  'rpm for ARP2 when manual mode is activated'               , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CBVManuallyEnable'      , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable CBV Opening Manually'                                             , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_CBVManually'            , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening Percentage for CBV when manual mode is activated'               , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CSIVManuallyEnable'     , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable CSIV Opening Manually'                                             , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_CSIVManually'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening Percentage for CSIV when manual mode is activated'               , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CSOVManuallyEnable'     , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable CSOV Opening Manually'                                             , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_CSOVManually'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening Percentage for CSOV when manual mode is activated'               , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_TCPManuallyEnable'      , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable TCP Operation Manually'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_TCPManually'            , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    'rpm',  'rpm for TCP when manual mode is activated'               , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_ETVManuallyEnable'      , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable ETV Opening Manually'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_ETVManually'            , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening Percentage for ETV when manual mode is activated'               , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_EATBVManuallyEnable'    , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable EATBV Opening Manually'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_EATBVManually'          , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening Percentage for EATBV when manual mode is activated'               , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_CHXVManuallyEnable'     , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable CHXV Opening Manually'                                             , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_CHXVManually'           , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening Percentage for CHXV when manual mode is activated'               , {STREAM_LVL.Release, 1});
	BusSignalDef('s_Ext_TDVManuallyEnable'      , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Enable TDV Opening Manually'                                             , {STREAM_LVL.Release, 1});  
	BusSignalDef('s_Ext_TDVManually'            , 1,    'boolean',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'Opening Percentage for TDV when manual mode is activated'               , {STREAM_LVL.Release, 1});
    BusSignalDef('s_Ext_LCON_Plus_MM_Enable',         1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_Ext_LCON_Plus_MM_signal',       1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});   
    BusSignalDef('s_Ext_LCON_Minus_MM_Enable',        1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_Ext_LCON_Minus_MM_signal',      1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});   
    BusSignalDef('s_Ext_LCON_PreCh_MM_Enable',        1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_Ext_LCON_PreCh_MM_signal',      1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});   
    BusSignalDef('s_Ext_HVCON_Plus_MM_Enable',        1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_Ext_HVCON_Plus_MM_signal',      1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});  
    BusSignalDef('s_Ext_HVCON_PreCh_MM_Enable',       1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_Ext_HVCON_PreCh_MM_signal',     1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});  
    BusSignalDef('s_Ext_LVCON_Plus_MM_Enable',        1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_Ext_LVCON_Plus_MM_signal',      1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});      
    BusSignalDef('s_Ext_ManualMode_PIN_signal',             1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});      
    BusSignalDef('s_Ext_ManualMode_PIN_submit',             1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});      
    BusSignalDef('s_Ext_ManualMode_termination',            1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});      
    BusSignalDef('s_st_enum_UI_Get',                    1,    'Enum: SENS_STATUS',    -1,     'real', 'Sample','Fixed',  [],  [],    '',  'State of CAN3 UserInterface communication'                                 , {STREAM_LVL.All, 1});
    ];

UserInterface_IN_BusDef.AssignBusElements(busElements);

UserInterface_IN_BusDef.GenerateRespectiveDatatypeStructures();

%% UICommands

UICommands_BusDef = BusDef("UICommands", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    % Anode Sensors
    BusSignalDef('s_StateCmd_enum'              , 1,    'Enum: OMM_STATE_CMD',          -1,     'real', 'Sample','Fixed',   [],     [],     '',     'introduce to b_UserInterface_IN', {STREAM_LVL.All, 1});
    BusSignalDef('s_State_TH_enum'              , 1,    'Enum: OMM_STATE',              -1,     'real', 'Sample','Fixed',   [],     [],     '',     'introduce to b_UserInterface_IN', {STREAM_LVL.All, 1});
    BusSignalDef('s_ShutdownCmd_bool'           , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',   [],     [],     '',     'introduce to b_UserInterface_IN', {STREAM_LVL.All, 1});
    BusSignalDef('s_EmergencyShutdownCmd_bool'  , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',   [],     [],     '',     'introduce to b_UserInterface_IN', {STREAM_LVL.All, 1});
    BusSignalDef('s_Req_Connect_Load_bool'      , 1,    'single',                       -1,     'real', 'Sample','Fixed',   [],     [],     '',     'introduce to b_UserInterface_IN', {STREAM_LVL.All, 1});
    BusSignalDef('s_Mtc_ResolveAStiLowPressure'         , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'only in maintenance standby', {STREAM_LVL.All, 1});
    BusSignalDef('s_Mtc_ResolveAPRViHighPressure'         , 1,    'single',               -1,     'real', 'Sample','Fixed',  [],  [],    '',  'only in maintenance standby', {STREAM_LVL.All, 1});
    ];

UICommands_BusDef.AssignBusElements(busElements);

UICommands_BusDef.GenerateRespectiveDatatypeStructures();

%% UserInterface_Helpers

UserInterface_Helpers_BusDef = BusDef("UserInterface_Helpers", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_AutoShutdown_Electrical'                , 1 ,   'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.All, 1});
    BusSignalDef('s_SensActOffMsg_enable'                , 1 ,   'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.All, 1});
    ];

UserInterface_Helpers_BusDef.AssignBusElements(busElements);

UserInterface_Helpers_BusDef.GenerateRespectiveDatatypeStructures();


%% clear working variables

clear busElements
clear busName
