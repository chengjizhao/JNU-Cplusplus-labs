#include "Student_Manage.h"
#include "stringapiset.h"
 
using namespace std;

/*--------------------以下为变量定义--------------------*/ 

stu aStudent[61];	//建立结构体数组存储信息
int nTarget;		//选中的学生在结构体数组中的位置
int temp[5];		//各种数据都能用的暂存

/*--------------------以下为主函数--------------------*/
int main()
{

	string nID;
	int nMethod;	//对学生数据进行的操作
	
	// 读文件
	file_Input(aStudent);
	cout << endl << "！！！！！！文件载入已完成！！！！！！";
	cout << endl << "！！！所有学生期末成绩将自动计算！！！" << endl;
	while (1)
	{
		text_Show(0);
		//输入学号
		cin >> nID;
		text_Show(3);

		//判断学号是否在库中
		if(id_Read(stol(nID)))
		{
			cin >> nMethod;
			text_Show(3);
			stu_Operate(nMethod);
			
			// 写文件
			file_Output(aStudent);
			text_Show(4);
		}
	}
	return 0;
}


/*--------------------以下为各函数定义--------------------*/

/***************************************************
*函数名称：file_Input
*输入变量：stu *pStudent
*返回数值：0
*功能简介：将csv文件数据载入结构体数组
***************************************************/
int file_Input(stu *pStudent)
{
	int nStu = 0;		//学生编号
	int nMem = 0;		//结构体内成员编号
	// 读文件
	ifstream inFile("test.csv", ios::in);
	string lineStr;
	// 读取行
	while (getline(inFile, lineStr))
	{
		stringstream ss(lineStr);
		string str;
		memset(pStudent[nStu].aScore, 0, sizeof(pStudent[nStu].aScore));	//初始化成绩
		// 读取并存储一行中逗号间字符串
		while (getline(ss, str, ','))
		{
			//int nScr = 0;	//成绩编号
				switch(nMem)//这部分一用for循环就会读取失败，所以只能一个个都写出来
				{
					case 0: pStudent[nStu].nID    		= atol(str.c_str());
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
					case 13:pStudent[nStu].nFinalScore	= atol(str.c_str());
							nMem++;   break;
				}
			//nScr = 0;
		}
		nMem = 0;
		nStu ++;
	}
	return 0;
}


/***************************************************
*函数名称：file_Output
*输入变量：stu *pStudent
*返回数值：0
*功能简介：将结构体数组中的数据输出至目标csv文件
***************************************************/
int file_Output(stu *pStudent)
{
	//计算期末成绩
	final_Calculate(pStudent);

	ofstream outFile;
	outFile.open("test.csv", ios::out); 	// 打开模式可省略
	for(int i=0; i<=60; i++)
	{
		outFile << pStudent[i].nID << ',' << pStudent[i].sName << ',' << pStudent[i].sMajor << ','
				<< pStudent[i].aScore[0] << ',' << pStudent[i].aScore[1] << ',' << pStudent[i].aScore[2] << ','
				<< pStudent[i].aScore[3] << ',' << pStudent[i].aScore[4] << ',' << pStudent[i].aScore[5] << ','
				<< pStudent[i].aScore[6] << ',' << pStudent[i].aScore[7] << ',' << pStudent[i].aScore[8] << ','
				<< pStudent[i].aScore[9] << ',' << pStudent[i].nFinalScore << endl;
	}
	outFile.close();
	return 0;
}


/***************************************************
*函数名称：id_Read
*输入变量：int id
*返回数值：1:检索到对应学号		0:未检索到对应学号
*功能简介：显示提示文字
***************************************************/
int id_Read(int id)
{
	for(int i=0; i<=60; i++)
	{
		if(aStudent[i].nID == id)
		{
			nTarget = i;

			cout << endl << "选中该学生:" << endl;
			message_Show(nTarget);
			text_Show(1);
			return 1;
		}
	}
	text_Show(2);
	return 0;
}


/***************************************************
*函数名称：stu_Operate
*输入变量：int n
*返回数值：
*功能简介：对学生数据执行操作
***************************************************/
void stu_Operate(int n)
{
	switch(n)
	{
		case 0: break;
		//成绩查询
		case 1: 
			cout << "课时成绩:" << endl;
			cout << "    ";
			for(int i=0; i<=9; i++)
			{
				cout << aStudent[nTarget].aScore[i] << " ";
			}	
			cout << endl << endl;
			cout << "期末成绩:" << endl;
			cout << "    " << aStudent[nTarget].nFinalScore << endl;break;
		//成绩增改
		case 2:
			cout << "请输入成绩:" << endl;
			cin >> temp[0];
			cout << endl << "请输入该成绩要存入的课次(1~10):" << endl;
			cin >> temp[1];
			aStudent[nTarget].aScore[temp[1]-1] = temp[0];
			cout << endl << "成绩写入成功！" << endl;
	}
}


/***************************************************
*函数名称：final_Calculate
*输入变量：stu *pStudent
*返回数值：
*功能简介：计算期末成绩(从后往前第一个非零成绩/分数个数)
***************************************************/
int final_Calculate(stu *pStudent)
{
	int nNonZero;
	int nSum = 0;

	for(int i=0; i<=60; i++)
	{
		for(int j=0; j<=9; j++)
		{
			if(pStudent[i].aScore[9-j] != 0)
			{
				for(int k=0; k<=9-j; k++)
				{
					nSum += pStudent[i].aScore[k];
					nNonZero++;
				}					
				break;
			}
		}

		if(nSum != 0)
		{
			pStudent[i].nFinalScore = nSum / nNonZero;
		}
		
		nNonZero = 0;
		nSum = 0;
	}

	return 0;
}

/***************************************************
*函数名称：message_Show
*输入变量：int id
*返回数值：
*功能简介：显示学生信息(学号，姓名，专业)
***************************************************/
void message_Show(int id)
{	
	string temp;

	cout << "    " << aStudent[id].nID << " ";
	temp = ANSItoUTF8(aStudent[id].sName.c_str());
	cout << temp << " ";
	temp = ANSItoUTF8(aStudent[id].sMajor.c_str());
	cout << temp << " " << endl;
}
	

/***************************************************
*函数名称：text_Show
*输入变量：int n
*返回数值：
*功能简介：显示提示文字
***************************************************/
void text_Show(int n)
{
	switch(n)
	{
		case 0:	cout << endl << "--------请输入要操作的学号(int格式)--------" << endl;break;
		case 1: cout << endl << "已检索到输入学号，请选择要执行的操作:" << endl;
				cout << endl << "1.成绩查询" << endl;
				cout << endl << "2.成绩增改" << endl;
				cout << "-------------------------------------------" << endl;break;
		case 2: cout << endl << "未检索到对应学号！请重新输入。" << endl;break;
		case 3: cout << "-------------------------------------------" << endl;break;
		case 4: cout << "-------------------------------------------" << endl;
				cout << "！！！！！！！期末成绩计算完成！！！！！！！" << endl;break;
	}
}


/***************************************************
*函数名称：ANSItoUTF8
*输入变量：const char * ansi
*返回数值：
*功能简介：将ANSI编码的字符串转换为UTF-8编码格式
***************************************************/
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
