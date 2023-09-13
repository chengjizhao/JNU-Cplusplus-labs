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
        string student_ID, name, grade, major;
        getline(ss, student_ID , delim);
        getline(ss, name , delim);
        getline(ss, major,delim);
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
file << "学号,姓名,专业,成绩1,成绩2,成绩3,成绩4,成绩5,成绩6,成绩7,成绩8,成绩9,成绩10,成绩11,成绩12,成绩13,成绩14,成绩15,成绩16\n";
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
    cout << "请输入查询学号：";
    cin >> student_ID;
    auto it = students.find(student_ID);
    int choice;
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
                else { cout << "学生不存在" << endl; }
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
