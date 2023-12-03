#include <iostream>

// 车辆基类
class Vehicle {
protected:
 int speed;

public:
 Vehicle(int speed) : speed(speed) {}

 virtual void start() {
 std::cout << "Vehicle started." << std::endl;
 }
};

// 汽车类，继承自车辆基类
class Car : virtual public Vehicle {
public:
 Car(int speed) : Vehicle(speed) {}

 void start() override {
 std::cout << "Car started. Speed: " << speed << " km/h." << std::endl;
 }
};

// 船类，继承自车辆基类
class Boat : virtual public Vehicle {
public:
 Boat(int speed) : Vehicle(speed) {}

 void start() override {
 std::cout << "Boat started. Speed: " << speed << " knots." << std::endl;
 }
};

//两栖车辆类，虚继承自汽车类和船类
class AmphibiousVehicle : public Car, public Boat {
public:
 AmphibiousVehicle(int carSpeed, int boatSpeed) : Car(carSpeed), Boat(boatSpeed), Vehicle(carSpeed) {}

 void start() override {
 Car::start();
 Boat::start();
 }
};

int main() {
 AmphibiousVehicle amphibiousVehicle(100,30);

 amphibiousVehicle.start();

 return 0;
}
