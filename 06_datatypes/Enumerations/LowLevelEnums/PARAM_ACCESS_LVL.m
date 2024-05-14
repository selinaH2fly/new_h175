%debug enumeration which is to be replaced by a more specific one
%for now it is used for instance to turn fault monitors on and off
%
classdef PARAM_ACCESS_LVL < Simulink.IntEnumType
  enumeration
    READ_ONLY(0)
    WRITE(1)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 