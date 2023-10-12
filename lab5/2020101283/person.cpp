#include "person.h"

// 默认构造函数
Person::Person() : name_("") {}

// 带参数的构造函数
Person::Person(std::string name, std::string id, std::string birthday, std::string gender, double height, double weight)
    : name_(name), id_(id), birthday_(birthday), gender_(gender), height_(height), weight_(weight) {}

// 拷贝构造函数
Person::Person(const Person& other)
    : name_(other.name_), id_(other.id_), birthday_(other.birthday_), gender_(other.gender_), height_(other.height_), weight_(other.weight_) {}

// 析构函数
Person::~Person() {}

// 查询和设置名字
std::string Person::getName() const {
    return name_;
}

void Person::setName(std::string name) {
    name_ = name;
}

// 查询和设置身份证号
std::string Person::getId() const {
    return id_;
}

void Person::setId(std::string id) {
    id_ = id;
}

// 查询和设置出生年月日
std::string Person::getBirthday() const {
    return birthday_;
}

void Person::setBirthday(std::string birthday) {
    birthday_ = birthday;
}

// 查询和设置性别
std::string Person::getGender() const {
    return gender_;
}

void Person::setGender(std::string gender) {
    gender_ = gender;
}

// 查询和设置身高
double Person::getHeight() const {
    return height_;
}

void Person::setHeight(double height) {
    height_ = height;
}

// 查询和设置体重
double Person::getWeight() const {
    return weight_;
}

void Person::setWeight(double weight) {
    weight_ = weight;
}
