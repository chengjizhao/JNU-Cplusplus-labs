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
    void boot() {
        std::cout << "Computer booted up." << std::endl;
    }
};

// ������ Phone
class Phone : public Device {
public:
    void call() {
        std::cout << "Phone is making a call." << std::endl;
    }
};

// ������ SmartDevice ͬʱ�̳��� Computer �� Phone
class SmartDevice : public Computer, public Phone {
public:
    void runApp() {
        std::cout << "SmartDevice is running an application." << std::endl;
    }

    // ������������⣬ʹ����������������
    using Computer::powerOn;
    using Computer::powerOff;
};

int main() {
    SmartDevice smartDevice;

    // ��ʾ��̳е�Ӧ�ó���
    smartDevice.Computer::powerOn();
    smartDevice.boot();
    smartDevice.call();
    smartDevice.runApp();
    smartDevice.Computer::powerOff();

    return 0;
}