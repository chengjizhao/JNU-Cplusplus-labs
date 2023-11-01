#include <iostream>
using namespace std;

// 汽车基类
class Car {
public:
    virtual double calculatePrice() = 0; // 虚函数，计算价格
};

// 轿车派生类
class Sedan : public Car {
public:
    double calculatePrice() {
        // 根据轿车类型计算价格
        return 200000;
    }
};

// SUV派生类
class SUV : public Car {
public:
    double calculatePrice() {
        // 根据SUV类型计算价格
        return 300000;
    }
};

int main() {
    Car* car1 = new Sedan();
    Car* car2 = new SUV();

    cout << "轿车价格：" << car1->calculatePrice() << endl;
    cout << "SUV价格：" << car2->calculatePrice() << endl;

    delete car1;
    delete car2;

    return 0;
}
