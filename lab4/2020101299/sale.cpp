#include "sales.h"
#include <iostream>

namespace SALES 
{
    void setSales(Sales& s, const double ar[], int n) 
    {
        double total = 0.0;
        s.max = ar[0];
        s.min = ar[0];

        for (int k = 0; k < QUARTERS; k++) 
        {
            if (k < n) 
            {
                s.sales[k] = ar[k];
                total += ar[k];
                if (ar[k] > s.max)
                    s.max = ar[k];
                if (ar[k] < s.min)
                    s.min = ar[k];
            }
            else 
            {
                s.sales[k] = 0.0;
            }
        }

        s.average = total / n;

        for (int k = n; k < QUARTERS; k++) 
        {
            s.sales[k] = s.average;
        }
    }

    void setSales(Sales& s) 
    {
        double ar[QUARTERS];
        std::cout << "Enter sales for each quarter:\n";
        for (int k = 0; k < QUARTERS; k++) 
        {
            std::cout << "Quarter " << k + 1 << ": ";
            std::cin >> ar[k];
        }
        setSales(s, ar, QUARTERS);
    }

    void showSales(const Sales& s) 
    {
        std::cout << "Sales for each quarter:\n";
        for (int k = 0; k < QUARTERS; k++) 
        {
            std::cout << "Quarter " << k + 1 << ": " << s.sales[k] << std::endl;
        }
        std::cout << "最大值: " << s.max << std::endl;
        std::cout << "最小值: " << s.min << std::endl;
        std::cout << "平均值: " << s.average << std::endl;
    }
}