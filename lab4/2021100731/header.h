#ifndef __HEADER_H__
#define __HEADER_H__



namespace SALES 
{
    const int QUARTERS = 4;

    struct Sales 
    {
        double sales[QUARTERS];
        double max;
        double min;
        double average;
    };
    void setSales(Sales *s, const double ar[], int n);                            //写数据
    void setSales(Sales *s);                            //读数据
    void showSales(Sales *s);                           //显示数据
    void Calculate(Sales *s);
}



#endif
