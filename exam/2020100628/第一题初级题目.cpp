#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double area() const = 0; 
    virtual ~Shape() = default;    
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
};

int main() {
    Shape* shapes[] = { new Circle(5.0), new Rectangle(4.0, 6.0) };

    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->area() << std::endl;
    }

    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
