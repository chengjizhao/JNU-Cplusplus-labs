#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
public:
 Person();
 Person(const std::string& name);
 Person(const std::string& name, const std::string& id, const std::string& dob, char gender, double height, double weight);

 std::string getName() const;
 std::string getID() const;
 std::string getDOB() const;
 char getGender() const;
 double getHeight() const;
 double getWeight() const;

 void setName(const std::string& name);
 void setID(const std::string& id);
 void setDOB(const std::string& dob);
 void setGender(char gender);
 void setHeight(double height);
 void setWeight(double weight);

private:
 std::string name;
 std::string id;
 std::string dob;
 char gender;
 double height;
 double weight;
};

#endif 

