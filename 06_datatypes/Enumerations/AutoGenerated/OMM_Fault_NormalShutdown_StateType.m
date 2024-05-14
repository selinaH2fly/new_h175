classdef OMM_Fault_NormalShutdown_StateType < Simulink.IntEnumType
    % MATLAB enumeration class definition generated from template
    %   to track the active leaf state of NormalShutdownRevised/NormalShutdown.
    
    enumeration
        None(0),
		CloseCathode(1),
		LetAllOxygenReact(2),
		DisconnectLoad(3),
		ShutdownAnode(4),
		DisableHVEnableIsomon(5),
		Off(6),
		notSettled(7),
		Settled(8),
		Purge(9),
		Done(10),
		TurnOffCompressor(11),
		RampDownCurrentFromRun(12)
    end

    methods (Static)

        function defaultValue = getDefaultValue()
            % GETDEFAULTVALUE  Returns the default enumerated value.
            %   If this method is not defined, the first enumeration is used.
            defaultValue = OMM_Fault_NormalShutdown_StateType.None;
        end

        function dScope = getDataScope()
            % GETDATASCOPE  Specifies whether the data type definition should be imported from,
            %               or exported to, a header file during code generation.
            dScope = 'Auto';
        end

        function desc = getDescription()
            % GETDESCRIPTION  Returns a description of the enumeration.
            desc = 'enumeration to track active leaf state of NormalShutdownRevised/NormalShutdown';
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
