#include <iostream>
using namespace std;

class Device
{
public:
    virtual void runApp()
    {
        cout << "Device::runApp()" << endl;
    }
};

class Computer : public Device
{
public:
    void runApp() override
    {
        cout << "Computer::runApp()" << endl;
    }
};

class Phone : public Device
{
public:
    void runApp() override
    {
        cout << "Phone::runApp()" << endl;
    }
};

class SmartDevice : public Computer, Phone
{
public:
    void runApp() override
    {
        cout << "SmartDevice::runApp()" << endl;
    }
};

int main()
{
    Device *p0 = new Device;
    Device *p1 = new Computer;
    Device *p2 = new Phone;
    Computer *p3 = new SmartDevice;
    SmartDevice s0;
    p3->runApp();
    s0.runApp(); // 为什么这个不报错
}
