#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    //����vector list
	vector<int>v(60);
	list<int>l(60);
	size_t size;
	srand(NULL);//��������ӣ�
	
	//�����ʱ���Ԫ��                 
	clock_t start,v_time,l_time; 
	
	//Ҫ�����Ԫ�ظ���
	int num;
	cout<<"����Ҫ�����Ԫ�ظ�����";
	cin>>num; 
		
	//��ʼ��ʱ1
	size=60;
	start=clock();
	
	//���������1
	vector<int>::iterator it_v=v.begin();//�� auto it_v = v.begin();
	for(int i=0;i<num;i++) 
	{
		advance(it_v,rand()%(size-1));//�������ƶ����λ��
		v.insert(it_v,0);
		++size;
		it_v=v.begin();
	}
	v_time=clock()-start;//������ʱ1������ʱ�䣻]
	
	//��ʼ��ʱ2
	size=60;
	start=clock();	                
	//���������2
	list<int>::iterator it_l=l.begin();//�� auto it_l=l.begin();
	for(int i=0;i<num;i++) 
	{
		advance(it_l,rand()%(size-1));//�������ƶ����λ��
		l.insert(it_l,0);
		++size;
		it_l=l.begin();
	}
	l_time=clock()-start;//������ʱ������ʱ�䣻
	
	cout<<"vector��ʱΪ��"<<v_time<<"ms"<<endl; 
 	cout<<"list��ʱΪ��"<<l_time<<"ms"<<endl; 
 	
 	return 0;
 } 
 
 
