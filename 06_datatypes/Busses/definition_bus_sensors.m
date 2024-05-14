
%% ARP1_Sens


ARP1_SENS_BusDef = BusDef("ARP1_SENS", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_ARP1_Get', 1,    'single',               -1, 'real', 'Sample','Fixed',    0,     1e5,    'rpm',  'meas signal for anode recirculation pump', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_I_A_ARP1_Get', 1,    'single',               -1, 'real', 'Sample','Fixed',    0,     1e5,    'A',  'auxilary meas signal for anode recirculation pump', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_U_V_ARP1_Get', 1,    'single',               -1, 'real', 'Sample','Fixed',    0,     1e5,    'V',  'auxilary meas signal for anode recirculation pump', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_ARP1_Get', 1,    'single',               -1, 'real', 'Sample','Fixed',    0,     1e5,    'degC',  'meas signal for the air temperature of the anode recirculation pump', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_ARP1_Get'  , 1,    'Enum: SENS_STATUS',    -1, 'real', 'Sample','Fixed',   [],     [],     '',     'state of ARP1 sensor', {STREAM_LVL.Release, 1});...
    ];

ARP1_SENS_BusDef.AssignBusElements(busElements);

%% ARP2_Sens

ARP2_SENS_BusDef = BusDef("ARP2_SENS", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_ARP2_Get', 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  1e5,    'rpm',  'meas signal for anode recirculation pump', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_I_A_ARP2_Get', 1,    'single',               -1, 'real', 'Sample','Fixed',    0,     1e5,    'A',  'auxilary meas signal for anode recirculation pump', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_U_V_ARP2_Get', 1,    'single',               -1, 'real', 'Sample','Fixed',    0,     1e5,    'V',  'auxilary meas signal for anode recirculation pump', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_ARP2_Get', 1,    'single',               -1, 'real', 'Sample','Fixed',    0,     1e5,    'degC',  'meas signal for the air temperature of the anode recirculation pump', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_ARP2_Get'  , 1,    'Enum: SENS_STATUS',    -1, 'real', 'Sample','Fixed',   [],     [],     '',     'state of ARP2 sensor', {STREAM_LVL.Release, 1});...
    ];

ARP2_SENS_BusDef.AssignBusElements(busElements);

%% pSens_ASVi

pSens_ASVi_BusDef = BusDef("pSens_ASVi", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_ASVi_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  15,    '',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_ASVi_Get'   , 1,    'Enum: SENS_STATUS',     -1, 'real', 'Sample', 'Fixed',  [], [], '', '', {STREAM_LVL.Release, 1});...
    ];

pSens_ASVi_BusDef.AssignBusElements(busElements);

%% ISens_ASV

