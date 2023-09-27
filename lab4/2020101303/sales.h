namespace SALES
{
    const int QUARTERS = 4;
    struct Sales 
    {
        double sales[QUARTERS];
        double max,min,average;
    };
    void setSales(Sales &s, const double ar[], int n);
    void setSales(Sales &s);
    void showSales(const Sales &s);
}