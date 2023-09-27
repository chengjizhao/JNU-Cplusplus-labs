#include <iostream>
#include "sales.h"

int main() {
    SALES::Sales s1, s2;
    double sales1[SALES::QUARTERS] = {1000.0, 2000.0, 1500.0, 1800.0};
    double sales2[SALES::QUARTERS] = {1200.0, 2200.0, 1300.0, 1900.0};

    SALES::setSales(s1, sales1, SALES::QUARTERS);
    SALES::setSales(s2, sales2, SALES::QUARTERS);

    std::cout << "第一个 Sales 对象的信息：\n";
    SALES::showSales(s1);

    std::cout << "\n第二个 Sales 对象的信息：\n";
    SALES::showSales(s2);

    return 0;
}