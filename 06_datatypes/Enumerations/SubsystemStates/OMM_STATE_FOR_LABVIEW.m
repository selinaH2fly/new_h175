%Enumeration Definition for the Operation Mode Manager
%tens define the superstate and ones define the substate
%i.e. "ControllerPowerup" is a substate of "Standby"
%
%Compiled Enum for the Communication with LabView --> the same as the
%powercell states
classdef OMM_STATE_FOR_LABVIEW < Simulink.IntEnumType
  enumeration
    Off(1)
    Standby(2)      % Actuators are powered and ready for requests.
    Start(3)        % System has received request to run; startup ongoing.
    Run(4)          % System is running and outputting power.
    Shutdown(5)     % System has received request to stop; shutdown ongoing.
    Error(6)        % System has encountered an error and is prevented from operating.
    Start_Stop(7)   % System has received a start-stop request and has stopped producing power.
    Service(8)      % The fuel cell system is in service mode and listens to the signals defined in the message Service.
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 