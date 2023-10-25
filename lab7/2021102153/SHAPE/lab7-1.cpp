#include <iostream>
#include <string>
#include "math.h"
#define pi 3.14
using namespace std;
class Shape
{
public:
string name;//名称
double area;//面积
double perimeter;//周长
void show()
{
    cout << "name:" << name << endl << "area:" << area << endl << "perimeter:" << perimeter << endl;
}
};

class Circle:public Shape//圆
{
public:
double radius;//半径
Circle(double t)
{
    radius=t;
    name="Circle";
    area=2*pi*t*t;
    perimeter=2*pi*t;
}
};

class Triangle:public Shape
{
public:
double a;//三边长
double b;
double c;
Triangle(double a,double b,double c)
{   
    double p=(a+b+c)/2;
    name="Triangle";
    area=sqrt(p*(p-a)*(p-b)*(p-c));
    perimeter=a+b+c;
}
};
class Rectangle:public Shape
{
public:
double a;
double b;//长和宽
Rectangle(double a,double b)
{
    name="Rectangle";
    area=a*b;
    perimeter=2*(a+b);

}
};

int main()
{
    Circle a(2);
    a.show();
    Triangle b(2,2,3);
    b.show();
    Rectangle c(2,3);
    c.show();
}
