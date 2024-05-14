classdef FaultID < Simulink.IntEnumType
  enumeration
    Reserved0(0)
    Reserved1(1)
    Reserved2(2)
    Reserved3(3)
    Reserved4(4)
    Startup_HV_ConnectionFault(5)
    Startup_LT_TurnOnTimeout(6)
    Startup_HT_TurnOnTimeout(7)
    Startup_CAT_SepValveFault(8)
    Startup_Load_NegConnectionFault(9)
    Startup_S
    Startup
    Fault(3)
    NotUsed(4)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 