#include <iostream>
#include <string>
using namespace std;

class Device
{
public:
    virtual void runApp()
    {
        cout << "device runAPP" << endl;
    }
};

class Computer :  virtual public Device
{
public:
    virtual void runApp()
    {
        cout << "computer runAPP" << endl;
    }
};

class Phone : virtual public Device
{
public:
    virtual void runApp()
    {
        cout << "phone runAPP" << endl;
    }
};

class SmartDevice : public Computer, public Phone
{
public:
    void runApp()
    {
        cout << "smartdevice runAPP" << endl;
    }
};

int main()
{
    SmartDevice huawei;
    huawei.runApp();
    return 0;
}