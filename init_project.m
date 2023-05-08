%% clear worksapce

clc
clear

%% heading

fprintf("\n")
fprintf("####################################################################\n")
fprintf("#              h175_model_fcs project startup                      #\n")
fprintf("####################################################################\n")
fprintf("\n")
fprintf("This is executed by 'init_project.m' for starting up the MATLAB project \n")

%% useful git commands

fprintf("\n")
fprintf(2,"git status\n")
fprintf(2,"---------------------------------------------------------------------------------\n")
!git status

fprintf(2, "git log --oneline\n")
fprintf(2,"---------------------------------------------------------------------------------\n")
!git log -10 --pretty=format:"%h%x09%x09%an%x09%x09%ad%x09%s"

%% scripts for project initialization

fprintf("\n\n")
fprintf(2,"Running scripts for initialization\n")
fprintf(2,"------------------------------------------------\n")


fprintf("\n")
fprintf("Project succesfully initialized!")
fprintf("\n\n")

%% open the top-level Simscape/Simulink model

open('h175_model_fcs.slx')