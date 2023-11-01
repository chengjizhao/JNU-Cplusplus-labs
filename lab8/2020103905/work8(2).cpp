#include <iostream>

class Car {
protected:
    double price;

public:
    Car(double p) : price(p) {}

    virtual double calculatePrice() {
        return price;
    }
};

class Sedan : public Car {
public:
    Sedan(double p) : Car(p) {}

    double calculatePrice() override {
        // 根据 Sedan 类型的汽车计算价格的特定逻辑
        return price * 1.2; // 假设 Sedan 的价格比基础价格高20%
    }
};

class SUV : public Car {
public:
    SUV(double p) : Car(p) {}

    double calculatePrice() override {
        // 根据 SUV 类型的汽车计算价格的特定逻辑
        return price * 1.5; // 假设 SUV 的价格比基础价格高50%
    }
};

int main() {
    Car* car1 = new Sedan(10000.0);
    Car* car2 = new SUV(20000.0);

    std::cout << "Car 1 price: " << car1->calculatePrice() << std::endl;
    std::cout << "Car 2 price: " << car2->calculatePrice() << std::endl;

    delete car1;
    delete car2;

    return 0;
}