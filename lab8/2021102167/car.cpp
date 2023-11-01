#include <iostream>

using namespace std;
class car 
{
public:
	virtual float calculatePrice() 
	{
		return 0;
	}
};

class Sedan :public car 
{
public:
	virtual float calculatePrice()
	{
		return 99999.9;
	}
};

class SUV :public car 
{
public:
	virtual float calculatePrice()
	{
		return 333333.3;
	}
};

int main()
{
	SUV suv;
	Sedan sd;
	cout << "THR PRICE OF SUV " << suv.calculatePrice() << endl;
	cout << "THR PRICE OF Sedan " << sd.calculatePrice() << endl;
	return 0;
}