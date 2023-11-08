#include <iostream>

// ���� Device
class Device {
public:
    void powerOn() {
        std::cout << "Device powered on." << std::endl;
    }

    void powerOff() {
        std::cout << "Device powered off." << std::endl;
    }
};

// ������ Computer
class Computer : virtual public Device {
public:
    void boot() {
        std::cout << "Computer booted." << std::endl;
    }

    void shutDown() {
        std::cout << "Computer shut down." << std::endl;
    }
};

// ������ Phone
class Phone : virtual public Device {
public:
    void call() {
        std::cout << "Phone call initiated." << std::endl;
    }

    void hangUp() {
        std::cout << "Phone call ended." << std::endl;
    }
};

// ��̳е� SmartDevice ��
class SmartDevice : public Computer, public Phone {
public:
    void runApp() {
        std::cout << "Smart device running app." << std::endl;
    }
};

int main() {
    SmartDevice smartDevice;
    smartDevice.powerOn();  // ���� Device ��ĳ�Ա����
    smartDevice.boot();     // ���� Computer ��ĳ�Ա����
    smartDevice.call();     // ���� Phone ��ĳ�Ա����
    smartDevice.runApp();   // ���� SmartDevice ��ĳ�Ա����
    smartDevice.hangUp();   // ���� Phone ��ĳ�Ա����
    smartDevice.shutDown(); // ���� Computer ��ĳ�Ա����
    smartDevice.powerOff(); // ���� Device ��ĳ�Ա����

    return 0;
}