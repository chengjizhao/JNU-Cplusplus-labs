#include<iostream>
using namespace std;

class Car{
public:
    virtual int calculatePrice() { return 100; }
};

class Sedan : public Car{
public:
    virtual int calculatePrice(){
        return 100*4000;
    }
};

class SUV : public Car{
public:
    virtual int calculatePrice(){
        return 100*1500;
    }
};

class BMW : public Car{
public:
    virtual int calculatePrice(){
        return 100*2000;
    }
};

int main()
{
    Car* car1 = new Car;
    Car* car2 = new Sedan;
    Car* car3 = new SUV;
    Car* car4 = new BMW;
    cout<<"car1's price : "<<car1->calculatePrice()<<endl;
    cout<<"car2's price : "<<car2->calculatePrice()<<endl;
    cout<<"car3's price : "<<car3->calculatePrice()<<endl;
    cout<<"car4's price : "<<car4->calculatePrice()<<endl;
    return 0;
}