% This script initializes buses fed to the PC DoE model

%% anode supply

anode_supply = Simulink.Bus;

anode_supply_elements(1) = Simulink.BusElement;
anode_supply_elements(1).Name = 'h2_molar_concentration';

anode_supply_elements(2) = Simulink.BusElement;
anode_supply_elements(2).Name = 'stoichiometry';

anode_supply_elements(3) = Simulink.BusElement;
anode_supply_elements(3).Name = 'dewpoint_temperature_degC';

anode_supply_elements(4) = Simulink.BusElement;
anode_supply_elements(4).Name = 'inlet_temperature_degC';

anode_supply_elements(5) = Simulink.BusElement;
anode_supply_elements(5).Name = 'inlet_pressure_barg';

anode_supply.Elements = anode_supply_elements;

%% cathode supply

cathode_supply = Simulink.Bus;

cathode_supply_elements(1) = Simulink.BusElement;
cathode_supply_elements(1).Name = 'stoichiometry';

cathode_supply_elements(2) = Simulink.BusElement;
cathode_supply_elements(2).Name = 'dewpoint_temperature_degC';

cathode_supply_elements(3) = Simulink.BusElement;
cathode_supply_elements(3).Name = 'inlet_temperature_degC';

cathode_supply_elements(4) = Simulink.BusElement;
cathode_supply_elements(4).Name = 'inlet_pressure_barg';

cathode_supply.Elements = cathode_supply_elements;

%% coolant

coolant_supply = Simulink.Bus;

coolant_supply_elements(1) = Simulink.BusElement;
coolant_supply_elements(1).Name = 'inlet_flow_lpmin';

coolant_supply_elements(2) = Simulink.BusElement;
coolant_supply_elements(2).Name = 'inlet_temperature_degC';

coolant_supply.Elements = coolant_supply_elements;