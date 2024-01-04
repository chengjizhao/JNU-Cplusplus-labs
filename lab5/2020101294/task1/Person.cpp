#include "Person.h"

Person::Person(const std::string& name) : name(name) {
    id = "";
    birthDate = "";
    gender = ' ';
    height = 0.0;
    weight = 0.0;
}

Person::Person(const std::string& name, const std::string& id, const std::string& birthDate, char gender, double height, double weight)
    : name(name), id(id), birthDate(birthDate), gender(gender), height(height), weight(weight) {
}

const std::string& Person::GetName() const {
    return name;
}

const std::string& Person::GetID() const {
    return id;
}

const std::string& Person::GetBirthDate() const {
    return birthDate;
}

char Person::GetGender() const {
    return gender;
}

double Person::GetHeight() const {
    return height;
}

double Person::GetWeight() const {
    return weight;
}

void Person::SetID(const std::string& id) {
    this->id = id;
}

void Person::SetBirthDate(const std::string& birthDate) {
    this->birthDate = birthDate;
}

void Person::SetGender(char gender) {
    this->gender = gender;
}

void Person::SetHeight(double height) {
    this->height = height;
}

void Person::SetWeight(double weight) {
    this->weight = weight;
}