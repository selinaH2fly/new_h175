classdef AIRCL_STATE < Simulink.IntEnumType
  enumeration
    Off(0)
    On(1)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 