#include <iostream>

class Device {
public:
    virtual void runApp() = 0;
};

class Computer : public Device {
public:
    void runApp() override {
        std::cout << "Running computer" << std::endl;
    }
};

class Phone : public Device {
public:
    void runApp() override {
        std::cout << "Running phone" << std::endl;
    }
};

class SmartDevice : public Computer, public Phone {
public:
    void runApp() {
        std::cout << "Running smartdevice" << std::endl;
    };
};

int main() {
    SmartDevice smartDevice;
    //对象调用
    smartDevice.runApp();
    
    //指针调用
    Computer* ptr1 = &smartDevice;
    Phone* ptr2 = &smartDevice;
    ptr1->runApp();
    ptr2->runApp();

    return 0;
}