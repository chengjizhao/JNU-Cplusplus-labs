#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    // 默认构造函数
    Person();

    // 带参数的构造函数
    Person(const std::string& name, const std::string& id, const std::string& dob,
           const std::string& gender, double height, double weight);

    // 查询和设置函数
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

    // 输出所有属性信息
    void printInfo() const;

private:
    std::string name;
    std::string id;
    std::string dob;
    std::string gender;
    double height;
    double weight;
};

#endif