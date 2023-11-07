#include <iostream>

using namespace std;

class Vehicle
{
    public:
        int speed;
        Vehicle(int value) : speed(value) {}
        virtual void start()
        {
            cout << "vehicle starts at " << speed << endl;
        }
};

class Car : public virtual Vehicle
{
    public:
        Car(int value) : Vehicle(value) {}
        virtual void start()
        {
            cout << "car starts at " << speed << endl;
        }
};

class Boat : public virtual Vehicle
{
    public:
        Boat(int value) : Vehicle(value) {}
        virtual void start()
        {
            cout << "boat starts at " << speed << endl;
        }
};

class AmphibiousVehicle : public Car, public Boat
{
    public:
        AmphibiousVehicle(int value) : Vehicle(value), Car(value), Boat(value) {}
        void start()
        {
            cout << "amphibious vehicle starts at " << speed << endl;
        }
};

int main()
{
    AmphibiousVehicle av1(50);
    av1.start();

    return 0;
}