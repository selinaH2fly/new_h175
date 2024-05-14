flagCheckNameLength = true;

%% ARP1_ACT

ARP1_ACT_BusDef = BusDef("ARP1_ACT", "Descripton goes here");

busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_ARP1_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  1e5,    'rpm',  'input signal for anode recirculation pump', {STREAM_LVL.Release, 1}); ...
    ];

ARP1_ACT_BusDef.AssignBusElements(busElements);

%% ARP2_ACT

ARP2_ACT_BusDef = BusDef("ARP2_ACT", "Descripton goes here");

busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_ARP2_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  1e5,    'rpm',  'input signal for anode recirculation pump', {STREAM_LVL.Release, 1}); ...
    ];

ARP2_ACT_BusDef.AssignBusElements(busElements);

%% ASV

ASV_BusDef = BusDef("ASV", "Descripton goes here");

busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_enum_ASV_Set'     , 1,    'Enum: DVLV_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  'set signal for anode seperation signal', {STREAM_LVL.Release, 1}); ...
    ];

ASV_BusDef.AssignBusElements(busElements);

%% APRV

APRV_BusDef = BusDef("APRV", "Descripton goes here");

busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_APRV_Set'   , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_pos_percent_APRV1_Set'  , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_pos_percent_APRV2_Set'  , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_pos_percent_APRV3_Set'  , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    ];

APRV_BusDef.AssignBusElements(busElements);

%% APRV1

