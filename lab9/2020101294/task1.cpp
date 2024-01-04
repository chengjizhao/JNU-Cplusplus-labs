#include <iostream>

// 基类 Device
class Device {
public:
    virtual void powerOn() {
        std::cout << "Device powered on." << std::endl;
    }

    virtual void powerOff() {
        std::cout << "Device powered off." << std::endl;
    }
};

// 派生类 Computer
class Computer : public Device {
public:
    void boot() {
        std::cout << "Computer booted up." << std::endl;
    }
};

// 派生类 Phone
class Phone : public Device {
public:
    void call() {
        std::cout << "Phone is making a call." << std::endl;
    }
};

// 派生类 SmartDevice 同时继承自 Computer 和 Phone
class SmartDevice : public Computer, public Phone {
public:
    void runApp() {
        std::cout << "SmartDevice is running an application." << std::endl;
    }

    // 解决二义性问题，使用作用域解析运算符
    using Computer::powerOn;
    using Computer::powerOff;
};

int main() {
    SmartDevice smartDevice;

    // 演示多继承的应用场景
    smartDevice.Computer::powerOn();
    smartDevice.boot();
    smartDevice.call();
    smartDevice.runApp();
    smartDevice.Computer::powerOff();

    return 0;
}