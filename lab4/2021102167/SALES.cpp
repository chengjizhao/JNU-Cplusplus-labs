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
			cout << "�������" << i+1 << "�����ȵ�ҵ��Ϊ";
			cin >> s.sales[i];
			cout << "����¼�����";
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
			cout << "��" << i + 1 << "���������۶�Ϊ";
			cout << s.sales[i];
			std::cout << "����ҵ�����Ϊ: " << s.max << std::endl;
			std::cout << "����ҵ�����Ϊ: " << s.min << std::endl;
		}
	}
}

