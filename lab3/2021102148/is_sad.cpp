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
			sum+=(n%10)*(n%10);//拆出末位计算平方，存入sum中； 
			n = n/10;//除去末位； 
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
 	vector<int>v1;//放忧郁数
	vector<int>v2;//放幸福数 
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
	 cout<<"1000内忧郁数为："<<endl; 
	 print_v(v1);
	 cout<<"1000内幸福数为："<<endl;
	 print_v(v2);
	 return 0;
 }
