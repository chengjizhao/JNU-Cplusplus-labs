#include<iostream>
#include"sales.h"

using namespace std;
using namespace SALES;

int main()
{
    Sales sale1;
    Sales sale2;
    cout<<"step1: creat two Sales: sale1,sale2."<<endl;
    double buffer[6]={100 , 120.5 , 98 , 110.2 , 230 , 125};
    cout<<"step2.1: put datas{100 , 120.5 , 98 , 110.2 , 230 , 125} to Sales1: "<<endl;
    setSales(sale1 , buffer , 6);
    cout<<"step2.2: show sale1"<<endl;
    showSales(sale1);
    cout<<"step3.1: input data to sale2 by keyboard."<<endl;
    setSales(sale2);
    cout<<"step3.2: show sale2"<<endl;
    showSales(sale2);
    return 0;
}