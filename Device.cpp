#include <iostream>
using namespace std;

// 基类 Device
class Device {
public:
    virtual void powerOn() {
        cout << "Device powered on." << endl;
    }
};

// 派生类 Computer
class Computer : public Device {
public:
    void powerOn() override {
        cout << "Computer powered on." << endl;
    }

    void bootOS() {
        cout << "Operating system booted." << endl;
    }
};

// 派生类 Phone
class Phone : public Device {
public:
    void powerOn() override {
        cout << "Phone powered on." << endl;
    }

    void makeCall() {
        cout << "Calling..." << endl;
    }
};

// 多继承的派生类 SmartDevice
class SmartDevice : public Computer, public Phone {
public:
    void runApp() {
        cout << "Running app." << endl;
    }
};


int main() {
    SmartDevice smartDevice;
    smartDevice.Computer::powerOn(); // 显式指定调用 Computer 类中的 powerOn() 函数
    smartDevice.Phone::powerOn(); // 显式指定调用 Phone 类中的 powerOn() 函数
    smartDevice.bootOS();
    smartDevice.makeCall();
    smartDevice.runApp();

    return 0;
}


