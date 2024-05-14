classdef APD_STATE < Simulink.IntEnumType
  enumeration
    Init(0)
    Off(1)
    PurgeOpen(2)
    DrainOpen(3)
    BothOpen(4)
    PurgeEvent(5)
    DrainEvent(6)
    PurgeEventExternal(7)
    DrainEventExternal(8)
    PurgeDrainEventStartup(9)
    Startup(10)
    Shutdown(11)
    DryCathode(12)
    timeBasedRun(13)
    
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 