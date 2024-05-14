classdef RDIS_STATE < Simulink.IntEnumType
  enumeration
    Off(0)
    On(1)
    Fault(2)
    ResetFault(3)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 