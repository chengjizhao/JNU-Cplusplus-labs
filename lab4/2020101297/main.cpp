#include <iostream>
#include "sales.h"

int main()
{
    double sales1[SALES::QUARTERS] = {1000, 2000, 1500, 3000};
    double sales2[SALES::QUARTERS] = {2500, 1800, 1900, 2200};
    
    SALES::Sales s1;
    SALES::Sales s2;
    
    SALES::setSales(s1, sales1, SALES::QUARTERS);
    SALES::setSales(s2, sales2, SALES::QUARTERS);
    
    std::cout << "Sales 1:" << std::endl;
    SALES::showSales(s1);
    
    std::cout << "Sales 2:" << std::endl;
    SALES::showSales(s2);
    
    return 0;
}
