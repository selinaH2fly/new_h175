classdef CAC_STATE < Simulink.IntEnumType
  enumeration
    Off(0)
    SelfTest(1)
    Standby(2)
    Idle(3)
    TurningOff(4)
    TurningOn(5)
    provideExhaustFlow(6)
    Fault(7)
    ResetFault(8)
    DryCathode(9)
    constRpm1(10)
    constRpm2(11)
    constMassflow1(12)
    constMassflow2(13)
    currentControlledMassflow(14)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 

%     Init(0)
%     Off(1)
%     Idle(2)
%     Purge(3)
%     Run(4)
%     Shutdown(5)
%     TurningOn(6)
%     TurningOff(7)
%     Fault(8)