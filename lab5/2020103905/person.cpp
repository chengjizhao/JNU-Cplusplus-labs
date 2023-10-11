#include "person.h"

Person::Person() {
    // 默认构造函数
}

Person::Person(const std::string& n) : name(n) {
    // 使用名字初始化对象
}

Person::Person(const std::string& n, const std::string& id, const std::string& dob, char g, double h, double w)
    : name(n), ID(id), DOB(dob), gender(g), height(h), weight(w) {
    // 使用给定的数据初始化对象
}

std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& n) {
    name = n;
}

std::string Person::getID() const {
    return ID;
}

void Person::setID(const std::string& id) {
    ID = id;
}

std::string Person::getDOB() const {
    return DOB;
}

void Person::setDOB(const std::string& dob) {
    DOB = dob;
}

char Person::getGender() const {
    return gender;
}

void Person::setGender(char g) {
    gender = g;
}

double Person::getHeight() const {
    return height;
}

void Person::setHeight(double h) {
    height = h;
}

double Person::getWeight() const {
    return weight;
}

void Person::setWeight(double w) {
    weight = w;
}