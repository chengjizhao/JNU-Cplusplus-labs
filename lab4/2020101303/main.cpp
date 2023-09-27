#include "sales.h"
#include <iostream>
using namespace SALES;
using namespace std;
int main() {
    Sales s1, s2;
    double salesData[] = {1000, 2500.15, 3000.25, 1500.35, 2000.45, 3500.55};
    setSales(s1, salesData, 4);
    showSales(s1);
    cout << endl;
    setSales(s2);
    showSales(s2);
    return 0;
}