#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
private:
    std::string name_;
    std::string id_;
    std::string birthday_;
    std::string gender_;
    double height_;
    double weight_;

public:
    Person();

    Person(std::string name, std::string id, std::string birthday, std::string gender, double height, double weight);

    Person(const Person& other);

    ~Person();

    //����
    std::string getName() const;
    void setName(std::string name);

    //���֤
    std::string getId() const;
    void setId(std::string id);

    //����
    std::string getBirthday() const;
    void setBirthday(std::string birthday);

    //�Ա�
    std::string getGender() const;
    void setGender(std::string gender);

    //���
    double getHeight() const;
    void setHeight(double height);

    //����
    double getWeight() const;
    void setWeight(double weight);
};

#endif 
