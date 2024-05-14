classdef VARIANT_TCVDirection < Simulink.IntEnumType
  enumeration
    OPEN_IS_COOLING(0)
    OPEN_IS_HEATING(1)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 