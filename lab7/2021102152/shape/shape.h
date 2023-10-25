#pragma once
#ifndef Shape_h
#define Shape_h
#define PI 3.141;
#include<iostream>
using namespace std;
class Shape
{
public:
 double getarea() ;
 void getperimeter() ;
 
};
class Circle: public Shape
{
    public:
    Circle();
    double getarea();
    void getperimeter();
    void set(int a);
    private:
    int r;
};

class Rectangle: public Shape
{
    public:
    Rectangle();
    double getarea();
    void getperimeter();
    void set(int a, int b);
    private:
    int length;
    int width;

};
#endif