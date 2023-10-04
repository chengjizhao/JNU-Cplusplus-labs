//person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    std::string name;

    Person() = default;
    Person(const std::string& name);
    Person(const std::string& name, const std::string& id, const std::string& birthdate, const std::string& gender, double height, double weight);

    void set_id(const std::string& id);
    void set_birthdate(const std::string& birthdate);
    void set_gender(const std::string& gender);
    void set_height(double height);
    void set_weight(double weight);

    std::string get_id() const;
    std::string get_birthdate() const;
    std::string get_gender() const;
    double get_height() const;
    double get_weight() const;

private:
    std::string id_;
    std::string birthdate_;
    std::string gender_;
    double height_ = 0.0;
    double weight_ = 0.0;
};

#endif // PERSON_H