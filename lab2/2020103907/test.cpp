#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
#include<locale>
#include<map>
using namespace std;
struct Student{
    string student_ID;
    string name;
    string major;
    vector<int>score;
};

map<string, Student> load_information(const string& filename) {
    map<string, Student> students;
    ifstream ifs;
    ifs.open(filename,ios::in);
    char delim = ',';
    string str;
    while (getline(ifs, str)) {
        stringstream ss(str);
        string student_ID, name, grade, department, major, 
               grade_class, course_characteristic, coure_type, 
               course_status, remake, course_selection, score_str;
        getline(ss, student_ID , delim);
        getline(ss, name , delim);
        getline(ss, grade , delim);
        getline(ss, department , delim);
        getline(ss, major , delim);
        getline(ss, grade_class ,delim);
        getline(ss, course_characteristic ,delim);
        getline(ss, coure_type ,delim);
        getline(ss, course_status ,delim);
        getline(ss, remake ,delim);
        getline(ss, course_selection ,delim);
        Student student{student_ID, name, major};
        while (getline(ss, score_str, delim)) {
            int score = stoi(score_str);
            student.score.push_back(score);
        }
        students[student_ID] = student;
    }
    return students;
}

void save_information(const string& filename, const map<string, Student>& students) {
    ofstream file(filename);
file << "学号,姓名,专业,实验1,实验2,实验3,实验4,实验5,实验6,实验7,实验8,实验9,实验10,实验11,实验12,实验13,实验14,实验15,实验16\n";
    for (const auto& pair : students) {
        const Student& student = pair.second;
        file << student.student_ID << "," << student.name << "," << student.major;
        for (int score : student.score) {
            file << "," << score;
        }
        file << "\n";
    }
}

int main()  {
    map<string, Student> students = load_information("students.csv");
    string student_ID;
    while(true){
    cout << "输入需要查询的学号：";
    cin >> student_ID;
    auto it = students.find(student_ID);
    int choice;
    cout << "请选择您要进行的操作：" << endl;
    cout << "1、查询成绩" <<endl;
    cout << "2、输入成绩" <<endl;
    cin >> choice;
    switch(choice) {
        case 1:
        if (it != students.end()) {
            int sum =0;
            const Student& student = it->second;
            cout << "学号：" << student.student_ID << endl;
            cout << "姓名：" << student.name << endl;
            cout << "专业：" << student.major << endl;
            cout << "成绩：";
            for (int score : student.score) {
                cout << score << " ";
                sum = sum + score;
                }
                cout << endl;
                cout << "总成绩：" << sum << endl;
        }
                else { cout << "该学生不存在" << endl; }
        break;
        case 2:
        if (it != students.end()) {
            int student_score;
            cout << "请输入成绩：";
            cin >> student_score;
            it->second.score.push_back(student_score);
            save_information("data.csv", students);
            cout << "成绩已保存" << endl;
        }
        else {cout << "学生不存在" << endl;}
        break;

    }
    int i;
    cout << "是否退出?0、退出;任意数字继续" << endl;
    cin >> i;
    if (i == 0)
    {
    return 0;
    }
    }
}