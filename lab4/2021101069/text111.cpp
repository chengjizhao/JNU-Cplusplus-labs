#include "Sales.h"  
#include <iostream>  
#include <algorithm>  
  
namespace SALES   
{   
void Sales::setSales(const double ar[], int n) {  
    if (n > QUARTERS) {  
        std::cout << "Error: trying to set more than " << QUARTERS << " sales numbers." << std::endl;  
        return;  
    }  
    for (int i = 0; i < n; ++i) {  
        sales[i] = ar[i];  
    }  
    std::sort(sales, sales + n);  
    max = sales[n-1];  
    min = sales[0];  
}  
  
void Sales::showSales() {  
    std::cout << "Sales: ";  
    for (int i = 0; i < QUARTERS; ++i) {  
        std::cout << sales[i] << " ";  
    }  
    std::cout << "\nMax: " << max << "\nMin: " << min << std::endl;  
}  
} // namespace SALES