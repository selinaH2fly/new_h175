classdef ECCL_STATE < Simulink.IntEnumType
  enumeration
    Off(0)
    TurningOff(1)
    TurningOn(2)
    Fault(3)
    ResetFault(4)
    Idle(5)
    constRpmMax(6)
    MaintenanceOverride(7)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 