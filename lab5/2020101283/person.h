#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    // 默认构造函数
    Person();
    // 带参数的构造函数
    Person(std::string name, std::string id, std::string birthday, std::string gender, double height, double weight);
    // 拷贝构造函数
    Person(const Person& other);
    // 析构函数
    ~Person();

    // 查询和设置名字
    std::string getName() const;
    void setName(std::string name);

    // 查询和设置身份证号
    std::string getId() const;
    void setId(std::string id);

    // 查询和设置出生年月日
    std::string getBirthday() const;
    void setBirthday(std::string birthday);

    // 查询和设置性别
    std::string getGender() const;
    void setGender(std::string gender);

    // 查询和设置身高
    double getHeight() const;
    void setHeight(double height);

    // 查询和设置体重
    double getWeight() const;
    void setWeight(double weight);

private:
    std::string name_; // 名字
    std::string id_; // 身份证号
    std::string birthday_; // 出生年月日
    std::string gender_; // 性别
    double height_; // 身高
    double weight_; // 体重
};

#endif // PERSON_H
