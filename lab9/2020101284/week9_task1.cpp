#include <iostream>

// 基类 Device
class Device {
public:
    void powerOn() {
        std::cout << "Device powered on." << std::endl;
    }

    void powerOff() {
        std::cout << "Device powered off." << std::endl;
    }
};

// 派生类 Computer
class Computer : virtual public Device {
public:
    void boot() {
        std::cout << "Computer booted." << std::endl;
    }

    void shutDown() {
        std::cout << "Computer shut down." << std::endl;
    }
};

// 派生类 Phone
class Phone : virtual public Device {
public:
    void call() {
        std::cout << "Phone call initiated." << std::endl;
    }

    void hangUp() {
        std::cout << "Phone call ended." << std::endl;
    }
};

// 多继承的 SmartDevice 类
class SmartDevice : public Computer, public Phone {
public:
    void runApp() {
        std::cout << "Smart device running app." << std::endl;
    }
};

int main() {
    SmartDevice smartDevice;
    smartDevice.powerOn();  // 调用 Device 类的成员函数
    smartDevice.boot();     // 调用 Computer 类的成员函数
    smartDevice.call();     // 调用 Phone 类的成员函数
    smartDevice.runApp();   // 调用 SmartDevice 类的成员函数
    smartDevice.hangUp();   // 调用 Phone 类的成员函数
    smartDevice.shutDown(); // 调用 Computer 类的成员函数
    smartDevice.powerOff(); // 调用 Device 类的成员函数

    return 0;
}