#include <iostream>

// 基类 Device
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// 派生类 Computer
class Computer : public Device {
public:
    void turnOn() override {
        std::cout << "Computer is turning on" << std::endl;
    }
    void turnOff() override {
        std::cout << "Computer is turning off" << std::endl;
    }
    virtual void runApp() {
        std::cout << "Running an application on computer" << std::endl;
    }
};

// 派生类 Phone
class Phone : public Device {
public:
    void turnOn() override {
        std::cout << "Phone is turning on" << std::endl;
    }
    void turnOff() override {
        std::cout << "Phone is turning off" << std::endl;
    }
    virtual void runApp() {
        std::cout << "Running an application on phone" << std::endl;
    }
};

// 多重继承，同时从Computer和Phone中继承
class SmartDevice : public Computer, public Phone {
public:
    void runApp() override {
        std::cout << "Running an application on smart device" << std::endl;
    }
};

int main() {
    SmartDevice mySmartDevice;
    mySmartDevice.turnOn();
    mySmartDevice.runApp();
    mySmartDevice.turnOff();

    return 0;
}
