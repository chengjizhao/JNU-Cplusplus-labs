#pragma once

#include <vector>
#include <string>

class Binary
{
public:
	Binary();
	Binary(unsigned int n);
	Binary(std::string& s);
	Binary(Binary& another);
	void setSize(unsigned char size);
	int getSize();
	bool operator[](int n)const;
	bool operator==(Binary& b);
	Binary operator&(Binary& b);
	Binary operator|(Binary& b);
	Binary operator~();
	friend std::ostream& operator<<(std::ostream& os, Binary& b);
	
private:
	int size;
	std::vector<bool> bits;
};

