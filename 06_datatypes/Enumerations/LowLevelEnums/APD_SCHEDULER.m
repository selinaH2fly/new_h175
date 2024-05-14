classdef APD_SCHEDULER< Simulink.IntEnumType
  enumeration
    Idle(0)
    OpenPurge(1)
    OpenDrain(2)
    OpenDrain2(3)
    Wait(4)
    EventStartup(5)
    EventDone(6)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 