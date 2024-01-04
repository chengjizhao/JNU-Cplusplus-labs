#include <iostream>

// 设备基类
class Device {
public:
 virtual void powerOn() {
 std::cout << "Device powered on." << std::endl;
 }

 virtual void powerOff() {
 std::cout << "Device powered off." << std::endl;
 }
};

// 计算机类
class Computer : public Device {
public:
 void boot() {
 std::cout << "Computer booted up." << std::endl;
 }

 void shutdown() {
 std::cout << "Computer shut down." << std::endl;
 }
};

// 手机类
class Phone : public Device {
public:
 void turnOn() {
 std::cout << "Phone turned on." << std::endl;
 }

 void turnOff() {
 std::cout << "Phone turned off." << std::endl;
 }
};

// 智能设备类，多继承自 Computer 和 Phone
class SmartDevice : public Computer, public Phone {
public:
 void runApp() {
 std::cout << "Running app on smart device." << std::endl;
 }
};

int main() {
 SmartDevice smartDevice;

 smartDevice.powerOn();
 smartDevice.boot();
 smartDevice.turnOn();
 smartDevice.runApp();
 smartDevice.turnOff();
 smartDevice.shutdown();
 smartDevice.powerOff();

 return 0;
}
