#include"Person.h"
#include<iostream>
Person::Person(const std::string& name):
p_name(name){}
Person::Person(const std::string& name,const std::string& id,const std::string& birthdate,const std::string& gender,double height,double weight):
p_name(name),p_id(id),p_birthdate(birthdate),p_gender(gender),p_height(height),p_weight(weight){}


void Person::set_information(const std::string& id,const std::string& birthdate,const std::string& gender,double height,double weight) 
{
    p_id = id;
    p_birthdate = birthdate;
    p_gender = gender;    
    p_height = height; 
    p_weight = weight;
}


void Person::show() const
{
    
    std::cout<< "name:" << p_name <<  std::endl;
    std::cout<< "id:" << p_id <<  std::endl;
    std::cout<< "birthdate:" << p_birthdate <<  std::endl;
    std::cout<< "gender:" << p_gender <<  std::endl;
    std::cout<< "height:" << p_height <<  std::endl;
    std::cout<< "weight:" << p_weight <<  std::endl;
    std::cout<< std::endl;
}
