#ifndef _SALES_H_   //防止重定义
#define _SALES_H_

namespace SALES
{
    const int QUARTERS = 4;//业绩数量限制
    struct Sales
    {
        double sales[QUARTERS];
        double max;
        double min;
        double average;
    };
    void setSales(Sales &s, const double ar[], int n);
    void setSales(Sales &s);
    void showSales(const Sales &s);
}

#endif