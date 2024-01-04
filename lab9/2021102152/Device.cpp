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
    a->func();//��������ͬ������
    a->runApp();//���Ǹ���Device�麯��
    Device* b=new Phone;
    b->func();//��������ͬ������
    b->runApp();//���Ǹ���Device�麯��
    //b->func1();����û��func1()����麯��
    Phone* c=new SmartDevice;
    c->func();//��������ͬ������
    c->runApp();//���Ǹ���Phone�麯��
    c->func1();//δ��������д�ĸ����麯��

}