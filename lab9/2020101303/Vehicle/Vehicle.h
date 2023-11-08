#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;

class Vehicle_1
{
    public:
        int speed;
        Vehicle_1(int value) : speed(value) {cout << "Non_Virtual" << endl;}
        virtual void start()
        {
            cout << "Vehicle !!!" << endl;
        }
};
class Car_1 : public Vehicle_1
{
    public:
        Car_1(int value) : Vehicle_1(value) {}
};
class Boat_1 : public Vehicle_1
{
    public:
        Boat_1(int value) : Vehicle_1(value) {}
};
class AmphibiousVehicle_1 : public Car_1, public Boat_1
{
    public:
        AmphibiousVehicle_1(int value) : Car_1(value), Boat_1(value) {}
};

class Vehicle_2
{
    public:
        int speed;
        Vehicle_2(int value) : speed(value) {cout << "Virtual" << endl;}
        virtual void start()
        {
            cout << "Vehicle !!!" << endl;
        }
};

class Car_2 : virtual public Vehicle_2
{
    public:
        Car_2(int value) : Vehicle_2(value) {}
};

class Boat_2 : virtual public Vehicle_2
{
    public:
        Boat_2(int value) : Vehicle_2(value) {}
};

class AmphibiousVehicle_2 : public Car_2, public Boat_2
{
    public:
        AmphibiousVehicle_2(int value) : Vehicle_2(value), Car_2(value), Boat_2(value) {}
};

#endif