#include "sales.h"
#include <iostream>

namespace SALES
{
    using namespace std;

    void setSales(Sales& s, const double ar[], int n)
    {
        //分别设置保存最值和总数的地方
        s.max = ar[0];
        s.min = ar[0];
        double sum = 0;
        //遍历以计算总数和找出最值，最后计算平均数
        for (int i = 0; i < n; i++)
        {
            s.sales[i] = ar[i];
            sum += ar[i];
            if (ar[i] > s.max) s.max = ar[i];
            if (ar[i] < s.min) s.min = ar[i];
        }
        s.average = sum / QUARTERS;
    }

    void setSales(Sales& s)
    {
        double ar[QUARTERS];
        cout << "请输入" << QUARTERS << "位销售的销量: ";
        //保存输入的销量数据
        for (int i = 0; i < QUARTERS; i++) cin >> ar[i];
        setSales(s, ar, QUARTERS);
    }

    void showSales(const Sales& s)
    {
        //输出各项数据到屏幕
        cout << QUARTERS << "位销售的销量分别为：";
        for (int i = 0; i < QUARTERS; i++) cout << s.sales[i] << " ";
        cout << endl << "最多销量为：" << s.max;
        cout << endl << "最少销量为：" << s.min;
        cout << endl << "平均销量为：" << s.average << endl;
    }
}