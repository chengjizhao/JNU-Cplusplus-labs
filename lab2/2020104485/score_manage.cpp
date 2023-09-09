//
//  score_manage.cpp
//  csv
//
//  Created by mac on 2023/9/7.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

struct Student {
 std::string studentId;
 std::string name;
 std::string major;
 int score;
};

std::vector<Student> students;

void readCSV(const std::string& filename) {
 std::ifstream file(filename);
 if (!file.is_open()) {
 std::cout << "无法打开文件" << std::endl;
 return;
 }

 std::string line;
 while (std::getline(file, line)) {
 std::stringstream ss(line);
 std::string cell;
 std::vector<std::string> cells;

 while (std::getline(ss, cell, ',')) {
 cells.push_back(cell);
 }

 if (cells.size() >=3) {
     if(cells.size() >=4){
         Student student;
         student.studentId = cells[0];
         student.name = cells[1];
         student.major = cells[2];
         student.score = std::stoi(cells[3]);
         students.push_back(student);
     }
     else{Student student;
         student.studentId = cells[0];
         student.name = cells[1];
         student.major = cells[2];
         student.score = NULL;
         students.push_back(student);}
 }
 }

 file.close();
}

void writeCSV(const std::string& filename) {
 std::ofstream file(filename);
 if (!file.is_open()) {
 std::cout << "无法打开文件" << std::endl;
 return;
 }

 for (const auto& student : students) {
 file << student.studentId << "," << student.name << "," << student.major << "," << student.score << std::endl;
 }

 file.close();
}

void queryScore(const std::string& studentId) {
 for (const auto& student : students) {
 if (student.studentId == studentId) {
     if(student.score == 0){std::cout << "学号为 " << studentId << " 的学生成绩没有录入" << std::endl;
         return;
     }
     else{std::cout << "学生 " << student.name << " 的成绩为 " << student.score << std::endl;}
 return;
 }
     
 }
 std::cout << "学号为 " << studentId << " 的学生成绩没有录入,请录入成绩" << std::endl;
}

void addScore(const std::string& studentId, int score) {
 for (auto& student : students) {
 if (student.studentId == studentId) {
 student.score = score;
 return;
 }
 }
 std::cout << "找不到学号为 " << studentId << " 的学生" << std::endl;
}

int main() {
    std::string studentId;
    std::string name;
    std::string major;
    std::string choose;
    int score;
    std::string filename = "/Users/mac/Documents/code/csv/csv/students.csv";
    readCSV(filename);
    
    std::cout << "查询成绩按1，录入成绩按2"<<std::endl;
    std::cin >> choose;
    if(choose == "1"){
        
        // 按学号查询成绩 std::string studentId;
        std::cout << "查询成绩请输入学号：";
        std::cin >> studentId;
        queryScore(studentId);}
    
    if(choose == "2"){
        
        // 按学号录入成绩 int score;
        std::cout << "录入成绩请输入学号：";
        std::cin >> studentId;
        std::cout << "请输入成绩：";
        std::cin >> score;
        addScore(studentId, score);
        
        writeCSV(filename);}
        
    return 0;
}

