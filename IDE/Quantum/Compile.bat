@ECHO OFF

title Compile Quantum
echo Compiling Quantum.

pyinstaller.exe --icon=Logo.ico --noconsole --onefile Quantum.py
cls

echo Done.
move dist\Quantum.exe Quantum.exe

del dist
del build
del __pycache__
del Quantum.spec

rmdir dist
rmdir build
rmdir __pycache__

echo|set /p="Continue."
pause >nul
exit
