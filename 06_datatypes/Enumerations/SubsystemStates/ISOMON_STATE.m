classdef ISOMON_STATE < Simulink.IntEnumType
  enumeration
    Init(0)
    OFF(1)
    SELFTEST(2)
    STARTUP(3)
    OP(4)
    GOTOSTANDBY(5)
    STANDBY(6)
    FAULT(7)
    GOTOOFF(8)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 