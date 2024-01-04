#include<iostream>
using namespace std;
class Device
{
public:
	virtual void runApp()=0;
};

class Computer : public Device
{
public:
	virtual void runApp(){
        cout << "Running Computer" << endl;
    }
};

class Phone : public Device
{
public:
    virtual void runApp(){
        cout << "Running Phone" << endl;
    }
};

class SmartDevice : public Computer, public Phone
{
    public:
    virtual void runApp(){
        cout << "Running SmartDevice" << endl;
    }
};
int main()
{
    SmartDevice obj;
    obj.Phone::runApp();
    obj.Computer::runApp();
    obj.runApp();//多继承可以通过类名调用重名的成员函数,
    //如果多继承的类中原本没有重名的函数,则无法确定调用哪一个

}
