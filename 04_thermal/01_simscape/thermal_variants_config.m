%% Variant Subsystems Configuration
% This script defines variant subsystem expressions and lets the user
% change between variant implementations.

%% Thermal Subsystem Stage
% Change between different stage models of the H2F-175 thermal subsystem.

% Definition
THERMALMODEL_VARIANT_STAGE_TWO = Simulink.Variant('THERMALMODEL_VARIANT_STAGE==2');
THERMALMODEL_VARIANT_STAGE_THREE = Simulink.Variant('THERMALMODEL_VARIANT_STAGE==3');

% Actual Choice
THERMALMODEL_VARIANT_STAGE = 2;

%% Heat Exchanger
% Change between different variants of modeling the external heat exchanger
% (not considered part of H2F-175).

% Definition
HEATEXCHANGER_VARIANT_PHYSICAL = Simulink.Variant('HEATEXCHANGER_VARIANT_MODE==1');
HEATEXCHANGER_VARIANT_POWER_CONTROLLED = Simulink.Variant('HEATEXCHANGER_VARIANT_MODE==2');
HEATEXCHANGER_VARIANT_TEMP_CONTROLLED = Simulink.Variant('HEATEXCHANGER_VARIANT_MODE==3');

% Actual Choice
HEATEXCHANGER_VARIANT_MODE = 1;

