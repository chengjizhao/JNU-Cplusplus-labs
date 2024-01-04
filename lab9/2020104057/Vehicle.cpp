#include <iostream>

//电子设备的类层次结构

// 基类 Vehicle
class Vehicle 
{
public:
    int speed;

    virtual void start()
    {
      std::cout << "Vehicle started." << std::endl;
    }
};

// 派生类 Car
class Car : virtual public Vehicle {
public:
    void start() override 
    {
      std::cout << "Car started." << std::endl;
    }
};

// 派生类 Boat
class Boat : virtual public Vehicle 
{
public:
    void start() override 
    {
      std::cout << "Boat started." << std::endl;
    }
};

// 多继承类 AmphibiousVehicle 同时继承自 Car 和 Boat
class AmphibiousVehicle : public Car, public Boat 
{
public:
    void start() override 
    {
      Car::start();   // 调用 Car 的 start()
      Boat::start();  // 调用 Boat 的 start()
    }
};

//讨论：虚拟继承可以解决菱形继承的二义性和数据冗余的问题。如上面的继承关系，在 Car 和 Boat，它们都继承 Vehicle 时使用虚拟继承，即可解决问题。

int main() 
{
  AmphibiousVehicle amphibiousVehicle;
  amphibiousVehicle.start();

  return 0;
}