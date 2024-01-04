#include "person.h"

Person::Person() {
    name = "";
    id = "";
    dateOfBirth = "";
    gender = "";
    height = 0.0;
    weight = 0.0;
}

Person::Person(const std::string& name) {
    this->name = name;
    id = "";
    dateOfBirth = "";
    gender = "";
    height = 0.0;
    weight = 0.0;
}

Person::Person(const std::string& name, const std::string& id, const std::string& dob,
    const std::string& gender, double height, double weight) {
    this->name = name;
    this->id = id;
    this->dateOfBirth = dob;
    this->gender = gender;
    this->height = height;
    this->weight = weight;
}

std::string Person::getName() const {
    return name;
}

std::string Person::getId() const {
    return id;
}

std::string Person::getDateOfBirth() const {
    return dateOfBirth;
}

std::string Person::getGender() const {
    return gender;
}

double Person::getHeight() const {
    return height;
}

double Person::getWeight() const {
    return weight;
}

void Person::setId(const std::string& id) {
    this->id = id;
}

void Person::setDateOfBirth(const std::string& dob) {
    dateOfBirth = dob;
}

void Person::setGender(const std::string& gender) {
    this->gender = gender;
}

void Person::setHeight(double height) {
    this->height = height;
}

void Person::setWeight(double weight) {
    this->weight = weight;
}