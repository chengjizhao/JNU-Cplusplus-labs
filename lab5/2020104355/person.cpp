#include "person.h"
Person::Person()
 {
  name = "";
  id = "";
  dob = "";
  gender = '\0';
  height =0.0;
  weight =0.0;
}
Person::Person(const std::string& name)
 {
  this->name = name;
  id = "";
  dob = "";
  gender = '\0';
  height =0.0;
  weight =0.0;
}
Person::Person(const std::string& name, const std::string& id, const std::string& dob, char gender, double height, double weight) 
{
  this->name = name;
  this->id = id;
  this->dob = dob;
  this->gender = gender;
  this->height = height;
  this->weight = weight;
}
std::string Person::getName() const
 {
  return name;
}
std::string Person::getID() const
 {
  return id;
}

std::string Person::getDOB() const
 {
  return dob;
}
char Person::getGender() const
 {
  return gender;
}

double Person::getHeight() const 
{
  return height;
}
double Person::getWeight() const {

   return weight;
}
void Person::setName(const std::string& name) 
{
  this->name = name;
}
void Person::setID(const std::string& id) 
{
  this->id = id;
}
void Person::setDOB(const std::string& dob)
{
  this->dob = dob;
}
void Person::setGender(char gender)
{
  this->gender = gender;
}
void Person::setHeight(double height) 
{
  this->height = height;
}
void Person::setWeight(double weight)
 {
  this->weight = weight;
}