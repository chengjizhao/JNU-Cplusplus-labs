#include "sales.h"
using namespace SALES;
using namespace std;

int main() {
    Sales s1;
    double salesData[] = { 2.7, 3.6, 4.8, 5.6 };

    setSales(s1, salesData, sizeof(salesData) / sizeof(double));
    showSales(s1);

    Sales s2;
    setSales(s2);
    showSales(s2);

    return 0;
}