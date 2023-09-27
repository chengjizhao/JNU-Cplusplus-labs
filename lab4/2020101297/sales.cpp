#include "sales.h"
#include "iostream"

namespace SALES {
    void setSales(Sales &s, const double ar[], int n)
    {
        for (int i = 0; i < n; i++) {
            s.sales[i] = ar[i];
        }
        
        // 计算最大值和最小值
        s.max = s.sales[0];
        s.min = s.sales[0];
        for (int i = 1; i < n; i++) {
            if (s.sales[i] > s.max) {
                s.max = s.sales[i];
            }
            if (s.sales[i] < s.min) {
                s.min = s.sales[i];
            }
        }
    }
    
    void setSales(Sales &s)
    {
        double total = 0.0;
        
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << "Enter sales for quarter " << i + 1 << ": ";
            std::cin >> s.sales[i];
            total += s.sales[i];
        }
        
        // 计算最大值和最小值
        s.max = s.sales[0];
        s.min = s.sales[0];
        for (int i = 1; i < QUARTERS; i++) {
            if (s.sales[i] > s.max) {
                s.max = s.sales[i];
            }
            if (s.sales[i] < s.min) {
                s.min = s.sales[i];
            }
        }
    }
    
    void showSales(const Sales &s)
    {
        std::cout << "Sales: ";
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << s.sales[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Max: " << s.max << std::endl;
        std::cout << "Min: " << s.min << std::endl;
    }
}
