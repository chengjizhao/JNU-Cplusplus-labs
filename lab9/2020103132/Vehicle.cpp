/*菱形继承问题：创建一个类 Vehicle，它具有成员变量 speed 和虚函数 start(). 
创建两个派生类 Car 和 Boat，它们都继承自 Vehicle。接下来，创建一个类 
AmphibiousVehicle，它同时继承自 Car 和 Boat，并实现 start() 函数来演示
菱形继承问题。讨论如何使用虚继承来解决这个问题。*/

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
    AmphibiousVehicle av(100);
    av.start();

    return 0;
}