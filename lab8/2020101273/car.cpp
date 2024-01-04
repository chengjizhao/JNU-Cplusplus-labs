#include <iostream>
using std::cout,std::endl;
class Car{
public:
    virtual double calculatePrice(){
        return 0;
    }
};

class Sedan : public Car{
public:
    double calculatePrice() override {
        //cout << "Sedan汽车价格" << endl;
        return 300000;
    }
};

class SUV : public Car{
public:
    double calculatePrice() override {
        //cout << "SUV汽车价格" << endl;
        return 200000;
    }
};

int main(){
    Car* car1 = new Sedan();
    Car* car2 = new SUV();

    cout << "Sedan price:" 
    << car1->calculatePrice() 
    << "$"
    << endl;

    cout << "SUV price:" 
    << car2->calculatePrice()
    << "$" 
    << endl;

    delete car1;
    delete car2;
}