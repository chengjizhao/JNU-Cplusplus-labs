#include <iostream>

// ���� Device
class Device {
public:
    virtual void powerOn() {
        std::cout << "Device powered on." << std::endl;
    }

    virtual void powerOff() {
        std::cout << "Device powered off." << std::endl;
    }
};

// ������ Computer
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

// ������ Phone
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

// ��̳��� SmartDevice
class SmartDevice : public Computer, public Phone {
public:
    void powerOn() override {
        Computer::powerOn();  // ��ȷ���� Computer ����� powerOn()
    }

    void powerOff() override {
        Phone::powerOff();    // ��ȷ���� Phone ����� powerOff()
    }

    void runApp() {
        std::cout << "Running app on smart device." << std::endl;
    }
};

int main() {
    SmartDevice smartDevice;

    smartDevice.powerOn();   // ���� Computer �� powerOn()
    smartDevice.startUp();   // ���� Computer �� startUp()

    smartDevice.powerOff();  // ���� Phone �� powerOff()
    smartDevice.shutDown();  // ���� Computer �� shutDown()

    smartDevice.powerOn();   // ���� Computer �� powerOn()
    smartDevice.call();      // ���� Phone �� call()

    smartDevice.powerOff();  // ���� Phone �� powerOff()
    smartDevice.hangUp();    // ���� Phone �� hangUp()

    smartDevice.runApp();    // ���� SmartDevice �� runApp()

    return 0;
}