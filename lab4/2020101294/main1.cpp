#include <iostream>
#include "SALES.h"
using namespace std;

void main1()
{
	using SALES::Sales;
	Sales s1;
	Sales s2;
	double arr[7]={5.2,6.3,4.1,2.5,3.0,4.2,7.5};
	using SALES::setSales;
	setSales(s1,arr,6);
	showSales(s1);
	setSales(s2);
	showSales(s2);
	system("pause");
}
