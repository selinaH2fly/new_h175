classdef TH_SP_MODE < Simulink.IntEnumType
  enumeration
    DISABLED(0)  
    LINEAR(1)
    PHASES3(2)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 