#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <memory>
#include "Person.h"

class Person; 

class Address {
public:
    Address(const std::string& city, const std::string& street);
    ~Address();

    void addResident(std::shared_ptr<Person> person);

private:
    std::string city;
    std::string street;
    std::weak_ptr<Person> resident;
};

#endif // ADDRESS_H