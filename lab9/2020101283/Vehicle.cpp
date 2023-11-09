#include <iostream>

// 基类 Vehicle
class Vehicle {
public:
    int speed;
    virtual void start() {
        std::cout << "Vehicle Start" << std::endl;
    }
};

// 派生类 Car
class Car : virtual public Vehicle {
public:
    void start() override {
        std::cout << "Car Start" << std::endl;
    }
};

// 派生类 Boat
class Boat : virtual public Vehicle {
public:
    void start() override {
        std::cout << "Boat Start" << std::endl;
    }
};

// 菱形继承，同时继承自Car和Boat
class AmphibiousVehicle : public Car, public Boat {
public:
    // 可以覆盖start()函数
};

int main() {
    AmphibiousVehicle amphibiousVehicle;
    amphibiousVehicle.start();  // 此处会调用Car的start()函数

    return 0;
}
//虚继承可以消除菱形继承所带来的二义性和冗余问题。当一个类通过虚继承从多个共同基类派生时，最终派生类只会包含一个基类的实例。因此，只有一份共同基类的成员变量和函数。这样可以避免在派生类中出现多份基类对象，从而解决了菱形继承可能导致的二义性和冗余问题。
