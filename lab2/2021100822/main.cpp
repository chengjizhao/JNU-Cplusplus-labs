#include "StudentManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <codecvt>
#include <locale>
#include <vector>

void SetConsoleUTF8() {
    SetConsoleOutputCP(CP_UTF8);
}

StudentManager::StudentManager() {
    // 构造函数，可以初始化一些变量
}

std::string GbkToUtf8(const std::string& src_str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    std::wstring wstr = conv.from_bytes(src_str);
    return std::string(wstr.begin(), wstr.end());
}//GBK转UFT_8

std::string Utf8ToGbk(const std::string& src_str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    std::wstring wstr(src_str.begin(), src_str.end());
    return conv.to_bytes(wstr);
}//UFT_8转GBK

void StudentManager::LoadDataFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cout << "无法打开文件！" << std::endl;
        return;
    }

    students.clear();
    std::string line;
    while (std::getline(inputFile, line)) {
        Student student;
        std::stringstream ss(line);
        ss >> student.studentID >> student.name >> student.major >> student.score;
        students.push_back(student);
    }

    inputFile.close();
}//读文件

void StudentManager::SaveDataToFile(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cout << "无法创建文件！" << std::endl;
        return;
    }

    for (const Student& student : students) {
        outputFile << student.studentID << " " << student.name << " " << student.major << " " << student.score << std::endl;
    }

    outputFile.close();
}//输出文件

void StudentManager::AddScore(int studentID, double newScore) {
    for (Student& student : students) {
        if (student.studentID == studentID) {
            student.score += newScore;
            break;
        }
    }
}//分数累加

double StudentManager::CalculateTotalScore(int studentID) {
    for (const Student& student : students) {
        if (student.studentID == studentID) {
            return student.score;
        }
    }
    return -1; // 学号不存在
}//统计当前分数

void StudentManager::Run() {
    while (true) {
        std::cout << "请选择操作：" << std::endl;
        std::cout << "1. 查询成绩" << std::endl;
        std::cout << "2. 录入实验课成绩" << std::endl;
        std::cout << "3. 保存数据" << std::endl;
        std::cout << "4. 退出程序" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "请输入学号进行查询：" << std::endl;
            int studentID;
            std::string value;
            std::cin >> studentID;
            double totalScore = CalculateTotalScore(studentID);
            for (const Student& student : students) {
                if (student.studentID == studentID) {
                value= student.name;
              }
            }
            if (totalScore != -1) {
                std::cout << "学号 " << studentID <<value << " 的总成绩为：" << totalScore << std::endl;
                value.clear();
            } else {
                std::cout << "学号不存在！" << std::endl;
            }
        } else if (choice == 2) {
            std::cout << "请输入学号和新的实验课成绩：" << std::endl;
            int studentID;
            double newScore;
            std::cin >> studentID >> newScore;
            AddScore(studentID, newScore);
        } else if (choice == 3) {
            std::cout << "请输入保存文件名：" << std::endl;
            std::string filename;
            std::cin >> filename;
            SaveDataToFile(filename);
            std::cout << "数据已保存到文件 " << filename << std::endl;
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "无效的选择！" << std::endl;
        }
    }
}//程序选择界面


int main() {
    // 设置控制台输出编码为UTF-8
    SetConsoleUTF8();

    StudentManager manager;
    manager.LoadDataFromFile("test.csv");
    manager.Run();
    return 0;
}主函数运行
