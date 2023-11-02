#include <iostream>

class Car {
public:
 virtual double calculatePrice() const =0;
};

class Sedan : public Car {
public:
 double calculatePrice() const override {
 // 计算 Sedan 类型汽车的价格 
return 20000.0;
 }
};

class SUV : public Car {
public:
 double calculatePrice() const override {
 // 计算 SUV 类型汽车的价格 
 return 30000.0;
 }
};

int main() {
 Car* car1 = new Sedan();
 Car* car2 = new SUV();

 std::cout << "Car1 price: " << car1->calculatePrice() << std::endl;
 std::cout << "Car2 price: " << car2->calculatePrice() << std::endl;

 delete car1;
 delete car2;

 return 0;
}
