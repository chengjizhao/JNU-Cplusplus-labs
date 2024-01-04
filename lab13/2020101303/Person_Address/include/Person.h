#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Person;

class Address
{
    public:
       Address(const string& city_, const string& street_) : city(city_), street(street_) {}
       string get_City() const;
       string get_Street() const;
       weak_ptr<Person> person;
       ~Address() {cout << "Destroy -- Address:" << city << "  " << street << endl;}
    private:
       string city;
       string street;
};

class Person : public enable_shared_from_this<Person>
{
    public:
       Person(const string& name_, int age_) : name(name_), age(age_) {}
       void set_Address(shared_ptr<Address> address);
       string get_Name() const;
       int get_Age() const;
       ~Person() {cout << "Destroy -- Person:" << name << "  " << age << endl;}
    private:
       string name;
       int age;
       shared_ptr<Address> address;
};

#endif