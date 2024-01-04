#pragma once

#include <string>

class Person
{
public:
	Person();
	Person(std::string name,int birth_year,int birth_month,int birth_day, int height, int weight, std::string id_number);
	Person(const char* name, int birth_year, int birth_month, int birth_day, int height, int weight, const char* id_number);
	~Person();

	void setName(const char* name);
	void setIDNumber(const char* id_number);
	void setBirth(int year, int month, int day);
	void setHeight(int height);
	void setWeight(int weight);

	std::string getName();
	bool getGender();
	int getBirthYear();
	int getBirthMonth();
	int getBirthDay();
	int getHeight();
	int getWeight();
	std::string getIDNumber();


	std::string name;
private:
	bool gender;
	int birth_year;
	int birth_month;
	int birth_day;
	int height;
	int weight;
	std::string id_number;

};

