#pragma once
#include<iostream>
using namespace std;
class Device
{
public:
	virtual void runApp();
};

class Computer : virtual public Device
{
public:
	virtual void runApp();
};

class Phone : virtual public Device
{
public:
virtual void runApp();
};

class SmartDevice : public Computer, public Phone
{
public:
virtual void runApp();

};