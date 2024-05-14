classdef OPERATION_STATE < Simulink.IntEnumType
  enumeration
    Steady(0)
    DynamicUp(1)
    DynamicDown(2)
    Derating(3)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 