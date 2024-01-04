#include "person.h"

Person::Person() {
    // Ĭ�Ϲ��캯��
}

Person::Person(const std::string& n) : name(n) {
    // ʹ�����ֳ�ʼ������
}

Person::Person(const std::string& n, const std::string& id, const std::string& dob, char g, double h, double w)
    : name(n), ID(id), DOB(dob), gender(g), height(h), weight(w) {
    // ʹ�ø��������ݳ�ʼ������
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