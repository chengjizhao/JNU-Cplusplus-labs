#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;

    // ���캯��
    Person();
    Person(const std::string& name);
    Person(const std::string& name, const std::string& id, const std::string& dob,
        const std::string& gender, double height, double weight);

    // ��ѯ����
    std::string getName() const;
    std::string getId() const;
    std::string getDateOfBirth() const;
    std::string getGender() const;
    double getHeight() const;
    double getWeight() const;

    // ���ú���
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