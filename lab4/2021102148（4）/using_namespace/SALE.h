#ifndef _SALE_H
#define _SALE_H
namespace SALES
{
    const int QUARTERS = 4; // 四季度
    struct Sales
    {
        double sales[QUARTERS]; // 存放四个季度销售额
        void setSales(int n);
        void showSales();
    };
}

#endif
