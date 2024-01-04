#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
};

class Circle : public Shape 
{
public:
    Circle(double r) 
    {
        R = r;
    }

    double area()
    {
        return 3.14159 * R * R;
    }

private:
    double R;//半径
};

class Rectangle : public Shape 
{


public:
    Rectangle(double w, double h) 
    { 
        Width = w;
        Height = h; 
    }

    double area()
    {
        return Width * Height;
    }

private:
    double Width;//长
    double Height;//宽
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(3);
    shapes[1] = new Rectangle(5.6, 6.5);

    for (int i = 0; i < 2; i++) {
        std::cout << "Area: " << shapes[i]->area() << std::endl;
    }

    delete[] shapes;
    system("pasue");
    return 0;
}
