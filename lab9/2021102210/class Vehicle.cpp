#include<iostream>

using namespace std;

class Vehicle
{
    public:
    void start()
    {
        cout << "this is Vehicle " << endl ;
    }
    int speed;
    Vehicle(int a) : speed (a) {}
};

class Car : public virtual Vehicle
{
    public:
    Car(int a) : Vehicle(a){} ;
};

class Boat : public virtual Vehicle
{
    public:
    Boat(int a) : Vehicle(a){} ;
};

class  AmphibiousVehicle : public Car , public Boat 
{
    public:
    AmphibiousVehicle (int a) :  Vehicle(a) , Car(a) , Boat(a) {} ;
};

int main()
{
    AmphibiousVehicle amph(10);
    cout << amph.speed << endl ;
    amph.start();
}