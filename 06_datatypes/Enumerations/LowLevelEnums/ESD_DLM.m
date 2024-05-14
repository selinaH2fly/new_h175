classdef ESD_DLM < Simulink.IntEnumType
  enumeration
    OpenRelays(0)
    CommandCurrentToZero(1)
    RampCurrentToZero(2)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 