#include <iostream>  
#include <cmath>  
  
// Shape 基类  
class Shape {  
public:  
    virtual float getArea() const = 0;  
    virtual float getPerimeter() const = 0;  
};  
  
// Circle 派生类  
class Circle : public Shape {  
public:  
    Circle(float radius) : radius_(radius) {}  
  
    float getArea() const override {  
        return static_cast<float>(M_PI * radius_ * radius_);  
    }  
  
    float getPerimeter() const override {  
        return 2.0f * M_PI * radius_;  
    }  
  
private:  
    float radius_;  
};  
  
// Rectangle 派生类  
class Rectangle : public Shape {  
public:  
    Rectangle(float width, float height) : width_(width), height_(height) {}  
  
    float getArea() const override {  
        return width_ * height_;  
    }  
  
    float getPerimeter() const override {  
        return 2.0f * (width_ + height_);  
    }  
  
private:  
    float width_;  
    float height_;  
};  
  
int main() {  
    Circle circle(5.0f);  
    Rectangle rectangle(4.0f, 6.0f);  
  
    std::cout << "Circle area: " << circle.getArea() << std::endl;  
    std::cout << "Circle perimeter: " << circle.getPerimeter() << std::endl;  
    std::cout << "Rectangle area: " << rectangle.getArea() << std::endl;  
    std::cout << "Rectangle perimeter: " << rectangle.getPerimeter() << std::endl;  
  
    return 0;  
}
