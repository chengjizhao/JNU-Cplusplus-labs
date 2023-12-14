#include "Person.h"
#include <iostream>
using namespace std;

void Person::set_Address(shared_ptr<Address> address)
{
    this->address = address;
    this->address->person = shared_from_this();
}

string Person::get_Name() const
{
    return name;
}

int Person::get_Age() const
{
    return age;
}

string Address::get_City() const
{
    return city;
}

string Address::get_Street() const
{
    return street;
}