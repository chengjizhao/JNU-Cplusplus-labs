#include <iostream>

// 基类
class BaseClass {
public:
    virtual void virtualFunction() const {
        std::cout << "BaseClass virtualFunction" << std::endl;
    }
};

// 派生类
class DerivedClass : public BaseClass {
public:
    void virtualFunction() const override {
        std::cout << "DerivedClass virtualFunction" << std::endl;
    }
};

int main() {
    BaseClass* obj = new DerivedClass();  // 使用基类指针指向派生类对象
    obj->virtualFunction();  // 调用虚函数，运行时将调用DerivedClass的实现

    delete obj;
    // 等待用户输入，防止程序立即退出
    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();
    return 0;
}