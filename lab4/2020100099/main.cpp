#include "sales.h"

int main()
{
    SALES::Sales s1, s2;
    
    double ar[SALES::QUARTERS] = {1000, 2000, 3000, 4000};
    
    // 使用setSales函数设置销售业绩
    s1.setSales(s1, ar, SALES::QUARTERS);
    
    // 使用setSales函数设置销售业绩
    s2.setSales(s2);
    
    // 显示销售业绩
    s1.showSales(s1);
    s2.showSales(s2);
    
    return 0;
}