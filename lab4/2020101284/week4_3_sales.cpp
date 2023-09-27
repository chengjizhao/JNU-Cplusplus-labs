#include "sales.h"
#include <iostream>

namespace SALES {
    void setSales(Sales& s, const double ar[], int n) {
        double total = 0.0;
        s.max = ar[0];
        s.min = ar[0];

        for (int i = 0; i < QUARTERS; i++) {
            if (i < n) {
                s.sales[i] = ar[i];
                total += ar[i];
                if (ar[i] > s.max)
                    s.max = ar[i];
                if (ar[i] < s.min)
                    s.min = ar[i];
            }
            else {
                s.sales[i] = 0.0;
            }
        }

        s.average = total / n;

        for (int i = n; i < QUARTERS; i++) {
            s.sales[i] = s.average;
        }
    }

    void setSales(Sales& s) {
        double ar[QUARTERS];
        std::cout << "Enter sales for each quarter:\n";
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << "Quarter " << i + 1 << ": ";
            std::cin >> ar[i];
        }
        setSales(s, ar, QUARTERS);
    }

    void showSales(const Sales& s) {
        std::cout << "Sales for each quarter:\n";
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << "Quarter " << i + 1 << ": " << s.sales[i] << std::endl;
        }
        std::cout << "Maximum sale: " << s.max << std::endl;
        std::cout << "Minimum sale: " << s.min << std::endl;
        std::cout << "Average sale: " << s.average << std::endl;
    }
}