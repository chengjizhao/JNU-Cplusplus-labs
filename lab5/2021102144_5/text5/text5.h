#pragma once
#include<string>
using namespace std;
class Person
{
private://类中使用，不可调用
    int Id;
    int Born;
    bool Sex;
    int High;
    int Weight; 
public://可以被调用
    string Name;
    void setId();
    void getId();
    void setBorn();
    void getBorn();
    void setSex();
    void getSex();
    void setHigh();
    void getHigh();
    void setWeight();
    void getWeight();
    Person();
    Person(int a);
    Person(int a,int b);
    ~Person();
};