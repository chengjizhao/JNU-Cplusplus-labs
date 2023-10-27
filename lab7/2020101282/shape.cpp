#include <iostream>

class Shape {
public:
    // 基类中定义了虚拟函数，用于计算面积和周长
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    // 构造函数
    Circle(double r) : radius(r) {}

    // 重载基类的虚拟函数
    double getArea() const override {
        return 3.14159265359 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14159265359 * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // 构造函数
    Rectangle(double l, double w) : length(l), width(w) {}

    // 重载基类的虚拟函数
    double getArea() const override {
        return length * width;
    }

    double getPerimeter() const override {
        return 2 * (length + width);
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // 计算不同形状的面积和周长
    std::cout << "圆的面积: " << circle.getArea() << std::endl;
    std::cout << "圆的周长: " << circle.getPerimeter() << std::endl;

    std::cout << "矩形的面积: " << rectangle.getArea() << std::endl;
    std::cout << "矩形的周长: " << rectangle.getPerimeter() << std::endl;

    return 0;
}
