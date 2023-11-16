#include <iostream>

// 基类
class Device {
public:
    void powerOn() {
        std::cout << "Device powered on." << std::endl;
    }

    void powerOff() {
        std::cout << "Device powered off." << std::endl;
    }
};

// 派生类
class Computer : virtual public Device {
public:
    void boot() {
        std::cout << "Computer booted." << std::endl;
    }

    void shutDown() {
        std::cout << "Computer shut down." << std::endl;
    }
};

// 派生类
class Phone : virtual public Device {
public:
    void call() {
        std::cout << "Phone call initiated." << std::endl;
    }

    void hangUp() {
        std::cout << "Phone call ended." << std::endl;
    }
};

// 多继承的
class SmartDevice : public Computer, public Phone {
public:
    void runApp() {
        std::cout << "Smart device running app." << std::endl;
    }
};

int main() {
    SmartDevice smartDevice;
    smartDevice.powerOn();  
    smartDevice.boot();     
    smartDevice.call();     
    smartDevice.runApp();   
    smartDevice.hangUp();   
    smartDevice.shutDown(); 
    smartDevice.powerOff(); 

    return 0;
}