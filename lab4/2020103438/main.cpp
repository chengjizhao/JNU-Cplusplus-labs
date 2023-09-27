#include <iostream>
#include "sale.h"
#include "sale.cpp"
using namespace std;
using namespace SALES;
int main()
{
    const double ar[5] = {35.6, 44.5, 66.3, 12.1, 41.2}; // 数组
    Sales s1, s2;                                        // 结构变量
    // 非交互版本
    set_sales(s1, ar, 5); // 当n=5时
    show_sales(s1);       // 显示
    // 交互版本
    set_sales(s2);
    show_sales(s2); // 显示
    return 0;
}