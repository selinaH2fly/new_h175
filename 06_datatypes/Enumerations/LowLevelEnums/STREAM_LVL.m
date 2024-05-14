%debug enumeration which is to be replaced by a more specific one
%for now it is used for instance to turn fault monitors on and off
%
classdef STREAM_LVL < Simulink.IntEnumType
  enumeration
    Release(0)
    Verbose(1)
    Debug(2)
    All(3)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 