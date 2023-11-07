#include <iostream>

using namespace std;

class Device
{
    public:
        virtual void runApp()
        {
            cout << "device is running app" << endl;
        }
};

class Computer : public virtual Device
{
    public:
        virtual void runApp()
        {
            cout << "computer is running app" << endl;
        }
};

class Phone : public virtual Device
{
    public:
        virtual void runApp()
        {
            cout << "phone is running app" << endl;
        }
};

class SmartDevice : public Computer, public Phone
{
    public:
        void runApp()
        {
            cout << "smart device is running app" << endl;
        }
};

int main()
{
    SmartDevice sd1;
    sd1.runApp();

    return 0;
}