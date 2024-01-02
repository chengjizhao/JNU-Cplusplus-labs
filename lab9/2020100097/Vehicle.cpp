#include <iostream>  
  
class Vehicle {  
public:  
    int speed;  
    virtual void start() {  
        std::cout << "Vehicle started" << std::endl;  
    }  
};  
   
class Car : virtual public Vehicle {  
public:  
    void start() override {  
        std::cout << "Car started" << std::endl;  
    }  
};  
  
class Boat : virtual public Vehicle {  
public:  
    void start() override {  
        std::cout << "Boat started" << std::endl;  
    }  
};  
  
class AmphibiousVehicle : public Car, public Boat {  
public:  
    void start() override {  
        Car::start();   
        Boat::start(); 
    }  
};  
  
int main() {  
    AmphibiousVehicle amphibiousVehicle;  
    amphibiousVehicle.speed = 50;
    amphibiousVehicle.start(); 
    return 0;  
}