#include<iostream>
using namespace std;

class Device
{
    public:
    virtual void runapp(){};
};
class Computer:public Device
{
    public:
    void runapp(){
        cout<<"computerapp"<<endl;
    }
};
class Phone:public Device
{
    public:
    void runapp(){
        cout<<"phoneapp"<<endl;
    }
};
class SmartDevice:public Computer,public Phone
{
    public:
    void runapp(){
        Computer::runapp();
        Phone::runapp();
    }
};

int main()
{
    SmartDevice obj;
    obj.runapp();
    return 0;
}