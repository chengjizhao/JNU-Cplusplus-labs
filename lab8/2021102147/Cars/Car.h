#pragma once
class Car
{
public:
	virtual int calculatePrice() = 0;

private:
	int price;
};


class Suv : public Car {
public:
	Suv();
	virtual int calculatePrice();
private:
	int price;
};

class Sedan : public Car {
public:
	Sedan();
	virtual int calculatePrice();
private:
	int price;
};


