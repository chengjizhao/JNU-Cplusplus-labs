#include "PERSON.h"

Person::Person() {}
Person::Person(string m_name)
{
    name = m_name;
    person_ID = "000000000000000000";
    birthday = "2000-01-01";
    gender = "Male";
    height = 160.0;
    weight = 50.0;
}
Person::Person(string m_name, string m_person_ID, const string m_birthday, const string m_gender, double m_height, double m_weight)
{
    set_name(m_name);
    set_person_ID(m_person_ID);
    set_birthday(m_birthday);
    set_gender(m_gender);
    set_height(m_height);
    set_weight(m_weight);
}

void Person::set_name(string m_name)
{
    this -> name = m_name;
}
string Person::get_name() const
{
    return name;
}
void Person::set_person_ID(string m_person_ID)
{
    this -> person_ID = m_person_ID;
}
string Person::get_person_ID() const
{
    return person_ID;
}
void Person::set_birthday(string m_birthday)
{
    this -> birthday = m_birthday;
}
string Person::get_birthday() const
{
    return birthday;
}
void Person::set_gender(string m_gender)
{
    gender = m_gender;
}
string Person::get_gender() const
{
    return gender;
}
void Person::set_height(double m_height)
{
    height = m_height;
}
double Person::get_height() const
{
    return height;
}
void Person::set_weight(double m_weight)
{
    weight = m_weight;
}
double Person::get_weight() const
{
    return weight;
}