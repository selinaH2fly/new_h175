from architectures import bop10, bop21, bop22, bop23, bop24, bop25, bop26, bop27, bop31, bop32, bop33, bop41, bop42

arch_list = ["bop21"]      # which architecture should be eveluated?, also possible to evaluate multiple architectures
input_dict = {}             # input_dict is not needed

input_dict = {}

# input
critical_operation = True
freezing_condition = True
if critical_operation is True:
    bc_dict = {"T_in" : 273.15 + 60.0,
                #"Vdot_in" : 0.5,
                "p_in" : 1.5,
                "p_end" : 1,
                "Qdot_hpdu" : 1000,
                "Qdot_lvdcdc" : 300,
                "Qdot_hvdcdc" : 1600,
                "Qdot_inverter" : 1250,
                "Qdot_intercooler" : 21000,
                "Qdot_compressor" : 1000,
                "Qdot_evap" : -13500}
##elif freezing_condition is True:
  #  bc_dict = {"T_in" : 273.15 + 10.0,
   #             "Vdot_in" : 0.5,
    #            "p_end" : 1,
     #           "Qdot_hpdu" : 0,
      #          "Qdot_lvdcdc" : 0,
       #         "Qdot_hvdcdc" : 0,
        #        "Qdot_inverter" : 0,
         #       "Qdot_intercooler" : 0,
          #      "Qdot_compressor" : 0,
           #     "Qdot_evap" : -13500}
else: 
    bc_dict = {"T_in" : 273.15 + 50.0,
               "Vdot_in" : 0.5,
                "p_end" : 1,
                "Qdot_hpdu" : 500,
                "Qdot_lvdcdc" : 150,
                "Qdot_hvdcdc" : 800,
                "Qdot_inverter" : 625,
                "Qdot_intercooler" : 21000,
                "Qdot_compressor" : 500,
                "Qdot_evap" : -13500}
    
result_dict = {"Vdot_in" :              ['', [], ''], 
                "Vdot_1" :              ['', [], ''], 
                "Vdot_2" :              ['', [],''],
                "Vdot_3" :              ['', [],''],
                "Vdot_4" :              ['', [],''],
                "t_in_lvdcdc":          ["", [],'LV DCDC T_in'],
                "t_in_hvdcdc" :         ["", [], 'HV DCDC T_in'],
                "t_in_inverter" :       ["", [], 'Inverter T_in'],
                "t_in_hpdu" :           ["", [], 'HPDU T_in'],
                "t_in_compressor" :     ["", [], 'Compressor T_in'],
                "t_in_intercooler" :    ["", [], "Intercooler T_in"],
                "t_out_intercooler" :   ["", [], "Intercooler T_out"],
                "t_out_Bop" :           ["", [],'BoP T_out'],
                "p_in" :               ["", [], 'bop pressure drop in [bar]']}


#calculation
for y in arch_list:
    key_init = "%s.initialize(%s, %s, %s)" %(y, input_dict, result_dict, bc_dict)
    circ, input_variable, result_dict = eval(key_init)
    circ.evaluate_big_arch(result_dict)



