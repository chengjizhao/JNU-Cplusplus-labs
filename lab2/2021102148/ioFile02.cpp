/*
�˰汾Ϊ��ȡԭ�ļ����룬���ԭ�ļ������޸ģ����������Ż��Ჹ�� 
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

//ѧ���ṹ�� 
struct Student//ѧ�ţ�������רҵ���������������룩�� 
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
   //���ļ� 
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
   //�����ļ���vector�������Vstu�� 
   getline(ifs,line);//�ȶ���һ������,����lineˢ�¸��Ǻ�Ͳ�������,�������ڶ�ȡ��ʦ����ԭ�ļ��Ĵ���
   while(getline(ifs,line))
   {
   	stringstream ss(line);//��ʼ����Ϣ�� 
   	string str;
   	Student studet;
   	
   	 getline(ss,str,',');
   	 studet.id=str; 
	  getline(ss,str,',');
	  studet.name=str;
	   getline(ss,str,','); getline(ss,str,',');//������ȥ��ȡ����ʦ����ԭ�ļ���������Ϣ 
	    getline(ss,str,',');
	    studet.major=str;//Ϊʲô����������Ϊstu,student���в�ͨ��
	Vstu.push_back(studet);
	} 
	 
	cout<<"��һλѧ��ѧ��Ϊ"<<Vstu[0].id<<"��������Ϊ��֤��������"<<endl;//������һ����֤Vstu��û�ж��� ���ֲ���� 
	//����ɼ�
	cout<<"������ѧ��ѧ��"<<endl;
   cin>>id1;
   cout<<"�������Ŀ"<<endl;
   cin>>kemu1;
   for(int i=0; i <Vstu.size();i++)  
   {
   	if(id1==Vstu[i].id)
   	{
   		cout<<"�������ѧ����"<<kemu1<<"�Ƴɼ���"<<endl;
		   cin>>chengji1;
		   Vstu[i].scores[kemu1-1]=chengji1;
		   cout<<"��¼��"<<endl;
		   break;
	   }
	    if(i==Vstu.size()-1)
	   {
	   	cout<<"�Ҳ�����ѧ��"<<endl;
	   }
	} 
	
	//��ѯ�ɼ�
	cout<<"������Ҫ��ѯ��ѧ��ѧ��"<<endl;
	cin>>id2;
	cout<<"����Ҫ��ѯ�Ŀ�Ŀ"<<endl;
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
	   	cout<<"�Ҳ�����ѧ��";
	   }
	}
	//�����ܳɼ�
	cout<<"�Ƿ�Ҫ����������ĩ�ܳɼ�"<<endl;
	string yes;
	cin>>yes;
	if(yes=="yes")
	{
	for(int i=0;i<Vstu.size();i++)
	{	
	    Sum=0;
			for(int j=0;j<10;j++)
			{
				Sum+=Vstu[i].scores[j];//��ÿ�Ƴɼ������� 
				
			}
			Vstu[i].sum=Sum;
	}
    }
    else {
    	cout<<"��ֹ"<<endl;
	}
    //��ѯ��ĩ�ܳɼ�
	 cout<<"������Ҫ��ѯ��ĩ�ܳɼ���ѧ��ѧ��"<<endl;
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
	   	cout<<"�Ҳ�����ѧ��";
	   }
	}
    ifs.close();//�ļ���ȡ����ϣ������ѷ���Vstu�У��ر��ļ��� 
    
	//�����ļ� 
	ofstream o_file("stu_score.csv");//�����ļ���o_file�����ļ������� 
	for(int i=0;i<Vstu.size();i++)
	{
		o_file<<Vstu[i].id<<","<<Vstu[i].name<<","<<Vstu[i].major<<" ";
		for(int j=0;j<10;j++)
		{
			o_file<<Vstu[i].scores[j]<<",";
		}
		o_file<<"��ĩ�ܳɼ�Ϊ"<<Vstu[i].sum<<endl;
	}
	o_file.close();
   return 0;
   
}
