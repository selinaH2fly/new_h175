%debug enumeration which is to be replaced by a more specific one
%for now it is used for instance to turn fault monitors on and off
%
classdef STATE < Simulink.IntEnumType
  enumeration
    Init(0)
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