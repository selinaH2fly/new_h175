% This struct is used to configure which is system variant is
% given. It utlizes enumerations and variant subsystems in the main model
% are configured acording to the variant definition herein.
variantConfigCell = {
'auxTCP'    , VARIANT_auxTCP.ControlledExtern;
'TCP'       , VARIANT_TCP.HVPump;
'ETCP'      , VARIANT_ETCP.ControlledExtern;
'TCV'       , VARIANT_TCV.BontazCAN;
'TCVDirection', VARIANT_TCVDirection.OPEN_IS_COOLING;
'EAC'       , VARIANT_EAC.FischerWithTurbine;
'Anode'     , VARIANT_Anode.Stage2;
};

variantConfig = cell2struct([variantConfigCell(1:end,2)],[variantConfigCell(1:end,1)],1);