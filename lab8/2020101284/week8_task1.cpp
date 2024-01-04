#include <iostream>

// 基类 Car
class Car {
protected:
    double basePrice;  // 基本价格

public:
    Car(double price) : basePrice(price) {}

    virtual double calculatePrice() {
        return basePrice;
    }
};

// 派生类 Sedan
class Sedan : public Car {
public:
    Sedan(double price) : Car(price) {}

    double calculatePrice() override {
        // 假设 Sedan 类的价格是基本价格的 1.5 倍
        return basePrice * 1.5;
    }
};

// 派生类 SUV
class SUV : public Car {
public:
    SUV(double price) : Car(price) {}

    double calculatePrice() override {
        // 假设 SUV 类的价格是基本价格的 2 倍
        return basePrice * 2;
    }
};

int main() {
    Car* car1 = new Sedan(10000.0);
    Car* car2 = new SUV(20000.0);

    std::cout << "Sedan price: $" << car1->calculatePrice() << std::endl;
    std::cout << "SUV price: $" << car2->calculatePrice() << std::endl;

    delete car1;
    delete car2;

    return 0;
}