#pragma once
#ifndef Person_H
#define Person_H

#include <string>
#include <iostream>
 
class Person 
{
public:
    std::string p_name;
    
    Person()=default;
    //生成默认构造函数
    Person(const std::string& name);
    //生成单一参数构造函数
    Person(const std::string& name,const std::string& id,const std::string& birthdate,const std::string& gender,double height,double weight);
    //生成多参数构造函数
    void set_information(const std::string& id,const std::string& birthdate,const std::string& gender,double height,double weight);
    //设置其他参数
    void show() const;
    //打印所有属性
    
    
private:
    std::string p_id;
    std::string p_birthdate;
    std::string p_gender;
    double p_height ;
    double p_weight ;
};

#endif 