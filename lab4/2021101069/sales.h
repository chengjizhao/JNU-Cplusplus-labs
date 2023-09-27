#ifndef SALES_H  
#define SALES_H  
  
namespace SALES   
{   
const int QUARTERS = 4;  
  
struct Sales {  
    double sales[QUARTERS];  
    double max, min;  
  
    void setSales(const double ar[], int n);  
    void showSales();  
};  
  
} // namespace SALES  
  
#endif // SALES_H