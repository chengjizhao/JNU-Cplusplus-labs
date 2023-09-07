#pragma once
#include <cstdint>
#include <string>
#include <vector>

using std::string;

class Student
{
public:
	Student(string name, string number, string major);
	~Student();

	string getName();
	string getNumber();
	string getMajor();
	size_t getExperimentTimes();
	uint8_t getScoreByIndex(size_t index);

	bool addScore(size_t index, int score);
	bool addScore(int score);
private:
	string name;
	string number;
	string major;
	std::vector<int> scores;
};

