classdef EmergencyShutdownModeType < Simulink.IntEnumType
    % MATLAB enumeration class definition generated from template
    %   to track the active child state of ModularEmergencyShutdown/ModularEmergencyShutdown/EmergencyShutdown.
    
    enumeration
        None(0),
		Entry(1),
		ShutdownComplete(2),
		StopAnodeConcentrationControl(3),
		ShutdownAnodeAndRelatedSystems(4),
		ThermalAfterrun(5),
		OpenEACBlV(6),
		ShutoffCathode(7),
		LetAllOxygenInCathodeReact(8),
		DelayAfterOxygenReacted(9),
		DisconnectLoad(10)
    end

    methods (Static)

        function defaultValue = getDefaultValue()
            % GETDEFAULTVALUE  Returns the default enumerated value.
            %   If this method is not defined, the first enumeration is used.
            defaultValue = EmergencyShutdownModeType.None;
        end

        function dScope = getDataScope()
            % GETDATASCOPE  Specifies whether the data type definition should be imported from,
            %               or exported to, a header file during code generation.
            dScope = 'Auto';
        end

        function desc = getDescription()
            % GETDESCRIPTION  Returns a description of the enumeration.
            desc = 'enumeration to track active child state of ModularEmergencyShutdown/ModularEmergencyShutdown/EmergencyShutdown';
        end

        function fileName = getHeaderFile()
            % GETHEADERFILE  Returns path to header file if non-empty.
            fileName = '';
        end

        function flag = addClassNameToEnumNames()
            % ADDCLASSNAMETOENUMNAMES  Indicate whether code generator applies the class name as a prefix
            %                          to the enumeration.
            flag = true;
        end

    end

end
