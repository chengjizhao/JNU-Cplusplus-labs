#include <iostream>
using namespace std;

class Car
{
public:
    virtual void price()
    {
        cout << "汽车价格根据类型区分:" << endl;
    }
};

class Sedan : public Car
{
public:
    void price() override
    {
        cout << "20w" << endl;
    }
};

class SUV : public Car
{
public:
    void price() override
    {
        cout << "40w" << endl;
    }
};

int main()
{
    Car *p0 = new Car;
    Car *p1 = new Sedan;
    Car *p2 = new SUV;
    p0->price();
    p1->price();
    p2->price();
    delete p0;
    delete p1;
    delete p2;
    // delete p1;
    // delete p2;
    return 0;
}
