#include <iostream>
#include <string>
using namespace std;
// 基类 Device
class Device {
public:
    string brand;

    Device(const string& brand) : brand(brand) {}

    void powerOn() {
        cout << "Device powered on." << endl;
    }
};

// 派生类 Computer，使用虚继承
class Computer : public virtual Device {
public:
    Computer(const string& brand) : Device(brand) {}

    void bootUp() {
        cout << brand << " computer is booting up." << endl;
    }
};

// 派生类 Phone，使用虚继承
class Phone : public virtual Device {
public:
    Phone(const string& brand) : Device(brand) {}

    void makeCall() {
        cout << brand << " phone is making a call." << endl;
    }
};

// SmartDevice 类，同时继承自 Computer 和 Phone
class SmartDevice : public Computer, public Phone {
public:
    SmartDevice(const string& brand) : Device(brand), Computer(brand), Phone(brand) {}

    void runApp() {
        cout << brand << " smart device is running an app." << endl;
    }
};

int main() {
    // 创建一个 SmartDevice 对象并演示多继承的应用场景
    SmartDevice smartDevice("SmartBrand");
    smartDevice.powerOn();  // 调用虚继承的基类 Device 的成员函数
    smartDevice.bootUp();   // 调用派生类 Computer 的成员函数
    smartDevice.makeCall(); // 调用派生类 Phone 的成员函数
    smartDevice.runApp();   // 调用自身的成员函数

    return 0;
}
