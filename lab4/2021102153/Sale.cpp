#include"Sale.h"
#include<string>
namespace SALES
{
void setSales(Sales &s)
{
string a={"请输入第"};
string a1={"季度销售额"};
for(int i=0; i<4 ;i++)
{
    cout << a << i << a1 << endl;
    cin >> s.sales[i];
    if (i==0)
    {
        s.max=s.sales[i];
        s.min=s.sales[i];
    }
    if(i>1&&s.sales[i]>s.max)
    {
        s.max=s.sales[i];
    }
    if(i>1&&s.sales[i]<s.min)
    {
        s.min=s.sales[i];
    }
    if(i==3)
    {
        double s1;
        s1=s.sales[0];
        for(int i=1;i<4;i++)
        {
            s1+=s.sales[i];
        }
        s.average=s1/4;
    }
}
}


void setSales(Sales &s, const double ar[], int n)
{
s.max=ar[0];
s.min=ar[0];
double s1;
if(n<QUARTERS)
{
    for(int i=0;i<n;i++)
    {
    s.sales[i] = ar[i];
    if(s.max < s.sales[i])
    {
    s.max = s.sales[i];
    }
    if(s.min > s.sales[i])
    {
    s.min = s.sales[i];
    }
    s1+=s.sales[i];
    }
    s.average=s1/4;
}
else
{
for(int i=0;i<QUARTERS;i++)
{
    s.sales[i] = ar[i];
    if(s.max < s.sales[i])
    {
    s.max = s.sales[i];
    }
    if(s.min > s.sales[i])
    {
    s.min = s.sales[i];
    }
    s1+=s.sales[i];
}
    s.average=s1/4;
}

}


void showSales(const Sales& s)
{
    cout << endl << " max :" << s.max << "," << "min :" << s.min << "," <<"average :" <<s.average << endl;
}
}
