#include "sales.h"
#include <iostream>
 namespace SALES
 {
    void Sales::setSales(Sales& s, const double ar[],int n)
    {
        for (int i = 0; i <n; i++)
        {
            s.sales[i]=ar[i];
        }
        s.max=s.sales[0];
        s.min=s.sales[0];
        for (int  i = 0; i < n; i++)
        {
            if (s.sales[i] > s.max)
            {
                s.max=s.sales[i];
            }
            if (s.sales[i] < s.min)
            {
                s.min=s.sales[i];
            }
            
        }
        
    }
    void Sales::setSales(Sales& s)
    {
        std::cout << "请输入第" << QUARTERS << "季度的销售业绩：" << std::endl;
        for (int i = 0; i < QUARTERS; i++)
        {
            std::cin >> s.sales[i];
        }
        
    }
    void Sales::showSales(const Sales& s)
    {
        std::cout << "销售业绩" <<std::endl;
        for (int i = 1; i < QUARTERS; i++)
        {
            std::cout << "第" << i << "季度:" << s.sales[i] << std::endl;
        }
        std::cout << "最大销售额为：" << s.max <<std::endl;
        std::cout << "最小销售额为：" << s.min <<std::endl;
    }
 }