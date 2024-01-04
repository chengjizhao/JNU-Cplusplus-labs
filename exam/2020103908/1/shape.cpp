#include <iostream>
#include <cmath>

// 抽象基类 Shape
class Shape {
public:
    // 纯虚函数 area
    virtual double area() const = 0;

    // 虚析构函数
    virtual ~Shape() = default;
};

// Circle 类，派生自 Shape
class Circle : public Shape {
private:
    double radius;

public:
    // 构造函数
    Circle(double _radius) : radius(_radius) {}

    // 实现基类的纯虚函数 area 来计算圆的面积
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// Rectangle 类，派生自 Shape
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // 构造函数
    Rectangle(double _length, double _width) : length(_length), width(_width) {}

    // 实现基类的纯虚函数 area 来计算矩形的面积
    double area() const override {
        return length * width;
    }
};

int main() {
    // 创建 Shape 指针数组，包含一个 Circle 和一个 Rectangle 对象
    Shape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    // 调用 area 函数计算并输出面积
    for (int i = 0; i < 2; ++i) {
        std::cout << "Shape " << (i + 1) << " Area: " << shapes[i]->area() << std::endl;
    }

    // 释放内存
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }

    return 0;
}
