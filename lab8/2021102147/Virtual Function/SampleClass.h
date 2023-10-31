#pragma once

#include <string>


class SampleClass
{
public:
	virtual void VirtualMethod();
	virtual void VirtualMethod2();
	void (*fptr)() = nullptr;

};

class SampleClassExtend : public SampleClass
{
public:
	virtual void VirtualMethod();
};

class SampleClassExtend2 : public SampleClass
{

};

