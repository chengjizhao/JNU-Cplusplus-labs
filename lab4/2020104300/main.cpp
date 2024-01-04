// main.cpp
#include <iostream>
#include "sales.h"

int main() {
    SALES::Sales s1, s2;
    double ar[] = {1200.5, 2300.0, 1400.25, 2000.75};

    SALES::setSales(s1, ar, sizeof(ar) / sizeof(ar[0]));
    SALES::setSales(s2);

    std::cout << "Sales Data for s1:\n";
    SALES::showSales(s1);

    std::cout << "\nSales Data for s2:\n";
    SALES::showSales(s2);

    return 0;
}
