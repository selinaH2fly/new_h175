classdef PUMP_STATE < Simulink.IntEnumType
  enumeration
    Idle(0)
    Off(1)
    On(2)
    Fault(3)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 