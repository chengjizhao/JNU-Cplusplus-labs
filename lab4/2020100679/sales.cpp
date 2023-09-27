#include "sales.h"
#include <iostream>

namespace SALES {
    void setSales(Sales& s, const double ar[], int n) {
        double total = 0;
        s.max = ar[0];
        s.min = ar[0];

        for (int i = 0; i < n; ++i) {
            s.sales[i] = ar[i];
            total += ar[i];
            if (ar[i] > s.max)
                s.max = ar[i];
            if (ar[i] < s.min)
                s.min = ar[i];
        }

        for (int i = n; i < QUARTERS; ++i) {
            s.sales[i] = 0.0;
        }
    }

    void setSales(Sales& s) {
        std::cout << "Enter sales for each quarter:\n";
        double total = 0;

        for (int i = 0; i < QUARTERS; ++i) {
            std::cout << "Quarter " << i + 1 << ": ";
            std::cin >> s.sales[i];
            total += s.sales[i];
            if (i == 0) {
                s.max = s.sales[i];
                s.min = s.sales[i];
            }
            else {
                if (s.sales[i] > s.max)
                    s.max = s.sales[i];
                if (s.sales[i] < s.min)
                    s.min = s.sales[i];
            }
        }
    }

    void showSales(const Sales& s) {
        std::cout << "Sales for each quarter:\n";
        for (int i = 0; i < QUARTERS; ++i) {
            std::cout << "Quarter " << i + 1 << ": " << s.sales[i] << std::endl;
        }
        std::cout << "Max: " << s.max << std::endl;
        std::cout << "Min: " << s.min << std::endl;
    }
}
