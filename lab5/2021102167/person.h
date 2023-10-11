#ifndef PERSON_H
#define PERSON_H
using namespace std;
#include<string>
#include<iostream>

class Person 
{
public:
	string name_;
	Person();
	Person(string& name);
	Person(string& name,string& id,string& birthyear, string& birthdaymonth,string& birthday,double height, double weight);
	void setName(string& name);
	void setId(string& id);
	void setBirthyear(string& birthyear);
	void setBirthmonth(string& birthmonth);
	void setBirthday(string& birthday);
	void setHeight(double height);
	void setWeight(double weight);

	string getName();
	string getId();
	string getBirthyear();
	string getBirthmonth();
	string getBirthday();
	double getHeight();
	double getWeight();
private:
	string id_;
	string birthyear_;
	string birthmonth_;
	string birthday_;
	double height_;
	double weight_;
};
#endif
