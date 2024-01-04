#include <iostream>

// 基类 Vehicle
class Vehicle {
public:
    int speed;
    virtual void start() {
        std::cout << "Vehicle started" << std::endl;
    }
};

// 派生类 Car
class Car : virtual public Vehicle {
public:
    void drive() {
        std::cout << "Car driving" << std::endl;
    }
};

// 派生类 Boat
class Boat : virtual public Vehicle {
public:
    void sail() {
        std::cout << "Boat sailing" << std::endl;
    }
};

// 菱形继承类 AmphibiousVehicle
class AmphibiousVehicle : public Car, public Boat {
public:
    // 实现 start 函数以解决菱形继承问题
    void start() override {
        Car::start();  // 使用 Car 中的 start 函数
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle;
    amphibiousVehicle.drive();
    amphibiousVehicle.sail();
    amphibiousVehicle.start();

    return 0;
}
