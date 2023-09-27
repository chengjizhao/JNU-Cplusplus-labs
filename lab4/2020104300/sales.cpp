// sales.cpp
#include "sales.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace SALES {
    void setSales(Sales &s, const double ar[], int n) {
        memset(&s, 0, sizeof(s));
        n = (n < QUARTERS) ? n : QUARTERS;
        
        for (int i = 0; i < n; i++) {
            s.sales[i] = ar[i];
            s.max = (i == 0) ? ar[i] : (s.max > ar[i] ? s.max : ar[i]);
            s.min = (i == 0) ? ar[i] : (s.min < ar[i] ? s.min : ar[i]);
            s.average += ar[i];
        }
        
        s.average /= n;
    }

    void setSales(Sales &s) {
        double ar[QUARTERS];
        
        std::cout << "Enter sales for each of the " << QUARTERS << " quarters:\n";
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << "Quarter " << (i + 1) << ": ";
            std::cin >> ar[i];
        }
        
        setSales(s, ar, QUARTERS);
    }

    void showSales(const Sales &s) {
        std::cout << "Sales Data:\n";
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << "Quarter " << (i + 1) << ": " << s.sales[i] << std::endl;
        }
        std::cout << "Average: " << s.average << std::endl;
        std::cout << "Max: " << s.max << std::endl;
        std::cout << "Min: " << s.min << std::endl;
    }
}
