
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;

    // 构造函数
    Person();
    Person(const std::string& n);
    Person(const std::string& n, const std::string& id, const std::string& dob, char gender, double height, double weight);

    // 查询和设置函数
    std::string getName() const;
    void setName(const std::string& n);
    std::string getID() const;
    void setID(const std::string& id);
    std::string getDOB() const;
    void setDOB(const std::string& dob);
    char getGender() const;
    void setGender(char gender);
    double getHeight() const;
    void setHeight(double height);
    double getWeight() const;
    void setWeight(double weight);

private:
    std::string ID;
    std::string DOB;
    char gender;
    double height;
    double weight;
};

#endif  // PERSON_H
