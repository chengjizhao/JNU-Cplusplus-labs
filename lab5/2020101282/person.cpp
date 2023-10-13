#include "person.h"

// 默认构造函数
Person::Person() {}

// 构造函数，只设置名字
Person::Person(const std::string& name) : name(name) {}

// 构造函数，设置所有属性
Person::Person(const std::string& name, const std::string& id, const std::tm& dateOfBirth, char gender, double height, double weight)
    : name(name), id(id), dateOfBirth(dateOfBirth), gender(gender), height(height), weight(weight) {}

// 设置身份证号
void Person::SetID(const std::string& id) {
    this->id = id;
}

// 设置出生年月日
void Person::SetDateOfBirth(const std::tm& dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

// 设置性别
void Person::SetGender(char gender) {
    this->gender = gender;
}

// 设置身高
void Person::SetHeight(double height) {
    this->height = height;
}

// 设置体重
void Person::SetWeight(double weight) {
    this->weight = weight;
}

// 获取身份证号
std::string Person::GetID() const {
    return id;
}

// 获取出生年月日
std::tm Person::GetDateOfBirth() const {
    return dateOfBirth;
}

// 获取性别
char Person::GetGender() const {
    return gender;
}

// 获取身高
double Person::GetHeight() const {
    return height;
}

// 获取体重
double Person::GetWeight() const {
    return weight;
}
