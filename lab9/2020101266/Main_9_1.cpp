#include <iostream>  
#include <string>  

// ���� Device  
class Device {
public:
    virtual void turnOn() {
        std::cout << "Device turned on." << std::endl;
    }
    virtual void turnOff() {
        std::cout << "Device turned off." << std::endl;
    }
};

// ������ Computer  
class Computer : public Device {
public:
    void runApp() {
        std::cout << "Running an app on the computer." << std::endl;
    }
};

// ������ Phone  
class Phone : public Device {
public:
    void makeCall() {
        std::cout << "Making a call on the phone." << std::endl;
    }
};

// ��̳��� SmartDevice���̳��� Computer �� Phone  
class SmartDevice : public Computer, public Phone {
public:
    void runApp() override { // ��д Computer ��� runApp() ����  
        std::cout << "Running an app on the smart device." << std::endl;
    }
};