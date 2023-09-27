#include <iostream>
#include"Sale.h"
#include"Sale.cpp"
using namespace std;
using namespace SALES;
int main()
{
    const double ar[5] = {35.6,44.5,66.3,12.1,41.2 }; //数组
    Sales s1, s2; //结构变量
    //非交互版本
    setSales(s1, ar, 5);//当n=5时
    showSales(s1);//显示
    //交互版本
    setSales(s2);
    showSales(s2);//显示
    return 0;
}