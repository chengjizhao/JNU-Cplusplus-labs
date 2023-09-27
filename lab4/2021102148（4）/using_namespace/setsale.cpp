/*
doubles sales[QUARTERS];
void setSales( int n);
void showSales();
*/

#include "SALE.h"
#include <iostream>
using namespace std;
namespace SALES
{

	void Sales::setSales(int n)
	{
		cout << "输入第" << n + 1 << "个季度的销售额:";
		cin >> Sales::sales[n];
		cout << "数据已存入!" << endl;
	}

	void Sales::showSales()
	{
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "第" << i + 1 << "个季度的销售额为：" << Sales::sales[i] << endl;
		}
		}
}
