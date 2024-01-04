#include "Sales.h"
using namespace SALES;
int max = 0;
 
int main()
{
	Sales ann;
	Sales andy;
	double sales[4] = { 1,3,5,7 };
 
	setSales(ann, sales, 4);
	setSales(andy);
 
	showSales(ann);
	showSales(andy);
	return 0;
 
}
