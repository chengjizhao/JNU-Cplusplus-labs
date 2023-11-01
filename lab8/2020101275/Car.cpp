#include <iostream>  
using namespace std;  
  
class Car {  
public:  
    virtual float calculatePrice() {  
        // 基类中的默认价格计算逻辑  
        return 0.0;  
    }  
};  
  
class Sedan : public Car {  
public:  
    float calculatePrice() override {  
        // 轿车价格计算逻辑  
        return 30000.0;  
    }  
};  
  
class SUV : public Car {  
public:  
    float calculatePrice() override {  
        // SUV 价格计算逻辑  
        return 40000.0;  
    }  
};  
  
int main() {  
    Car* carPtr;  
    Sedan sedan;  
    SUV SUV;  
      
    carPtr = &sedan;  
    cout << "Sedan price: " << carPtr->calculatePrice() << endl;  
      
    carPtr = &SUV;  
    cout << "SUV price: " << carPtr->calculatePrice() << endl;  
      
    return 0;  
}