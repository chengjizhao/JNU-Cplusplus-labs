/*设计一个几何图形类层次结构，包括基类Shape和派生类如Circle、Rectangle。演示如何
使用继承来计算不同形状的面积和周长，并画UML类图。*/
#pragma once
#ifndef Shape_h
#define Shape_h
#define PI 3.14;
using namespace std;

class Shape
{
    public:
    virtual double get_perimeter()=0;
    virtual double get_area()=0;
};

class Circle:public Shape
{
    public:
    Circle(double radius);
    virtual double get_perimeter();
    virtual double get_area();
    private:
    double radius;
};

class Rectengle:public Shape
{
    public:
    Rectengle(double height,double width);
    virtual double get_perimeter();
    virtual double get_area();
    private:
    double height;
    double width;
};

#endif
#pragma once