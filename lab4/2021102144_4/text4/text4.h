#pragma once
namespace SALES 
{ 
const int QUARTERS =4;
struct Sales
{
double sales[QUARTERS];
double max,min;
void setSales(int a, const double ar[], int n);
void getSales(int a);
void showSales(const Sales& s);
};
}
