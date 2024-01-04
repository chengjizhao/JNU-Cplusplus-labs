#include <iostream>
#include <cmath>

using namespace std;

// 基类Shape
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape() {}
};

// 派生类Circle
class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}

    double area() const override {
        return 3.14 * radius_ * radius_;
    }

    double perimeter() const override {
        return 2 * 3.14 * radius_;
    }

private:
    double radius_;
};

// 派生类Rectangle
class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double area() const override {
        return width_ * height_;
    }

    double perimeter() const override {
        return 2 * (width_ + height_);
    }

private:
    double width_;
    double height_;
};

int main() {
    Circle circle(5);
    Rectangle rectangle(4, 6);

    cout << "Circle area: " << circle.area() << ", perimeter: " << circle.perimeter() << endl;
    cout << "Rectangle area: " << rectangle.area() << ", perimeter: " << rectangle.perimeter() << endl;

    return 0;
}