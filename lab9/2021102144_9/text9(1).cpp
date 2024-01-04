#include<iostream>
using namespace std;
class Device
{
    public:
    virtual void runApp()
    {
        cout<<"this is a device"<<endl;
    }
};
class Phone:public Device
{
    public:
    void runApp() override
    {
        cout<<"this is a phone"<<endl;
    }
};
class Computer:public Device
{
    public:
    void runApp() override
    {
        cout<<"this is a computer"<<endl;
    }
};
class Smartdevice:public Computer,public Phone
{
    public:
    void runApp() override
    {
        cout<<"this is a smartdevice"<<endl;
    }
};
int main()
{
    return 0;
}