
#include <iostream>
#include "SALES.h"

void SALES::setSales(SALES::Sales &s, const double ar[], int n)
{
    double ma, mi, ad;
    ma = mi = ad = s.sales[0] = ar[0];
    n = std::min(n, 4);
    for (int i = 1; i < n; i++)
    {
        s.sales[i] = ar[i];
        if (ar[i] > ma)
            ma = ar[i];
        if (ar[i] < mi)
            mi = ar[i];
        ad += ar[i];
    }
    s.average = ad / 4;
    s.max = ma;
    s.min = mi;
}

void SALES::setSales(SALES::Sales &s)
{
    double ma, mi, ad;
    int n;
    std::cout << "请输入业绩个数：";
    std::cin >> n;
    if (n > 4)
        n = 4;
    std::cout << "请输入" << n << "个季度的业绩：";
    std::cin >> s.sales[0];
    ma = mi = ad = s.sales[0];
    for (int i = 1; i < n; i++)
    {
        std::cin >> s.sales[i];
        if (s.sales[i] > ma)
            ma = s.sales[i];
        if (s.sales[i] < mi)
            mi = s.sales[i];
        ad += s.sales[i];
    }
    s.average = ad / 4;
    s.max = ma;
    s.min = mi;
}

void SALES::showSales(const SALES::Sales &s)
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << s.sales[i] << "0";
    }
}