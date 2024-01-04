#include <iostream>  
  
// Device 基类  
class Device 
{  
public:  
    virtual void turnOn() 
    {  
        std::cout << "Device turned on." << std::endl;  
    }  
};  
  
// Computer 派生类  
class Computer : public Device 
{  
public:  
    void runProgram() 
    {  
        std::cout << "Computer is running a program." << std::endl;  
    }  
};  
  
// Phone 派生类  
class Phone : public Device 
{  
public:  
    void makeCall() 
    {  
        std::cout << "Phone is making a call." << std::endl;  
    }  
};  
  
// SmartDevice 类同时继承自 Computer 和 Phone  
class SmartDevice : public Computer, public Phone 
{  
public:  
    void runApp() 
    {  
        std::cout << "SmartDevice is running an app." << std::endl;  
    }  
};  
  
int main() 
{  
    SmartDevice smartDevice;  
    smartDevice.turnOn();  
    smartDevice.runProgram();   
    smartDevice.makeCall();  
    smartDevice.runApp();  
    return 0;  
}