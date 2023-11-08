#include <iostream>

// 定义基类 Vehicle
class Vehicle {
public:
    int speed;

    virtual void start() {
        std::cout << "Vehicle started" << std::endl;
    }
};

// 定义派生类 Car
class Car : virtual public Vehicle {
public:
    void start() override {
        std::cout << "Car started" << std::endl;
    }
};

// 定义派生类 Boat
class Boat : virtual public Vehicle {
public:
    void start() override {
        std::cout << "Boat started" << std::endl;
    }
};

// 定义多继承类 AmphibiousVehicle
class AmphibiousVehicle : public Car, public Boat {
public:
    void start() override {
        Car::start(); // 显示调用 Car 类的 start 函数
        Boat::start(); // 显示调用 Boat 类的 start 函数
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle;
    amphibiousVehicle.start();

    return 0;
}

/*在上述代码中，使用了 virtual public Vehicle 来在 Car 和 Boat 类中虚继承 Vehicle。这样做可以确保只有一个 Vehicle 的实例被共享，从而解决了菱形继承问题。*/