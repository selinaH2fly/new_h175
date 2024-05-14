classdef VARIANT_TCP < Simulink.IntEnumType
  enumeration
    ValeoSPumpPS100(0)
    HVPump(1)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 