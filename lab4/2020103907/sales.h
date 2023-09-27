// sales.h
namespace SALES {
    const int QUARTERS = 4;

    struct Sales {
        double sales[QUARTERS];
        double max;
        double min;
        double average;
    };

    void setSales(Sales & s, const double ar[], int n);
    void setSales(Sales & s);
    void showSales(const Sales & s);
}
