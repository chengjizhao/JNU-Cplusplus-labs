#include <iostream>  
using namespace std;  
  
// 基类 Car  
class Car {  
public:  
    virtual float calculatePrice() {  
        cout << "This function needs to be overridden for each specific car type." << endl;  
        return 0;  
    }  
};  
  
// 派生类 Sedan  
class Sedan : public Car {  
public:  
    float calculatePrice() override {  
        cout << "The Sedan price is calculated." << endl;  
        return 30000.0; // 这里只是一个示例，实际价格应该根据具体情况计算  
    }  
};  
  
// 派生类 SUV  
class SUV : public Car {  
public:  
    float calculatePrice() override {  
        cout << "The SUV price is calculated." << endl;  
        return 40000.0; // 这里只是一个示例，实际价格应该根据具体情况计算  
    }  
};  
  
int main() {  
    Sedan sedan;  
    SUV SUV;  
    Car* carPtr1 = &sedan;  
    Car* carPtr2 = &SUV;  
    carPtr1->calculatePrice(); // 输出：The Sedan price is calculated. 30000.0  
    carPtr2->calculatePrice(); // 输出：The SUV price is calculated. 40000.0  
    return 0;  
}
