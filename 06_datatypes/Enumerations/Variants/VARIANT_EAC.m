classdef VARIANT_EAC < Simulink.IntEnumType
  enumeration
    FischerPS100(0)
    FischerWithTurbine(1)
    HydrowellWithTurbine(2)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 