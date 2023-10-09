#ifndef USE_CLASS_H
#define USE_CLASS_H
#include <iostream>
#include <string>
using namespace std;
// 创建类
class Person
{
    // 两个构造函数
public:
    Person(string name, string gender, string id, int year, int mouth, int day, double height, double weight);
    Person();
    // 属性
public:
    string name_;

private:
    string gender_;
    string id_;
    int year_, mouth_, day_;
    double height_, weight_;

    // 行为
public:
    void set();
    void search();
    void set2(Person &p);
    void size(Person &p);
};

#endif