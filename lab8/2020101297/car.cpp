#include <iostream>

//Car
class Car {
protected:
    double basePrice;  // 基本价格

public:
    Car(double price) : basePrice(price) {}

    virtual double calculatePrice() {
        return basePrice;
    }
};

//Sedan
class Sedan : public Car {
public:
    Sedan(double price) : Car(price) {}

    double calculatePrice() override {
        return basePrice * 3;
    }
};

//SUV
class SUV : public Car {
public:
    SUV(double price) : Car(price) {}

    double calculatePrice() override {
        return basePrice * 4;
    }
};

int main() {
    Car* car1 = new Sedan(60000.0);
    Car* car2 = new SUV(128000.0);

    std::cout << "Sedan price: $" << car1->calculatePrice() << std::endl;
    std::cout << "SUV price: $" << car2->calculatePrice() << std::endl;

    delete car1;
    delete car2;

    return 0;
}