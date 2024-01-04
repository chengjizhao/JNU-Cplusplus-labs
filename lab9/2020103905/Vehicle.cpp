#include <iostream>

// 基类 Vehicle
class Vehicle {
public:
    int speed;

    virtual void start() {
        std::cout << "Vehicle started." << std::endl;
    }
};

// 派生类 Car
class Car : virtual public Vehicle {
public:
    void start() override {
        std::cout << "Car started." << std::endl;
    }
};

// 派生类 Boat
class Boat : virtual public Vehicle {
public:
    void start() override {
        std::cout << "Boat started." << std::endl;
    }
};

// 多继承类 AmphibiousVehicle
class AmphibiousVehicle : public Car, public Boat {
public:
    void start() override {
        Car::start();   // 调用 Car 的 start()
        Boat::start();  // 调用 Boat 的 start()
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle;
    amphibiousVehicle.start();

    return 0;
}