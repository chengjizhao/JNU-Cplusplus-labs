#include "SALE.h"
#include <iostream>
using namespace std;
using namespace SALES;

struct Sales s1;
// struct Sales s2;
int main()
{

	// 输入四个季度的销售额
	for (int n = 0; n < QUARTERS; n++)
	{
		s1.setSales(n);
	}
	// 展示
	s1.showSales();

	return 0;
}
