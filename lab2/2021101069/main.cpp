//老师我真不会
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// 学生类
class Student {
public:
    string studentId;
    string name;
    string major;
    vector<int> scores;

    Student(const string& id, const string& n, const string& m) : studentId(id), name(n), major(m) {}
};

// 读取文件并构建学生对象
vector<Student> readStudents(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    if (file.is_open("text.xlsx",ios::out)) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string studentId, name, major;
            getline(ss, studentId, ',');
            getline(ss, name, ',');
            getline(ss, major, ',');
            students.emplace_back(studentId, name, major);
        }
        file.close();
    }
    return students;
}

// 按学号查询学生信息
Student* findStudent(const vector<Student>& students, const string& studentId) {
    for (auto& student : students) {
        if (student.studentId == studentId) {
        }
    }
    return nullptr;
}

// 录入实验课成绩并保存到文件
void recordScore(const string& filename, const string& studentId, int score) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << studentId << "," << score << endl;
        file.close();
    }
}

// 计算学生总成绩
void computeTotalScores(const vector<Student>& students, const string& scoresFilename) {
    ifstream file(scoresFilename);
    if (file.is_open()) {
        map<string, int> scoresMap; // 用于存储学生的累计成绩
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string studentId, scoreStr;
            getline(ss, studentId, ',');
            getline(ss, scoreStr, ',');
            int score = stoi(scoreStr);
            scoresMap[studentId] += score;
        }
        file.close();

        for (auto& student : students) {
            int totalScore = scoresMap[student.studentId];
            cout << "学号：" << student.studentId << "，姓名：" << student.name << "，总成绩：" << totalScore << endl;
        }
    }
}

int main() {
    // 读取学生信息文件并构建学生列表
    vector<Student> students = readStudents("students.csv");

    // 按学号查询成绩
    string studentId;
    cout << "请输入学号：";
    cin >> studentId;
    Student* student = findStudent(students, studentId);
    if (student) {
        cout << "姓名：" << student->name << "，专业：" << student->major << endl;
    } else {
        cout << "找不到该学生" << endl;
    }

    // 录入实验课成绩并保存到文件
    int score;
    cout << "请输入实验课成绩：";
    cin >> score;
    recordScore("scores.csv", studentId, score);

    // 计算总成绩
    computeTotalScores(students, "scores.csv");

    return 0;
}