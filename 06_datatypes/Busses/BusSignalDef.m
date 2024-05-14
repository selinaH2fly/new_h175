classdef BusSignalDef < handle
    %BUSELEMENT Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        name                      
        dimensions       
        datatype        
        sampleTime       
        complexity       
        samplingMode    
        dimensionMode    
        lowerLim        
        upperLim         
        unit      
        resolution
        description
        metaData
        parentBusName
        busHierarchy
    end
    
    methods
        function obj = BusSignalDef(name,dimensions,datatype,sampleTime,complexity,samplingMode,dimensionMode, lowerLim, upperLim, unit, description, metaData)
            
            metaDataFields = ["StreamLevel";
                              "WriteAccess";
                              "property3";
                              "property4"];

            obj.name             = name;
            obj.dimensions       = dimensions;
            obj.datatype         = datatype;
            obj.sampleTime       = sampleTime;
            obj.complexity       = complexity;
            obj.samplingMode     = samplingMode;
            obj.dimensionMode    = dimensionMode;
            obj.lowerLim         = lowerLim;
            obj.upperLim         = upperLim;
            obj.unit             = unit;
            obj.resolution       = 1;
            obj.description      = description;

            metaDataStruct = struct();

            for idx = 1:numel(metaData)
                    
                    metaDataStruct.(metaDataFields(idx)) = metaData{idx};        
            end %for    

            obj.metaData            = metaDataStruct;
            obj.parentBusName       = '';
            obj.busHierarchy        = [];

        end
       
        function UpdateParentBus(obj,busNameNew)

            obj.parentBusName = busNameNew;

        end %function

        function UpdateBusHierarchy(obj, busHierarchyNew)

            obj.busHierarchy = busHierarchyNew;

        end %function        
    end
end

