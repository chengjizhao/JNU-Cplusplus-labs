#ifndef SALES_H  
#define SALES_H
#include <iostream>
using std::cout,std::endl,std::cin;
namespace SALES 
{  
    const int QUARTERS = 4;  
      
    struct Sales 
    {  
        double sales[QUARTERS];  
        double max, min;  
        double average,sum;
        int m;int chu;
          
        void setSales(const double ar[], int num);  
        void setSales();  
        void showSales(const Sales& s);  
    } ; 
}
#endif // SALES_H 