APRV1_BusDef = BusDef("APRV1", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_APRV1_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_Current_mA_APRV1_set'      , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4000,    'mA',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    ];

APRV1_BusDef.AssignBusElements(busElements);

%% APRV2

APRV2_BusDef = BusDef("APRV2", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_APRV2_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_Current_mA_APRV2_set'      , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4000,    'mA',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    ];

APRV2_BusDef.AssignBusElements(busElements);

%% APRV_LO

APRV_LO_BusDef = BusDef("APRV_LO", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_APRV_LO_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_Current_mA_APRV_LO_set'      , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  4000,    'mA',  'set signal for anode pressure regulation valve', {STREAM_LVL.Release, 1}); ...
    ];

APRV_LO_BusDef.AssignBusElements(busElements);

%% APV

APV_BusDef = BusDef("APV", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_enum_APV_Set'               , 1,    'Enum: DVLV_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '(delayed) set signal for anode purge valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_pos_scheduled_enum_APV_Set'     , 1,    'Enum: DVLV_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  'scheduled set signal for anode purge valve', {STREAM_LVL.Debug, 1}); ...
    BusSignalDef('p_APV_Current_OpenTime'           , 1,    'single',               -1,             'real', 'Sample','Fixed',    [],  [],    '',  'the current opening time of the purge valve', {STREAM_LVL.Debug, 1}); ...
    ];

APV_BusDef.AssignBusElements(busElements);

%% ADV

ADV_BusDef = BusDef("ADV", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_enum_ADV_Set'               , 1,    'Enum: DVLV_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '(delayed) set signal for anode drain valve', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_pos_scheduled_enum_ADV_Set'     , 1,    'Enum: DVLV_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  'scheduled set signal for anode drain valve', {STREAM_LVL.Debug, 1}); ...
    BusSignalDef('p_ADV_Current_OpenTime'           , 1,    'single',               -1,             'real', 'Sample','Fixed',    [],  [],    '',  'the current opening time of the drain valve', {STREAM_LVL.Debug, 1}); ...
    ];

ADV_BusDef.AssignBusElements(busElements);


%% AnodeAct
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
AnodeAct_BusDef = BusDef("AnodeAct", "Descripton goes here");

% Add Stream Levels
ARP1_ACT_BusDef.AddMetaData({STREAM_LVL.All, 1});
ARP2_ACT_BusDef.AddMetaData({STREAM_LVL.All, 1});
ASV_BusDef.AddMetaData({STREAM_LVL.Release, 1});     
APRV_BusDef.AddMetaData({STREAM_LVL.Release, 1});    
APRV1_BusDef.AddMetaData({STREAM_LVL.All, 1});   
APRV2_BusDef.AddMetaData({STREAM_LVL.All, 1});   
APRV_LO_BusDef.AddMetaData({STREAM_LVL.All, 1}); 
APV_BusDef.AddMetaData({STREAM_LVL.Release, 1});     
ADV_BusDef.AddMetaData({STREAM_LVL.Release, 1});     


busElements = [
    ARP1_ACT_BusDef;
    ARP2_ACT_BusDef;
    ASV_BusDef;     
    APRV_BusDef;    
    APRV1_BusDef;   
    APRV2_BusDef;   
    APRV_LO_BusDef; 
    APV_BusDef;     
    ADV_BusDef;     
    ];


AnodeAct_BusDef.AssignBusElements(busElements);

signal = BusSignalDef('b_ADV2'           , 1,    'Bus: ADV',               -1,             'real', 'Sample','Fixed',    [],  [],    '',  'the current opening time of the drain valve', {STREAM_LVL.All, 1});

AnodeAct_BusDef.AssignBusElements(signal);

%% EAC_ACT

EAC_ACT_BusDef = BusDef("EAC_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_EAC_Set'      , 1,    'single',   -1,             'real', 'Sample','Fixed',  0,  10000,    'rpm',  'set signal for electric air compressor', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_Mmax_percent_EAC_Set'   , 1,    'single',   -1,             'real', 'Sample','Fixed',  0,  100,    'percent',  'Mmax signal for electric air compressor', {STREAM_LVL.Debug, 1}); ...
    BusSignalDef('s_reset_fault_EAC_Set'    , 1,    'boolean',   -1,             'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Debug, 1}); ...
    ];

EAC_ACT_BusDef.AssignBusElements(busElements);

%% CBV_ACT

CBV_ACT_BusDef = BusDef("CBV_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CBV_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  'set signal for cathode bypass valve', {STREAM_LVL.Release, 1}); ...
    ];

CBV_ACT_BusDef.AssignBusElements(busElements);

%% EATBV

EATBV_ACT_BusDef = BusDef("EATBV_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_EATBV_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  'set signal for Electric Air Turbine bypass valve', {STREAM_LVL.Release, 1}); ...
    ];

EATBV_ACT_BusDef.AssignBusElements(busElements);

%% EATVNT

EATVNT_ACT_BusDef = BusDef("EATVNT_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_EATVNT_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  'set signal for EAT VNT Valve', {STREAM_LVL.Release, 1}); ...
    ];

EATVNT_ACT_BusDef.AssignBusElements(busElements);

%% CSIV_ACT

CSIV_ACT_BusDef = BusDef("CSIV_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CSIV_Set'    , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for CSI valve', {STREAM_LVL.Release, 1}); ...
    ];

CSIV_ACT_BusDef.AssignBusElements(busElements);

%% CSOV_ACT

CSOV_ACT_BusDef = BusDef("CSOV_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CSOV_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for cathode shutoff valve', {STREAM_LVL.Release, 1}); ...
    ];

CSOV_ACT_BusDef.AssignBusElements(busElements);

%% CHUBVd

CHUBVd_ACT_BusDef = BusDef("CHUBVd_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CHUBVd_Set',      1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    '',  'set PWM signal for dry-side humidifier bypass valve', {STREAM_LVL.Release, 1}); ...
    ];

CHUBVd_ACT_BusDef.AssignBusElements(busElements);

%% CHUBVw

CHUBVw_ACT_BusDef = BusDef("CHUBVw_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CHUBVw_Set'              , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    '',  'set PWM signal for wet-side humidifier bypass valve', {STREAM_LVL.Release, 1}); ...
    ];

CHUBVw_ACT_BusDef.AssignBusElements(busElements);

%% CHXV_ACT

CHXV_ACT_BusDef = BusDef("CHXV_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_CHXV_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for chx valve', {STREAM_LVL.Release, 1}); ...
    ];

CHXV_ACT_BusDef.AssignBusElements(busElements);

%% ETV_ACT

ETV_ACT_BusDef = BusDef("ETV_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_percent_ETV_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  'set signal for throttle valve', {STREAM_LVL.Release, 1}); ...
    ];

ETV_ACT_BusDef.AssignBusElements(busElements);

%% TDV_ACT - Turbine Drain Valve

TDV_ACT_BusDef = BusDef("TDV_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_enum_TDV_Set'     , 1,    'Enum: DVLV_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    'percent',  'set signal for turbine drain valve', {STREAM_LVL.Release, 1}); ...
    ];

TDV_ACT_BusDef.AssignBusElements(busElements);

%% Cathode Act
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

CathodeAct_BusDef = BusDef("CathodeAct", "Descripton goes here");


EAC_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
EATBV_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
EATVNT_ACT_BusDef.AddMetaData({STREAM_LVL.All, 1});
CBV_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CSIV_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});    
CSOV_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CHUBVd_ACT_BusDef.AddMetaData({STREAM_LVL.All, 1});
CHUBVw_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CHXV_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ETV_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TDV_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});

