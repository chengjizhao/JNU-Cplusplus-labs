#include "SampleClass.h"

#include <iostream>

void (*SampleClass::get_private_method_ptr())() {

	// C++��ֱֹ�ӻ�ȡ�Ǿ�̬��Ա������ָ��
	// return SampleClass::private_method; // �������
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