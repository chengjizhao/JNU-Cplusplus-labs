#include"lab8.h"
void Sedan::calculatePrice(int a,string b)
{
    this->price=a;this->name=b;
    cout << this->price <<endl << this->name;
}


void Suv::calculatePrice(int a,string b)
{
    this->price=a;this->name=b;
    cout << this->price <<endl << this->name;
}

void Car::calculatePrice(int a, string b)
{
    cout << "car";
}
void Car::a()
{
    cout << "a";
}
int main()
{
    Suv a;Sedan b;
    a.calculatePrice(10,"SUV");
    b.calculatePrice(15,"Sedan");
    
    

}