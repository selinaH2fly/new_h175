classdef ARECI_STATE < Simulink.IntEnumType
  enumeration
    Off(1)
    TurningOff(2)
    TurningOn(3)
    Idle(4)
    Startup(5)
    Run(6)
    Fault(7)
    ResetFault(8)
    ConstRpmLow(9)
    ConstRpmMid(10)
    ConstRpmHigh(11)
    FlushAnodeWithH2(12)
    FlushAnodeWithN2(13)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end

%     Off(1)
%     Startup(2)
%     Run(3)
%     TurningOff(4)
%     TurningStartup(5)
%     TurningRun(6)
%     Shutdown(7)
%     Fault(8)