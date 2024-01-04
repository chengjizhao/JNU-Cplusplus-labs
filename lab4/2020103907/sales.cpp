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
        cout << "输入每个季度的销售数据:\n";
        for (int i = 0; i < QUARTERS; ++i) {
            cout << "季度 " << i + 1 << ": ";
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
        cout << "每一个季度的销售业绩:\n";
        for (int i = 0; i < QUARTERS; ++i) {
            cout << "季度 " << i + 1 << ": " << s.sales[i] << std::endl;
        }
        cout << "最大值: " << s.max << endl;
        cout << "最小值: " << s.min << endl;
        cout << "平均值: " << s.average << endl;
    }
}

