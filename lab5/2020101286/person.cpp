#include "person.h"

// 默认构造函数
Person::Person() {}

// 带参数的构造函数
Person::Person(const std::string& name, const std::string& id, const std::string& dob,
               const std::string& gender, double height, double weight)
    : name(name), id(id), dob(dob), gender(gender), height(height), weight(weight) {}

// 查询和设置函数的实现
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

// 输出所有属性信息
void Person::printInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Date of Birth: " << dob << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Height: " << height << " cm" << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;
}
