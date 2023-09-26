#include <iostream>
#include"Sale.h"
#include"Sale.cpp"
using namespace std;
using namespace SALES;
int main()
{
    const double ar[7] = {1.23,5.32,8.56,7.36,12.57,56.255,42.23}; 
    Sales t;
    //非交互版本
    setSales(t, ar, 7);//取前四个
    showSales(t);
    //交互版本
    setSales(t);
    showSales(t);
    return 0;
}