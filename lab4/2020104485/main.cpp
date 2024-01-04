 #include "sales.h"
int main() {
 SALES::Sales s1, s2;

 double ar[] = {1000,2000,1500,1800};
 s1.setSales(s1, ar, SALES::QUARTERS);

 s2.setSales(s2);
    
 s1.showSales(s1);
 s2.showSales(s2);

 return 0;
}
