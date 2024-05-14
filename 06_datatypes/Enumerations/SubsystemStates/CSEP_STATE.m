classdef CSEP_STATE < Simulink.IntEnumType
  enumeration
    Closed(0)
    OpeningCSIVCSOV(1)
    OpeningCSOVCSIV(2)
    Opened(3)
    Closing(4)
    Fault(5)
    ResetFault(6)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 