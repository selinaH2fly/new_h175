classdef SD_TRANSITION_TYPE < Simulink.IntEnumType
  enumeration
    FaultShutdown(0)
    UserCommandedHardShutdown(1)
    SafetyMonitorShutdown(2)
    SensorStatusShutdown(3)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 