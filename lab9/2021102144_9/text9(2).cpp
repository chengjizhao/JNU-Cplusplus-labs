#include<iostream>
using namespace std;
class Vehicle
{
    public:
    Vehicle(double num):speed(num){};
    virtual void start(){cout<<speed<<endl;};
    double speed;
};
class Car:public virtual Vehicle
{
    public:
    Car(double num):Vehicle(num){};
    virtual void start(){cout<<speed<<endl;};
};
class Boat:public virtual Vehicle
{
    public:
    Boat(double num):Vehicle(num){};
    virtual void start(){cout<<speed<<endl;};
};
class AmphibiousVehicle:public Car,public Boat
{
    public:
    AmphibiousVehicle(double num):Vehicle(num),Car(num),Boat(num){};
    virtual void start(){cout<<speed<<endl;}
};
int main()
{
    AmphibiousVehicle a(1);
    a.start();
    return 0;
}