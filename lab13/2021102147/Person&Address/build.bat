@echo off

set all=

setlocal enabledelayedexpansion

g++ --version > nul

if %errorlevel% equ 0 (
	mkdir build
	for %%f in (*.cpp) do (
		echo Compiling %%f...
		g++ -c %%f -o build\%%~nf.o
		set all=!all! build\%%~nf.o 
	)
	echo Linking...
	g++ !all! -o build\main.exe
) else (
	echo g++ not found
	exit /b 1
)

if %errorlevel% equ 0 (
	copy info.txt build
	echo Compile success
	pause
	exit /b 0
) else (
	echo Compile failed
	pause
	exit /b 1
)

