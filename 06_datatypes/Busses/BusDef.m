classdef BusDef < handle & matlab.mixin.Copyable

    properties
        name
        busElements
        parentBusName
        busHierarchy
        description
        metaData
    end
    
    methods
        function obj = BusDef(name, description)

            obj.name = name;
            obj.metaData = {};
            obj.busElements = {};
            obj.parentBusName = '';
            obj.busHierarchy = [];
            obj.description = description;
            

        end

        function CheckBusElementsDatatype(obj, busElementsNew, datatypesPermit)

            for idx = 1:numel(busElementsNew)

                %for idxDatatype = 1:numel(datatypesPermit)

                    if ~ismember(string(class(busElementsNew(idx))), datatypesPermit)

                        flattenDatatypes = strjoin(datatypesPermit, ' or ');

                        error("busElementsNew elements are not from datatype " + flattenDatatypes + ".")

                    end %if 

                %end %for              

            end %for

        end %function
        
        function AssignBusElements(obj,busElementsNew)


            for idx = 1:numel(busElementsNew)

                busElementNew = busElementsNew(idx);

                busElementNew.UpdateBusHierarchy(obj.name);
            
                obj.busElements{end+1} = busElementNew;

            end %for

        end

        function UpdateParentBus(obj, parentBusName)

            obj.parentBusName = parentBusName; 
           
        end %function

        function UpdateBusHierarchy(obj, newBusHierarchy)

            obj.busHierarchy = newBusHierarchy;

            for idx = 1:numel(obj.busElements)

                obj.busElements{idx}.UpdateBusHierarchy([newBusHierarchy, obj.name])

            end %for

        end %function

        function GenerateRespectiveDatatypeStructures(obj)
            
            busElements = {};
            values = struct();
            
            % Meta Data Struct for Bus
            obj.InitMetaDataCell();

            for idx = 1:numel(obj.busElements)

                busElement = cell(1,11);

                if (isa(obj.busElements{idx}, 'BusDef') || ismember("BusDef", superclasses(class(obj.busElements{idx}))))

                    obj.busElements{idx}.GenerateRespectiveDatatypeStructures();

                    busElement{1}    = ['b_', char(obj.busElements{idx}.name)];
                    busElement{2}    = 1;
                    busElement{3}    = ['Bus: ', char(obj.busElements{idx}.name)];
                    busElement{4}    = -1;
                    busElement{5}    = 'real';
                    busElement{6}    = 'Sample';
                    busElement{7}    = 'Fixed';
                    busElement{8}    = [];
                    busElement{9}    = [];
                    busElement{10}   = '';
                    busElement{11}   = obj.busElements{idx}.description;

                    busElements{end+1} = busElement; 
                   
                                        
                else 

                    busElement{1}    = obj.busElements{idx}.name;
                    busElement{2}    = obj.busElements{idx}.dimensions;
                    busElement{3}    = obj.busElements{idx}.datatype;
                    busElement{4}    = obj.busElements{idx}.sampleTime;
                    busElement{5}    = obj.busElements{idx}.complexity;
                    busElement{6}    = obj.busElements{idx}.samplingMode;
                    busElement{7}    = obj.busElements{idx}.dimensionMode;
                    busElement{8}    = obj.busElements{idx}.lowerLim;
                    busElement{9}    = obj.busElements{idx}.upperLim;
                    busElement{10}   = obj.busElements{idx}.unit;
                    busElement{11}   = obj.busElements{idx}.description;
            
                    busElements{end+1} = busElement; 

                    %values.(obj.busElements{idx}.name) = obj.busElements{idx}.values
                
                end %if

                

                % Parameter 
                if isa(obj, "BusParamDef")

                    if isa(obj.busElements{idx}, "BusSignalParamDef")
                        
                        castDatatype = "";
    
                        if contains(obj.busElements{idx}.datatype, "Bus:")
    
                            castDatatype = string(obj.busElements{idx}.datatype);
    
                        elseif contains(obj.busElements{idx}.datatype, "Enum:")
                        
                            castDatatype = ''; %string(obj.busElements{idx}.datatype);
    
                        else                            
    
                            castDatatype = string(obj.busElements{idx}.datatype);
    
                        end %if
    
                        eval("castedValue = " + castDatatype +"(obj.busElements{idx}.value');");
    
                        values.(obj.busElements{idx}.name) = castedValue;
    
                        clear castedValue;
    
    
                    else
    
                        %splittedStrings = strsplit(obj.busElements{idx}.name,'_');
    
                        structValue = evalin("base","init_" + obj.busElements{idx}.name);
    
                        values.("b_" + obj.busElements{idx}.name) = structValue;
    
                    end %if

                end


            end %for

            % synthesize busCell
            busCell = {{obj.name, '', '', 'Auto', '-1', '0', busElements, }};                   
            
            % define bus
            Simulink.Bus.cellToObject(busCell)
        
            % init struct derived from bus definition
            eval("struct_" + obj.name + " = Simulink.Bus.createMATLABStruct('" + obj.name + "');")
            
            % assign struct into base workspace
            assignin("base", "struct_" + obj.name, eval("struct_" + obj.name));

            % if the BusDefObject is from the 
            if isa(obj, "BusParamDef")

                % init structes with inital values
                eval("init_" + obj.name + " = Simulink.Bus.createMATLABStruct('" + obj.name + "', values);")
    
                % assign init struct into base workspace
                assignin("base", "init_" + obj.name, eval("init_" + obj.name));

            end %if
            


        end %function

        function AddMetaData(obj, metaData)

            obj.metaData = metaData;

        end % function

        function InitMetaDataCell(obj)
            
            % init empty struct
            metaStruct = struct();
            
            % iterate over bus elements
            for idx = 1:numel(obj.busElements)

                % if object is from "BusDef" or from "BusDef"-Subclass -->
                if (isa(obj.busElements{idx}, 'BusDef') || ismember("BusDef", superclasses(class(obj.busElements{idx}))))

                    metaStruct.("b_" + obj.busElements{idx}.name) = obj.busElements{idx}.metaData;
                
                % element is bus signal definition object
                else

                    metaStruct.(obj.busElements{idx}.name) = struct2cell(obj.busElements{idx}.metaData)';
                end %if

            end %for
            
            % save meta struct to base workspace
            assignin("base", "meta_" + obj.name, metaStruct);

            


        end %function
    end
end

