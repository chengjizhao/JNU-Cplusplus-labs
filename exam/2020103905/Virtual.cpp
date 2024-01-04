#include <iostream>

// 抽象基类
class Shape {
public:
    virtual void draw() const = 0; // 纯虚函数
};

// 派生类
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

int main() {
    // 无法实例化抽象类Shape
    // Shape s;  // 这会导致编译错误

    Circle c;
    c.draw(); // 调用Circle类的draw函数

    return 0;
}