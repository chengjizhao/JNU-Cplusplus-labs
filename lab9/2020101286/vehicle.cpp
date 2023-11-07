#include <iostream>

// 基类 Vehicle
class Vehicle {
protected:
    int speed;

public:
    Vehicle(int s) : speed(s) {}

    virtual void start() {
        std::cout << "Starting the vehicle" << std::endl;
    }
};

// 派生类 Car
class Car : virtual public Vehicle {
public:
    Car(int s) : Vehicle(s) {}

    void start() override {
        std::cout << "Starting the car" << std::endl;
    }
};

// 派生类 Boat
class Boat : virtual public Vehicle {
public:
    Boat(int s) : Vehicle(s) {}

    void start() override {
        std::cout << "Starting the boat" << std::endl;
    }
};

// 虚继承解决菱形继承问题的类 AmphibiousVehicle
class AmphibiousVehicle : public Car, public Boat {
public:
    AmphibiousVehicle(int s) : Vehicle(s), Car(s), Boat(s) {}

    void start() override {
        std::cout << "Starting the amphibious vehicle" << std::endl;
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle(100);
    amphibiousVehicle.start();

    return 0;
}
