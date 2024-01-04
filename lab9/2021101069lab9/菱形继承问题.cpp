#include <iostream>  
  
// 基类 Vehicle  
class Vehicle {  
public:  
    Vehicle() {  
        std::cout << "Vehicle constructor called." << std::endl;  
    }  
    virtual void start() {  
        std::cout << "Vehicle started." << std::endl;  
    }  
};  
  
// 派生类 Car  
class Car : virtual public Vehicle {  
public:  
    Car() {  
        std::cout << "Car constructor called." << std::endl;  
    }  
    void start() override {  
        std::cout << "Car started." << std::endl;  
    }  
};  
  
// 派生类 Boat  
class Boat : virtual public Vehicle {  
public:  
    Boat() {  
        std::cout << "Boat constructor called." << std::endl;  
    }  
    void start() override {  
        std::cout << "Boat started." << std::endl;  
    }  
};  
  
// 派生类 AmphibiousVehicle，同时继承自 Car 和 Boat  
class AmphibiousVehicle : public Car, public Boat {  
public:  
    AmphibiousVehicle() {  
        std::cout << "AmphibiousVehicle constructor called." << std::endl;  
    }  
    void start() override {  
        std::cout << "AmphibiousVehicle started." << std::endl;  
    }  
};  
  
int main() {  
    AmphibiousVehicle amphi; // 创建 AmphibiousVehicle 对象  
    amphi.start(); // 调用 start() 函数，菱形继承问题已解决  
    return 0;  
}