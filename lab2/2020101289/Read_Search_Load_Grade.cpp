#include <iostream>
#include <fstream>
#include<vector>
#include<sstream>
#include <map>

using namespace std;

struct Student {
    string name;
    string major;
    map<string, int> scores;
    int totalScore;
};

vector<string>stringSplit(const string str,char delim){
    stringstream ss;
    ss<<str;
    string item;
    vector<string>elems;
    while (getline(ss,item,delim))
    {
        if(!item.empty()){
            elems.push_back(item);
        }
    }
    return elems;
}


void readFromFile(map<int, Student>& students) {
    ifstream file;
    file.open("students.txt",ios::in);
    int flag=file.is_open();
    string b;
    file>>b;
    vector<string> buf;

    while (file >>b) {
     buf=  stringSplit(b,',');
    students[stoi(buf[0])].name=buf[1];
    students[stoi(buf[0])].major=buf[2];
    cout<<students[stoi(buf[0])].major<<endl;
    }
    
    file.close();
}

void writeToFile(const map<int, Student>& students) {
    ofstream file("students.txt");
    for (const auto& pair : students) {
        file << pair.first << "," << pair.second.name << "," << pair.second.major << endl;
    }
    file.close();
}

void addScore(map<int, Student>& students, int id, const string& experiment, int score) {
    students[id].scores[experiment] = score;
}

void calculateTotalScore(map<int, Student>& students) {
    for (auto& pair : students) {
        int total = 0;
        for (const auto& scorePair : pair.second.scores) {
            total += scorePair.second;
        }
        pair.second.totalScore = total;
    }
}

int main() {

    ifstream ifs;
    ifs.open("students.txt",ios::in);
    string buf;
    if (ifs.is_open())
    {
        while (ifs>>buf)
        {
            cout<<buf<<endl;
        }
        
    }
    else{
        cout<<"buf"<<endl;
    }
 map<int, Student> students;
    readFromFile(students);

    int choice;
    do {
        cout << "1. 查询成绩" << endl;
        cout << "2. 录入成绩" << endl;
        cout << "3. 退出" << endl;
        cout << "请选择: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            cout << "请输入学号: ";
            cin >> id;

            if (students.count(id) > 0) {
                cout << "学号：" << id << endl;
                cout << "姓名：" << students[id].name << endl;
                cout << "专业：" << students[id].major << endl;
                cout << "总成绩：" << students[id].totalScore << endl;
            } else {
                cout << "找不到该学生信息！" << endl;
            }
        } else if (choice == 2) {
            int id, score;
            string experiment;
            cout << "请输入学号: ";
            cin >> id;
            cout << "请输入实验名称: ";
            cin >> experiment;
            cout << "请输入成绩: ";
            cin >> score;

            if (students.count(id) > 0) {
                addScore(students, id, experiment, score);
                calculateTotalScore(students);
                writeToFile(students);
                cout << "成绩已录入！" << endl;
            } else {
                cout << "找不到该学生信息！" << endl;
            }
        }
    } while (choice != 3);

    return 0;
}