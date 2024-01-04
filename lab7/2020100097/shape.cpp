#include <iostream>  
#include <cmath>  
  
class Shape {  
public:  
    virtual double getArea() const = 0;  
    virtual double getPerimeter() const = 0;  
};  
  
class Circle : public Shape {  
private:  
    double radius;  
public:  
    Circle(double r) : radius(r) {}  
    double getArea() const override { return M_PI * radius * radius; }  
    double getPerimeter() const override { return 2 * M_PI * radius; }  
};  
  
class Rectangle : public Shape {  
private:  
    double width;  
    double height;  
public:  
    Rectangle(double w, double h) : width(w), height(h) {}  
    double getArea() const override { return width * height; }  
    double getPerimeter() const override { return 2 * (width + height); }  
};  
  
int main() {  
    Circle circle(5);  
    Rectangle rectangle(4, 6);  
  
    std::cout << "Circle area: " << circle.getArea() << std::endl;  
    std::cout << "Circle perimeter: " << circle.getPerimeter() << std::endl;  
    std::cout << "Rectangle area: " << rectangle.getArea() << std::endl;  
    std::cout << "Rectangle perimeter: " << rectangle.getPerimeter() << std::endl;  
  
    return 0;  
}