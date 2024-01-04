#include "SALES.h"
#include <iostream>
static int count=0;
using  std::cout;
using std::cin;
using std::endl;
namespace SALES
{
	void setSales(Sales &s,const double ar[],int n)
	{
		count=n;
		double Avg,Max,Min,Sum=0;
		if(n>4)
			n=4;
		if(n==0)
		{
			s.average=0;
			s.max=0;
			s.min=0;
		}
		if(n<=4&&n>0)
		{
			count=n;
			Avg=Max=Min=ar[0];
			for(int i=0;i<n;i++)
			{
				s.sales[i]=ar[i];
				Sum+=s.sales[i];
				if(s.sales[i]>Max)
					Max=s.sales[i];
				if(s.sales[i]<Min)
					Min=s.sales[i];
			}
			Avg=Sum*1.0/n;
			s.average=Avg;
			s.max=Max;
			s.min=Min;	
		}
	}
	void setSales(Sales &s)
	{
		double Max,Min,Avg;
		Max=-999;	
		Min=9999;
		Avg=0;
		double Sum=0;
		for(int i=0;i<QUARTERS;i++)
		{
			cout<<"Please enter the valus:"<<endl;
			cin>>s.sales[i];
			Sum+=s.sales[i];
				if(s.sales[i]>Max)
					Max=s.sales[i];
				if(s.sales[i]<Min)
					Min=s.sales[i];	
		}
			Avg=Sum*1.0/QUARTERS;
			s.average=Avg;
			s.max=Max;
			s.min=Min;
			count=QUARTERS;	//令count=4
	}
	void showSales(const Sales &s)
	{
		cout<<"show Sales:"<<endl;
		cout<<"s.sales address="<<s.sales<<endl;
		cout<<"count="<<count<<endl;
		for(int i=0;i<count;i++)
			cout<<s.sales[i]<<"  ";
		cout<<"\nmax is :"<<s.max<<endl;
		cout<<"Min is :"<<s.min<<endl;
		cout<<"Avg is "<<s.average<<endl;
		cout<<"show end;"<<endl<<endl;
	}
}