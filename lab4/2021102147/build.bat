@echo off
g++ --version > nul

if %errorlevel% equ 0 (
	echo ���ڱ���
	g++ Sales.cpp main.cpp -o main.exe
) else (
	echo �Ҳ���g++����ȷ��mingw�Ѿ���װ���һ�����������ȷ����
	exit /b 1
)

echo �������
pause
exit /b 0