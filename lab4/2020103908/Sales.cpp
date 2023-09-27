// sales.cpp
#include "sales.h"
#include <iostream>
#include <algorithm>
namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        n = std::min(n, QUARTERS);
        double sum;
        for (int i = 0; i < n; ++i)
        {
            s.sales[i] = ar[i];
            sum = sum + s.sales[i];
        }
        s.max = *std::max_element(s.sales, s.sales + n);
        s.min = *std::min_element(s.sales, s.sales + n);
        s.average = sum / n;
    }

    void setSales(Sales & s)
    {
        std::cout << "Enter sales data for " << "\n";
        double sum;
        for (int i = 0; i < 4; ++i)
        {
            std::cout << "Quarter " << i + 1 << ": ";
            std::cin >> s.sales[i];
            sum = sum + s.sales[i];
        }
        s.max = *std::max_element(s.sales, s.sales + 4);
        s.min = *std::min_element(s.sales, s.sales + 4);
        s.average = sum / 4;
    }

    void showSales(const Sales & s)
    {
        std::cout << "Sales data:\n";
        for (int i = 0; i < QUARTERS; ++i)
        {
          std::cout << "Quarter " << i + 1 << ": " << s.sales[i] << std::endl;
        }
        std::cout << "Max: " << s.max << std::endl;
        std::cout << "Min: " << s.min << std::endl;
        std::cout << "Average: " << s.average << std::endl;
    }
}
