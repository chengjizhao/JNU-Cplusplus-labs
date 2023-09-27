#include "sales.h"  
#include <iostream>  
#include <algorithm>  
#include <cmath>
#include <numeric>
  
using namespace SALES;  
using namespace std;

double Average(double a[], int n)
{
	double sum = 0;
	for(int i = 0; i < n; ++i)
	{
		sum += a[i];
	}
	return sum/n;
}
 
void SALES::setSales(SALES::Sales &s, const double ar[], int n)
{
	s.max = 0;
	s.min = 2147483647;
	int i;
	for(i = 0; i < n; ++i)
	{
		s.sales[i] = ar[i];
		s.max = max(s.max,ar[i]);
		s.min = min(s.min,ar[i]);
	} 

	s.average = Average(s.sales, n);
}

void setSales(Sales &s) {  
    std::cout << "Please enter sales for 4 quarters: ";  
    for (int i = 0; i < QUARTERS; ++i) {  
        std::cin >> s.sales[i];  
    }  
    s.max=0;
    s.min=2147483647;
    int n=4;
   for(int i=0;i<n;++i)
   {
    s.max = max(s.max,s.sales[i]);
    s.min = min(s.min,s.sales[i]); 
   }
   s.average = Average(s.sales, n);
}  
  
void showSales(const Sales& s) {  
    std::cout << "Sales: ";  
    for (int i = 0; i < QUARTERS; ++i) {  
        std::cout << s.sales[i] << " ";  
    }  
    std::cout << "\nMax: " << s.max << "\nMin: " << s.min << "\nAverage: " << s.average << std::endl;  
}