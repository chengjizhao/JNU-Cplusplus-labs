#include <iostream>
#include "sales.h"

int main() {
    SALES::Sales sales1, sales2;
    double salesData[] = {1100.0, 1200.0, 1300.0, 1400.0};
    SALES::setSales(sales1, salesData, 4); 
    SALES::setSales(sales2); 
    std::cout << "Sales 1:\n";
    SALES::showSales(sales1);
    std::cout << "\nSales 2:\n";
    SALES::showSales(sales2);
    return 0;
}
