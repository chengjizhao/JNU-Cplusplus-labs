#ifndef SALES_H_
#define SALES_H_

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

    void setSales(Sales &s, const double ar[], int n);
    void setSales(Sales &s);
    void showSales(const Sales &s);
}

#endif // SALES_H_