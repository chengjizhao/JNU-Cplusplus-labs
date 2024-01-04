#include "sales.h"
#include <iostream>

using SALES::Sales;
const double ar[]={1000,2000,1500,1800};

int main()
{
    Sales s1,s2;
    setSales(s1,ar,4);
    showSales(s1);
    setSales(s2);
    showSales(s2);
    return 0;
}