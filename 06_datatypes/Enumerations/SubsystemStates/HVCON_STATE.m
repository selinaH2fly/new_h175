classdef HVCON_STATE < Simulink.IntEnumType
  enumeration
    Init(0)
    Disconnected(1)
    Precharge(2)
    Connected(3)
    Fault(4)
    ResetFault(5)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 