#include <iostream>
#include <string>
using namespace std;
class Device {
public:
    Device(const string& brand, const string& model) : brand(brand), model(model) {}
    virtual string info() const {
        return "Brand: " + brand + ", Model: " + model;
    }
private:
    string brand;
    string model;
};
class Computer : public Device {
public:
    Computer(const string& brand, const string& model, const string& cpu, int ram)
        : Device(brand, model), cpu(cpu), ram(ram) {}
    string specs() const {
        return info() + ", CPU: " + cpu + ", RAM: " + to_string(ram) + "GB";
    }
private:
    string cpu;
    int ram;
};
class Phone : public Device {
public:
    Phone(const string& brand, const string& model, double screen_size, int battery)
        : Device(brand, model), screen_size(screen_size), battery(battery) {}
    string specs() const {
        return info() + ", Screen Size: " + to_string(screen_size) + " inches, Battery: " + to_string(battery) + "mAh";
    }
private:
    double screen_size;
    int battery;
};
class SmartDevice : public Computer, public Phone {
public:
    SmartDevice(const string& brand, const string& model, const string& cpu, int ram, double screen_size, int battery)
        : Computer(brand, model, cpu, ram), Phone(brand, model, screen_size, battery) {}
    void runApp(const string& appName) const {
        cout << "Running " << appName << " on " << info() << endl;
    }
};
int main() {
    SmartDevice smartphone("Apple", "iPhone 12", "A14 Bionic", 4, 6.1, 2815);
    cout << smartphone.specs() << endl;
    smartphone.runApp("Maps");
    return 0;
}