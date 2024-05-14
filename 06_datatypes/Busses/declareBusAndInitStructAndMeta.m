function declareBusAndInitStructAndMeta(busName, busElementsIn, flagCheckNameLength, varargin)

    
    flagParameterBus = false;

    if length(varargin) > 0

        if length(varargin) ~= 1

            error("too much inputs values")

        end %if

        if varargin{1} == 'ParameterBus'

            flagParameterBus = true;
            values = struct();
        else
            error("unkown special bus")            
        end %if
    end %if

    maxCharacterBusSignal = 32;

    % extract meta and busCell information
    metaCell = busElementsIn;
    busElements = busElementsIn;

    for i=1:length(busElementsIn)
        metaCell(i) = {[busElementsIn{i}(1), busElementsIn{i}(end)]};
        
        if flagParameterBus
            busElements(i)  = {[busElementsIn{i}(1), busElementsIn{i}(3:end-1)]};
            % pepare values struct for parameter init struct

            if contains(busElementsIn{i}{4},'Enum:')
                
                eval("values." + busElementsIn{i}(1) + " = busElementsIn{i}{2}';");
            else

                eval("values." + busElementsIn{i}(1) + " = " + busElementsIn{i}{4} + "(busElementsIn{i}{2}');");
            end %if
        else        
            busElements(i) = {busElementsIn{i}(1:end-1)};
        end %if

    end %for
    
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

    % init struct derived from bus definition
    eval("struct_" + busName + " = Simulink.Bus.createMATLABStruct('" + busName + "');")
    
    % assign struct into base workspace
    assignin("base", "struct_" + busName, eval("struct_" + busName));

    if flagParameterBus
    
        % init_struct for parameter bus
        eval("init_" + busName + " = Simulink.Bus.createMATLABStruct('" + busName + "', values);")
        
        % assign init struct into base workspace
        assignin("base", "init_" + busName, eval("init_" + busName));

    end %if

    % generate meta structs

    % Option A: nested bus structure, similar to init_parameters
    % Downside: meta data of busses cannot be processed

    % deriveMetaStructsFromBusDefinition(busName, "meta_", metaCellUnpacked, 1)

    % Option B: each bus structure is reflected by a meta structure
    % containing the meta information
    % Downside: not as easy to iterate over, since it does not have the
    % nested structure

    % iterate over bus elements
    structHandle = struct();
    busDefinition = evalin('base', busName);
    theseBusElements = busDefinition.Elements;
    for i = 1:length(theseBusElements)
        % assign bus elements to new struct
        structHandle.(theseBusElements(i).Name) = metaCellUnpacked{i,2};
    end
    % assign new struct in workspace
    assignin('base','meta_' + busName, structHandle)
    
end

