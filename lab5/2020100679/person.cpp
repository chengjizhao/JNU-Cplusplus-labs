
#include "person.h"

// 默认构造函数
Person::Person() {}

// 带名字的构造函数
Person::Person(const std::string& n) : name(n) {}

// 完整构造函数
Person::Person(const std::string& n, const std::string& id, const std::string& dob, char g, double h, double w)
    : name(n), ID(id), DOB(dob), gender(g), height(h), weight(w) {}

// 获取名字
std::string Person::getName() const {
    return name;
}

// 设置名字
void Person::setName(const std::string& n) {
    name = n;
}

// 获取身份证号
std::string Person::getID() const {
    return ID;
}

// 设置身份证号
void Person::setID(const std::string& id) {
    ID = id;
}

// 获取出生年月日
std::string Person::getDOB() const {
    return DOB;
}

// 设置出生年月日
void Person::setDOB(const std::string& dob) {
    DOB = dob;
}

// 获取性别
char Person::getGender() const {
    return gender;
}

// 设置性别
void Person::setGender(char g) {
    gender = g;
}

// 获取身高
double Person::getHeight() const {
    return height;
}

// 设置身高
void Person::setHeight(double h) {
    height = h;
}

// 获取体重
double Person::getWeight() const {
    return weight;
}

// 设置体重
void Person::setWeight(double w) {
    weight = w;
}
