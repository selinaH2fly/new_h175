
function deriveInitStructsFromBusDefinition(busName, structPrefix, initParameter, suppressOutput)

    % extend initParameter with an indication column

    nParameter = size(initParameter,1);

    emptyInit = isempty(initParameter);

    if ~emptyInit
        
        initParameter = [initParameter, repmat({false},[nParameter,1])];

    end

    % initialize struct from bus and sub-structs from sub-buses
    [~,initParameter] = processBusFields(busName, structPrefix, initParameter, suppressOutput);


    % indicate if a parameter could not be assigned to corresponding field
    % from the bus definition

    if (~emptyInit) && (~suppressOutput)

        fprintf(2,"\n Not assignable parameters  \n")
        fprintf(2,"----------------------------\n")

        for idx = 1:nParameter
        
            if initParameter{idx,3} == false

                
            
                fprintf(2,"\nParameter '" + string(initParameter{idx,1} + "' could not be assigned to any field. Please check your parameter name or the bus definition."))

            end %if
        end %for
    end %for

end %function

function [structHandle, initParameter] = processBusFields(busName, structPrefix, initParameter, suppressOutput)
    % allocate struct
    
    structHandle = struct();

    % Get Bus Elements    
    busDefinition = evalin('base', busName);

    busElements = busDefinition.Elements;
    
    for idxElements = 1:length(busElements)

        if checkForNonStructuredDatatype(busElements(idxElements).DataType)       

            [structHandle, initParameter] = assignValueToField(busElements(idxElements), structHandle, initParameter, suppressOutput);
           
        else
            
            busDataTypeName = busElements(idxElements).DataType(6:end);

            % call function recursivly again
            [structHandle.(busElements(idxElements).Name), initParameter] = processBusFields(busDataTypeName, structPrefix, initParameter, suppressOutput);

        end %if

    end %for
    
    

    assignin('base',structPrefix + busName, structHandle)


end %function


function [structHandleOut, initParameter] = assignValueToField(busElement, structHandleIn, initParameter, suppressOutput)
    %disp("   " + busElement.Name)

    structHandleOut = structHandleIn;

    if isempty(initParameter)

        structHandleOut.(busElement.Name) = getDefaultValueByDatatype(busElement);

    else

        idx = checkIfParameterShallBeAssigned(busElement, initParameter);

        if idx == -1

            
            structHandleOut.(busElement.Name) = getDefaultValueByDatatype(busElement);

             % print
             if ~suppressOutput
                fprintf(2, "\nParameter '" + busElement.Name + "' was assigned by a standard value.")
             end %if

        else
            
            %convert double to single
            if isa(initParameter{idx,2},'double')
                
                structHandleOut.(busElement.Name) = single(initParameter{idx,2});
                initParameter{idx,3} = true;
         
            else
                
                structHandleOut.(busElement.Name) = initParameter{idx,2};
                initParameter{idx,3} = true;
            
            end %if

        end %if


    end %if

end

function idx = checkIfParameterShallBeAssigned(busElement, initParameter)

    for idx = 1:size(initParameter,1)

        if strcmp(busElement.Name, initParameter{idx,1})
            
            return

        end %if

    end %for

    idx = -1;

end %function


function bool = checkForNonStructuredDatatype(datatype)

    bool = false;

    if (string(datatype) == "single")

        bool = true;

        return

    end %if

    if (string(datatype) == "double")
        warning("The Parameter Structure contains a double value")
        bool = true;
    
        return

    end %if

    if (string(datatype) == "boolean")

        bool = true;

        return

    end %if

    if (strncmp("Enum",string(datatype),4))

        bool = true;

        return

    end %if

    if (string(datatype) == "uint32")

        bool = true;
    
        return

    end %if

    if (string(datatype) == "int32")

        bool = true;
    
        return

    end %if

end %for

function defaultValue = getDefaultValueByDatatype(busElement)

    defaultValue = single(0.0);

    if string(busElement.DataType) == "single"

        defaultValue = repmat(single(0.0), busElement.Dimensions);

    elseif string(busElement.DataType) == "boolean"

        defaultValue = repmat(false, busElement.Dimensions);

    elseif string(busElement.DataType) == "uint32"

        defaultValue = repmat(uint32(0), busElement.Dimensions);

    elseif string(busElement.DataType) == "int32"

        defaultValue = repmat(int32(0), busElement.Dimensions);
        
    elseif (strncmp("Enum",string(busElement.DataType),4))
        
        % assign the null value of that enum
        eval("defaultValue = " + string(busElement.DataType(7:end))+"("+string(0)+");")

    end %if



end %function