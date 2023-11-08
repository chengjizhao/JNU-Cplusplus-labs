#include <iostream>

// ���� Vehicle
class Vehicle {
public:
    int speed;

    virtual void start() {
        std::cout << "Vehicle started." << std::endl;
    }
};

// ������ Car
class Car : virtual public Vehicle {
public:
    void start() override {
        std::cout << "Car started." << std::endl;
    }
};

// ������ Boat
class Boat : virtual public Vehicle {
public:
    void start() override {
        std::cout << "Boat started." << std::endl;
    }
};

// ��̳��� AmphibiousVehicle
class AmphibiousVehicle : public Car, public Boat {
public:
    void start() override {
        Car::start();   // ���� Car �� start()
        Boat::start();  // ���� Boat �� start()
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle;
    amphibiousVehicle.start();

    return 0;
}