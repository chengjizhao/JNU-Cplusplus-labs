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

Rectengle::Rectengle(double height,double width)
{
    this->height=height;
    this->width=width;
}

double Rectengle::get_perimeter()
{
    return 2*(height+width);
}

double Rectengle::get_area()
{
    return height*width;
}