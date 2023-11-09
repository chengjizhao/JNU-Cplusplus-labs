#include <iostream>
using namespace std;

// 基类 Vehicle
class Vehicle {
public:
    int speed;

    virtual void start() {
        cout << "Vehicle starts" << endl;
    }
};

// 派生类 Car
class Car : virtual public Vehicle {
public:
    void start() override {
        cout << "Car starts" << endl;
    }

    // Car 特有的方法
    void drive() {
        cout << "Car is driving" << endl;
    }
};

// 派生类 Boat
class Boat : virtual public Vehicle {
public:
    void start() override {
        cout << "Boat starts" << endl;
            }

    // Boat 特有的方法
    void sail() {
        cout << "Boat is sailing" << endl;
    }
};

// 多继承类 AmphibiousVehicle
class AmphibiousVehicle : public Car, public Boat {
public:
    void start() override {
        Car::start(); // 调用 Car 的 start 方法
        Boat::start(); // 调用 Boat 的 start 方法
        cout << "AmphibiousVehicle starts" << endl;
    }
};

// 主函数
int main() {
    AmphibiousVehicle av;
    av.start(); // 调用 AmphibiousVehicle 的 start 方法
    av.drive(); // 调用 Car 的 drive 方法
    av.sail(); // 调用 Boat 的 sail 方法

    return 0;
}
