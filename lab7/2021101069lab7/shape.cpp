#include<iostream>
class Shape {  
public:  
    virtual float getArea() const = 0;  
    virtual float getPerimeter() const = 0;  
};
class Circle : public Shape {  
private:  
    float radius;  
public:  
    Circle(float r) : radius(r) {}  
  
    float getArea() const override {  
        return 3.14f * radius * radius;  
    }  
  
    float getPerimeter() const override {  
        return 2 * 3.14f * radius;  
    }  
};
class Rectangle : public Shape {  
private:  
    float width;  
    float height;  
public:  
    Rectangle(float w, float h) : width(w), height(h) {}  
  
    float getArea() const override {  
        return width * height;  
    }  
  
    float getPerimeter() const override {  
        return 2 * (width + height);  
    }  
};
int main() {  
    Circle circle(5.0f);  
    Rectangle rectangle(4.0f, 6.0f);  
  
    float circleArea = circle.getArea();  
    float circlePerimeter = circle.getPerimeter();  
    float rectangleArea = rectangle.getArea();  
    float rectanglePerimeter = rectangle.getPerimeter();  
  
    std::cout << "Circle area: " << circleArea << std::endl;  
    std::cout << "Circle perimeter: " << circlePerimeter << std::endl;  
    std::cout << "Rectangle area: " << rectangleArea << std::endl;  
    std::cout << "Rectangle perimeter: " << rectanglePerimeter << std::endl;  
  
    return 0;  
}