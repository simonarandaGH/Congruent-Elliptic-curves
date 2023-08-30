REM  Windows bat to compile.
echo on
prompt $g
REM
cls
g++ -Wall -march=native -Ofast -o %1.exe %1.cpp
REM


