#include <iostream>

// 基类 Car
class Car {
public:
    virtual double calculatePrice() const {
        return 0.0;
    }
};

// 派生类 Sedan
class Sedan : public Car {
public:
    double calculatePrice() const override {
        return 30000.0;
    }
};

// 派生类 SUV
class SUV : public Car {
public:
    double calculatePrice() const override {
        return 40000.0;
    }
};

int main() {
    Car* car1 = new Sedan();
    Car* car2 = new SUV();

    std::cout << "Price of Sedan: $" << car1->calculatePrice() << std::endl;
    std::cout << "Price of SUV: $" << car2->calculatePrice() << std::endl;

    delete car1;
    delete car2;

    return 0;
}