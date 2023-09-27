#include <iostream>
#include "sales.h"

using namespace std;

namespace SALES
{
	void setSales(Sales& s, const double ar[], int n)
	{
		s.max = 0;
		s.min = ar[0];
		for (int i = 0; i < n; ++i)
		{
			s.sales[i] = ar[i];
			if (s.sales[i] > s.max)
				s.max = s.sales[i];
			if (s.sales[i] < s.min)
				s.min = s.sales[i];
		}

	}

	void setSales(Sales& s)
	{
		for (int i = 0; i < QUARTERS; ++i)
		{
			cout << "请输入第" << i+1 << "个季度的业绩为";
			cin >> s.sales[i];
			cout << "数据录入完毕";
			if (s.sales[i] > s.max)
				s.max = s.sales[i];
			if(i==0)
				s.min = s.sales[i];
			if(s.sales[i] < s.min)
				s.min = s.sales[i];

		}

	}

	void showSales(const Sales& s)
	{
		for (int i = 0; i < QUARTERS; ++i)
		{
			cout << "第" << i + 1 << "个季度销售额为";
			cout << s.sales[i];
			std::cout << "销售业绩最高为: " << s.max << std::endl;
			std::cout << "销售业绩最低为: " << s.min << std::endl;
		}
	}
}

