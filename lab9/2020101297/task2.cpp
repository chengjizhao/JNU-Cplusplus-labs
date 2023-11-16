#include <iostream>

class Vehicle {
protected:
    int speed;

public:
    Vehicle(int speed) : speed(speed) {}

    virtual void start() {
        std::cout << "Vehicle started. Speed: " << speed << " km/h." << std::endl;
    }
};

class Car : virtual public Vehicle {
public:
    Car(int speed) : Vehicle(speed) {}

    void start() override {
        std::cout << "Car started. Speed: " << speed << " km/h." << std::endl;
    }
};

class Boat : virtual public Vehicle {
public:
    Boat(int speed) : Vehicle(speed) {}

    void start() override {
        std::cout << "Boat started. Speed: " << speed << " knots." << std::endl;
    }
};

class AmphibiousVehicle : public Car, public Boat {
public:
    AmphibiousVehicle(int carSpeed, int boatSpeed) : Vehicle(carSpeed), Car(carSpeed), Boat(boatSpeed) {}

    void start() override {
        Car::start();
        Boat::start();
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle(60, 30);
    amphibiousVehicle.start();

    return 0;
}