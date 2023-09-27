#include "Sales.h"
#include <iostream>
using namespace SALES;
using namespace std;
namespace SALES
{
        void setSales(Sales& s, const double ar[], int n)
        {
                double total = 0;
                s.max = s.min = ar[0];
                for (int i = 0; i < n; i++)
                {
                        s.sales[i] = ar[i];
                        if (s.max < ar[i])
                                s.max = ar[i];
                        else if (s.min > ar[i])
                                s.min = ar[i];
                        total += ar[i];
                }
                s.average = total / n;
        }
 
        void setSales(Sales& s)
        {
                double ar[4];
                int n = 4;
                cout << "请输入四个销售业绩: ";
                for (int i = 0; i < n; i++)
                {
                        cin >> ar[i];
                }
 
        int total = 0;
        s.max = s.min = ar[0];
        for (int i = 0; i < n; i++)
        {
                s.sales[i] = ar[i];
                if (s.max < ar[i])
                        s.max = ar[i];
                else if (s.min > ar[i])
                        s.min = ar[i];
                total += ar[i];
        }
        s.average = total / n;
        }
        void showSales(const Sales& s)
        {
                cout << "销售业绩分别为: ";
                for (int i = 0; i < 4; i++)
                {
                        cout << s.sales[i] << " ";
                }
                cout << endl;
                cout << "最大值: " << s.max << "最小值: " << s.min << "平均值: " << s.average << endl;
        }
}
