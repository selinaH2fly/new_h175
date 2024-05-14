classdef PIN_CHECK < Simulink.IntEnumType
  enumeration
    Idle(0)
    Success(1)
    Failed(2)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 