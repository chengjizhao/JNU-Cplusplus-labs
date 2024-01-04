#ifndef SHAPE_H
#define SHAPE_H

#include <math.h>
const double pi = acos(-1);

class Shape
{
    public:
        virtual double calculate_Perimerter() const {return 0.0;}
        virtual double calculate_Area() const {return 0.0;}
};

class Circle : public Shape
{
    private:
        double Radius;
    public:
        Circle(double Radius_) : Radius(Radius_) {};
        double calculate_Perimerter() const override
        {
            return 2 * pi * Radius;
        }
        double calculate_Area() const override
        {
            return pi * Radius * Radius;
        }
};

class Rectangle : public Shape
{
    private:
        double Length;
        double Width;
    public:
        Rectangle(double Length_, double Width_) : Length(Length_), Width(Width_) {};
        double calculate_Perimerter() const override
        {
            return 2 * (Length + Width);
        }
        double calculate_Area() const override
        {
            return Length * Width;
        }
};

#endif