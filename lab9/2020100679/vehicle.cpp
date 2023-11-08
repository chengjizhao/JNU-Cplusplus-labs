#include <iostream>
using namespace std;

class Vehicle {
protected:
    int speed;

public:
    virtual void start() = 0;
};

class Car : public Vehicle {
public:
    void start() override {
        cout << "Car starts." << endl;
    }
};

class Boat : public Vehicle {
public:
    void start() override {
        cout << "Boat starts." << endl;
    }
};

class AmphibiousVehicle : public virtual Car, public virtual Boat {
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
