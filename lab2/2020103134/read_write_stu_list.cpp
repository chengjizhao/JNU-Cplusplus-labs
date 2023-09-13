#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<map>

using namespace std;

//����str_studengt�ṹ�������Դ洢ѧ�š�������רҵ��ʵ��ֺ��ܷ֣� 
struct str_student
{
	string stu_id;
	string stu_name;
	string stu_major;
	int stu_exp_score[16];
	int stu_total_score;
 } ;
 
 vector<str_student> V_student;
//���ļ�����
 void read_csv(const string& filename)
 {
     //��������������
 	ifstream fin;
	fin.open("stu_list.csv",ios::in);
	if(!fin.is_open())  //����ļ��Ƿ񱻴� 
	{
		cerr<<"�޷����ļ�"<<endl;
		return;
	}
	string line;
	while(getline(fin,line))
	{
		stringstream ss(line);//��line���Ƶ�ss�� 
		string cell;
		vector<string> cells;
		while(getling(ss,cell,','))//�����Ƿָ��� 
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
		 			student.stu_exp_score[i]=stoi(cells[i+3]);//�� n ���Ƶ��ַ���ת��Ϊʮ����
		 			student.stu_total_score=student.stu_total_score+student.stu_exp_score[i];
				 }
				 V_Student.push_back(student);
	}
	fin.close(); 
 }
 
//����д���ļ�����
 void write_csv(const string& filename)
 {
 	//������������� 
 	ofstream fout(filename);
 	if(!fout.is_open())
 	{
 		cerr<<"�޷����ļ�"<<endl;
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
 
//��ѯ�ɼ�����
 void query_score(const string& stu_id)
 {
 	for(const auto& student : V_student)
 	{
 		if(student.stu_id==stu_id)
 		{
 			cout<<"����Ϊѧ����Ϣ"<<endl;
 			cout<<"ѧ��: "<<student.stu_id<<endl;
 			cout<<"����: "<< student.stu_name<<endl;
 			cout<<"רҵ: "<< student.stu_major<<endl;
 			for(int i=0;i<16;i++)
 			{
 				 cout<<"��"<<i+1<<"��ʵ��֣�" ;
				 cout<<student.stu_exp_score[i]<<endl;
			 }
			 cout<<"�ܷ֣�"<< student.stu_total_score<<endl;
			 return; 
		 }
	 }
	 cout<<"ѧ�Ŵ���"<<endl;
 } 

//¼��ɼ�����
void enter_score(const string& stu_id,int i,int stu_score)
{
	for(auto& student : V_student)
	{
		if(student.stu_id==stu_id)
		{
			student.stu_total_score=student.stu_total_score+stu_score;
			student.stu_exp_score[i-1]=stu_score;
			query_score(stu_id);
			cout<<"¼��ɹ�"<<endl<<endl;
			return;
		}
	 }
	 cout<<"ѧ�Ŵ���"<<endl;
}
 
//������ 
int main()
{
	
    string stu_id;
    string stu_name;
    string stu_major;
    int stu_score;
    string filename="stu_list.csv";
    read_csv(filename);
    cout<<"��ӭʹ�óɼ�ϵͳ"<<endl<<endl;
    int choice;
    do
    {
    	cout<<"��ѯ�ɼ�����1��¼��ɼ�����2���˳�����0�������룺"<<endl;
    	cin>>choice;
    	if(chice==1)
    	{
    		cout<<"������ѧ��ѧ�ţ�"<<endl;
    		cin>>stu_id;
    		query_score(stu_id);
		}
		else if(chice==2)
		{
			cout<<"������ѧ��ѧ�ţ�"<<endl;
			cin>>stu_id;
			cout<<"��ѡ��ʵ������ţ�1-16����"<<endl;
			int i;
			cin>>i;
			cin.get();
			while(i<1||i>16)
			{
				cout<<"��Ŵ���,����������"<<endl;
				cin>>i; 
				cin.get();
			}
			cout<<"������ѧ��ʵ��֣�0-3����"<<endl;
			cin>>stu_score;
			cin.get();
			while(stu_score<0||stu_score>3)
			{
				cout<<"�ɼ�������Χ�����������룺"<<endl;
				cin>>stu_score;
			}
			enter_score(stu_id,i,stu_score);
		}
		else if(!choice==0)
		{
			cout<<"������Ч������������"<<endl;
		}
	}while(choice==0);
	write_csv(filename);
	enter 0;
}
