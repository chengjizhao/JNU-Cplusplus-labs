// main.cpp
#include <iostream>
#include "sales.h"

using namespace std;
int main() {
    SALES::Sales sale1, sale2;
    double salesData[] = {5600.0, 6000.0,5800.0, 6200.0};

    SALES::setSales(sale1, salesData, sizeof(salesData) / sizeof(salesData[0]));
    SALES::setSales(sale2);

    cout << "sale1的销售数据:\n";
    SALES::showSales(sale1);

    cout << "\nsale2的销售数据:\n";
    SALES::showSales(sale2);

    return 0;
}
