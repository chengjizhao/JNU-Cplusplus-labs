#include<iostream>
#include"head.h"
using namespace std ;
using namespace SALES;

void SetSales(Sales &s,double ar[], int n)
{
    s.max=0;
    s.min=0;
    for(int i=0;i<4;i++)
    {
        int b=rand()%(n-i);
        s.sales[i]=ar[b];
    }
    for(int i=0;i<4;i++)
    {
        s.max=max(s.max,s.sales[i]);
        s.min=min(s.min,s.sales[i]);
    }
    s.average=(ar[0]+ar[1]+ar[2]+ar[3])/4;
}

void setSales(Sales &s)
{
    s.max=0;
    s.min=0;
    double a[4];
    cout << "请输入四个季度的销售额: " ;
    for(int i=0;i<4;i++)
    {
        cin >> a[i] ;
        s.sales[i]=a[i];
    } 
    for(int i=0;i<4;i++)
    {
        s.max=max(s.max,a[i]);
        s.min=min(s.min,a[i]);
    }
    s.average=(a[0]+a[1]+a[2]+a[3])/4;
}

void showSales(const Sales& s)
{
    cout << "sales为" << s.sales[0] << "," << s.sales[1] << "," << s.sales[2] << "," << s.sales[3] << endl;
    cout << "max= " << s.max << endl ;
    cout << "min= " << s.min << endl ;
    cout << "average= " << s.average << endl ; 
}

int main()
{
    Sales s;
    double ar[8]={10.0,20.0,30.0,40.0,10.0,15.0,34.0,20.0};
    cout << "数组ar为: ";
    for(int i=0;i<8;i++)
    {
        cout << ar[i] << " "  ;
    }
    cout << endl ;
    SetSales(s,&ar[0],8);
    showSales(s);
    setSales(s);
    showSales(s);
    return 0;
}

