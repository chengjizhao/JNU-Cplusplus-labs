#include<iostream>
#include"sales.h"
using namespace std;
namespace SALES
{
    void setSales(Sales &s, const double ar[], int n)//从n个销售业绩中选出4个并计算
         {
            double sum=0.0;
            s.max=ar[0];
            s.min=ar[0];
            for(int i=0;i<QUARTERS;++i)
            if(i<n)
                {
                s.sales[i]=ar[i];
                sum+=ar[i];
                if(ar[i]>s.max)
                {s.max=ar[i];}
                if(ar[i]<s.min)
                {s.min=ar[i];}
                }
            else
            {
                s.sales[i]=0.0;
            }
            s.average=sum/n;
         }

    void setSales(Sales &s);//交互式输入销售成绩并计算
         {
            double ar[QUARTERS];
            cout<<"输入每个季度的销售业绩："<<endl;
            for(int i=0;i<QUARTERS;++i)
            {
                cout<<"季度"<<i+1<<":"<<endl;
                cin>>ar[i];
            }
            setSales(s, ar, QUARTERS);
        }
     void showSales(const Sales &s);//展示销售业绩
         {
            cout<<"以下是四个季度的销售业绩："<<endl;
            for(double x:s)
            cout<<x<<endl;
            cout<<"最大值为："<<s.max<<endl;
            cout<<"最小值为："<<s.min<<endl;
            cout<<"平均值为："<<s.average<<endl;
         }
}