#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <memory>
#include "Address.h"

class Address;

class Person {
public:
    Person(const std::string& name, int age);
    ~Person();

    void setAddress(std::shared_ptr<Address> address);

private:
    std::string name;
    int age;
    std::shared_ptr<Address> address;
};

#endif // PERSON_H