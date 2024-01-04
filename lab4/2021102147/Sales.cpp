#include "Sales.h"

#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::max;
using std::min;

double Average(double a[], int n)
{
	double sum = 0;
	for(int i = 0; i < n; ++i)
	{
		sum += a[i];
	}
	return sum/n;
}

void SALES::setSales(SALES::Sales &s) {
	s.max = 0;
	s.min = 2147483647;
	cout << "Please input sales: ";
	for(int i = 0; i < 4; ++i)
	{
		cin >> s.sales[i];
		s.max = max(s.max,s.sales[i]);
		s.min = min(s.min,s.sales[i]);
	}
	s.average = Average(s.sales, 4);
};

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
	
	while(i < 4)s.sales[i++] = 0; 

	s.average = Average(s.sales, n);
}

void SALES::showSales(const SALES::Sales &s)
{
	cout << "Sales: ";
	for(int i = 0; i < 4; ++i)
	{
		cout << s.sales[i] << ' ';
	}
	cout << '\n';
	cout << "max: " << s.max << '\n';
	cout << "min: " << s.min << '\n';
	cout << "average: " << s.average << '\n';
}
