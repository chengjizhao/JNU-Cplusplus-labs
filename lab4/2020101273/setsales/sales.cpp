#include "sales.h"

namespace SALES 
{  
    void Sales::setSales(const double ar[], int num) 
    {  
        max = ar[0];  
        min = ar[0];  
        average = 0;sum=0;

        for (int i = 0; i < num; ++i) 
        {  
            sales[i] = ar[i];  
            if (sales[i] > max) 
            {  
                max = sales[i];  
            }  
            if (sales[i] < min) 
            {  
                min = sales[i];  
            }  
            sum += sales[i];
            
        }  average = sum / num;
    }

    void Sales::setSales() 
    {  
        double ar[QUARTERS];
        cout << "选择业绩个数m:";
        cin >> m;
        if(m < QUARTERS)
        {chu = m;}
        else{chu = QUARTERS;}
        cout << "Enter " << chu << " sales: ";  
        for (int i = 0; i < chu; ++i) 
        {  
            cin >> ar[i];  
        }  
        setSales(ar, chu);  
    }

    void Sales::showSales(const Sales& s) 
    {  
        cout << "Sales: ";  
        for (int i = 0; i < QUARTERS; ++i) {  
            cout << sales[i] << (i == QUARTERS - 1 ? '\n' : ',');  
        }  
        cout << "Max: " << max << ", Min: " << min << ", Average: " << average << endl;  
    }  
}