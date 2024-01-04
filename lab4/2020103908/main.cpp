// main.cpp
#include "sales.h"
int main()
{
    using SALES::Sales;
    Sales s1, s2;
    double salesData1[] = {1000.0, 2000.0, 1500.0, 3000.0};
    SALES::setSales(s1, salesData1, 4);
    SALES::showSales(s1);
    SALES::setSales(s2);
    SALES::showSales(s2);
    return 0;
}
