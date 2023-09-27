#include<iostream>
#include"Sale.h"
using namespace std;
namespace SALES
{
    //非交互式计算销售额
    void setSales(Sales &s, const double ar[], int n)
    {
        double sum = 0.0;
        s.max = ar[0];
        s.min = ar[0];
        if (n < QUARTERS)
        {
            for(int i = 0;i < n;i++)
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
                sum += s.sales[i];
            }
            s.average = sum / 4;
        }
        else
        {
            for(int i = 0;i < QUARTERS;i++)
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
                sum += s.sales[i];
            }
            s.average = sum / 4;
        }
    }
    //交互式计算销售额
    void setSales(Sales &s)
    {
        cout << "请输入Sales结构元素:" << endl;
        cout << "sales数组的元素:" << endl;
        cout << "sales[0]:";
        cin >> s.sales[0];
        s.max = s.sales[0];
        s.min = s.sales[0];
        double sum;

        for (int i = 1;i < QUARTERS;i++)
        {
            cout << "sales[" << i << "]:";
            cin >> s.sales[i];
            if(s.max < s.sales[i])
            {
                s.max = s.sales[i];
            }
            if(s.min > s.sales[i])
            {
                s.min = s.sales[i];
            }
            sum += s.sales[i];
        }
        s.average = sum / 4;
    }
    //显示销售额
    void showSales(const Sales &s)
    {
        for(int i = 0;i < QUARTERS;i++)
        {
            cout << " sales[" << i << "] :" << s.sales[i] << " , ";
        }
        cout << endl;
        cout << "max : " << s.max << " , ";
        cout << "min : " << s.min << " , ";
        cout << "average : " << s.average << endl;
    }
}