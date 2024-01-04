#include "sales.h"
#include <iostream>
#include <algorithm>
using namespace std;
namespace SALES {
double Average(const double ar[],int n)
{
    double sum = 0;
    for(int i = 0; i < n; i=i+1)
    {
        sum = sum + ar[i];
    }
    double average = sum/n;
    return average;
}
void setSales(Sales &s, const double ar[], int n)
{
    s.max = 0;
    s.min = 10000000;
    for(int i = 0; i < n; i=i+1)
    {
        s.sales[i] = ar[i];
        s.max = max(s.max,ar[i]);
        s.min = min(s.min,ar[i]);
    }
    s.average = Average(ar,n);
}
void setSales(Sales &s)
{
    s.max = 0;
    s.min = 10000000;
    cout << "请输入4个季度的销售业绩" << endl;
    for(int i = 0; i < 4; i=i+1)
    {
        cin >> s.sales[i];
        s.max = max(s.max,s.sales[i]);
        s.min = min(s.min,s.sales[i]);
    }
    s.average = Average(s.sales, 4);
}
void showSales(const Sales &s)
{
    cout << "4个季度的销售业绩:" << " ";
    for(int i = 0; i < 4; i=i+1)
    {
        cout << s.sales[i] << " ";
    } 
    cout << endl;
    cout << "平均：" << s.average << endl;
    cout << "最低：" << s.min << endl;
    cout << "最高：" << s.max << endl;
}
}