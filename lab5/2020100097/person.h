#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
    public:
        string name;

        Person();
        Person(string& n);
        
        void setID(string& id);
        void setBirthday(string& bd);
        void setGender(string& gender);
        void setHeight(double h);
        void setWeight(double w);
        string getID();
        string getBirthday();
        string getGender();
        double getHeight();
        double getWeight();
    private:
        string pid;
        string pbd;
        string pg;
        double ph;
        double pw;
};

#endif