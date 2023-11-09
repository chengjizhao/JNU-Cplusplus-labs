#include <iostream>

using namespace std;

class Vehicle {
public:
    int speed;

    virtual void start() {
        cout << "Vehicle started" << endl;
    }
};

class Car : virtual public Vehicle {
public:
    void start() override {
        cout << "Car started" << endl;
    }
};

class Boat : virtual public Vehicle {
public:
    void start() override {
        cout << "Boat started" << endl;
    }
};

class AmphibiousVehicle : public Car, public Boat {
public:
    void start() override {
        Car::start();
        Boat::start();
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle;
    amphibiousVehicle.start();

    return 0;
}
