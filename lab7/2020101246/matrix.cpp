#include <iostream>

// 基类 Shape
class Shape {
public:
    virtual double getArea() const = 0;     // 纯虚函数，用于计算面积
    virtual double getPerimeter() const = 0;    // 纯虚函数，用于计算周长
};

// 派生类 Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

// 派生类 Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double getArea() const override {
        return length * width;
    }

    double getPerimeter() const override {
        return 2 * (length + width);
    }
};

int main() {
    // 创建 Circle 对象并计算面积和周长
    Circle circle(5.0);
    double circleArea = circle.getArea();
    double circlePerimeter = circle.getPerimeter();

    std::cout << "Circle Area: " << circleArea << std::endl;
    std::cout << "Circle Perimeter: " << circlePerimeter << std::endl;

    // 创建 Rectangle 对象并计算面积和周长
    Rectangle rectangle(4.0, 6.0);
    double rectangleArea = rectangle.getArea();
    double rectanglePerimeter = rectangle.getPerimeter();

    std::cout << "Rectangle Area: " << rectangleArea << std::endl;
    std::cout << "Rectangle Perimeter: " << rectanglePerimeter << std::endl;

    return 0;
}