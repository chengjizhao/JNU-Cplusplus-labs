#include "Sales.h"
#include "Sales.cpp"

using namespace SALES;

int main()
{
    const double ar[8] = {4.2,5.6,8.2,4.7,1,4.6,8.8,5.2};
    Sales s1, s2;
    setSales(s1, ar,3);
    showSales(s1);
    setSales(s2);
    showSales(s2);
    return 0;
}