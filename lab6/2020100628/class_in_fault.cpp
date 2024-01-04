#include <iostream>

class MyClass {
private:
    void pr() {
        std::cout << "Private " << std::endl;
    }

public:
    void pu() {
        std::cout << "Public " << std::endl;
    }
};

int main() {
    MyClass obj;
    
    void (MyClass::*prtr)() = &MyClass::pr; // 函数指针调用私有成员函数
    //error：函数 "MyClass::privateMethod" (已声明 所在行数:5) 不可访问
    (obj.*prtr)();
    
    obj.pu();
    
    return 0;
}