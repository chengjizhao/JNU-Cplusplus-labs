// main.cpp
#include "sales.h"

int main() {
    using namespace SALES;

    // 创建两个 Sales 对象
    Sales sales1, sales2;

    double salesData1[] = {1200.5, 800.2, 1000.0, 1500.7};
    setSales(sales1, salesData1, 4);
    showSales(sales1);

    setSales(sales2);
    showSales(sales2);

    return 0;
}
