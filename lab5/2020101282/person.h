#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ctime>

class Person {
public:
    // 公有成员变量
    std::string name;

    // 构造函数
    Person();
    Person(const std::string& name);
    Person(const std::string& name, const std::string& id, const std::tm& dateOfBirth, char gender, double height, double weight);

    // 查询和设置函数
    void SetID(const std::string& id);
    void SetDateOfBirth(const std::tm& dateOfBirth);
    void SetGender(char gender);
    void SetHeight(double height);
    void SetWeight(double weight);

    std::string GetID() const;
    std::tm GetDateOfBirth() const;
    char GetGender() const;
    double GetHeight() const;
    double GetWeight() const;

private:
    // 私有成员变量
    std::string id;       // 身份证号
    std::tm dateOfBirth;  // 出生年月日
    char gender;          // 性别
    double height;        // 身高
    double weight;        // 体重
};

#endif // PERSON_H
