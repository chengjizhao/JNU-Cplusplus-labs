/*
此版本为读取原文件代码，会对原文件产生修改，后续继续优化会补上 
*/ 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <algorithm>
#include <cstring>

using namespace std;
string id1,id2,id3;
int kemu1,kemu2;
int chengji1;
float Sum=0;

//学生结构体 
struct Student//学号，姓名，专业，分数（后续读入）； 
{
	string id;
	string name;
	string major;
	float scores[10]={0};
	float sum=0;	
};


 
int main() 
{
   vector<struct Student> Vstu;
   ifstream ifs("stu_score.csv",ios::in);
   string line;
   //打开文件 
  /* if(ifs.is_open())
   {
   	char buf[100000]={0};
   	while(ifs>>buf)
   	{
   		cout<<buf<<endl;
	   }
   }
   else
   {
   	cout<<"Failed"<<endl;
   }*/ //!!!!worng
   //读入文件到vector型容器里（Vstu） 
   getline(ifs,line);//先读第一行文字,后面line刷新覆盖后就不存在了,这是用于读取老师给的原文件的代码
   while(getline(ifs,line))
   {
   	stringstream ss(line);//初始化信息流 
   	string str;
   	Student studet;
   	
   	 getline(ss,str,',');
   	 studet.id=str; 
	  getline(ss,str,',');
	  studet.name=str;
	   getline(ss,str,','); getline(ss,str,',');//用来消去读取的老师给的原文件的无用信息 
	    getline(ss,str,',');
	    studet.major=str;//为什么这里用命名为stu,student都行不通。
	Vstu.push_back(studet);
	} 
	 
	cout<<"第一位学生学号为"<<Vstu[0].id<<"（此行作为验证程序无误）"<<endl;//随便输出一个验证Vstu有没有东西 发现不输出 
	//输入成绩
	cout<<"请输入学生学号"<<endl;
   cin>>id1;
   cout<<"请输入科目"<<endl;
   cin>>kemu1;
   for(int i=0; i <Vstu.size();i++)  
   {
   	if(id1==Vstu[i].id)
   	{
   		cout<<"请输入该学生第"<<kemu1<<"科成绩："<<endl;
		   cin>>chengji1;
		   Vstu[i].scores[kemu1-1]=chengji1;
		   cout<<"已录入"<<endl;
		   break;
	   }
	    if(i==Vstu.size()-1)
	   {
	   	cout<<"找不到该学生"<<endl;
	   }
	} 
	
	//查询成绩
	cout<<"输入你要查询的学生学号"<<endl;
	cin>>id2;
	cout<<"输入要查询的科目"<<endl;
	cin>>kemu2;
	for(int i=0;i<Vstu.size();i++)  
	{
		if(id2==Vstu[i].id)
		{
			cout<<Vstu[i].scores[kemu2-1]<<endl;
			break;
		}
		if(i==Vstu.size()-1)
	   {
	   	cout<<"找不到该学生";
	   }
	}
	//计算总成绩
	cout<<"是否要计算最新期末总成绩"<<endl;
	string yes;
	cin>>yes;
	if(yes=="yes")
	{
	for(int i=0;i<Vstu.size();i++)
	{	
	    Sum=0;
			for(int j=0;j<10;j++)
			{
				Sum+=Vstu[i].scores[j];//将每科成绩加起来 
				
			}
			Vstu[i].sum=Sum;
	}
    }
    else {
    	cout<<"终止"<<endl;
	}
    //查询期末总成绩
	 cout<<"输入你要查询期末总成绩的学生学号"<<endl;
	cin>>id3;
	for(int i=0;i<Vstu.size();i++)  
	{
		if(id3==Vstu[i].id)
		{
			cout<<Vstu[i].sum<<endl;
			break;
		}
		if(i==Vstu.size()-1)
	   {
	   	cout<<"找不到该学生";
	   }
	}
    ifs.close();//文件读取已完毕，数据已放入Vstu中，关闭文件； 
    
	//存入文件 
	ofstream o_file("stu_score.csv");//创建文件流o_file，与文件关联； 
	for(int i=0;i<Vstu.size();i++)
	{
		o_file<<Vstu[i].id<<","<<Vstu[i].name<<","<<Vstu[i].major<<" ";
		for(int j=0;j<10;j++)
		{
			o_file<<Vstu[i].scores[j]<<",";
		}
		o_file<<"期末总成绩为"<<Vstu[i].sum<<endl;
	}
	o_file.close();
   return 0;
   
}
