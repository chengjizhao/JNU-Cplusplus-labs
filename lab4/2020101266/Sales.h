#pragma once
#ifndef SALES_H  
#define SALES_H  

#include <iostream>  

namespace SALES {
    const int QUARTERS = 4;

    struct Sales {
        double sales[QUARTERS];
        double max, min;

        void setSales(const double ar[], int n);
        void setSales();
        void showSales() const;
    };
} // namespace SALES  

#endif // SALES_H
