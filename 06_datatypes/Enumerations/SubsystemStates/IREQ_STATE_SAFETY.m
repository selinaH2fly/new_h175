classdef IREQ_STATE_SAFETY < Simulink.IntEnumType
  enumeration
    Safe(0)
    EmergencyShutdown(1)
    Off(2)
    RampOff(3)
    SurgeDerating(4)
    RampOn(5)
    FastOff(6)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 