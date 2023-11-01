#include <iostream>
#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    double basePrice;

public:
    // 构造函数，用于初始化品牌、型号和基础价格
    Car(std::string brand, std::string model, double basePrice)
        : brand(brand), model(model), basePrice(basePrice) {}

    // 虚函数，可在派生类中重写
    virtual double calculatePrice() {
        return basePrice;
    }
};

class Sedan : public Car {
public:
    // Sedan类的构造函数，调用基类Car的构造函数进行初始化
    Sedan(std::string brand, std::string model, double basePrice)
        : Car(brand, model, basePrice) {}

    // 重写基类的calculatePrice()函数，根据Sedan类型的特定价格进行计算
    double calculatePrice() override {
        return basePrice + 4000.0; // Sedan类型增加4000元
    }
};

class SUV : public Car {
public:
    // SUV类的构造函数，调用基类Car的构造函数进行初始化
    SUV(std::string brand, std::string model, double basePrice)
        : Car(brand, model, basePrice) {}

    // 重写基类的calculatePrice()函数，根据SUV类型的特定价格进行计算
    double calculatePrice() override {
        return basePrice + 5000.0; // SUV类型增加5000元
    }
};

int main() {
    // 创建Sedan和SUV对象，传入品牌、型号和基础价格
    Sedan sedan("Brand1", "Model1", 20000.0);
    SUV suv("Brand2", "Model2", 30000.0);

    // 调用各自对象的calculatePrice()函数并打印价格
    std::cout << "Sedan Price: " << sedan.calculatePrice() <<"元"<< std::endl;
    std::cout << "SUV Price: " << suv.calculatePrice() << "元"<<std::endl;

    return 0;
}
