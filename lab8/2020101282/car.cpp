#include <iostream>
#include <string>

// 基类 Car
class Car {
public:
    Car(const std::string& make, const std::string& model) : make(make), model(model) {}

    virtual double calculatePrice() const {
        return 0.0;
    }

    void displayInfo() const {
        std::cout << "Make: " << make << ", Model: " << model << ", Price: " << calculatePrice() << std::endl;
    }

protected:
    std::string make;
    std::string model;
};

// 派生类 Sedan
class Sedan : public Car {
public:
    Sedan(const std::string& make, const std::string& model, int numDoors) : Car(make, model), numDoors(numDoors) {}

    double calculatePrice() const override {
        // 假设 Sedan 的价格是每个车门的数量的基础价格
        return 10000.0 + numDoors * 2000.0;
    }

private:
    int numDoors;
};

// 派生类 SUV
class SUV : public Car {
public:
    SUV(const std::string& make, const std::string& model, bool hasThirdRow) : Car(make, model), hasThirdRow(hasThirdRow) {}

    double calculatePrice() const override {
        // 假设 SUV 的价格在是否有第三排座位的基础上有不同
        if (hasThirdRow) {
            return 35000.0;
        } else {
            return 30000.0;
        }
    }

private:
    bool hasThirdRow;
};

int main() {
    Sedan sedan("Toyota", "Camry", 4);
    SUV suv("Ford", "Explorer", true);

    sedan.displayInfo(); // 输出 Sedan 的信息和价格
    suv.displayInfo();   // 输出 SUV 的信息和价格

    return 0;
}
