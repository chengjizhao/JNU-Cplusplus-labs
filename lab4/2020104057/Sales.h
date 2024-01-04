#pragma once

namespace SALES
{
	const int QUARTERS = 4;
	struct Sales 
  {
		double sales[QUARTERS];
		double max,min,average;
	};
	void setSales(Sales &s);
	void setSales(Sales &s, const double ar[], int n);
	void showSales(const Sales &s);

}
