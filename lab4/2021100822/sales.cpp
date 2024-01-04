#include <iostream>
#include <limits>
#include "sales.h"

namespace SALES {
    void setSales(Sales &s, const double ar[], int n) {
        double total = 0.0;
        s.max = ar[0];
        s.min = ar[0];

        for (int i = 0; i < QUARTERS && i < n; ++i) {
            s.sales[i] = ar[i];
            total += ar[i];

            if (ar[i] > s.max)
                s.max = ar[i];

            if (ar[i] < s.min)
                s.min = ar[i];
        }

        s.average = total / QUARTERS;
    }

    void setSales(Sales &s) {
        double total = 0.0;
        s.max = -std::numeric_limits<double>::infinity();
        s.min = std::numeric_limits<double>::infinity();

        for (int i = 0; i < QUARTERS; ++i) {
            std::cout << "Enter sales for Quarter " << i + 1 << ": ";
            std::cin >> s.sales[i];
            total += s.sales[i];

            if (s.sales[i] > s.max)
                s.max = s.sales[i];

            if (s.sales[i] < s.min)
                s.min = s.sales[i];
        }

        s.average = total / QUARTERS;
    }

    void showSales(const Sales &s) {
        for (int i = 0; i < QUARTERS; ++i) {
            std::cout << "Quarter " << i + 1 << ": " << s.sales[i] << std::endl;
        }
        std::cout << "Average: " << s.average << std::endl;
        std::cout << "Max: " << s.max << std::endl;
        std::cout << "Min: " << s.min << std::endl;
    }
}
