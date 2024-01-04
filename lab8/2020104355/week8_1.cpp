#include <iostream>
class Car
{
    protected:
    double basePrice;
    public:
    Car(double price) : basePrice(price){}
    virtual double calculatePrice()
    {
        return basePrice;
    }
};

class Sedan : public Car
{
    public:
    Sedan(double price) : Car(price){}
    double calculatePrice() override{
        return basePrice*1.5;
    }
};

class SUV : public Car
{
    public:
    SUV (double price) : Car(price){}
    double calculatePrice() override{
        return basePrice*2;
    }
};
int main()
{
    Car*car1=new Sedan(10000.0);
    Car*car2=new SUV(20000.0);
    std::cout << "Sedan price : $" << car1->calculatePrice() << std::endl;
    std::cout << "SUV price : $" << car2->calculatePrice() << std::endl;
    delete car1;
    delete car2;
    return 0;
}