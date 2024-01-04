#include <iostream>
using namespace std;

class Vehicle
{
public:
    double speed;
    virtual void start()
    {
        cout << "Vehicle::start()---" << speed << endl;
    }
    Vehicle(double sped) : speed(sped){};
};

class Car : virtual public Vehicle
{
public:
    void start() override
    {
        cout << "Car::start()---" << speed << endl;
    }
    // Car(double sped) : Vehicle(sped),speed(sped){} 这样会报错
    Car(double sped) : Vehicle(sped)
    {
        speed = sped;
    }
};

class Boat : virtual public Vehicle
{
public:
    void start() override
    {
        cout << "Boat::start()---" << speed << endl;
    }
    // Car(double sped) : Vehicle(sped),speed(sped){} 这样会报错
    Boat(double sped) : Vehicle(sped)
    {
        speed = sped;
    }
};

/**************************************************************/

class AmphibiousVehicle : public Car, public Boat
{
public:
    void start() override
    {
        cout << "AmphibiousVehicle::start()---" << speed << endl;
    }
    AmphibiousVehicle(double sped) : Car(sped), Boat(sped), Vehicle(sped)
    {
        speed = sped;
    }
};

int main()
{
    Vehicle V1(100);
    Car C1(90);
    Boat B1(80);
    AmphibiousVehicle A1(70);
    V1.start();
    C1.start();
    B1.start();
    A1.start();

    return 0;
}