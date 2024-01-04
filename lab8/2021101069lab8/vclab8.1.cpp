#include <iostream>  
  
// 基类 Car  
class Car {  
public:  
    virtual float calculatePrice() const {  
        return 0.0;  
    }  
};  
  
// 派生类 Sedan  
class Sedan : public Car {  
public:  
    float calculatePrice() const override {  
        return 30000.0; 
    }  
};  
  
// 派生类 SUV  
class SUV : public Car {  
public:  
    float calculatePrice() const override {  
        return 40000.0; 
    }  
};  
  
int main() {  
    // 创建 Car 对象数组，包含 Sedan 和 SUV 对象  
    Car* cars[2];  
    cars[0] = new Sedan();  
    cars[1] = new SUV();  
      
    // 调用 calculatePrice 方法并输出结果  
    for (int i = 0; i < 2; ++i) {  
        std::cout << "Car type: " << (i == 0 ? "Sedan" : "SUV") << ", price: " << cars[i]->calculatePrice() << std::endl;  
        delete cars[i];  // 释放内存  
    }  
      
    return 0;  
}