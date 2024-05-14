function parameterBusInitStruct = ParamElement(name,value,dimensions,datatype,sampleTime,complexity,samplingMode,dimensionMode, lowerLim, upperLim, unit, description, metaData)

    % {'p_ARECI_SP_Off_omega_rpm'             , 0                         ,   1,  'single',               -1, 'real', 'Sample','Fixed',   [],     [],    'rpm',  '', {STREAM_LVL.Release, 1}};...

    metaDataFields = ["streamLevel";
                      "property2";
                      "property3";
                      "property4"];
                    


    parameterBusInitStruct = struct();

    parameterBusInitStruct.name             = name;
    parameterBusInitStruct.value            = value;
    parameterBusInitStruct.dimensions       = dimensions;
    parameterBusInitStruct.datatype         = datatype;
    parameterBusInitStruct.sampleTime       = sampleTime;
    parameterBusInitStruct.complexity       = complexity;
    parameterBusInitStruct.samplingMode     = samplingMode;
    parameterBusInitStruct.dimensionMode    = dimensionMode;
    parameterBusInitStruct.lowerLim         = lowerLim;
    parameterBusInitStruct.upperLim         = upperLim;
    parameterBusInitStruct.unit             = unit;
    parameterBusInitStruct.description      = description;

    metaDataStruct = struct();

    for idx = 1:numel(metaData)

        metaDataStruct.(metaDataFields(idx)) = metaData{1};

    end %for    
    parameterBusInitStruct.metaData         = metaDataStruct;
    parameterBusInitStruct.busName          = '';
    parameterBusInitStruct.topLevelBusName  = '';


end