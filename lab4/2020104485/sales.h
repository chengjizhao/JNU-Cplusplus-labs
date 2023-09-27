//
//  sales.h
//  sales
//
//  Created by mac on 2023/9/21.
//

#ifndef sales_h
#define sales_h
 namespace SALES {
 const int QUARTERS =4;

 struct Sales {
 double sales[QUARTERS];
 double max;
 double min;

 void setSales(Sales& s, const double ar[], int n);
 void setSales(Sales& s);
 void showSales(const Sales& s);
 };

}

#endif /* sales_h */
