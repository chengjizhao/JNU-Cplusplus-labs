#include "SampleClass.h"

#include <iostream>

void SampleClass::VirtualMethod() {
	std::cout << "I am virtual method of base class" << std::endl;
}

void SampleClass::VirtualMethod2() {
	std::cout << "I am the second virtual method of base class" << std::endl;
}

void SampleClassExtend::VirtualMethod() {
	std::cout << "I am virtual method of child class" << std::endl;
}

