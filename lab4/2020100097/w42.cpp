#include "sales.h"
#include <iostream>

namespace SALES
{
    using namespace std;
    void setSales(Sales& s, const double a[], int n)
    {
        s.max = a[0];
        s.min = a[0];
        double sum = 0;
        for (int i=0;i<n;i++)
        {
            s.sales[i] = a[i];
            sum += ar[i];
            if (a[i] > s.max) s.max = a[i];
            if (a[i] < s.min) s.min = a[i];
        }
        s.average=sum/4;
    }

    void setSales(Sales& s)
    {
        double a[QUARTERS];
        cout << "请输入" << QUARTERS;
        for (int i = 0; i<4; i++) cin >> a[i];
        setSales(s, a[], QUARTERS);
    }

    void showSales(const Sales& s)
    {
        cout << QUARTERS << "销量分别为：";
        for (int i = 0; i < QUARTERS; i++) cout << s.sales[i] << " ";
        cout << endl << "最少为：" << s.min;
        cout << endl << "最多为：" << s.max;
        cout << endl << "平均为：" << s.average << endl;
    }
}