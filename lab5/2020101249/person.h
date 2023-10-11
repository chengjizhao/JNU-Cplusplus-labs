#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
    Person();

    Person(const std::string& name, const std::string& id, const std::string& dob,
           const std::string& gender, double height, double weight);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getID() const;
    void setID(const std::string& id);

    std::string getDOB() const;
    void setDOB(const std::string& dob);

    std::string getGender() const;
    void setGender(const std::string& gender);

    double getHeight() const;
    void setHeight(double height);

    double getWeight() const;
    void setWeight(double weight);

    void inputFromTerminal();

private:
    std::string name;
    std::string id;
    std::string dob;
    std::string gender;
    double height;
    double weight;
};

#endif
