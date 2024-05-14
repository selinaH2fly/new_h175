classdef VLV_SELF_TEST < Simulink.IntEnumType
  enumeration
    Idle(0)
    Testing(1)
    Success(2)
    Failed(3)
    Aborted(4)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 