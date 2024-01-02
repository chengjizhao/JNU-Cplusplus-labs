#include <iostream>  
#include <string>  
  
class Device {  
public:  
    void powerOn() {  
        std::cout << "Device powered on." << std::endl;  
    }  
    virtual void describe() {  
        std::cout << "This is a device." << std::endl;  
    }  
};  
  
class Computer : public Device {  
public:  
    void describe() override {  
        std::cout << "This is a computer." << std::endl;  
    }  
    void runProgram() {  
        std::cout << "Running a program on the computer." << std::endl;  
    }  
};  
   
class Phone : public Device {  
public:  
    void describe() override {  
        std::cout << "This is a phone." << std::endl;  
    }  
    void makeCall() {  
        std::cout << "Making a call on the phone." << std::endl;  
    }  
};  
    
class SmartDevice : public Computer, public Phone {  
public:  
    void runApp() {  
        std::cout << "Running an app on the smart device." << std::endl;  
    }  
};  
  
int main() {  
    SmartDevice sd;  
    sd.powerOn(); 
    sd.describe(); 
    sd.runApp();   
    sd.runProgram();
    sd.makeCall(); 
    return 0;  
}