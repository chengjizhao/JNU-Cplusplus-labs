#include "person.h"
#include<iostream>
#include<>

person::Person(){}
person::Person(string n):name(n){}
person::Person(string n, int i, int b, string g, int h, int w){}

void Person::setName(string n)
{
    name=n;
}

void Person::setId(string i) 
{
    id=i;
}

string Person::getId() 
const {
    return id;
}

void Person::setBirthday(string b) 
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
{
    return weight;
}