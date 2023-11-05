#include"car.h"
#include<iostream>
using namespace std;

int main()
{
    Sedan Sedan;
    SUV SUV;
    cout<<"price of Sedan:"<<Sedan.calculatePrice()<<endl;
    cout<<"price of SUV:"<<SUV.calculatePrice()<<endl;
    return 0;
}