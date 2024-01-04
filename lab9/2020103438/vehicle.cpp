#include <iostream>
using namespace std;

class Vehicle
{
public:
    int speed;
    Vehicle(int value) : speed(value) {}
    virtual void start()
    {
        cout << "vehicle's speed is " << speed << "km/h" << endl;
    }
};

class Car : public virtual Vehicle
{
public:
    Car(int value) : Vehicle(value) {}
    virtual void start()
    {
        cout << "car's speed is " << speed << "km/h" << endl;
    }
};

class Boat : public virtual Vehicle
{
public:
    Boat(int value) : Vehicle(value) {}
    virtual void start()
    {
        cout << "boat's speed is " << speed << "km/h" << endl;
    }
};

class AmphibiousVehicle : public Car, public Boat
{
public:
    AmphibiousVehicle(int value) : Vehicle(value), Car(value), Boat(value) {}
    void start()
    {
        cout << "amphibious vehicle's speed is " << speed << "km/h" << endl;
    }
};

int main()
{
    AmphibiousVehicle tank(100);
    tank.start();

    return 0;
}