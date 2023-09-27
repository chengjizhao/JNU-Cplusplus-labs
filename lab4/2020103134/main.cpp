#include<iostream>
#include"sales.h"
using namespace std;
using namespace SALES;
int main()
{
    Sales s1,s2;
    double data[]={1.3,2.5,3.2,4.7,5.1,6.3,7.5,8.9};
    int n=4;
    setSales(s1, data, n);
    showSales(s1);
    setSales(s2);
    showSales(s2);
    return 0;
}