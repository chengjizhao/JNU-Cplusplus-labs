#include "Binary.h"
#include <iostream>
#include <cstdlib>

Binary::Binary()
{
	bits.push_back(0);
	size = 1;
}

Binary::Binary(unsigned int n)
{
	if (n == 0)
	{
		bits.push_back(0);
		size = 1;
		return;
	}
	while (n)
	{
		bits.push_back(n % 2);
		n /= 2;
	}
	size = bits.size();
}

Binary::Binary(std::string& s)
{
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '0')
			bits.push_back(0);
		else
			bits.push_back(1);
	}
	size = bits.size();
}

Binary::Binary(Binary& another)
{
	size = another.size;
	bits = another.bits;
}

void Binary::setSize(unsigned char size)
{
	bits.resize(size);
	this->size = size;
}

int Binary::getSize()
{
	return size;
}

bool Binary::operator[](int n)const
{
	return bits[n];
}

bool Binary::operator==(Binary& b)
{
	return bits == b.bits;
}

Binary Binary::operator&(Binary& b)
{
	Binary result;
	result.setSize(std::max(size, b.size));
	for (int i = 0; i < std::min(size, b.size); i++)
	{
		bits[i] && b.bits[i] ? result.bits[i] = 1 : result.bits[i] = 0;
	}
	return result;
}

Binary Binary::operator|(Binary& b)
{
	Binary result;
	result.setSize(std::max(size, b.size));
	for (int i = 0; i < std::min(size, b.size); i++)
	{
		bits[i] || b.bits[i] ? result.bits[i] = 1 : result.bits[i] = 0;
	}
	return result;
}

Binary Binary::operator~()
{
	Binary result;
	result.setSize(size);
	for (int i = 0; i < size; i++)
	{
		result.bits[i] = !bits[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, Binary& b)
{
	for (auto i : b.bits)
	{
		os << i;
	}
	return os;
}
