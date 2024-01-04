#include <iostream>
#include <string>

#include "Binary.h"

int main()
{
	std::string s1("10011001");
	std::string s2("11110000");
	Binary b1(s1), b2(s2);
	
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	
	b1 = b1 & b2;
	std::cout << b1 << std::endl;
	
	return 0;
}