#include<iostream>

using namespace std;

class Device
{
    public:
    virtual void runApp()
    {
        cout << "this is Device " << endl;
    }
};

class Computer : public Device
{
    public:
    virtual void runApp()
    {
        cout << "this is Computer " << endl ;
    }
};

class Phone : public Device
{
    public:
    
        virtual void runApp()
        {
            cout << "this is Phone " << endl ;
        }
    
};

class SmartDevice : public Phone , public Computer 
{
    public:
    
        virtual void runApp()
        {
            cout << "this is SmartDevice " << endl ;
        }
    
};

int main()
{
    SmartDevice smartdevice ;//创造一个SmartDevice的对象
    smartdevice.runApp();//通过SmaratDevice对象调用runApp函数为SmartDevice中的runApp函数
    Computer *p=&smartdevice;//创造一个指向该对象的Computer类型的指针
    Phone *q=&smartdevice;//创造一个指向该对象的Phone类型指针
    p->runApp();//用Computer指针调用runApp函数，为SmartDevice中的函数
    q->runApp();//用Phone指针调用runApp函数，为SmartDevice中的函数
    p->Device::runApp();//用p指针调用device中的函数
    p->Computer::runApp();//用p指针调用Computer中的函数
    //p->Phone::runApp();//用p指针无法调用Phone中的函数
    //Device *o=&smartdevice;//无法用Device的指针直系那个SmartDevice的引用
    smartdevice.Phone::runApp();//可以通过派生类访问上一位的函数
    //smartdevice.Device::runApp();//无法通过派生类访问上上级的函数，因为上上级函数是上一级函数的private对象
}