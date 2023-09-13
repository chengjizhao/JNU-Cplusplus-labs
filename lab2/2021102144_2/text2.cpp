#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
//解决中文显示乱码问题：将.csv文件用文本打开，另存为适配的编码方式
using namespace std;
int I_id1,I_id2,I_id3;
int I_score1,I_score2,I_score3,I_score4;
int Num1,Num2,Num3;
int Sum=0;
int Ava;
struct Student
    {
        int Id;
        string Name;
        string Professiong;
        int Score[10]={0};    
    };
int main() 
 {
 //文件导入   
    ifstream infile("ndoc.csv", ios::in);//文件路径有四种格式，这里用的同目录下相对路径；绝对路径要改“//”
	string line;
	vector<struct Student> studentVector;
	getline(infile, line);//从infile即.csv文件中读一行并存入到line里面
	while (getline(infile, line)) //每行循环
    {
		stringstream ss(line);//初始化流，将行中内容变成信息流
		string str;
		Student studet;
		getline(ss, str, ' ');//根据分隔符，将流ss的内容存进str中
		studet.Id=stod(str);//将str中的内容强制转换格式存入结构体中
        getline(ss, str, ' ');
		studet.Name=str;
        getline(ss, str, ' ');
		studet.Professiong=str;
		/*getline(ss, str, ',');
		studet.Class = stold(str);
		getline(ss, str, ',');
		studet. Aca= stold(str);*/

		studentVector.push_back(studet);
	}
//输出结构体
    for(int i=0; i <studentVector.size();i++) 
        {
        cout<<studentVector[i].Id<<" "<<studentVector[i].Name<<" "<<studentVector[i].Professiong<<" ";
         for(int j=0;j<10;j++)
        {
        cout<<studentVector[i].Score[j]<<",";
        }
        cout << endl;
        }  

//按学号录入第n次成绩
   cout<<"请输入要录入成绩的学号:"<<endl;
   cin>>I_id1;
   cout<<"请输入要录入第几次成绩"<<endl;
   cin>>Num1;
for(int i=0;i<studentVector.size();i++)
    {
       if(I_id1==studentVector[i].Id)
       {
       cout<<"请输入第"<<Num1<<"次录入成绩分数:"<<endl;
       cin>> I_score1;
       studentVector[i].Score[Num1-1]=I_score1;
       //cout<< studentVector[i].Score1;
       cout<<"成功录入!"<<endl;
       break;
       }
       if(i==studentVector.size()-1)
       cout<<"抱歉，未能找到您需要录入成绩的学号"<<endl;
    }
    
    
//按学号查询成绩
    cout<<"请输入要查询成绩的学号:"<<endl;
    cin>>I_id2;
    cout<<"请输入要查询第几次"<<endl;
    cin>>Num2;
    for(int i=0;i<studentVector.size();i++)
    {
       if(I_id2==studentVector[i].Id)
       {
       cout<<studentVector[i].Name<<":"<<studentVector[i].Score[Num2-1]<<endl;
       break;
       } 
       if(i==studentVector.size()-1)
       cout<<"抱歉，未能找到您需要查询的学号"<<endl;
    }
//计算期末总成绩
    cout<<"请输入要查询期末总成绩的学号:"<<endl;
    cin>>I_id3;
    for(int i=0;i<studentVector.size();i++)
    {
       if(I_id3==studentVector[i].Id)
       {
       for(int a:studentVector[i].Score)
       {
         Sum+=a;
       }
       Ava=Sum/10;
       cout<<studentVector[i].Name<<"期末总成绩为:"<<Ava<<endl;
       break;
       } 
       if(i==studentVector.size()-1)
       cout<<"抱歉，未能找到您需要查询的学号"<<endl;
    }
//将用户写入的数据存入到文件中
    string file_name = "ndoc.csv";
    std::ofstream os("ndoc.csv");
    //ofstream os;     //创建一个文件输出流对象
    //os.open("ndoc.csv");//将对象与文件关联
    //string str_score;
    for(int i=0;i<studentVector.size();i++)
    {
    os<<studentVector[i].Id<<" "<<studentVector[i].Name<<
    " "<<studentVector[i].Professiong<<" ";
    for(int j=0;j<10;j++)
    {
        os<<studentVector[i].Score[j]<<",";
    }  //将输入的内容放入txt文件中
    os<<endl;
    }
    os.close();
    return 0;
}
