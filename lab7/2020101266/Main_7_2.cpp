#include <iostream>  
#include <cmath>  
#define M_PI       3.14159265358979323846

class Shape {
public:
    virtual double calculate_area() const = 0;
    virtual double calculate_perimeter() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculate_area() const override {
        return M_PI * radius * radius;
    }
    double calculate_perimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculate_area() const override {
        return width * height;
    }
    double calculate_perimeter() const override {
        return 2 * (width + height);
    }
};

int main() {
    Circle circle(5);
    Rectangle rectangle(4, 6);
    std::cout << "Circle area: " << circle.calculate_area() << std::endl;
    std::cout << "Circle perimeter: " << circle.calculate_perimeter() << std::endl;
    std::cout << "Rectangle area: " << rectangle.calculate_area() << std::endl;
    std::cout << "Rectangle perimeter: " << rectangle.calculate_perimeter() << std::endl;
    return 0;
}