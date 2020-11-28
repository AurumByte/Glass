@ECHO OFF
title Build C++

if EXIST src (
    cd src
)

echo Compiling Glass.cpp
g++ Glass.cpp GetStr.cpp

cd ..

echo Locating Glass.exe
move src\a.exe bin\Glass.exe

cd bin

echo Opening Glass.exe
start Glass.exe

exit
