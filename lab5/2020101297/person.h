#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    Person();

    Person(std::string name, std::string id, std::string birthday, std::string gender, double height, double weight);

    Person(const Person& other);

    ~Person();

    //名字
    std::string getName() const;
    void setName(std::string name);

    //身份证号
    std::string getId() const;
    void setId(std::string id);

    //出生年月日
    std::string getBirthday() const;
    void setBirthday(std::string birthday);

    //性别
    std::string getGender() const;
    void setGender(std::string gender);

    //身高
    double getHeight() const;
    void setHeight(double height);

    //体重
    double getWeight() const;
    void setWeight(double weight);

private:
    std::string name_;
    std::string id_;
    std::string birthday_;
    std::string gender_; 
    double height_;
    double weight_;
};

#endif 
