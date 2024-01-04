#include <iostream>

class Vehicle {
protected:
    int speed;

public:
    Vehicle(int s) : speed(s) {}

    virtual void start() {
        std::cout << "Starting the vehicle" << std::endl;
    }
};

class Car : virtual public Vehicle {
public:
    Car(int s) : Vehicle(s) {}

    void start() override {
        std::cout << "Starting the car" << std::endl;
    }
};

class Boat : virtual public Vehicle {
public:
    Boat(int s) : Vehicle(s) {}

    void start() override {
        std::cout << "Starting the boat" << std::endl;
    }
};

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