// Person.cpp
#include "Person.h"
#include "Address.h"
#include <iostream>

Person::Person(const std::string& name, int age)
    : name(name), age(age) {}

Person::~Person() {
    std::cout << name << " is being destroyed." << std::endl;
}

void Person::setAddress(std::shared_ptr<Address> address) {
    this->address = address;
}