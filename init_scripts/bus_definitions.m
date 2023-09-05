% This script initializes buses fed to the PC DoE model

%% anode supply

anode_supply = Simulink.Bus;

anode_supply_elements(1) = Simulink.BusElement;
anode_supply_elements(1).Name = 'h2_concentration';

anode_supply_elements(2) = Simulink.BusElement;
anode_supply_elements(2).Name = 'stoichiometry';

anode_supply_elements(3) = Simulink.BusElement;
anode_supply_elements(3).Name = 'dewpoint_temperature';

anode_supply_elements(4) = Simulink.BusElement;
anode_supply_elements(4).Name = 'inlet_temperature';

anode_supply_elements(5) = Simulink.BusElement;
anode_supply_elements(5).Name = 'inlet_pressure';

anode_supply.Elements = anode_supply_elements;

%% TODO: same for cathode and coolant