//person.h
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person {
public:
    string name;

    Person() = default;
    Person(const string& name);
    Person(const string& name, const string& id, const string& birthdate, const string& gender, double height, double weight);

    void set_id(const string& id);
    void set_birthdate(const string& birthdate);
    void set_gender(const string& gender);
    void set_height(double height);
    void set_weight(double weight);

    string get_id() const;
    string get_birthdate() const;
    string get_gender() const;
    double get_height() const;
    double get_weight() const;

private:
    string id_;
    string birthdate_;
    string gender_;
    double height_ = 0.0;
    double weight_ = 0.0;
};

#endif // PERSON_H