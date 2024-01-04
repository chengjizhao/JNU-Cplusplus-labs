#include<iostream>
class Device {
public:
    virtual void turnOn() const = 0;
    virtual ~Device() {}
};

// 派生类 Computer
class Computer : public Device {
public:
    void turnOn() const override {
        std::cout<<"Computer is turning on!"<<std::endl;
    }
    void runSoftware() {
         std::cout<<"Computer is runing software!"<<std::endl;
    }
};

// 派生类 Phone
class Phone : public Device {
public:
    void turnOn() const override{
        std::cout<<"Phone is turning on!"<<std::endl;
    }
    void makeCall() {
        std::cout<<"Phone is making call !"<<std::endl;
    }
};

// 多继承类 SmartDevice
class SmartDevice : public Computer, public Phone {
public:
    virtual void runApp() {
        std::cout<<"Smart device is runing app!"<<std::endl;
    }
};


int main() {
    SmartDevice smartDevice;
    smartDevice.Phone::turnOn();    // 来自 Device 类
    smartDevice.Computer::turnOn(); //来自SmartDevice类
    smartDevice.runSoftware(); // 来自 Computer 类
    smartDevice.makeCall();    // 来自 Phone 类
    smartDevice.runApp();      // SmartDevice 特有的方法

    return 0;
}
