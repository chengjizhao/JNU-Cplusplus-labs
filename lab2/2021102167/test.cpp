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
file << "ѧ��,����,רҵ,�ɼ�1,�ɼ�2,�ɼ�3,�ɼ�4,�ɼ�5,�ɼ�6,�ɼ�7,�ɼ�8,�ɼ�9,�ɼ�10,�ɼ�11,�ɼ�12,�ɼ�13,�ɼ�14,�ɼ�15,�ɼ�16\n";
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
    cout << "�������ѯѧ�ţ�";
    cin >> student_ID;
    auto it = students.find(student_ID);
    int choice;
    cout << "1����ѯ�ɼ�" <<endl;
    cout << "2������ɼ�" <<endl;
    cin >> choice;
    switch(choice) {
        case 1:
        if (it != students.end()) {
            int sum =0;
            const Student& student = it->second;
            cout << "ѧ�ţ�" << student.student_ID << endl;
            cout << "������" << student.name << endl;
            cout << "רҵ��" << student.major << endl;
            cout << "�ɼ���";
            for (int score : student.score) {
                cout << score << " ";
                sum = sum + score;
                }
                cout << endl;
                cout << "�ܳɼ���" << sum << endl;
        }
                else { cout << "ѧ��������" << endl; }
        break;
        case 2:
        if (it != students.end()) {
            int student_score;
            cout << "������ɼ���";
            cin >> student_score;
            it->second.score.push_back(student_score);
            save_information("data.csv", students);
            cout << "�ɼ��ѱ���" << endl;
        }
        else {cout << "ѧ��������" << endl;}
        break;

    }
    int i;
    cout << "�Ƿ��˳�?0���˳�;�������ּ���" << endl;
    cin >> i;
    if (i == 0)
    {
    return 0;
    }
    }
}
