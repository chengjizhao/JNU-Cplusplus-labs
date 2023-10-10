#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;

private:
    std::string id;
    std::string birthday;
    std::string gender;
    int height;
    int weight;

public:
    Person();
    Person(std::string n);
    Person(std::string n, std::string i, std::string b, std::string g, int h, int w);

    void setId(std::string i);
    std::string getId() const;

    void setBirthday(std::string b);
    std::string getBirthday() const;

    void setGender(std::string g);
    std::string getGender() const;

    void setHeight(int h);
    int getHeight() const;

    void setWeight(int w);
    int getWeight() const;
};

#endif
