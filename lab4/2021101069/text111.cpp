#include "Sales.h"  
#include <iostream>  
  
int main() {  
    SALES::Sales s1, s2;  
    double sales1[] = {1000, 2000, 3000, 4000};  
    double sales2[] = {500, 1500, 2500, 3500};  
    s1.setSales(sales1, 4);  
    s2.setSales(sales2, 4);  
    s1.showSales();  
    s2.showSales();  
    return 0;  
}
