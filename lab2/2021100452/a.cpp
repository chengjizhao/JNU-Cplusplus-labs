#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <vector>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

// 定义结构体，存储学生信息
struct Student {
    string student_id;  // 学号
    string name;        // 姓名
    string major;       // 专业
    int daily_scores[16];   // 平时成绩，一共16项
    int total_score;    // 总成绩
};

// 定义学生信息的容器
vector<Student> students;

// 声明函数
void read_csv(string file);    // 读取CSV文件
void write_csv(string file_path);   // 将学生信息写入CSV文件
void add_score();   // 按学号录入成绩
void query_score(); // 按学号查询成绩

int main() {
    read_csv("students.csv");

    while (true) {
        // 输出菜单
        cout << "请选择操作：" << endl;
        cout << "1. 按学号录入成绩" << endl;
        cout << "2. 按学号查询成绩" << endl;
        cout << "3. 退出程序" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            add_score();
            break;
        case 2:
            query_score();
            break;
        case 3:
            write_csv("students_score.csv");
            exit(0);
        default:
            cout << "无效的操作，请重新选择" << endl;
            break;
        }
    }
}

// 从CSV文件读取学生信息，存入容器
void read_csv(string file_path) {
    ifstream in(file_path);     // 打开文件

    // 如果无法打开文件，输出错误信息并退出程序
    if(!in) {
        cout << "打开文件失败" << endl;
        exit(1);
    }

    string line;
    getline(in, line);  // 第一行是标题，读取并忽略

    // 逐行读取学生信息
    while (getline(in, line)) {
        Student student;
        stringstream ss(line);
        string cell;

        // 逐个读取单元格，即学生信息的各个属性
        getline(ss, cell, ',');
        student.student_id = cell;

        getline(ss, cell, ',');
        student.name = cell;

        getline(ss, cell, ',');
        student.major = cell;

        // 读取平时成绩
        for (int i = 0; i < 16; i++) {
            getline(ss, cell, ',');
            student.daily_scores[i] = stoi(cell);
        }

        students.push_back(student);    // 将学生信息存入容器中
    }

    in.close(); // 关闭文件
}

// 将学生信息写入CSV文件
void write_csv(string file_path) {
    ofstream out(file_path);    // 打开文件

    // 输出标题
    cout << "学号,姓名,专业,平时成绩1,平时成绩2,平时成绩3,平时成绩4,平时成绩5,平时成绩6,平时成绩7,平时成绩8,平时成绩9,平时成绩10,平时成绩11,平时成绩12,平时成绩13,平成绩14,平时成绩15,平时成绩16,总成绩" << endl;

    // 遍历容器，逐个输出学生信息
    for (const auto& student : students) {
        cout << student.student_id << "," << student.name << "," << student.major << ",";

        for (int i = 0; i < 16; i++) {
            cout << student.daily_scores << ",";
        }

        cout << student.total_score << endl;
    }

    out.close();    // 关闭文件
}

// 按学号录入成绩
void add_score() {
    string student_id;
    cout << "请输入学号：" << endl;
    cout << student_id;

    for (auto& student : students) {
        if (student.student_id == student_id) {
            // 学生存在，录入平时成绩并计算总分
            cout << "请输入平时成绩（用空格隔开）：" << endl;

            int total = 0;
            for (int i = 0; i < 16; i++) {
                cin >> student.daily_scores[i];
                total += student.daily_scores[i];
            }

            student.total_score = total;
            cout << "录入成功" << endl;

            return;
        }
    }

    // 学生不存在
    cout << "该学号不存在，请确认后重新输入" << endl;
}

// 按学号查询成绩
void query_score() {
    string student_id;
    cout << "请输入学号：" << endl;
    cin >> student_id;

    for (const auto& student : students) {
        if (student.student_id == student_id) {
            // 学生存在，输出学生信息和绩
            cout << "学号：" << student.student_id << endl;
            cout << "姓名：" << student.name << endl;
            cout << "专业：" << student.major << endl;
            cout << "平时成绩：" << endl;

            for (int i = 0; i < 16; i++) {
                cout << "平时成绩" << i + 1 << "：" << student.daily_scores[i] << endl;
            }

            cout << "总成绩：" << student.total_score << endl;

            return;
        }
    }

    // 学生不存在
    cout << "该学号不存在，请确认后重新输入" << endl;
}