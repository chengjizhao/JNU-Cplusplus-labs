#pragma once
#include <vector>
#include <cstdint>
#include <fstream>
#include <string>



class Student;
using std::string;



class ManagerSystem
{
public:
	ManagerSystem();
	~ManagerSystem();

	size_t getStudentCount();
	bool isModified();
	bool isReady();
	int queryScore(string number, size_t times);
	bool addScoreToStudent(string number,size_t index, int score);
	bool save();

private:
	bool initialize_json(std::ifstream &jsonFile);
	
	std::vector<Student> students;
	bool ready;
	bool modified;
};

