#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;

    // 构造函数
    Person();
    Person(const std::string& name);
    Person(const std::string& name, const std::string& id, const std::string& dob,
        const std::string& gender, double height, double weight);

    // 查询函数
    std::string getName() const;
    std::string getId() const;
    std::string getDateOfBirth() const;
    std::string getGender() const;
    double getHeight() const;
    double getWeight() const;

    // 设置函数
    void setId(const std::string& id);
    void setDateOfBirth(const std::string& dob);
    void setGender(const std::string& gender);
    void setHeight(double height);
    void setWeight(double weight);

private:
    std::string id;
    std::string dateOfBirth;
    std::string gender;
    double height;
    double weight;
};

#endif  // PERSON_H