#include "person.h"

Person::Person() {}

Person::Person(std::string n) : name(n) {}

Person::Person(std::string n, std::string i, std::string b, std::string g, int h, int w)
    : name(n), id(i), birthday(b), gender(g), height(h), weight(w) {}

void Person::setId(std::string i) 
{
    id = i;
}

std::string Person::getId() 
const {
    return id;
}

void Person::setBirthday(std::string b) 
{
    birthday = b;
}

std::string Person::getBirthday() 
const {
    return birthday;
}

void Person::setGender(std::string g) 
{
    gender = g;
}

std::string Person::getGender() 
const {
    return gender;
}

void Person::setHeight(int h) 
{
    height = h;
}

int Person::getHeight() 
const {
    return height;
}

void Person::setWeight(int w)
 {
    weight = w;
}

int Person::getWeight() 
const {
    return weight;
}
