#include "Person.h"

#include <iostream>

Person::Person(const std::string& name, int age, Address& addr) {
  this->name = name;
  this->age = age;
  this->addr = std::make_shared<Address>(addr);
}

std::string Person::getName() const { return name; }

int Person::getAge() const { return age; }

void Person::printAddr() const { addr->printAddr(); }

Address::Address(const char* addr) { this->addr = addr; }

void Address::printAddr() const { std::cout << addr << std::endl; }

void Address::setAddr(const char* addr) { this->addr = addr; }

void Address::addPerson(std::shared_ptr<Person> sp) { persons.push_back(sp); }

const std::vector<std::weak_ptr<Person>>& Address::getPersons() const {
  return persons;
}