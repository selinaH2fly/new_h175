classdef CSEP_STATE_SAFETY < Simulink.IntEnumType
  enumeration
    Safe(0)
    EmergencyShutdown(1)
    HardOff(2)
    ResetESD(3)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 