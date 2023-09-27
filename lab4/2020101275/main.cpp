#include "sales.h"

int main()
{
    using namespace SALES;
    Sales sale1, sale2;

    double saleData[6] = {25, 302, 54, 679, 222, 376};
    double salesData1[QUARTERS];
    for (int i = 0; i < QUARTERS; i ++) salesData1[i] = saleData[i];
    setSales(sale1, salesData1, QUARTERS);
    showSales(sale1);

    setSales(sale2);
    showSales(sale2);

    return 0;
}

