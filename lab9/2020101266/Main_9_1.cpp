#include <iostream>  
#include <string>  

// 基类 Device  
class Device {
public:
    virtual void turnOn() {
        std::cout << "Device turned on." << std::endl;
    }
    virtual void turnOff() {
        std::cout << "Device turned off." << std::endl;
    }
};

// 派生类 Computer  
class Computer : public Device {
public:
    void runApp() {
        std::cout << "Running an app on the computer." << std::endl;
    }
};

// 派生类 Phone  
class Phone : public Device {
public:
    void makeCall() {
        std::cout << "Making a call on the phone." << std::endl;
    }
};

// 多继承类 SmartDevice，继承自 Computer 和 Phone  
class SmartDevice : public Computer, public Phone {
public:
    void runApp() override { // 重写 Computer 类的 runApp() 方法  
        std::cout << "Running an app on the smart device." << std::endl;
    }
};