busElements = [
    EAC_ACT_BusDef;
    EATBV_ACT_BusDef;
    EATVNT_ACT_BusDef;
    CBV_ACT_BusDef;
    CSIV_ACT_BusDef;
    CSOV_ACT_BusDef;
    CHUBVd_ACT_BusDef;
    CHUBVw_ACT_BusDef;
    CHXV_ACT_BusDef;
    ETV_ACT_BusDef;
    TDV_ACT_BusDef;
    ];


CathodeAct_BusDef.AssignBusElements(busElements);

%% auxTCP_ACT

auxTCP_ACT_BusDef = BusDef("auxTCP_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_auxTCP_Set'   , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  10000,    'rpm',  '', {STREAM_LVL.All, 1}); ...
    ];

auxTCP_ACT_BusDef.AssignBusElements(busElements);

%% TCP_ACT

TCP_ACT_BusDef = BusDef("TCP_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_TCP_Set'   , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  10000,    '',  '', {STREAM_LVL.Release, 1}); ...
    ];

TCP_ACT_BusDef.AssignBusElements(busElements);

%% TCV_ACT

TCV_ACT_BusDef = BusDef("TCV_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_per_TCV_Set'        , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  '', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_TCV_Histo_Enable'       , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  1,         '',  '', {STREAM_LVL.Debug, 1}); ...
    BusSignalDef('s_TCV_State_Command'      , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  255,    '',  '', {STREAM_LVL.Debug, 1}); ...
    ];

TCV_ACT_BusDef.AssignBusElements(busElements);

%% Thermal
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ThermalAct_BusDef = BusDef("ThermalAct", "Descripton goes here");

auxTCP_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TCP_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
TCV_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1}); 

busElements = [
    % signal name               %dim    %datatype   % sample time   %
    auxTCP_ACT_BusDef;
    TCP_ACT_BusDef;
    TCV_ACT_BusDef; 
    ];

ThermalAct_BusDef.AssignBusElements(busElements);

%% ETCP_ACT

ETCP_ACT_BusDef = BusDef("ETCP_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_omega_rpm_ETCP_Set', 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  10000,    'rpm',  '', {STREAM_LVL.Debug, 1}); ...
    ];

ETCP_ACT_BusDef.AssignBusElements(busElements);

%% ECooling_ACT
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ECoolingAct_BusDef = BusDef("ECoolingAct", "Descripton goes here");

ETCP_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});

busElements = [
    ETCP_ACT_BusDef;
    ];

ECoolingAct_BusDef.AssignBusElements(busElements);

%% StackRelays

