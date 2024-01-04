// person.cpp
#include "person.h"

Person::Person(const std::string& name) : name(name) {}

Person::Person(const std::string& name, const std::string& id, const std::string& birthdate, const std::string& gender, double height, double weight)
        : name(name), id_(id), birthdate_(birthdate), gender_(gender), height_(height), weight_(weight) {}

void Person::set_id(const std::string& id) {
    id_ = id;
}

void Person::set_birthdate(const std::string& birthdate) {
    birthdate_ = birthdate;
}

void Person::set_gender(const std::string& gender) {
    gender_ = gender;
}

void Person::set_height(double height) {
    height_ = height;
}

void Person::set_weight(double weight) {
    weight_ = weight;
}

std::string Person::get_id() const {
    return id_;
}

std::string Person::get_birthdate() const {
    return birthdate_;
}

std::string Person::get_gender() const {
    return gender_;
}

double Person::get_height() const {
    return height_;
}

double Person::get_weight() const {
    return weight_;
}
