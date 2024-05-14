classdef SM_STATE < Simulink.IntEnumType
  enumeration
    % enums must be ranked by severity and lower limit before upper limit 
    OK(0)
    INACT_OORL(1)
    INACT_OORH(2)
    CAU_OORL(3)
    CAU_OORH(4)
    WARNL1_TOOL(5)
    WARNL1_TOOH(6)
    WARNL2_TOOL(7)
    WARNL2_TOOH(8)
    IMPLAUSIBLE(11)
    ERROR(12)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 