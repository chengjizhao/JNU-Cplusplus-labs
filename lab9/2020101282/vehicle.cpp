#include <iostream>

// 基类 Vehicle
class Vehicle {
public:
    Vehicle(int speed) : speed(speed) {}

    virtual void start() {
        std::cout << "Vehicle starts." << std::endl;
    }

protected:
    int speed;
};

// 派生类 Car
class Car : virtual public Vehicle {
public:
    Car(int speed) : Vehicle(speed) {}

    void start() override {
        std::cout << "Car starts." << std::endl;
    }
};

// 派生类 Boat
class Boat : virtual public Vehicle {
public:
    Boat(int speed) : Vehicle(speed) {}

    void start() override {
        std::cout << "Boat starts." << std::endl;
    }
};

// 派生类 AmphibiousVehicle，使用虚继承
class AmphibiousVehicle : public Car, public Boat {
public:
    AmphibiousVehicle(int carSpeed, int boatSpeed) : Car(carSpeed), Boat(boatSpeed), Vehicle(carSpeed + boatSpeed) {}

    // 解决菱形继承问题，重新实现 start() 函数
    void start() override {
        std::cout << "AmphibiousVehicle starts." << std::endl;
    }
};

int main() {
    // 创建 AmphibiousVehicle 对象并演示虚继承
    AmphibiousVehicle amphibiousVehicle(50, 30);

    // 调用 AmphibiousVehicle 的 start() 函数
    amphibiousVehicle.start();

    // 调用 Car 的 start() 函数
    amphibiousVehicle.Car::start();

    // 调用 Boat 的 start() 函数
    amphibiousVehicle.Boat::start();

    // 调用基类 Vehicle 的 start() 函数
    amphibiousVehicle.Vehicle::start();

    return 0;
}
