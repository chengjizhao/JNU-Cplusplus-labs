#ifndef _SALE_H_//±‹√‚÷ÿ∏¥…˘√˜
#define _SALE_H_

namespace SALES
{
	const int QUARTERS = 4;
	struct Sales
	{
		double sales[QUARTERS];
		double max, min;
	};
	void setSales(Sales& s, const double ar[], int n);
	void setSales(Sales& s);
	void showSales(const Sales& s);
}

#endif 

