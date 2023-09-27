// sales.cpp
#include "sales.h"
#include <iostream>

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

        s.average = total / n;
    }

    void setSales(Sales &s) {
        std::cout << "请输入" << QUARTERS << "个季度的销售业绩：" << std::endl;
        double total = 0.0;

        for (int i = 0; i < QUARTERS; ++i) {
            std::cout << "季度 " << i + 1 << " 销售业绩: ";
            std::cin >> s.sales[i];
            total += s.sales[i];

            if (i == 0) {
                s.max = s.sales[i];
                s.min = s.sales[i];
            } else {
                if (s.sales[i] > s.max)
                    s.max = s.sales[i];
                if (s.sales[i] < s.min)
                    s.min = s.sales[i];
            }
        }

        s.average = total / QUARTERS;
    }

    void showSales(const Sales &s) {
        std::cout << "销售业绩数据如下：" << std::endl;
        for (int i = 0; i < QUARTERS; ++i) {
            std::cout << "季度 " << i + 1 << ": " << s.sales[i] << std::endl;
        }
        std::cout << "平均销售业绩: " << s.average << std::endl;
        std::cout << "最高销售业绩: " << s.max << std::endl;
        std::cout << "最低销售业绩: " << s.min << std::endl;
    }
}
