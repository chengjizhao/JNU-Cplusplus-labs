#ifndef PERSON_H_
#define PERSON_H_
#include<iostream>
#include<string>
using namespace std;
class person
{
public:
    person();
    person(string Name,int ID,string Birthday,string gender,int height,int weight);
    person(const person &);
    ~person();
    string Name;
    void getName(string N);
    void getID(int I);
    void getBirthday(string B);
    void getGender(string G);
    void getHeight(int H);
    void getWeight(int W);
    void show();

private:
    int ID;
    string Birthday;
    int Height;
    string Gender;
    int Weight;


};
#endif