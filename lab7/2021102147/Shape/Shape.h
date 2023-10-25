#pragma once
class Shape
{
public:
	virtual double get_perimeter() = 0;
	virtual double get_area() = 0;
};

class Circle : public Shape {
public:
	Circle(double radius);
	virtual double get_area();
	virtual double get_perimeter();
private:
	double radius;
};

class Rectangle : public Shape {
public:
	Rectangle(double width, double height);
	virtual double get_area();
	virtual double get_perimeter();
private:
	double width;
	double height;
};


