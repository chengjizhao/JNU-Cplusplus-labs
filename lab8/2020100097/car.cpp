#include <iostream>  
    
class Car {  
public:  
    virtual double calculatePrice() {  
        std::cout << "The price of the car is not available." << std::endl;  
        return -1;  
    }  
};  
  
class Sedan : public Car {  
public:  
    double calculatePrice() override {  
        std::cout << "The price of the sedan is $20,000." << std::endl;  
        return 20000;  
    }  
};  
   
class SUV : public Car {  
public:  
    double calculatePrice() override {  
        std::cout << "The price of the SUV is $30,000." << std::endl;  
        return 30000;  
    }  
};  
  
int main() {  
    Car* car = new Sedan(); 
    double price = car->calculatePrice(); 
    if (price != -1) { 
        std::cout << "The price of the car is $" << price << "." << std::endl;  
    }  
    delete car;   
    return 0;  
}