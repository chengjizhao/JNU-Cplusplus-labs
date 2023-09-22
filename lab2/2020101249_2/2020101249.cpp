#include <iostream>
#include <istream>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

void enter()
{
	char sNum[20];            
	char sScore[10];          
	cout << "请输入学号：";   
	cin >> sNum;              
	cout << "请输入分数：";
	cin >> sScore;            
    //定义了两个字符数组sNum和sScore用于储存学号和分数，并通过cin获取输入的学号和分数
	
	ifstream csv_data("文件.csv", ios::in);
	string line;
	
	if (!csv_data.is_open())
	{
		cout << "Error: opening file fail" << endl;
		exit(1);
	}
	//打开名为“test.csv"的CSV文件，并检查是否成功打卡，若失败则报错并退出程序

	istringstream sin;
	vector<vector<string> > datas;
	string word;
	vector<string> words;
	
	while (getline(csv_data, line))
	{
		sin.clear();
		sin.str(line);
		words.clear();
		int flag = 0;
		while (getline(sin, word, ','))
		{
			flag += 1;
			words.push_back(word);
		}
		if (flag == 10) words.push_back("--");
		if (words[0] == sNum) words.push_back(sScore);
		datas.push_back(words);
	}
	csv_data.close();                                    //关闭CSV文件
	
	ofstream outFile;
	outFile.open("文件.csv", ios::out | ios::trunc);     //打开“test.csv"文件
	for (int i = 0; i < datas.size(); i ++)
	{
		for (int j = 0; j < datas[i].size(); j ++)
		{
			outFile << datas[i][j] << ',';
		}
		outFile << endl;
	}                                                    //遍历datas变量
	outFile.close();
	
	cout << "已录入成功\n" << endl;                       //输出录入成功的提示信息
}

void search()
{
	char sNum[20];
	cout << "请输入学号：";
	cin >> sNum;
	
	ifstream csv_data("文件.csv", ios::in);
	string line;
	
	if (!csv_data.is_open())
	{
		cout << "Error: opening file fail" << endl;
		exit(1);
	}
	
	istringstream sin;
	vector<string> words;
	string word;
	
	while (getline(csv_data, line))
	{
		sin.clear();
		sin.str(line);
		words.clear();
		while (getline(sin, word, ',')) words.push_back(word);

		if (words[0] == sNum)
		{
			cout << "\n学号：" << words[0]
				 << "\n姓名：" << words[1]
				 << "\n专业：" << words[4]
				 << "\n成绩：";
			for (int k = 11; k < words.size(); k ++) cout << words[k] << " ";
			cout << endl;
		}
	}
	csv_data.close();	
}

int main()
{
	struct student
	{
		char num[20];
		char name[10];
		char spec[20];
		int score;
	}s1;
	int q = 1;
	char choice;
	while (q)
	{
		cout << "-------------------------\n";
		cout << "请选择查询成绩或录入成绩（1：查询；2：录入；q：退出）：";
		cin >> choice;
		switch (choice)
		{
			case '1': search(); break;
			case '2': enter(); break;
			case 'q': q = 0; break;
		}
	}
	return 0;
}