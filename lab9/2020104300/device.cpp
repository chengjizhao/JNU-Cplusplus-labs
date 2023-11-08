#include <iostream>  
  
// Device 基类  
class Device {  
public:  
    virtual void turnOn() {  
        std::cout << "Device turned on." << std::endl;  
    }  
};  
  
// Computer 派生类  
class Computer : public Device {  
public:  
    void runProgram() {  
        std::cout << "Computer is running a program." << std::endl;  
    }  
};  
  
// Phone 派生类  
class Phone : public Device {  
public:  
    void makeCall() {  
        std::cout << "Phone is making a call." << std::endl;  
    }  
};  
  
// SmartDevice 类同时继承自 Computer 和 Phone  
class SmartDevice : public Computer, public Phone {  
public:  
    // 添加一个虚函数 runApp()，以演示多继承的应用场景  
    void runApp() {  
        std::cout << "SmartDevice is running an app." << std::endl;  
    }  
};  
  
int main() {  
    SmartDevice smartDevice;  
    smartDevice.turnOn();  // 调用基类的虚函数 turnOn()，将执行 Device 中的 turnOn() 方法。  
    smartDevice.runProgram();  // 调用派生类 Computer 中的 runProgram() 方法。  
    smartDevice.makeCall();  // 调用派生类 Phone 中的 makeCall() 方法。  
    smartDevice.runApp();  // 调用 SmartDevice 中的 runApp() 方法。  
    return 0;  
}
