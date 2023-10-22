#include <iostream>

using namespace std;

//父类
class Shape
{
private:
    int color;

protected:
    float perimeter_;
    float area_;

public:
    Shape(float p = 0, float a = 0)
    {
        perimeter_ = p;
        area_ = a;
        cout << "Shape Created" << endl;
    }

    void printPerimeter()
    {
        cout << perimeter_ << endl;
    }

    void printArea()
    {
        cout << area_ << endl;
    }
};


//子类1
class Circle: public Shape
{
private:
    float radius_ = 0;
    float pi = 3.1416;
public:
    Circle(float radius = 0): radius_(radius){cout << "Circle Created" << endl;}

    void PerimeterCalculate()
    {
        perimeter_ = 2 * pi * radius_;
        printPerimeter();
    }

    void AreaCalculate()
    {
        area_ = pi * radius_ * radius_;
        printArea();
    }
};


//子类2
class Rectangle: public Shape
{
private:
    float length_ = 0;
    float width_ = 0;
public:
    Rectangle(float length, float width): length_(length), width_(width){cout << "Rectangle Created" << endl;}

    void PerimeterCalculate()
    {
        perimeter_ = 2 * (length_ + width_);
        printPerimeter();
    }

    void AreaCalculate()
    {
        area_ = length_ * width_;
        printArea();
    }
};



int main()
{
    Shape A(1,2);
    Circle B(3);
    Rectangle C(4,5);
    //发现在调用子类构造函数时,会先使用父类构造函数,再调用子类构造函数
    return 0;
}




