classdef VARIANT_ETCP < Simulink.IntEnumType
  enumeration
    EMPPS100(0)
    ControlledExtern(1)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 