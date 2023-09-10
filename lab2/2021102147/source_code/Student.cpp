#include <cstdint>
#include <string>
#include <vector>

#include "Student.h"

using std::string;

Student::Student(string name, string number, string major)
{
	this->name = name;
	this->number = number;
	this->major = major;
}

Student::~Student()
{

}

string Student::getName()
{
	return name;
}

string Student::getNumber()
{
	return number;
}

string Student::getMajor()
{
	return major;
}

size_t Student::getExperimentTimes()
{
	return scores.size();
}

uint8_t Student::getScoreByIndex(size_t index)
{
	return scores[index];
}

bool Student::addScore(int score)
{
	scores.push_back(score);
	return true;
}
bool Student::addScore(size_t index, int score)
{
	if (index >= scores.size())
	{
		scores.resize(index + 1, 0);
	}
	scores[index] = score;
	return true;
}