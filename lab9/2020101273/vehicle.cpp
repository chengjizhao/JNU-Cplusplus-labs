#include <iostream>
using std::cout,std::endl;

class Vehicle {
public:
    virtual void start() = 0;
    virtual void setSpeed(int speed) {
        this->speed = speed;
    }
    int speed;
};

class Car : public virtual Vehicle {
public:
    void start() override {
        cout << "Starting a Car at the speed:" << speed << endl;
    }
};

class Boat : public virtual Vehicle {
public:
    void start() override {
        cout << "Starting a Boatat the speed:" << speed << endl;
    }
};

class AmphibiousVehicle : public Car, public Boat {
public:
    void start() override {
       cout << "Starting an Amphibious Vehicle at the speed:" << speed << endl;
    }
};

int main() {
    Car* ptr1 = new Car();
    ptr1->setSpeed(120);
    ptr1->start();

    Boat* ptr2 = new Boat();
    ptr2->setSpeed(100);
    ptr2->start();

    AmphibiousVehicle amphibiousVehicle;
    amphibiousVehicle.setSpeed(150);
    amphibiousVehicle.start();

    delete ptr1;
    delete ptr2;

    /*Car car;基类指针Vehicle不行
    car.setSpeed(120);
    car.start();
    Boat boat;
    boat.setSpeed(100);
    boat.start();*/

    return 0;
}