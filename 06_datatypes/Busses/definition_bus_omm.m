flagCheckNameLength = false;

%% OMM_Anode_Set

OMM_Anode_Set_BusDef = BusDef("OMM_Anode_Set", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_APD_StateSetREQ_enum'           , 1,    'Enum: APD_STATE',          -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_APD_EventREQ_enum'              , 1,    'Enum: APD_STATE',          -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1});
    BusSignalDef('s_APD_ForceShutdownState_enum'    , 1,    'Enum: APD_STATE_SAFETY',   -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APV_ManualTrigger_bool'         , 1,    'boolean',                  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APV_ForceState_enum'            , 1,    'Enum: DVLV_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ADV_ForceState_enum'            , 1,    'Enum: DVLV_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ADV_ManualTrigger_bool'         , 1,    'boolean',                  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ADV_ManualTrigger2_bool'        , 1,    'boolean',                  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APRES_StateSetREQ_enum'         , 1,    'Enum: APRES_STATE',        -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APRES_ForceShutdownState_enum'  , 1,    'Enum: APRES_STATE_SAFETY', -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APRES_ControllerReset_bool'     , 1,    'boolean',                  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1});  
    BusSignalDef('s_APRV_ForceState_enum'           , 1,    'Enum: DVLV_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APRV1_ManualMode_bool'          , 1,    'boolean',                  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APRV1_ManualMode_signal'        , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_APRV2_ManualMode_bool'          , 1,    'boolean',                  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APRV2_ManualMode_signal'        , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_APRV3_ManualMode_bool'          , 1,    'boolean',                  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APRV3_ManualMode_signal'        , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});  
    BusSignalDef('s_ARECI_StateSetREQ_enum'         , 1,    'Enum: ARECI_STATE',        -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ARECI_ForceShutdown_State_enum' , 1,    'Enum: ARECI_STATE_SAFETY', -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ARP1_ManualMode_bool'          , 1,    'boolean',                  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ARP1_ManualMode_signal'        , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_ARP2_ManualMode_bool'          , 1,    'boolean',                  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ARP2_ManualMode_signal'        , 1,    'single',                   -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});        
    BusSignalDef('s_ASEP_ForceState_enum'           , 1,    'Enum: DVLV_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ASV_ManualMode_bool'            , 1,    'boolean',              -1,     'real', 'Sample','Fixed',  [],  [],    ''       ,  'Enable ARP1 Operation Manually'                                             , {STREAM_LVL.All, 1}); 
    BusSignalDef('s_ASV_ManualMode_signal'          , 1,    'boolean',               -1,     'real', 'Sample','Fixed',  [],  [],    'rpm'    ,   'rpm for ARP1 when manual mode is activated'                                , {STREAM_LVL.All, 1}); 	
    ];


OMM_Anode_Set_BusDef.AssignBusElements(busElements);

%% OMM_Cathode_Set

OMM_Cathode_Set_BusDef = BusDef("OMM_Cathode_Set", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_CAC_StateSetREQ_enum'           , 1,    'Enum: CAC_STATE',              -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CAC_ForceShutdownState_enum'    , 1,    'Enum: CAC_STATE_SAFETY',       -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CBV_ForceState_enum'            , 1,    'Enum: DVLV_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_EAC_ForceState_enum'            , 1,    'Enum: PUMP_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_EAC_mDotControllerReset_bool'   , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ETV_ManualMode_bool'            , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ETV_ManualMode_signal'          , 1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_EATBV_ManualMode_bool'          , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_EATBV_ManualMode_signal'        , 1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_TDV_ManualMode_bool'            , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_TDV_ManualMode_signal'          , 1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});  
    BusSignalDef('s_AIRCL_StateSetREQ_enum'         , 1,    'Enum: AIRCL_STATE',            -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_AIRCL_ForceShutdownState_enum'  , 1,    'Enum: AIRCL_STATE_SAFETY',     -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_AIRCL_ControllerReset_bool'     , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_CHXV_ForceState_enum'           , 1,    'Enum: DVLV_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CHXV_ManualMode_bool'           , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CHXV_ManualMode_signal'         , 1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSEP_StateSetREQ_enum'          , 1,    'Enum: CSEP_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSEP_ForceShutdownState_enum'   , 1,    'Enum: CSEP_STATE_SAFETY',      -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSIV_ForceState_enum'           , 1,    'Enum: DVLV_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSOV_ForceState_enum'           , 1,    'Enum: DVLV_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSIV_ManualMode_bool'           , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSIV_ManualMode_signal'         , 1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSOV_ManualMode_bool'           , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSOV_ManualMode_signal'         , 1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});      
    BusSignalDef('s_CStoBlV_ForceShutdownState_enum', 1,    'Enum: CSTOBLV_STATE_SAFETY',   -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CStoBlV_ForceState_enum'        , 1,    'Enum: DVLV_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CBV_ManualMode_bool'            , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CBV_ManualMode_signal'          , 1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_CHU_StateSetREQ_enum'           , 1,    'Enum: CHU_STATE',              -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CHU_ForceShutdownState_enum'    , 1,    'Enum: CHU_STATE_SAFETY',       -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CHUBVd_ManualMode_bool'         , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});   
    BusSignalDef('s_CHUBVd_ManualSignal_pos_percent', 1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_CHUBVw_ManualMode_bool'         , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_CHUBVw_ManualSignal_pos_percent', 1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    ];


OMM_Cathode_Set_BusDef.AssignBusElements(busElements);


%% OMM_ECCL_Set

OMM_ECCL_Set_BusDef = BusDef("OMM_ECCL_Set", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_ECCL_StateSetREQ_enum',         1,    'Enum: ECCL_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ECCL_ForceShutdownState_enum',  1,    'Enum: ECCL_STATE_SAFETY',  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ETCP_ForceState_enum',          1,    'Enum: PUMP_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ECCL_ControllerReset_bool',     1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    ];


OMM_ECCL_Set_BusDef.AssignBusElements(busElements);


%% OMM_Thermal_Set

OMM_Thermal_Set_BusDef = BusDef("OMM_Thermal_Set", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_STCL_StateSetREQ_enum',         1,    'Enum: STCL_STATE',           -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_STCL_ForceShutdownState_enum',  1,    'Enum: STCL_STATE_SAFETY',    -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_STCL_T_ControllerReset_bool',   1,    'boolean',                    -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_STCL_p_ControllerReset_bool',   1,    'boolean',                    -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_TCP_ForceState_enum',           1,    'Enum: PUMP_STATE',           -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_TCP_ManualMode_bool'          , 1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_TCP_ManualMode_signal'        , 1,    'single',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});        
    BusSignalDef('s_TCV_ForceState_enum',           1,    'Enum: DVLV_STATE',           -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_TCV_ManualMode_bool',            1,    'boolean',                    -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_TCV_ManualSignal_pos_percent',  1,    'single',                     -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_auxTCP_ForceState_enum',        1,    'Enum: PUMP_STATE',           -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    ];

OMM_Thermal_Set_BusDef.AssignBusElements(busElements);

%% OMM_Electrical_Set

OMM_Electrical_Set_BusDef = BusDef("OMM_Electrical_Set", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_LCON_StateSetREQ_enum',             1,    'Enum: LCON_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LCON_ForceShutdownState_enum',      1,    'Enum: LCON_STATE_SAFETY',      -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LCON_Plus_ManualMode_enable',         1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LCON_Plus_ManualMode_signal',       1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_LCON_Minus_ManualMode_enable',        1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LCON_Minus_ManualMode_signal',      1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_LCON_PreCh_ManualMode_enable',        1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LCON_PreCh_ManualMode_signal',      1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});    
    BusSignalDef('s_HVCON_StateSetREQ_enum',            1,    'Enum: HVCON_STATE',            -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_HVCON_ForceShutdownState_enum',     1,    'Enum: HVCON_STATE_SAFETY',     -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_HVCON_Plus_ManualMode_enable',        1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_HVCON_Plus_ManualMode_signal',      1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});   
    BusSignalDef('s_HVCON_PreCh_ManualMode_enable',       1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_HVCON_PreCh_ManualMode_signal',     1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});   
    BusSignalDef('s_LVCON_StateSetREQ_enum',            1,    'Enum: LVCON_STATE',            -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LVCON_ForceShutdownState_enum',     1,    'Enum: LVCON_STATE_SAFETY',     -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LVCON_Plus_ManualMode_enable',        1,    'boolean',                      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LVCON_Plus_ManualMode_signal',      1,    'boolean',                       -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1});   
    BusSignalDef('s_ISOMON_StateSetREQ_enum',           1,    'Enum: ISOMON_STATE',           -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_IREQ_StateSetREQ_enum',             1,    'Enum: IREQ_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_IREQ_ForceShutdownState_enum',      1,    'Enum: IREQ_STATE_SAFETY',      -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_RDIS_StateSetREQ_enum',             1,    'Enum: RDIS_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_RDIS_ForceShutdownState_enum',      1,    'Enum: RDIS_STATE_SAFETY',      -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    ];

OMM_Electrical_Set_BusDef.AssignBusElements(busElements);


%% OMM_ComponentProtection_Set

OMM_ComponentProtection_Set_BusDef = BusDef("OMM_ComponentProtection_Set", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    % ANODE
    BusSignalDef('s_CompProt_pSens_ASVi_LL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_ASVi_UL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_APRVi_LL_enable'    		      , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_APRVi_UL_enable'    		      , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_Asti_LL_enable'                , 1 , 'boolean',		-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_Asti_UL_enable'                , 1 , 'boolean',		-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_MemDiff_LL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_MemDiff_UL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    % new
    BusSignalDef('s_CompProt_TSens_ASVi_LL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_ASVi_UL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_dpSens_APRV_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_dpSens_APRV_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_ARP_LL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_ARP_UL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_PSens_ARP_LL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_PSens_ARP_UL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    % CATHODE
    BusSignalDef('s_CompProt_pSens_EACi_LL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_EACi_UL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_EACi_LL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_EACi_UL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_mdotSens_EACi_LL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_mdotSens_EACi_UL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_EACo_LL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_EACo_UL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CHUi_LL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CHUi_UL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CSti_LL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CSti_UL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_CSti_LL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_CSti_UL_enable'                , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_INV_LL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_INV_UL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    % new
    BusSignalDef('s_CompProt_Surge_EAC_LL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_Surge_EAC_UL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_ISens_EAC_LL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_ISens_EAC_UL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_USens_EAC_LL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_USens_EAC_UL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_omegaSens_EAC_LL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_omegaSens_EAC_UL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TMotorSens_EAC_LL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TMotorSens_EAC_UL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    % THERMAL
    BusSignalDef('s_CompProt_pSens_ECL_LL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_ECL_UL_enable'                 , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CLSti_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CLSti_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CLSto_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CLSto_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_CLSti_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_CLSti_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_FCSDiff_LL_enable'                   , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_FCSDiff_UL_enable'                   , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    %new
    BusSignalDef('s_CompProt_pSens_TCPi_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_pSens_TCPi_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_CoolMemDiff_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_CoolMemDiff_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    % ELECTRICAL
    BusSignalDef('s_CompProt_USens_AvgCell_LL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_USens_AvgCell_UL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_USens_AvgCellMinCell_LL_enable'      , 1 , 'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_USens_AvgCellMinCell_UL_enable'      , 1 , 'boolean',      -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_Shunt_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_Shunt_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_ISens_Stack_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_ISens_Stack_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_USens_LVBus_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_USens_LVBus_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_USens_HVBus_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_USens_HVBus_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_RSens_IsoMonitor_LL_enable'          , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_RSens_IsoMonitor_UL_enable'          , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    % new
    BusSignalDef('s_CompProt_ISens_DiffReqAct_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_ISens_DiffReqAct_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_ISens_Imperm_LL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_ISens_Imperm_UL_enable'               , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 

    % MISC
    BusSignalDef('s_CompProt_H2Sens_Long_LL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_H2Sens_Long_UL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_H2Sens_Short_LL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_H2Sens_Short_UL_enable'             , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CubeInside_LL_enable'          , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CompProt_TSens_CubeInside_UL_enable'          , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ResetWarnings_bool'                           , 1 , 'boolean',   	-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); 
    ];

OMM_ComponentProtection_Set_BusDef.AssignBusElements(busElements);


%% OMM_Set

OMM_Set_BusDef = BusDef("OMM_Set", "Descripton goes here");

OMM_Anode_Set_BusDef.AddMetaData({STREAM_LVL.All, 1});
OMM_Cathode_Set_BusDef.AddMetaData({STREAM_LVL.All, 1});
OMM_ECCL_Set_BusDef.AddMetaData({STREAM_LVL.All, 1}); 
OMM_Thermal_Set_BusDef.AddMetaData({STREAM_LVL.All, 1});
OMM_Electrical_Set_BusDef.AddMetaData({STREAM_LVL.All, 1});
OMM_ComponentProtection_Set_BusDef.AddMetaData({STREAM_LVL.All, 1});

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    OMM_Anode_Set_BusDef;
    OMM_Cathode_Set_BusDef;
    OMM_ECCL_Set_BusDef; 
    OMM_Thermal_Set_BusDef;
    OMM_Electrical_Set_BusDef;
    OMM_ComponentProtection_Set_BusDef;
    ];

    signal = BusSignalDef('s_OMM_State_Actual'               , 1,    'Enum: OMM_STATE',                  -1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.All, 1});...

OMM_Set_BusDef.AssignBusElements(busElements);
OMM_Set_BusDef.AssignBusElements(signal);

clear signal

OMM_Set_BusDef.GenerateRespectiveDatatypeStructures();

%% OMM_Anode_Get

OMM_Anode_Get_BusDef = BusDef("OMM_Anode_Get", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_APD_CurrentState_enum'          , 1,    'Enum: APD_STATE',          -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APD_CurrentStateSafety_enum'    , 1,    'Enum: APD_STATE_SAFETY',   -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APRES_CurrentState_enum'        , 1,    'Enum: APRES_STATE',        -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_APRES_CurrentStateSafety_enum'  , 1,    'Enum: APRES_STATE_SAFETY', -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ARECI_CurrentState_enum'        , 1,    'Enum: ARECI_STATE',        -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ARECI_CurrentStateSafety_enum'  , 1,    'Enum: ARECI_STATE_SAFETY', -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ARECI_PumpState_enum'           , 1,    'Enum: PUMP_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    ];

OMM_Anode_Get_BusDef.AssignBusElements(busElements);


%% OMM_Cathode_Get

OMM_Cathode_Get_BusDef = BusDef("OMM_Cathode_Get", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_CAC_CurrentState_enum'          , 1,    'Enum: CAC_STATE',          -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CAC_CurrentStateSafety_enum'    , 1,    'Enum: CAC_STATE_SAFETY',   -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_EAC_PumpState_enum'             , 1,    'Enum: PUMP_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_AIRCL_CurrentState_enum'        , 1,    'Enum: AIRCL_STATE',        -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_AIRCL_CurrentStateSafety_enum'  , 1,    'Enum: AIRCL_STATE_SAFETY', -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSEP_CurrentState_enum'         , 1,    'Enum: CSEP_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CSEP_CurrentStateSafety_enum'   , 1,    'Enum: CSEP_STATE_SAFETY',  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CHU_CurrentState_enum'          , 1,    'Enum: CHU_STATE',          -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_CHU_CurrentStateSafety_enum'    , 1,    'Enum: CHU_STATE_SAFETY',   -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    ];

OMM_Cathode_Get_BusDef.AssignBusElements(busElements);


%% OMM_ECCL_Get

OMM_ECCL_Get_BusDef = BusDef("OMM_ECCL_Get", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_ECCL_CurrentState_enum',        1,    'Enum: ECCL_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ECCL_CurrentStateSafety_enum',  1,    'Enum: ECCL_STATE_SAFETY',  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ECCL_PumpState_enum',           1,    'Enum: PUMP_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    ];

OMM_ECCL_Get_BusDef.AssignBusElements(busElements);


%% OMM_Thermal_Get

OMM_Thermal_Get_BusDef = BusDef("OMM_Thermal_Get", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_STCL_CurrentState_enum',        1,    'Enum: STCL_STATE',         -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_STCL_CurrentStateSafety_enum',  1,    'Enum: STCL_STATE_SAFETY',  -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    ];

OMM_Thermal_Get_BusDef.AssignBusElements(busElements);


%% OMM_Electrical_Get

OMM_Electrical_Get_BusDef = BusDef("OMM_Electrical_Get", "Descripton goes here");

busElements = [  
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_LCON_CurrentState_enum',            1,    'Enum: LCON_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LCON_CurrentStateSafety_enum',      1,    'Enum: LCON_STATE_SAFETY',      -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_HVCON_CurrentState_enum',           1,    'Enum: HVCON_STATE',            -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_HVCON_ForceShutdownState_enum',     1,    'Enum: HVCON_STATE_SAFETY',     -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LVCON_CurrentState_enum',           1,    'Enum: LVCON_STATE',            -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_LVCON_ForceShutdownState_enum',     1,    'Enum: LVCON_STATE_SAFETY',     -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_Operation_State_enum',              1,    'Enum: OPERATION_STATE',        -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_IREQ_CurrentState_enum',            1,    'Enum: IREQ_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_IREQ_ForceShutdownState_enum',      1,    'Enum: IREQ_STATE_SAFETY',      -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_ISOMON_CurrentState_enum',          1,    'Enum: ISOMON_STATE',           -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_RDIS_CurrentState_enum',            1,    'Enum: RDIS_STATE',             -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    BusSignalDef('s_RDIS_ForceShutdownState_enum',      1,    'Enum: RDIS_STATE_SAFETY',      -1,     'real', 'Sample','Fixed',  [],  [],    's',  '', {STREAM_LVL.Debug, 1}); 
    ];

OMM_Electrical_Get_BusDef.AssignBusElements(busElements);



%% OMM_Get

OMM_Get_BusDef = BusDef("OMM_Get", "Descripton goes here");

OMM_Anode_Get_BusDef.AddMetaData({STREAM_LVL.Debug, 1});
OMM_Cathode_Get_BusDef.AddMetaData({STREAM_LVL.Debug, 1});
OMM_ECCL_Get_BusDef.AddMetaData({STREAM_LVL.Debug, 1});
OMM_Thermal_Get_BusDef.AddMetaData({STREAM_LVL.Debug, 1});
OMM_Electrical_Get_BusDef.AddMetaData({STREAM_LVL.Debug, 1});

busElements = [ ... 
    OMM_Anode_Get_BusDef;
    OMM_Cathode_Get_BusDef;
    OMM_ECCL_Get_BusDef;
    OMM_Thermal_Get_BusDef;
    OMM_Electrical_Get_BusDef;
    ];

OMM_Get_BusDef.AssignBusElements(busElements);

OMM_Get_BusDef.GenerateRespectiveDatatypeStructures();


%% clear working variables

clear busElements
clear busName
