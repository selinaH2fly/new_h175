classdef VARIANT_auxTCP < Simulink.IntEnumType
  enumeration
    ValeoSPumpPS100(0)
    ControlledExtern(1)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 