#include<iostream>
#include <fstream>
#include <istream>
#include <streambuf>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;
//构造结构体，包括学生学号、姓名、专业、成绩
struct stu
{
	vector<string> sno;
	vector<string> name;
	vector<string> major;
	vector<string> grade;
}stu1;
//录入成绩
void entry()
{
 	string file= "test.csv";
 	ifstream data(file, ios::in);
 	if(!data.is_open())
 	{
 	cout << "错误，打开文件失败"<< endl;
 	exit(1);
 	}
//输入查询	
 	char no[20];
 	char sScore[10];
 	cout << "请输入需要录入成绩的学生学号:\n";
 	cin >> no;
 	cout << "请输入分数：";
	cin >> sScore;

//存储临时数据
 	string line;
 	istringstream sin;
 	string word;
 	vector<string> words;
 	vector<vector<string> > datas; 
 	for(int i=0;i<100;i++)
	{
		getline(data,line);
		sin.clear();
		sin.str(line);
		words.clear();
		int j = 0;
		while (getline(sin, word, ','))
		{
			j += 1;
			words.push_back(word);
		}
	

		if (j == 10) words.push_back("--");
		if (words[0] == no){
			words.push_back(sScore);
		
		}
		
		
		datas.push_back(words);
	}
		data.close();
//将临时数据存入csv文件中	
		ofstream outFile;
		outFile.open(file, ios::out | ios::trunc);
		for (int i = 0; i < datas.size(); i ++)
		{
		for (int j = 0; j < datas[i].size(); j ++)
		{
			outFile << datas[i][j] << ',';
		}
		outFile << endl;
		}
		outFile.close();
		cout << "成绩录入成功\n" << endl;
}


//计算总成绩
void query()
{

	string file= "test.csv";
    ifstream data(file, ios::in);
    if(!data.is_open())
    {
        cout << "错误，打开文件失败"<< endl;
        exit(1);
    }

 
    string line;
    istringstream sin;
    string word;
    vector<string> words;
    vector<vector<string> > datas; 
//将csv文件数据存入结构体中
	for(int i=0;i<100;i++)
	{
	getline(data,line);
		sin.clear();
		sin.str(line);
		words.clear();
		
		while (getline(sin, word, ','))words.push_back(word);
		
		stu1.sno.push_back(words[0]);
		stu1.name.push_back(words[1]);
		
        for(int j=11;j<words.size()&&words[j].length()!=0;j++)
        {
            stu1.grade.push_back(words[j]);

        }

		datas.push_back(words);
	}
		data.close();

//查找学生信息并计算总成绩
	string no;
	cout<<"请输入学生学号:\n";
	cin>>no;
	string grades;
	int l;
	int score=0;
	int scores=0;
	l=stu1.sno.size();
	for(int i=0;i<l;i++)
	{
	if(stu1.sno[i]==no)
	{

	if(stu1.grade.size()<1)cout<<"该学生无成绩录入。\n";
	else
	{
	cout<<"学号:"<<stu1.sno[i]<<endl;
	cout<<"姓名:"<<stu1.name[i]<<endl;
	cout<<"成绩:";
 	
	for(int k=0;k<stu1.grade.size();k++)
	{
	cout<<stu1.grade[k]<<" ";
	stringstream geek(stu1.grade[k]);geek>>score;
	scores=scores+score;
	}
	cout<<endl;
	}
	}
	}
	cout<<"总成绩:"<<scores<<endl;
	stu1.grade.clear();
}



//功能选择
int main()
{
	while(true) 
	{
	int opt;
	cout<<"请选择以下功能:\n";
	cout<<"1.查询成绩并计算总成绩\n";
	cout<<"2.录入成绩\n";
	cout<<"0.结束程序\n";
	cin>>opt;
	
	
	switch(opt)
	{
	
	case 1: query(); break;
	case 2: entry(); break;
	
	}
	if(opt!=0){
 	int exit;
        cout << "是否继续操作？" << endl;
        cout << "1、继续" << endl;
        cout << "2、停止" << endl;
        cin >> exit;
        if(exit == 2) { return 0; }
	}
	else
	return 0;
    
	}
return 0;
}