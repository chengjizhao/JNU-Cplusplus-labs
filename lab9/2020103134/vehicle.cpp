#include<iostream>
using namespace std;

class Vehicle
{
    public:
    int speed;
    Vehicle(int speed):speed(speed){};
    virtual void start()
    {
        cout<<"speed is "<<speed<<"km/h"<<endl;
    };
};
class Car:public virtual Vehicle
{
    public:
    Car(int speed):Vehicle(speed){};
    void start()
    {
        cout<<"car's speed is"<<speed<<"km/h"<<endl;
    };
};
class Boat:public virtual Vehicle
{
    public:
    Boat(int speed):Vehicle(speed){};
    void start()
    {
        cout<<"boat's speed is"<<speed<<"kts"<<endl;
    };
};
class AmphibiousVehicle:public Car,public Boat
{
    public:
    AmphibiousVehicle(int car_speed,int boat_speed):Vehicle(car_speed),Car(car_speed),Boat(boat_speed){};
    void start()
    {
        Car::start();
        Boat::start();
    }
};
int main()
{
    AmphibiousVehicle obj(12,35);
    obj.start();
    return 0;
}