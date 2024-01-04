#include <iostream>
// 抽象类
class Shape {
public:
    // 纯虚函数
    virtual void draw() const = 0;
};

// 派生类
class Circle : public Shape {
public:
    // 实现纯虚函数
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

int main() {
    // 创建派生类对象
    Circle circle;

    // 获取对象的地址
    uintptr_t* vptr = *reinterpret_cast<uintptr_t**>(&circle);

    // 输出虚函数表中的函数地址
    std::cout << "Virtual Function Table (Address): " << vptr << std::endl;

    // 获取虚函数表中第一个函数的地址，即 draw 函数的地址
    uintptr_t drawFunctionAddress = vptr[0];
    std::cout << "Draw Function Address: " << drawFunctionAddress << std::endl;

    // 通过虚函数表调用 draw 函数
    typedef void (*DrawFunction)(const Shape*);
    DrawFunction drawFunction = reinterpret_cast<DrawFunction>(drawFunctionAddress);
    drawFunction(&circle);

    return 0;
}
