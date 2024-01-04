
#include "person.h"

person::person() {}

person::person(std::string n) : name(n) {}

person::person(std::string n, std::string id, std::string dob, std::string gender,
               double height, double weight)
    : name(n), id(id), dob(dob), gender(gender), height(height), weight(weight) {}

std::string person::getId() const {
    return id;
}

void person::setId(std::string id) {
    this->id = id;
}

std::string person::getDob() const {
    return dob;
}

void person::setDob(std::string dob) {
    this->dob = dob;
}

std::string person::getGender() const {
    return gender;
}

void person::setGender(std::string gender) {
    this->gender = gender;
}

double person::getHeight() const {
    return height;
}

void person::setHeight(double height) {
    this->height = height;
}

double person::getWeight() const {
    return weight;
}

void person::setWeight(double weight) {
    this->weight = weight;
}