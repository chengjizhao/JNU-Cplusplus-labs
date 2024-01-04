#include "sales.h"

int main() {
    SALES::Sales s1, s2;

    double salesData[] = { 100.0, 200.0, 300.0 };
    int numElements = sizeof(salesData) / sizeof(double);

    SALES::setSales(s1, salesData, numElements);
    SALES::setSales(s2);

    SALES::showSales(s1);
    SALES::showSales(s2);

    return 0;
}
