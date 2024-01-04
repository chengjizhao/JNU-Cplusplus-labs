#include "person.h"
#include <iostream>
using namespace std; 

Person::Person(){}
Person::Person(string& name)
{
	name_ = name;
}

	void Person::setName(string& name)
	{
		name_ = name;
	}
	void Person::setId(string& id)
	{
		id_ = id;
	}
	void Person::setBirthyear(string& birthyear)
	{
		birthyear_ = birthyear;
	}
	void Person::setBirthmonth(string& birthmonth)
	{
		birthmonth_ = birthmonth;
	}
	void Person::setBirthday(string& birthday)
	{
		birthday_ = birthday;
	}
	void Person::setWeight(double weight)
	{
		weight_ = weight;
	}
	void Person::setHeight(double height)
	{
		height_ = height;
	}
	string Person::getName()
	{
		return name_;
	}
	string Person::getId()
	{
		return id_;
	}
	string Person::getBirthyear()
	{
		return birthyear_;
	}
	string Person::getBirthmonth()
	{
		return birthmonth_;
	}
	string Person::getBirthday()
	{
		return birthday_;
	}
	double Person::getWeight()
	{
		return weight_;
	}
	double Person::getHeight()
	{
		return height_;
	}
