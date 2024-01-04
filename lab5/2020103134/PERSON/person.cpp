#include<iostream>
#include"person.h"
using namespace std;
//构造函数
person::person()
{
    name_="";
    id_="";
    birthday_="";
    gender_="";
    height_=0.0;
    weight_=0.0;
}
person::person(const string & name, const string & id, const string & bd, const string & g, double h, double w)
{
    name_=name;
    id_=id;
    birthday_=bd;
    gender_=g;
    height_=h;
    weight_=w;
}
//查询函数
string person::get_name() const
{
    return name_;
}

string person::get_id() const
{
    return id_;
}

string person::get_birthday() const
{
    return birthday_;
}

string person::get_gender() const
{
    return gender_;
}

double person::get_height() const
{
    return height_;
}

double person::get_weight() const
{
    return weight_;
}
// 设置函数
void person::set_name(const string &name)
{
    name_=name;
}

void person::set_id(const string &id)
{
    id_=id;
}

void person::set_birthday(const string &bd)
{
    birthday_=bd;
}

void person::set_gender(const string &g)
{
    gender_=g;
}

void person::set_height(double h)
{
    height_=h;
}

void person::set_weight(double w)
{
    weight_=w;
}
