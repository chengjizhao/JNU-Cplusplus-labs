#include "lab9.h"
void Device::runApp()
{
    cout << "device" << endl;
}
void Computer::runApp()
{
    cout << "computer" << endl;
}
void SmartDevice::runApp()
{
    cout << "smartdevice" << endl;
}
void Phone::runApp()
{
    cout << "phone" << endl;
}
int main()
{
    SmartDevice a;
    a.Device::runApp();
    a.Phone::runApp();
    a.Computer::runApp();
    a.runApp();//多继承可以通过类名调用重名的成员函数,
    //如果多继承的类中原本没有重名的函数,则无法确定调用哪一个

}


