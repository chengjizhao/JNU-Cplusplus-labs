#include <iostream>
#include <cmath>

class Shape {
public:
 virtual double getArea() const =0;
 virtual double getPerimeter() const =0;
};

class Circle : public Shape {
private:
 double radius;

public:
 Circle(double radius) : radius(radius) {}

 double getArea() const override {
 return M_PI * radius * radius;
 }

 double getPerimeter() const override {
 return2 * M_PI * radius;
 }
};

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
 return2 * (length + width);
 }
};

int main() {
 Shape* circle = new Circle(5.0);
 Shape* rectangle = new Rectangle(4.0,6.0);

 std::cout << "Circle Area: " << circle->getArea() << std::endl;
 std::cout << "Circle Perimeter: " << circle->getPerimeter() << std::endl;

 std::cout << "Rectangle Area: " << rectangle->getArea() << std::endl;
 std::cout << "Rectangle Perimeter: " << rectangle->getPerimeter() << std::endl;

 delete circle;
 delete rectangle;

 return 0;
}
