#include <iostream>
#include <vector>
#include <cmath> 
#include <algorithm>
using namespace std;


bool sad(int n)
{
	vector<int>v ;
	vector<int>:: iterator it;
	while(n!=1)
	{
		int sum=0;
		while(n>0)
		{
			sum+=(n%10)*(n%10);//���ĩλ����ƽ��������sum�У� 
			n = n/10;//��ȥĩλ�� 
		}
		it=find(v.begin(),v.end(),sum) ;
		if(it !=v.end())
		{
			return false;
		}
		n=sum;
		v.push_back(sum);
	}
	return true;
 } 
 
 void print_v(vector<int>&v)
 {
 	for(int i=0;i<v.size();i++)
 	{
 		cout<<v[i]<<" ";
	 }
	 cout<<endl;
 }
 
 int main()
 {
 	vector<int>v1;//��������
	vector<int>v2;//���Ҹ��� 
 	for(int i=0;i<1001;i++)
 	{
 		if(sad(i))
 		{
 		 v1.push_back(i);
		 }
		else
		{
		v2.push_back(i);
		}		
	 }
	 cout<<"1000��������Ϊ��"<<endl; 
	 print_v(v1);
	 cout<<"1000���Ҹ���Ϊ��"<<endl;
	 print_v(v2);
	 return 0;
 }
