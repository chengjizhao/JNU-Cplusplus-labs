#include <iostream>
#include <string>

// 定义基类 Device
class Device {
public:
    Device(const std::string& brand, const std::string& model) : brand(brand), model(model) {}

    virtual std::string info() const {
        return "Brand: " + brand + ", Model: " + model;
    }

private:
    std::string brand;
    std::string model;
};

// 定义派生类 Computer
class Computer : public Device {
public:
    Computer(const std::string& brand, const std::string& model, const std::string& cpu, int ram)
        : Device(brand, model), cpu(cpu), ram(ram) {}

    std::string specs() const {
        return info() + ", CPU: " + cpu + ", RAM: " + std::to_string(ram) + "GB";
    }

private:
    std::string cpu;
    int ram;
};

// 定义派生类 Phone
class Phone : public Device {
public:
    Phone(const std::string& brand, const std::string& model, double screen_size, int battery)
        : Device(brand, model), screen_size(screen_size), battery(battery) {}

    std::string specs() const {
        return info() + ", Screen Size: " + std::to_string(screen_size) + " inches, Battery: " + std::to_string(battery) + "mAh";
    }

private:
    double screen_size;
    int battery;
};

// 定义多继承类 SmartDevice
class SmartDevice : public Computer, public Phone {
public:
    SmartDevice(const std::string& brand, const std::string& model, const std::string& cpu, int ram, double screen_size, int battery)
        : Computer(brand, model, cpu, ram), Phone(brand, model, screen_size, battery) {}

    void runApp(const std::string& appName) const {
        std::cout << "Running " << appName << " on " << info() << std::endl;
    }
};

int main() {
    // 创建一个 SmartDevice 实例
    SmartDevice smartphone("Apple", "iPhone 12", "A14 Bionic", 4, 6.1, 2815);

    // 调用方法
    std::cout << smartphone.specs() << std::endl;
    smartphone.runApp("Maps");

    return 0;
}
