#include <iostream>

using namespace std;

class Car
{
private:
    int price_;
public:
    Car(int price):
        price_(price)
        {}
    
    void printPrice()
    {
        cout << price_ << endl;
    }

    virtual void calculatePrice()
    {
        cout << "this is base class's func." << endl;
        printPrice();
    }
};

class Sedan: public Car
{
private:
public:
    Sedan(int price):
        Car(price)
        {}

    void calculatePrice() override
    {
        cout << "this func has been overrided by Sedan." << endl;
        printPrice();
    }
};

class SUV: public Car
{
private:
public:
    SUV(int price):
        Car(price)
        {}

    void calculatePrice() override
    {
        cout << "this func has been overrided by SUV." << endl;
        printPrice();
    }
};


int main()
{
    Car* auto1 = new Car(1000);
    Car* auto2 = new Sedan(2000);
    Car* auto3 = new SUV(3000);

    auto1->calculatePrice();
    cout << endl;
    auto2->calculatePrice();
    cout << endl;
    auto3->calculatePrice();

    delete auto1;
    delete auto2;
    delete auto3;
    return 0;
}