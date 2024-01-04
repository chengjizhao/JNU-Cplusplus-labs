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
    void powerOn() override {
        std::cout << "Computer powered on." << std::endl;
    }

    void powerOff() override {
        std::cout << "Computer powered off." << std::endl;
    }

    void startUp() {
        std::cout << "Computer started up." << std::endl;
    }

    void shutDown() {
        std::cout << "Computer shut down." << std::endl;
    }
};

// 派生类 Phone
class Phone : public Device {
public:
    void powerOn() override {
        std::cout << "Phone powered on." << std::endl;
    }

    void powerOff() override {
        std::cout << "Phone powered off." << std::endl;
    }

    void call() {
        std::cout << "Phone making a call." << std::endl;
    }

    void hangUp() {
        std::cout << "Phone hanging up." << std::endl;
    }
};

// 多继承类  SmartDevice 同时继承自 Computer 和 Phone
class SmartDevice : public Computer, public Phone {
public:
    void powerOn() override {
        Computer::powerOn();  
    }

    void powerOff() override {
        Phone::powerOff();    
    }

    void runApp() {
        std::cout << "Running app on smart device." << std::endl;
    }
};

int main() 
{
  SmartDevice smartDevice;

  smartDevice.powerOn();   // 调用 Computer 的 powerOn()
  smartDevice.startUp();   // 调用 Computer 的 startUp()

  smartDevice.powerOff();  // 调用 Phone 的 powerOff()
  smartDevice.shutDown();  // 调用 Computer 的 shutDown()

  smartDevice.powerOn();   // 调用 Computer 的 powerOn()
  smartDevice.call();      // 调用 Phone 的 call()
  smartDevice.powerOff();  // 调用 Phone 的 powerOff()
  smartDevice.hangUp();    // 调用 Phone 的 hangUp()

  smartDevice.runApp();    // 调用 SmartDevice 的 runApp()


  system("pause");
  return 0;
}