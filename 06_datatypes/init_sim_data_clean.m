%% run OK script for parameter

cleanSimData = { ... 
 % thermal Sim Data
's_p_bara_CLSto_Sim',       0;
's_VDot_lpm_STCL_Sim',      0;
's_VDot_lpm_MixCold_Sim',   0;
's_VDot_lpm_MixHot_Sim',    0;
's_VDot_lpm_ByP_Sim',       0;
's_VDot_lpm_Rad_Sim',       0;
};

deriveInitStructsFromBusDefinition("ThermalSim","clean_data_", cleanSimData, true);
