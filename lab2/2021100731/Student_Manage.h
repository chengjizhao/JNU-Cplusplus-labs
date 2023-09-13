#ifndef __STUDENT_MANAGE__
#define __STUDENT_MANAGE__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring> 

using namespace std;

//定义数据结构体格式
struct stu
{
	int nID;			//学号
	string sName;		//姓名
	string sMajor;		//专业
	int aScore[10];		//10次作业的成绩
	int nFinalScore;	//期末成绩
};

int file_Input(stu *pStudent);
int file_Output(stu *pStudent);
int id_Read(int id);
void stu_Operate(int n);
int final_Calculate(stu *pStudent);
void message_Show(int id);
void text_Show(int n);
string ANSItoUTF8(const char * ansi);

#endif
