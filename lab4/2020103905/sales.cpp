#include "sales.h"
#include<iostream>
namespace SALES {
    void setSales(Sales &s, const double ar[], int n) {
        // 设置销售额
        for (int i = 0; i < n; ++i) {
            s.sales[i] = ar[i];
        }

        // 计算最大值和最小值
        s.max = s.min = ar[0];
        for (int i = 1; i < n; ++i) {
            if (ar[i] > s.max) {
                s.max = ar[i];
            }
            if (ar[i] < s.min) {
                s.min = ar[i];
            }
        }
    }

    void setSales(Sales &s) {
        // 提示用户输入销售额
        std::cout << "请输入" << QUARTERS << "个季度的销售额：\n";
        for (int i = 0; i < QUARTERS; ++i) {
            std::cin >> s.sales[i];
        }

        // 计算最大值和最小值
        s.max = s.min = s.sales[0];
        for (int i = 1; i < QUARTERS; ++i) {
            if (s.sales[i] > s.max) {
                s.max = s.sales[i];
            }
            if (s.sales[i] < s.min) {
                s.min = s.sales[i];
            }
        }
    }

    void showSales(const Sales &s) {
        std::cout << "销售额：\n";
        for (int i = 0; i < QUARTERS; ++i) {
            std::cout << "季度 " << i + 1 << ": " << s.sales[i] << std::endl;
        }
        std::cout << "最大值: " << s.max << std::endl;
        std::cout << "最小值: " << s.min << std::endl;
    }
}