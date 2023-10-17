#ifndef PERSON_H
#define PERSON_H

#include <string>

class person
{
public:
    std::string name;

    person();              // 默认构造函数
    person(std::string n); // 带名字参数的构造函数
    person(std::string n, std::string id, std::string dob, std::string gender,
           double height, double weight); // 带所有属性参数的构造函数

    // 查询和设置函数
    std::string getId() const;
    void setId(std::string id);

    std::string getDob() const;
    void setDob(std::string dob);

    std::string getGender() const;
    void setGender(std::string gender);

    double getHeight() const;
    void setHeight(double height);

    double getWeight() const;
    void setWeight(double weight);

private:
    std::string id;
    std::string dob;
    std::string gender;
    double height;
    double weight;
};

#endif