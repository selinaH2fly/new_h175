flagCheckNameLength = true;

%% SensorChecks

persistentValues_Electrical_BusDef = BusParamDef("persistentValues_Electrical", "Descripton goes here");

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %
    % setpoints
    BusSignalParamDef('v_Electrical_RelayLifetime_N_D'   ,   0   , 1 , 'single',   		-1,     'real', 'Sample','Fixed',  [],  [],    '',  '', {STREAM_LVL.Release, 1});
    ];

persistentValues_Electrical_BusDef.AssignBusElements(busElements);

%% GlobalBus

persistentValues_BusDef = BusParamDef("persistentValues", "Descripton goes here");

persistentValues_Electrical_BusDef.AddMetaData({STREAM_LVL.Release, 1});

busElements = [ ... 
    % signal name               %dim    %datatype   % sample time   %    
    persistentValues_Electrical_BusDef
    ];

persistentValues_BusDef.AssignBusElements(busElements);

persistentValues_BusDef.GenerateRespectiveDatatypeStructures();


%% clear working variables

clear busElements
clear busName
