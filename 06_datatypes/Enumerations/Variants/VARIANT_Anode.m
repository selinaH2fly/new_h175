classdef VARIANT_Anode < Simulink.IntEnumType
  enumeration
    Stage2(0)
    Stage3(1)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 