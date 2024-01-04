#include<iostream>
using namespace std;

class Car
{
    public:
    int price;
    virtual void calculatePrice(int n)
    {
        cout << "chose your car's type, SUV or Sedan ."<< endl;
    }
};

class SUV : public Car
{
    public:
    virtual void calculatePrice(int n)
    {
        Car::price=n;
        cout << "the price of SUV is " << Car::price  <<endl;
    }
};
class Sedan : public Car
{
    public:
    virtual void calculatePrice(int n)
    {
        Car::price=n*2;
        cout << "the price of Sedan is " << Car::price  << endl;
    }
};

int main()
{
    Car *p = new SUV();
    Car *q = new Sedan();
    Car car;
    car.calculatePrice(50);
    p->calculatePrice(50);
    q->calculatePrice(50);
    return 0;
}