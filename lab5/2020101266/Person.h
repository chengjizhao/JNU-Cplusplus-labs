#pragma once
#ifndef PERSON_H  
#define PERSON_H  

#include <string>  
#include <iostream>  

class Person {
public:
    std::string name; // ����������  

    // ���캯��  
    Person();
    Person(const std::string& name, const std::string& id, const std::string& birthdate,
        const std::string& gender, double height, double weight);

    // ��ѯ����  
    std::string getID() const;
    std::string getBirthdate() const;
    std::string getGender() const;
    double getHeight() const;
    double getWeight() const;

    // ���ú���  
    void setID(const std::string& id);
    void setBirthdate(const std::string& birthdate);
    void setGender(const std::string& gender);
    void setHeight(double height);
    void setWeight(double weight);

private:
    std::string id; // ���֤��  
    std::string birthdate; // ����������  
    std::string gender; // �Ա�  
    double height; // ���  
    double weight; // ����  
};

#endif // PERSON_H