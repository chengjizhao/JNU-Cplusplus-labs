#include <iostream>
#include "sales.h"

using namespace std ;
using namespace SALES ;

int main() 
{
    SALES::Sales s1, s2;
    double ar1[SALES::QUARTERS] = {1500,2300,1800,1400};
     double ar2[SALES::QUARTERS] = {1800,2500,1700,1600};
    SALES::setSales(s1, ar1, SALES::QUARTERS);
    SALES::setSales(s2, ar2, SALES::QUARTERS);
    SALES::showSales(s1);
    SALES::showSales(s2);
    return0;
}