#include <iostream>

using namespace std;

/*Base*/
class Vehicle
{
public:
    int price;
    virtual void start();
};

class Car: public Vehicle
{
public:
    void start() override
    {
       cout << "Car starting..." << endl; 
    }
};

class Bike: public Vehicle
{
public:
    void start() override
    {
       cout << "Bike starting..." << endl; 
    }
};

int main()
{
    Vehicle* vehicle[2];
    Car _car;
    Bike _bike;

    vehicle[0] = &_car;
    vehicle[1] = &_bike;
    
    vehicle[0]->start();
    vehicle[1]->start();

    return 0;
}

