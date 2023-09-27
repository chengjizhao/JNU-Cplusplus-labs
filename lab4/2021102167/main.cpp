#include "sales.h"
using namespace SALES;

int main()
{

	Sales s1, s2;
	const double ar[] = { 888.11,777.22,555.33,666.44 };
	setSales(s1, ar, 4);
	showSales(s1);
	setSales(s2);
	showSales(s2);
	return 0;
}
