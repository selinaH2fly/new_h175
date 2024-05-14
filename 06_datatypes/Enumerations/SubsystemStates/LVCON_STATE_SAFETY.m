classdef LVCON_STATE_SAFETY < Simulink.IntEnumType
  enumeration
    Safe(0)
    EmergencyShutdown(1)
    Off(2)
    ResetESD(3)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 