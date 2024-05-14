% Defined after compatibility with the PS100-System. Direct modes extracted
% from the manual
%
% Description of Commands as elaborated in Power Cell Manual "P System 100 - User Manual - Original instruction - Revision 03 (2021-05-24)" 
% near the enum entries

classdef OMM_STATE_CMD < Simulink.IntEnumType
    enumeration
        Standby_Stop(1)           %Powers the actuators if the system is in Off state or requests the system to stop if it is in Run state
        Run(2)                  %Request system to start and deliver power
        FastShutdown(3)         %Can be used to initiate fast shutdown, this is NOT an emergency stop
        Off_Emergency_Stop(4)   %Depowers actuators and halts the system immediately. Only recommended to use when the system is in Standby or when an emergency stop is needed.
        Start_Stop(5)           %If this state is requested from Run, the system will directly stop producing power. The system will be ready to start producting energy again by getting a new Run request. To shut down from this state, simply send Standby/Stop request.
        Service(6)              %Puts the fuel cell system in service mode
    end
      methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end
% hint: use this syntax to play around with the statemachine
% set_param('StateMachineArchitectureTest_V1/Host','Value','HostCmd.Start')