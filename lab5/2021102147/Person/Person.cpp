#include "Person.h"

Person::Person()
{
	name = "Annonymous";

	birth_year = 1970;
	birth_month = 1;
	birth_day = 1;

	height = 170;
	weight = 50;

	id_number = "000000000000000000";
}

Person::Person(std::string name, int birth_year, int birth_month, int birth_day, int height, int weight, std::string id_number)
{
	this->name = name;

	this->birth_year = birth_year;
	this->birth_month = birth_month;
	this->birth_day = birth_day;

	this->height = height;
	this->weight = weight;

	this->id_number = id_number;
}

Person::Person(const char* name, int birth_year, int birth_month, int birth_day, int height, int weight, const char* id_number)
{
	this->name = name;

	this->birth_year = birth_year;
	this->birth_month = birth_month;
	this->birth_day = birth_day;

	this->height = height;
	this->weight = weight;

	this->id_number = id_number;
}

Person::~Person()
{
}

void Person::setName(const char* name)
{
	this->name = name;
}

void Person::setBirth(int year, int month, int day)
{
	birth_year = year;
	birth_month = month;
	birth_day = day;
}

void Person::setHeight(int height)
{
	this->height = height;
}

void Person::setWeight(int weight)
{
	this->weight = weight;
}

std::string Person::getName()
{
	return name;
}

bool Person::getGender() {
	return gender;
}

int Person::getBirthYear()
{
	return birth_year;
}

int Person::getBirthMonth()
{
	return birth_month;
}

int Person::getBirthDay()
{
	return birth_day;
}

int Person::getHeight()
{
	return height;
}

int Person::getWeight()
{
	return weight;
}

std::string Person::getIDNumber()
{
	return id_number;
}


void Person::setIDNumber(const char* id_number)
{
	this->id_number = id_number;
}


