#include "sales.h"
using namespace SALES;
using namespace std;

int main() {
    Sales s1;
    double salesData[] = { 1000.0, 2000.0, 1500.0, 2500.0 };

    setSales(s1, salesData, sizeof(salesData) / sizeof(double));
    showSales(s1);

    Sales s2;
    setSales(s2);
    showSales(s2);

    return 0;
}