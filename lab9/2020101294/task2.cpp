#include <iostream>

// 基类 Vehicle
class Vehicle {
protected:
    int speed;

public:
    Vehicle(int spd) : speed(spd) {}

    virtual void start() {
        std::cout << "Vehicle started." << std::endl;
    }
};

// 派生类 Car
class Car : virtual public Vehicle {
public:
    Car(int spd) : Vehicle(spd) {}

    void start() override {
        std::cout << "Car started. Speed: " << speed << " km/h." << std::endl;
    }
};

// 派生类 Boat
class Boat : virtual public Vehicle {
public:
    Boat(int spd) : Vehicle(spd) {}

    void start() override {
        std::cout << "Boat started. Speed: " << speed << " knots." << std::endl;
    }
};

// 派生类 AmphibiousVehicle 同时继承自 Car 和 Boat
class AmphibiousVehicle : public Car, public Boat {
public:
    AmphibiousVehicle(int carSpeed, int boatSpeed) : Vehicle(carSpeed), Car(carSpeed), Boat(boatSpeed) {}

    // 实现虚函数 start 来解决菱形继承问题
    void start() override {
        std::cout << "AmphibiousVehicle started. Car Speed: " << Car::speed << " km/h, Boat Speed: " << Boat::speed << " knots." << std::endl;
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle(60, 30);

    // 演示菱形继承问题和解决方法
    amphibiousVehicle.start();

    return 0;
}