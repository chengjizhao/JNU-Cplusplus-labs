#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 定义学生结构体
struct Student
 {
    string studentId;
    string name;
    string major;
    vector<double> scores; // 存储成绩

    // 添加成绩的函数
    void addScore(double score) {
        scores.push_back(score);
    }
};

// 使用map存储学生信息，学号作为键
map<string, Student> students;

// 读取CSV文件并解析学生信息
void readCSVFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "无法打开文件 " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // 跳过表头行

    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> tokens;
        string token;

        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() == 10) { 
            Student student;
            student.studentId = tokens[0];
            student.name = tokens[1];
            student.major = tokens[4];
            students[student.studentId] = student;
        }
    }

    file.close();
}

// 保存学生信息到studentscores.csv文件
void saveScores(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "无法创建文件 " << filename << endl;
        return;
    }

    file << "学号,姓名,年级,所在学院,专业,班级,课程性质,课程类别,选课状态,重修重考,选课志愿,分数1,分数2,分数3,分数4,分数5,分数6,分数7,分数8,分数9,分数10" << endl;

    for (const auto& pair : students) {
        const Student& student = pair.second;
        file << student.studentId << "," << student.name << ",," << student.major << ",,,,,,,,,,,,,,,,,,,,,,,";

        // 将每个分数写入文件
        for (double score : student.scores) {
            file << score << ",";
        }

        file << endl;
    }

    file.close();
}

// 计算总成绩
double calculateTotalScore(const string& studentId) {
    if (students.find(studentId) != students.end()) {
        double totalScore = 0.0;
        const Student& student = students[studentId];
        for (double score : student.scores) {
            totalScore += score;
        }
        return totalScore;
    }
    return 0.0; // 如果学号不存在，返回0
}

int main() {
    const string originalFilename = "student.csv";
    const string scoresFilename = "studentscores.csv";
    readCSVFile(originalFilename);

    while (true) {
        cout << "\n学生成绩管理系统" << endl;
        cout << "1. 查询学生成绩" << endl;
        cout << "2. 录入学生成绩" << endl;
        cout << "3. 计算学生总成绩" << endl;
        cout << "4. 退出" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // 查询学生成绩逻辑
                string studentId;
                cout << "请输入学号: ";
                cin >> studentId;

                double totalScore = calculateTotalScore(studentId);
                if (totalScore > 0.0) {
                    const Student& student = students[studentId];
                    cout << "学号: " << student.studentId << " 姓名: " << student.name << " 专业: " << student.major << " 成绩: ";
                    for (double score : student.scores) {
                        cout << score << " ";
                    }
                    cout << endl;
                } else {
                    cout << "学号不存在" << endl;
                }
                break;
            }
            case 2: {
                // 录入学生成绩逻辑
                string studentId;
                cout << "请输入学号:";
                cin >> studentId;

                if (students.find(studentId) != students.end()) {
                    double score;
                    cout << "请输入成绩: ";
                    cin >> score;
                    students[studentId].addScore(score); // 添加成绩
                    saveScores(scoresFilename); // 保存学生成绩到文件
                    cout << "成绩录入成功" << endl;
                } else {
                    cout << "学号不存在" << endl;
                }
                break;
            }
            case 3: {
                // 计算学生总成绩逻辑
                string studentId;
                cout << "请输入学号: ";
                cin >> studentId;

                double totalScore = calculateTotalScore(studentId);
                if (totalScore > 0.0) {
                    cout << "学号: " << studentId << " 总成绩: " << totalScore << endl;
                } else {
                    cout << "学号不存在" << endl;
                }
                break;
            }
            case 4: {
                // 退出程序逻辑
                saveScores(scoresFilename);
                return 0;
            }
            default:
                cout << "无效的操作" << endl;
                break;
        }
    }
     saveScores(scoresFilename);
    return 0;
}