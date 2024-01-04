#ifndef PERSON_H
#define PERSON_H
#include <string>

class person 
{
    public:
    std::string name;
    person();
    person(const std::string& n);
    person(const std::string& n, const std::string& id, const std::string& dob, const std::string& gender, double height, double weight);
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
};
#endif