ISens_ASV_BusDef = BusDef("ISens_ASV", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_ASV_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_I_ASV_Get' , 1, 'Enum: SENS_STATUS', -1   ,         'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

ISens_ASV_BusDef.AssignBusElements(busElements);

%% ISens_ADV

ISens_ADV_BusDef = BusDef("ISens_ADV", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_ADV_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  6,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_I_ADV_Get' , 1, 'Enum: SENS_STATUS', -1,         'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

ISens_ADV_BusDef.AssignBusElements(busElements);

%% ISens_APV

ISens_APV_BusDef = BusDef("ISens_APV", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_APV_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_I_APV_Get' , 1, 'Enum: SENS_STATUS', -1   ,         'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

ISens_APV_BusDef.AssignBusElements(busElements);


%% TSens_ASVi

TSens_ASVi_BusDef = BusDef("TSens_ASVi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_ASVi_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    -200,  200,    '',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_ASVi_Get'   , 1,    'Enum: SENS_STATUS',     -1, 'real', 'Sample', 'Fixed',  [], [], '', '', {STREAM_LVL.Release, 1});...
    ];

TSens_ASVi_BusDef.AssignBusElements(busElements);

%% pSens_APRVi

pSens_APRVi_BusDef = BusDef("pSens_APRVi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_APRVi_Get'  , 1,    'single',   -1,             'real', 'Sample', 'Fixed',    0,  100,    'percent',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_APRVi_Get' , 1, 'Enum: SENS_STATUS', -1  ,          'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

pSens_APRVi_BusDef.AssignBusElements(busElements);

%% ISens_APRV1

ISens_APRV1_BusDef = BusDef("ISens_APRV1", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_APRV1_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_I_APRV1_Get' , 1, 'Enum: SENS_STATUS', -1 ,           'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

ISens_APRV1_BusDef.AssignBusElements(busElements);

%% ISens_APRV2

ISens_APRV2_BusDef = BusDef("ISens_APRV2", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_APRV2_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_I_APRV2_Get' , 1, 'Enum: SENS_STATUS', -1 ,           'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

ISens_APRV2_BusDef.AssignBusElements(busElements);

%% ISens_APRV_LO

ISens_APRV_LO_BusDef = BusDef("ISens_APRV_LO", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_APRV_LO_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  6,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_I_APRV_LO_Get' , 1, 'Enum: SENS_STATUS', -1,            'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

ISens_APRV_LO_BusDef.AssignBusElements(busElements);

%% pSens_ASti

pSens_ASti_BusDef = BusDef("pSens_ASti", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_ASti_Get'       , 1, 'single',              -1, 'real', 'Sample', 'Fixed',    0,      5,      '',     'meas signal for anode purge valve', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_p_bara_ASti_MovAvg50ms', 1, 'single',              -1, 'real', 'Sample', 'Fixed',    0,      5,      '',     'moving average filtered 50ms', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_p_bara_ASti_MovAvg100ms'    , 1, 'single',              -1, 'real', 'Sample', 'Fixed',    0,      5,      '',     'moving average filtered 100ms', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_p_bara_ASti_MovAvg200ms'    , 1, 'single',              -1, 'real', 'Sample', 'Fixed',    0,      5,      '',     'moving average filtered 200ms', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_p_bara_ASti_MovAvg500ms'    , 1, 'single',              -1, 'real', 'Sample', 'Fixed',    0,      5,      '',     'moving average filtered 500ms', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_st_enum_ASti_Get'      , 1, 'Enum: SENS_STATUS',   -1, 'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

pSens_ASti_BusDef.AssignBusElements(busElements);

%% AnodeSens
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
AnodeSens_BusDef = BusDef("AnodeSens", "Descripton goes here");

ARP1_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ARP2_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ISens_APRV1_BusDef.AddMetaData({STREAM_LVL.All, 1});
ISens_APRV2_BusDef.AddMetaData({STREAM_LVL.All, 1});
ISens_APRV_LO_BusDef.AddMetaData({STREAM_LVL.All, 1});
ISens_ASV_BusDef.AddMetaData({STREAM_LVL.All, 1});
ISens_ADV_BusDef.AddMetaData({STREAM_LVL.All, 1});
ISens_APV_BusDef.AddMetaData({STREAM_LVL.All, 1});
pSens_ASVi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_APRVi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_ASti_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_ASVi_BusDef.AddMetaData({STREAM_LVL.Release, 1});

busElements = [ ... 
    ARP1_SENS_BusDef;
    ARP2_SENS_BusDef;
    ISens_APRV1_BusDef;
    ISens_APRV2_BusDef;
    ISens_APRV_LO_BusDef;
    ISens_ASV_BusDef;
    ISens_ADV_BusDef;
    ISens_APV_BusDef;
    pSens_ASVi_BusDef;
    pSens_APRVi_BusDef;
    pSens_ASti_BusDef;
    TSens_ASVi_BusDef;
    ];

AnodeSens_BusDef.AssignBusElements(busElements);


%% EAC_SENS

EAC_SENS_BusDef = BusDef("EAC_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_EAC_Get' ,                1,  'single',               -1,     'real', 'Sample','Fixed',   0,  10000,    'rpm',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_M_Nm_EAC_Get' ,                     1,  'single',               -1,     'real', 'Sample','Fixed',   0,  10000,    'Nm',     '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_U_V_EACDCLink_Get' ,                1,  'single',               -1,     'real', 'Sample','Fixed',   0,  10000,    'V',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_I_A_Get' ,                          1,  'single',               -1,     'real', 'Sample','Fixed',   0,  10000,    'A',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_P_W_EACDCLinkPowerEstimate_Get',  1,  'single',               -1 ,    'real', 'Sample','Fixed',   0,  50000,    'W', '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_T_degC_INV_T_Get',                  1,  'single',               -1 ,    'real', 'Sample','Fixed',   [],  [],    'degC', '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_EAC_Get',                  1,  'single',               -1 ,    'real', 'Sample','Fixed',   [],  [],    'degC', '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EAC_Get'   ,                1,  'Enum: SENS_STATUS',    -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

EAC_SENS_BusDef.AssignBusElements(busElements);

%% EATVNT_SENS

EATVNT_SENS_BusDef = BusDef("EATVNT_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_EATVNT_Get'  , 1,    'single',   -1,             'real', 'Sample', 'Fixed',    0,  100,    'percent',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EATVNT_Get' , 1, 'Enum: SENS_STATUS', -1,            'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_I_A_EATVNT_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_I_EATVNT_Get' , 1, 'Enum: SENS_STATUS', -1,           'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

EATVNT_SENS_BusDef.AssignBusElements(busElements);

%% CBV_SENS

CBV_SENS_BusDef = BusDef("CBV_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CBV_Get'  , 1,    'single',   -1,             'real', 'Sample', 'Fixed',    0,  100,    'percent',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CBV_Get' , 1, 'Enum: SENS_STATUS', -1,           'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

CBV_SENS_BusDef.AssignBusElements(busElements);



%% EATBV_SENS

EATBV_SENS_BusDef = BusDef("EATBV_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_EATBV_Get'  , 1,    'single',   -1,             'real', 'Sample', 'Fixed',    0,  100,    'percent',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EATBV_Get' , 1, 'Enum: SENS_STATUS', -1,           'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

EATBV_SENS_BusDef.AssignBusElements(busElements);
%% mdotSens_MFE
mdotSens_MFE_BusDef = BusDef("mdotSens_MFE", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_st_enum_MFE'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_mDot_gps_EAC' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  10000,    'gps',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_mDot_gps_EAT' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  10000,    'gps',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_mDot_gps_CAC' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  10000,    'gps',     '', {STREAM_LVL.Release, 1});...
    ];

mdotSens_MFE_BusDef.AssignBusElements(busElements);
%% mdotSens_EACi

mdotSens_EACi_BusDef = BusDef("mdotSens_EACi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_mDot_gps_EACi_Get' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  10000,    'gps',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EACi_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_mDot_gps_EACi_Get_biasCorr' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  10000,    'gps',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_mDot_gps_EACi_Get_TSE_a' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  10000,    'gps',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EACi_Get_TSE_a'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_mDot_gps_EACi_Get_TSE_b' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  10000,    'gps',     '', {STREAM_LVL.Release, 1});...
    ];

mdotSens_EACi_BusDef.AssignBusElements(busElements);

%% CSens_G_EATo

CSens_G_EATo_BusDef = BusDef("CSens_G_EATo", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_C_percentLeL_H2_G_EATo_Get'  , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'percentLel',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_C_percentLeL_H2O_G_EATo_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'percentLel',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_p_bara_G_EATo_Get'      , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  5,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_G_EATo_Get'      , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'degC',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_G_EATo_Get'     , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

CSens_G_EATo_BusDef.AssignBusElements(busElements);

%% pSens_EATi

pSens_EATi_BusDef = BusDef("pSens_EATi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_EATi_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  5,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EATi_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

pSens_EATi_BusDef.AssignBusElements(busElements);
%% pSens_EATo

pSens_EATo_BusDef = BusDef("pSens_EATo", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_EATo_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  5,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EATo_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

pSens_EATo_BusDef.AssignBusElements(busElements);
%% TSens_EATi

TSens_EATi_BusDef = BusDef("TSens_EATi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_EATi_Get' ,      1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EATi_Get'   ,   1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

TSens_EATi_BusDef.AssignBusElements(busElements);
%% TSens_EATo

TSens_EATo_BusDef = BusDef("TSens_EATo", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_EATo_Get' ,      1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EATo_Get'   ,   1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

TSens_EATo_BusDef.AssignBusElements(busElements);
%% rHSens_M_ChUdi

rHSens_M_ChUdi_BusDef = BusDef("rHSens_M_ChUdi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_rH_percent_M_ChUdi_Get' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'percent',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_M_ChUdi_Get'    , 1, 'Enum: SENS_STATUS', -1,           'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

rHSens_M_ChUdi_BusDef.AssignBusElements(busElements);

%% pSens_EACi

pSens_EACi_BusDef = BusDef("pSens_EACi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_EACi_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  5,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EACi_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

pSens_EACi_BusDef.AssignBusElements(busElements);


%% pSens_EACo

pSens_EACo_BusDef = BusDef("pSens_EACo", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_EACo_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  5,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EACo_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

pSens_EACo_BusDef.AssignBusElements(busElements);


%% pSens_CSti

pSens_CSti_BusDef = BusDef("pSens_CSti", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_CSti_Get'    , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  5,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_p_bara_CSti_MovAvg50ms' ,   1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     'moving average filtered with 50ms', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_p_bara_CSti_MovAvg100ms' ,  1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     'moving average filtered with 100ms', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_p_bara_CSti_MovAvg200ms' ,  1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     'moving average filtered with 200ms', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_p_bara_CSti_MovAvg500ms' ,  1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     'moving average filtered with 500ms', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_st_enum_CSti_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

pSens_CSti_BusDef.AssignBusElements(busElements);

%% TSens_CSto

TSens_CSto_BusDef = BusDef("TSens_CSto", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_CSto_Get'    , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'degC',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CSto_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

TSens_CSto_BusDef.AssignBusElements(busElements);

%% pSens_CSto

pSens_CSto_BusDef = BusDef("pSens_CSto", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_CSto_Get'    , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  5,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CSto_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

pSens_CSto_BusDef.AssignBusElements(busElements);


%% pSens_PT_C_601

pSens_PT_C_601_BusDef = BusDef("pSens_PT_C_601", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_PT_C_601_Get'    , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  5,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_PT_C_601_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

pSens_PT_C_601_BusDef.AssignBusElements(busElements);


%% pSens_PT_C_701

pSens_PT_C_701_BusDef = BusDef("pSens_PT_C_701", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_PT_C_701_Get'    , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  5,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_PT_C_701_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

pSens_PT_C_701_BusDef.AssignBusElements(busElements);


%% TSens_EACi

TSens_EACi_BusDef = BusDef("TSens_EACi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_EACi_Get' ,      1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_EACi_Get'   ,   1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

TSens_EACi_BusDef.AssignBusElements(busElements);


%% TSens_CHUi

TSens_CHUi_BusDef = BusDef("TSens_CHUi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_CHUi_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CHUi_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

TSens_CHUi_BusDef.AssignBusElements(busElements);


%% TSens_CSti

TSens_CSti_BusDef = BusDef("TSens_CSti", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_CSti_Get' ,          1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     'measured signal', {STREAM_LVL.Release, 1});...    
    BusSignalDef('s_st_enum_CSti_Get'   ,       1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

TSens_CSti_BusDef.AssignBusElements(busElements);


%% TSens_TT_C_601

TSens_TT_C_601_BusDef = BusDef("TSens_TT_C_601", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_TT_C_601_Get' ,          1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     'measured signal', {STREAM_LVL.Release, 1});...    
    BusSignalDef('s_st_enum_TT_C_601_Get'   ,       1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

TSens_TT_C_601_BusDef.AssignBusElements(busElements);


%% CSIV_SENS

CSIV_SENS_BusDef = BusDef("CSIV_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CSIV_Get'   , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'percent',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CSIV_Get'  , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

CSIV_SENS_BusDef.AssignBusElements(busElements);

%% CSOV_SENS

CSOV_SENS_BusDef = BusDef("CSOV_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CSOV_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'percent',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CSOV_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

CSOV_SENS_BusDef.AssignBusElements(busElements);

%% CHUBVd

CHUBVd_SENS_BusDef = BusDef("CHUBVd_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CHUBVd_Get', 1,    'single',                -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'get signal for dry-side humidifier bypass valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_st_enum_CHUBVd_Get', 1,    'Enum: SENS_STATUS',     -1,             'real', 'Sample','Fixed',    [],  [],    'percent',  'get signal for dry-side humidifier bypass valve', {STREAM_LVL.Release, 1}); ...
    ];

CHUBVd_SENS_BusDef.AssignBusElements(busElements);

%% CHUBVw

CHUBVw_SENS_BusDef = BusDef("CHUBVw_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CHUBVw_ACT_Get',    1,    'single',                 -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'get signal for wet-side humidifier bypass valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_st_enum_CHUBVw_Get',            1,    'Enum: SENS_STATUS',      -1,             'real', 'Sample','Fixed',    [],  [],    'percent',  'get signal for dry-side humidifier bypass valve', {STREAM_LVL.Release, 1}); ...
    ];

CHUBVw_SENS_BusDef.AssignBusElements(busElements);

%% ETV_SENS

ETV_SENS_BusDef = BusDef("ETV_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_ETV_Get' , 1,   'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'percent',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_ETV_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

ETV_SENS_BusDef.AssignBusElements(busElements);

%% ISens_TDV

ISens_TDV_BusDef = BusDef("ISens_TDV", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_TDV_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_I_TDV_Get' , 1, 'Enum: SENS_STATUS', -1,           'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

ISens_TDV_BusDef.AssignBusElements(busElements);

%% CathodeSens
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
CathodeSens_BusDef = BusDef("CathodeSens", "Descripton goes here");

EAC_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
EATVNT_SENS_BusDef.AddMetaData({STREAM_LVL.All, 1});
EATBV_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1}); 
CBV_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});   
mdotSens_EACi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
mdotSens_MFE_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CSens_G_EATo_BusDef.AddMetaData({STREAM_LVL.All, 1});
rHSens_M_ChUdi_BusDef.AddMetaData({STREAM_LVL.All, 1});
pSens_EACi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_EACo_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_EATi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_EATo_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_CSti_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_EACi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_EATi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_EATo_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_CHUi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_CSti_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CSIV_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CSOV_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CHUBVd_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CHUBVw_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ETV_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_CSto_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_CSto_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ISens_TDV_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_TT_C_601_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_PT_C_601_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_PT_C_701_BusDef.AddMetaData({STREAM_LVL.Release, 1});

busElements = [ ... 
    EAC_SENS_BusDef;
    EATVNT_SENS_BusDef;
    EATBV_SENS_BusDef; 
    CBV_SENS_BusDef;   
    mdotSens_EACi_BusDef;
    mdotSens_MFE_BusDef;
    CSens_G_EATo_BusDef;
    rHSens_M_ChUdi_BusDef;
    pSens_EACi_BusDef;
    pSens_EACo_BusDef;
    pSens_EATi_BusDef;
    pSens_EATo_BusDef;
    pSens_CSti_BusDef;
    TSens_EACi_BusDef;
    TSens_EATi_BusDef;
    TSens_EATo_BusDef;
    TSens_CHUi_BusDef;
    TSens_CSti_BusDef;
    CSIV_SENS_BusDef;
    CSOV_SENS_BusDef;
    CHUBVd_SENS_BusDef;
    CHUBVw_SENS_BusDef;
    ETV_SENS_BusDef;
    pSens_CSto_BusDef;
    TSens_CSto_BusDef;
    ISens_TDV_BusDef;
    TSens_TT_C_601_BusDef;
    pSens_PT_C_601_BusDef;
    pSens_PT_C_701_BusDef;
    ];

CathodeSens_BusDef.AssignBusElements(busElements);

%% auxTCP_SENS

auxTCP_SENS_BusDef = BusDef("auxTCP_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_auxTCP_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  10000,    'rpm',     '', {STREAM_LVL.All, 1});...
    BusSignalDef('s_I_A_auxTCP_Get'  , 1,    'single',               -1,     'real', 'Sample',   'Fixed',    0,     10000,    'A',  '', {STREAM_LVL.All, 1});...
    BusSignalDef('s_U_V_auxTCP_Get'  , 1,    'single',               -1,     'real', 'Sample',   'Fixed',    0,     10000,    'V',  '', {STREAM_LVL.All, 1});...
    BusSignalDef('s_st_enum_auxTCP_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.All, 1});...
    ];

auxTCP_SENS_BusDef.AssignBusElements(busElements);

%% TCP_SENS

TCP_SENS_BusDef = BusDef("TCP_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_TCP_Get'  , 1,    'single',               -1,     'real', 'Sample',   'Fixed',    0,     10000,    'rpm',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_I_A_TCP_Get'  , 1,    'single',               -1,     'real', 'Sample',   'Fixed',    0,     10000,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_U_V_TCP_Get'  , 1,    'single',               -1,     'real', 'Sample',   'Fixed',    0,     10000,    'V',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_P_W_TCP_Get'  , 1,    'single',               -1,     'real', 'Sample',   'Fixed',    0,     20000,    'W',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_Medium_TCP_Get'  , 1,    'single',               -1,     'real', 'Sample',   'Fixed',    -50,     100,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_TCP_Get'    , 1,    'Enum: SENS_STATUS',    -1,     'real', 'Sample',   'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

TCP_SENS_BusDef.AssignBusElements(busElements);

%% TCV_SENS

TCV_SENS_BusDef = BusDef("TCV_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_per_TCV_Get'   , 1,    'single',               -1,     'real', 'Sample','Fixed',    0,     100, 'percent','', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_deg_TCV_Get'     , 1,    'single',               -1,   'real', 'Sample','Fixed',     0,      120,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_MotorEffort_TCV_Get'    , 1,    'single',               -1,   'real', 'Sample','Fixed',     [],      [],    '',  '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_ActuatorFault_TCV_Get'  , 1,    'single',               -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_TCV_Get'   , 1,    'Enum: SENS_STATUS',    -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

TCV_SENS_BusDef.AssignBusElements(busElements);

%% pSens_TCVi

pSens_TCVi_BusDef = BusDef("pSens_TCVi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_TCVi_Get' , 1,    'single',               -1,   'real', 'Sample','Fixed',   -20,  120,    'bara',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_TCVi_Get'  , 1,    'Enum: SENS_STATUS',    -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

pSens_TCVi_BusDef.AssignBusElements(busElements);

%% pSens_TCPi

pSens_TCPi_BusDef = BusDef("pSens_TCPi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_TCPi_Get' , 1,    'single',               -1,     'real', 'Sample','Fixed',    0,  100,    'bara',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_TCPi_Get'  , 1,    'Enum: SENS_STATUS',    -1,     'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

pSens_TCPi_BusDef.AssignBusElements(busElements);

%% pSens_TCPo

pSens_TCPo_BusDef = BusDef("pSens_TCPo", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_TCPo_Get' , 1,    'single',               -1,     'real', 'Sample','Fixed',    0,  100,    'bara',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_TCPo_Get'  , 1,    'Enum: SENS_STATUS',    -1,     'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

pSens_TCPo_BusDef.AssignBusElements(busElements);

%% pSens_CLSti

pSens_CLSti_BusDef = BusDef("pSens_CLSti", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_CLSti_Get',        1,  'single',               -1,   'real', 'Sample', 'Fixed',    0,  100,    'bara',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CLSti_Get' ,   1,  'Enum: SENS_STATUS',    -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

pSens_CLSti_BusDef.AssignBusElements(busElements);

%% pSens_CLSto

pSens_CLSto_BusDef = BusDef("pSens_CLSto", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_CLSto_Get',        1,  'single',               -1,   'real', 'Sample', 'Fixed',    0,  100,    'bara',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_p_bara_CLSto_Est',        1,  'single',               -1,   'real', 'Sample', 'Fixed',    0,  100,    'bara',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CLSto_Get' ,      1,  'Enum: SENS_STATUS',    -1,   'real', 'Sample', 'Fixed',    [],     [],     '',  '', {STREAM_LVL.Release, 1});...
    ];

pSens_CLSto_BusDef.AssignBusElements(busElements);
%% TSens_TCVi

TSens_TCVi_BusDef = BusDef("TSens_TCVi", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_TCVi_Get', 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  120,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_TCVi_Observed', 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  120,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_TCVi_Predict', 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  120,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_TCVi_Get' , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

TSens_TCVi_BusDef.AssignBusElements(busElements);

%% TSens_CLSti

TSens_CLSti_BusDef = BusDef("TSens_CLSti", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_CLSti_Get', 1,    'single',   -1,                 'real', 'Sample','Fixed',    0,  100,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_CLSti_Observed', 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  120,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_CLSti_Predict', 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  120,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CLSti_Get', 1,    'Enum: SENS_STATUS',   -1,      'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

TSens_CLSti_BusDef.AssignBusElements(busElements);

%% TSens_CLSto

TSens_CLSto_BusDef = BusDef("TSens_CLSto", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_CLSto_Get'  , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  100,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_CLSto_Observed'  , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  120,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_CLSto_Predict'  , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  120,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CLSto_Get' , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

TSens_CLSto_BusDef.AssignBusElements(busElements);

%% TSens_STCLDiff

TSens_STCLDiff_BusDef = BusDef("TSens_STCLDiff", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_STCLDiff_Estimated'  , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  100,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_STCLDiff_Get', 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

TSens_STCLDiff_BusDef.AssignBusElements(busElements);

%% VDotSens_STCLFlow

VDotSens_STCLFlow_BusDef = BusDef("VDotSens_STCLFlow", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_VDot_lpm_STCLFlow_Est',         1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  300,    'lpm',    '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_st_enum_STCLFlow_Get',          1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [], [],     '',       '', {STREAM_LVL.Debug, 1});...
    ];

VDotSens_STCLFlow_BusDef.AssignBusElements(busElements);

%% pSens_STCLDiff

pSens_STCLDiff_BusDef = BusDef("pSens_STCLDiff", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bar_STCLDiff_Est',          1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  1000,   'bar',    '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_st_enum_STCLDiff_Get',        1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [], [],     '',       '', {STREAM_LVL.Debug, 1});...
    ];

pSens_STCLDiff_BusDef.AssignBusElements(busElements);

%% ThermalSens
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ThermalSens_BusDef = BusDef("ThermalSens", "Descripton goes here");

auxTCP_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TCP_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TCV_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_TCVi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_TCPi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_CLSti_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_CLSto_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_TCVi_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_CLSti_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_CLSto_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_STCLDiff_BusDef.AddMetaData({STREAM_LVL.Release, 1});
VDotSens_STCLFlow_BusDef.AddMetaData({STREAM_LVL.Debug, 1});
pSens_STCLDiff_BusDef.AddMetaData({STREAM_LVL.Debug, 1});

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    auxTCP_SENS_BusDef;
    TCP_SENS_BusDef;
    TCV_SENS_BusDef;
    pSens_TCVi_BusDef;
    pSens_TCPi_BusDef;
    pSens_CLSti_BusDef;
    pSens_CLSto_BusDef;
    TSens_TCVi_BusDef;
    TSens_CLSti_BusDef;
    TSens_CLSto_BusDef;
    TSens_STCLDiff_BusDef;
    VDotSens_STCLFlow_BusDef;
    pSens_STCLDiff_BusDef;
    ];

ThermalSens_BusDef.AssignBusElements(busElements);

%% ThermalSens_Stage3
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ThermalSens_Stage3_BusDef = BusDef("ThermalSens_Stage3", "Descripton goes here");

auxTCP_SENS_Stage3_BusDef = copy(auxTCP_SENS_BusDef);
TCP_SENS_Stage3_BusDef = copy(TCP_SENS_BusDef);
TCV_SENS_Stage3_BusDef = copy(TCV_SENS_BusDef);
pSens_TCVi_Stage3_BusDef = copy(pSens_TCVi_BusDef);
pSens_TCPo_Stage3_BusDef = copy(pSens_TCPo_BusDef);
pSens_CLSti_Stage3_BusDef = copy(pSens_CLSti_BusDef);
pSens_CLSto_Stage3_BusDef = copy(pSens_CLSto_BusDef);
TSens_TCVi_Stage3_BusDef = copy(TSens_TCVi_BusDef);
TSens_CLSti_Stage3_BusDef = copy(TSens_CLSti_BusDef);
TSens_CLSto_Stage3_BusDef = copy(TSens_CLSto_BusDef);
TSens_STCLDiff_Stage3_BusDef = copy(TSens_STCLDiff_BusDef);
VDotSens_STCLFlow_Stage3_BusDef = copy(VDotSens_STCLFlow_BusDef);
pSens_STCLDiff_Stage3_BusDef = copy(pSens_STCLDiff_BusDef);

auxTCP_SENS_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
TCP_SENS_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
TCV_SENS_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
pSens_TCVi_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
pSens_TCPo_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
pSens_CLSti_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
pSens_CLSto_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
TSens_TCVi_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
TSens_CLSti_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
TSens_CLSto_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
TSens_STCLDiff_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
VDotSens_STCLFlow_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
pSens_STCLDiff_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    auxTCP_SENS_Stage3_BusDef;
    TCP_SENS_Stage3_BusDef;
    TCV_SENS_Stage3_BusDef;
    pSens_TCVi_Stage3_BusDef;
    pSens_TCPo_Stage3_BusDef;
    pSens_CLSti_Stage3_BusDef;
    pSens_CLSto_Stage3_BusDef;
    TSens_TCVi_Stage3_BusDef;
    TSens_CLSti_Stage3_BusDef;
    TSens_CLSto_Stage3_BusDef;
    TSens_STCLDiff_Stage3_BusDef;
    VDotSens_STCLFlow_Stage3_BusDef;
];

ThermalSens_Stage3_BusDef.AssignBusElements(busElements);


%% ETCP_SENS

ETCP_SENS_BusDef = BusDef("ETCP_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_ETCP_Get' , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  100,    'rpm',  '', {STREAM_LVL.All, 1});...
    BusSignalDef('s_P_W_ETCP_Get'       , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  100,    'Watt',  '', {STREAM_LVL.All, 1});...
    BusSignalDef('s_st_enum_ETCP_Get'   , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.All, 1});...
    ];

ETCP_SENS_BusDef.AssignBusElements(busElements);

%% pSens_ECL

pSens_ECL_BusDef = BusDef("pSens_ECL", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_ECL_Get'     , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  100,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_ECL_Get'    , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

pSens_ECL_BusDef.AssignBusElements(busElements);

%% CHXV_SENS

CHXV_SENS_BusDef = BusDef("CHXV_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CHXV_Get'  , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  100,    'percent',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_CHXV_Get', 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_I_A_CHXV_Get'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_I_CHXV_Get', 1, 'Enum: SENS_STATUS', -1,           'real', 'Sample', 'Fixed', [],  [], '', '', {STREAM_LVL.Release, 1});...
    ];

CHXV_SENS_BusDef.AssignBusElements(busElements);

%% ECoolingSens
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ECoolingSens_BusDef = BusDef("ECoolingSens", "Descripton goes here");

ETCP_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1}); 
pSens_ECL_BusDef.AddMetaData({STREAM_LVL.Release, 1}); 
CHXV_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1}); 

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    ETCP_SENS_BusDef; 
    pSens_ECL_BusDef; 
    CHXV_SENS_BusDef; 
    ];

ECoolingSens_BusDef.AssignBusElements(busElements);

%% USens_StCV

USens_StCV_BusDef = BusDef("USens_StCV", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_U_V_CVSUM_Get'      , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  3,    'V',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_U_V_CVAVG_Get'      , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  3,    'V',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_pos_D_CVAVG_Get'    , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  100,    '',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_U_V_CVMIN_Get'      , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  3,    'V',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_pos_D_CVMIN_Get'    , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  100,    '',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_U_V_CVMAX_Get'      , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  3,    'V',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_pos_D_CVMAX_Get'    , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  100,    '',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_StCV_Get'   , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_StCV_Test'  , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_U_mV_Cell'          , 300, 'single',            -1,   'real', 'Sample', 'Fixed',    0, 1500, 'mV', '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_n_Cells'           , 1, 'single',            -1,   'real', 'Sample', 'Fixed',    0, 1000, '', '', {STREAM_LVL.Debug, 1})    
];

USens_StCV_BusDef.AssignBusElements(busElements);

%% Sens_IVT

Sens_IVT_BusDef = BusDef("Sens_IVT", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_StN_Get'        , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  1000,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_I_A_StN_MovAvg50ms' , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  1000,    'A',  '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_I_A_StN_MovAvg100ms', 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  1000,    'A',  '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_I_A_StN_MovAvg200ms', 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  1000,    'A',  '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_I_A_StN_MovAvg500ms', 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  1000,    'A',  '', {STREAM_LVL.Debug, 1});...
    BusSignalDef('s_U_V_StP_Get'        , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  [],    'V',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_U_V_LoadP_Get'      , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  [],    'V',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_P_W_St_Get'         , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  [],    'W',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_T_degC_IVT_Get'     , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  150,    'degC',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_IVT_Get'    , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

Sens_IVT_BusDef.AssignBusElements(busElements);

%% ISens_BoP

ISens_BoP_BusDef = BusDef("ISens_BoP", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_BOP_Get'        , 1, 'single',                 -1,   'real', 'Sample', 'Fixed',    0,  100,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_BoP_Get'    , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

ISens_BoP_BusDef.AssignBusElements(busElements);

%% RSens_ISOMON

RSens_ISOMON_BusDef = BusDef("RSens_ISOMON", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_ResultFlag_enum_ISOMON_Get' , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  [],    '',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_R_Ohm_ISOMON_Get'           , 1, 'single',              -1,   'real', 'Sample', 'Fixed',    0,  [],    'Ohm',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_State_enum_ISOMON_Get'      , 1, 'Enum: ISOMON_STATE',              -1,   'real', 'Sample', 'Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_ISOMON_Get'         , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});
    ];

RSens_ISOMON_BusDef.AssignBusElements(busElements);

%% ISens_HVPre

ISens_HVPre_BusDef = BusDef("ISens_HVPre", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_I_A_HVPre_Get'          , 1, 'single',                 -1,   'real', 'Sample', 'Fixed',    0,  100,    'A',  '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_HVPre_Get'      , 1, 'Enum: SENS_STATUS',   -1,   'real', 'Sample', 'Fixed',    [],     [],     '',     '', {STREAM_LVL.Release, 1});...
    ];

ISens_HVPre_BusDef.AssignBusElements(busElements);

%% StackRelays

StackRelay_SENS_BusDef = BusDef("StackRelay_SENS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_enum_StNR_Get',    1,    'Enum: RELAY_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_pos_enum_StPR_Get',    1,    'Enum: RELAY_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    ];

StackRelay_SENS_BusDef.AssignBusElements(busElements);

%% TSens_RDIS

TSens_RDIS_BusDef = BusDef("TSens_RDIS", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_RDIS_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  300,    'degC',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_RDIS_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

TSens_RDIS_BusDef.AssignBusElements(busElements);

%% X90_Sens

X90_Sens_BusDef = BusDef("X90_Sens", "Descripton goes here");

busElements = [ ... 
    BusSignalDef('s_U_V_LV_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  32,    'V',     '', {STREAM_LVL.Release, 1});...    
    ];

X90_Sens_BusDef.AssignBusElements(busElements);

%% ElectricalSens
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ElectricalSens_BusDef = BusDef("ElectricalSens", "Descripton goes here");

USens_StCV_BusDef.AddMetaData({STREAM_LVL.Release, 1});
Sens_IVT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ISens_BoP_BusDef.AddMetaData({STREAM_LVL.Release, 1});
RSens_ISOMON_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ISens_HVPre_BusDef.AddMetaData({STREAM_LVL.Release, 1});
StackRelay_SENS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_RDIS_BusDef.AddMetaData({STREAM_LVL.Release, 1});
X90_Sens_BusDef.AddMetaData({STREAM_LVL.Release, 1});

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    USens_StCV_BusDef;
    Sens_IVT_BusDef;
    ISens_BoP_BusDef;
    RSens_ISOMON_BusDef;
    ISens_HVPre_BusDef;
    StackRelay_SENS_BusDef;
    TSens_RDIS_BusDef;
    X90_Sens_BusDef;
    ];

ElectricalSens_BusDef.AssignBusElements(busElements);

%% TSens_Ambt

TSens_Ambt_BusDef = BusDef("TSens_Ambt", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_T_degC_Ambt_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'degC',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_Ambt_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

TSens_Ambt_BusDef.AssignBusElements(busElements);

%% pSens_Ambt

pSens_Ambt_BusDef = BusDef("pSens_Ambt", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_p_bara_Ambt_Get' , 1,    'single',             -1,     'real', 'Sample','Fixed',  0,  120,    'bara',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_pAmbt_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

pSens_Ambt_BusDef.AssignBusElements(busElements);

%% CSens_H2Amb1

CSens_H2Amb1_BusDef = BusDef("CSens_H2Amb1", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_C_percentLeL_H2Amb1_Get' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'percentLel',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_H2Amb1_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

CSens_H2Amb1_BusDef.AssignBusElements(busElements);

%% CSens_H2Amb2

CSens_H2Amb2_BusDef = BusDef("CSens_H2Amb2", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_C_percentLeL_H2Amb2_Get' , 1,     'single',             -1,     'real', 'Sample','Fixed',  0,  100,    'percentLel',     '', {STREAM_LVL.Release, 1});...
    BusSignalDef('s_st_enum_H2Amb2_Get'   , 1,    'Enum: SENS_STATUS',  -1,     'real', 'Sample','Fixed',  [],  [],     '',         '', {STREAM_LVL.Release, 1});...
    ];

CSens_H2Amb2_BusDef.AssignBusElements(busElements);

%% TimeSync

TimeSync_BusDef = BusDef("TimeSync", "Descripton goes here");
busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_time_sync' , 1,     'single',             -1,     'real', 'Sample','Fixed',  [],  [],    '',     '', {STREAM_LVL.Release, 1});...
    ];

TimeSync_BusDef.AssignBusElements(busElements);

%% AmbientSens
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

AmbientSens_BusDef = BusDef("AmbientSens", "Descripton goes here");

CSens_H2Amb1_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CSens_H2Amb2_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TSens_Ambt_BusDef.AddMetaData({STREAM_LVL.Release, 1});
pSens_Ambt_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TimeSync_BusDef.AddMetaData({STREAM_LVL.Release, 1});

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    CSens_H2Amb1_BusDef;
    CSens_H2Amb2_BusDef;
    TSens_Ambt_BusDef;
    pSens_Ambt_BusDef;
    TimeSync_BusDef
    ];

AmbientSens_BusDef.AssignBusElements(busElements);
%% Sensors
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Sensors_BusDef = BusDef("Sensors", "Descripton goes here");

AnodeSens_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CathodeSens_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ThermalSens_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ThermalSens_Stage3_BusDef.AddMetaData({STREAM_LVL.All, 1});
ECoolingSens_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ElectricalSens_BusDef.AddMetaData({STREAM_LVL.Release, 1});
AmbientSens_BusDef.AddMetaData({STREAM_LVL.Release, 1});

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    AnodeSens_BusDef;
    CathodeSens_BusDef;
    ThermalSens_BusDef;
    ThermalSens_Stage3_BusDef;
    ECoolingSens_BusDef;
    ElectricalSens_BusDef;
    AmbientSens_BusDef;
    ];

Sensors_BusDef.AssignBusElements(busElements);

%% Generate Sensor Busses

Sensors_BusDef.GenerateRespectiveDatatypeStructures();

%% clear working variables

clear busElements
clear busName
