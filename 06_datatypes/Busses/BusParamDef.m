classdef BusParamDef < handle & BusDef

    properties
    end
    
    methods
        function obj = BusParamDef(name, description)
            
            obj@BusDef(name,description)           

        end %function
        
        function AssignBusElements(obj,busElementsNew)
            
            % check the datatype of the new bus elements
            obj.CheckBusElementsDatatype(busElementsNew, ["BusSignalParamDef", "BusParamDef"]);
           
            % call function for superclass assign the new bus elements to the bus
            AssignBusElements@BusDef(obj,busElementsNew);
           
        end %function
      
        function GenerateParameterListXLSX(obj, filepath)
        
            fileHandle = obj.OpenParameterListXLSX(filepath);
            
            obj.CloseParameterListXLSX(fileHandle);

        end %function

        function fileHandle = OpenParameterListXLSX(~, filePath)
          
            % Check if the file exists
            if exist(filePath, 'file')
                % Delete the file if it exists
                delete(filePath);
            end
        
            % Open the file for writing
            fileHandle = fopen(filePath, 'w');

        end %fucntion

        function CloseParameterListXLSX(~, filePath)
            % Close the file
            fclose(filePath); 
        end 

        function ExportParameterList(obj, fileNameParameterListExport)

            % check datatype suffix of filename
            if ~contains(fileNameParameterListExport, ".xlsx")
            
                stringSplitted = strsplit(fileNameParameterListExport,".");

                filename = stringSplitted(1) + ".xlsx";
            else 
                filename = fileNameParameterListExport;
            end %if

            filename = "Documents\Artefacts\" + filename;

            global parameterList;
            global parameterNumber;

            % init
            parameterList = {};
            parameterNumber = 0;
            
            try
                delete(filename)
            catch

            end 
            
            % copy from prepared template
            copyfile("Documents\Templates\Parameterlist_Template.xlsx", filename);
            
            % parameter data
            obj.AssembleParameterBusForList();
            writecell(parameterList, filename, "Sheet", "Functional_Parameter_List","WriteMode","append");
            
            % meta data of revision
            generationMetaData = {"Generation Date", datetime};
            writecell(generationMetaData, filename, "Sheet", "RevisionMetaData","WriteMode","append")

            clear parameterList;
            clear parameterNumber;

        end %function
        
        function AssembleParameterBusForList(obj)

            for idx = 1:numel(obj.busElements)
            
                if isa(obj.busElements{idx}, 'BusParamDef')
                    
                    % go to next hierarchy level
                    obj.busElements{idx}.AssembleParameterBusForList();
                    

                elseif isa(obj.busElements{idx}, 'BusSignalParamDef')

                    obj.busElements{idx}.AssembleParameterForList();

                else

                    error("Unexpected Datatype.")

                end %for
                


            end %for

            


        end %function
         
    end
end

