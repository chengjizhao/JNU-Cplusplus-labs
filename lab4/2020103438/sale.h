#ifndef Sale_H
#define Sale_H
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
    void set_sales(Sales &s, const double ar[], int n);
    void set_sales(Sales &s);
    void show_sales(const Sales &s);
}
#endif