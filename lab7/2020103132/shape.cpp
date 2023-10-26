#include"Shape.h"
#include<iostream>
#include<cmath>

using namespace std;

Circle::Circle(double radius)
{
    this->radius=radius;//半径
}

double Circle::get_perimeter()
{
    return 2*radius*PI;
}

double Circle::get_area()
{
    return radius*radius*PI;
}

Rectangle::Rectangle(double height,double width)
{
    this->height=height;
    this->width=width;
}

double Rectangle::get_perimeter()
{
    return 2*(height+width);
}

double Rectangle::get_area()
{
    return height*width;
}