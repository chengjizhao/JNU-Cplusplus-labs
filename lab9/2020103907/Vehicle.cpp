#include <iostream>
using namespace std;

class Vehicle1
{
public:
    int speed;
    Vehicle1(int speed_) : speed(speed_) {cout << "1" << endl;}
    virtual void start()
    {
            cout << "Vehicle started" << endl;
    }
};

class Car1 : public Vehicle1
{
    public:
        Car1(int speed_) : Vehicle1(speed_) {}
};

class Boat1 : public Vehicle1
{
    public:
        Boat1(int speed_) : Vehicle1(speed_) {}
};

class AmphibiousVehicle1 : public Car1, public Boat1
{
    public:
        AmphibiousVehicle1(int speed_) : Car1(speed_), Boat1(speed_) {}
};

class Vehicle2
{
public:
    int speed;
    Vehicle2(int speed_) : speed(speed_) {cout << "2" << endl;}
    virtual void start()
    {
            cout << "Vehicle started" << endl;
    }
};

class Car2 : virtual public Vehicle2
{
    public:
        Car2(int speed_) : Vehicle2(speed_) {}
};

class Boat2 : virtual public Vehicle2
{
    public:
        Boat2(int speed_) : Vehicle2(speed_) {}
};

class AmphibiousVehicle2 : public Car2, public Boat2
{
    public:
        AmphibiousVehicle2(int speed_) : Vehicle2(speed_), Car2(speed_), Boat2(speed_) {}
};

int main()
{

    AmphibiousVehicle1 obj1(1);
    AmphibiousVehicle2 obj2(1);
    obj2.start();
    
    return 0;
}





