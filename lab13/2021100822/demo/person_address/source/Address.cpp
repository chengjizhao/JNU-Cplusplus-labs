#include "Address.h"
#include "Person.h"
#include <iostream>

Address::Address(const std::string& city, const std::string& street)
    : city(city), street(street) {}

Address::~Address() {
    std::cout << "Address in " << city << " is being destroyed." << std::endl;
}

void Address::addResident(std::shared_ptr<Person> person) {
    resident = person;
}