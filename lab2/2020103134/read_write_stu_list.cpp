#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<map>

using namespace std;

//定义str_studengt结构体类型以存储学号、姓名、专业、实验分和总分； 
struct str_student
{
	string stu_id;
	string stu_name;
	string stu_major;
	int stu_exp_score[16];
	int stu_total_score;
 } ;
 
 vector<str_student> V_student;
//读文件函数
 void read_csv(const string& filename)
 {
     //创建输入流对象
 	ifstream fin;
	fin.open("stu_list.csv",ios::in);
	if(!fin.is_open())  //检查文件是否被打开 
	{
		cerr<<"无法打开文件"<<endl;
		return;
	}
	string line;
	while(getline(fin,line))
	{
		stringstream ss(line);//将line复制到ss中 
		string cell;
		vector<string> cells;
		while(getling(ss,cell,','))//逗号是分隔符 
		{
			cells.push_back(cell); 
		 } 

		 		str_student student;
		 		student.stu_id=cells[0];
		 		student.stu_name=cells[1];
		 		student.stu_major=cells[2];
		 		student.stu_total_score=0;
		 		for(int i=0;i<16;i++)
		 		{
		 			student.stu_exp_score[i]=stoi(cells[i+3]);//将 n 进制的字符串转化为十进制
		 			student.stu_total_score=student.stu_total_score+student.stu_exp_score[i];
				 }
				 V_Student.push_back(student);
	}
	fin.close(); 
 }
 
//程序写入文件函数
 void write_csv(const string& filename)
 {
 	//创建输出流对象 
 	ofstream fout(filename);
 	if(!fout.is_open())
 	{
 		cerr<<"无法打开文件"<<endl;
 		return;
	 }
	 for(const auto& student : students)
	 {
	 	fout<<student.stu_id<<","<<student.stu_name<<","<<student.stu_major<<",";
	 	for(int i=0;i<16;i++)
	 	{
	 		fout<<student.stu_exp_score[i]<<",";
		 }
		 fout<<student.stu_total_score<<endl;
	 }
	 fout.close();
 }
 
//查询成绩函数
 void query_score(const string& stu_id)
 {
 	for(const auto& student : V_student)
 	{
 		if(student.stu_id==stu_id)
 		{
 			cout<<"以下为学生信息"<<endl;
 			cout<<"学号: "<<student.stu_id<<endl;
 			cout<<"姓名: "<< student.stu_name<<endl;
 			cout<<"专业: "<< student.stu_major<<endl;
 			for(int i=0;i<16;i++)
 			{
 				 cout<<"第"<<i+1<<"次实验分：" ;
				 cout<<student.stu_exp_score[i]<<endl;
			 }
			 cout<<"总分："<< student.stu_total_score<<endl;
			 return; 
		 }
	 }
	 cout<<"学号错误"<<endl;
 } 

//录入成绩函数
void enter_score(const string& stu_id,int i,int stu_score)
{
	for(auto& student : V_student)
	{
		if(student.stu_id==stu_id)
		{
			student.stu_total_score=student.stu_total_score+stu_score;
			student.stu_exp_score[i-1]=stu_score;
			query_score(stu_id);
			cout<<"录入成功"<<endl<<endl;
			return;
		}
	 }
	 cout<<"学号错误"<<endl;
}
 
//主函数 
int main()
{
	
    string stu_id;
    string stu_name;
    string stu_major;
    int stu_score;
    string filename="stu_list.csv";
    read_csv(filename);
    cout<<"欢迎使用成绩系统"<<endl<<endl;
    int choice;
    do
    {
    	cout<<"查询成绩输入1，录入成绩输入2，退出输入0，请输入："<<endl;
    	cin>>choice;
    	if(chice==1)
    	{
    		cout<<"请输入学生学号："<<endl;
    		cin>>stu_id;
    		query_score(stu_id);
		}
		else if(chice==2)
		{
			cout<<"请输入学生学号："<<endl;
			cin>>stu_id;
			cout<<"请选择实验次序编号（1-16）："<<endl;
			int i;
			cin>>i;
			cin.get();
			while(i<1||i>16)
			{
				cout<<"编号错误,请重新输入"<<endl;
				cin>>i; 
				cin.get();
			}
			cout<<"请输入学生实验分（0-3）："<<endl;
			cin>>stu_score;
			cin.get();
			while(stu_score<0||stu_score>3)
			{
				cout<<"成绩超出范围，请重新输入："<<endl;
				cin>>stu_score;
			}
			enter_score(stu_id,i,stu_score);
		}
		else if(!choice==0)
		{
			cout<<"输入无效，请重新输入"<<endl;
		}
	}while(choice==0);
	write_csv(filename);
	enter 0;
}
