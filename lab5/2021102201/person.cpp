#include "person.h"

//�������
Person::Person() : name_("") {}

Person::Person(std::string name, std::string id, std::string birthday, std::string gender, double height, double weight)
    : name_(name), id_(id), birthday_(birthday), gender_(gender), height_(height), weight_(weight) {}


Person::Person(const Person& other)
    : name_(other.name_), id_(other.id_), birthday_(other.birthday_), gender_(other.gender_), height_(other.height_), weight_(other.weight_) {}


Person::~Person() {}

//����
std::string Person::getName() const
{
    return name_;
}

void Person::setName(std::string name)
{
    name_ = name;
}

//���֤
std::string Person::getId() const
{
    return id_;
}

void Person::setId(std::string id)
{
    id_ = id;
}

//����
std::string Person::getBirthday() const
{
    return birthday_;
}

void Person::setBirthday(std::string birthday)
{
    birthday_ = birthday;
}

//�Ա�
std::string Person::getGender() const
{
    return gender_;
}

void Person::setGender(std::string gender)
{
    gender_ = gender;
}

//���
double Person::getHeight() const
{
    return height_;
}

void Person::setHeight(double height)
{
    height_ = height;
}

// ����
double Person::getWeight() const
{
    return weight_;
}

void Person::setWeight(double weight)
{
    weight_ = weight;
}