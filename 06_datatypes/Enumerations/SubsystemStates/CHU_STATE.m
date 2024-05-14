classdef CHU_STATE < Simulink.IntEnumType
  enumeration
    Off(0)
    Idle(1)
    SelfTest(2)
    Operation(3)
    Shutdown(4)
    Fault(5)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 