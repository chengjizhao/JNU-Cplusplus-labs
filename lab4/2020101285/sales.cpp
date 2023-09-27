#include"sales.h"


void SALES::setSales(Sales &s,const double ar[] ,int n)
{   
    double max=ar[0],min=ar[0];/*
    if(n>4){
        n=4;
    }*/
    double sum=0;
    for (int i=0 ; i < n; i++)
    {
        s.sales[i]=ar[i];
        sum += ar[i];
        if (ar[i]>max)
            max = ar[i];
        if (ar[i] < min)
            min = ar[i];           
    }
    s.average = sum/n;
    s.max=max;
    s.min=min;   
}

void SALES::setSales(Sales &s)
{   
    double input_num;
    std::cout<<"input four numbers for sales : ";
    for (int i = 0; i < QUARTERS; i++)
    {
        std::cin>>input_num;
        s.sales[i] = input_num;
    }
    double max=s.sales[0],min=s.sales[0];
    double sum = 0;
    for (int i=0 ; i < QUARTERS; i++)
    {
        sum += s.sales[i];
        if (s.sales[i]>max)
            max = s.sales[i];
        if (s.sales[i] < min)
            min = s.sales[i];      
    }   
    s.max = max;
    s.min = min;
    s.average = sum/QUARTERS;
}

void SALES::showSales(const Sales& s)
{
    std::cout<<"\tSales is: ";
    for (int i = 0; i < QUARTERS; i++)
    {
        std::cout<<s.sales[i]<<" ";
    }
    std::cout<<std::endl<<"\tmax Sales is "<<s.max<<std::endl;
    std::cout<<"\tmin Sales is "<<s.min<<std::endl;
    std::cout<<"\taverage Sales is "<<s.average<<std::endl;
    
}