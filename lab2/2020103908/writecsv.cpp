#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

struct Student {
    std::string studentID;
    std::string name;
    std::string major;
    std::map<std::string, double> scores;
};

std::vector<Student> students;

// Function to parse a line of CSV data and create a student object
Student parseStudentData(const std::string& line) {
    std::vector<std::string> tokens;
    std::istringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    std::string studentID = tokens[0];
    std::string name = tokens[1];
    std::string major = tokens[4];

    return {studentID, name, major, {}};
}

// Function to load student data from the CSV file
void loadStudentData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Ignore the header line

    while (std::getline(file, line)) {
        students.push_back(parseStudentData(line));
    }

    file.close();
}

// Function to save student data to the CSV file
void saveStudentData(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file << "学号,姓名,专业,实验1，实验2，实验3，实验4，实验5，实验6，实验7，实验8，实验9，实验10，实验11，实验12，实验13，实验14，实验15，实验16\n";
    for (const auto& student : students) {
        file << student.studentID << "," << student.name << ",,," << student.major;
        for (const auto& score : student.scores) {
            file << "," << score.second;
        }
        file << ",,,,,\n";
    }

    file.close();
}

// Function to find a student by their student ID
Student* findStudentByID(const std::string& studentID) {
    for (auto& student : students) {
        if (student.studentID == studentID) {
            return &student;
        }
    }
    return nullptr;
}

// Function to calculate the total score for a student
double calculateTotalScore(const Student& student) {
    double totalScore = 0.0;
    for (const auto& score : student.scores) {
        totalScore += score.second;
    }
    return totalScore;
}

int main() {
    std::string filename = "data.csv";
    loadStudentData(filename);
while(true){


    std::string studentID;
    std::cout << "请您输入学生学号: ";
    std::cin >> studentID;

    Student* student = findStudentByID(studentID);
    if (student) {
        std::cout << "学号: " << student->studentID << std::endl;
        std::cout << "姓名: " << student->name << std::endl;
        std::cout << "专业: " << student->major << std::endl;

        // Query score or add score
        std::string option;
        std::cout << "输入'q'查询成绩，输入'a'录入新成绩: ";
        std::cin >> option;

        if (option == "q") {
            if (student->scores.empty()) {
                std::cout << "没有记录该学生的分数." << std::endl;
            } else {
                std::cout << "得分:" << std::endl;
                for (const auto& score : student->scores) {
                    std::cout << score.first << ": " << score.second << std::endl;
                }
                double totalScore = calculateTotalScore(*student);
                std::cout << "总分: " << totalScore << std::endl;
            }
        } else if (option == "a") {
            std::string experiment;
            double score;
            std::cout << "输入实验课名字： ";
            std::cin >> experiment;
            std::cout << "请输入实验课得分: ";
            std::cin >> score;

            student->scores[experiment] = score;
            saveStudentData(filename);
            std::cout << "得分已经保存到文件中." << std::endl;
            
        } else {
            std::cout << "Invalid option." << std::endl;
        }
    } else {
        std::cout << "未找到该学生." << std::endl;
    }
}
    return 0;
}
//该代码基本实现老师提出的要求，但是仍然有一些地方留有问题，如写入的csv文件中多了几处空白列。