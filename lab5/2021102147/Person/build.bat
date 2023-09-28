@echo off
g++ --version > nul

if %errorlevel% equ 0 (
	g++ Person.cpp main.cpp -o main.exe
) else (
	echo g++ not found
	exit /b 1
)

echo Compile success
pause
exit /b 0