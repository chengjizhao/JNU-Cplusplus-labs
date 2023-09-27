#include "Sales.h"
#include <iostream>

using namespace std;

namespace SALES
{
    //设置销售业绩
    void setSales(Sales &s,const double ar[],int n)
    {
        double sum=0.0;
        s.max = s.min= ar[0];
        if(n <= QUARTERS && n != 0)
        {
        for(int i = 0;i < n;i ++)
        {
            s.sales[i] = ar[i];
            if(s.max < s.sales[i])
                 s.max = s.sales[i];
            if(s.min > s.sales[i])
                s.min = s.sales[i];
            sum = sum + s.sales[i];
        }
        s.average = sum / 4;
        }
        else
            cout << "所选业绩数量不符合要求。\n";
    }

    //交互式输入4个季度的销售业绩
    void setSales(Sales &s)
    {
        double ar[QUARTERS];
        std::cout << "请输入每个季度的销售业绩:\n";
        for (int i = 0; i < QUARTERS; i ++) 
        {
            std::cout << "第 " << i +1 << "个季度: ";
            std::cin >> ar[i];
        }
        setSales(s, ar, QUARTERS);
    }

    //显示
    void showSales(const Sales &s)
    {
        cout << endl 
             << "最高销售业绩: " << s.max << endl
             << "最低销售业绩: " << s.min << endl 
             << "平均销售业绩: " << s.average << endl;
    }
}