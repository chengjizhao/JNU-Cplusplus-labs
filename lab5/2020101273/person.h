#ifndef PERSON_H  
#define PERSON_H

#include <iostream>
using std::string,std::cout;

class Person 
{  
public:  
    string name; // 名字是 public 的
    // 公共的 getter 和 setter 方法  
    string getName() const { return name; }  
    void setName(const string& name) { this->name = name; }

    string getID() const { return id; }  
    void setID(const string& id) { this->id = id; }

    string getBirthdate() const { return birthdate; }  
    void setBirthdate(const string& birthdate) { this->birthdate = birthdate; }

    string getGender() const { return gender; }  
    void setGender(const string& gender) { this->gender = gender; }

    double getHeight() const { return height; }  
    void setHeight(double height) { this->height = height; }

    double getWeight() const { return weight; }  
    void setWeight(double weight) { this->weight = weight; }


    Person();
    Person(const string& name);
    Person(const string& name, const string& birthdate);
    Person(const string& name, const string& birthdate, const string& gender);
    Person(const string& name, const string& birthdate, const string& gender, double height);
    Person(const string& name, const string& id, const string& birthdate, const string& gender, double height, double weight);
    ~Person();

private:  
    string id;  
    string birthdate;  
    string gender;  
    double height;  
    double weight;  
};

#endif  