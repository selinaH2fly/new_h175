classdef RELAY_STATE < Simulink.IntEnumType
  enumeration
    Disconnected(0)
    Connected(1)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 