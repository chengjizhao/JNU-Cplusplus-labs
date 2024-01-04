#include <iostream>
#include <string>

class Device {
protected:
    std::string brand;

public:
    Device(const std::string& b) : brand(b) {}

    void powerOn() {
        std::cout << "Powering on " << brand << " device" << std::endl;
    }
};

class Computer : virtual public Device {
public:
    Computer(const std::string& b) : Device(b) {}

    void boot() {
        std::cout << "Booting " << brand << " computer" << std::endl;
    }

    virtual void runApp() {
        std::cout << "Running application on " << brand << " computer" << std::endl;
    }
};

class Phone : virtual public Device {
public:
    Phone(const std::string& b) : Device(b) {}

    void call() {
        std::cout << "Making a phone call with " << brand << " phone" << std::endl;
    }

    virtual void runApp() {
        std::cout << "Running application on " << brand << " phone" << std::endl;
    }
};

class SmartDevice : public Computer, public Phone {
public:
    SmartDevice(const std::string& b) : Device(b), Computer(b), Phone(b) {}

    void runApp() {
        std::cout << "Running application on smart device" << std::endl;
    }
};

int main() {
    SmartDevice smartDevice("SmartDevice");
    smartDevice.powerOn();
    smartDevice.boot();
    smartDevice.runApp();

    return 0;
}