function initTopLevelParameterBusses(busName)

% get bus element names
bus = evalin('base', busName);

busElements = bus.Elements;

%busElementNames = [];

initStruct = struct();

for idx = 1:numel(busElements)

    busElementName = string(bus.Elements(idx).Name);
    
    splittedStrings = strsplit(busElementName,'b_');

    busElementName = splittedStrings(2);
    

    initStructSubBus = evalin('base', "init_" + busElementName);


    eval("initStruct." + "b_" + busElementName + " = initStructSubBus;" )


end %for

assignin("base", "init_" + busName, initStruct);

end

