#include <iostream>

// 基类 Device
class Device {
public:
    Device() {
        std::cout << "Device constructor" << std::endl;
    }

    virtual ~Device() {
        std::cout << "Device destructor" << std::endl;
    }

    virtual void turnOn() {
        std::cout << "Device is turning on" << std::endl;
    }

    virtual void turnOff() {
        std::cout << "Device is turning off" << std::endl;
    }
};

// 派生类 Computer
class Computer : public Device {
public:
    Computer() {
        std::cout << "Computer constructor" << std::endl;
    }

    ~Computer() override {
        std::cout << "Computer destructor" << std::endl;
    }

    void runSoftware() {
        std::cout << "Running software on the computer" << std::endl;
    }
};

// 派生类 Phone
class Phone : public Device {
public:
    Phone() {
        std::cout << "Phone constructor" << std::endl;
    }

    ~Phone() override {
        std::cout << "Phone destructor" << std::endl;
    }

    void makeCall() {
        std::cout << "Making a call on the phone" << std::endl;
    }
};

// 继承自 Computer 和 Phone 的 SmartDevice 类
class SmartDevice : public Computer, public Phone {
public:
    SmartDevice() {
        std::cout << "SmartDevice constructor" << std::endl;
    }

    ~SmartDevice() override {
        std::cout << "SmartDevice destructor" << std::endl;
    }

    // 虚函数，演示多继承的应用场景
    void runApp() {
        std::cout << "Running a smart application on the SmartDevice" << std::endl;
    }
};

int main() {
    // 创建一个 SmartDevice 对象并演示多继承
    SmartDevice mySmartDevice;
    
    // 调用基类 Device 的函数
    mySmartDevice.turnOn();
    mySmartDevice.turnOff();

    // 调用派生类 Computer 的函数
    mySmartDevice.runSoftware();

    // 调用派生类 Phone 的函数
    mySmartDevice.makeCall();

    // 调用 SmartDevice 类中添加的虚函数
    mySmartDevice.runApp();

    return 0;
}

