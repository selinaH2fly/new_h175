classdef VARIANT_TCV < Simulink.IntEnumType
  enumeration
    BelimoPS100(0)
    BontazCAN(1)
    Bontaz2_CAN(2)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 