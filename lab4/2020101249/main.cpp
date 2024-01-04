#include <iostream>
#include "Sales.h"

using SALES::Sales;
using std::cout;

const double ar[] = { 100, 200, 100 };

int main()
{
	Sales s1, s2;
	SALES::setSales(s1);
	SALES::setSales(s2, ar, 3);
	SALES::showSales(s1);
	cout << '\n';
	SALES::showSales(s2);
	return 0;
}