#include <iostream>
#include <string>

// 定义汽车基类
class Car {
public:
    Car(const std::string& make, const std::string& model, int year)
        : make(make), model(model), year(year) {}

    // 定义虚函数 calculatePrice
    virtual double calculatePrice() const {
        return 0.0;
    }

protected:
    std::string make;
    std::string model;
    int year;
};

// 定义 Sedan 类，继承自 Car
class Sedan : public Car {
public:
    Sedan(const std::string& make, const std::string& model, int year, int trunkSize)
        : Car(make, model, year), trunkSize(trunkSize) {}

    // 覆盖 calculatePrice 函数以计算 Sedan 的价格
    double calculatePrice() const override {
        double basePrice = 20000.0;
        return basePrice + (year - 2023) * 1000 + trunkSize * 50;
    }

private:
    int trunkSize;
};

// 定义 SUV 类，继承自 Car
class SUV : public Car {
public:
    SUV(const std::string& make, const std::string& model, int year, int passengerCapacity)
        : Car(make, model, year), passengerCapacity(passengerCapacity) {}

    // 覆盖 calculatePrice 函数以计算 SUV 的价格
    double calculatePrice() const override {
        double basePrice = 25000.0;
        return basePrice + (year - 2023) * 1200 + passengerCapacity * 100;
    }

private:
    int passengerCapacity;
};

int main() {
    Sedan sedan("Toyota", "Camry", 2024, 15);
    SUV suv("Ford", "Explorer", 2023, 7);

    std::cout << "价格: Sedan - $" << sedan.calculatePrice() << ", SUV - $" << suv.calculatePrice() << std::endl;

    return 0;
}
