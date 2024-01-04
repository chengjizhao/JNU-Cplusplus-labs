#include "person.h"
#include <iostream>
using namespace std;

Person::Person() {}

Person::Person(string& n)
{
    name = n;
}

void Person::setID(string& id)
{
    pid = id;
}

void Person::setBirthday(string& bd)
{
    pbd = bd;
}

void Person::setGender(string& gender)
{
    pg = gender;
}

void Person::setHeight(double h)
{
    ph = h;
}

void Person::setWeight(double w)
{
    pw = w;
}

string Person::getID()
{
    return pid;
}

string Person::getBirthday()
{
    return pbd;
}

string Person::getGender()
{
    return pg;
}

double Person::getHeight()
{
    return ph;
}

double Person::getWeight()
{
    return pw;
}