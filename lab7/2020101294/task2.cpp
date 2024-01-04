#include <iostream>

// Shape 基类
class Shape {
public:
    // 基类构造函数
    Shape() {}

    // 计算面积的方法（在派生类中实现）
    virtual double calculateArea() {
        return 0.0;
    }

    // 计算周长的方法（在派生类中实现）
    virtual double calculatePerimeter() {
        return 0.0;
    }
};

// Circle 派生类
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    // 覆盖基类的方法
    double calculateArea() override {
        return 3.141592653589793238 * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * 3.141592653589793238 * radius;
    }
};

// Rectangle 派生类
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    // 覆盖基类的方法
    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    std::cout << "Circle Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << std::endl;
    std::cout << "Rectangle Area: " << rectangle.calculateArea() << ", Perimeter: " << rectangle.calculatePerimeter() << std::endl;

    return 0;
}