StackRelays_BusDef = BusDef("StackRelays", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_enum_StNR_enum',    1,    'Enum: RELAY_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_pos_enum_StPrePR_enum', 1,    'Enum: RELAY_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_pos_enum_StPR_enum',    1,    'Enum: RELAY_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    ];

StackRelays_BusDef.AssignBusElements(busElements);

%% HVRelays

HVRelays_BusDef = BusDef("HVRelays", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_enum_HVPrePR_Set'   , 1,    'Enum: RELAY_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    BusSignalDef('s_pos_enum_HVPR_Set'      , 1,    'Enum: RELAY_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    ];

HVRelays_BusDef.AssignBusElements(busElements);

%% SKSSRelays

SKSSRelays_BusDef = BusDef("SKSSRelays", "Descripton goes here");
busElements = [
    % signal name                   %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_enum_SKSS_Enable_Set'   , 1,    'Enum: RELAY_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    ];

SKSSRelays_BusDef.AssignBusElements(busElements);

%% BoPRelays

BoPRelays_BusDef = BusDef("BoPRelays", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_pos_enum_BoPR_Set', 1,    'Enum: RELAY_STATE',   -1,             'real', 'Sample','Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    ];

BoPRelays_BusDef.AssignBusElements(busElements);

%% RSens_ISOMON_ACT

RSens_ISOMON_ACT_BusDef = BusDef("RSens_ISOMON_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_State_enum_ISOMON_Set'       , 1, 'Enum: ISOMON_STATE',              -1,   'real', 'Sample', 'Fixed',    [],  [],    '',  '', {STREAM_LVL.Release, 1}); ...
    ];

RSens_ISOMON_ACT_BusDef.AssignBusElements(busElements);

%% RDIS_ACT

RDIS_ACT_BusDef = BusDef("RDIS_ACT", "Descripton goes here");
busElements = [
    % signal name               %dim    %datatype   % sample time   %
    BusSignalDef('s_R_percent_RDIS_Set'     , 1,    'single',   -1,             'real', 'Sample','Fixed',    0,  100,    'percent',  '', {STREAM_LVL.Release, 1}); ...
    ];

RDIS_ACT_BusDef.AssignBusElements(busElements);

%% ElectricalAct

StackRelays_BusDef.AddMetaData({STREAM_LVL.Release, 1});
HVRelays_BusDef.AddMetaData({STREAM_LVL.Release, 1});
SKSSRelays_BusDef.AddMetaData({STREAM_LVL.All, 1});
BoPRelays_BusDef.AddMetaData({STREAM_LVL.Release, 1});
RSens_ISOMON_ACT_BusDef.AddMetaData({STREAM_LVL.Release, 1});
RDIS_ACT_BusDef.AddMetaData({STREAM_LVL.All, 1});

ElectricalAct_BusDef = BusDef("ElectricalAct", "Descripton goes here");
busElements = [
    StackRelays_BusDef;
    HVRelays_BusDef;
    SKSSRelays_BusDef;
    BoPRelays_BusDef;
    RSens_ISOMON_ACT_BusDef;
    RDIS_ACT_BusDef;
    ];

ElectricalAct_BusDef.AssignBusElements(busElements);

%% Actuators
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Actuators_BusDef = BusDef("Actuators", "Descripton goes here");

AnodeAct_BusDef.AddMetaData({STREAM_LVL.Release, 1});
CathodeAct_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ThermalAct_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ECoolingAct_BusDef.AddMetaData({STREAM_LVL.Release, 1});
ElectricalAct_BusDef.AddMetaData({STREAM_LVL.Release, 1});

busElements = [
    AnodeAct_BusDef;
    CathodeAct_BusDef;
    ThermalAct_BusDef;
    ECoolingAct_BusDef;
    ElectricalAct_BusDef;
    ];

Actuators_BusDef.AssignBusElements(busElements);

%% Generate Sensor Busses

Actuators_BusDef.GenerateRespectiveDatatypeStructures();

%% clear working variables

clear busElements
clear busName

