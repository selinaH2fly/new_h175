classdef STCL_STATE_SAFETY < Simulink.IntEnumType
  enumeration
    Safe(0)
    ESD_MaxCooling(1)
    ESD_MinCooling(2)
    ESD_Off(3)
    ResetESD(4)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 