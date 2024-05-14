classdef BusSignalParamDef < handle & BusSignalDef
    %BUSELEMENT Summary of this class goes here
    %   Detailed explanation goes here
    
    properties             
        value 
        idxUDP = -1;           
    end

    properties (Constant = true)
        maxNameLength = 32;
        
    end %properties
    
    methods
        function obj = BusSignalParamDef(name,value,dimensions,datatype,sampleTime,complexity,samplingMode,dimensionMode, lowerLim, upperLim, unit, description, metaData)
                      
            % call constructor of inherited super class
            obj@BusSignalDef(name,dimensions,datatype,sampleTime,complexity,samplingMode,dimensionMode, lowerLim, upperLim, unit, description, metaData);
                                   
            % assign initial value to Parameter Signal Defintion
            obj.value            = value;
            obj.idxUDP           = -1;
            
            % Parameter LINT functions
            obj.LintFunctions();
            
        end

        function LintFunctions(obj)

            obj.CheckParameterLengthName();

        end %function

        function out = CheckParameterLengthName(obj)
        
            if (length(obj.name) > obj.maxNameLength)

                out = false;
                
                fprintf(2, "\nBus Signal " + parameterName + " from Bus " + busName + " has more than the " + string(maxCharacterBusSignal) + " allowed characters.")
    
            else 
                out = true;

            end %if

        end %function


        function AssembleParameterForList(obj)

            % parameter is scalar
            if isscalar(obj.value)                                                     

                obj.AssembleParameterCellForList(obj.name, obj.value);

            % parameter is vector or matrix
            else 

                [rowLength, columnLength] = size(obj.value);

                % parameter is standing or laying array
                if rowLength == 1 ||columnLength == 1 

                    if rowLength == 1 
                        nElements = columnLength;
                    else
                        nElements = rowLength;
                    end %if

                    for idxElement = 1:nElements
                
                        printName = string(obj.name) + "[" + num2str(idxElement) + "]"; 

                        printValue = obj.value(idxElement);
                        
                        obj.AssembleParameterCellForList(printName, printValue);                       

                    end %for

                % parameter is matrix
                else 

                    for idxRow = 1:rowLength
                    
                        for idxColumn = 1:columnLength

                            printName = string(obj.name) + "[" + num2str(idxRow) + "][" + num2str(idxColumn) + "]";

                            printValue = obj.value(idxRow, idxColumn);

                            obj.AssembleParameterCellForList(printName, printValue);

                        end %for
                    end %for
                end %if                            
            end %if

        end %function

        function AssembleParameterCellForList(obj, printName, printValue)
            
            global parameterList
            global parameterNumber
            
            parameterNumber = parameterNumber + 1;
            
            busHierarchy1 = obj.busHierarchy(2);

            try
                busHierarchy2 = obj.busHierarchy(3);
            catch
                busHierarchy2 = "";
            end 

            parameterCell = {parameterNumber, obj.idxUDP, printName, printValue, obj.lowerLim, obj.upperLim, busHierarchy1, busHierarchy2, '-', '-', '-','-','-', '-', obj.unit, obj.resolution, obj.description};
            
            if isempty(parameterList)

                parameterList = parameterCell;
            else 
                parameterList = [parameterList; parameterCell];
            end %if

        end %function
    
    end
end

