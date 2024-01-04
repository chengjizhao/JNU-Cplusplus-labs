#include <iostream>

using namespace std;

class Device
{
public:
    Device()
        {}

    virtual void runApp(){}
};

class Computer: public Device
{
public:
    int price;
    void runApp() override
    {
        cout << "overrided by Computer" << endl;
    }
};

class Phone: public Device
{
public:
    int price;
    void runApp() override
    {
        cout << "overrided by Phone" << endl;
    }
};

class SmartDevice: public Computer, public Phone
{
public:
    void runApp() override
    {
        cout << "overrided by SmartDevice" << endl;
    }
};

int main()
{
    SmartDevice device1;
    Computer device2;

    device1.runApp();
    device2.runApp();

    return 0;
}