classdef CSTOBLV_STATE_SAFETY < Simulink.IntEnumType
  enumeration
    Safe(0)
    EmergencyShutdown(1)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 