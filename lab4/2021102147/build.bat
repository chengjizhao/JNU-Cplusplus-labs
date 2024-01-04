@echo off
g++ --version > nul

if %errorlevel% equ 0 (
	echo 正在编译
	g++ Sales.cpp main.cpp -o main.exe
) else (
	echo 找不到g++，请确认mingw已经安装并且环境变量已正确设置
	exit /b 1
)

echo 编译完成
pause
exit /b 0