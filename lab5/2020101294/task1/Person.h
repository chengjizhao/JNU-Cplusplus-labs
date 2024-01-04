#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(const std::string& name);
    Person(const std::string& name, const std::string& id, const std::string& birthDate, char gender, double height, double weight);

    const std::string& GetName() const;
    const std::string& GetID() const;
    const std::string& GetBirthDate() const;
    char GetGender() const;
    double GetHeight() const;
    double GetWeight() const;

    void SetID(const std::string& id);
    void SetBirthDate(const std::string& birthDate);
    void SetGender(char gender);
    void SetHeight(double height);
    void SetWeight(double weight);

private:
    std::string name;
    std::string id;
    std::string birthDate;
    char gender;
    double height;
    double weight;
};

#endif