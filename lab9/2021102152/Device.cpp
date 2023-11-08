#include<iostream>
using namespace std;
class Device
{
    public:
    void func()
    {cout<<"Device:func()"<<endl;}
    virtual  void runApp()
    {cout<<"Device:runApp()"<<endl;}
    private:
    int Data;


};
class Computer : public Device 
{
    public:
    void func()
    {cout<<"Computer:func()"<<endl;}
    virtual void runApp()
    {cout<<"Computer:runApp()"<<endl;}
    private:
    int cData;

};
class Phone : public Device
{
    public:
    void func()
    {cout<<"Phone:func()"<<endl;}
    virtual void runApp()
    {cout<<"Phone:runApp()"<<endl;}
    virtual void func1()
    {cout<<"Phone:func1"<<endl;}
    private:
    int pData;

};
class SmartDevice : public Computer , public Phone
{
    public:
    void func()
    {cout<<"SmartDevice:func()"<<endl;}
    virtual void runApp()
    {cout<<"SmartDevice:runApp()"<<endl;}
    virtual void func2()
    {cout<<"SmartDevice:func2"<<endl;}
    private:
    int sData;

};
int main()
{
    
    Device* a=new Computer;
    a->func();//隐藏子类同名函数
    a->runApp();//覆盖父类Device虚函数
    Device* b=new Phone;
    b->func();//隐藏子类同名函数
    b->runApp();//覆盖父类Device虚函数
    //b->func1();父类没有func1()这个虚函数
    Phone* c=new SmartDevice;
    c->func();//隐藏子类同名函数
    c->runApp();//覆盖父类Phone虚函数
    c->func1();//未被子类重写的父类虚函数

}