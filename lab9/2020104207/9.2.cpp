#include <iostream>

class Vehicle 
{
protected:
    int speed;

public:
    Vehicle(int s) : speed(s) {}

    virtual void start() 
    {
        std::cout << "Starting the vehicle" << std::endl;
    }
};

class Car : virtual public Vehicle 
{
public:
    Car(int s) : Vehicle(s) {}

    void start() override 
    {

        std::cout << "Starting the car" << std::endl;
    }
};

class Boat : virtual public Vehicle 
{
public:
    Boat(int s) : Vehicle(s) {}

    void start() override 
    {
        std::cout << "Starting the boat" << std::endl;
    }
};

class Boat : virtual public Vehicle 
{  
public:  
    Boat() 
    {  
        std::cout << "Boat constructor called." << std::endl;  
    }  
    void start() override {  
        std::cout << "Boat started." << std::endl;  
    }  
};  
  
// 派生类 AmphibiousVehicle，同时继承自 Car 和 Boat  
class AmphibiousVehicle : public Car, public Boat 
{  
public:  
    AmphibiousVehicle() 
    {  
        std::cout << "AmphibiousVehicle constructor called." << std::endl;  
    }  
    void start() override 
    {  
        std::cout << "AmphibiousVehicle started." << std::endl;  
    }  
};  
  
int main() 
{  
    AmphibiousVehicle amphi; // 创建 AmphibiousVehicle 对象  
    amphi.start(); // 调用 start() 函数，菱形继承问题已解决  
    return 0;  
}