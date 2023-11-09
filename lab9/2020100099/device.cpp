#include <iostream>

// 基类 Device
class Device {
public:
    void powerOn() {
        std::cout << "Device powered on" << std::endl;
    }
};

// 派生类 Computer
class Computer : public Device {
public:
    void bootUp() {
        std::cout << "Computer booted up" << std::endl;
    }
};

// 派生类 Phone
class Phone : public Device {
public:
    void makeCall() {
        std::cout << "Phone making a call" << std::endl;
    }
};

// 多继承类 SmartDevice
class SmartDevice : public Computer, public Phone {
public:
    void runApp() {
        std::cout << "SmartDevice running an app" << std::endl;
    }
};

int main() {
    SmartDevice smartDevice;
    smartDevice.Computer::powerOn();  // 调用 Computer 类的 powerOn 函数
    smartDevice.Phone::powerOn();     // 调用 Phone 类的 powerOn 函数
    smartDevice.bootUp();
    smartDevice.makeCall();
    smartDevice.runApp();

    return 0;
}
