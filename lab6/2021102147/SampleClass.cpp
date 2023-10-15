#include "SampleClass.h"

#include <iostream>

void (*SampleClass::get_private_method_ptr())() {

	// C++禁止直接获取非静态成员方法的指针
	// return SampleClass::private_method; // 编译错误
	return SampleClass::static_private_method;
}

void SampleClass::static_private_method() {
	std::cout << "Hello, I am a static private method." << std::endl;
}

void SampleClass::private_method() {
	std::cout << "Hello, I am a private method." << std::endl;
}


void SampleClass::call_private_method() {
	std::cout << "Hello, I am a public method, now I am going to call a private method." << std::endl;
	SampleClass::private_method();
}