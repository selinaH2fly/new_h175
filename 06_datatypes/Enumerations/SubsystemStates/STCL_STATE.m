classdef STCL_STATE < Simulink.IntEnumType
  enumeration
    Off(0)
    SelfTest(1)
    Idle(2)
    TurningOn(3)
    TurningOff(4)
    HeatUpStack(5)
    NormalOperationMode1(6)
    NormalOperationMode2(7)
    Fault(8)
    ResetFault(9)
    MaintenanceOverride(10)
    AutoOff(11)

    %%OLD
    %BothPumpsFFWD(9)
    %auxPumpTCVControlled(10)
    %auxPumpPressureControlled(11)
    %OpeningTCV(1)
    %StartingTCP(2)
    %ShutdownCooling(4)
    %StoppingTCP(5)
    %ClosingTCV(6)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 