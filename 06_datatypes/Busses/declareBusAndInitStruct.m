function declareBusAndInitStruct(busName, busElementsIn, flagCheckNameLength)

    maxCharacterBusSignal = 32;

    % extract meta and busCell information
    metaCell = busElementsIn;
    busElements = busElementsIn;

    for i=1:length(busElementsIn)
        metaCell(i) = {[busElementsIn{i}(1), busElementsIn{i}(end)]};
        busElements(i) = {busElementsIn{i}(1:end-1)};
    end
    
    %convert meta cell into correct format
    metaCellUnpacked=cat(1,metaCell{:});

    % synthesize busCell
    busCell = {{busName, '', '', 'Auto', '-1', '0', busElements, }};

    % check for bus signal length
    
    if flagCheckNameLength == true

        for idx = 1:numel(busElements)
    
            if (length(busElements{idx}{1}) > 32)
                
                fprintf(2, "\nBus Signal " + busElements{idx}{1} + " from Bus " + busName + " has more than the " + string(maxCharacterBusSignal) + " allowed characters.")
    
            end %if
    
        end %for
        
    end %if
    
    % define bus
    Simulink.Bus.cellToObject(busCell)

    % meta struct derived from bus definition
    %deriveInitStructsFromBusDefinition(busName, "meta_", metaCellUnpacked, 0)
    
    % init struct derived from bus definition
    eval("struct_" + busName + " = Simulink.Bus.createMATLABStruct('" + busName + "');")
    
    % assign struct into base workspace
    assignin("base", "struct_" + busName, eval("struct_" + busName));
    
end

