#include "Person.h"  
#include <string>  
#include <iostream>  
#include <cstdlib> // for size_t type and malloc/free functions  

Person::Person() : name(""), id(""), birthdate(""), gender(""), height(0.0), weight(0.0) {}

Person::Person(const std::string& name, const std::string& id, const std::string& birthdate,
    const std::string& gender, double height, double weight)
    : name(name), id(id), birthdate(birthdate), gender(gender), height(height), weight(weight) {}

std::string Person::getID() const { return id; }
std::string Person::getBirthdate() const { return birthdate; }
std::string Person::getGender() const { return gender; }
double Person::getHeight() const { return height; }
double Person::getWeight() const { return weight; }

void Person::setID(const std::string& id) { this->id = id; }
void Person::setBirthdate(const std::string& birthdate) { this->birthdate = birthdate; }
void Person::setGender(const std::string& gender) { this->gender = gender; }
void Person::setHeight(double height) { this->height = height; }
void Person::setWeight(double weight) { this->weight = weight; }