#include <iostream>
#include"Sale.h"
#include"Sale.cpp"
using namespace std;
using namespace SALES;
int main()
{
    const double ar[5]={5.4,7.5,2.3,1.1,9.2};
    Sales s1,s2;
    setSales(s1,ar,5);
    showSales(s1);
    setSales(s2);
    showSales(s2);
    return 0;
}