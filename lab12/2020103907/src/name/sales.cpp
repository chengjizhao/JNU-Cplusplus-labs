// sales.cpp
#include "sales.h"
#include <iostream>
#include <algorithm>
using namespace std;

namespace SALES {
    void setSales(Sales & s, const double ar[], int n) {
        n = min(n, QUARTERS);
        copy(ar, ar + n, s.sales);
        s.max = *max_element(s.sales, s.sales + n);
        s.min = *min_element(s.sales, s.sales + n);

        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += s.sales[i];
        }
        s.average = sum / n;
    }

    void setSales(Sales & s) {
        cout << "Enter sales data:\n";
        for (int i = 0; i < QUARTERS; ++i) {
            cout << "quarter " << i + 1 << ": ";
            cin >> s.sales[i];
        }
        s.max = *max_element(s.sales, s.sales + QUARTERS);
        s.min = *min_element(s.sales, s.sales + QUARTERS);

        double sum = 0;
        for (int i = 0; i < QUARTERS; i++)
        {
            sum += s.sales[i];
        }
        s.average = sum / QUARTERS;
    }

    void showSales(const Sales & s) {
        cout << "Sales performance for each quarter:\n";
        for (int i = 0; i < QUARTERS; ++i) {
            cout << "quarter " << i + 1 << ": " << s.sales[i] << std::endl;
        }
        cout << "Max: " << s.max << endl;
        cout << "Min: " << s.min << endl;
        cout << "Average: " << s.average << endl;
    }
}