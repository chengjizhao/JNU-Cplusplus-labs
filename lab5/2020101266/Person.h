#pragma once
#ifndef PERSON_H  
#define PERSON_H  

#include <string>  
#include <iostream>  

class Person {
public:
    std::string name; // 公开的属性  

    // 构造函数  
    Person();
    Person(const std::string& name, const std::string& id, const std::string& birthdate,
        const std::string& gender, double height, double weight);

    // 查询函数  
    std::string getID() const;
    std::string getBirthdate() const;
    std::string getGender() const;
    double getHeight() const;
    double getWeight() const;

    // 设置函数  
    void setID(const std::string& id);
    void setBirthdate(const std::string& birthdate);
    void setGender(const std::string& gender);
    void setHeight(double height);
    void setWeight(double weight);

private:
    std::string id; // 身份证号  
    std::string birthdate; // 出生年月日  
    std::string gender; // 性别  
    double height; // 身高  
    double weight; // 体重  
};

#endif // PERSON_H