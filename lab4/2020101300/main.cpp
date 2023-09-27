#include "sales.h"

int main()
{
    using namespace SALES;
    Sales sale1, sale2;

    double saleData[6] = {200.0, 400.0, 600.0, 800.0, 1000.0, 1200.0};
    double salesData1[QUARTERS];
    for (int i = 0; i < QUARTERS; i ++) salesData1[i] = saleData[i];
    setSales(sale1, salesData1, QUARTERS);
    showSales(sale1);

    setSales(sale2);
    showSales(sale2);

    return 0;
}
