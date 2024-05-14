classdef CHU_STATE_SAFETY < Simulink.IntEnumType
  enumeration
    Safe(0)
    ESD(1)
    ResetESD(2)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 