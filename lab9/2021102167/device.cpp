#include <iostream>
using namespace std;

class Device 
{
public:
	void Func();
	virtual void runApp()
	{}
};

class Computer :public Device
{
public:
	void runApp()override
	{
		cout << "computer overrided" << endl;
	}
};

class Phone :public Device
{
public:
	void runApp()override
	{
		cout << "phone overrided" << endl;
	}
};

class Smartdevice : public Computer, public Phone
{
public:
	void runApp() override
	{
		cout << "smartdevice overrided" << endl;
	}
};

int main()
{
	Smartdevice dev1;
	Computer dev2;
	dev1.runApp();
	dev2.runApp();
	return 0;
}