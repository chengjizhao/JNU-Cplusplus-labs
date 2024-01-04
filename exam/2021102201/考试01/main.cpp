#include <iostream>

using namespace std;

class Vehicle
{
public:
    virtual void start() { cout << "Vehicle starting..." << endl; }
};

class Car : public Vehicle
{
public:
    void start() override { cout << "Car starting..." << endl; }
};

class Bike : public Vehicle
{
public:
    void start() override { cout << "Bike starting..." << endl; }
};

int main()
{
    Vehicle* vehicles[2];
    Car car;
    Bike bike;

    vehicles[0] = &car;
    vehicles[1] = &bike;

    for (int i = 0; i < 2; i++) {
        vehicles[i]->start();
    }

    return 0;
}