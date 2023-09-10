#include "ManagerSystem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include "Student.h"
#include "include/json.hpp"


using std::cout;
using std::string;
using nlohmann::json;


ManagerSystem::ManagerSystem()
{
	cout << "欢迎使用学生管理系统\n";
	cout << "####################\n";
	cout << "正在初始化...\n";
	std::ifstream dataFile("data/students.txt");
	if (!dataFile.is_open())
	{
		cout << "无法找到json数据文件，初始化出错\n";
		ready = false;
		return;
	}
	if (!initialize_json(dataFile))
	{
		ready = false;
		return;
	}
	cout << "初始化完毕\n\n";
	modified = false;
	ready = true;
}

ManagerSystem::~ManagerSystem()
{}

bool ManagerSystem::isModified()
{
	return modified;
}

bool ManagerSystem::isReady()
{
	return ready;
}

size_t ManagerSystem::getStudentCount()
{
	return students.size();
}

bool ManagerSystem::initialize_json(std::ifstream &jsonFile)
{
	// 存储信息
	Student* student = nullptr;
	json stuJson;
	string stu;
	while (std::getline(jsonFile,stu))
	{
		try {
			stuJson = json::parse(stu);
			student = new Student(stuJson["Name"], stuJson["Number"], stuJson["Major"]);
		}
		catch (...) {
			cout << "初始化失败！\n";
			cout << "请检查数据文件的格式是否正确\n";
			return false;
		}
		for (auto i : stuJson["Scores"])
		{
			student->addScore(i);
		}
		students.push_back(*student);
	}
	return true;
}

bool ManagerSystem::save()
{
	cout << "正在保存...\n";
	std::ofstream dataFile("data/students.txt");
	if (!dataFile.is_open())
	{
		cout << "无法打开数据文件，保存失败\n";
		return false;
	}
	json stuJson;
	for (Student stu : students)
	{
		stuJson["Name"] = stu.getName();
		stuJson["Number"] = stu.getNumber();
		stuJson["Major"] = stu.getMajor();
		stuJson["Scores"] = json::array();
		for (size_t i = 0; i < stu.getExperimentTimes(); i++)
		{
			stuJson["Scores"].push_back(stu.getScoreByIndex(i));
		}
		dataFile << stuJson.dump() << "\n";
	}
	dataFile.close();
	cout << "保存完毕\n";
	modified = false;
	return true;
}

int ManagerSystem::queryScore(string number, size_t index)
{
	for (auto i : students)
	{
		if (i.getNumber() == number)
		{
			// 如果实验次数不够，返回0
			if (i.getExperimentTimes() < index + 1)
			{
				return 0;
			}
			return i.getScoreByIndex(index);
		}
	}
	// 没找到指定的学生
	return -1;
}

bool ManagerSystem::addScoreToStudent(string number, size_t index, int score)
{
	for (auto &st : students)
	{
		if (st.getNumber() == number)
		{
			modified = true;
			st.addScore(index, score);
			return true;
		}
	}
	return false;
}