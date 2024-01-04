#include "person.h"

person::person() {}

person::person(const std::string& n) : name(n) {}

person::person(const std::string& n, const std::string& id, const std::string& dob, const std::string& gender, double height, double weight)
 : name(n) // 设置其他属性

std::string person::getID() const ; // 返回身份证号

void person::setID(const std::string& id) ；// 设置身份证号

std::string person::getDOB() const // 返回出生年月日

void person::setDOB(const std::string& dob) // 设置出生年月日

std::string person::getGender() const // 返回性别

void person::setGender(const std::string& gender) // 设置性别

double person::getHeight() const {}// 返回身高

void person::setHeight(double height) {}// 设置身高

double person::getWeight() const {}// 返回体重

void person::setWeight(double weight) {}// 设置体重