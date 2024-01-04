#include<iostream>
#include"Sale.h"
using namespace std;
namespace SALES
{
    void setSales(Sales &s,const double ar[],int n){
        double sum=0.0;
        s.max=ar[0];
        s.min=ar[0];
        if (n<QUARTERS){
            for(int i=0;i<n;i++){
                s.sales[i]=ar[i];
                if(s.max<s.sales[i]){
                    s.max=s.sales[i];
                }
                if(s.min>s.sales[i]){
                    s.min=s.sales[i];
                }
                sum=sum+s.sales[i];
            }
            s.average=sum/4;
        }
        else{
            for(int i=0;i<QUARTERS;i++){
                s.sales[i]=ar[i];
                if(s.max<s.sales[i]){
                    s.max=s.sales[i];
                }
                if(s.min>s.sales[i]){
                    s.min=s.sales[i];
                }
                sum=sum+s.sales[i];
            }
            s.average=sum/4;
        }
    }

    void setSales(Sales &s)
    {
        cout << "请输入Sales元素:" << endl << "sales[0]:";
        cin >> s.sales[0];
        s.max=s.sales[0];
        s.min=s.sales[0];
        double sum;
        for (int i=1;i<QUARTERS;i++){
            cout << "sales[" << i << "]:";
            cin >> s.sales[i];
            if(s.max<s.sales[i]){
                s.max=s.sales[i];
            }
            if(s.min>s.sales[i]){
                s.min=s.sales[i];
            }
            sum=sum+s.sales[i];
        }
        s.average=sum/4;
    }

    void showSales(const Sales &s)
    {
        for(int i=0;i<QUARTERS;i++){
            cout << " sales[" << i << "] :" << s.sales[i] << " ,";
        }
        cout << endl << "最高销售业绩: " << s.max << " ," << "最低销售业绩: " << s.min << " ," << "平均销售业绩: " << s.average << endl;
    }
}