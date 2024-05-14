classdef APD_REQUEST < Simulink.IntEnumType
  enumeration
    Idle(0)
    Wait(1)
    OnRequest(2)
    Actuate(3)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 