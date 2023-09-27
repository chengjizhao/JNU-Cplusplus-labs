#ifndef SALES_H
#define SALES_H
namespace SALES 
{ 
const int QUARTERS =4;
}
struct Sales 
{
double sales[SALES::QUARTERS];//数组
double max,min,average;
void setSales(Sales &s, const double ar[], int n);
void getSales(Sales &s);
void showSales(const Sales &s);
};

#endif