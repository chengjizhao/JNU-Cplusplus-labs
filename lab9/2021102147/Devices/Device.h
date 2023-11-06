#pragma once
class Device
{
public:
	virtual void runApp();
};

class Computer : virtual public Device
{
public:
	void playGalgameDirectly();
};

class Phone : virtual public Device
{
public:
	void makeCall();
};

class SmartDevice : public Computer, public Phone
{

};

