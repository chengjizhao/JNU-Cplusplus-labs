#include "person.h"
#include <iostream>

Person::Person() {}

Person::Person(const std::string& name, const std::string& id, const std::string& dob,
               const std::string& gender, double height, double weight)
    : name(name), id(id), dob(dob), gender(gender), height(height), weight(weight) {}

std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

std::string Person::getID() const {
    return id;
}

void Person::setID(const std::string& id) {
    this->id = id;
}

std::string Person::getDOB() const {
    return dob;
}

void Person::setDOB(const std::string& dob) {
    this->dob = dob;
}

std::string Person::getGender() const {
    return gender;
}

void Person::setGender(const std::string& gender) {
    this->gender = gender;
}

double Person::getHeight() const {
    return height;
}

void Person::setHeight(double height) {
    this->height = height;
}

double Person::getWeight() const {
    return weight;
}

void Person::setWeight(double weight) {
    this->weight = weight;
}

void Person::inputFromTerminal() {
    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter ID: ";
    std::cin >> id;

    std::cout << "Enter Date of Birth: ";
    std::cin >> dob;

    std::cout << "Enter Gender: ";
    std::cin >> gender;

    std::cout << "Enter Height: ";
    std::cin >> height;

    std::cout << "Enter Weight: ";
    std::cin >> weight;
}
