#include "person.h"

using namespace std;

// 构造函数的实现
Person::Person() : name(""), id(""), birthday(""), gender('M'), height(0), weight(0) {}

Person::Person(const string &n) : name(n), id(""), birthday(""), gender('M'), height(0), weight(0) {}

Person::Person(const string &n, const string &i) : name(n), id(i), birthday(""), gender('M'), height(0), weight(0) {}

Person::Person(const string &n, const string &i, const string &b, char g, double h, double w) 
    : name(n), id(i), birthday(b), gender(g), height(h), weight(w) {}

// 设置函数的实现
void Person::setName(const string &n) { name = n; }
void Person::setID(const string &i) { id = i; }
void Person::setBirthday(const string &b) { birthday = b; }
void Person::setGender(char g) { gender = g; }
void Person::setHeight(double h) { height = h; }
void Person::setWeight(double w) { weight = w; }

// 查询函数的实现
string Person::getName() const { return name; }
string Person::getID() const { return id; }
string Person::getBirthday() const { return birthday; }
char Person::getGender() const { return gender; }
double Person::getHeight() const { return height; }
double Person::getWeight() const { return weight; }
