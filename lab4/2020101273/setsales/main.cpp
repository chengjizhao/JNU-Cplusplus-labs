#include "sales.h"

int main() 
{  
    SALES::Sales s1, s2;  
    double ar1[] = {1000, 1500, 1200, 1800, 2000, 1600,1300, 1900};  
    double ar2[SALES::QUARTERS];
    
    for (int i = 0; i < sizeof(ar1)/sizeof(ar1[0]); ++i) 
    {  
        cout << ar1[i] << (i == sizeof(ar1)/sizeof(ar1[0]) - 1 ? '\n' : ',');  
    }
    cout <<"选出不多于4个业绩" << endl;
    s1.setSales();  
    s1.showSales(s1);  

    std::cout << "Enter 4 sales for s2: ";  
    for (int i = 0; i < 4; ++i) {  
        std::cin >> ar2[i];  
    }  
    s2.setSales(ar2, 4);  
    s2.showSales(s2);

    return 0;  
}