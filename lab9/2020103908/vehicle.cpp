#include <iostream>

// 基类 Vehicle
class Vehicle {
public:
    int speed;
    Vehicle(int s) : speed(s) {}

    virtual void start() {
        std::cout << "Vehicle is starting." << std::endl;
    }
};

// 派生类 Car，虚继承自 Vehicle
class Car : virtual public Vehicle {
public:
    Car(int s) : Vehicle(s) {}

    void start() override {
        std::cout << "Car is starting." << std::endl;
    }
};

// 派生类 Boat，虚继承自 Vehicle
class Boat : virtual public Vehicle {
public:
    Boat(int s) : Vehicle(s) {}

    void start() override {
        std::cout << "Boat is starting." << std::endl;
    }
};

// 类 AmphibiousVehicle，同时继承自 Car 和 Boat
class AmphibiousVehicle : public Car, public Boat {
public:
    AmphibiousVehicle(int carSpeed, int boatSpeed)
        : Vehicle(0), Car(carSpeed), Boat(boatSpeed) {}

    void start() override {
        std::cout << "AmphibiousVehicle is starting." << std::endl;
        Car::start(); // 显示调用 Car 的 start() 函数
        Boat::start(); // 显示调用 Boat 的 start() 函数
    }
};

int main() {
    AmphibiousVehicle amphibious(60, 20);
    amphibious.start();

    return 0;
}
