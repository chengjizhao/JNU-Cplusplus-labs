//老师，没有什么思路就借鉴了其他同学的作业，根据自己的理解改动了一些

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring> 
#include "stringapiset.h"
using namespace std;

struct stu
{
	int ID;			//学号
	string sName;		//姓名
	string sMajor;		//专业
	float aScore[10];		//10次作业的成绩
	int nFinalScore;	//期末成绩
};
stu aStudent[61];	
int nTarget;
int nID;

int file_Input(stu *pStudent);	
int id_Read(int id);
int final_Calculate(stu *pStudent);
string ANSItoUTF8(const char * ansi);

//主函数
int main()
{
	int Method;	   
	int grade[5];
	// 读文件
	file_Input(aStudent);                         
    cout << endl << "文件已成功读取";
	cout << endl << "请输入要操作的学生的学号" << endl;                
	cin >> nID;                              //输入学号  
	cout << "请等待" << endl;       
    //判断学号是否在库中
	if(id_Read(nID))              
	{
        cout << endl << "请选择要执行的操作，并输入操作对应的数字:" << endl;
		cout << endl << "1.成绩查询" << endl;
		cout << endl << "2.成绩增改" << endl;
		cin >> Method;           
		cout << endl;          
        final_Calculate(aStudent);          //计算平均成绩
        switch(Method)                       //对数据进行操作
	    {                        
		    case 1:                                
			cout <<"学号为 "<<nID <<" 的同学的成绩:" << endl;
			cout << endl;
			for(int i=0; i<=9; i++)
			{
			   cout <<"第"<<i<<"次成绩为"<< aStudent[nTarget].aScore[i] << endl;
			}	
			cout << endl;
			cout << "期末最终成绩是：" << endl;
			cout  << aStudent[nTarget].nFinalScore << endl;
			break;
		    
		    case 2:                                
			cout << "请输入"<<"学号为 "<<nID<<" 的同学需要修改的成绩为10次作业中的哪一次:" << endl;
			cin >> grade[0];
			cout << endl << "需要将该次作业的成绩修改为:" << endl;
			cin >> grade[1];
			aStudent[nTarget].aScore[grade[0]-1] = grade[1];
			cout << endl << "成绩修改成功！" << endl;
			break;
	    }
		cout << endl;
		cout << "程序运行结束" << endl;
	}
    else
   {
	  cout << endl << "文件中不存在该学号，请输入正确学号" << endl;
   }
	return 0;
}

//函数file_input()
int file_Input(stu *pStudent)                 
{
	int nStu = 0;		//学生编号
	int nMem = 0;		//结构体内成员编号      //定义的一个学生的结构体数组中各变量的编号，学号编号是0，姓名编号是1，专业编号是2，第一次成绩编号为3... ...
	// 读文件
	ifstream inFile("test.csv", ios::in);     
	string lineStr;                          
	// 读取行
	while (getline(inFile, lineStr))        // 循环条件是 getline(inFile, lineStr)为真，即其结果为1,即文件中该行始终储存有信息
	{
		stringstream ss(lineStr);               
		string str;                                
		memset(pStudent[nStu].aScore, 0, sizeof(pStudent[nStu].aScore));	//初始化成绩    
		
		// 读取并存储一行中逗号间字符串
		while (getline(ss, str, ','))     
		   { 
				switch(nMem)         
				{                                                                             
					case 0: pStudent[nStu].ID    		= atol(str.c_str());                    
							nMem++;	  break;
					case 1: pStudent[nStu].sName  		= str;
							nMem++;   break;
					case 2: pStudent[nStu].sMajor 		= str;
							nMem++;   break;
					case 3: pStudent[nStu].aScore[0]	= atol(str.c_str());
							nMem++;   break;
					case 4: pStudent[nStu].aScore[1]	= atol(str.c_str());
							nMem++;   break;
					case 5: pStudent[nStu].aScore[2]	= atol(str.c_str());
							nMem++;   break;
					case 6: pStudent[nStu].aScore[3]	= atol(str.c_str());
							nMem++;   break;
					case 7: pStudent[nStu].aScore[4]	= atol(str.c_str());
							nMem++;   break;
					case 8: pStudent[nStu].aScore[5]	= atol(str.c_str());
							nMem++;   break;
					case 9: pStudent[nStu].aScore[6]	= atol(str.c_str());
							nMem++;   break;
					case 10:pStudent[nStu].aScore[7]	= atol(str.c_str());
							nMem++;   break;
					case 11:pStudent[nStu].aScore[8]	= atol(str.c_str());
							nMem++;   break;
					case 12:pStudent[nStu].aScore[9]	= atol(str.c_str());
							nMem++;   break;
				}
		    }
		nMem = 0;      //结构体内成员变量编号初始化，开始下一位同学的信息读取
		nStu ++;       
	}
	return 0;           
}

//函数 id_Read 
int id_Read(int id)
{
	string temp;
	for(int i=0; i<=60; i++)
	{
		if(aStudent[i].ID == id)       //判断每一个学生的结构组变量中的ID与定义的变量id是否相等，如果相等，执行以下语句，否则进入循环结构中的而下一步
		{
			nTarget = i;               //对变量nTarget进行赋值
            cout << endl << "该学号存在于文件中，其对应信息为：" << endl;
	        temp = ANSItoUTF8(aStudent[id].sName.c_str());           //输出该学号同学的姓名
	        cout << temp << " ";
	        temp = ANSItoUTF8(aStudent[id].sMajor.c_str());          //输出该学号同学的专业
	        cout << temp << " " << endl;
			return 1;                //函数调用时的循环条件为真（1）
		}
	}  
	return 0;             //输入的学号不存在于文件中，返回值为0，不执行主函数中的if结构的循环体
}

//函数 final_Calculate
int final_Calculate(stu *pStudent)
{
	int nNonZero;
	float nSum = 0;
	for(int i=0; i<=60; i++)
	{
		for(int j=0; j<=9; j++)
		{
            nSum += pStudent[i].aScore[j];
			nNonZero++;					
		}
		pStudent[i].nFinalScore = nSum / nNonZero;
		nNonZero = 0;
		nSum = 0;
	}
	return 0;
}

//函数 ANSItoUTF8
string ANSItoUTF8(const char * ansi)
{
	int len = MultiByteToWideChar(CP_ACP, 0, ansi, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_ACP, 0, ansi, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len+1];
	memset(str, 0, len+1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if(wstr) delete[] wstr;
	std::string ret = str;
	if(str) delete[] str;
	return ret;
}


