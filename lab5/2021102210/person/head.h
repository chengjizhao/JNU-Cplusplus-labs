#ifndef CA_H
#define CA_H
#include<string>
#include<iostream>
using namespace std ;

class Person
{
    public:
    string name ;
    Person(string a , int b , string c , int d ,int e);
    void show();
    private:
    int ID ;
    string birthday;
    int tall ;
    int heavy ;
};

#endif