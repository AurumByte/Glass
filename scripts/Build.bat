@ECHO OFF
title Build C++

if EXIST scripts (
    cd scripts
)

echo Compiling Glass.cpp
call Link.py

cd ..

echo Locating Glass.exe
move src\a.exe bin\Glass.exe

cd bin

echo Opening Glass.exe
start Glass.exe

exit
