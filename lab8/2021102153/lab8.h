#ifndef  _LAB8_H_
#define  _LAB8_H_
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Car
{
    public:
    virtual void calculatePrice(int a,string b);
};
class Suv : public Car {
public:
	
	virtual void calculatePrice(int a,string b);
private:
	int price;
    string name;
};
class Sedan : public Car {
public:
	
	virtual void calculatePrice(int a,string b);
private:
	int price;
    string name;
};
#endif