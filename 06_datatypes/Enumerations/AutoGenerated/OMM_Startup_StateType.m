classdef OMM_Startup_StateType < Simulink.IntEnumType
    % MATLAB enumeration class definition generated from template
    %   to track the active leaf state of Startup/Startup.
    
    enumeration
        None(0),
		DisableIsolationMonitor(1),
		EnableHV(2),
		StartCoolingSystems(3),
		StartCathodeControlSystems(4),
		ConnectStackNegativePole(5),
		OpenASV_StartARECI(6),
		StartAnodePressureController(7),
		NotOK(8),
		OK(9),
		StartCathode(10),
		WaitForOCV(11),
		waitForCompressor(12),
		FlushCathode(13),
		ConnectLoad(14),
		Wait(15),
		APD_StartupEvent(16),
		APD_Timebased(17),
		RunupOver20A(18)
    end

    methods (Static)

        function defaultValue = getDefaultValue()
            % GETDEFAULTVALUE  Returns the default enumerated value.
            %   If this method is not defined, the first enumeration is used.
            defaultValue = OMM_Startup_StateType.None;
        end

        function dScope = getDataScope()
            % GETDATASCOPE  Specifies whether the data type definition should be imported from,
            %               or exported to, a header file during code generation.
            dScope = 'Auto';
        end

        function desc = getDescription()
            % GETDESCRIPTION  Returns a description of the enumeration.
            desc = 'enumeration to track active leaf state of Startup/Startup';
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
