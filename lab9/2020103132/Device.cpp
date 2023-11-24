/*多继承的应用：设计一个电子设备的类层次结构，包括 Device 基类，
以及派生类 Computer 和 Phone。接下来，创建一个 SmartDevice 类，
它同时继承自 Computer 和 Phone，并添加一个虚函数 runApp()，
以演示多继承的应用场景。*/

#include<iostream>
#include<string>

using namespace std;

class Device
{
    public:
    virtual void runApp();
};

class Computer:virtual public Device
{
    public:
    void runSoftware();
};

class Phone:virtual public Device
{
    public:
    void takePhoto();
};

class SmartDevice:public Computer,public Phone
{
    public:
    void runApp()
    {
        cout<<"SmartDevice"<<endl;
    }
};

int main()
{
    SmartDevice SD;
    SD.runApp();
    return 0;
}