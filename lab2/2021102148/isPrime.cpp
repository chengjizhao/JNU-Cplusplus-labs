#include <iostream>
#include <iomanip>
#include <vector>
#include<stdio.h>
using namespace std;
bool isPrime(int i)
{
	for(int k=2;k<=i/2;k++)
	{
		if(i%k==0)
		return false;
	}
	return true;
}
int main()
{
	int count=0;
	int i;
	vector<int>a;
	for(i=1;i<1001;i++)
	{
		if(isPrime(i))
	{
		count++;
		a.push_back(i);
		if(count%10==0)
		cout<<endl;
		else cout<<setw(4)<<i;
	}
	}
}
