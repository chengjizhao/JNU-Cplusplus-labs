#include "Sales.h"  
#include <algorithm>  
#include <limits>  

using namespace SALES;

void Sales::setSales(const double ar[], int n) {
    if (n != QUARTERS) {
        std::cerr << "Invalid number of quarters!" << std::endl;
        return;
    }
    for (int i = 0; i < QUARTERS; ++i) {
        sales[i] = ar[i];
    }
    std::sort(sales, sales + QUARTERS);
    max = sales[QUARTERS - 1];
    min = sales[0];
}

void Sales::setSales() {
    std::cout << "Enter " << QUARTERS << " sales figures: ";
    for (int i = 0; i < QUARTERS; ++i) {
        std::cin >> sales[i];
    }
    std::cin.ignore(); // Ignore the newline character left in the input buffer.  
    std::sort(sales, sales + QUARTERS);
    max = sales[QUARTERS - 1];
    min = sales[0];
}

void Sales::showSales() const {
    std::cout << "Sales Figures:" << std::endl;
    for (int i = 0; i < QUARTERS; ++i) {
        std::cout << "Quarter " << (i + 1) << ": " << sales[i] << std::endl;
    }
    std::cout << "Maximum: " << max << std::endl;
    std::cout << "Minimum: " << min << std::endl;
}